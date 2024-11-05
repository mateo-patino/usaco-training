#include <iostream>
#include <fstream>
using namespace std;

ifstream in("shell.in");
ofstream out("shell.out");

int main(void)
{
    int N;
    in >> N;
    int best[3];

    int a, b, tmp, g;
    for (int j = 1; j < 4; j++)
    {
        int shell = j;
        int score = 0;
        for (int i = 0; i < N; i++)
        {
            in >> a;
            in >> b;

            if (shell == a) { shell = b; }
            else if (shell == b) { shell = a; }
            
            if (g == shell) { score++; }
        }
        best[j - 1] = score;
    }

    int max = 0;
    for (int i = 0; i < 3; i++)
    {
        if (best[i] > max) { max = best[i]; }
    }
    out << max;
}