#include <iostream>
using namespace std;

extern int globalVar;  

void modificaGlobal() {
    globalVar = 20; 
    cout << "Novo valor da variável global: " << globalVar << endl;
}
