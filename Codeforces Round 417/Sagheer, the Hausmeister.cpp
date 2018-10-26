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

int r , c;
std::vector<int> ri(16);
std::vector<int> le(16);
int calc(int cp , bool l ,int row)
{
	int ne = 0;
	if(row == r-1)
	{
		if(l)
			ne =1 + ri[row]; 
		else
			ne =1 + c+1 - le[row];
		return ne; 
	}
	if(l){
		ne = 1 + ri[row];
		cp = ri[row]; 
	}
	else{
		ne = 1 + c+1 - le[row];
		cp = le[row];
	}
	int left = calc(cp , 1 ,row+1);
	int right = calc(cp ,0 ,row+1);
	if(min(left , right) == 1)
		ne = ne; 
	else{
		left += cp;
		right += c+1 - cp;
		ne = ne + min(left , right);
	}
	return ne; 
}

int main()
{
	si(r); si(c);
	vector<string> v(r);
	ren(i , r-1 , 0)
	{
		cin >> v[i];
	}
	int key = 0;
	re(i , r)
	{
		le[i] = c+1;
		re(j , c+2)
		{
			if(v[i][j] == '1'){
				le[i] = j;
				key = i;
				break;
			}
		}
		ren(j , c+1 , 0)
		{
			if(v[i][j] == '1'){
				ri[i] = j;
				break;
			}
		}
	}
	int time = 0 , cp;
	time = ri[0];
	cp = ri[0];
	if(r > 1 && key > 0){
		int left = calc(cp , 1 ,1);
		left += cp;
		int right = calc(cp , 0, 1);
		right += c+1 - cp;
		time = time + min(left , right);
	}
	cout << time;
	return 0;
}