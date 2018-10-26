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
	ll n , x;
	cin >> n;
		x = n/3;
		if(n%3 == 0)
		{
			if(x%3 == 0)
				cout << x+2 <<" " << x-1 <<" " << x-1 <<"\n";  
			else
				cout << x <<" " << x << " " << x <<"\n";
		}
		else{
			if(n%3 == 1){
				if(x%3 == 0)
				{
					cout << x+1 <<" " << x+1 <<" " << x-1 <<"\n";
				}
				if(x%3 == 1)
					cout << x <<" " << x << " " << x+1 <<"\n";
				if(x%3 == 2)
					cout << x <<" " << x-1 <<" " << x+2 <<"\n";
			}
			else
			{
				if(x%3 == 0)
				{
					cout << x+2 <<" " << x-1 <<" " << x+1 <<"\n";
				}
				if(x%3 == 1)
					cout << x <<" " << x+1 << " " << x+1 <<"\n";
				if(x%3 == 2)
					cout << x <<" " << x <<" " << x+2 <<"\n";
			}
		}
	return 0;
}