#include <iostream>
#include "flashSort.h"
#include "normalSort.h"
void flashSort(int* arr, int left, int right, long long &countComparision)
{
    int n = right + 1;
    int minVal = arr[0];
    int maxIdx = 0;
    int m = int(0.43 * n);
    int *l = new int[m];
    for (int i = 0; ++countComparision && i < m; i++)
    {
        l[i] = 0;
    }

    for (int i = 1; ++countComparision && i < n; i++)
    {
        if (++countComparision && arr[i] < minVal)
        {
            minVal = arr[i];
        }
        if (++countComparision && arr[i] > arr[maxIdx])
        {
            maxIdx = i;
        }
    }

    if (++countComparision && arr[maxIdx] == minVal)
    {
        return;
    }

    double c1 = 1.00 * (m - 1) / (arr[maxIdx] - minVal);

    for (int i = 0; ++countComparision && i < n; i++)
    {
        int k = int(c1 * (arr[i] - minVal));
        ++l[k];
    }

    for (int i = 1; ++countComparision && i < m; i++)
    {
        l[i] += l[i - 1];
    }

    _swap(arr[maxIdx], arr[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;

    while (++countComparision && move < n - 1)
    {
        while (++countComparision && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (arr[j] - minVal));
        }

        flash = arr[j];

        if (++countComparision && k < 0)
        {
            break;
        }

        while (++countComparision && j != l[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = arr[t = --l[k]];

            arr[t] = flash;
            flash = hold;

            ++move;
        }
    }
    delete[] l;
    insertionSort(arr, 0, right, countComparision);
}