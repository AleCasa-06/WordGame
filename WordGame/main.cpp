#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

class Game{
public:
    ifstream Leggo;


   string parolaDaIndovinare;
   string parolaCensurata;
   int vite = 15;

   Game() : Leggo("parole.txt") {}

   void Start(){
       srand(time(nullptr));
       int rigaDesiderata = rand() % 60454 + 1;
       for(int rigaCorrente = 0; rigaCorrente < rigaDesiderata; rigaCorrente++){
           getline(Leggo,parolaDaIndovinare);


       }


        parolaCensurata = string(parolaDaIndovinare.length(), '_');





   }

   bool Gioca(){
       this->Start();
       char c;





       while(vite > 0){
           cout << parolaCensurata << endl;
           cout << "inserisci una lettera" << endl;
           cin >> c;
           bool trovato = false;

           for(int i = 0; i < parolaDaIndovinare.length(); i++){
               if(parolaDaIndovinare[i] == c){
                   parolaCensurata[i] = c;

                   trovato = true;
               }


           }
           if(!trovato){
               cout << "char non contenuto nella stringa" << endl;

               vite -= 1;
               cout << "vite rimaste: "<< vite << endl;

           }
           else if(parolaCensurata == parolaDaIndovinare){
               cout << "hai vinto!!" << endl;
               return true;
           }


       }
        return false;
   }

};

int main() {
    string nome;
    cout << "inserisci il tuo nome: " << endl;
    cin >> nome;
    cout << "il tuo nome è: " << nome << endl;

    Game g1;
    while(g1.Gioca());




    return 0;
}
