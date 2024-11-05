#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream in("cane.in");

int main(void)
{
    long long N;
    long long M;

    in >> N >> M;

    vector<long long> cows(N);
    vector<long long> canes(M);

    for (int i = 0; i < N; i++) { in >> cows[i]; }
    for (int i = 0; i < M; i++) { in >> canes[i]; }

    for (int ca = 0; ca < M; ca++)
    {
        long long startingH = canes[ca];
        for (int co = 0; co < N; co++)
        {
            cout << "Cane number " << ca << endl;
            cout << "Starting height: " << startingH << endl;
            cout << "Cow's height:  " << cows[co] << endl;

            cout << endl;
            if (startingH == 0) { break; }
            else
            { 
                if (co == 0)
                {
                    if (startingH > cows[co]) { startingH = cows[co]; cows[co] += cows[co]; }
                    else if (startingH == cows[co]) { startingH = 0; cows[co] += cows[co]; }
                    else { cows[co] += startingH; startingH = 0; }
                }
                else
                {
                    if (startingH < cows[co]) { long long tmp = startingH; startingH = cows[co]; cows[co] += (cows[co] - tmp); }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) { cout << cows[i] << endl; }
}