#ifndef INC_5_LAB_LIBRARY_H
#define INC_5_LAB_LIBRARY_H

typedef float(*Der)(float, float);
typedef float(*Sq)(float, float);

float Derivative(float A, float deltaX);
float Square(float A, float B);

#endif