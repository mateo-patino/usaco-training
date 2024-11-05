#include <iostream>
#include <fstream>
using namespace std;

ifstream in("mixmilk.in");
ofstream out("mixmilk.out");

int main(void)
{
    int c1, m1;
    int c2, m2;
    int c3, m3;

    in >> c1;
    in >> m1;
    in >> c2;
    in >> m2;
    in >> c3;
    in >> m3;

    if (m1 + m2 <= c2) { m2 += m1; m1 = 0; } 
    else { m2 = c2; m1 = (m1 + m2) - c2; }

    if (m2 + m3 <= c3) { m3 += m2; m2 = 0; }
    else { m3 = c3; m2 = (m2 + m3) - c3; }

    if (m3 + m1 <= c1) { m1 += m3; m3 = 0; }
    else { m3 = (m1 + m3) - c1; m1 = c1; }

    if (m1 + m2 <= c2) { m2 += m1; m1 = 0; } 
    else { m2 = c2; m1 = (m1 + m2) - c2; }

    out << m1 << endl;
    out << m2 << endl; 
    out << m3 << endl;
}