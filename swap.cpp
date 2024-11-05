#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("swap.in");
ofstream out("swap.out");

int main(void)
{
    int n, k, a1, a2, b1, b2;
    in >> n >> k >> a1 >> a2 >> b1 >> b2;

    vector<int> COWS(n+1);
    for (int i = 1; i <= n; i++) { COWS[i] = i; }

    vector<int> tmp1(a2 - a1 + 1);
    vector<int> tmp2(b2 - b1 + 1);
    int c = 0;

    for (int times = 0; times < k; times++)
    {
        c = 0;
        for (int i = a1; i <= a2; i++)
        {
            tmp1[c] = COWS[i];
            c++;
        }
        reverse(tmp1.begin(), tmp1.end());

        c = 0;
        for (int i = a1; i <= a2; i++)
        {
            COWS[i] = tmp1[c];
            c++;
        }

        c = 0;
        for (int i = b1; i <= b2; i++)
        {
            tmp2[c] = COWS[i];
            c++;
        }
        reverse(tmp2.begin(), tmp2.end());

        c = 0;
        for (int i = b1; i <= b2; i++)
        {
            COWS[i] = tmp2[c];
            c++;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        out << COWS[i] << endl;
    }
}