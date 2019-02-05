#include<iostream>
using namespace std;

unsigned int factorial(unsigned int n)
{
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main()
{
	int num;
	int extra;
    cin >> num;
    cout << factorial(num) << endl;
    cin >> extra;
    cout << factorial(num) + extra << endl;
    return 0;
}
