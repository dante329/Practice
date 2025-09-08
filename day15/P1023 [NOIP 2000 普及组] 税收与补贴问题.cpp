#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int aim,a,c[N]; //题目说明所有数据不超过1e5，所以可以直接用价格映射销量。i价格下的销量为c[i] 
 
int main()
{
	cin >> aim;
	
	int x,y; cin >> x >> y; 
	a = x;
	c[x] = y;
	int pre = x;
	
	while(cin >> x >> y, x != -1 && y != -1)
	{
		int d = (y - c[pre]) / (pre - x); //销量下降量 
		//在本轮读入x后，要把上一个x到这个x之间的所有价格/销量填上 
		for(int i=pre+1,j=c[pre]-d;i<=x;i++,j-=d)
		{
			c[i] = j;
		}
		pre = x; //记录当前x，以计算到下一个x之间所有价格对应的销量。 题目已说明：并假设相邻价位间销量的变化是线性的 
	}
	
	int d; cin >> d;
	
	for(int i=pre+1,j=c[pre]-d;j>=0;i++,j-=d) 
	{
		c[i] = j; 
	}
	
	double left = 1e9, right = -1e9;
	for(int i=a,j=c[i];i<=pre;i++)
	{
		double x = 1.0*(aim-a)*(c[aim]-(i-a)*j) / (j-c[aim]);
		
		if(j-c[aim] > 0) right = min(left,x);
		else left = max(right,x);
	}
	
	if(left > right) cout << "NO SOLUTION" << endl;
	else if(left > 0) cout << (int)ceil(left) << endl;
	else if(right < 0) cout << (int)floor(right) << endl;
	else cout << 0 << endl;
	
	return 0;
}


