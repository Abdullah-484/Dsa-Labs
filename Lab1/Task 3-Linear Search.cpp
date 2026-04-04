#include<iostream>
#include <string>
using namespace std;

template <typename T, int size>
int linearSearch(T(&arr)[size], T key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
template <typename T>
void printSearchResult(int index, T key)
{
    if (index != -1)
        cout << "Value " << key << " found at index: " << index << endl;
    else
        cout << "Value " << key << " not found in array." << endl;
}

int main()
{
    int intArr[5] = { 64, 25, 12, 22, 11 };
    int intKey = 12;
    int intIndex = linearSearch(intArr, intKey);
    printSearchResult(intIndex, intKey);
    float floatArr[4] = { 3.14, 2.71, 1.62, 0.57 };
    float floatKey = 1.62;
    int floatIndex = linearSearch(floatArr, floatKey);
    printSearchResult(floatIndex, floatKey);
    string stringArr[4] = { "apple", "orange", "banana", "grape" };
    string stringKey = "banana";
    int stringIndex = linearSearch(stringArr, stringKey);
    printSearchResult(stringIndex, stringKey);


    return 0;
}