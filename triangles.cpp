#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

ifstream in("triangles.in");
ofstream out("triangles.out");

int main(void)
{
    cout << "Hello";
    int N;
    in >> N;

    vector<pair<int, int>> POINTS;
    for (int i = 0; i < N; i++) { in >> POINTS[i].first >> POINTS[i].second; }

    cout << "GOT HERE" << endl;

    vector<int>solutions;

    for (int origin = 0; origin < N; origin++)
    {
        pair<int, int> P = POINTS[origin];
        for (int j = origin + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                cout << "j: " << j << " k: " << k << endl;
                if (P.first == POINTS[j].first && P.second == POINTS[k].second)
                {
                    cout << "ORIGIN: " << P.first << P.second << endl;
                    cout << "J POINT: " << POINTS[j].first << POINTS[j].second << endl;
                    cout << "K POINT: " << POINTS[k].first << POINTS[k].second << endl;
                }
            }
        }
    }

    out << *max_element(solutions.begin(), solutions.end()) << endl;
}