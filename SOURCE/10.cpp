#include <iostream>
#include <string>
#include "commandProcess.cpp"
using namespace std;

int main(int argc, char *argv[])
{
    string mode = convertCharToString(argv[1]);
    if (mode == ALGORITHM_MODE)
    {
        cout << "ALGORITHM MODE" << endl;
        string algorithm = convertCharToString(argv[2]);
        string outPutParameter = convertCharToString(argv[argc - 1]);
        string buffer = convertCharToString(argv[3]);
        // Command 1:
        if (checkValidInputFile(buffer))
        {
            commandOne(buffer, algorithm, outPutParameter);
        }
        else
        {
            int inputSize = stoi(argv[3]);
            string temp = convertCharToString(argv[4]);
            // Command 3:
            if (temp == "-both" || temp == "-time" || temp == "-comp")
            {
                commandThree(inputSize, algorithm, outPutParameter);
            }
            else
            {
                // Command 2:
                string inputOrder = convertCharToString(argv[4]);
                commandTwo(inputOrder, inputSize, algorithm, outPutParameter);
            }
        }
    }
    else if (mode == COMPARE_MODE)
    {
        cout << "COMPARE MODE" << endl;
        string buffer = convertCharToString(argv[4]);
        string algorithm_1 = convertCharToString(argv[2]);
        string algorithm_2 = convertCharToString(argv[3]);
        // Command 4:
        if (checkValidInputFile(buffer))
        {
            commandFour(buffer, algorithm_1, algorithm_2);
        }
        else
        {
            // Command 5:
            int inputSize = stoi(buffer);
            string inputOrder = convertCharToString(argv[5]);
            commandFive(inputSize, inputOrder, algorithm_1, algorithm_2);
        }
    }

    return 0;
}
