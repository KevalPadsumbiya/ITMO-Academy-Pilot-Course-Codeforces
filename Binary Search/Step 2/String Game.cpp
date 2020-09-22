#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

string t,p;
vector<int> a;

bool good(int n)
{
	string s="",temp=t;
	int i,j;
	
	for(i=0;i<n;i++)
		temp[a[i]-1]='0';
	for(i=0;i<temp.length();i++)
		if(temp[i]!='0')
			s+=temp[i];
	
	// check whether p is present in t as a substring
	i=j=0;
	while(i<s.length() && j<p.length())
	{
		if(s[i]==p[j])
			j++;
		i++;
	}
	
	return j==p.length();
}

int main()
{
	fastio;
	
	cin>>t>>p;
	
	int l,i,r,mid;
	a.resize(t.length());
	
	for(i=0;i<t.length();i++)
		cin>>a[i];
	
	l=0,r=t.length()-p.length()+1;
	
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

