#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long int n , m;
        cin >> n >> m;
        set<int> mp;
        int u = m%10 , in = 0;
        int temp = 0;
        while(mp.find(u) == mp.end())
        {
            in++;
            temp += u;
            mp.insert(u);
            u = (u + m)%10;
        }
        long long int d = n/m;
        long long int a = d/in , b = d%in;
        long long int ans = temp*a;
        u = m%10;
        while(b--)
        {
            ans += u;
            u = (u + m)%10;
        }
        cout << ans <<"\n";
    }
    return 0;
}