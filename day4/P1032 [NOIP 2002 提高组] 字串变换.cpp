#include<iostream>
#include<unordered_map>
#include<queue>

using namespace std;

string a,b;

string x[10],y[10];
int n; //��¼�ж��ٸ��任���� 

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
		
		//ö�����б任����: x[i]->y[i] 
		for(int i=0;i<n;i++)
		{
			int pos = 0;
			while(s.find(x[i], pos) != -1) //fint(Ҫ���ҵ��Ӵ���������ʼλ��)
			{
				pos = s.find(x[i], pos);
				//ƴ���´� 
				string news = s.substr(0, pos) + y[i] + s.substr(pos + x[i].size()); //substr(��ʼλ�ã���ȡ����) / substr(��ʼλ��)->��ȡ��ĩβ 
				pos++; //����һ��λ�ÿ�ʼ������x[i]
				
				//s -> news 
				if(dist.count(news)) continue; //���news֮ǰ�Ѿ��任���˾�continue 
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
