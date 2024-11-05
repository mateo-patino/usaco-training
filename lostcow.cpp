#include <iostream>
#include <fstream>
using namespace std;

ifstream in("lostcow.in");
ofstream out("lostcow.out");

int main(void)
{
    int x, y;
    in >> x >> y;

    // John is to the left of Bessie
    bool direction = true;
    int distance = 0;
    int position = x;
    int change = 1;
    if (y > x) 
    {
        while (position < y)
        {
            if (direction) 
            { 
                if (change == 1) { position++; } 
                else { position = x + change; }
                distance += 1.5 * abs(position - x);
                change = 2 * change;
                direction = false;
            }
            else 
            {
                
                position = x - change;
                distance += 1.5 * abs(position - x);
                change = 2 * change;
                direction = true;
            }
        }
        distance -= position - y;
    }
    else if (y < x)
    {
        while (position > y)
        {
            if (direction) 
            { 
                if (change == 1) { position++; } 
                else { position = x + change; }
                distance += 1.5 * abs(position - x);
                change = 2 * change;
                direction = false;
            }
            else 
            {
                position = x - change;
                distance += 1.5 * abs(position - x);
                change = 2 * change;
                direction = true;
            }
        }
        distance -= y - position;
    }
    else { distance = 0; }

    out << distance;
}