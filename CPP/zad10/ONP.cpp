#include "ONP.h"
using namespace std;
double onp::oblicz_i_zwroc(string w)
{

  string tmp="";
  stack<wyrazenie*>stos;
  int i=0;
  while(true)
  {

    while(w[i]!=' ' and i<w.length())
    {
      tmp+=w[i];
      i++;
    }
    if(tmp.compare("sin")==0)
    {
      wyrazenie* tmp1=new Sin(stos.top());
      stos.pop();
      stos.push(tmp1);
    }
    else if(tmp.compare( "cos")==0)
    {
      wyrazenie* tmp1=new Cos(stos.top());
      stos.pop();
      stos.push(tmp1);
    }
    else if(tmp.compare( "exp")==0)
    {
      wyrazenie* tmp1=new Exp(stos.top());
      stos.pop();
      stos.push(tmp1);
    }
    else if(tmp.compare("ln")==0)
    {
      wyrazenie* tmp1=new Ln(stos.top());
      stos.pop();
      stos.push(tmp1);
    }
    else if(tmp.compare( "abs")==0)
    {
      wyrazenie* tmp1=new bezwzgl(stos.top());
      stos.pop();
      stos.push(tmp1);
    }
    else if(tmp.compare( "+")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new dodaj(tmp1, tmp2));
    }
    else if(tmp.compare( "-")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new odejmij(tmp2, tmp1));
    }
    else if(tmp.compare( "*")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new mnoz(tmp1, tmp2));
    }
    else if(tmp.compare( "/")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new dziel(tmp2, tmp1));
    }
    else if(tmp.compare( "log")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new logarytm(tmp2, tmp1));
    }
    else if(tmp.compare( "pow")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new potega(tmp2, tmp1));
    }
    else if(tmp.compare( "mod")==0)
    {
      wyrazenie* tmp1=stos.top();
      stos.pop();
      wyrazenie* tmp2=stos.top();
      stos.pop();
      stos.push(new modulo(tmp2, tmp1));
    }
    else if(tmp.compare( "e")==0)
    {
      stos.push(new e());
    }
    else if(tmp.compare( "pi")==0)
    {
      stos.push(new pi());
    }
    else if(tmp.compare( "fi")==0)
    {
      stos.push(new fi());
    }
    else if(zmienna::zmienne.find(tmp) != zmienna::zmienne.end())
    {
      stos.push(new liczba(zmienna::zmienne[tmp]));
    }
    else
    {
      try{

        stos.push(new liczba(stod(tmp)));
      }catch(...)
      {
        throw ;
      }
    }
    tmp="";
    if(w[i]==' ') i++;
    if(i>=w.length()) break;
  }
  return stos.top()->oblicz();
}
void onp::print(string w)
{
  try{

    cout<<oblicz_i_zwroc(w)<<endl;
  }catch(...)
  {
    cout<<"Błędnie wpisane wyrażenie"<<endl;
  }
}
void onp::assign(string w, string zm)
{
  if(zm.compare("print")==0 or zm.compare("assign")==0 or zm.compare("clear")==0 or zm.compare("exit")==0)
  {
    cout<<"Nazwa zmiennej jest taka sama jak słowo kluczowe"<<endl;
  }
  else if(zm.length()>7)
    cout<<"Nazwa zmiennej dłuższa niż 7 znaków"<<endl;
  else
  {
    try{

      double tmp=oblicz_i_zwroc(w);
      zmienna::dodaj(zm, tmp);
      cout<<tmp;
    }catch(...)
    {
      cout<<"Błędnie wpisane wyrażenie"<<endl;
    }

  }
}
void onp::clear()
{
  zmienna::zmienne.clear();
}
