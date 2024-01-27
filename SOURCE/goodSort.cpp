#include <iostream>
#include "goodSort.h"
#include "normalSort.h"
// void _swap(int &a, int &b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
// }
void heapRebuild(int *arr, int n, int pos, long long &countComparision)
{
    int k = pos, isHeap = 0;
    while (++countComparision && isHeap == 0 && ++countComparision && 2 * k + 1 < n)
    {
        int j = 2 * k + 1;
        if (++countComparision && j < n - 1)
        {
            if (++countComparision && arr[j] < arr[j + 1])
                j++;
        }
        if (++countComparision && arr[k] < arr[j])
        {
            _swap(arr[k], arr[j]);
            k = j;
        }
        else
        {
            isHeap = 1;
        }
    }
}
void heapConstruct(int *arr, int n, long long &countComparision)
{
    int idx = n / 2 - 1;
    while (++countComparision && idx >= 0)
    {
        heapRebuild(arr, n, idx, countComparision);
        idx--;
    }
}

void heapSort(int *arr, int left, int right, long long &countComparision)
{
    heapConstruct(arr, right + 1, countComparision);
    int r = right;
    while (++countComparision && r > 0)
    {
        _swap(arr[0], arr[r]);
        heapRebuild(arr, r, left, countComparision);
        r--;
    }
}

void merge(int *arr, int left, int mid, int right, long long &countComparision)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; ++countComparision && i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; ++countComparision && j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = left;

    while (++countComparision && i < n1 && ++countComparision && j < n2)
    {
        if (++countComparision && L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (++countComparision && i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (++countComparision && j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int left, int right, long long &countComparision)
{
    if (++countComparision && left < right)
    {
        int mid = (right + left) / 2;

        mergeSort(arr, left, mid, countComparision);
        mergeSort(arr, mid + 1, right, countComparision);
        merge(arr, left, mid, right, countComparision);
    }
}

void quickSort(int *arr, int left, int right, long long &countComparision)
{
    int p = arr[(left + right) / 2];
    int i = left, j = right;
    while (++countComparision && i < j)
    {
        while (++countComparision && arr[i] < p)
        {
            i++;
        }
        while (++countComparision && arr[j] > p)
        {
            j--;
        }
        if (++countComparision && i <= j)
        {
            _swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (++countComparision && i < right)
    {
        quickSort(arr, i, right, countComparision);
    }
    if (++countComparision && left < j)
    {
        quickSort(arr, left, j, countComparision);
    }
}