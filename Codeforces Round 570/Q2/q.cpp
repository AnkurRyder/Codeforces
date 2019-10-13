#include <bits/stdc++.h>

using namespace std;

int8_t check(vector<int>&v , int x , int k)
{
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i] - x > k)
            return 1;
        else if(x - v[i] > k)
            return 2;
    }
    //cout << x <<"\n";
    return 0;
}

int fi(vector<int> &v , int mn , int mx , int k)
{
    int mid , last;
    while(mx >= mn)
    {
        mid = (mn + mx)/2;
        //cout << mid <<" mid" <<"\n";
        int a = check(v , mid , k);
        if(a == 0){
            last = mid;
            mn = mid+1;
        }
        else if(a == 1){
            mn = mid+1;        
        }
        else
        {
            mx = mid-1;
        }
        
    }
    return last;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n , k;
        cin >> n >> k;
        vector<int> v(n);
        int mn = INT_MAX , mx = 0;
        for(int i = 0 ; i< n ; i++){
            cin >> v[i];
            mx = max(mx , v[i]);
            mn = min(mn , v[i]);
        }
        if(ceil((double)(mx - mn)/2) > k)
        {
            cout << -1 <<"\n";
            continue;
        }
        else
        {
            mx = mx + k;
            cout << fi(v , mn , mx , k) << "\n";
        }
    }
    return 0;
}