#include <iostream>
#include <fstream>
using namespace std;

ifstream in("mixmilk.in");
ofstream out("mixmilk.out");

int main(void)
{
    int c1, m1, c2, m2, c3, m3;
    in >> c1 >> m1 >> c2 >> m2 >> c3 >> m3;

    // Pour 1:
    if (c2 >= (m1 + m2)) { m2 += m1; m1 = 0; }
    else { m1 = m1 - (c2 - m2); m2 = c2; }

    // Pour 2:
    if (c3 >= (m2 + m3)) { m3 += m2; m2 = 0; }
    else { m2 = m2 - (c3 - m3); m3 = c3; }

    // Pour 3: 
    if (c1 >= m1 + m3) { m1 += m3; m3 = 0;}
    else { m3 = m3 - (c1- m1); m1 = c1; }

    // Pour 4:
    if (c2 >= m1 + m2) { m2 += m1; m1 = 0; }
    else { m1 = m1 - (c2 - m2); m2 = c2; }

    out << m1 << endl;
    out << m2 << endl;
    out << m3 << endl;

}