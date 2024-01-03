#ifndef SORT_H
#define SORT_H
#include <iostream>

void SelectionSort(int arr[], int n, long long& comparisons);
void InsertionSort(int a[], int n, long long& comparisons);
void BubbleSort(int a[], int n, long long& comparisons);

void Heapify(int arr[], int n, int i, long long& comparisons);
void HeapSort(int arr[], int n, long long& comparisons);

void Merge(int arr[], int l, int m, int r, long long& comparisons);
void MergeSort(int arr[], int l, int r, long long& comparisons);

int MedianOfThree(int arr[], int l, int r, long long& comparisons);
int Partition(int arr[], int l, int r, long long& comparisons);
void QuickSort(int arr[], int l, int r, long long& comparisons);

int GetMax(int a[], int n, long long& comparisons);
void CountSort(int a[], int n, int exp, long long& comparisons);
void RadixSort(int a[], int n, long long& comparisons);

void ShakerSort(int a[], int n, long long& comparisons);
void ShellSort(int a[], int n, long long& comparisons);

void CountingSort(int a[], int n, long long& comparisons);

void FlashSort(int a[], int n, long long& comparisons);
#endif // SORT_H