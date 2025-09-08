#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;

int aim,a,c[N]; //��Ŀ˵���������ݲ�����1e5�����Կ���ֱ���ü۸�ӳ��������i�۸��µ�����Ϊc[i] 
 
int main()
{
	cin >> aim;
	
	int x,y; cin >> x >> y; 
	a = x;
	c[x] = y;
	int pre = x;
	
	while(cin >> x >> y, x != -1 && y != -1)
	{
		int d = (y - c[pre]) / (pre - x); //�����½��� 
		//�ڱ��ֶ���x��Ҫ����һ��x�����x֮������м۸�/�������� 
		for(int i=pre+1,j=c[pre]-d;i<=x;i++,j-=d)
		{
			c[i] = j;
		}
		pre = x; //��¼��ǰx���Լ��㵽��һ��x֮�����м۸��Ӧ�������� ��Ŀ��˵�������������ڼ�λ�������ı仯�����Ե� 
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


