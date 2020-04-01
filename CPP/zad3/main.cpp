#include <bits/stdc++.h> 

/*
to do the test enter in terminal
./a.out 1 2 3999 223 374 895 999 1000 2444
*/
 
std::string bin2rom(int);
int digit(int);

const std::vector<std::pair<int, std::string>> rzym = {
	{1000, "M"},
	{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
	{90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
	{9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

int main(int const argc, char const *argv[])
{
	if (argc < 2)
		throw std::invalid_argument("Number of arguments is wrong! Insert at least one number");
	
	int number;
	for(int i = 1; i < argc; i++){
		try{
			number = std::stoi(argv[i]);
			if (number > 3999 || number < 0)
				throw std::out_of_range("Number is less then 0 or more then 3999!");
			if (digit(number) != strlen(argv[i]))
				throw std::invalid_argument("Insert only number!");
			std::cout << number << " in roman system: " << bin2rom(number) << "\n";
		}
		catch(std::invalid_argument& e){
			std::clog << e.what() << "\n";
		}
		catch(std::out_of_range& e){
			std::clog << "Number is too long!\n";
		}
	}
	return 0;
}

std::string bin2rom(int x){
	std::string temp = "";
	std::string ret ="";
	int n = 0;
	while(x > 0 && n < rzym.size()){
		if(x >= rzym[n].first){
			x -= rzym[n].first;
			temp = ret + rzym[n].second;
			ret = temp;
		}
		else{
			n++;
		}
	}
	return ret;
}

int digit(int x){
	int ret = 0;
	while(x > 0){
		x /= 10;
		ret++;
	}
	return ret;
}