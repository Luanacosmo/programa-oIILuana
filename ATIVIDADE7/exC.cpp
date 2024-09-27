#include <iostream>
using namespace std;

struct Complexo {
    double real;
    double imaginario;
};

void lerComplexo(Complexo *c) {
    cout << "Digite a parte real: ";
    cin >> c->real;
    cout << "Digite a parte imaginária: ";
    cin >> c->imaginario;
}

void somar(const Complexo *z, const Complexo *w, Complexo *resultado) {
    resultado->real = z->real + w->real;
    resultado->imaginario = z->imaginario + w->imaginario;
}

void subtrair(const Complexo *z, const Complexo *w, Complexo *resultado) {
    resultado->real = z->real - w->real;
    resultado->imaginario = z->imaginario - w->imaginario;
}

void multiplicar(const Complexo *z, const Complexo *w, Complexo *resultado) {
    resultado->real = z->real * w->real - z->imaginario * w->imaginario;
    resultado->imaginario = z->real * w->imaginario + z->imaginario * w->real;
}

void exibirComplexo(const Complexo *c) {
    if (c->imaginario >= 0)
        cout << c->real << " + " << c->imaginario << "i" << endl;
    else
        cout << c->real << " - " << -c->imaginario << "i" << endl;
}

int main() {
    Complexo z, w, resultado;

    cout << "Digite o primeiro número complexo (z):" << endl;
    lerComplexo(&z);

    cout << "Digite o segundo número complexo (w):" << endl;
    lerComplexo(&w);

    somar(&z, &w, &resultado);
    cout << "Soma: ";
    exibirComplexo(&resultado);

    subtrair(&z, &w, &resultado);
    cout << "Subtração: ";
    exibirComplexo(&resultado);

    multiplicar(&z, &w, &resultado);
    cout << "Produto: ";
    exibirComplexo(&resultado);

    return 0;
}
