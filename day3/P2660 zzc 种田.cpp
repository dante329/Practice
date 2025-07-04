//��ʱ�ˣ�while(x <= y)���ѭ��̫��ʱ�ˣ�Ϊʲô��ֱ�ӳ��� 
//#include<iostream>
//
//using namespace std;
//
//int main()
//{
//	int x, y; cin >> x >> y;
//	
//	if(x > y) swap(x,y); //����x��С 
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

//�Ľ� 
#include<iostream>

using namespace std;
typedef long long LL;
int main()
{
	LL x, y; cin >> x >> y;
	
	if(x > y) swap(x,y); //����x��С 
	
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

//�ݹ飬���� 
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
	
	if(x > y) swap(x,y); //����x��С 
	
	dfs(x,y);
	
	cout << ret;
	
	return 0;
} 

//�ݹ�Ľ� 
#include <iostream>
using namespace std;
typedef long long LL;

LL solve(LL x, LL y, LL ret = 0) {
    if (y == 0) return ret;  // ��ֹ������yΪ0ʱ���ص�ǰ�ۼ�ֵ
    
    LL cnt = y / x;
    ret += cnt * x * 4;      // ���㵱ǰ����Ĺ���
    y %= x;                  // ����y��ֵ
    
    if (y != 0) swap(x, y);  // ��֤x�ǽ�С����
    return solve(x, y, ret); // �ݹ����
}

int main() {
    LL x, y; cin >> x >> y;
    if (x > y) swap(x, y);   // ��֤x <= y
    cout << solve(x, y);
    return 0;
}

//��ȴ�С������շת����� 
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

//��ȷ�ݹ�
#include <iostream>
using namespace std;
typedef long long LL;

LL dfs(LL x, LL y, LL ret = 0) 
{
    if (x == 0 || y == 0) return ret;  // ��ֹ����
    
    LL cnt = x / y;
    ret += cnt * y * 4;
    x %= y;
    
    return dfs(y, x, ret);  // ����x,y���ݹ�
}

int main() 
{
    LL x, y; 
    cin >> x >> y;
    
    cout << dfs(x, y);
    
    return 0;
} 
