#include <iostream>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string first_name, last_name;
    cout << "Enter Your first name please";
    cin >> first_name;
    cout << "Enter your last name please";
    cin >> last_name;
    cout << "Your full name is " << first_name << " " << last_name;
    return 0;
}