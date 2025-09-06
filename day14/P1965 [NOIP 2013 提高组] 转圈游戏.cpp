#include<iostream>

using namespace std;

typedef long long LL;

LL n,m,k,x;

LL qpow(LL a,LL b,LL p)
{
	LL ret = 1;
	while(b)
	{	
		if(b&1) ret = ret * a % p;
		a = a * a % p;
		b >>= 1; 
	}
	return ret;
}

int main()
{
	cin >> n >> m >> k >> x;
	
	LL pos = m * qpow(10,k,n) % n;
	
	cout << (x + pos) % n;
	
	return 0;
 } 
