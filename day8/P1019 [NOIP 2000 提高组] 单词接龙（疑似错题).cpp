#include<iostream>

using namespace std;

const int N = 30;

int n,ret,cnt[N]; //ret记录最长长度，cnt记录每个单词使用次数 

string s[N]; //s储存单词 

char ch;

void dfs(string path)
{
	if(path.size() > ret) ret = path.size();
	
	//将path与每一个单词进行匹配 
	for(int i=1;i<=n;i++)
	{
		if(cnt[i] >= 2) continue;
		//定义两个指针帮助判断能否接龙
		int cur1 = path.size() - 1, cur2 = 0;
		//循环判断 
		while(cur1 >= 1 && cur2 < path.size()) //过滤包含关系 
		{
			//通过指针分别对要判断的部分做切割
			string s1 = path.substr(cur1), s2 = s[i].substr(0,cur2+1);  	
			if(s1 == s2) //可以接龙 
			{
				cnt[i]++;
				dfs(path + s[i].substr(cur2+1));
				cnt[i]--;
			}
			//如果s1、s2不匹配，那么移动指针继续判断 
			cur1--; cur2++;
		}	
	}
	 
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> s[i];
	cin >> ch;
	
	//针对龙开头的字母，因为dfs过滤了包含关系，我们直接遍历判断单词中的首字母 
	for(int i=1;i<=n;i++)
	{
		if(s[i][0] == ch)
		{
			cnt[i]++;
			dfs(s[i]);
			cnt[i]--; //恢复现场 
		}
	}
	
	cout << ret; 
	return 0;
}
