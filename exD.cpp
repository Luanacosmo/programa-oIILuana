#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const string naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};
const string valores[] = {"Ás", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};

struct Carta {
    string valor;
    string naipe;
};

void criarBaralho(Carta baralho[]) {
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baralho[index].naipe = naipes[i];
            baralho[index].valor = valores[j];
            index++;
        }
    }
}

void embaralharBaralho(Carta baralho[], int tamanho) {
    srand(time(0));
    for (int i = 0; i < tamanho; i++) {
        int r = rand() % tamanho;
        swap(baralho[i], baralho[r]);
    }
}

void distribuirCartas(Carta baralho[], Carta jogador1[], Carta jogador2[]) {
    for (int i = 0; i < 5; i++) {
        jogador1[i] = baralho[i];
        jogador2[i] = baralho[i + 5];
    }
}

void exibirCartas(const Carta jogador[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << jogador[i].valor << " de " << jogador[i].naipe << endl;
    }
}

int main() {
    Carta baralho[52];
    criarBaralho(baralho);
    embaralharBaralho(baralho, 52);

    Carta jogador1[5];
    Carta jogador2[5];

    distribuirCartas(baralho, jogador1, jogador2);

    cout << "Cartas do Jogador 1:" << endl;
    exibirCartas(jogador1, 5);
    cout << endl;

    cout << "Cartas do Jogador 2:" << endl;
    exibirCartas(jogador2, 5);

    return 0;
}
