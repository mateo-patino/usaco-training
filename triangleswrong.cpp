#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

ifstream in("triangles.in");
ofstream out("triangles.out");

int main(void)
{
    int N;
    in >> N;

    vector<pair<int, int>> POINTS(N);
    for (int i = 0; i < N; i++) { in >> POINTS[i].first >> POINTS[i].second; }


    // For iterating through all the points, you can imagine it as picking an origin point and checking the rest of points relative to this origin,
    // or just finding every 3-point combination in the input and find which ones satisfy the conditions we have. 

    vector<int> solutions;
    for (int origin = 0; origin < N; origin++)
    {
        // Find points with same x coordinate relative to origin point
        pair<int, int> P = POINTS[origin];
        for (int j = origin + 1; j < N; j++)
        {

            // This implementation is wrong because the if statement below stops the innermost for loop from running, so some comparisons will be ignored. 

            if (P.first == POINTS[j].first)
            {
                for (int k = j + 1; k < N; k++)
                {
                    if (P.second == POINTS[k].second)
                    {
                        // Compute height and width with points
                        int height = max(P.second, POINTS[j].second) - min(P.second, POINTS[j].second);
                        int width = max(P.first, POINTS[k].first) - min (P.first, POINTS[k].first);
                        solutions.push_back(width * height);
                    }
                }
            }
        }
    }

    out << *max_element(solutions.begin(), solutions.end()) << endl;


}