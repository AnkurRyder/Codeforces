#include<bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        vector<pair<int , int> > r(n) , c(n);
        vector<vector<int>> mov(n , vector<int> (4 , 0));
        int t;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> t;
            c[i] = {t , i};
            cin >> t;
            r[i] = {t , i};
            cin >> mov[i][0] >> mov[i][1] >> mov[i][2] >> mov[i][3];
        }
        sort(r.begin() , r.end());
        sort(c.begin() , c.end());
        int left , right , up , down;
        left = down = -100000;
        up = right = 100000;
        bool key = true;
        for(int i = 0 ; i < n ; i++)
        {
            if(!mov[r[i].second][1])
            {
                if(up > r[i].first)
                    up = r[i].first;
                if(up < down)
                {
                    key = false;
                    break;
                }
            }
            if(!mov[r[i].second][3])
            {
                if(down < r[i].first)
                    down = r[i].first;
                if(up < down)
                {
                    key = false;
                    break;
                }
            }
        }
        if(!key)
        {
            cout << 0 <<"\n";
            continue;
        }
        for(int i = 0 ; i < n ; i++)
        {
            //cout << "r " << right <<" l " << left <<"\n";
            if(!mov[c[i].second][0])
            {
                if(left < c[i].first)
                    left = c[i].first;
                if(right < left)
                {
                    key = false;
                    break;
                }
            }
            if(!mov[c[i].second][2])
            {
                if(right > c[i].first)
                    right = c[i].first;
                if(right < left)
                {
                    key = false;
                    break;
                }
            }
        }
        if(!key)
        {
            cout << 0 <<"\n";
            continue;
        }
        cout << 1 << " " << left <<" " << up <<"\n";
    }
    return 0;
}