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
			int nested_segments=query(1,0,2*n-1,left[a[i]],i,segtree);
			ans[a[i]]=(i-left[a[i]]-1)-2*nested_segments;
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

- used logic of nested segments
- " if for any number number , nested segments into it will not be counted as intersected segment and rest will either have left end point or right end point into 
    current segment". keeping this in mind count number of elements between two end points of any segment and then subtract 2*nested_segments from it as any nested 
	segment has two end points.
- 				   index : 0 1 2 3 4 5
- consider given example : 1 2 3 2 1 3
- here segment of any number means subarray between index_of_first_occurance of that number and index_of_last_occurance of that element. eg: for 1 segment = [2,3,2]
- for segment of 1 which ends at index 4 , so initially our ans = (4-0)-1 : number of elements in segment of 1 ,here segment of 2 is nested into 1's segment so we will
  subtract it two end points from our ans so ans = 3-(2*nested segment) = 3-(2*1) = 1

*/
