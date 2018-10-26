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
	cin >> n;
	std::vector<int> f(n);
	std::vector<int> c(n);
	re(i , n)
		cin >> f[i];
	re(i , n)
		cin >> c[i];
	vector<std::vector<pll> > dp(n , std::vector<pll> (4 , mp(-1 , INFL)));
	dp[0][1] = mp(0 , c[0]);
	rep(i ,1 , n-1)
		dp[i][1] = mp(i , c[i]);
	rep(i ,2 , 3)
	{
		rep(j , 1 , n-1)
		{
			re(k , j){
				if(dp[k][i-1].fi != -1){
					if(f[j] > f[dp[k][i-1].fi]){
						if(dp[j][i].se > dp[k][i-1].se + c[j])
								dp[j][i] = mp(j , dp[k][i-1].se + c[j]);
					}
				}
			}
		}
	}
	/*re(i , 4)
	{
		re(j , n)
			cout << "("<<dp[j][i].fi <<" " <<dp[j][i].se <<") ";
		cout <<"\n";
	}*/
	ll m = INFL;
	re(i , n)
	{
		m = min(m , dp[i][3].se);
	}
	if(m == INFL)
		cout << -1 <<"\n";
	else
		cout << m <<"\n";
	return 0;
}