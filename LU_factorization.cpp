#include<bits/stdc++.h>
 
using namespace std;

void lu(vector<vector<float>> &a, vector<vector<float>> &l, vector<vector<float>> &u, int n)
{
    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for (k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
        }
        for (j = 0; j < n; j++)
        {
            if (j < i)
                u[i][j] = 0;
            else if (j == i)
                u[i][j] = 1;
            else
            {
                u[i][j] = a[i][j] / l[i][i];
                for (k = 0; k < i; k++)
                {
                    u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
                }
            }
        }
    }
}

void output(vector<vector<float>> &x, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%f ", x[i][j]);
        }
        cout << "\n";
    }
}
 
int main(int argc, char **argv)
{
    vector<vector<float>> a(10,vector<float>(10)), l(10,vector<float>(10)),u(10,vector<float>(10));
    int n = 0, i = 0, j = 0;
    cout << "Enter size of 2d array(Square matrix) : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Enter values no:" << i << ", " << j << ": ";
            cin >> a[i][j];
        }
    }
    lu(a, l, u, n);
    cout << "\nL Decomposition\n\n";
    output(l, n);
    cout << "\nU Decomposition\n\n";
    output(u, n);
    return 0;
}

