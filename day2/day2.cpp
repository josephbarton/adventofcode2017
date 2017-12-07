#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

std::vector< std::vector<int> > read_input_file(std::string file_name)
{
	std::ifstream file;
	file.open(file_name.c_str());
	if(!file)
	{
		std::cout << "Unable to open file :(" << std::endl;
	}
	std::string row;
	char cell[100];
	std::vector< std::vector<int> > rows;
	while(std::getline(file, row))
	{	
	    std::vector<int> row_ints;
		std::stringstream ss(row);
		std::cout << row << std::endl;
		while(ss.getline(cell, 10, '\t'))
		{
		    row_ints.push_back(atoi(cell));
		}
		rows.push_back(row_ints);
	}
	return rows;
}

int checksum(std::vector< std::vector<int> > input)
{
    int sum = 0;
    for(int i = 0; i < input.size(); i++)
    {
        std::sort(input.at(i).begin(), input.at(i).end());
        std::cout << *(input.at(i).end() - 1) << ' ' << *input.at(i).begin() << std::endl;
        sum += *(input.at(i).end()-1) - *input.at(i).begin();
    }
    return sum;
}

int main()
{
	std::vector< std::vector<int> > input = read_input_file("input.txt");
	
	std::cout << checksum(input) << std::endl;
	
	return 0;
}
