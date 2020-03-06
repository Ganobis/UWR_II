#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

vector <int64_t> rozklad(int64_t);
int64_t to_int(string);
void instrukcja();
void wypisz(int64_t, vector <int64_t>);
void f(int64_t);

int main(int argc, char **wejscie) {
    if(argc == 1) {
        cerr << "Aby podać rozkład liczby, podaj JEDNĄ liczbę w argumentach programu" << endl;
        return -1;
    }
    else if(argc == 2) {
        vector <int64_t> wyjscie;
        int64_t wejscie_int = to_int(wejscie[1]);
        wyjscie =rozklad(wejscie_int);
        wypisz(wejscie_int, wyjscie);
    }
    else {
        cerr << "Za dużo argumentów!";
        return -1;
    }
    return 0;
}

void f(int64_t x){
    cout << x << " * ";
}

void wypisz(int64_t liczba, vector <int64_t> rozklad){
    cout << liczba << " = ";
    for_each(rozklad.begin(), rozklad.end() - 1, f);
    cout << rozklad[rozklad.size() - 1] << endl;
}

int64_t to_int(string text){
    stringstream strumien(text);
    int64_t wynik = 0;
    strumien >> wynik;
    int wynik_dlugosc = 1;
    while((int) (wynik / pow(10, wynik_dlugosc)) != 0)
        wynik_dlugosc++;

    if(text[0] == '-')
        wynik_dlugosc++;
    if((text[0] != '0' && wynik == 0  || text.length() != wynik_dlugosc)) {
        throw invalid_argument("Błędne dane");
    }
    return wynik;
}

vector <int64_t> rozklad(int64_t wejscie){
    vector <int64_t> wynik;
    int64_t licznik = 2;

    if(wejscie == 1 || wejscie == 0 || wejscie == -1){
        wynik.push_back(wejscie);
        return wynik;
    }

    if(wejscie < 0){
        wejscie *= (-1);
        wynik.push_back(-1);
    }

    int64_t granica= floor(sqrt(wejscie));

    while(wejscie != 1){
        if(wejscie % licznik == 0){
            wejscie /= licznik;
            wynik.push_back(licznik);
            granica= floor(sqrt(wejscie));
            licznik = 1;
        }
        else if(licznik >= granica){
            wynik.push_back(wejscie);
            break;
        }
        licznik++;
    }
    return wynik;
}