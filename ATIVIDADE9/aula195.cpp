#include <iostream>
using namespace std;

int main(){
    int *p1, *p2;
    int x=1, y=4;
    p1 = &x;
    p2 = &y;
    if (*p1 == *p2){
        cout << "o conteudo dos ponteiros sao iguais" << endl;
    }
    else{
        cout << "o conteudo dos ponteiros e diferente" << endl;
    }
}