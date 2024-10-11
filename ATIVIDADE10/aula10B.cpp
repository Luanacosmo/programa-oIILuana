#include <iostream>
using namespace std;

void inserir(int *v, int n);  
void imprimir(int *v, int n);

int main() {
    int *v = nullptr, n;   
    cin >> n;

    v = new(nothrow) int[n];   
    if (v == nullptr) {
        cout << "Falha de alocacao de memoria" << endl;
        return 1;
    }

    inserir(v, n);        
    imprimir(v, n);      
     
    delete[] v;           
    v = nullptr;          
    return 0;
}

void inserir(int *v, int n) {  
    for (int i = 0; i < n; i++) {
        *(v + i) = i * 2;  // Aritmética de ponteiros
    }
}

void imprimir(int *v, int n) {
    for (int i = 0; i < n; i++) {
        cout << *(v + i) << " ";  // Aritmética de ponteiros
    }
    cout << endl;
}
