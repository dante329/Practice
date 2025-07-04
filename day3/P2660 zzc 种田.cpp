//超时了，while(x <= y)这个循环太耗时了，为什么不直接除呢 
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int x, y; cin >> x >> y;
//	
//	if(x > y) swap(x,y); //保持x最小 
//	
//	int ret = 0;
//	
//	while(y != 0)
//	{
//		while(x <= y) 
//		{
//			ret += x * 4;
//			y -= x;
//		} 
//		
//		if(y) swap(x,y);
//	}
//	
//	cout << ret;
//	
//	return 0;
//} 

//改进 
#include<iostream>

using namespace std;
typedef long long LL;
int main()
{
	LL x, y; cin >> x >> y;
	
	if(x > y) swap(x,y); //保持x最小 
	
	LL ret = 0;
	
	while(y != 0)
	{
		LL cnt = y / x; 
		ret += cnt * x * 4;
		y %= x; 
			
		if(y) swap(x,y);
	}
	
	cout << ret;
	
	return 0;
} 

//递归，错误 
#include<iostream>

using namespace std;

int ret;

void dfs(int x, int y)
{
	if(y == 0) return; 
	
	ret += (y/x) * x * 4;
	
	dfs(y % x, y);

}

int main()
{
	int x, y; cin >> x >> y;
	
	if(x > y) swap(x,y); //保持x最小 
	
	dfs(x,y);
	
	cout << ret;
	
	return 0;
} 

//递归改进 
#include <iostream>
using namespace std;
typedef long long LL;

LL solve(LL x, LL y, LL ret = 0) {
    if (y == 0) return ret;  // 终止条件：y为0时返回当前累加值
    
    LL cnt = y / x;
    ret += cnt * x * 4;      // 计算当前步骤的贡献
    y %= x;                  // 更新y的值
    
    if (y != 0) swap(x, y);  // 保证x是较小的数
    return solve(x, y, ret); // 递归调用
}

int main() {
    LL x, y; cin >> x >> y;
    if (x > y) swap(x, y);   // 保证x <= y
    cout << solve(x, y);
    return 0;
}

//免比大小，类似辗转相除法 
#include<iostream>

using namespace std;
typedef long long LL;
LL ret;

int main()
{
	LL x, y; cin >> x >> y;
	
	while(x && y)
	{
		LL cnt = x / y;
		ret += cnt * y * 4;
		x %= y;
		swap(x, y);
	}	

	cout << ret;
	
	return 0;
} 

//正确递归
#include <iostream>
using namespace std;
typedef long long LL;

LL dfs(LL x, LL y, LL ret = 0) 
{
    if (x == 0 || y == 0) return ret;  // 终止条件
    
    LL cnt = x / y;
    ret += cnt * y * 4;
    x %= y;
    
    return dfs(y, x, ret);  // 交换x,y并递归
}

int main() 
{
    LL x, y; 
    cin >> x >> y;
    
    cout << dfs(x, y);
    
    return 0;
} 
