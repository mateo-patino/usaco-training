#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

// ifstream in("abc.in");

int main(void)
{
    vector<int> nums(7);
    for (int i = 0; i < 7; i++) { cin >> nums[i]; }

    sort(nums.begin(), nums.end());
    int A = nums[0];
    int B = nums[1];
    int ABC = nums[6];
    int C = ABC - A - B;

    cout << A << " " << B << " " << C << endl;

}
