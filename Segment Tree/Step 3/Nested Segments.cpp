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
		return query(index<<1,start,mid,l,mid,segtree)+query(index<<1|1,mid+1,end,mid+1,r,segtree);	
}

int main()
{
	fastio;
	int n,i;
	cin>>n;
	int a[2*n],left[n+1],right[n+1],vis[n+1]={0},segtree[4*(2*n)]={0};
	for(i=0;i<2*n;i++)
	{
		cin>>a[i];
		// store index of first occurance of evrery number for update purpose
		if(vis[a[i]]==0)
			left[a[i]]=i;
		vis[a[i]]^=1;
	}
	
	int ans[n+1]={0};
	
	for(i=0;i<2*n;i++)
	{
		if(vis[a[i]])
		{	
			ans[a[i]]=query(1,0,2*n-1,left[a[i]],i,segtree);
			update(1,0,2*n-1,left[a[i]],segtree);
		}
		else
			vis[a[i]]^=1;	
	}
	for(i=1;i<=n;i++)
		cout<<ans[i]<<" ";
	return 0;
}

/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~[Logic]~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-				index  : 0 1 2 3 4 5
- consider given array : 1 2 3 2 1 3
- example of nested segment : 1 2 2 1 .. here 2 is nested in 1
- for counting number of nested segments:
- we start travesring array from left and when we encounter second occurance of any number we count sum in range left[a[i]] to i and then we update ith pos as 1
- here i am finding a[i]th 1 from left to right and ans would be n-position_of_a[i]th_1 due to left to right logic

*/
