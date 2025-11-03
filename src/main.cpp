//Hubert Bzówka
//Zadanie 3
#include <iostream>
#include <fstream>
using namespace std;

string z2_1_path_symbole_txt = "../zalaczniki-2025/symbole.txt";

bool czy_palindrom(string tekst){
    int ile_znakow = tekst.length();
    for(int i =0; i < ile_znakow/2 ; i++){
        if(tekst[i] != tekst[ile_znakow-i-1]){
            return false;
        }
    }
    return true;
}


void Zadanie2_1(){
    ifstream plik{z2_1_path_symbole_txt};
    if(!plik.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
    }

    string linia;
    while(plik >> linia){
        if(czy_palindrom(linia)){
            cout << linia << endl;
        }
        
    }
    

    
    plik.close();
}
int main() {
    Zadanie2_1();
    return 0;
}
