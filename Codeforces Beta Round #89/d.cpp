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
int mod = 100000000;
int dp[101][101][2];
int k1 , k2;
int calc(int n1 , int n2 , int f)
{
	if(dp[n1][n2][f] != -1)
		return dp[n1][n2][f];
	if(n1 + n2 == 0)
	{
		dp[n1][n2][f] = 1;
		return 1;
	}
	dp[n1][n2][f] = 0;
	if(f == 0)
	{
		for(int i =1; i <= min(n1 , k1) ; i++){
			dp[n1][n2][f] += calc(n1-i , n2 , 1-f);
			dp[n1][n2][f] %= mod;
		}
	}
	else
	{
		for(int i =1; i <= min(n2 , k2) ; i++){
			dp[n1][n2][f] += calc(n1 , n2-i , 1-f);
			dp[n1][n2][f] %= mod;
		}
	}
	return dp[n1][n2][f];
}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n1 , n2;
	cin >> n1 >> n2 >> k1 >> k2;
	re(i , 101)
	{
		re(j , 101)
		{
			re(k , 2)
				dp[i][j][k] = -1;
		}
	}
	cout << (calc(n1 , n2 , 0) + calc(n1 , n2 , 1))%mod <<"\n";
	return 0;
}