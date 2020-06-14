#include <iostream>
#include "wymierna.hpp"

using namespace std;
int nwd(int,int);
int main()
{
    try
    {
    int nww;
    Wymierna li;
    Wymierna liczba(3,9);
    Wymierna liczba2(2,4);
    cout<<liczba<<endl;
    liczba=!liczba;
    cout<<liczba<<endl;

    Wymierna liczba3(-3,5);
    Wymierna liczba4(4,-3);
    Wymierna liczba5(1,17);

    cout<<liczba3<<endl;
    cout<<liczba4<<endl;
    cout<<liczba5<<endl;

    }
    catch (wyjatek_wymierny &wyj)
    {
        cout<<wyj.what();
    }
}
