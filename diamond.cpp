#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("diamond.in");
ofstream out("diamond.out");

int main(void)
{
    int diamonds, difference;
    in >> diamonds >> difference;

    vector<int> sizes(diamonds);

    for (int i = 0; i < diamonds; i++)
    {
        in >> sizes[i];
    }

    vector<int> solutions;

    sort(sizes.begin(), sizes.end());

    int fittables = 0;

    for (int origin = 0; origin < diamonds; origin++)
    {
        for (int j = origin + 1; j < diamonds; j++)
        {
            if (sizes[origin] + difference >= sizes[j]) { fittables++; }
        }
        solutions.push_back(fittables);
        fittables = 0;
    }
    out << *max_element(solutions.begin(), solutions.end()) + 1;

}