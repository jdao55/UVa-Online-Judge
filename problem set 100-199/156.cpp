#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <locale>
#include <vector>


using namespace std;

int main()
{
	map<string,set<string>> wordmap;
	string input,in;
	
	cin>>in;
	while(in!="#")
	{
		stringstream strstream(in);
		strstream>>input;
		do 
		{
			string upper=input;
			std::transform(upper.begin(), upper.end(),upper.begin(), ::toupper);
			sort(upper.begin(), upper.end());
			auto iter= wordmap.find(upper);
			if(iter!=wordmap.end())
			{
				iter->second.insert(input);
			}
			else
			{
				set<string> tempset={input};
				wordmap.insert(make_pair(upper, tempset));
			}
			strstream>>input;
		}while (!strstream.eof());
		cin>>in;
	}
	vector<string> outlist;
	for(auto temp:wordmap)
	{
		if(temp.second.size()==1)
		{
			outlist.push_back(*(temp.second.begin()));
		}
	}
	sort(outlist.begin(), outlist.end());
	for(auto i: outlist)
	{
		cout<<i<<endl;
	}

}
		
			
	
	
