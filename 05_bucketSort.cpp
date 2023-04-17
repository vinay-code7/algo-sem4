#include "arrHelper.cpp"
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(float arr[], int n, int num_buckets=5)
{
    // Determine minimum and maximum values in array
    float min_val = arr[0];
    float max_val = arr[0];
    for (int i = 0; i < n; i++)
    {
        max_val = max(max_val, arr[i]);
        min_val = min(min_val, arr[i]);
    }

    // Determine range of values per bucket
    float bucket_range = (max_val - min_val + 1) / num_buckets;

    // Create empty buckets
    vector<vector<float>> buckets(num_buckets);

    // Assign each element to its corresponding bucket
    for (int i = 0; i < n; i++)
    {
        int bucket_index = (arr[i] - min_val) / bucket_range;
        buckets[bucket_index].push_back(arr[i]);
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < num_buckets; i++)
    {
        int bucket_size = buckets[i].size();
        for (int j = 1; j < bucket_size; j++)
        {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    // Concatenate all buckets into the sorted array
    int index = 0;
    for (int i = 0; i < num_buckets; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
        {
            arr[index] = buckets[i][j];
            index++;
        }
    }
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
