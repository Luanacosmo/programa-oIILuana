#include <iostream>
using namespace std;

void funcao1(int v[]);

int main() {
    int v[] = {0, 1, 2, 3, 4, 5, 6, 7};
    funcao1(v);  

    return 0;
}

void funcao1(int v[]) {
    int* p1;  
    int* p2;  

    p1 = &v[0];  
    p2 = &v[7];  

    cout << "Endereco de v[0]: " << p1 << endl;
    cout << "Endereco de v[7]: " << p2 << endl; 
}
