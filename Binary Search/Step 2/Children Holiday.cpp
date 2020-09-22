#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli m,n,cur;
lli t[15001],z[15001],y[15001],ans[15001];

bool good(lli time)
{
	lli i,temp=time;
	cur=0;
	memset(ans,0,sizeof(0));
	for(i=0;i<n;i++)
	{
		time=temp;
		if(time/t[i]>z[i])
		{
			ans[i]=z[i]*(time/((t[i]*z[i])+y[i]));
			time=time%((t[i]*z[i])+y[i]);
			if(time/t[i]>z[i])
				ans[i]+=z[i];
			else
				ans[i]+=(time/t[i]);
		}
		else
			ans[i]=time/t[i];
		cur+=ans[i];
	}
	return cur>=m;
}

int main()
{
	fastio;
	
	lli i,l,r,mid;
	cin>>m>>n;
	
	for(i=0;i<n;i++)
		cin>>t[i]>>z[i]>>y[i];
	
	if(m==0)
	{
		cout<<0<<endl;
		for(i=0;i<n;i++)
			cout<<0<<" ";
		return 0;
	}
	
	l=0,r=1e9;
	
	while(l+1<r)
	{
		mid=(l+r)/2;
		if(good(mid))
			r=mid;
		else
			l=mid;
	}

	// r is answer so for filling ans array we have to call good(r)
	bool last=good(r);
	lli c=m;

	cout<<r<<endl;
	for(i=0;i<n;i++)
	{
		cout<<max((lli)0,min(c,(lli)ans[i]))<<" ";
		c-=ans[i];		// because we have to inflates exactly m balloons
	}

	return 0;
}

