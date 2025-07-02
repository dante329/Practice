#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int n,m,r[N],d[N],s[N],t[N];

int f[N]; //������� 

bool check(int x) //ִ��1~x�����������Ƿ�ᵼ�·Ƿ� 
{
	//��ʼ���������   
	for(int i=1;i<=n;i++) f[i] = r[i] - r[i-1];
	
	for(int i=1;i<=x;i++)
	{
		int t1 = s[i], t2 = t[i]; //t1��ʼ���ڣ�t2�������� 
		f[t1] -= d[i], f[t2 + 1] += d[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		f[i] = f[i-1] + f[i];
		if(f[i] < 0) return false; //�Ƿ�����false 
	}
	
	return true; //�Ϸ�����true 
}

int main()
{
	cin >> n >> m;
	
	for(int i=1;i<=n;i++) cin >> r[i];
	
	for(int i=1;i<=m;i++) cin >> d[i] >> s[i] >> t[i];
	
	int left = 1, right = m;
	
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(check(mid)) left = mid + 1; //�Ϸ����������䣬����left 
		else right = mid;
	}

//�����ж�left�Ƿ����m��ȷ���ǲ���m�������������� 
//	if(left == m) cout << 0 << endl; //���ж�����������
//	else 
//	{
//		cout << -1 << endl;
//		cout << left << endl;
//	} 


	//Ҳ���ԶԶ��ֽ������left checkһ�£�������ֵ��t or f 
	if(check(left)) cout << 0 << endl; //check(left)Ϊfalse��������ߣ����ж�����������
	else cout << -1 << endl << left << endl;
	
	return 0;
} 
