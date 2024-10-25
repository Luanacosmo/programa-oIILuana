#include<iostream>
using namespace std;

int somaPares(int n){
    if (n <= 0){
        return 0;
    }
    else if(n % 2 == 0)
    return n + somaPares(n - 2);
    else   
    return somaPares(n - 1);
}

int main(){
    int n;
    cin >> n;
    cout << somaPares(n)  << endl;
}
