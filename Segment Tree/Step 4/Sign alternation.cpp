#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

void makeSegTree(int index,int start,int end,lli segtree[],int a[])
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

void update(int index,int start,int end,int i,int value,lli segtree[])
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
		
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
}

lli query(int index,int start,int end,int l,int r,lli segtree[])
{
	if(l==start && r==end)
		return segtree[index];
	int mid=(start+end)>>1;
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
	int n,i,m,x;
	cin>>n;
	int odd[n]={0},even[n]={0};
	lli segtree1[4*n],segtree2[4*n];
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(i%2)
			odd[i]=x;
		else
			even[i]=x;
	}
	
	makeSegTree(1,0,n-1,segtree1,odd);	// odd
	makeSegTree(1,0,n-1,segtree2,even);	// even
	
	cin>>m;
	
	while(m--)
	{
		int type;
		cin>>type;
		if(type==0)
		{
			int pos,value;
			cin>>pos>>value;
			pos--;
			if(pos%2)
				update(1,0,n-1,pos,value,segtree1);	// odd
			else	
				update(1,0,n-1,pos,value,segtree2);	// even
		}	
		else
		{
			int l,r;
			cin>>l>>r;
			l--,r--;
			lli sum1=query(1,0,n-1,l,r,segtree1);	// odd
			lli sum2=query(1,0,n-1,l,r,segtree2);	// even
			if(l%2)
				cout<<sum1-sum2<<"\n";
			else
				cout<<sum2-sum1<<"\n";
		}
	}
	
	return 0;
}

