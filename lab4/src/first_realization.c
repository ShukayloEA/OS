#include <stdio.h>
#include <math.h>
#include "realization.h"

float Derivative(float A, float deltaX) {
  return (cosf(A + deltaX) - cosf(A)) / deltaX;
}

float Square(float A, float B) {
    return A * B;
}