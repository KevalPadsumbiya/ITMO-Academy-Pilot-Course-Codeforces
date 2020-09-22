#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli k,n,ans;
vector<lli> a;

bool good(lli x)
{
	lli temp=x;
	x*=k;
	for(auto el : a)
		x-=min(temp,el);
	return x<=0;
}

int main()
{
	fastio;
	lli l,r,mid,i;
	cin>>k>>n;
	a.resize(n);
	for(i=0;i<n;i++)
		cin>>a[i];

	l=0,r=1e12;
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(good(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<l;
	return 0;
}

