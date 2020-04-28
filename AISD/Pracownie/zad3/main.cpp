#include <iostream>
//#include <verctor>

const int64_t int_val = 10000000000001;
const int32_t max_int = 2147483647;

int32_t war[101];
int32_t tab[1000001][2];
bool flaga;
int32_t suma;
int32_t ilosc_monet;

void zwroc_reszty_min(){
	int64_t ret[suma+1][2];
	ret[0][0] = 0;
	for (int32_t i = 1; i < suma + 1; i++)
		ret[i][0] = int_val;
	for (int32_t i = 0; i < ilosc_monet; i++)
	{
		int32_t waga = tab[i][1];
		for (int32_t j = 0; j < suma - waga + 1; j++)
		{
			if (ret[j][0] < int_val)
			{
				if (ret[j][0] + tab[i][0] < ret[j + waga][0])
				{
					ret[j + waga][0] = ret[j][0] + tab[i][0];
					ret[j + waga][1] = i;
				}
			}
		}
	}
	if (ret[suma][0] >= int_val)
	{
		flaga = true;
	}
	else
	{
		int32_t sum = suma;
		for (int32_t i = 0; i < ilosc_monet; i++)
			war[i] = 0;
		std::cout << "TAK\n" << ret[sum][0] << "\n";
		do{
			war[ ret[sum][1] ]++;
			sum = sum - tab[ ret[sum][1] ][1];
			if (sum <= 0)
				break;
		}while(1);
		for (int32_t i = 0; i < ilosc_monet; ++i)
		{
			std::cout << war[i] << " ";
		}
		std::cout << "\n";
	}
}

void zwroc_reszty_max(){
	int64_t ret[suma+1][2];
	ret[0][0] = max_int;
	for (int32_t i = 1; i < suma + 1; i++)
		ret[i][0] = -1;
	for (int32_t i = 0; i < ilosc_monet; i++)
	{
		int32_t waga = tab[i][1];
		for (int32_t j = 0; j < suma - waga + 1; j++)
		{
			if (ret[j][0] > -1)
			{
				if (ret[j][0] + tab[i][0] > ret[j + waga][0])
				{
					ret[j + waga][0] = ret[j][0] + tab[i][0];
					ret[j + waga][1] = i;
				}
			}
		}
	}

	std::cout << (ret[suma][0] - max_int  ) << "\n";
	for (int32_t i = 0; i < ilosc_monet; i++)
		war[i] = 0;
	do{
		war[ ret[suma][1] ]++;
		suma = suma - tab[ ret[suma][1] ][1];
		if (suma <= 0)
			break;
	}while(1);

	for (int32_t i = 0; i < ilosc_monet; i++)
	{
		std::cout << war[i] << " ";
	}
}

int32_t main()
{
	std::cin>>suma;
	std::cin>>ilosc_monet;

	flaga = false;
	for (int32_t i = 0; i < ilosc_monet; i++)
		std::cin >> tab[i][0] >> tab[i][1];

	zwroc_reszty_min();
	if (flaga){
		std::cout << "NIE";
		return 0;
	}
	else
		zwroc_reszty_max();

	return 0;
}