#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli n,x,y,l,r,mid;

bool good(lli t)
{
	return (t/x)+(t/y)>=n-1;	
}

int main()
{
	fastio;
	cin>>n>>x>>y;
	if(n==1)
	{
		cout<<min(x,y);
		return 0;
	}

	l=0,r=2*(1e9)+10;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}
	
	cout<<r+min(x,y);
	
	return 0;
}

