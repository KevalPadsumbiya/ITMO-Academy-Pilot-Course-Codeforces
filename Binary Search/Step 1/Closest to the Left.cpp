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
	lli n,k,i,mid,l,r,num;
	cin>>n>>k;
	lli a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	while(k--)
	{
		cin>>num;
		l=-1,r=n;
		while(l+1<r)
		{
			mid=(l+r)/2;
			if(a[mid]<=num)		//a[l]<=num , a[r]>num
				l=mid;
			else
				r=mid;	
		}
		// we have to print index+1 so if l lies in [0,n-1] then we will print l+1
		if(l!=n && l>-1)
			cout<<l+1<<"\n";
		else 	// if all elements are less than given elemtnt or all are greater than given element
			cout<<max((lli)0,l)<<"\n";
	}
	return 0;
}

// l=-1 and r=n because to handle corner cases:
// all elements are less than given element
// all elements are greater than given element
