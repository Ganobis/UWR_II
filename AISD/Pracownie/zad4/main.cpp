#include <iostream>
#include <vector>
#include <algorithm>

int32_t liczba;

int32_t mediana(std::vector<int32_t> v){
	std::vector<int> v2;
	for (int i = 0; i < 5; i++)
	{
		v2.push_back(v[i]);
	}
	sort(v2.begin(), v2.end());
	return v2[2];
}

int32_t wybierz_edit(std::vector<int32_t> v, int32_t pozycja){
	if (v.size() < 20){
		std::sort(v.begin(), v.end());
		return v[pozycja];
	}
	else{
		int32_t kubki;
		if (v.size() % 5 != 0)
		{
			if(v.size() % 5 == 1){
				v.push_back(1000000002);
				v.push_back(1000000002);
				v.push_back(1000000002);
				v.push_back(1000000002);
			}
			else{
				if (v.size() % 5 == 2){
					v.push_back(1000000002);
					v.push_back(1000000002);
					v.push_back(1000000002);
				}
				else{
					if (v.size() % 5 == 3)
					{
						v.push_back(1000000002);
						v.push_back(1000000002);
					}
					else{
						v.push_back(1000000002);
					}
				}
			}
		}
		kubki = v.size()/5;
		std::vector<int32_t> tablica_vektorow[kubki];
		for (int i = 0; i < kubki; i++)
		{
			tablica_vektorow[i].push_back(v[i*5]);
			tablica_vektorow[i].push_back(v[i*5 + 1]);
			tablica_vektorow[i].push_back(v[i*5 + 2]);
			tablica_vektorow[i].push_back(v[i*5 + 3]);
			tablica_vektorow[i].push_back(v[i*5 + 4]);
		}
		std::vector<int32_t> mediany;
		for (int i = 0; i < kubki; i++)
			mediany.push_back(mediana(tablica_vektorow[i]));
		int32_t m = wybierz_edit(mediany, (mediany.size()/2));
		std::vector<int32_t> aLess;
		std::vector<int32_t> aEq;
		std::vector<int32_t> aMor;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] < m)
				aLess.push_back(v[i]);
			else if(v[i] > m)
				aMor.push_back(v[i]);
			else
				aEq.push_back(v[i]);
		}
		if (pozycja < aLess.size()){
			return wybierz_edit(aLess, pozycja);
		}
		else if (pozycja < aLess.size() + aEq.size()){
			return m;
		}
		else{
			return wybierz_edit(aMor, (int32_t)(pozycja - (int32_t)(aLess.size() + aEq.size())));
		}
	}
}


int main()
{
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int32_t pozycja;
	std::cin >> liczba >> pozycja;
	pozycja --;
	std::vector<int32_t> vektor;
	int32_t x;
	for (int32_t i = 0; i < liczba; i++)
	{
		std::cin >> x;
		vektor.push_back(x);
	}
	liczba = wybierz_edit(vektor, pozycja);
	std::cout << liczba;

	return 0;
}