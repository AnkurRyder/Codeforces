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
	int n , key = 0 , keu =0;
	cin >> n;
	std::vector<int> v(n);
	std::vector<int> k(101);
	int c = 0 , ke;
	re(i, n){
		cin >> v[i];
		k[v[i]]++;
	}
	re(i , 101)
	{
		if(k[i] == 1)
			c++;
	}
	ke = c;
	if(c%2 == 0)
	{
		cout << "YES" <<"\n";
		re(i , n)
		{
			if(k[v[i]] == 1)
			{
				if(ke > c/2){
					cout << "A";
					ke--;
				}
				else
					cout << "B";
			}
			else
				cout << "A";
		}
	}
	else{
		re(i , n)
		{
			if(k[v[i]] > 2 && k[v[i]] != 1){
				cout << "YES" <<"\n";
				keu = 1;
				break;
			}
		}
		if(keu){
			re(i , n)
			{
				if(!key && k[v[i]] > 2 && k[v[i]] != 1)
				{
					cout << "B";
					key = 1;
				}
				else{
					if(k[v[i]] == 1)
					{
						if(ke > c/2){
							cout << "A";
							ke--;
						}
						else
							cout << "B";
					}
					else
						cout << "A";
				}
			}
		}
		else
			cout <<"NO";
	}
	cout <<"\n";
	return 0;
}