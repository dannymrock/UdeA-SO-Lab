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

void inicializar_matrix(double value, matrix2D *M);
void imprimir_matrix(matrix2D *M);
int chequear_dimensiones(enum operacion op, matrix2D M1, matrix2D M2);
matrix2D *sumarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *restarMatrices(matrix2D *M1, matrix2D *M2);
matrix2D *multiplicarMatrices(matrix2D *M1, matrix2D *M2);
double get_ms(struct timeval t_ini,struct  timeval t_fin);

int main ()
{
  // Variables para la medida del tiempo
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
  M1->num_rows = 20;
  M1->num_colums = 20;
  M1->data = malloc(sizeof(double)*M1->num_rows*M1->num_colums);
  M2->num_rows = 20;
  M2->num_colums = 20;
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
  // imprimir_matrix(MR);
  // Liberando memoria antes de finalizar por completo la aplicacion
  free(M1->data);
  free(M1);
  free(M2->data);
  free(M2);
  free(MR->data);
  free(MR);
  return 0;
}

void inicializar_matrix(double value, matrix2D *M) {
  for(int i = 0; i < M->num_rows; i++) {
    for(int j = 0; j < M->num_colums; j++) {
      *((M->data + i) + j*M->num_colums) = value;
    }
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
  double acum = 0;
  int i,j,k;
  if (chequear_dimensiones(resta,*M1, *M2)==TRUE) {
    MR = malloc(sizeof(matrix2D));
    MR->num_rows = M1->num_rows;
    MR->num_colums = M2->num_colums;

    MR->data = malloc(sizeof(double)*M1->num_rows*M2->num_colums);
    for(i = 0; i < M1->num_rows; i++) {
      for(j = 0; j < M2->num_colums; j++) {
        for(k = 0; k < M1->num_rows; k++) {
          acum += *((M1->data + i) + k*M1->num_colums) + *((M2->data + k*M2->num_colums) + j);
        }
        *((MR->data + i) + j*MR->num_colums) = acum;
        acum = 0;
      }
    }
    return MR;
  }
  else {
    return NULL;
  }
}

double get_ms(struct timeval t_ini,struct timeval t_fin) {
  return (t_fin.tv_sec - t_ini.tv_sec)*1000 + (t_fin.tv_usec - t_ini.tv_usec)/1000.0;
}
