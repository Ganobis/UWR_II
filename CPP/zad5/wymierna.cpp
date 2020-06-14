#include "wymierna.hpp"
#include <iostream>
#include <climits>
#include <stdlib.h>
using namespace std;

int nwd(int,int);
int nww(int,int);
int suma25(int);


Wymierna::Wymierna():licznik(0),mianownik(1){}

Wymierna::Wymierna(int i):licznik(i),mianownik(0){};


Wymierna::Wymierna(int l,int m) :licznik(l),mianownik(m)
{
    popraw();
}

Wymierna::get_licznik() const
{
    return licznik;
}

Wymierna::get_mianownik() const
{
    return mianownik;
}

void Wymierna::set_licznik(int l)
{
    licznik=l;
}

void Wymierna::set_mianownik(int m)
{
    mianownik=m;
}


Wymierna Wymierna::popraw()
{
    if (mianownik<0)
    {
        if (licznik<0)
        {
            licznik*=-1;
            mianownik*=-1;
        }
        else
        {
            licznik*=-1;
            mianownik*=-1;
        }
    }
    int nwda=nwd(licznik,mianownik);
    licznik/=nwda;
    mianownik/=nwda;
    return *this;
}


Wymierna operator+(const Wymierna &wym,const Wymierna &wym2) throw (przekroczenie_zakresu)
{
    int licznik,mianownik;
    licznik=(wym.get_licznik()*(nww(wym.get_mianownik(),wym2.get_mianownik())/wym.get_mianownik())+(wym2.get_licznik()*(nww(wym.get_mianownik(),wym2.get_mianownik())/wym2.get_mianownik())));
    mianownik=(nww(wym.get_mianownik(),wym2.get_mianownik()));
    Wymierna res(licznik,mianownik);
    res.popraw();
    if (INT_MAX<res.get_licznik())
        throw przekroczenie_zakresu();
    return res;
}

Wymierna operator-(const Wymierna &wym,const Wymierna &wym2) throw (przekroczenie_zakresu)
{
    int licznik,mianownik;
    licznik=(wym.get_licznik()*(nww(wym.get_mianownik(),wym2.get_mianownik())/wym.get_mianownik())-(wym2.get_licznik()*(nww(wym.get_mianownik(),wym2.get_mianownik())/wym2.get_mianownik())));
    mianownik=(nww(wym.get_mianownik(),wym2.get_mianownik()));
    Wymierna res(licznik,mianownik);
    res.popraw();
    if (INT_MIN>res.get_licznik())
        throw przekroczenie_zakresu();
    return res;
}

Wymierna operator*(const Wymierna &wym,const Wymierna &wym2)    throw (przekroczenie_zakresu)
{
    int licznik,mianownik;
    licznik=(wym.get_licznik()*wym2.get_licznik());
    mianownik=(wym.get_mianownik()*wym2.get_mianownik());
    Wymierna res(licznik,mianownik);
    if (INT_MAX<res.get_licznik())
        throw przekroczenie_zakresu();
    return res;
}
Wymierna operator/(const Wymierna &wym,const Wymierna &wym2) throw (dzielenie_przez_0)
{
    int licznik,mianownik;
    if (wym2.get_licznik()==0)
        throw dzielenie_przez_0();
    licznik=(wym.get_licznik()*wym2.get_mianownik());
    mianownik=(wym.get_mianownik()*wym2.get_licznik());
    Wymierna res(licznik,mianownik);
    res.popraw();
    return res;
}

Wymierna &operator-(Wymierna &wym)
{
    if (wym.get_licznik()*-1<INT_MIN)
        throw przekroczenie_zakresu();
    wym.set_licznik(wym.get_licznik()*-1);
    return wym;
}

Wymierna &operator!(Wymierna &wym)
{
    int pom;
    if (wym.get_licznik()==0)
        throw dzielenie_przez_0();
    pom=wym.get_licznik();
    wym.set_licznik(wym.get_mianownik());
    wym.set_mianownik(pom);
    wym.popraw();
    return wym;
}

ostream &operator<<(ostream &wy,const Wymierna &x)
{

    if(x.get_licznik()/x.get_mianownik() == 0 && x.get_licznik() < 0)
      wy << "-";
    wy << x.get_licznik()/x.get_mianownik();
    if(x.get_licznik() % x.get_mianownik() != 0)
    {
      wy << ".";
      int suma = suma25(x.get_mianownik());
      int o = x.get_licznik() % x.get_mianownik() * 10;
      for(int i=0; i<suma ; i++)
      {
        wy << abs(o / x.get_mianownik());
        o = o % x.get_mianownik() * 10;
      }
      wy << "(";
      int p = o , i = 1;
      while(p != o || i == 1)
      {
        wy << abs(o / x.get_mianownik());
        o = o % x.get_mianownik() * 10;
        i++;
      }
      wy << ")";
    }
    return wy;
}


Wymierna::operator double()
{
    return static_cast<double> (this->get_licznik()) / this->get_mianownik();
}

Wymierna::operator int()
{
    return this->get_licznik()/this->get_mianownik();
}

int nwd(int a,int b)
{
    int pom;
    if (a<0)
        a*=-1;
    if (b<0)
        b*=-1;

    while (b>0)
    {
        pom=b;
        b=a%b;
        a=pom;
    }
    return a;
}

int nww(int a,int b)
{
    return a*b/nwd(a,b);
}

int suma25(int n)
{
    int d=0;
    while (n%2==0)
    {
        n/=2;
        d++;

    }
    while (n%5==0)
    {
        n/=5;
        d++;
    }
    return d;
}
