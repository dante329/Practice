#include<iostream>
#include<algorithm>

using namespace std;

const int N = 5e4 + 10;

int n,k,a[N],f[N],g[N]; 
//本题要求两个展示柜中一起展示的最大钻石数量，先求第一个最长子序列会影响第二个子序列的最长长度。
//所以正确的方式就是同时求，暴力枚举左右两个区间的分割点，结果一定在这两个区间内产生
//先用滑动窗口预处理f、g两个数组，在枚举分割点的时候，求f[i-1]+g[i]的最大值，就是整个数列中能挑选出来的个数和最大的两段连续序列 
//f[i]:[1,i]区间内的最长子序列 
//g[i]:[i,n]区间内的最长子序列 

int main()
{
	cin >> n >> k;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	//正向滑动窗口 
	for(int left=1,right=1;right<=n;right++)
	{
		while(a[right] - a[left] > k) left++; //非法 
		
		//跳出while就合法
		f[right] = max(f[right-1],right-left+1); 
	}
	
	//逆向滑动窗口 
	for(int left=n,right=n;left>=1;left--)
	{
		while(a[right] - a[left] > k) right--; //非法 
		
		//跳出while就合法
		g[left] = max(g[left+1],right-left+1); 
	}
	
	//枚举分割点
	int ret = 0;
	for(int i=2;i<=n;i++) 
	{
		ret = max(ret,f[i-1] + g[i]);
	}
	
	cout << ret;
	return 0;
}
