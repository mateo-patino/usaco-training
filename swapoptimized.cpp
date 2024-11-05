#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream in("swap.in");
ofstream out("swap.out");

int main(void)
{
    int n, k, a1, a2, b1, b2;
    in >> n >> k >> a1 >> a2 >> b1 >> b2;

    vector<int>COWS(n + 1);
    for (int i = 1; i <= n; i++) { COWS[i] = i; }

    int tmp;
    int c = 0;

    for (int times = 0; times < k; times++)
    {
        tmp = 0;
        c = 0;
        if ((a2 - a1 + 1) % 2 == 0)
        {
            for (int i = a1; i < a1 + ((a2 - a1 + 1) / 2); i++)
            {
                tmp = COWS[i];
                COWS[i] = COWS[a2 - c];
                COWS[a2 - c] = tmp;
                c++; 
            }
        }
        else 
        {
            for (int i = a1; i < (a1 + a2) / 2; i++)
            {
                tmp = COWS[i];
                COWS[i] = COWS[a2 - c];
                COWS[a2 - c] = tmp;
                c++; 
            }
        }

        tmp = 0;
        c = 0;
        if ((b2 - b1 + 1) % 2 == 0)
        {
            for (int i = b1; i < b1 + ((b2 - b1 + 1) / 2); i++)
            {
                tmp = COWS[i];
                COWS[i] = COWS[b2 - c];
                COWS[b2 - c] = tmp;
                c++; 
            }
        }
        else 
        {
            for (int i = b1; i < (b1 + b2) / 2; i++)
            {
                tmp = COWS[i];
                COWS[i] = COWS[b2 - c];
                COWS[b2 - c] = tmp;
                c++; 
            }
        }
    }

    for (auto itr = COWS.begin() + 1; itr != COWS.end(); ++itr)
    {
        out << *itr << endl;
    }
}