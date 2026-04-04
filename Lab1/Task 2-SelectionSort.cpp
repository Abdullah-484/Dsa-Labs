#include<iostream>
#include<string>
using namespace std;

template <typename T, int size>
void selectionSort(T(&arr)[size])
{
    for (int i = 0; i < size - 1; i++)
    {
        int small = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        if (small != i)
        {
            T temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
        }
    }
}
template <typename T, int size>
void printArray(T(&arr)[size])
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int intArr[5] = { 64, 25, 12, 22, 11 };
    cout << "Original integer array: ";
    printArray(intArr);
    selectionSort(intArr);
    cout << "Sorted integer array: ";
    printArray(intArr);
    string stringArr[4] = { "apple", "orange", "banana", "grapes" };
    cout << "\nOriginal string array: ";
    printArray(stringArr);
    selectionSort(stringArr);
    cout << "Sorted string array: ";
    printArray(stringArr);


    return 0;
}