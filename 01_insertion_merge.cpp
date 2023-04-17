#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int insertionSort(int arr[], int n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && ++cnt && arr[j] > k)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = k;
    }
    return cnt;
}

// Helper function for Merge Sort Algorithm
int MERGE(int arr[], int left, int mid, int right)
{
    int subOneSize = mid - left + 1;
    int subTwoSize = right - mid;

    int subOne[subOneSize], subTwo[subTwoSize];

    for (int i = 0; i < subOneSize; i++)
        subOne[i] = arr[left + i];
    for (int j = 0; j < subTwoSize; j++)
        subTwo[j] = arr[mid + 1 + j];

    int i = 0, j = 0, cnt = 0;
    int k = left;
    while (i < subOneSize && j < subTwoSize)
    {
        cnt++;
        if (subOne[i] < subTwo[j])
            arr[k++] = subOne[i++];
        else
            arr[k++] = subTwo[j++];
    }

    while (i < subOneSize)
        arr[k++] = subOne[i++];
    while (j < subTwoSize)
        arr[k++] = subTwo[j++];

    return cnt;
}

// main sorting function
int mergeSort(int arr[], int begin, int end)
{
    if (begin >= end)
        return 0;

    int cnt = 0;
    int middle = (begin + end) / 2;

    cnt += mergeSort(arr, begin, middle);
    cnt += mergeSort(arr, middle + 1, end);

    cnt += MERGE(arr, begin, middle, end);

    return cnt;
}

// caller function
int mergeSort(int arr[], int n)
{
    return mergeSort(arr, 0, n - 1);
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    // *******************************
    // int num_comp = insertionSort(arr, n);
    int num_comp = mergeSort(arr, n);
    // *******************************

    cout << "\nArray after sorting:\n";
    print(arr, n);
    cout << "\nNumber of comparisons: " << num_comp;
    cout << endl;
}
