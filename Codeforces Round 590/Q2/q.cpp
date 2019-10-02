#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , q;
    cin >> n >> q;
    int temp;
    queue<int> qe;
    set<int> st;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        cin >> temp;
        if(st.find(temp) == st.end())
        {
            if(qe.size() == q)
            {
                int t = qe.front();
                qe.pop();
                st.erase(t);
                st.insert(temp);
                qe.push(temp);
            }
            else
            {
                qe.push(temp);
                st.insert(temp);
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