#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
 
void make_segTree(lli index,lli start,lli end,lli segtree[],lli a[])
{
	if(start==end)
	{
		segtree[index]=a[start];
		return;
	}
	lli mid=(start+end)>>1;
	make_segTree(index<<1,start,mid,segtree,a);
	make_segTree(index<<1|1,mid+1,end,segtree,a);
	
	segtree[index]=min(segtree[index<<1],segtree[index<<1|1]);
}
 
void update(lli index,lli start,lli end,lli i,lli value,lli segtree[])
{
	if(start==end)
	{
		segtree[index]=value;
		return;	
	}	
	lli mid=(start+end)>>1;
	if(i<=mid)
		update(index<<1,start,mid,i,value,segtree);
	else
		update(index<<1|1,mid+1,end,i,value,segtree);
	segtree[index]=min(segtree[index<<1],segtree[index<<1|1]);
}
 
lli query(lli index,lli start,lli end,lli l,lli r,lli segtree[])
{
	if(l==start && r==end)
		return segtree[index];	
	
	lli mid=(start+end)>>1;
	if(r<=mid)
		return query(index<<1,start,mid,l,r,segtree);
	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,segtree);
	else
		return min(query(index<<1,start,mid,l,mid,segtree),query(index<<1|1,mid+1,end,mid+1,r,segtree));
}
 
int main()
{
	fastio;
	lli n,q,i,l,r,type;
	
	cin>>n>>q;
 
	lli segtree[n*4],a[n];
	
	for(i=0;i<n;i++)
		cin>>a[i];
	make_segTree(1,0,n-1,segtree,a);
	while(q--)
	{
		cin>>type>>l>>r;
		if(type==1)
			update(1,0,n-1,l,r,segtree);
		else
			cout<<query(1,0,n-1,l,r-1,segtree)<<"\n";
	}
	return 0;
}
