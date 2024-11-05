#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in("cowsignal.in");
ofstream out("cowsignal.out");

int main(void)
{
    int m, n, k;
    in >> m >> n >> k;

    for (int i = 0; i < m; i++)
    {
        string line = "";
        for (int c = 0; c < n; c++)
        {
            char ch;
            in >> ch;
            for (int j = 0; j < k; j++)
            {
                line += ch;
            }
        }
        for (int w = 0; w < k; w++)
        {
            // line += "\n";
            // cout << i << w << " " << line << endl;
            if (w == 1) { out << line; }
            else { line += "\n"; out << line; }
        }
    }
}
