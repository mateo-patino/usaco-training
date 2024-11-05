#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("forlooping");
ofstream out("forlooping.out");

int main(void)
{
    int N;
    in >> N;

    vector<int> NUMS(N);

    for (int i = 0; i < N; i++) { in >> NUMS[i]; }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                // More stuff
            }
        }
    }

}