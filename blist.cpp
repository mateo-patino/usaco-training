#include <vector>
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream in("blist.in");
ofstream out("blist.out");

struct Cow 
{
    int start, end;
    int bucketsNeeded;
};

int main(void)
{
    vector<Cow> cow;
    int n;
    in >> n;

    for (int i = 0; i < n; i++) { in >> cow[i].start >> cow[i].end >> cow[i].bucketsNeeded; }


    // Try implementing the original approach you had were you verify for cross-overlaping.
}