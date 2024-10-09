#include <iostream>
using namespace std;

int main(){
    int *p;
    int x=2;
    p = &x;
    cout << *p << endl;
    p ++;
    cout << *p << endl;
    p--;
    cout << *p << endl;
}
