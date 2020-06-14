#include <bits/stdc++.h>
using namespace std;
int tab[1003];

int main()
{
  int k;
  cin>>k;
  for(int i=0;i<100;i++)
    tab[i] = rand() % 100;
  cout<<"Wygenerowana tablica:\n";
  for(int i =0;i<100;i++)
    cout<<tab[i]<<' ';
  cout<<'\n';
  cout<<"Posortowana tablica:\n";
  sort(tab,tab+100);
  for(int i =0;i<100;i++)
    cout<<tab[i]<<' ';
  cout<<'\n';
  cout<<"kty element: "<<tab[k-1];
}