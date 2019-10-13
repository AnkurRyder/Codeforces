#include <bits/stdc++.h>

using namespace std;

long long int helper(int k , int n , int a , int b)
{
    long long int l = 0 , r = n , mid;
    long long int last = 0;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(a*mid + b*(n-mid) < k){
            last = mid;
            l = mid+1;
        }
        else
            r = mid-1;
    }
    return last;
}


int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long int a , b , n , k;
        cin >> k >> n >> a >> b;
        if(n*b >= k)
        {
            cout << -1 <<"\n";
            continue;
        }
        cout << helper(k , n , a , b) <<"\n";
    }
    return 0;
}