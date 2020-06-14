#include"wyrazenia.h"

using namespace std;
map<string, double> zmienna::zmienne;
liczba::liczba(double l)
{
  a=l;
}
string liczba::opisz()
{
  return to_string(a);
}
double liczba::oblicz()
{
  return a;
}
pi::pi()
{
  a="pi";
}
string pi::opisz()
{
  return a;
}
double pi::oblicz()
{
  return M_PI;
}
e::e()
{
  a="e";
}
string e::opisz()
{
  return a;
}
double e::oblicz()
{
  return M_E;
}
fi::fi()
{
  a="fi";
}
string fi::opisz()
{
  return a;
}
double fi::oblicz()
{
  return (1+sqrt(5))/2;
}
zmienna::zmienna(string n)
{
  nazwa=n;
}
void zmienna::dodaj(string zm, double val)
{
  zmienne[zm]=val;
}
double zmienna::wartosc()
{
  return zmienne[nazwa];
}
string zmienna::opisz()
{
  return nazwa;
}
double zmienna::oblicz()
{
  return this->wartosc();
}
string Sin::opisz()
{
  string tmp="sin(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double Sin::oblicz()
{
  return sin(a->oblicz());
}
Sin::Sin(wyrazenie *b)
{
  a=b;
}
string Cos::opisz()
{
  string tmp="cos(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double Cos::oblicz()
{
  return cos(a->oblicz());
}
Cos::Cos(wyrazenie *b)
{
  a=b;
}
string Exp::opisz()
{
  string tmp="exp(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double Exp::oblicz()
{
  return exp(a->oblicz());
}
Exp::Exp(wyrazenie *b)
{
  a=b;
}
string Ln::opisz()
{
  string tmp="ln(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double Ln::oblicz()
{
  return log(a->oblicz());
}
Ln::Ln(wyrazenie *b)
{
  a=b;
}
string bezwzgl::opisz()
{
  string tmp="abs(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double bezwzgl::oblicz()
{
  return abs(a->oblicz());
}
bezwzgl::bezwzgl(wyrazenie *b)
{
  a=b;
}
string przeciw::opisz()
{
  string tmp="przeciw(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double przeciw::oblicz()
{
  return -1*a->oblicz();
}
przeciw::przeciw(wyrazenie *b)
{
  a=b;
}
string odwrot::opisz()
{
  string tmp="odwrot(";
  tmp+=a->opisz();
  tmp+=")";
  return tmp;
}
double odwrot::oblicz()
{
  return 1/a->oblicz();
}
odwrot::odwrot(wyrazenie *b)
{
  a=b;
}
dodaj::dodaj(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string dodaj::opisz()
{
  return "(" + a->opisz() + "+" + b->opisz() + ")";;
}
double dodaj::oblicz()
{
  return a->oblicz()+b->oblicz();
}
odejmij::odejmij(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string odejmij::opisz()
{
  return "(" + a->opisz() + "-" + b->opisz() + ")";;
}
double odejmij::oblicz()
{
  return a->oblicz()-b->oblicz();
}
mnoz::mnoz(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string mnoz::opisz()
{
  string tmp="(";
  tmp+=a->opisz();
  tmp+="*";
  tmp+=b->opisz();
  tmp+=")";
  return tmp;
}
double mnoz::oblicz()
{
  return a->oblicz()*b->oblicz();
}
dziel::dziel(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string dziel::opisz()
{
  string tmp="(";
  tmp+=a->opisz();
  tmp+="/";
  tmp+=b->opisz();
  tmp+=")";
  return tmp;
}
double dziel::oblicz()
{
  return a->oblicz()/b->oblicz();
}
logarytm::logarytm(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string logarytm::opisz()
{
  string tmp="log((";
  tmp+=a->opisz();
  tmp+=")(";
  tmp+=b->opisz();
  tmp+="))";
  return tmp;
}
double logarytm::oblicz()
{
  return log(a->oblicz())/log(b->oblicz());
}
modulo::modulo(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string modulo::opisz()
{
  string tmp="(";
  tmp+=a->opisz();
  tmp+="mod";
  tmp+=b->opisz();
  tmp+=")";
  return tmp;
}
double modulo::oblicz()
{
  return (int)a->oblicz()%(int)b->oblicz();
}
potega::potega(wyrazenie *r, wyrazenie *l)
{
  a=r;
  b=l;
}
string potega::opisz()
{
  string tmp="(";
  tmp+=a->opisz();
  tmp+="^";
  tmp+=b->opisz();
  tmp+=")";
  return tmp;
}
double potega::oblicz()
{
  return pow(a->oblicz(), b->oblicz());
}
