#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define vzero fill(v.begin(), v.end(), 0);
#define re(i, n) for(ll i = 0; i < n; i++)
#define test llt; cin >> t; while(t--)
#define rep(i,a,b) for(ll i = (a); i <= (b); i++)
#define ren(i,a,b) for(ll i = (a); i >= (b); i--)
#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1e9+7
#define PI 3.1415926535897932384626433832795
#define MAX 100001
#define INF (1<<20)
ll dfs(ll s,ll &k,vector<bool> &visited,vector<ll> adj[])
{
	visited[s]=true;
				k++;
	re(i,adj[s].size())
	{
		if(visited[adj[s][i]]==false)
		{
			dfs(adj[s][i],k,visited,adj);
		}
	}
	return k;
}
int main()
{
	ll n;
	cin>>n;
	vector<ll> G[n+1];
	ll i=0;
	for(i=0;i<n;i++)
	{
	 ll m;
	 cin>>m;
	 G[i+1].push_back(m);
	 G[m].push_back(i+1);
	}
	vector<bool> visited(n+1);
	vector<ll> v;
	fill(visited.begin(),visited.end(),false);
	ll k=0;
	rep(i,1,n)
		{
        if(visited[i]==false)
                {
                    k=dfs(i,k,visited,G);
                    v.push_back(k);
                    k=0;
                }
                }

                if(v.size()==1)
                {
                    cout<<v[0]*(v[0]-1)+v[0]<<endl;
                    return 0;
                }
                else
                {
                int s=v.size();
            sort(v.begin(),v.end());
           ll mx=v[s-1];
            ll mx1=v[s-2];
        ll sum=0;
        re(i,v.size()-2)
        {
            sum+=((v[i])*(v[i]-1)+v[i]);
        }
        sum+=((mx+mx1)*(mx+mx1-1)+mx+mx1);
        cout<<sum<<endl;
		}
		return 0;
}
