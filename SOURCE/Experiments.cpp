#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>
#include "GenerateData.cpp"
#include "normalSort.cpp"
#include "goodSort.cpp"
#include "noComparisionSort.cpp"
#include "flashSort.cpp"

using SortingFunction = function<void(int *, int, int, long long &)>;

void sort(int* arr, int l, int n, long long &countComparision, SortingFunction algorithm)
{
    algorithm(arr, l, n, countComparision);
}

int main()
{
    map<int, string> dataOrder = {
        {0, "Randomized data"},
        {1, "Sorted data"},
        {2, "Reverse sorted data"},
        {3, "Nearly sorted data"},
    };
    ofstream out("result.txt");
    // vector<int> dataSize = {100, 300, 500, 1000, 3000, 5000};
    vector<int> dataSize = {10000, 30000, 50000, 100000, 300000, 500000};
    long long countComparision = 0;
    SortingFunction algorithms[11] = {selectionSort, insertionSort, bubbleSort,
                                      shakerSort, shellSort, heapSort, mergeSort,
                                      quickSort, countingSort, radixSort, flashSort};
    string algorithmNames[11] = {"selectionSort", "insertionSort", "bubbleSort",
                                 "shakerSort", "shellSort", "heapSort", "mergeSort",
                                 "quickSort", "countingSort", "radixSort", "flashSort"};
    for (auto item : dataOrder)
    {
        int number = item.first;
        string TYPE = item.second;
        out << "Data Order: " << TYPE << endl;
        for (int j = 0; j < dataSize.size(); j++)
        {
            int *arr = new int[dataSize[j]];
            GenerateData(arr, dataSize[j], number);
            out << "Data Size: " << dataSize[j] << endl;
            for (int k = 0; k < 11; k++)
            {
                countComparision = 0;
                clock_t start, end;
                int *temp = new int[dataSize[j]];
                for (int h = 0; h < dataSize[j]; h++)
                {
                    temp[h] = arr[h];
                }
                start = clock();
                sort(temp, 0, dataSize[j] - 1, countComparision, algorithms[k]);
                end = clock();
                double runningTime = (double)(end - start);
                // out << "Algorithm: " << algorithmNames[k] << endl;
                // out << "Running Time: " << runningTime << endl;
                // out << "Comparisions: " << countComparision << endl
                //     << endl;
                out << "Algorithm: " << algorithmNames[k] << " " << runningTime << " " << countComparision << endl;
            }
        }
    }
    out.close();
    return 0;
}