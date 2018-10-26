#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
#define fi first
#define se second
#define mp make_pair
#define re(i, n) for(int i = 0; i < n; i++)
#define rep(i,a,b) for(int i = (a); i <= (b); i++)
#define ren(i,a,b) for(int i = (a); i >= (b); i--)
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define ss(s) scanf("%s",s)
#define pi(x) printf("%d\n",x)
#define pl(x) printf("%lld\n",x)
#define ps(s) printf("%s\n",s)
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl





int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string a , b;
	cin >> n;
	cin >> a >> b;
	if(n == 1)
	{
		cout <<( a == b ? 0 : 1 )<<"\n";
		return 0;
	}
	std::vector<int> dp(n);
	re(i , n-1)
	{
		if(a[i] != b[i])
		{
			if(a[i+1] == b[i] && a[i] == b[i+1])
			{
				swap(a[i] , a[i+1]);
				if(i == 0)
					dp[i] = 1;
				else
					dp[i] = 1+dp[i-1];
			}
			else{
				if(i == 0)
					dp[i] = 1;
				else
					dp[i] = dp[i-1]+1;
			}
		}
		else{
			if(i == 0)
				dp[i] = 0;
			else
				dp[i] = dp[i-1];
		}
		//trace1(dp[i]);
	}
	if(a[n-1] != b[n-1])
		dp[n-1] = dp[n-2] + 1;
	else
		dp[n-1] = dp[n-2];
	cout << dp[n-1] <<"\n";
	return 0;
}