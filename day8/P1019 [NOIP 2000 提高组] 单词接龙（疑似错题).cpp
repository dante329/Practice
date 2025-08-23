#include<iostream>

using namespace std;

const int N = 30;

int n,ret,cnt[N]; //ret��¼����ȣ�cnt��¼ÿ������ʹ�ô��� 

string s[N]; //s���浥�� 

char ch;

void dfs(string path)
{
	if(path.size() > ret) ret = path.size();
	
	//��path��ÿһ�����ʽ���ƥ�� 
	for(int i=1;i<=n;i++)
	{
		if(cnt[i] >= 2) continue;
		//��������ָ������ж��ܷ����
		int cur1 = path.size() - 1, cur2 = 0;
		//ѭ���ж� 
		while(cur1 >= 1 && cur2 < path.size()) //���˰�����ϵ 
		{
			//ͨ��ָ��ֱ��Ҫ�жϵĲ������и�
			string s1 = path.substr(cur1), s2 = s[i].substr(0,cur2+1);  	
			if(s1 == s2) //���Խ��� 
			{
				cnt[i]++;
				dfs(path + s[i].substr(cur2+1));
				cnt[i]--;
			}
			//���s1��s2��ƥ�䣬��ô�ƶ�ָ������ж� 
			cur1--; cur2++;
		}	
	}
	 
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> s[i];
	cin >> ch;
	
	//�������ͷ����ĸ����Ϊdfs�����˰�����ϵ������ֱ�ӱ����жϵ����е�����ĸ 
	for(int i=1;i<=n;i++)
	{
		if(s[i][0] == ch)
		{
			cnt[i]++;
			dfs(s[i]);
			cnt[i]--; //�ָ��ֳ� 
		}
	}
	
	cout << ret; 
	return 0;
}
