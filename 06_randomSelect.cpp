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

int partition(int arr[], int begin, int end)
{
    // random   
    srand(time(NULL));
    int random = begin + rand() % (end - begin);
    swap(arr[random], arr[end]);

    // simple algo
    int pivot = arr[end];

    int i = begin - 1;
    for (int j = begin; j < end; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[end]);
    return i;
}

int randomized_select(int arr[], int begin, int end, int rank)
{
    if (begin == end)
        return arr[begin];

    int q = partition(arr, begin, end);
    int k = q - begin + 1;

    if (rank == k)
        return arr[q];
    
    if (rank < k)
        return randomized_select(arr, begin, q - 1, rank);
    return randomized_select(arr, q + 1, end, rank - k);   
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    cout << "Enter rank: ";
    int rank;
    cin >> rank;

    // *******************************
    int ele = randomized_select(arr, 0, n - 1, rank);
    // *******************************

    cout << endl;
    cout << "Element at rank " << rank << " is: " << ele << endl;
}
