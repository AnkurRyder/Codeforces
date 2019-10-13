#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    int sm = 0;
    while(n)
    {
        sm += n%10;
        n = n/10;
    }
    if(sm%4 == 0)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int i = n;
    while(1)
    {
        if(check(i))
            break;
        i++;
    }
    cout << i <<"\n";
    return 0;
}