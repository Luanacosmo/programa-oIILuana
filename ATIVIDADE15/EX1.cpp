#include<iostream>
using namespace std;

int soma(int n);

int main(){
    int n; 
    cin >> n;
    cout << soma(n) << endl;
}
int soma(int n){
    if (n <= 1)
    return 1;
    else
    return n + soma(n - 1);
}
