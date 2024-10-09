#include <iostream>
using namespace std;

void incrementaVariavelEstatica() {
    static int contador = 0;  
    contador++;              
    cout << "Valor do contador: " << contador << endl;
}

int main() {
    incrementaVariavelEstatica();  
    incrementaVariavelEstatica(); 
    incrementaVariavelEstatica();  

    return 0;
}
