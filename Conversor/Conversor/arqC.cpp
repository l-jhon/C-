#include<iostream>
#include<string>
using namespace std;
int main(){
float condition;
string line;
int a;
int b;
a = 10;
if (a > b || b==a )
{
    cout << "The variable is set to true." << endl;
    cin >> line;
    a = a + b * 12 / 2;
}
else 
{
    cout << "The variable is set to false." << endl;
}
return 0;
}
