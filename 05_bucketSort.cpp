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

void bucketSort(float arr[], int n)
{
    
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    float arr[n];

    cout << "Enter " << n << " decimal numbers: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // *******************************
    bucketSort(arr, n);
    // *******************************

    cout << "\nArray after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
