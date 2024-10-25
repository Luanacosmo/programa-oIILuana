#include<iostream>
using namespace std;

int trib(int n){
    if (n ==1 || n==0){
        return 0;
    }
    if(n ==2){
        return 1;
    }
    else {
        return trib(n - 1) + trib(n - 2) + trib(n - 3);
    }
}
int main(){
    int n; 
    cin >> n;
    cout << trib(n) << endl;
}