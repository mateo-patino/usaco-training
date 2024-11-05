#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream in("word.in");
ofstream out("word.out");

int main(void)
{
    int N, K;
    in >> N;
    in >> K;

    string words[N];
    for (int i = 0; i < N; i++) { in >> words[i]; }

    int total = 0;
    for (int i = 0; i < N; i++)
    {
        if ((total + words[i].size() + words[i + 1].size() <= K) && (i != N - 1))
        {
            out << words[i] << " ";
            total += words[i].size();
        }
        else if (total + words[i].size() <= K)
        {
            out << words[i] << "\n";
            total = 0;
        }
    }
}