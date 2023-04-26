#include <iostream>
using namespace std;

void knapSack(int profits[], int weights[], int N, int W)
{
    int DP[N + 1][W + 1];

    for (int i = 0; i < N + 1; i++)
        DP[i][0] = 0;
    for (int i = 0; i < W + 1; i++)
        DP[0][i] = 0;

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (weights[i - 1] <= j)
            {
                int take = profits[i - 1] + DP[i - 1][j - weights[i - 1]];
                int not_take = DP[i - 1][j];
                DP[i][j] = max(take, not_take);
            }
            else
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
    }

    // cout << "The DP table will be: " << endl;
    // for (int i = 0; i < N + 1; i++)
    // {
    //     for (int j = 0; j < W + 1; j++)
    //     {
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "The maximum profit would be: " << DP[N][W] << endl;
    cout << "The items taken are: ";

    int res = DP[N][W];
    int w = W;
    for (int i = N; i > 0 && res > 0; i--)
    {
        if (res != DP[i - 1][w])
        {
            cout << i << " ";
            res -= profits[i - 1];
            w -= weights[i - 1];
        }
    }
    cout << endl;
}

int main()
{
    // int N = 3;
    // int W = 5;
    // int profits[] = {6, 10, 12};
    // int weights[] = {1, 2, 3};

    // int N = 4;
    // int W = 8;
    // int profits[] = {3, 4, 6, 5};
    // int weights[] = {2, 3, 1, 4};

    // int N = 4;
    // int W = 5;
    // int profits[] = {3, 4, 5, 6};
    // int weights[] = {2, 3, 4, 5};

    int N = 4;
    int W = 8;
    int profits[] = {2, 4, 7, 10};
    int weights[] = {1, 3, 5, 7};

    knapSack(profits, weights, N, W);
}
