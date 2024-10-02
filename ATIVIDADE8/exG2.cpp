#include <iostream>
using namespace std;


void unirVetores(int v1[], int tam1, int v2[], int tam2, int vetorResultado[]) {
    for (int i = 0; i < tam1; ++i) {
        vetorResultado[i] = v1[i];
    }
    for (int i = 0; i < tam2; ++i) {
        vetorResultado[tam1 + i] = v2[i];
    }
}

int main() {
    int v1[] = {1, 2, 3, 4};
    int v2[] = {5, 6, 7};

    int tam1 = sizeof(v1) / sizeof(v1[0]);
    int tam2 = sizeof(v2) / sizeof(v2[0]);

    int vetorResultado[tam1 + tam2];

    unirVetores(v1, tam1, v2, tam2, vetorResultado);

    cout << "Vetor resultante: ";
    for (int i = 0; i < tam1 + tam2; ++i) {
        cout << vetorResultado[i] << " ";
    }
    cout << endl;

    return 0;
}
