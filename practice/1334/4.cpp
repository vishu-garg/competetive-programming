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
ll n,l,r;
V ans;

void func(ll lf, ll rg , ll id)
{
    if(lf==rg)
    return;
    // cout<<min(id+2*(rg-lf),r)<<" "<<max(l,id);
    if(min(id+2*(rg-lf),r)>max(l,id))
    {
        // cout<<"HERE "<<lf+1<<" "<<rg+1<<endl;
        rep(i,lf+1,rg+1)
        {
            // cout<<id<<" "<<l<<" "<<r<<" <---"<<endl;
            if(l<=id && id<r)
            ans.pb(lf);
            id++;
            if(l<=id && id<r)
            ans.pb(i);
            id++;
        }
    }
    else
        id+=2*(rg-lf);
    
    func(lf+1,rg,id);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
   cin>>t;
    while(t--)
    {
    //    ll n,l,r;
       cin>>n>>l>>r;
       l--;
       func(0,n-1,0);
      if(r==n*(n-1)+1)
      ans.pb(0);
       for(auto it : ans)
       cout<<it+1<<" ";
       cout<<endl;
       ans.clear();
    }
}  