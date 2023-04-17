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

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // crucial part
    for (int i = n - 1; i >= 0; i--)
    {
        int dig = (arr[i] / exp) % 10;
        int idx = count[dig] - 1;

        output[idx] = arr[i];
        count[dig]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    if (n == 0)
        return;

    int max_num = arr[0];
    for (int i = 0; i < n; i++)
        max_num = max(max_num, arr[i]);

    for (int exp = 1; max_num / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

int main()
{
    cout << "Enter n: ";
    int n;
    cin >> n;
    int arr[n];

    input(arr, n);

    // *******************************
    radixSort(arr, n);
    // *******************************

    cout << "\nArray after sorting:\n";
    print(arr, n);
}
