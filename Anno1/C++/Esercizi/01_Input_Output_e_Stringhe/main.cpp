#include <iostream>
#include <string>

int main() {
    int a, b;
    std::string nome;

    // Chiediamo ed estraiamo i due numeri in un colpo solo
    std::cout << "Inserisci due numeri: ";
    std::cin >> a >> b;

    // Pulizia buffer e lettura riga intera (Stdlib does it)
    std::cout << "Inserisci nome e cognome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    // Stampa finale senza variabili di supporto inutili
    std::cout << "Ciao " << nome << ", la somma e': " << (a + b) << std::endl;

    return 0;
}