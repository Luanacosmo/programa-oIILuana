#include <iostream>
using namespace std;

typedef struct{
    int dia;
    int mes;
    int ano;
} Data;
typedef struct{
    int minuto;
    int hora;
} Horario;
typedef struct{
    string compromisso;
    Data dma;
    Horario mh;
}Compromisso;

void preenche(Compromisso agenda[]);
void imprime(Compromisso agenda[]);

int main(){
    int N;
    cout << "digite quantos compromissos voce tera no mes: " << endl;
    cin >> N;
    Compromisso agenda;
    preenche(&agenda);
    for (int i = 0; i < N; i++){
    //imprime(agenda[i]);
}
}
void preenche(Compromisso (*agenda)){
    cout << "data: ";
    cin >> agenda->dma.dia;
    cin >> agenda->dma.mes;
    cin >> agenda->dma.ano;
    cout << "Horário:";
    cin >> agenda->mh.hora;
    cin >> agenda->mh.minuto;
    cout << "compromisso: ";
    getw;
    getline(cin,agenda->compromisso);
}
void imprime(Compromisso (*agenda)){
    cout << "Compromisso: " << agenda->compromisso << endl;
    cout << "Data: " << agenda->dma.dia << agenda->dma.mes << agenda->dma.ano << endl;
    cout << "horario: " << agenda->mh.hora << agenda->mh.minuto << endl;
}

