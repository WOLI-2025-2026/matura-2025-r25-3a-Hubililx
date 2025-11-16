//Hubert Bzówka
//Zadanie 3
#include <iostream>
#include <fstream>
#include <vector>
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

int konwertuj(string s){
    int wynik = 0;
    for(char c : s){
        int cyfra;
        if(c == 'o') cyfra = 0;
        else if(c == '+') cyfra = 1;
        else if(c == '*') cyfra = 2;

        wynik = wynik * 3 + cyfra;
    }
    return wynik;
}

string na_trojkowy(int liczba){
    if(liczba == 0) return "o";

    string wynik = "";

    while(liczba > 0){
        int reszta = liczba % 3;
        char znak;

        if(reszta == 0) znak = 'o';
        else if(reszta == 1) znak = '+';
        else znak = '*';

        wynik = znak + wynik;
        liczba /= 3;
    }

    return wynik;
}


void Zadanie2_1(){
    ifstream plik{z2_1_path_symbole_txt};
    if(!plik.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
    }

    ofstream wynik("wynik2_1.txt");

    string linia;
    while(plik >> linia){
        if(czy_palindrom(linia)){
            cout << linia << endl;
            wynik << linia << endl;
        }
        
    }
    
    wynik.close();
    plik.close();
}

void Zadanie2_2(){
    ifstream plik{z2_1_path_symbole_txt};
    if(!plik.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
        return;
    }

    vector<string> wiersze;
    string linia;
    while(getline(plik, linia)){
        wiersze.push_back(linia);
    }
    plik.close();

    ofstream wynik("wynik2_2.txt");

    int liczba_wierszy = wiersze.size();
    int licznik_kwadratow = 0;

    for(int i = 1; i < liczba_wierszy - 1; i++){
        int dlugosc = wiersze[i].length();
        for(int j = 1; j < dlugosc - 1; j++){
            char znak = wiersze[i][j];

            bool kwadrat = true;
            for(int di = -1; di <= 1 && kwadrat; di++){
                for(int dj = -1; dj <= 1; dj++){
                    if(i+di < 0 || i+di >= liczba_wierszy) { kwadrat = false; break; }
                    if(j+dj < 0 || j+dj >= wiersze[i+di].length()) { kwadrat = false; break; }
                    if(wiersze[i+di][j+dj] != znak){ kwadrat = false; break; }
                }
            }

            if(kwadrat){
                licznik_kwadratow++;
                cout << i+1 << " " << j+1 << endl;
                wynik << i+1 << " " << j+1 << endl;
            }
        }
    }

    cout << "Liczba kwadratow: " << licznik_kwadratow << endl;
    wynik << "Liczba kwadratow: " << licznik_kwadratow << endl;

    wynik.close();
}

void Zadanie2_3() {
    ifstream plik{z2_1_path_symbole_txt};
    if(!plik.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
        return;
    }

    ofstream wynik("wynik2_3.txt");

    string linia;
    int max_wartosc = -1;
    string max_napis = "";

    while(plik >> linia){
        int liczba = konwertuj(linia);

        if(liczba > max_wartosc){
            max_wartosc = liczba;
            max_napis = linia;
        }
    }

    cout << max_wartosc << " " << max_napis << endl;
    wynik << max_wartosc << " " << max_napis << endl;

    plik.close();
    wynik.close();
}

void Zadanie2_4() {
    ifstream plik{z2_1_path_symbole_txt};
    if(!plik.is_open()){
        cerr << "Nie mozna otworzyc pliku" << endl;
        return;
    }

    ofstream wynik("wynik2_4.txt");

    long long suma = 0;
    string linia;

    while(plik >> linia){
        int liczba = konwertuj(linia);
        suma += liczba;
    }

    string trojkowy = na_trojkowy(suma);

    cout << suma << " " << trojkowy << endl;
    wynik << suma << " " << trojkowy << endl;

    plik.close();
    wynik.close();
}


int main() {
    Zadanie2_1();
    Zadanie2_2();
    Zadanie2_3();
    Zadanie2_4();
    return 0;
}
