#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

double x[100001],v[100001],n;

bool good(double t)
{
	long double mx=-1e10,mn=1e10;
	int i;
	for(i=0;i<n;i++)
	{
		long double a=x[i]-t*v[i];
		long double b=x[i]+t*v[i];
		mn=min(mn,b);
		mx=max(mx,a);	
	}
	// check whether all intervals intersect	
	return mx<=mn;
}

int main()
{
	fastio;
	int i;
	double l,r,mid;
	
	cin>>n;
	for(i=0;i<n;i++)
		cin>>x[i]>>v[i];
	
	l=0,r=1e9+10;
	
	for(i=0;i<100;i++)
	{
		mid=(l+r)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}
	
	cout<<setprecision(10)<<l;
	
	return 0;
}

