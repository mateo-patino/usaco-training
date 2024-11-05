#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

ifstream in("shuffle.in");
ofstream out("shuffle.out");

vector<int> unshuffle(vector<int> nextState, vector<int> shuffle, int k);

int main(void)
{
    int n;
    in >> n;

    vector<int> shuffle(n+1);
    vector<int> finalState(n+1);

    for (int i = 1; i < n+1; i++) { in >> shuffle[i]; }
    for (int i = 1; i < n+1; i++) { in >> finalState[i]; }

    vector<int> middleState = unshuffle(finalState, shuffle, n+1);
    vector<int> firstState = unshuffle(middleState, shuffle, n+1);
    vector<int> oState = unshuffle(firstState, shuffle, n+1);

    for (int i = 1; i < n + 1; i++) { out << oState[i] << "\n"; }
}

vector<int> unshuffle(vector<int> nextState, vector<int> shuffle, int k)
{
    vector<int> previousState(k);
    for (int i = 1; i < k; i++)
    {   
        // BRILLIANT SOLUTION! CONCISE, CLEAN, PERFECT!
        previousState[i] = nextState[shuffle[i]];
    }

    return previousState;
}

