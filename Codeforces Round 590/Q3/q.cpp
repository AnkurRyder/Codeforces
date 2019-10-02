#include<bits/stdc++.h>

using namespace std;

bool helper(vector<vector<int> > &v , int r , int c , int l)
{
    //cout << r <<" " << c <<"\n";
    if(c == 0 && r == 0)
    {
        if(v[0][0] > 2 && l == 1)
            return true;
        if(v[0][0] < 3 && l == 0)
            return true;
        else
        {
            return false;
        }
        
    }
    bool ans = false;
    if(v[r][c] > 2)
    {
        if(l == 0 && r == 0)
        {
            if(v[1][c] > 2)
                ans |= helper(v , 1 , c , r);
            else
                return false;
        }
        else if(l == 1 && r == 1)
        {
            if(v[0][c] > 2)
                ans |= helper(v , 0 , c , r);
            else
                return false;
        }
        else if(l == 0 && r == 1)
        {
            ans |= helper(v , 1 , c-1 , r);
        }
        else
        {
            ans |= helper(v , 0 , c-1 , r);
        }
    }
    else
    {
        ans |= helper(v , r , c-1, r);
    }
    return ans;
}
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        char a;
        vector<vector<int> > v(2 , vector<int> (n));
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            v[0][i] = (a - '0');
        }
        for(int i = 0 ; i < n ; i++)
        {
            cin >> a;
            v[1][i] = (a - '0');
        }
        if(helper(v , 1 , n-1 , 1))
            cout << "YES" <<"\n";
        else
            cout << "NO" <<"\n";
    }
    return 0;
}