#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;

ll comp(vector<int> &v , vector<string> &s,vector<vector<ll> > &dp)
{
	int n = v.size() , flag;
	rep(i ,1 , n-1)
	{
		re(j , 2)
		{
			re(k , 2)
			{
				if(s[2*i + j] >= s[2*(i-1) + k])
					dp[j][i] = min(dp[k][i-1] , dp[j][i]);
				trace1(dp[j][i]);
			}
			dp[j][i] += v[i]*j;
		}
	}
	if(min(dp[0][n-1] , dp[1][n-1]) >= INT_MAX)
		return -1;
	else
		return min(dp[0][n-1] , dp[1][n-1]);

}


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string temp;
	cin >> n;
	std::vector<int> v(n);
	std::vector<string> s(2*n);
	re(i , n)
		cin >> v[i];
	re(i , n){
		cin >> temp;
		s[2*i] = temp;
		reverse(temp.begin(), temp.end());
		s[2*i+1]= temp;
	}
	std::vector<std::vector<ll> > dp(2 , std::vector<ll> (n , INFL));
	dp[0][0] = 0;
	dp[1][0] = v[0];
	cout << comp(v , s , dp) <<"\n";
	return 0;
}