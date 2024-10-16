#include <iostream>
using namespace std;

int buscarElemento(int A[], int l, int n, int v) {
    for (int i = l; i <= n; i++) {
        if (A[i] == v) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {10, 20, 30, 40, 50, 60, 70, 80};
    int l = 2;
    int n = 6;
    int v = 50;

    int resultado = buscarElemento(A, l, n, v);

    if (resultado != -1) {
        cout << "Elemento " << v << " encontrado na posição: " << resultado << endl;
    } else {
        cout << "Elemento " << v << " não encontrado." << endl;
    }

    return 0;
}
// Complexidade Linear O(n)
