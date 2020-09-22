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
	lli n,k,i,l,r,mid,num;
	cin>>n>>k;
	lli a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	while(k--)
	{	
		cin>>num;
		l=0,r=n-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(a[mid]==num)
				break;
			if(a[mid]<num)
				l=mid+1;
			else
				r=mid-1;
		}
		if(a[mid]==num)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}

