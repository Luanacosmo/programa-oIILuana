#include <iostream>
using namespace std;

extern void modificaGlobal();  

int globalVar = 10;

int main() {
    cout << "Valor inicial da variável global: " << globalVar << endl;

    modificaGlobal();

    return 0;
}
