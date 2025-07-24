#include<iostream>

using namespace std;

string s;

int main()
{
	cin >> s; 
	
	string ss = s.substr(0,1) + s.substr(2,3) + s.substr(6,5) + s.substr(12,1);   
	
	
	int sum = 0;
	for(int i=0;i<ss.size()-1;i++)
	{
		sum += (ss[i] - '0') * (i+1); 
	}
	sum %= 11;
	
	char ch = *(ss.end()-1);
	int t = ch - '0';
	if(ch == 'X') t = 10;
	
	if(sum == t) cout << "Right";
	else 
	{
		if(sum == 10) cout << s.substr(0,s.size()-1) << "X";
		else cout << s.substr(0,s.size()-1) << sum;
	 } 
	
	return 0;
}
