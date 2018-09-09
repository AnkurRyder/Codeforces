#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define re(i, n) for(int i = 0; i < n; i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)



int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll q , n , m , k;
	sl(q);
	while(q--)
	{
		sl(n); sl(m); sl(k);
		if(k < n || k < m){
			cout << -1 <<"\n";
		}
		else{ 
			if(n == m)
			{
				if((k)%m == 1)
					cout <<  k - 3 <<"\n";
				else if((k)%m == 3)
				{
					cout << k/m + 1;
				}
				else
					cout << k <<"\n";
			}
			else
			{
				if(n < m){
					if((k - (m-n)-n)%n == 1)
						cout << k - (m-n) +1 <<"\n";
					else
						cout << k - (m-n) <<"\n";
				}
				else{
					if((k - (n-m)-m)%m == 1)
						cout << k - (n-m)+1 <<"\n";
					else
						cout << k - (n-m) <<"\n";
				}
			}
		}
	}
	return 0;
}