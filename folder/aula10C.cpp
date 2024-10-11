#include <iostream>
using namespace std;

void lerNotas(float* notas, int n);  
void calcularMedia(float* notas, int n);  

int main() {
    int n;  
    cout << "Digite a quantidade de alunos: ";
    cin >> n;

    
    float* notas = new(nothrow) float[n];
    if (notas == nullptr) {
        cout << "Falha na alocacao de memoria" << endl;
        return 1;
    }

    lerNotas(notas, n);       
    calcularMedia(notas, n);   

    delete[] notas; 
    notas = nullptr;

    return 0;
}

void lerNotas(float* notas, int n) {
    cout << "Digite as notas dos alunos: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Nota do aluno " << i + 1 << ": ";
        cin >> notas[i]; 
    }
}

void calcularMedia(float* notas, int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += notas[i];  
    }
    float media = soma / n;  
    cout << "A media aritmetica das notas e: " << media << endl;
}
