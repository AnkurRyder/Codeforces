#include <bits/stdc++.h>

using namespace std;

long long int pow(int a , long long int b)
{
    long long int temp;  
    if(b == 0)  
        return 1;  
    temp = pow(a, b / 2);  
    if (b % 2 == 0)  
        return (temp%1000000007 * temp%1000000007)%1000000007;  
    else
        return (a* temp%1000000007 * temp%1000000007)%1000000007;   
}


int main()
{
    int r , c;
    cin >> r >> c;
    vector<int> row(r);
    vector<int> col(c);
    for(int i = 0 ; i < r ; i++)
        cin >> row[i];
    for(int i = 0 ; i < c ; i++)
        cin >> col[i];
    long long int t = r*c;
    vector<vector<int> > mat(r , vector<int> (c , 0));
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j <= row[i] ; j++)
        {
            if(j == c)
                break;
            if(j == row[i])
            {
                mat[i][j] = 2;
                t--;
                break;
            }
            if(mat[i][j] == 2)
            {
                cout << 0 <<"\n";
                return 0;
            }
            if(mat[i][j] == 0)
            {
                mat[i][j] = 1;
                t--;
            }
        }
    }
    for(int i = 0 ; i < c ; i++)
    {
        for(int j = 0 ; j <= col[i] ; j++)
        {
            if(j == r)
                break;
            if(j == col[i])
            {
                if(mat[j][i] != 2)
                    t--;
                mat[j][i] = 2;
                break;
            }
            if(mat[j][i] == 2)
            {
                cout << 0 <<"\n";
                return 0;
            }
            if(mat[j][i] == 0)
            {
                mat[j][i] = true;
                t--;
            }
        }
    }
    long long int ans = pow(2 , t);
    cout << ans%1000000007 <<"\n";
}