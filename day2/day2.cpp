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
        sum += *(input.at(i).end()-1) - *input.at(i).begin();
    }
    return sum;
}

int checksum_division(std::vector< std::vector<int> > input)
{
    int sum = 0;
    for(int i = 0; i < input.size(); i++)
    {
        for(int j = 0; j < input.at(i).size(); j++)
        {
            std::vector<int> copy = input.at(i);
            for(int k = 0; k < copy.size(); k++)
            {
                if(input.at(i).at(j) % input.at(i).at(k) == 0 && j != k)
                {
                    sum += input.at(i).at(j)/input.at(i).at(k);
                    break;
                }
            }
            
        }
    }
    return sum;
}

int main()
{
	std::vector< std::vector<int> > input = read_input_file("input.txt");
	
	std::cout << checksum(input) << std::endl;
	std::cout << checksum_division(input) << std::endl;
	return 0;
}
