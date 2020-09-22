#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

void update(lli index,lli start,lli end,lli i,lli value,lli segtree[])
{
	if(start==end)
	{
		segtree[index]+=value;
		return;	
	}	
	lli mid=(start+end)>>1;
	if(i<=mid)
		update(index<<1,start,mid,i,value,segtree);
	else
		update(index<<1|1,mid+1,end,i,value,segtree);
	
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
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
		return query(index<<1,start,mid,l,mid,segtree)+query(index<<1|1,mid+1,end,mid+1,r,segtree);
}

int main()
{
	fastio;
	lli n,m,i,type;
	cin>>n>>m;
	lli a[n]={0},segtree[4*n]={0};
	while(m--)
	{
		cin>>type;
		if(type==1)
		{
			lli l,r,value;
			cin>>l>>r>>value;
			update(1,0,n,l,value,segtree);
			update(1,0,n,r,-value,segtree);
		}
		else
		{
			lli pos;
			cin>>pos;
			cout<<query(1,0,n,0,pos,segtree)<<"\n";
		}
	}
	return 0;
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[Logic]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

- idea is to update lth index by value and rth index by -value
- than for finding value at ith index we will find prefix sum of a[0,i]

*/
