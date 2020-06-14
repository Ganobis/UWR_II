#ifndef WYJATEK_HPP_INCLUDED
#define WYJATEK_HPP_INCLUDED
using namespace std;
#include <iostream>
class wyjatek_wymierny : exception
{
public:
    wyjatek_wymierny(string);
    virtual string what() =0;
    string napis;
};

class dzielenie_przez_0 :public wyjatek_wymierny
{
    public:
    dzielenie_przez_0();
    string what();
};

class przekroczenie_zakresu:public wyjatek_wymierny
{
    public:
    przekroczenie_zakresu();
    string what();
};



#endif // WYJATEK_HPP_INCLUDED
