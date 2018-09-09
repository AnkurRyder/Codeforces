#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int MinSTree(vector <int> arr, int ss, int se, vector <int>& st, int si);

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	//Size of Segment Tree.

	int m = n;
	int cont = 0;
	int max_size= 1;
	// count = minimum number of bits required to represent n
	while(n != 0) {
        n = n >> 1;
        cont++;
	}
	n = m;
	cont++;
	// max_size= size of the array representing the segment tree
    while(cont != 0) {
        max_size = max_size << 1;
        cont--;
	}
	max_size--;
	vector<int> v(max_size);
	MinSTree(a,0,n-1,v,0);
	return 0;
}

int MinSTree(vector <int> arr, int ss, int se, vector <int>& st, int si)
{
	if (ss== se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = (ss+ se)/2;
	st[si] = min(MinSTree(arr, ss, mid, st, si*2+1) , MinSTree(arr, mid+1, se, st, si*2+2));
	return st[si];
}

int getMin(vector<int> &st, int ss, int se, int qs, int qe, int index)
{
	// If segment of this node is contained in the given range, then return the min of the segment
	if (qs<= ss && qe>= se)
		return st[index];
	// If segment of this node is outside the given range
	if (se < qs|| ss> qe)
		return INT_MAX;
	// If a part of this segment overlaps with the given range
	int mid = (ss+ se)/2;
	return (min( getMin(st, ss, mid, qs, qe, 2*index+1) , getMin(st, mid+1, se, qs, qe, 2*index+2)));
}


int updateMinValue(vector <int> arr, vector <int> &st, int ss, int se, int i, int new_val, int si)
	{
	// Base Case: If the input index lies outside the range of this segment
	if (i< ss|| i> se)
		return st[si];
	// If the input index is the node to be updated, then update the value of the node
	if(ss== se && ss== i)
	{
		arr[i] = new_val;
		st[si] = new_val;
		return st[si];
	}
	// If the input index is in range of this node, then update the value of the node and its children
	int mid = (ss+ se)/2;
	st[si] = min(updateMinValue(arr, st, ss, mid, i, new_val, 2*si+ 1) , updateMinValue(arr, st, mid+1, se, i, new_val, 2*si+ 2));
	return st[si];
}
