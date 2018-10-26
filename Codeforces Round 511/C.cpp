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

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
void findGCD(vector <int> &arr, int n , vector<int> &gc) 
{
	gc[n-1] = arr[n-1];  
    int result = arr[n-1]; 
    for (int i = n-2; i >= 0; i--){ 
        result = gcd(arr[i], result);
        gc[i] = result; 
  	} 
} 
 


int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	re(i , n)
		cin >> v[i];
	sort(v.begin(), v.end());
	std::vector<int> gc(n);
	findGCD(v , n , gc);
	rep(i ,0 ,  n-2)
	{
		if(gc[i] < gc[i+1])
		{
			cout << i+1 << "\n";
			return 0;
		}
	}
	cout << -1 <<"\n";
	return 0;
}