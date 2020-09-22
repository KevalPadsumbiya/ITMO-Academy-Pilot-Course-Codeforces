#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

void makeSegTree(int index,int start,int end,int segtree[])
{
	if(start==end)
	{
		segtree[index]=1;
		return;	
	}	
	int mid=(start+end)>>1;
	makeSegTree(index<<1,start,mid,segtree);
	makeSegTree(index<<1|1,mid+1,end,segtree);
	
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
}

void update(int index,int start,int end,int i,int segtree[])
{
	if(start==end)
	{
		segtree[index]^=1;
		return;
	}
	int mid=(start+end)>>1;
	if(i<=mid)
		update(index<<1,start,mid,i,segtree);
	else
		update(index<<1|1,mid+1,end,i,segtree);
		
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
}

int query(int index,int start,int end,int k,int segtree[])
{
	if(start==end)
		return start;
	int mid=(start+end)>>1;
	if(segtree[index<<1]>=k)
		query(index<<1,start,mid,k,segtree);
	else 
		query(index<<1|1,mid+1,end,k-segtree[index<<1],segtree);
}

int main()
{
	fastio;
	int n,i,type,k;
	cin>>n;
	int a[n],segtree[4*n];
	for(i=0;i<n;i++)
		cin>>a[i];
	makeSegTree(1,0,n-1,segtree);
	
	vector<int> ans;
	
	for(i=n-1;i>=0;i--)
	{
		int pos=query(1,0,n-1,a[i]+1,segtree);
		ans.pb(n-pos);
		update(1,0,n-1,pos,segtree);
	}
	
	for(i=n-1;i>=0;i--)
		cout<<ans[i]<<" ";
	return 0;
}	

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[Logic]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- consider given array a[] = 0 1 1 0 3
											 index    = 1 2 3 4 5 	(1 based)
- take one more array and initialized it with one b[] = 1 1 1 1 1 
- now start traversing a[] from last and find 1 which is at ith position(0-based) from right in b[] and for that i ans would be index of a[i]th 1
- then update position of a[i]th 1 as 0
 
*/
