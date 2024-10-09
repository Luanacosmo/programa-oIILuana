#include <iostream>
using namespace std;

int main(){
    int *p;
    int x = 5;
    p = &x;
    cout << *p << endl;
    p += 1;
    cout << *p << endl;
}
