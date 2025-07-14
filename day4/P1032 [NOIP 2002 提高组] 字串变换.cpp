#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

string a,b;

string x[10],y[10];
int n; //记录有多少个变换规则 

unordered_map<string,int> dist;

bool st[10];

int bfs()
{
	if(a == b) return 0;
	
	queue<string> q;
	
	q.push(a);
	dist[a] = 0;
	
	while(q.size())
	{
		string s = q.front(); q.pop();
		
		if(dist[s] > 10) return -1;
		
		//枚举所有变换规则: x[i]->y[i] 
		for(int i=0;i<n;i++)
		{
			int pos = 0;
			while(s.find(x[i], pos) != -1) //fint(要查找的子串，查找起始位置)
			{
				pos = s.find(x[i], pos);
				//拼接新串 
				string news = s.substr(0, pos) + y[i] + s.substr(pos + x[i].size()); //substr(起始位置，截取长度) / substr(起始位置)->截取到末尾 
				pos++; //从下一个位置开始接着找x[i]
				
				//s -> news 
				if(dist.count(news)) continue; //如果news之前已经变换过了就continue 
				dist[news] = dist[s] + 1; 
				if(news == b) return dist[news];
				 
				q.push(news);
			}				
		}	
	} 
	
	return -1;
}

int main()
{
	cin >> a >> b; 
	
	while(cin >> x[n] >> y[n]) n++;

	int ret = bfs();
	if(ret == -1) cout << "NO ANSWER!" << endl;
	else cout << ret << endl;	
	
	return 0;
}
