/***********************************************************************
* Code listing from "Advanced Linux Programming," by CodeSourcery LLC  *
* Copyright (C) 2001 by New Riders Publishing                          *
* See COPYRIGHT for license information.                               *
***********************************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 1

struct matrix2D {
  int num_rows;
  int num_colums;
  double *data;
} typedef matrix2D;

enum operacion {suma = 1, resta = 2, multiplicacion = 3};

/* Funciones para paralelizar */
struct fila {
  int num_elementos;
  double *data;
  double valor;
} typedef fila;

struct fila_columna {
  double *vector_F;
  double *vector_C;
  int tam;
} typedef fila_columna;

struct fila_i {
  int indice;
  double *v;
  matrix2D *M;
} typedef fila_i;

struct columna_j {
  int indice;
  double *v;
  matrix2D *M;
} typedef columna_j;

struct elemento_ij {
  matrix2D *M1;
  matrix2D *M2;
  int i;
  int j;
} typedef elemento_ij;

/* Funciones para paralelizar a nivel de hilo */
void* llenar_fila (void* parameters);
void* multiplicar_fila_columna(void* parameters);
void* obtener_fila(void* parameters);
void* obtener_columna(void* parameters);
void* calcular_elemento_multiplicacion(void* parameters);

/* Funciones normales */
void inicializar_matrix(double value, matrix2D *M);
void imprimir_matrix(matrix2D *M);
int chequear_dimensiones(enum operacion op, matrix2D M1, matrix2D M2);
matrix2D *sumarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *restarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2);
double get_ms(struct timeval t_ini,struct  timeval t_fin);

/* Funciones de test */
void test_llenarfila(void);
void test_llenar_matrix(void);
void test_multiplicar_fila_columna(void);
void test_obtenerfila(void);
void test_obtenercolumna(void);
void test_multiplicar_matrices(void);

int main ()
{
  // test_llenarfila();
  //test_llenar_matrix();
  //test_multiplicar_fila_columna();
  //test_obtenerfila();
  //test_obtenercolumna();
  //test_multiplicar_matrices();
  struct timeval ti, tf;
  double tiempo;
  // Reserva de memoria para las matrices
  matrix2D *M1,  // Matrix 1
           *M2,  // Matrix 2
           *MR;  // Matrix resultante
  M1 = malloc(sizeof(matrix2D));
  M2 = malloc(sizeof(matrix2D));
  MR = malloc(sizeof(matrix2D));
  // Inicializacion de las matrices
  M1->num_rows = 3;
  M1->num_colums = 3;
  M1->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
  M2->num_rows = 3;
  M2->num_colums = 3;
  M2->data = malloc(sizeof(double)*M2->num_rows*M2->num_colums);
  gettimeofday(&ti, NULL);   // Instante inicial
  inicializar_matrix(3, M1);
  gettimeofday(&tf, NULL);   // Instante final
  tiempo= get_ms(ti, tf);
  printf("Inicializacion Matrix 1: t(ms) = %.10e\n\n", tiempo);
  gettimeofday(&ti, NULL);   // Instante inicial
  inicializar_matrix(4, M2);
  gettimeofday(&tf, NULL);   // Instante final
  tiempo= get_ms(ti, tf);
  printf("Inicializacion Matrix 2: t(ms) = %.10e\n\n", tiempo);
  // imprimir_matrix(M1);
  // imprimir_matrix(M2);
  printf("\nM1 + M2 -> \n");
  gettimeofday(&ti, NULL);   // Instante inicial
  MR = sumarMatrices(M1,M2);
  gettimeofday(&tf, NULL);   // Instante final
  tiempo= get_ms(ti, tf);
  printf("Suma matrices: t(ms) = %.10e\n\n", tiempo);
  // imprimir_matrix(MR);
  printf("\nM1 - M2 -> \n");
  // Liberando MR antes de hacer nuevamente la operacion
  free(MR->data);
  free(MR);
  gettimeofday(&ti, NULL);   // Instante inicial
  MR = restarMatrices(M1,M2);
  gettimeofday(&tf, NULL);   // Instante final
  tiempo= get_ms(ti, tf);
  printf("Resta Matrices: t(ms) = %.10e\n\n", tiempo);
  // imprimir_matrix(MR);
  printf("\nM1 * M2 -> \n");
  free(MR->data);
  free(MR);
  gettimeofday(&ti, NULL);   // Instante inicial
  MR = multiplicarMatrices(M1,M2);
  gettimeofday(&tf, NULL);   // Instante final
  tiempo= get_ms(ti, tf);
  printf("Multiplicacion matrices: t(ms) = %.10e\n\n", tiempo);
  //imprimir_matrix(MR);
  // Liberando memoria antes de finalizar por completo la aplicacion
  free(M1->data);
  free(M1);
  free(M2->data);
  free(M2);
  free(MR->data);
  free(MR);
  return 0;
}

