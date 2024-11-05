#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

ifstream in("breedflip.in");
ofstream out("breedflip.out");


// YOU SOLVED THIS PROBLEM IN YOUR FIRST TRY! Fantastic! 
// Now you know about the approach of dealing with strings by using start and ending points:
// you iterate through the string and you set start and ending points at particular indexes to then access
// all the values in between those indexes. 

int main(void)
{
    int n;
    string A, B;
    in >> n >> A >> B;

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        // Before the outer loop starts again, you better have changed A and B. 
        if (A[i] != B[i])
        {
            int start = i;
            int end = -1;
            for (int s = i + 1; s < n; s++)
            {
                if (A[s] == B[s])
                {
                    end = s;
                    break;
                }
            }

            // If every character after start must be flipped
            if (end == -1) { end = n; }

            // Flip
            for (int j = start; j < end; j++)
            {
                if (B[j] == 'G') { B[j] = 'H'; }
                else { B[j] = 'G'; }
            }
            counter++;
        }
    }

    out << counter << endl;
}