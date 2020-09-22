#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> multiply(vector<int> m1,vector<int> m2,int r)
{
	vector<int> v(4);
	v[0]=((m1[0]*m2[0]) + (m1[1]*m2[2]))%r;	
	v[1]=((m1[0]*m2[1]) + (m1[1]*m2[3]))%r;
	v[2]=((m1[2]*m2[0]) + (m1[3]*m2[2]))%r;
	v[3]=((m1[2]*m2[1]) + (m1[3]*m2[3]))%r;
	return v;
}

void makeSegTree(int index,int start,int end,int r,int a[][4],vector<vector<int>> segtree[])
{
	if(start==end)
	{
		vector<int> v(4);
		v[0]=a[start][0];
		v[1]=a[start][1];
		v[2]=a[start][2];
		v[3]=a[start][3];
		segtree[index].pb(v);
		return;
	}
	int mid=(start+end)>>1;
	makeSegTree(index<<1,start,mid,r,a,segtree);
	makeSegTree(index<<1|1,mid+1,end,r,a,segtree);
	
	vector<int> v=multiply(segtree[index<<1][0],segtree[index<<1|1][0],r);
	segtree[index].pb(v);
}

vector<int> query(int index,int start,int end,int l,int r,int m,vector<vector<int>> segtree[])
{
	if(l==start && r==end)
		return segtree[index][0];
		
	int mid=(start+end)>>1;
	if(r<=mid)
		return query(index<<1,start,mid,l,r,m,segtree);
	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,m,segtree);
	else
	{
		vector<int> m1=query(index<<1,start,mid,l,mid,m,segtree);
		vector<int> m2=query(index<<1|1,mid+1,end,mid+1,r,m,segtree);
		vector<int> v=multiply(m1,m2,m);
		return v;
	}	
}


int main()
{
	fastio;

	int r,n,m,i,low,up;
	cin>>r>>n>>m;

	int a[n][4];
	vector<vector<int>> segtree[4*n];

	for(i=0;i<n;i++)
		cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];

	makeSegTree(1,0,n-1,r,a,segtree);

	while(m--)
	{
		cin>>low>>up;
		low--,up--;
		vector<int> ans=query(1,0,n-1,low,up,r,segtree);
		cout<<ans[0]<<" "<<ans[1]<<"\n";
		cout<<ans[2]<<" "<<ans[3]<<"\n\n";
	}
	return 0;
}

