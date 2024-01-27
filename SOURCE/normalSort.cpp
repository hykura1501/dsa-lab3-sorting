#include <iostream>
#include "normalSort.h"
void _swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selectionSort(int* arr, int left, int right, long long &countComparision)
{
    for (int i = left; ++countComparision && i < right; i++)
    {
        int min_idx = i;
        for (int j = i + 1; ++countComparision && j <= right; j++)
        {
            if (++countComparision && arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        _swap(arr[min_idx], arr[i]);
    }
}

void insertionSort(int* arr, int left, int right, long long &countComparision)
{
    for (int i = 1; ++countComparision && i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (++countComparision && key < arr[j] && ++countComparision && j >= 0)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int* arr, int left, int right, long long &countComparision)
{
    bool swapped;
    for (int i = 0; ++countComparision && i < right; i++)
    {
        swapped = false;
        for (int j = 0; ++countComparision && j < right - i; j++)
        {
            if (++countComparision && arr[j] > arr[j + 1])
            {
                _swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (++countComparision && swapped == false)
            break;
    }
}

void shakerSort(int* arr, int left, int right, long long &countComparision)
{
    int k = 0;
    while (++countComparision && left < right)
    {
        for (int i = left; ++countComparision && i < right; i++)
        {
            if (++countComparision && arr[i] > arr[i + 1])
            {
                _swap(arr[i], arr[i + 1]);
                k = i;
            }
        }

        right = k;

        for (int i = right; ++countComparision && i > left; i--)
        {
            if (++countComparision && arr[i] < arr[i - 1])
            {
                _swap(arr[i], arr[i - 1]);
                k = i;
            }
        }

        left = k;
    }
}

void shellSort(int* arr, int left, int right, long long &countComparision)
{
    for (int gap = (right + 1) / 2; ++countComparision && gap > left; gap /= 2)
    {
        for (int i = gap; ++countComparision && i <= right; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; ++countComparision && j >= gap && ++countComparision && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
