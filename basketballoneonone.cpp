#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

int toValue (char c);

int main(void) 
{
    string input;
    cin >> input;
    
    int ascore = 0;
    int bscore = 0;

    int iSize = input.size();
    for (int i = 0; i < iSize - 1; i++) 
    {
        if ((ascore >= 11 || bscore >= 11) && (abs(ascore - bscore) >= 2)){
            if (ascore > bscore) {
                cout << "A: " << ascore << endl;
                cout << "B: " << bscore << endl;
                cout << 'A' << endl;
                return 0;
            }
            else {
                cout << "A: " << ascore << endl;
                cout << "B: " << bscore << endl;
                cout << 'B' << endl;
                return 0;
            }
        }
        else 
        {
            if (input[i] == 'A') {
                ascore += toValue(input[i + 1]);
            }
            else if (input[i] == 'B') {
                bscore += toValue(input[i + 1]);
            }
        }
    }

    cout << "A: " << ascore << endl;
    cout << "B: " << bscore << endl;

    if (ascore > bscore) cout << "A" << endl;
    else cout << "B" << endl;
    
}


int toValue(char c) {
    return c - 48;
}