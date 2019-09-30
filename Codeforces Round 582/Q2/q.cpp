#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        int temp;
        for(int i = 0 ; i < n ; i++)
        {
            cin >> temp;
            if(st.empty())
                st.push(temp);
            else
            {
                while(!st.empty() && temp < st.top())
                {
                    st.pop();
                }
                st.push(temp);
            }
            
        }
        cout << n - st.size() <<"\n";
    }
    return 0;
}