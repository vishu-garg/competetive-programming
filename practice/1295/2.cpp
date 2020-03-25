#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
#define err() cout<<"=================================="<<endl;
#define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
#define err1(a) cout<<#a<<" "<<a<<endl
#define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
#define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
#define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
#define pb push_back
#define all(A)  A.begin(),A.end()
#define allr(A)    A.rbegin(),A.rend()
#define ft first
#define sd second
 
#define pll pair<ll,ll>
#define V vector<ll>
#define S set<ll>
#define VV vector<V>
#define Vpll vector<pll>
 
#define endl "\n"
 
const ll logN = 20;
const ll M = 1000000007;
const ll INF = 1e12;
#define PI 3.14159265

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        ll cnt0=0,cnt1=0;
        ll ans[n];
        ll tot=0;
        rep(i,0,n)
        {
            if(s[i]=='1')cnt1++;
            else cnt0++;
            ans[i]=(cnt0-cnt1);
        }
        if(x==0 && ans[n-1]==0)
        {cout<<"-1"<<endl;continue;}
        ll bal=ans[n-1];
        rep(i,0,n)
        ans[i]=(x-ans[i]);
        if(bal==0)
        {
        	ll fnd=0;
			rep(i,0,n)
			if(ans[i]==0)
			{
			fnd=1;break;}
			if(fnd==1)
			cout<<"-1"<<endl;
			else 
			cout<<"0"<<endl;
			continue;
		}
        rep(i,0,n)
        {
			if(ans[i]%bal==0)
        	{
        		ll k=(ans[i]/bal);
        		if(k>=0)
        		tot++;
			}
		}
		if(x==0 && tot==0)
		tot++;
		cout<<tot<<endl;
	}
}