#include <iostream>

int main()
{
	int n, m, x, poczatek, koniec, szukana;
	std::cin>>n;
	int tab[n];
	for (int i = 0; i < n; ++i)
	{
		std::cin>>tab[i];
	}
	std::cin>>m;
	int data[m];
	for (int i = 0; i < m; ++i)
	{
		std::cin>>szukana;
		poczatek = 0;
		koniec = n;
		x = (poczatek+koniec)/2;
		while(x != n && x != 0){
			std::cout<<x<<" ";
			if((tab[x]<szukana) && (tab[x+1]>=szukana)){
				std::cout<<x<<" "<<std::endl;
				data[i] = x;
				break;
			}
			else{
				if(tab[x]>szukana)
					koniec = x;
				else
					poczatek = x;
			}
			x = (poczatek+koniec)/2;
		}
		if(x == n)
			data[i] = poczatek;
		if (x == 0)
		{
			data[i] = koniec;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		std::cout<<data[i]<<" ";
	}

	return 0;
}