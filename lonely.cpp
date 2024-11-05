#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// ifstream in("lonely.in");

vector<string> SUBSTRINGS;

void calculateSubstrings(void)
{
    int N;
    string line;
    cin >> N >> line;

    for (int substringSize = 3; substringSize <= N; substringSize++)
    {
        // cout << "SUBSTRING SIZE: " << substringSize << endl;
        for (int index = 0; index + (substringSize - 1) < N; index++)
        {
            string substring = "";

            for (int i = 0; i < substringSize; i++)
            {
                substring.push_back(line[index + i]);
            }
            SUBSTRINGS.push_back(substring);
        }
    }
}


// Very good job implementing the algorithms below and above; they work really well!

// Apparently, you misread the problem and you only needed to find all substrings with length of 3 (at least that's what the official solution indicates to do).
// Write another solution just finding substrings of length of 3 :)

// Some things you learned today:
//      - You are very good! You can be very smart when you stay calm and implement a solution simply and pragmatically. 
//        The main area you need to work on is implementation; being able to write correct C++ code, correct code! That's where you need to keep working on.
//        Luckily, improving your implementation skills is really easy and you have enough time to do it until January 29! 
//      - You also learned that it's better to go on the official USACO website and solve problems from recent (past two or three) years. This is
//        better than surfing the USACO.guide website looking for a problem. 
//      - Some things to do include: go to Carrara's "35-minute Full Contest Live-solve!!" video and do the three problems from that Bronze contest.
//        Remember to compare your solutions and approach to Carrara's and read VERY, VERY carefully what problem-solving practices you can imitate from him. 
//        After re-implementing the lonely photos problem again with 3-length substrings, this is the next task you'll tackle. 
// YOU ALSO LEARNED THAT YOU DON'T NEED THREE HOURS DAILY TO IMPROVE MUCH! Bronze is in fact very, very easy and does not require you to put in crazy amounts of work
// Therefore, with at least an hour and 20 minutes simulating one problem in a real contest, you can improve significantly!

int main(void)
{
    // Calculate all substrings
    calculateSubstrings();

    // Verify what photos are lonely photos

    long long size = SUBSTRINGS.size();
    int lonelyPhotos = 0;
    string substring = "";

    for (long long i = 0; i < size; i++)
    {
        
        substring = SUBSTRINGS[i];
        // cout << "SUBSTRING: " << substring << endl;
        int subsSize = substring.length();
        int Gcount = 0;
        int Hcount = 0;

        for (int j = 0; j < subsSize; j++)
        {
            if (substring[j] == 'G') { Gcount++; }
            else if (substring[j] == 'H') { Hcount++; }
        }

        if (Gcount == 1 || Hcount == 1) { lonelyPhotos++; }
    }

    cout << lonelyPhotos << endl;
}