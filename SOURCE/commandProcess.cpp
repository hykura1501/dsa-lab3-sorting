#include <string>
#include <map>
#include <fstream>
#include <time.h>
#include <functional>
#include "GenerateData.cpp"
#include "normalSort.cpp"
#include "goodSort.cpp"
#include "noComparisionSort.cpp"
#include "flashSort.cpp"
using namespace std;

const long long maxN = 1000000;
const string ALGORITHM_MODE = "-a";
const string COMPARE_MODE = "-c";
const string INPUT_FILE = "input.txt";
const string OUTPUT_FILE = "output.txt";

using SortingFunction = function<void(int *, int, int, long long &)>;

void sort(int* arr, int l, int n, long long &countComparision, SortingFunction algorithm)
{
    algorithm(arr, l, n, countComparision);
}

map<string, SortingFunction> algorithms = {
    {"selection-sort", selectionSort},
    {"insertion-sort", insertionSort},
    {"bubble-sort", bubbleSort},
    {"shaker-sort", shakerSort},
    {"shell-sort", shellSort},
    {"heap-sort", heapSort},
    {"merge-sort", mergeSort},
    {"quick-sort", quickSort},
    {"counting-sort", countingSort},
    {"radix-sort", radixSort},
    {"flash-sort", flashSort},
};
map<string, string> algorithmName = {
    {"insertion-sort", "Insertion Sort"},
    {"selection-sort", "Selection Sort"},
    {"bubble-sort", "Bubble Sort"},
    {"shaker-sort", "Shaker Sort"},
    {"shell-sort", "Shell Sort"},
    {"heap-sort", "Heap Sort"},
    {"merge-sort", "Merge Sort"},
    {"quick-sort", "Quick Sort"},
    {"counting-sort", "Counting Sort"},
    {"radix-sort", "Radix Sort"},
    {"flash-sort", "Flash Sort"},
};

// Date Type
map<string, int> DATA_TYPE = {
    {"-rand", 0},
    {"-nsorted", 3},
    {"-sorted", 1},
    {"-rev", 2},
};
map<string, string> TYPE = {
    {"-rand", "Randomize"},
    {"-sorted", "Sorted"},
    {"-rev", "Reversed"},
    {"-nsorted", "Nearly Sorted"},
};

map<string, string> fileName = {
    {"-rand", "input_1.txt"},
    {"-sorted", "input_3.txt"},
    {"-rev", "input_4.txt"},
    {"-nsorted", "input_2.txt"},
};

string convertCharToString(char *c)
{
    string result(c, c + strlen(c));
    return result;
}

int *getDataFromInputFile(string fileName, int &inputSize)
{
    ifstream ifs(fileName);
    ifs >> inputSize;
    int *arr = new int[inputSize];
    for (int i = 0; i < inputSize; i++)
    {
        ifs >> arr[i];
    }
    ifs.close();
    return arr;
}

void display_Algorithm(
    string algorithmName,
    string outPutParameter,
    double runningTime,
    long long countComparision,
    int inputSize,
    string inputOrder = "",
    string fileName = "")
{
    cout << "Algorithm: " << algorithmName << endl;
    if (fileName != "")
    {
        cout << "Input file: " << fileName << endl;
        cout << "Input size: " << inputSize << endl;
    }
    else if (inputOrder != "")
    {
        cout << "Input size: " << inputSize << endl;
        cout << "Input order: " << inputOrder << endl;
    }
    cout << "-------------------------" << endl;
    if (outPutParameter == "-both")
    {
        cout << "Running time: " << runningTime << endl;
        cout << "Comparisions: " << countComparision << endl;
    }
    else if (outPutParameter == "-time")
    {
        cout << "Running time: " << runningTime << endl;
    }
    else if (outPutParameter == "-comp")
    {
        cout << "Comparisions: " << countComparision << endl;
    }
}

void display_Comparision(
    string algorithm_1,
    string algorithm_2,
    double runningTime_1,
    double runningTime_2,
    long long countComparision_1,
    long long countComparision_2,
    int inputSize,
    string inputOrder = "",
    string fileName = "")
{
    cout << "Algorithm: " << algorithm_1 << "  |  " << algorithm_2 << endl;
    if (fileName != "")
    {
        cout << "Input file: " << fileName << endl;
        cout << "Input size: " << inputSize << endl;
    }
    else
    {
        cout << "Input size: " << inputSize << endl;
        cout << "Input order: " << inputOrder << endl;
    }
    cout << "-------------------------" << endl;
    cout << "Running time: " << runningTime_1 << "  |  " << runningTime_2 << endl;
    cout << "Comparisions: " << countComparision_1 << "  |  " << countComparision_2 << endl;
}

bool checkValidInputFile(string fileName)
{
    int idx = fileName.find('.');
    if (idx == string::npos)
    {
        return false;
    }
    string buffer = fileName.substr(idx);
    return buffer == ".txt";
}

