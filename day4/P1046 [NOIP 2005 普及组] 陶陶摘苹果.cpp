#include <iostream>

using namespace std; 

int a[15], h; 

int main() 
{
	for(int i=1;i<=10;i++) cin >> a[i]; 
	
	cin >> h;
	
	int ret = 0;
	for(int i=1;i<=10;i++)
		if(h + 30 >= a[i]) ret++;
	
	cout << ret;
	
	return 0;
}
