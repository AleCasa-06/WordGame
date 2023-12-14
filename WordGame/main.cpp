#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Game{
public:
    ifstream Leggo;

   int rigaCorrente = 0;
   string parola;
   string parolaDaIndovinare;
   string parolaCensurata;
   int vite = 5;

   Game() : Leggo("parole.txt") {}

   void Start(){
       srand(time(NULL));
       int rigaDesiderata = rand() % 60454 + 1;
       while(getline(Leggo,parola) && ++rigaCorrente < rigaDesiderata){


       }
       if(rigaCorrente == rigaDesiderata){
           parolaDaIndovinare = parola;
       }

       for(int i = 0; i < parolaDaIndovinare.length(); i++){
           char c = '_';
           parolaCensurata[i] = c;


       }
       for(int i = 0; i < parolaDaIndovinare.length(); i++){
           cout << parolaDaIndovinare[i];
       }
   }

   void Gioca(){
       char c;
       bool error = false;
       char carattScritto;

       while(!error){
           cout << "inserisci una lettera" << endl;
           cin >> c;

           for(int i = 0; i < parolaDaIndovinare.length(); i++){
               if(parolaDaIndovinare.find(c) !=  string::npos){
                   parolaCensurata[i] = c;
                   carattScritto = c;
                   cout << parolaCensurata[i];
               }
               else if(parolaDaIndovinare.find(c) ==  string::npos){
                   cout << "parola non contenuta nella stringa" << endl;
                   error = true;
                   vite -= 1;
                   cout << "vite rimaste: "<< vite << endl;

               }
               else if(c == carattScritto) {
                   cout << "carattere già presente" << endl;
                   error = true;
               }
           }


       }

   }

};

int main() {
    string nome;
    cout << "inserisci il tuo nome: " << endl;
    cin >> nome;
    cout << "il tuo nome è: " << nome << endl;

    Game* g1 = new Game();
    g1->Start();
    g1->Gioca();



    return 0;
}
