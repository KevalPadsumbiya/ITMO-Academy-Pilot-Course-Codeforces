#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli h,w,n;

bool good(lli a)
{
	return (a/w)*(a/h)>=n;
}

int main()
{
	fastio;
	lli l,r,mid;
	cin>>h>>w>>n;
	
	l=0,r=1;
	while(!good(r))		// to avoid overflow
		r*=2;
	
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}
	
	cout<<r;
	
	return 0;
}

