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
	int t;
	cin >> t;
	string s;
	while(t--)
	{
		cin >> s;
		std::vector<bool> v(3);
		std::vector<int> k(3);
		v[0] = 0; v[1] = 0 ; v[2] = 0;
		k[0] = 0; k[1] = 0 ; k[2] = 0;
		re(i , s.size())
		{
			if(s[i] >= 48 && s[i] <= 57)
				v[0] = 1;
			else
			{
				if(s[i] >= 65 && s[i] <= 90)
					v[1] = 1;
				else
					v[2] = 1;
			}
		}
		if((!v[0] && !v[1]) || (!v[0] && !v[2]) || (!v[1] && !v[2]))
		{
			if((!v[0] && !v[1]))
			{
				s[1] = '2'; 
				s[2] = 'A'; 
			}
			if((!v[0] && !v[2]))
			{
				s[1] = '1'; s[2] = 'a'; 
			}
			if( (!v[1] && !v[2]))
			{
				s[1] = 'A'; s[2] = 'a'; 
			}
			v[0] = 1; v[1] = 1 ; v[2] = 1;
		}
		if(v[0] == 0)
		{
					re(i , s.size())
					{
						v[0] = 1;
						if(s[i] >= 65 && s[i] <= 90)
							k[1]++; 
						if(s[i] >= 97 && s[i] <= 122)
							k[2]++;
						if(k[1] == 2 || k[2] == 2){
							s[i] = '1';
							break;
						}
					}
		}
		if(v[1] == 0)
		{
			re(i , s.size())
					{
						v[1] = 1;
						if(s[i] >= 48 && s[i] <= 57)
							k[0]++; 
						if(s[i] >= 97 && s[i] <= 122)
							k[2]++;
						if(k[0] == 2 || k[2] == 2){
							s[i] = 'A';
							break;
						}
					}
		}
		if(v[2] == 0)
		{
			re(i , s.size())
					{
						v[2] = 1;
						if(s[i] >= 48 && s[i] <= 57)
							k[0]++; 
						if(s[i] >= 65 && s[i] <= 90)
							k[1]++;
						if(k[0] == 2 || k[1] == 2){
							s[i] = 'a';
							break;
						}
					}
		}
		cout << s <<"\n";
		}
	return 0;
}