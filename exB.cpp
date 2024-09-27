#include<iostream>
using namespace std;

struct vetor{
    float x;
    float y;
    float z;
};

int main(){
    int vetor1, vetor2;
    vetor1.x = 0; 
    vetor1.y = 0;
    vetor1.z = 0;
    vetor2.x = 0;
    vetor2.y = 0;
    vetor2.z = 0;
    cout << "Digite os valores do primeiro vetor:" << endl;
    cin >> vetor1.x = 0; 
    cin >> vetor1.y = 0;
    cin >> vetor1.z = 0;

    cout << "Digite os valores do segundo vetor:"
    cin >> vetor2.x = 0;
    cin >> vetor2.y = 0;
    cin >> vetor2.z = 0;


    cout << "x:" << vetor1.x + vetor2.x << endl;
    cout << "y:" << vetor1.y + vetor2.y << endl;
    cout << "z:" << vetor1.z + vetor2.z << endl;
}