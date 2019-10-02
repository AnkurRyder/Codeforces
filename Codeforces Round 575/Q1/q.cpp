#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        vector<long long int> v(3);
        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin() , v.end());
        cout << (v[0] + v[1] + v[2])/2 <<"\n";
    }
}