void test_llenar_matrix(void) {
  matrix2D *M = malloc(sizeof(matrix2D));
  M->num_rows = 10;
  M->num_colums = 10;
  M->data = malloc(sizeof(double)*M->num_rows*M->num_colums);
  inicializar_matrix(3, M);
  imprimir_matrix(M);
  free(M);
}

void inicializar_matrix(double value, matrix2D *M) {
  fila *f[M->num_rows];
  pthread_t threads_ids[M->num_rows];
  fila f_unica;
  f_unica.valor = value;
  f_unica.num_elementos = M->num_colums;
  int i;
  for(i = 0; i < M->num_rows; i++) {
    // Acceso a cada fila de la matrix
    f_unica.data = M->data + i*M->num_rows;
    f[i] = &f_unica;
    // Creando un hilo para llenar cada fila
    pthread_create (&threads_ids[i], NULL, &llenar_fila, f[i]);
    pthread_join(threads_ids[i],NULL);
  }
}

void imprimir_matrix(matrix2D *M) {
  for(int i = 0; i < M->num_rows; i++) {
    printf("[ ");
    for(int j = 0; j < M->num_colums; j++) {
      printf("%lf ", *((M->data + i) + j*M->num_colums));
    }
    printf(" ]\n");
  }
}

int chequear_dimensiones(enum operacion op, matrix2D M1, matrix2D M2) {
  if (op == suma | op == resta) {
    if((M1.num_rows == M2.num_rows) && (M1.num_colums == M2.num_colums)) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
  else {
    if(M1.num_colums == M2.num_rows) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }
}

matrix2D *sumarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  if (chequear_dimensiones(suma,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M1->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(int i = 0; i < MR->num_rows; i++) {
      for(int j = 0; j < MR->num_colums; j++) {
        *((MR->data + i) + j*MR->num_colums) = *((M1->data + i) + j*M1->num_colums) + *((M2->data + i) + j*M2->num_colums);
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}

matrix2D *restarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M1->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(int i = 0; i < MR->num_rows; i++) {
      for(int j = 0; j < MR->num_colums; j++) {
        *((MR->data + i) + j*MR->num_colums) = *((M1->data + i) + j*M1->num_colums) - *((M2->data + i) + j*M2->num_colums);
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2) {
  matrix2D *MR = NULL;
  pthread_t t_elem[M1->num_rows*M2->num_colums];
  int i, j, k = 0;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    elemento_ij* e_ij[M1->num_rows*M2->num_colums];
    double *acum[M1->num_rows*M2->num_colums];
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M2->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for (int i = 0; i < M1->num_rows; i++) {
      for (int j = 0; j < M2->num_colums; j++) {
        acum[k] = malloc(sizeof(double));
        e_ij[k] = malloc(sizeof(elemento_ij));
        e_ij[k]->M1 = malloc(sizeof(matrix2D));
        e_ij[k]->M2 = malloc(sizeof(matrix2D));
        e_ij[k]->i = i;
        e_ij[k]->j = j;
        //printf("(i,j) = (%d,%d)\n", e_ij[k]->i,e_ij[k]->j);
        pthread_create(&t_elem[k], NULL, &calcular_elemento_multiplicacion, e_ij[k]);
        pthread_join(t_elem[k], (void *) acum[k]);
        //printf("%lf\n", *acum);
        //*((MR->data + i) + j*MR->num_colums) = *acum;
        free(e_ij[k]->M1);
        free(e_ij[k]->M2);
        free(e_ij[k]);
        free(acum[k]);
        k++;
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}
/*
----------------------------------------------------------------
INTENTO 2
----------------------------------------------------------------
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2) {
  double *f_i = malloc(sizeof(double)*M1->num_colums);
  double *c_j = malloc(sizeof(double)*M2->num_rows);
  pthread_t t_elem[M1->num_rows*M2->num_colums];
  matrix2D *MR = NULL;
  fila_columna *fc = malloc(sizeof(fila_columna));
  double *acum = malloc(sizeof(double));
  int i, j, k = 0;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M2->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(i = 0; i < M1->num_rows; i++) {
      for(j = 0; j < M2->num_colums; j++) {
        // Obteniendo la fila i-esima
        *(f_i + j) = *((M1->data + j) + i*M1->num_colums);
        // Obteniendo la columna j-esima
        *(c_j + j) = *((M2->data + j*M2->num_rows) + i);
        fc->tam = M1->num_rows;
        fc->vector_F = f_i;
        fc->vector_C = c_j;
        pthread_create(&t_elem[k], NULL, &multiplicar_fila_columna, fc);
        pthread_join(t_elem[k], (void *) &acum);
        *((MR->data + i) + j*MR->num_colums) = *acum;
        k++;
      }
    }
    free(f_i);
    free(c_j);
    free(acum);
    free(fc);
    return MR;
  }
  else {
    return NULL;
  }
}
*/

/*
----------------------------------------------------------------
INTENTO 1
----------------------------------------------------------------
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2) {
  pthread_t t_f[M1->num_rows*M2->num_colums];
  pthread_t t_c[M1->num_rows*M2->num_colums];
  pthread_t t_elem[M1->num_rows*M2->num_colums];
  fila_i *filas[M1->num_rows];
  columna_j *columnas[M2->num_colums];
  matrix2D *MR = NULL;
  double *acum = malloc(sizeof(double));
  fila_columna *fc = malloc(sizeof(fila_columna));
  int i, j, k = 0;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M2->num_colums;
    MR->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
    for(i = 0; i < M1->num_rows; i++) {
      for(j = 0; j < M2->num_colums; j++) {
        filas[i] = malloc(sizeof(fila_i));
        filas[i]->indice = i;
        filas[i]->M = M1;
        filas[i]->v = malloc(sizeof(double)*M1->num_colums);

        columnas[j] = malloc(sizeof(columna_j));
        columnas[j]->indice = j;
        columnas[j]-> M = M2;
        columnas[j]->v = malloc(sizeof(double)*M2->num_rows);
        pthread_create (&t_f[k], NULL, &obtener_fila, filas[i]);
        pthread_create (&t_c[k], NULL, &obtener_columna, columnas[j]);
        pthread_join(t_f[k],NULL);
        pthread_join(t_c[k],NULL);
        fc->tam = M1->num_rows;
        fc->vector_F = filas[i]->v;
        fc->vector_C = columnas[j]->v;
        pthread_create(&t_elem[k], NULL, &multiplicar_fila_columna, fc);
        pthread_join(t_elem[k], (void *) &acum);
        *((MR->data + i) + j*MR->num_colums) = *acum;
        k++;
        free(filas[i]->v);
        free(filas[i]);
        free(columnas[j]->v);
        free(columnas[j]);
      }
    }
    free(acum);
    free(fc);
    return MR;
  }
  else {
    return NULL;
  }
}

*/

double get_ms(struct timeval t_ini,struct timeval t_fin) {
  return (t_fin.tv_sec - t_ini.tv_sec)*1000 + (t_fin.tv_usec - t_ini.tv_usec)/1000.0;
}

/* Funciones para paralelizar */
void* llenar_fila (void* parameters)
{
  fila *p = (fila*) parameters;
  int i;
  for (i = 0; i < p->num_elementos; ++i)
    *(p->data + i) = p->valor;
  return NULL;
}

void* obtener_fila(void* parameters) {
  //printf("Thread PID: %lu \n",(unsigned long)pthread_self());
  fila_i *p = (fila_i*) parameters;
  //*double fila = malloc(sizeof(double)*p->num_colums);
  for(int i = 0; i < p->M->num_colums; i++) {
    *(p->v + i) = *(p->M->data + \
                    p->indice*p->M->num_colums + \
                    i);
  }
}

void* obtener_columna(void* parameters) {
  //printf("Thread PID: %lu \n",(unsigned long)pthread_self());
  columna_j *p = (columna_j*) parameters;
  for(int j = 0; j < p->M->num_rows; j++) {
    *(p->v + j) = *((p->M->data + p->indice) + j*p->M->num_rows);
  }
}


void* calcular_elemento_multiplicacion(void* parameters) {
  printf("Thread PID: %lu \n",(unsigned long)pthread_self());
  elemento_ij *p = (elemento_ij*) parameters;
  double *v = malloc(sizeof(double));
  *v = 0;
  for(int i = 0; i < p->M1->num_rows; i++) {
    // printf("%lf\n", *((p->M1->data + p->i*p->M1->num_colums) + i));
    //printf("---\n");
    //printf("(i,j) = (%lf,%lf)\n", *((p->M1->data + p->i) + p->j*p->M1->num_colums), \
                          *((p->M2->data + p->j*p->M2->num_rows) + i));
    //*v += *((p->M1->data + p->i) + p->j*p->M1->num_colums) * \
    //      *((p->M2->data + p->j*p->M2->num_rows) + i);

  }
  //printf("%lf\n",*v);
  //printf("%lf\n",*v);
  return v;
}



void* multiplicar_fila_columna(void* parameters) {
  fila_columna *p = (fila_columna*) parameters;
  double* resultado = malloc(sizeof(double));
  *resultado = 0;
  for(int i = 0; i < p->tam; i++) {
    *resultado += (*(p->vector_F + i)) * (*(p->vector_C + i));
  }
  return resultado;
}

void test_multiplicar_fila_columna(void) {
  double vf[] = {1,2,3};
  double vc[] = {2,3,4};
  double *r = malloc(sizeof(double));
  fila_columna *fc = malloc(sizeof(fila_columna));
  fc->tam = 3;
  fc->vector_F = vf;
  fc->vector_C = vc;
  r = multiplicar_fila_columna(fc);
  printf("%lf\n", *r);
  free(fc);
  free(r);
}

void test_llenarfila(void) {
  double v[4];
  fila f1;
  f1.num_elementos = 4;
  f1.valor = 2;
  f1.data = v;
  llenar_fila(&f1);
  for (int i = 0; i < f1.num_elementos; i++) {
    printf("%lf ",*(f1.data + i));
  }
  printf("\n");
}

void test_obtenerfila(void){
  matrix2D *M = malloc(sizeof(matrix2D));
  fila_i *p = malloc(sizeof(fila_i));
  M->num_rows = 5;
  M->num_colums = 5;
  M->data = malloc(sizeof(double)*M->num_rows*M->num_colums);
  inicializar_matrix(3, M);
  p->indice = 3;
  p->M = M;
  p->v = malloc(sizeof(double)*M->num_colums);
  obtener_fila(p);
  for (int i = 0; i < M->num_colums; i++) {
    printf("%lf ", *(p->v + i));
  }
  printf("\n");
  free(p->v);
  free(M->data);
  free(p);
  free(M);
}

void test_obtenercolumna(void){
  matrix2D *M = malloc(sizeof(matrix2D));
  columna_j *p = malloc(sizeof(columna_j));
  M->num_rows = 5;
  M->num_colums = 5;
  M->data = malloc(sizeof(double)*M->num_rows*M->num_colums);
  inicializar_matrix(3, M);
  p->indice = 3;
  p->M = M;
  p->v = malloc(sizeof(double)*M->num_rows);
  obtener_columna(p);
  for (int i = 0; i < M->num_rows; i++) {
    printf("%lf ", *(p->v + i));
  }
  printf("\n");
  free(p->v);
  free(M->data);
  free(p);
  free(M);
}

void test_multiplicar_matrices(void){
  matrix2D *M1,  // Matrix 1
           *M2,  // Matrix 2
           *MR;  // Matrix resultante
  M1 = malloc(sizeof(matrix2D));
  M2 = malloc(sizeof(matrix2D));
  MR = malloc(sizeof(matrix2D));
  // Inicializacion de las matrices
  M1->num_rows = 20;
  M1->num_colums = 20;
  M1->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
  M2->num_rows = 20;
  M2->num_colums = 20;
  M2->data = malloc(sizeof(double)*M2->num_rows*M2->num_colums);
  inicializar_matrix(3, M1);
  inicializar_matrix(4, M2);
  printf("%s ->\n","M1");
  imprimir_matrix(M1);
  printf("\n%s ->\n","M2");
  imprimir_matrix(M2);
  MR = multiplicarMatrices(M1,M2);
  imprimir_matrix(MR);
  free(MR->data);
}
