#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , b;
    cin >> a >> b;
    int t;
    bool key;
    for(int i = a ; i <= b ; i++)
    {
        vector<int> m(10 , 0);
        key = true;
        t = i;
        while(t)
        {
            if(m[t%10] == 1){
                key = false;
                break;
            }
            else
            {
                m[t%10] = 1;
                t = t/10;
            }
        }
        if(key){
            cout << i <<"\n";
            return 0;
        }
    }
    cout << -1 <<"\n";
    return 0;
}