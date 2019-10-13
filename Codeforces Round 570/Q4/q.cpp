#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        map<int , int> m;
        int t;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> t;
            m[t]++;
        }
        set<pair<int , int>> st;
        for(auto j:m)
            st.insert({j.second , j.first});
        int ans = 0, mx = 0;
        mx = INT_MAX;
        for(auto j = --(st.end());  ; j--)
        {
            if(j->first >= mx){
                ans += (mx-1);
                mx--;
            }
            else
            {
                ans += j->first;
                mx = j->first;
            }
            if(mx == 0 || j == st.begin())
                break;
        }
        cout << ans <<"\n";
    }
    return 0;
}