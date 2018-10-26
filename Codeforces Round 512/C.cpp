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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int sum = 0, sumt = 0;
	vector<int> v(s.size());
	re(i , s.size()){
		v[i] = s[i] - 48;
		sum += v[i];
	}
	int j =0;
	if(sum == 0){
		cout << "YES" <<"\n";
		return 0;
	}
	rep(i , 2 , sum)
	{
		if(sum % i == 0)
		{
			j = 0;
			sumt = 0;
			for(j ; j < n ; j++)
			{
				if(sumt < (sum/i))
					sumt += v[j];
				if(sumt > (sum/i))
					break;
				if(sumt == (sum/i))
					sumt = 0;  
			}
			if(sumt == 0 && j == n){
				cout << "YES" <<"\n";
				return 0;
			}
		}
	}
	cout << "NO" <<"\n";
	return 0;
}