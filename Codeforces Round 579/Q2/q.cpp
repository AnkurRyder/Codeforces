#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<int> v(4*n);
        map<int , int> mp;
        for(int i = 0 ; i < 4*n ; i++){
            cin >> v[i];
            mp[v[i]]++;
        }
        bool key = true;
        for(auto j:mp)
        {
            if(j.second%2 != 0)
            {
                key = false;
                break;
            }
        }
        if(!key)
        {
            cout << "NO" <<"\n";
            continue;
        }
        sort(v.begin() , v.end());
        int i = 0 , j = 4*n-1;
        int e = v[0]*v[4*n-1];
        while(i < j)
        {
            if(v[i]*v[j] != e)
            {
                key = false;
                break;
            }
            i++;
            j--;
        }
        if(key)
            cout << "YES" << "\n";
        else
            cout << "NO" <<"\n";
    }
}