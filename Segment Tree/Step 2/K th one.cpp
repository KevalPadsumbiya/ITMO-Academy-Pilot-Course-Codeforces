#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

void makeSegTree(int index,int start,int end,int segtree[],int a[])
{
	if(start==end)
	{
		segtree[index]=a[start];
		return;	
	}	
	int mid=(start+end)>>1;
	makeSegTree(index<<1,start,mid,segtree,a);
	makeSegTree(index<<1|1,mid+1,end,segtree,a);
	
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
	int n,m,i,type,k;
	cin>>n>>m;
	int a[n],segtree[4*n];
	for(i=0;i<n;i++)
		cin>>a[i];
	makeSegTree(1,0,n-1,segtree,a);
	while(m--)
	{
		cin>>type>>k;
		if(type==2)
			cout<<query(1,0,n-1,k+1,segtree)<<"\n";
		else
			update(1,0,n-1,k,segtree);
	}
	return 0;
}

