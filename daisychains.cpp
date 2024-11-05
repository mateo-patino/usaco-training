#include <iostream>
#include <fstream>
#include <vector>
using namespace std;



// Nice NICEEE!! You solved this one in less than one hour all by yourself!
// From this problem, remember to not mix up 'i' 'j' and 'index' when doing nested for loops
// to iterate through ranges within a vector or array. Also remember to NOT ASSUME
// your input will contain integers IF they do NOT EXPLICITLY say it; you may get FLOATS
// and then you'll have to use DOUBLES data types and you should be good making comparisons
// and not having to deal with decimal imprecision and all that. 



// ifstream in("daisychains.in");

int main(void)
{
    int n;
    cin >> n;
    vector<double>petals(n);
    for (int i = 0; i < n; i++) { cin >> petals[i]; }

    int counter = 0;
    double sum = 0;
    double avg = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int index = i; index <= j; index++)
            {   
                sum += petals[index];
            }
            avg = sum / (j - i + 1);
            

            for (int index = i; index <= j; index++)
            {
                if (petals[index] == avg)
                {
                    // cout << "RANGE: " << i << " " << j << " ";
                    // cout << "P: " << petals[i] << " " << "AVG: " << avg << endl;
                    counter++;
                    break;
                }
            }
            avg = 0;
            sum = 0;
        }
    }

    cout << counter + n << endl;
}

