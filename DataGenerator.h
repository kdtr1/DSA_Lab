#pragma once

#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H
#include <iostream> 
#include <ctime>
#include <cstdlib>

template <class T>
void HoanVi(T& a, T& b);

void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);

#endif // DATAGENERATOR_H