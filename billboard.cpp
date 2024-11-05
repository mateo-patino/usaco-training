#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("billboard.in");
ofstream out("billboard.out");

bool isRectangle(int x1, int y1, int x2, int y2, int a, int b, int c, int d);

int main(void)
{
    int x1, y1, x2, y2, a, b, c, d;
    in >> x1 >> y1 >> x2 >> y2 >> a >> b >> c >> d;

    int area = abs(x2 - x1) * abs(y2 - y1);

    // NO INTERSECTION
    if (y2 <= b || d <= y1 || x2 <= a || c <= x1)
    {
        out << area;
    }
    // CONTAINED
    else if (x1 >= a && x2 <= c && y1 >= b && y2 <= d)
    {
        out << 0;
    }
    else if (isRectangle(x1, y1, x2, y2, a, b, c, d))
    {
        int overlap = (min(c, x2) - max(x1, a)) * (min(d, y2) - max(b, y1));
        out << area - overlap;
    }
    else { out << area; }
}

bool isRectangle(int x1, int y1, int x2, int y2, int a, int b, int c, int d)
{
    if (x1 >= a && x2 <= c) { return true; }
    if (y1 >= b && y2 <= d) { return true; }
    return false;
}