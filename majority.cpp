#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
#include <cmath>
#include <cstddef>
#include <map>
using namespace std;

ifstream in("majority.in");

int main(void)
{
    int T;
    in >> T;

    for (int testCase = 0; testCase < T; testCase++)
    {

        int N; 
        in >> N;
        vector<int> HAYS(N + 1);
        for (int i = 1; i <= N; i++)
        {
            in >> HAYS[i];
        }

        map<int, int>counters;
        set<int>SOLS;
        for (int start = 1; start < N; start++)
        {
            for (int end = start + 1; end <= N; end++)
            {
                // Calculate minimum
                int min = 0;
                int numCows = end - start +1;
                if (numCows % 2 == 0) { min = (numCows/2) + 1; }
                else { min = (numCows + 1)/ 2; }

                int tmp = HAYS[start];
                bool cont = false;
                for (int i = start; i <= end; i++)
                {
                    if (HAYS[i] != tmp) { cont = true; break; }
                }

                if (cont)
                {
                    for (int i = start; i <= end; i++)
                    {
                        counters[HAYS[i]]++;
                    }
                }

                int max = 0;
                int index = 0;
                for (int i = 0; i < counters.size(); i++)
                {
                    if (counters[i] > max) { max = counters[i]; index = i; }
                }

                counters.clear();
                cout << max << " " << min << endl;

                // cout << "max: " << max << " " << "min: " << min << endl;
                if ((max >= min)) { 
                    if (testCase == 1) { 
                        cout << "START: " << start << " END: " << end << " MIN: " << min << " MAX: " << max;
                        cout << " HAY: " << index << endl;
                    }
                    
                    SOLS.insert(index); 
            }

        }
        // Append your solution at the end of each test case

        if (SOLS.size() != 0)
        {
            for (auto itr = SOLS.begin(); itr != SOLS.end(); ++itr)
            {
               // cout << *itr << " ";
            }
        }
        else { cout << -1; }
        // cout << endl;
    }
}
}
