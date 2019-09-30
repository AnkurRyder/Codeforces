#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int a[n];
    long long int mx = INT_MIN;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        mx = max(mx , a[i]);
    }
    int o , e;
    o = 0; e = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if((a[i]-mx)%2 == 0)
            e++;
        else
            o++;
    }
    cout << min(o , e) << "\n";
    return 0;
}