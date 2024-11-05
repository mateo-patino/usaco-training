                // The fourth point in POINTS is the one that really works out. Bu when origin = 4 and we'll actually check if it works as an origin, the for loops
                // will no longer be ran because 4 !< n, so we'll never check the rest of points with respect to point 4 as an origin. 
                // That is why Carrara's solution works. He is treating all points as potential origins!

                // Your notion of an if statement is not accurate of what they do. doing do a == b is the same as b == a. REMEMBER THIS. FEEL AND EMBRACE THIS. 
                // If you have n elements to compare, the number of statements you'll have to write is n choose 2 (because you always compare by sets of 2). 
                // THERE IS NO ORDER IN AN IF STATEMENT. NO ORDER!!!

                // When you do stuff like the x1 == x2 || x1 == x3 || x2 == x3, you are correctly comparing all the coordinates against each other.
                // When you need to operate with them, max() will be your best friend because some xi - xj will yield 0, while others (the values you're interested
                // in) will yield non-zero. 
                // To find the maximum of three or more numbers, you nest a max() within more max().
                // int largest = max(10, max(11, 6));

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

ifstream in("triangles.in");
ofstream out("triangles.out");

int main(void)
{
    int n;
    in >> n;

    vector<pair<int, int>> POINTS(n);
    vector<int> solutions;
    for (int i = 0; i < n; i++) { in >> POINTS[i].first >> POINTS[i].second; }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                // cout << "i: " << POINTS[i].first << POINTS[i].second << " j: " << POINTS[j].first << POINTS[j].second << " k: " << POINTS[k].first << POINTS[k].second << endl << endl;
                int x1 = POINTS[i].first; int y1 = POINTS[i].second;
                int x2 = POINTS[j].first; int y2 = POINTS[j].second;
                int x3 = POINTS[k].first; int y3 = POINTS[k].second;

                if ((x1 == x2 || x1 == x3 || x2 == x3) && (y1 == y2 || y1 == y3 || y2 == y3))
                {
                    int width = max(abs(x1 - x2), max(abs(x1 - x3), abs(x2 - x3)));
                    int height = max(abs(y1 - y2), max(abs(y1 - y3), abs(y2 - y3)));
                    solutions.push_back(width * height);
                }
            }
        }
    }

    out << *max_element(solutions.begin(), solutions.end()) << endl;
}