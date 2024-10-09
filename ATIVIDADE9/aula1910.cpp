#include <iostream>
using namespace std;

int main() {
    int var1 = 10; 
    int var2 = 20;  

    int *ptr1 = &var1;  
    int *ptr2 = &var2;  

    if (ptr1 > ptr2) {
        cout << "var1 está em um endereço de memória mais alto." << endl;
    }
     else {
        cout << "var2 está em um endereço de memória mais alto." << endl;
    }

    return 0;
}
