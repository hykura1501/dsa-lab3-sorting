#ifndef _goodSort_H_
#define _goodSort_H_
// void _swap(int &a, int &b);
void heapRebuild(int arr[], int n, int pos, long long &countComparision);
void heapConstruct(int arr[], int n, long long &countComparision);
void heapSort(int arr[], int left, int right, long long &countComparision);
void merge(int arr[], int left, int mid, int right, long long &countComparision);
void mergeSort(int arr[], int left, int right, long long &countComparision);
void quickSort(int a[], int left, int right, long long &countComparision);
#endif // _goodSort_H_