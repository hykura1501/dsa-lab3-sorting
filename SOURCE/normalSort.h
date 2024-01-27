#ifndef _normalSort_H_
#define _normalSort_H_
void _swap(int &a, int &b);
void selectionSort(int a[], int left, int right, long long &countComparision);
void insertionSort(int arr[], int left, int right, long long &countComparision);
void bubbleSort(int arr[], int left, int right, long long &countComparision);
void shakerSort(int arr[], int left, int right, long long &countComparision);
void shellSort(int arr[], int left, int right, long long &countComparision);
#endif // _normalSort_H_