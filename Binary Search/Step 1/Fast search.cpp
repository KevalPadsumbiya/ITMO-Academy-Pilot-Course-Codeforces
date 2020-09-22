#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	lli q,n,i,j,num,l,r,mid,low,up,low1,up1;
	cin>>n;
	lli a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		
		// find closest element to the right(num>=l) number of l
		low=-1,up=n;
		while(low+1<up)
		{
			mid=(low+up)/2;
			if(a[mid]<l)	// a[low]<l , a[up]>=r
				low=mid;
			else	
				up=mid;
		}
		
		// find closet to the left(num<=r) number of r		
		low1=-1,up1=n;
		while(low1+1<up1)
		{
			mid=(low1+up1)/2;
			if(a[mid]<=l)	// a[low1]<=l && a[up1]>r
				low1=mid;
			else
				up1=mid;
		}
		
		if(low1==-1 && up==n)
			cout<<0<<"\n";
		else
			cout<<low1-up+1<<"\n";
	}
	return 0;
}

