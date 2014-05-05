#include <iostream>
#include <string>
#include <algorithm>

#define IP_LENGTH 4
using namespace std;

bool InTheRange(int* arr)
{
	for(int i= 0; i< IP_LENGTH; ++i)
	{
		if(arr[i] > 255 || arr[i] < 0)
			return false;
	}
	return true;
}

bool NotNumber(char a)
{
	int tmp = a -'0';
	if(tmp >= 0 && tmp <= 9)
		return false;
	return true;
}

bool IpAddress(const string a)
{
	int len = a.length();

	if(NotNumber(a.at(len-1))) return false;
	char tmp_str =0;
	int tmp_int[IP_LENGTH] = {0};

	int count =0;
	char i_next = 0;
	for(int i = 0; i< len; ++i)
	{
		i_next = i+1;
		if(a.at(i) == '.')
		{
			if(a.at(i_next) == '.') return false;
			count++;
			if(count > 3) return false;
			continue;
		}	
		tmp_str = a.at(i);
		if(NotNumber(tmp_str)) return false;
		tmp_int[count] = tmp_int[count] * 10 + (tmp_str - '0');	
	}
	if(count != 3) return false;
	if(InTheRange(tmp_int))
	{
		return true;
	}
	else return false;
}


int main()
{
	string input;
	cout<<"input string"<<endl;

	while(cin>>input)
	{
		if(input == "quit")
		{
			cout<<"The end"<<endl;
			return 0;
		}
		else
		{
			if(IpAddress(input))
			{
				cout<<"The IP Matches successfully"<<endl;
			}
			else
				cout<<"The IP invalid"<<endl;
		}
		
	}
}










