#include<bits/stdc++.h>
using namespace std;

int comb(int j)
{
  if(j == 0)
    return 0;
  else
    return pow(2 , j) + comb(j-1);
}

int main() {
  int n,j = 0 , a = 0 , c;
  cin >> n;
  c = n;
  while(c > 0)
  {
    c = c/10;
    j++;
  }
  c = pow(10 , j-1);
  while(n > 0)
  {
    if(n/c == 4)
    {
      a = (a<<1);
    }
    else
    {
      a = (a<<1)|1; 
    }
    n = n%c;
    c = c/10;
  }
  cout <<comb(j-1) + a + 1 <<"\n";
	return 0;
}