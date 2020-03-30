#include <iostream>
#include <vector>

short idd[4];

int main()
{
	short i;
	int x;
	x = 32;
	x <<= 16;
	x += 42;
	std::vector<int> vector1[4];
	vector1[0].push_back(1);
	vector1[0].push_back(1);
	vector1[3].push_back(0);
	std::cout << vector1[0].size() << " " << vector1[1].size() << " " << vector1[3].size() << std::endl;
	std::cout << idd[0] << std::endl;
	i = x;
	std::cout << i << " " << x;

	return 0;
}