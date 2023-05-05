#include <algorithm>
#include <iostream>
using namespace std;

// to represent interval
class Interval
{
public:
    int start, end, weight;
};

void findSolution(Interval arr[], int table[], int p_value[], int n)
{
    int i = n - 1;
    while (i >= 0)
    {
        int value = p_value[i] == 0 ? 0 : table[p_value[i] - 1];
        int take = arr[i].weight + value;

        int not_take = i == 0 ? 0 : table[i - 1];

        if (take >= not_take)
        {
            cout << arr[i].start << ", "
                 << arr[i].end << " => "
                 << arr[i].weight << endl;

            i = p_value[i] - 1;
        }
        else i--;
    }
}

// A utility function that is used for sorting events
// according to finish time
bool compare(Interval a, Interval b)
{
    return a.end < b.end;
}

void find_p_value(Interval arr[], int p_value[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int left = 0;
        int right = i - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (arr[mid].end <= arr[i].start)
                left = mid + 1;
            else
                right = mid - 1;
        }
        p_value[i] = left;
    }
}

void solution(Interval arr[], int n)
{
    sort(arr, arr + n, compare);

    int p_value[n];
    find_p_value(arr, p_value, n);

    int table[n];
    for (int i = 0; i < n; i++)
    {
        int value = p_value[i] == 0 ? 0 : table[p_value[i] - 1];
        int take = arr[i].weight + value;

        int not_take = i == 0 ? 0 : table[i - 1];

        table[i] = max(take, not_take);
    }

    cout << "\nMaximum weight: " << table[n - 1];
    cout << "\nIntervals that should be taken: " << endl;
    findSolution(arr, table, p_value, n);
}

int main()
{
    int n = 8;
    Interval arr[n] = {
        {3, 6, 1},
        {0, 5, 4},
        {3, 9, 5},
        {5, 10, 2},
        {1, 4, 2},
        {0, 3, 3},
        {8, 10, 1},
        {4, 7, 2},
    };

    solution(arr, n);
}
