#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int bananas;
    int price;
    int money;

    cin >> price >> money >> bananas;

    long long total = 0;
    for (int i = 1; i <= bananas; i++)
    {
        total = total + (i * price);
    }
    if (total > money)
    {
        cout << (total - money) << endl; 
    }
    else
    {
        cout << "0";
    }
}