#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define first fi
#define second se
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
	int n , k;
	cin >> n >> k;
	int ma =  0, mi = INT_MAX;
	std::vector<int> v(n);
	re(i , n)
	{
		cin >> v[i];
		if(ma < v[i])
			ma = v[i];
		if(mi > v[i])
			mi = v[i];
	}
	std::vector<int> table(ma+1);
	re(i , n)
		table[v[i]]++;
	ren(i , ma-1 , 0)
		table[i] += table[i+1];
	int s = 0 , c = 0;
	//re(i , ma+1)
	//	cout << table[i] <<"\n";
	ren(i , ma , mi+1)
	{
		if(s + table[i] < k)
			s += table[i];
		else
		{
			if(s + table[i] == k){
				c++;
				s = 0;
			}
			else{
				c++;
				s = table[i];
			}
		}
	}
	if (s > 0)
		c++;
	cout << c <<"\n";
	return 0;
}