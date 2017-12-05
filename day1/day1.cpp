#include <iostream>
#include <string>
#include <fstream>
#include <vector>


std::vector<int> read_input_file(std::string file_name)
{
	std::fstream file;
	file.open(file_name.c_str());
	if(!file)
	{
		std::cout << "Unable to open file :(" << std::endl;
	}
	char byte;
	std::vector<int> input_array;
	while(file >> byte)
	{
		input_array.push_back(byte-'0');
	}
	return input_array;
}

int inverse_captcha(std::vector<int> input, int shift)
{
	int sum = 0;
	for(int i = 0; i < input.size(); i++)
	{
		if(input[i] == input[(i+shift) % input.size()])
		{
			sum += input[i];
		}
	}
	return sum;
}


int main()
{
	std::vector<int> input = read_input_file("input.txt");
	std::cout << inverse_captcha(input, 1) << std::endl;
	std::cout << inverse_captcha(input, input.size()/2) << std::endl;
	return 0;
}
