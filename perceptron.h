#if !defined(PERCEPTRON_H)
#define PERCEPTRON_H

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#define MAX_TAB 50
#define MAX_COL 4 //number of attributes


void chargerBaseExcel(double**,char*, int &);
void perceptron(double*, double**, int);
int natureFleur(double*, double*);
void testBase(double*, double**, int n);

#endif // PERCEPTRON_H
