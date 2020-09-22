#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
void update(int index,int start,int end,int i,int segtree[])
{
	if(start==end)
	{
		segtree[index]=1;
		return;	
	}	
	int mid=(start+end)>>1;
	if(i<=mid)
		update(index<<1,start,mid,i,segtree);
	else
		update(index<<1|1,mid+1,end,i,segtree);
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
}
 
int query(int index,int start,int end,int l,int r,int segtree[])
{
	if(l==start && r==end)
		return segtree[index];	
	
	int mid=(start+end)>>1;
	if(r<=mid)
		return query(index<<1,start,mid,l,r,segtree);
	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,segtree);
	else
		return query(index<<1,start,mid,l,mid,segtree) + query(index<<1|1,mid+1,end,mid+1,r,segtree);
}
 
int main()
{
	fastio;
	int n,q,i,l,r,type;
	
	cin>>n;
 
	int segtree[400005]={0},a;
		
	for(i=0;i<n;i++)
	{
		cin>>a;
		cout<<query(1,1,100001,a+1,100001,segtree)<<" ";
		update(1,1,100001,a,segtree);
	}
	return 0;
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[Logic]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- first segment tree is initialised with zero.. we need to calculate numbers more than a[i] at any step so we use seg tree to find sum in range(a[i]+1,1e5)
- because a[] is a permutation of N and N<=1e5
- after finding sum we are updating that index 

*/
