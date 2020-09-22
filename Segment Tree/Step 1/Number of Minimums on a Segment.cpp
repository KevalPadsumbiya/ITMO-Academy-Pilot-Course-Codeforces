#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

void merge(int index,vector<pair<int,int>> *segtree)
{
	pair<int,int> p;
	if(segtree[index<<1][0].first>segtree[index<<1|1][0].first)
		p=segtree[index<<1|1][0];
	else if(segtree[index<<1][0].first<segtree[index<<1|1][0].first)
		p=segtree[index<<1][0];
	else 
		p={segtree[index<<1][0].first,segtree[index<<1][0].second+segtree[index<<1|1][0].second};
	
	if(segtree[index].size())
		segtree[index][0].first=p.first , segtree[index][0].second=p.second;
	else
		segtree[index].pb(p);
}

void makeSegTree(int index,int start,int end,int a[],vector<pair<int,int>> *segtree)
{
	if(start==end)	
	{
		segtree[index].pb({a[start],1});
		return;
	}
	int mid=(start+end)>>1;
	makeSegTree(index<<1,start,mid,a,segtree);
	makeSegTree(index<<1|1,mid+1,end,a,segtree);
	
	merge(index,segtree);
}

pair<int,int> cur_ans;

pair<int,int> query(int index,int start,int end,int l,int r,vector<pair<int,int>> *segtree)
{
	if(l==start && r==end)
		return segtree[index][0];	
	
	int mid=(start+end)>>1;
	
	if(r<=mid)
		return query(index<<1,start,mid,l,r,segtree);
 	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,segtree);
	else
	{
		pair<int,int> p1=query(index<<1,start,mid,l,mid,segtree);
		pair<int,int> p2=query(index<<1|1,mid+1,end,mid+1,r,segtree);
		if(p1.first<p2.first)
			return p1;
		else if(p1.first>p2.first)
			return p2;
		else 
			return {p1.first,p1.second+p2.second};
	}	
}	

void update(int index,int start,int end,int i,int value,int a[],vector<pair<int,int>> *segtree)
{
	if(start==end)
	{
		a[i]=value;
		segtree[index][0].first=value;
		return;
	}	
	int mid=(start+end)>>1;
	
	if(i<=mid)
		update(index<<1,start,mid,i,value,a,segtree);
	else
		update(index<<1|1,mid+1,end,i,value,a,segtree);
	
	merge(index,segtree);
}

int main()
{
	fastio;
	int n,m,i,l,r,type;

	cin>>n>>m;

	vector<pair<int,int>> segtree[4*n];
	int a[n];

	for(i=0;i<n;i++)
		cin>>a[i];

	makeSegTree(1,0,n-1,a,segtree);

	while(m--)
	{
		cin>>type>>l>>r;
		if(type==2)
		{
			pair<int,int> p=query(1,0,n-1,l,r-1,segtree);
			cout<<p.first<<" "<<p.second<<"\n";
		}
		else
			update(1,0,n-1,l,r,a,segtree);
	}
	return 0;
}

