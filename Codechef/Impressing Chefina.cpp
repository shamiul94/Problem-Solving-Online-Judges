#include <bits/stdc++.h>

#define fi freopen("cmake-build-debug/in.txt", "r", stdin)
#define fo freopen("cmake-build-debug/out.txt", "w", stdout)
using namespace std;

void printmatrix(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void rearrange(vector<vector<int>> &matrix, vector<vector<int>> &ans, unordered_map<int, int> &um)
{

    priority_queue<pair<int, int>> pq; // occurence, number

    auto it = um.begin();
    for (it = um.begin(); it != um.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
    }

    int row = matrix.size();
    int colm = matrix[0].size();

    for (int j = 0; j < colm / 2; j++)
    {
        for (int i = 0; i < row; i++)
        {
            pair<int, int> tem = pq.top();
            pq.pop();
            ans[i][j] = ans[i][colm - j - 1] = tem.second;
            tem.first -= 2;
            if (tem.first != 0)
            {
                pq.push(tem);
            }
        }
    }

    if (colm % 2 == 0)
    {
        printmatrix(ans);
    }
    else
    {
        int mid = colm / 2;
        for (int i = 0; i < row; i++)
        {
            pair<int, int> tem = pq.top();
            pq.pop();
            ans[i][mid] = tem.second;
            tem.first -= 1;
            if (tem.first != 0)
            {
                pq.push(tem);
            }
        }
        printmatrix(ans);
    }
}

int main()
{
    // fi;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int row, colm;
        cin >> row >> colm;

        vector<vector<int>> matrix(row, vector<int>(colm, -1));
        vector<vector<int>> ans(row, vector<int>(colm, -1));

        int neededPair = (colm / 2) * row;
        int foundPair = 0;

        unordered_map<int, int> um;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colm; j++)
            {
                int a;
                cin >> a;
                matrix[i][j] = a;

                if (um.find(a) == um.end())
                {
                    // not seen before this.
                    um[a] = 1;
                }
                else
                {
                    int prev = um[a];
                    if (prev / 2 != (prev + 1) / 2)
                    {
                        foundPair++;
                    }
                    um[a]++;
                }
            }
        }

        if (colm == 1)
        {
            printmatrix(matrix);
        }
        else
        {
            if (foundPair >= neededPair)
            {
                rearrange(matrix, ans, um);
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}