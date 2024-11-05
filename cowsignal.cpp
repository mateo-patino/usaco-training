#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream in("cowsignal.in");
ofstream out("cowsignal.out");

int main(void)
{
    // USE TWO NESTED VECTORS OF VECTORS TO ORGANIZE THE SIGNAL DATA
    int rows, columns, k;
    in >> rows >> columns >> k;

    vector<vector<char>> signal(rows, vector<char>(columns));

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++) { in >> signal[r][c]; }
    }

    vector<vector<char>> resultSignal;

    for (int r = 0; r < rows; r++)
    {
        vector<char> row;
        for (int c = 0; c < columns; c++)
        {
            for (int times = 0; times < k; times++) { row.push_back(signal[r][c]); }
        }

        for (int times = 0; times < k; times++) { resultSignal.push_back(row); }
    }

    for (int r = 0; r < k * rows; r++)
    {
        for (int c = 0; c < k * columns; c++) { out << resultSignal[r][c]; }
        out << "\n";
    }
}