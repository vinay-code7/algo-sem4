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

// helper for heapSort
int heapify(int arr[], int n, int i)
{
    int l = 2 * i + 1;
    int r = l + 1;
    int cnt = 0;

    int largest = i;

    if (l < n && ++cnt && arr[l] > arr[largest])
        largest = l;
    if (r < n && ++cnt && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        cnt += heapify(arr, n, largest);
    }
    return cnt;
}

// main sorting function
int heapSort(int arr[], int n)
{
    // building max-heap
    int cnt = 0;
    for (int i = n / 2 - 1; i >= 0; i--)
        cnt += heapify(arr, n, i);

    // getting elements and maintaining heap
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        cnt += heapify(arr, --n, 0);
    }

    return cnt;
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    // *******************************
    int num_comp = heapSort(arr, n);
    // *******************************

    cout << "\nArray after sorting:\n";
    print(arr, n);
    cout << "\nNumber of comparisons: " << num_comp;
    cout << endl;
}
