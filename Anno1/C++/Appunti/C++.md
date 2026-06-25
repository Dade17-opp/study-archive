Appunti C++ - Fondamenti per l'Esame
1. Input/Output e Stringhe
Definizione
L'Input/Output in C++ si gestisce tramite il concetto di flussi di dati (stream) includendo le librerie <iostream> e <string>. Questo sistema sostituisce interamente le funzioni printf e scanf del C, garantendo maggiore sicurezza e astrazione.

Punti Chiave
std::cout: Flusso di uscita (operatore <<). Riconosce i tipi di dato in automatico senza bisogno di formattatori (%d, %f).

std::cin: Flusso di ingresso (operatore >>). Legge parola per parola, interrompendosi al primo spazio bianco o carattere Invio (\n).

std::string: Gestisce il testo come tipo di dato nativo. Supporta il confronto diretto tramite == e la concatenazione tramite l'operatore +.

std::getline(std::cin, var): Funzione della libreria standard che legge un'intera riga di testo, spazi inclusi, fino alla pressione del tasto Invio.

std::cin.ignore(): Svuota il buffer di input. È fondamentale utilizzarlo prima di un getline se l'istruzione precedente è stata un std::cin >>, per evitare il salto della lettura del testo.

Codice Minimo Funzionante
C++

#include <iostream>
#include <string>

int main() {
    int a, b; std::string nome;

    std::cout << "Inserisci due numeri: ";
    std::cin >> a >> b;

    std::cout << "Inserisci nome e cognome: ";
    std::cin.ignore();
    std::getline(std::cin, nome);

    std::cout << "Ciao " << nome << ", la somma e': " << (a + b) << std::endl;
    return 0;
}
2. Passaggio per Riferimento (Reference)
Definizione
Un reference (&) è un alias, ovvero un soprannome, di una variabile già esistente. Consente a una funzione di accedere e modificare direttamente la cella di memoria della variabile originale, eliminando la necessità e la sintassi complessa dei puntatori (*).

Punti Chiave
Sintassi: Si dichiara posizionando l'operatore & accanto al tipo di dato (int &ref = x;). Una volta creato, si utilizza come una variabile normale senza modificatori.

Vincoli: Deve essere obbligatoriamente inizializzato al momento della creazione, non può mai essere nullo (NULL) e non può cambiare il suo "bersaglio" nel corso del programma.

Uso nelle Funzioni: Permette modifiche permanenti alle variabili passate come argomento e previene la copia inutile in memoria di strutture dati o oggetti pesanti.

Trabocchetto d'esame: Non accetta valori costanti letterali (Rvalue) come parametri diretti (es. funzione(10); genera un errore di compilazione poiché il valore 10 non corrisponde a una variabile modificabile in memoria).

Codice Minimo Funzionante
C++

#include <iostream>

void azzera(int &n) {
    n = 0;
}

int main() {
    int numero = 10;
    azzera(numero); // Passaggio pulito senza l'operatore & nel main
    std::cout << "Il valore azzerato e': " << numero << std::endl;
    return 0;
}
3. Classi e Oggetti (OOP)
Definizione
Una classe rappresenta un modello astratto che unisce dati (Attributi) e funzioni (Metodi) in un unico blocco logico indipendente. L'oggetto costituisce l'istanza concreta di tale classe.

Punti Chiave
private: Sezione che racchiude gli attributi protetti (incapsulamento). Non sono accessibili né modificabili direttamente dall'esterno (es. dal main), ma esclusivamente dai metodi interni alla classe stessa.

public: Sezione che contiene i metodi accessibili dall'esterno, definendo l'interfaccia sicura per interagire con l'oggetto.

Costruttore: Metodo speciale con lo stesso nome della classe e privo di tipo di ritorno. Inizializza l'oggetto alla nascita tramite la sintassi efficiente Initialization List (: attributo(valore)).

Setter: Metodo pubblico implementato per modificare il valore di un attributo privato quando l'oggetto è già esistente.

Destruttore: Metodo speciale contrassegnato dalla tilde (~NomeClasse). Viene invocato automaticamente dal sistema quando l'oggetto esce dal proprio raggio di azione (scope) per rilasciare le risorse e pulire la memoria.

Costruttore di Default: Costruttore privo di parametri. Diventa necessario ridefinirlo esplicitamente tramite l'overloading se è stato introdotto un costruttore parametrico, consentendo così la creazione di oggetti vuoti (es. Rettangolo r;).

Codice Minimo Funzionante
C++

#include <iostream>

class Rettangolo {
private:
    int base, altezza;

public:
    Rettangolo() : base(0), altezza(0) {} // Costruttore di default
    Rettangolo(int b, int a) : base(b), altezza(a) {} // Costruttore parametrico
    ~Rettangolo() { std::cout << "Oggetto distrutto" << std::endl; } // Destruttore

    void setBase(int b) { base = b; } // Setter
    int calcolaArea() { return base * altezza; } // Metodo
};

int main() {
    int b = 4, a = 5;
    Rettangolo ret(b, a);
    std::cout << "Valore area rettangolo: " << ret.calcolaArea() << std::endl;
    return 0;
}
