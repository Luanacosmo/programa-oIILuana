#include <iostream>
using namespace std;

void separarParesImpares(int* vetor, int tamanho, int* pares, int* impares, int& tamPares, int& tamImpares) {
    tamPares = 0;
    tamImpares = 0;

    for (int i = 0; i < tamanho; ++i) {
        if (*(vetor + i) % 2 == 0) {
            *(pares + tamPares) = *(vetor + i); 
            tamPares++;
        } else {
            *(impares + tamImpares) = *(vetor + i); 
            tamImpares++;
        }
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    int pares[tamanho];
    int impares[tamanho];

    int tamPares = 0, tamImpares = 0;

    separarParesImpares(vetor, tamanho, pares, impares, tamPares, tamImpares);

    cout << "Elementos pares: ";
    for (int i = 0; i < tamPares; ++i) {
        cout << *(pares + i) << " ";
    }
    cout << endl;

    cout << "Elementos ímpares: ";
    for (int i = 0; i < tamImpares; ++i) {
        cout << *(impares + i) << " ";
    }
    cout << endl;

    return 0;
}
