#include <bits/stdc++.h>

using namespace std;

bool helper(vector<int> &v , int in , int k , vector<int> &ans , long long int sum)
{
    if(k <= 0 || in > v.size())
        return false;
    if(k == 1 && in == v.size())
    {
        if(sum%2 == 1){
            ans.push_back(in);
            return true;
        }
        else
            return false;
    }
    bool key = false;
    if(sum%2 == 1)
    {
        key |= helper(v , in+1 , k , ans , (sum+v[in])%2);
        if(key)
            return key;
        ans.push_back(in);
        key |= helper(v , in+1 , k-1 , ans , v[in]);
        if(!key)
            ans.pop_back();
    }
    else
    {
        key |= helper(v , in+1 , k , ans , (sum+v[in])%2);
    }
    return key;
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n , k;
        cin >> n >> k;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            v[i] = v[i]%2;
        }
        vector<int> ans;
        if(helper(v , 0 , k , ans , 0))
        {
            cout << "YES" <<"\n";
            for(auto j:ans)
                cout << j <<" ";
            cout << "\n";
        }
        else
        {
            cout << "NO" <<"\n";
        }
    }
}