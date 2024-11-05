#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;

ifstream in("teleport.in");
ofstream out("teleport.out");
int withTele(int a, int b, int x, int y);

int main(void)
{   
    int a, b, x, y;
    in >> a >> b >> x >> y;

    if (withTele(a, b, x, y) > abs(b - a))
    {
        out << abs(b - a) << endl;
    }
    else if (withTele(a, b, x, y) < abs(b - a) && withTele(a, b, x, y) != - 1)
    {
        out << withTele(a, b, x, y) << endl;
    }

}

int withTele(int a, int b, int x, int y)
{
    int XtoB;
    int YtoB;

    int AtoX = abs(x - a);
    int AtoY = abs(y - a);
    if (AtoX < AtoY)
    {
        YtoB = abs(y - b);
        return (AtoX + YtoB);
    }
    else if (AtoX > AtoY)
    {   
        XtoB = abs(x - b);
        return (AtoY + XtoB);
    }
    else
    {
        return -1;
    }
}