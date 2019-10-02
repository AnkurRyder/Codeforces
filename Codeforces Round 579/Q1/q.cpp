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
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
            v[i]--;
        }
        bool key = true;
        for(int i = 0 ; i < n-1 ; i++)
        {
            if((v[i] + 1)%(n) != v[i+1])
            {
                key = false;
                break;
            }
        }
        if(key)
        {
            cout << "YES" <<"\n";
            continue;
        }
        key = true;
        for(int i = n-1 ; i > 0 ; i--)
        {
            if((v[i] + 1)%(n) != v[i-1])
            {
                key = false;
                break;
            }
        }
        if(key)
            cout << "YES" <<"\n";
        else
        {
                cout << "NO" <<"\n";
        }
    }
    return 0;
}