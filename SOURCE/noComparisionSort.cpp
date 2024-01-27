#include <iostream>
#include "noComparisionSort.h"
int getMax(int* arr, int right, long long &countComparision)
{
    int mx = arr[0];
    for (int i = 1; ++countComparision && i <= right; i++)
        if (++countComparision && arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countingSort(int* arr, int left, int right, long long &countComparision)
{
    int maxElement = getMax(arr, right, countComparision);
    int* count = new int[maxElement + 1]();
    for (int i = 0; ++countComparision && i <= right; i++)
    {
        count[arr[i]]++;
    }
    for (int i = left, j = left; ++countComparision && i <= maxElement && ++countComparision && j <= right; j++)
    {
        while (++countComparision && count[j] > 0)
        {
            count[j]--;
            arr[i++] = j;
        }
    }
}

void countSort(int* arr, int n, int exp, long long &countComparision)
{
    int* output = new int[n];
    int i, count[10] = {0};

    for (i = 0; ++countComparision && i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; ++countComparision && i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; ++countComparision && i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; ++countComparision && i < n; i++)
        arr[i] = output[i];
}

void radixSort(int* arr, int left, int right, long long &countComparision)
{

    int m = getMax(arr, right, countComparision);

    for (int exp = 1; ++countComparision && m / exp > 0; exp *= 10)
        countSort(arr, right + 1, exp, countComparision);
}
