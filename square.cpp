#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ifstream in("square.in");
ofstream out("square.out");

int main(void)
{
    vector<int> a(5);
    vector<int> b(5);
    for (int i = 1; i <= 4; i++) { in >> a[i]; }  
    for (int i = 1; i <= 4; i++) { in >> b[i]; }

    int x[] = {a[1], a[3], b[1], b[3]};
    int y[] = {a[2], a[4], b[2], b[4]};

    int width = abs(*max_element(x, x + 4) - *min_element(x, x + 4));
    int height = abs(*max_element(y, y + 4) - *min_element(y, y + 4));
     
    int size = max(width, height);
    out << size * size << endl;

}