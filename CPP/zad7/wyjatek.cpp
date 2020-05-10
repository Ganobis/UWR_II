#include "wyjatek.hpp"


wyjatek_wymierny::wyjatek_wymierny(string nap) : napis(nap) {};
dzielenie_przez_0::dzielenie_przez_0(): wyjatek_wymierny("Nie wolno dzielic przez 0!!"){};


przekroczenie_zakresu::przekroczenie_zakresu(): wyjatek_wymierny("przekroczyles zakres"){};


string dzielenie_przez_0::what()
{
    return napis;
}

string przekroczenie_zakresu::what()
{
    return napis;
}


