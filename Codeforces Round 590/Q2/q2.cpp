#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , q;
    cin >> n >> q;
    int temp;
    queue<int> qe;
    map<int , int> st;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> temp;
        if(st[temp] == 0)
        {
            if(qe.size() == q)
            {
                int t = qe.front();
                qe.pop();
                st[t] = 0;
                st[temp] = 1;
                qe.push(temp);
            }
            else
            {
                qe.push(temp);
                st[temp] = 1;
            }
            
        }
        cnt = max(cnt , (int)qe.size());
    }
    cout << cnt << "\n";
    vector<int> v;
    while(!qe.empty())
    {
        v.push_back(qe.front());
        qe.pop();
    }
    for(int i = v.size()-1 ; i >= 0 ; i--)
        cout << v[i] <<" ";
    cout << "\n";
}