#include <iostream>
using namespace std;

int main(){
    int *p1, *p2;
    int x=4, y=8;
    p1 = &x;
    p2 = &y;
    int d = *p2 - *p1;
    cout << d << endl;
}