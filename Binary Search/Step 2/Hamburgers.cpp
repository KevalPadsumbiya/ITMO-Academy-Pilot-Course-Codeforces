#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli rb,price;

bool good(lli n)
{
	return rb/price>=n;	
}

int main()
{
	fastio;
	string s;
	cin>>s;
	lli B=0,S=0,C=0,nb,ns,nc,pb,ps,pc,l,r,mid;
	for(auto ch : s)
	{
		if(ch=='B')
			B++;
		else if(ch=='S')
			S++;
		else
			C++;
	}

	cin>>nb>>ns>>nc;
	cin>>pb>>ps>>pc;
	cin>>rb;
	
	if(B>0)	
		rb+=(nb*pb) , price+=(B*pb);
	if(S>0)
		rb+=(ns*ps) , price+=(S*ps);
	if(C>0)	
		rb+=(nc*pc) , price+=(C*pc);
//	cout<<rb<<" "<<price<<endl;
	l=0,r=1e18;
	
//	while(l+1<r)
//	{
//		mid=(l+r)/2;
//		if(good(mid))
//			l=mid;
//		else
//			r=mid;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
//	}
	cout<<rb/price;	
	return 0;
}

