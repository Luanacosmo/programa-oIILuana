#include <iostream>
using namespace std;

int contarDigitos(int num) {
    if (num == 0) {
        return 0;
    } 
    else {
        return 1 + contarDigitos(num / 10);
    }
}

int main() {
    int num;
    cout << "Digite um numero: ";
    cin >> num;
    cout << "O numero tem " << contarDigitos(num) << " digitos." << endl;
    
    return 0;
}