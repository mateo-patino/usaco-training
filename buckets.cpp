#include <iostream>
#include <fstream>
using namespace std;

ifstream in("buckets.in");
ofstream out("buckets.out");

int main(void)
{
    int xLAKE, yLAKE;
    int xROCK, yROCK;
    int xBARN, yBARN;

    for (int i = 1; i < 11; i++)
    {
        for (int j = 1; j < 11; j++)
        {
            char tmp;
            in >> tmp;
            if (tmp == 'L')
            {
                xLAKE = j;
                yLAKE = i;
            }
            else if (tmp == 'R')
            {
                xROCK = j;
                yROCK = i;
            }
            else if (tmp == 'B')
            {
                xBARN = j;
                yBARN = i;
            }
        }
    }

    int xdistance = abs(xLAKE - xBARN) - 1;
    int ydistance = abs(yLAKE - yBARN) - 1;
    int total = xdistance + ydistance + 1;

    if ((xLAKE == xROCK && xROCK == xBARN) &&
        ((yLAKE > yROCK && yROCK > yBARN) || 
        (yLAKE < yROCK && yROCK < yBARN))) 
        { total += 2; }

    else if (yLAKE == yROCK && yROCK == yBARN &&
        ((xLAKE > xROCK && xROCK > xBARN) || 
        (xLAKE < xROCK && xROCK < xBARN)))
        { total += 2; }

    out << total << "\n";
}