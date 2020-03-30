#include <bits/stdc++.h> 
 
std::string bin2rom(int);

const std::vector<std::pair<int, std::string>> rzym = {
	{1000, "M"},
	{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
	{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

int main(int argc, char const *argv[])
{
	if (argc != 2){
		throw std::invalid_argument("Number of arguments is wrong!");
		return (-1);
	}
	int number = std::stoi(argv[2]);
	if (number > 3999 || number < 0)
	{
		throw std::invalid_argument("Number is less then 0 or more then 3999!");
		return -1;
	}
	return 0;
}

std::string bin2rom(int x){
	while(x != 0)
		break;
	return "xD";
}