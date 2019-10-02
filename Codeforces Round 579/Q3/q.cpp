#include<bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

long long int findGCD(vector<long long int> &arr, int n) 
{ 
    long long int result = arr[0]; 
    for (int i = 1; i < n; i++) 
        result = gcd(arr[i], result); 
  
    return result; 
} 

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    long long int mn = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
        mn = min(mn , v[i]);
    }
    if(mn == 1){
        cout << 1 <<"\n";
        return 0;
    }
    long long int gd = findGCD(v , n);
    int cnt = 0;
    long long int i = 2;
    for (int i=1; i<=sqrt(gd); i++) 
    { 
        if (gd%i == 0) 
        { 
            if (gd/i == i) 
                cnt++; 
            else // Otherwise print both 
                cnt += 2; 
        } 
    } 
    cout << cnt <<"\n";
    return 0;
}