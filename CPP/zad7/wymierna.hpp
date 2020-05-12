#ifndef WYMIERNA_HPP_INCLUDED
#define WYMIERNA_HPP_INCLUDED

#include <iostream>
#include "wyjatek.hpp"
using namespace std;

class Wymierna
{
    int64_t licznik;
    int64_t mianownik;
public:
    Wymierna();
    Wymierna(int);
    Wymierna(int,int);
    int get_licznik() const;
    int get_mianownik() const;
    void set_mianownik(int);
    void set_licznik(int);
    Wymierna popraw();
    friend Wymierna operator+(const Wymierna &wym,const Wymierna &wym2) throw (przekroczenie_zakresu);
    friend Wymierna operator-(const Wymierna &wym,const Wymierna &wym2) throw (przekroczenie_zakresu);
    friend Wymierna operator*(const Wymierna &wym,const Wymierna &wym2) throw (przekroczenie_zakresu);
    friend Wymierna operator/(const Wymierna &wym,const Wymierna &wym2) throw (dzielenie_przez_0);
    friend Wymierna &operator-(Wymierna &wym);
    friend Wymierna &operator!(Wymierna &wym);
    Wymierna &operator=(Wymierna &wym) = default;
    friend ostream &operator<<(ostream &wym,const Wymierna &w);
    operator double();
    explicit operator int();
};





#endif // WYMIERNA_HPP_INCLUDED
