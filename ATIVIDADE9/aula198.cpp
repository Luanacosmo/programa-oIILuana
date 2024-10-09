#include <iostream>
using namespace std;

void incrementaVariavelRegistro() {
    register int contador = 0;  
    contador++;                 
    cout << "Valor do contador (variável de registro): " << contador << endl;
}

int main() {
    incrementaVariavelRegistro();  
    incrementaVariavelRegistro();  
    incrementaVariavelRegistro();  

    return 0;
}
