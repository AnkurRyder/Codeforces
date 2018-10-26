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





int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n , m;
	cin >> n;
	std::vector<int> v(n);
	re(i , n)
		cin >> v[i];
	cin >> m;
	std::vector<int> u(m);
	re(i , m)
		cin >> u[i];
	std::map<int, int> mc;
	int cnt = 0;
	if(n >= m)
	{
		sort(u.begin(), u.end());
		re(i , n)
			mc[v[i]]++;
		re(i, m)
		{
			if(mc[u[i]-1] != 0)
			{
				cnt++;
				mc[u[i]-1]--;
				continue;
			}
			if(mc[u[i]] != 0)
			{
				cnt++;
				mc[u[i]]--;
				continue;
			}
			if(mc[u[i]+1] != 0)
			{
				cnt++;
				mc[u[i]+1]--;
				continue;
			}
		}
	}
	else
	{
		sort(v.begin(), v.end());
		re(i , m)
			mc[u[i]]++;
		re(i, n)
		{
			if(mc[v[i]-1] != 0)
			{
				cnt++;
				mc[v[i]-1]--;
				continue;
			}
			if(mc[v[i]] != 0)
			{
				cnt++;
				mc[v[i]]--;
				continue;
			}
			if(mc[v[i]+1] != 0)
			{
				cnt++;
				mc[v[i]+1]--;
				continue;
			}
		}
	}
	cout << cnt <<"\n";
	return 0;
}