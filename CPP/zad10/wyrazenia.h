#include<iostream>
#include<string>
#include<stdexcept>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;

class wyrazenie
{
public:
  virtual double oblicz() = 0;
  virtual string opisz() = 0;
};
class liczba : public wyrazenie
{
private:
  double a;
public:
  liczba(double);
  double oblicz();
  string opisz();
};
class stala: public wyrazenie
{
protected:
  string a;
};
class pi: public stala
{
public:
  pi();
  double oblicz();
  string opisz();
};
class e: public stala
{
public:
  e();
  double oblicz();
  string opisz();
};
class fi: public stala
{
public:
  fi();
  double oblicz();
  string opisz();
};
class zmienna : public wyrazenie
{
private:
  string nazwa;  
public:
  static map<string,double> zmienne;
  static void dodaj(string, double);
  friend void clear();
  double wartosc();
  double oblicz();
  string opisz();
  zmienna(string);
};
class operator1arg: public wyrazenie
{
protected:
  wyrazenie *a;
};
class Sin: public operator1arg
{
public:
  double oblicz();
  string opisz();
  Sin(wyrazenie*);
};
class Cos: public operator1arg
{
public:
  double oblicz();
  string opisz();
  Cos(wyrazenie*);
};
class Exp: public operator1arg
{
public:
  double oblicz();
  string opisz();
  Exp(wyrazenie*);
};
class Ln: public operator1arg
{
public:
  double oblicz();
  string opisz();
  Ln(wyrazenie*);
};
class bezwzgl: public operator1arg
{
public:
  double oblicz();
  string opisz();
  bezwzgl(wyrazenie*);
};
class przeciw: public operator1arg
{
public:
  double oblicz();
  string opisz();
  przeciw(wyrazenie*);
};
class odwrot: public operator1arg
{
public:
  double oblicz();
  string opisz();
  odwrot(wyrazenie*);
};
class operator2arg: public operator1arg
{
protected:
  wyrazenie *b;
};
class dodaj: public operator2arg
{
public:
  dodaj(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class odejmij: public operator2arg
{
public:
  odejmij(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class mnoz: public operator2arg
{
public:
  mnoz(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class dziel: public operator2arg
{
public:
  dziel(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class logarytm: public operator2arg
{
public:
  logarytm(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class modulo: public operator2arg
{
public:
  modulo(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
class potega: public operator2arg
{
public:
  potega(wyrazenie*, wyrazenie*);
  double oblicz();
  string opisz();
};
