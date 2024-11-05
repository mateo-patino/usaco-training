#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int iteration = 0;
    int problems = 0;
    int n;
    cin >> n;

    string line;
    while (getline(cin, line))
    {
        int solutions = 0;
        if (iteration > 0)
        {
            for(int i = 0; i < 5; i++)
            {
                if (line[i] - '0' == 1)
                {
                    solutions++;
                }
            }
            if (solutions >= 2)
            {
                problems++;
            }
        }
        if (iteration == n)
        {
            cout << problems << endl;
            break;
        }
        iteration++;
    }

}