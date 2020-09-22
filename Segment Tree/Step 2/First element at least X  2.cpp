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
	
	segtree[index]=max(segtree[index<<1],segtree[index<<1|1]);
}

void update(int index,int start,int end,int i,int value,int segtree[])
{
	if(start==end)
	{
		segtree[index]=value;
		return;	
	}	
	int mid=(start+end)>>1;
	if(i<=mid)
		update(index<<1,start,mid,i,value,segtree);
	else
		update(index<<1|1,mid+1,end,i,value,segtree);
		
	segtree[index]=max(segtree[index<<1],segtree[index<<1|1]);
}

int query(int index,int start,int end,int value,int r,int segtree[])
{
	cout<<"query : "<<index<<endl;
	if(segtree[1]<value)
		return -1;
	if(start==end)
		return start;
	int mid=(start+end)/2;
	if(segtree[index<<1]>=value && mid>=r)
		return query(index<<1,start,mid,value,r,segtree);
	else if(end<=r)
		return query(index<<1|1,mid+1,end,value,r,segtree);	
}

int main()
{
	fastio;
	int n,m,i,type,l,r;
	cin>>n>>m;
	int a[n],segtree[4*n];
	for(i=0;i<n;i++)
		cin>>a[i];
	makeSegTree(1,0,n-1,segtree,a);
	while(m--)
	{
		cin>>type>>l>>r;
		if(type==2)
			cout<<query(1,0,n-1,l,r,segtree)<<"\n";	
		else
			update(1,0,n-1,l,r,segtree);
	}
	return 0;
}

