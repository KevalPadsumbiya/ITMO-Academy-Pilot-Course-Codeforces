#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int n,i,k,a[10001],j;

bool good(double l)
{
	int pieces=0;
	for(i=0;i<n;i++)
		pieces+=(a[i]/l);	
	return pieces>=k;
}

int main()
{
	fastio;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>a[i];
		
	double l=0; 	// l is good..because it is possible to cut k pieces or ropes having length 0
	double r=1e7+10; 	// a[i]<=10^7;
	double mid;
	
	for(j=0;j<100;j++)
	{
		mid=(l+r)/2;
		if(good(mid))
			l=mid;
		else
			r=mid;
	}

	cout<<setprecision(7)<<l;	// we can print either r or l as they are very close

	return 0;
}

