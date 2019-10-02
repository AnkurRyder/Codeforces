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
        long long int sum = 0 , temp;
        for(int i = 0 ; i < n ; i++){
            cin >> temp;
            sum += temp;
        }
        cout << (sum%n == 0 ? sum/n : sum/n +1) <<"\n";
    }
    return 0;
}