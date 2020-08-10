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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int pow1(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
        	res=res*a;
		}
        a=a*a;
        b>>=1;
    }
    return res;
}

void fctr(ll n , vector<ll>&v)
{
	rep(i,2,sqrt(n)+1)
	{
		if(n%i==0)
		{
			v.pb(i);
			if(i*i!=n)
			v.pb(n/i);
		}
	}
}

int main()
{
    fast;
    

    ll t=1;
    cin>>t;
    while(t--)
    {
    
	ll n;
   	cin>>n;

	ll a[n];
	rep(i,0,n)
	cin>>a[i];

	ll ans[n];
	ans[0]=1;
	vector<ll>v;
	rep(i,1,n)
	{
		ans[i]=1;
		v.pb(1);
		fctr(i+1,v);
		for(auto it:v)
		{
			if(a[it-1]<a[i])
			ans[i]=max(ans[i],ans[it-1]+1);
		}
		v.clear();
	}
	ll mx=1;
   	rep(i,0,n)
	mx=max(mx,ans[i]);
	cout<<mx<<endl;
    }

}