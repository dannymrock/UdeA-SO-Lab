/* areas.c */
#include "areas.h"

double area_triangulo(double base, double altura) {
  double area; 
  area = base*altura/2;
  return area;
}

double area_circulo(double radio) {
    float area;
    area = PI*radio*radio;
    return area;
}

double area_rectangulo(double base, double altura) {
  return base*altura;
}

double area_trapecio(double base_mayor, double base_menor, double altura) {
  double area = ((base_mayor+base_menor)*altura)/2;
  return area;
}

