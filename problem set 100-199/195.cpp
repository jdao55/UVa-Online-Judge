#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <sstream>
#include <locale>
#include <algorithm>
#include <set>

bool alphaLessThan(std::string a, std::string b)
{
	std::string u_a=a, u_b=b;
	std::transform(u_a.begin(), u_a.end(), u_a.begin(), ::toupper);
	std::transform(u_b.begin(), u_b.end(), u_b.begin(), ::toupper);

	for(int i=0; i<a.size() && i<b.size(); i++)
	{
		//fix this
		if(u_a[i]==u_b[i])
			if (a[i]==b[i])
				continue;
			else 
			{
				return a[i]<b[i];
			}
		else
			return (u_a[i]<u_b[i]);
	}
	return false;
}

int main()
{

	size_t input_lines;
	std::string str;
	std::cin>>input_lines;
	for(int i=0; i< input_lines;i++)
	{
		std::cin>> str;
		std::vector<std::string> permute_list;
		std::sort(str.begin(), str.end());

		do {
			permute_list.push_back(str);
		}while(std::next_permutation(str.begin(), str.end()));
		std::sort(permute_list.begin(), permute_list.end(), alphaLessThan);
		for(int i=0 ;i <permute_list.size();i++)
		{
			if(i!=0)
			{
				if(permute_list[i]!=permute_list[i-1])
					std::cout<<permute_list[i]<<std::endl;
			}
			else
				std::cout<<permute_list[i]<<std::endl;
		}


	}

}

