#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("gymnastics.in");
ofstream out("gymnastics.out");

int main(void)
{
    int k, n;
    in >> k >> n;
    vector<vector <int>> sessions(k, vector<int>(n));

    for (int i = 0; i < k; k++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> sessions[i][j];
        }
    }

    vector<vector<int>> pairs;

    bool breakOuter = false;
    for (int i = 0; i < k; i++)
    {
        for (int c = i; c < n; c++)
        {
            pairs[i].push_back(sessions[0][i]);
            pairs[i].push_back(sessions[0][c+1]);

            if (c + 2 > n) { breakOuter = true; break; }
        }

        if (breakOuter) { break; }
    }


    
}