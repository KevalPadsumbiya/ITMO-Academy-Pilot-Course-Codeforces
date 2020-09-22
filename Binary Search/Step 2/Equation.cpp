#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

double c;

bool good(double x)
{
	return pow(x,2)+pow(x,0.5)>=c;	
}

int main()
{
	fastio;
	double l,r,mid,i;
	cin>>c;
	
	l=0,r=c;
	
	for(i=0;i<100;i++)
	{
		mid=(r+l)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}
	
	cout<<setprecision(10)<<r;
	
	return 0;
}

