#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};  
    int *ptr = arr;  

    int tamanho = sizeof(arr) / sizeof(arr[0]); 

    
    for (int i = 0; i < tamanho; i++) {
        cout << "Elemento " << i << ": " << *(ptr + i) << endl;
    }

    return 0;
}
