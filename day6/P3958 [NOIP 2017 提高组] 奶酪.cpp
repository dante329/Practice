#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL;

const int N = 1e3 + 10;

LL n,h,r;

int fa[N]; //���鼯 

LL x[N],y[N],z[N];

int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
	fa[find(x)] = find(y);
}

bool check(int a, int b)
{
	//Ϊ�˱����漰double�ıȽϣ�������Ǿ����ƽ��
	LL d = (x[a]-x[b]) * (x[a]-x[b]) + (y[a]-y[b]) * (y[a]-y[b]) + (z[a]-z[b]) * (z[a]-z[b]);
	return d <= 4 * r * r;
}

int main()
{
	int T; cin >> T;
	while(T--)
	{
		cin >> n >> h >> r;
		//��ʼ�����鼯����0~n+1 
		for(int i=0;i<=n+1;i++) fa[i] = i;
		for(int i=1;i<=n;i++)
		{
			cin >> x[i] >> y[i] >> z[i];
			//�ж����±����Ƿ���ͨ
			if(z[i] <= r) merge(i,0);
			//�ж��ϱ���
			if(z[i] >= h - r) merge(i,n+1);
			//�жϵ�ǰ�ն���֮ǰ���еĿն��Ƿ���������һ���Ǳ���ģ���Ϊ��Ŀ�����Ŀն���˳��������� 
			for(int j=1;j<i;j++) 
			{
				if(check(i,j)) merge(i,j);	
			}	
		} 
		if(find(0) == find(n+1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
} 
