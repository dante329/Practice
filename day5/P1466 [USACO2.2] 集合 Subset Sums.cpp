//��ά 
//#include<iostream>
//
//using namespace std;
//
//typedef long long LL; 
//
//int n;
// 
//LL f[40][800]; //f[i][j]:��ǰi������ѡ����ֵ��Ϊj�ķ����� 
//
//int main()
//{
//	cin >> n;
//
//	int sum = (1 + n) * n / 2; //�Ȳ�������� 
//	
//	if(sum % 2 == 1) //�ܺ��������ʹղ�����������ֵ��ͬ�� 
//	{
//		cout << 0;
//		return 0;
//	}
//	
//	sum /= 2; //sum/2��Ϊ�������� 
//
//	f[0][0] = 1; //��״̬��ʾΪ��������ʱ�򣬲�Ҫ���ǳ�ʼ�������� 
//	 
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=sum;j++)
//		{
//			f[i][j] += f[i-1][j]; //��ѡ 
//			if(j >= i) f[i][j] += f[i-1][j-i]; //ѡ 
//		}
//	}	
//	
//	cout << f[n][sum] / 2; //��Ŀ�ʵ��ǿ��Էֳɶ��ٶ� 
// 	
//	return 0;
//}


//һά
#include<iostream>

using namespace std;

typedef long long LL; 

int n;
 
LL f[800];  

int main()
{
	cin >> n;

	int sum = (1 + n) * n / 2; //�Ȳ�������� 
	
	if(sum % 2 == 1) //�ܺ��������ʹղ�����������ֵ��ͬ�� 
	{
		cout << 0;
		return 0;
	}
	
	sum /= 2; //sum/2��Ϊ�������� 

	f[0] = 1; //��״̬��ʾΪ��������ʱ�򣬲�Ҫ���ǳ�ʼ�������� 
	 
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=i;j--)
		{
			f[j] = f[j] + f[j-i];
		}
	}	
	
	cout << f[sum] / 2; //��Ŀ�ʵ��ǿ��Էֳɶ��ٶ� 
 	
	return 0;
}
