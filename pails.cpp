#include <algorithm>
#include <set>
#include <fstream>
using namespace std;

ifstream in("pails.in");
ofstream out("pails.out");

int main(void)
{
    int x, y, M;
    in >> x >> y >> M;

    set<int> solutions;

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if ((x*i) + (y*j) <= M) { solutions.insert((x*i) + (y*j)); }
        }
    }

    out << *max_element(solutions.begin(), solutions.end()) << endl;
}