void writeDataToTextFile(int* arr, int inputSize, string fileName)
{
    ofstream ofs(fileName);
    ofs << inputSize << endl;
    for (int i = 0; i < inputSize; i++)
    {
        ofs << arr[i] << " ";
    }
    ofs.close();
}

void commandOne(string fileName, string algorithm, string outPutParameter)
{
    clock_t start, end;
    int inputSize;
    long long countComparision = 0;
    int *arr = getDataFromInputFile(fileName, inputSize);
    start = clock();
    sort(arr, 0, inputSize - 1, countComparision, algorithms[algorithm]);
    end = clock();
    double runningTime = (double)(end - start);
    writeDataToTextFile(arr, inputSize, OUTPUT_FILE);
    display_Algorithm(algorithmName[algorithm], outPutParameter,
                      runningTime, countComparision, inputSize, "", fileName);
}

void commandTwo(string inputOrder, int inputSize, string algorithm, string outPutParameter)
{
    clock_t start, end;
    double runningTime;
    long long countComparision = 0;
    int *arr = new int[inputSize];
    GenerateData(arr, inputSize, DATA_TYPE[inputOrder]);
    writeDataToTextFile(arr, inputSize, INPUT_FILE);
    start = clock();
    sort(arr, 0, inputSize - 1, countComparision, algorithms[algorithm]);
    end = clock();
    writeDataToTextFile(arr, inputSize, OUTPUT_FILE);
    runningTime = (double)(end - start);
    display_Algorithm(algorithmName[algorithm], outPutParameter,
                      runningTime, countComparision, inputSize, TYPE[inputOrder], "");
}

void commandThree(int inputSize, string algorithm, string outPutParameter)
{
    int *arr = new int[inputSize];
    long long countComparision = 0;
    clock_t start, end;
    double runningTime;
    cout << "Algorithm: " << algorithmName[algorithm] << endl;
    cout << "Input Size: " << inputSize << endl
         << endl;
    for (auto item : DATA_TYPE)
    {
        countComparision = 0;
        string type = item.first;
        int number = item.second;
        GenerateData(arr, inputSize, number);
        writeDataToTextFile(arr, inputSize, fileName[type]);
        start = clock();
        sort(arr, 0, inputSize - 1, countComparision, algorithms[algorithm]);
        end = clock();
        runningTime = (double)(end - start);
        cout << "Input Order: " << TYPE[type] << endl;
        cout << "-------------------------" << endl;
        if (outPutParameter == "-both")
        {
            cout << "Running Time: " << runningTime << endl;
            cout << "Comparisions: " << countComparision << endl;
        }
        else if (outPutParameter == "-time")
        {
            cout << "Running Time: " << runningTime << endl;
        }
        else if (outPutParameter == "-cmp")
        {
            cout << "Comparisions: " << countComparision << endl;
        }
        cout << endl;
    }
}

void commandFour(string fileName, string algorithm_1, string algorithm_2)
{
    int inputSize;
    clock_t start_1, end_1;
    clock_t start_2, end_2;
    long long countComparision_1 = 0, countComparision_2 = 0;
    double runningTime_1, runningTime_2;
    int *arr_1 = getDataFromInputFile(fileName, inputSize);
    int *arr_2 = getDataFromInputFile(fileName, inputSize);
    start_1 = clock();
    sort(arr_1, 0, inputSize - 1, countComparision_1, algorithms[algorithm_1]);
    end_1 = clock();
    runningTime_1 = (double)(end_1 - start_1);
    start_2 = clock();
    sort(arr_2, 0, inputSize - 1, countComparision_2, algorithms[algorithm_2]);
    end_2 = clock();
    runningTime_2 = (double)(end_2 - start_2);
    display_Comparision(algorithmName[algorithm_1], algorithmName[algorithm_2],
                        runningTime_1, runningTime_2, countComparision_1,
                        countComparision_2, inputSize, "", fileName);
}

void commandFive(int inputSize, string inputOrder, string algorithm_1, string algorithm_2)
{
    clock_t start_1, end_1;
    clock_t start_2, end_2;
    long long countComparision_1 = 0, countComparision_2 = 0;
    double runningTime_1, runningTime_2;
    int *arr_1 = new int[inputSize];
    int *arr_2 = new int[inputSize];
    GenerateData(arr_1, inputSize, DATA_TYPE[inputOrder]);
    for (int i = 0; i < inputSize; i++)
    {
        arr_2[i] = arr_1[i];
    }
    writeDataToTextFile(arr_1, inputSize, INPUT_FILE);
    start_1 = clock();
    sort(arr_1, 0, inputSize - 1, countComparision_1, algorithms[algorithm_1]);
    end_1 = clock();
    runningTime_1 = (double)(end_1 - start_1);
    start_2 = clock();
    sort(arr_2, 0, inputSize - 1, countComparision_2, algorithms[algorithm_2]);
    end_2 = clock();
    runningTime_2 = (double)(end_2 - start_2);
    display_Comparision(algorithmName[algorithm_1], algorithmName[algorithm_2],
                        runningTime_1, runningTime_2, countComparision_1,
                        countComparision_2, inputSize, TYPE[inputOrder], "");
}