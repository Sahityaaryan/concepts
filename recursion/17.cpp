//start 19:10

//created at 19:21 on  1 november 23


//method to get the number out of the string '2 - '0'
// how to pass by reference like so "int &a"

#include<iostream>

#include<vector>
using namespace std;

void f2(string str, int i, string result, vector<string> &li, vector<string> &v);

	void f(string str, int i, string result, vector<string> &li, vector<string> &v)
{
	//here i am checking the string size that whether the required combinaltion is achieved or not
	if(i==str.size())
	{
		li.push_back(result);
		return;
	}
	
	//By this we are accessing the the actual number out of string and passing to the hash map adn getting the required string of which combinatiuons I have to make
	string currStr = v[str[i] - '0'];
	
	int j = 0;
	while(j < currStr.size())
	{
		f(str,i+1,result+currStr[j],li,v);
		j++;
	}
}

int main()
{
	string str = "423";
	vector<string> li;
	vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuvw","xyz"};
	f2(str,0,"",li,v);
	
	cout << "ans: ";
	int i = 0;
	while(i < li.size())
	{
		cout << " " << li[i];
		i++;
	}

	cout << '\n' << "size: " << li.size();
	return 0;
}

