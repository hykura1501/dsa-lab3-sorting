#ifndef _noComparisionSort_H_
#define _noComparisionSort_H_
int getMax(int arr[], int right, long long &countComparision);
void countingSort(int arr[], int left, int right, long long &countComparision);
void countSort(int arr[], int n, int exp, long long &countComparision);
void radixSort(int arr[], int left, int right, long long &countComparision);
#endif // _noComparisionSort_H_