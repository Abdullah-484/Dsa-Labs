#include <iostream>

using namespace std;
int maxNo(int arr[], int n, int i, int maxIdx)
{
    if (i == n)
    {
        return maxIdx;
    }
    //checking current element is not deleted and comparing with current maximum
    if (arr[i] != -1 && (maxIdx == -1 || arr[i] > arr[maxIdx]))
    {
        maxIdx = i;
    }
    //moving to next index recursively
    return maxNo(arr, n, i + 1, maxIdx);
}
bool sum(int arr[], int n, int i, int target)
{
    //if target becomes zero then required subset is found
    if (target == 0)
    {
        return true;
    }
    //if array ends and target is still not achieved
    if (i == n)
    {
        return false;
    }
    //trying to include current element in subset
    if (arr[i] != -1 && arr[i] <= target)
    {
        if (sum(arr, n, i + 1, target - arr[i]))
        {
            return true;
        }
    }
    //trying without including current element
    return sum(arr, n, i + 1, target);
}
int magicNo(int arr[], int n, int remaining)
{
    //stopping condition when no elements left to check
    if (remaining == 0)
    {
        return -1;
    }
    //finding index of maximum element in current array
    int idx = maxNo(arr, n, 0, -1);
    //if no valid maximum found then exit
    if (idx == -1)
    {
        return -1;
    }
    //taking value of maximum element
    int value = arr[idx];
    //marking this element as deleted (-1)
    arr[idx] = -1;
    //checking whether this value can be formed using subset sum
    if (sum(arr, n, 0, value))
    {
        return value;
    }
    //if not found then repeat process with remaining elements
    return magicNo(arr, n, remaining - 1);
}

int main()
{
    int n;
    cout << "Enter Size:";
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter no: ";
        cin >> arr[i];
    }
    cout << "Magic No :" << magicNo(arr, n, n);
    delete[] arr;

    return 0;
}