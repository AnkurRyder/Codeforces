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
	ll mod = 1000000005;
	int n;
	ll t;
	pair<ll , int> f , s;
	cin >> n;
	priority_queue<pair<ll , int> , std::vector<pair<ll , int> >, std::greater<pair<ll , int> > > v;
	re(i , n){
		cin >> t;
		v.push(make_pair(t , i+1));
	}
	f = v.top(); v.pop();
	s = v.top(); v.pop(); 
	while(!(f.fi <= 0 && s.fi > 0))
	{
		cout << 1 <<" " <<  f.se <<" " << s.se <<"\n";
		v.push(make_pair((f.fi %mod * s.fi%mod)%mod , s.se));
		if(v.size() == 1)
			return 0;
		f = v.top(); v.pop();
		s = v.top(); v.pop(); 
	}
	if(f.fi <= 0 && s.fi > 0)
	{
		cout << 2 <<" " << f.se <<"\n";
		while(v.size() != 0)
		{
			f = s;
			s = v.top(); v.pop();
			cout << 1 <<" " <<  f.se <<" " << s.se <<"\n";
		}
	}
	return 0;
}