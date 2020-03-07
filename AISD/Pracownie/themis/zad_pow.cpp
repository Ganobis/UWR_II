/*
	Wojciech Ganobis
	310519
	grupa: PRZE
*/

#include <iostream>

int main()
{
	int a, b;
	bool f = false;
	std::cin >> a >> b;
	if (a == 0)
	{
		a++;
	}
	if (b == 0)
	{
		return 0;
	}
	for (int i = a; i <= b; ++i)
	{
		if (2020%i == 0)
		{
			if (f)
				{
					std::cout<<" ";
				}
			std::cout<<i;
			f = true;
		}
	}
	return 0;
}