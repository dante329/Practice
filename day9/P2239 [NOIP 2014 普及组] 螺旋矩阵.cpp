#include<iostream>

using namespace std;

int n,x,y;

int dfs(int n,int begin,int x,int y)
{
	if(x == 1) return begin + y;
	else if(y == n) return begin + (n-1) + x;
	else if(x == n) return begin + 2*(n-1) + (n-y+1);
	else if(y == 1) return begin + 3*(n-1) + (n-x+1);
	
	return dfs(n-2,begin+4*(n-1),x-1,y-1); //不能写成x--、y--这会导致未定义的行为	
}
   
int main()
{
	cin >> n >> x >> y;

	cout << dfs(n,0,x,y) << endl;
	
	return 0;
}
