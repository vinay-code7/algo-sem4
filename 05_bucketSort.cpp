#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> brr[10];
    
    for (int i = 0; i < n; i++)
    {
        int idx = arr[i] / 10;
        brr[idx].push_back(arr[i]);
    }

    for (int i = 0; i < 10; i++)
        sort(brr[i].begin(), brr[i].end());

    int idx = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < brr[i].size(); j++)
            arr[idx++] = brr[i][j];
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
// 78 17 39 26 72 94 21 12 23 68