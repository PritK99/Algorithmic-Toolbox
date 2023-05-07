#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int> price, vector<int> weight, int capacity, int n, vector<bool> &status)
{
    vector<vector<int>> matrix(weight.size() + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i < matrix.size(); i++)
    {
        for (int j = 1; j < matrix[0].size(); j++)
        {
            if (weight[i - 1] <= j)
            {
                matrix[i][j] = max(matrix[i - 1][j], price[i - 1] + matrix[i - 1][j - weight[i - 1]]);
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }
        }
    }

    return matrix[weight.size()][capacity];
}

int main()
{
    int capacity;
    cin >> capacity;
    int n;
    cin >> n;
    vector<int> price(n);
    vector<int> weight(n);
    vector<bool> status(n, false);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        price[i] = weight[i];
    }

    int answer = knapsack(price, weight, capacity, n - 1, status);

    cout << answer << endl;

    return 0;
}
