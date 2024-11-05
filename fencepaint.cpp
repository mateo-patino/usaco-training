#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream in("facepaintin.in");
ofstream out("facepaintout.out");

int main(void) 
{
    int a, b, c, d;
    in >> a >> b >> c >> d;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;

    int john = b - a;
    int bessie = d - c;
    int offset = d - a;

    if (offset < 0) {
        out << john + bessie << endl;
        cout << john + bessie << endl;
    }
    else {
        out << john + bessie - offset << endl;
        cout << john + bessie - offset << endl;
    }

}