#include <iostream>

void azzeramento(int &n) {n=0;}

int main() {
    int numero=10;
    azzeramento(numero);
    std::cout<<numero;
    return 0;
}