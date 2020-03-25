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

bool vis[200005];
V v[200005];
int main()
{
    int n;
    cin>>n;
    ll a[n];
    rep(i,1,n+1)cin>>a[i];
    ll k=-1;
    rep(i,1,n+1)
    {
        if(!vis[i])
        {
            ll cur=i;k++;
            while(!vis[cur])
            {
                vis[cur]=true;
                v[k].pb(cur);
                cur=(a[cur]);
            }
        }
    }
    ll ans=1;
    rep(i,0,k+1)
    {
        // cout<<ans<<" ******** "<<endl;
        ll fnd=-1;
        ll x=a[v[i][v[i].size()-1]];
        // cout<<x<<" ";
        rep(j,0,v[i].size())
        {
            if(x==v[i][j])
            {
                fnd=j;
                break;
            }
        }
        // cout<<fnd<<" ";
        if(fnd!=-1)
        {
            ll tmp=v[i].size()-fnd;
            // cout<<tmp<<" ";
            ll tmp2=fnd;
            ll ans1=1;
            rep(i,0,tmp)
            {
                ans1*=2;
                ans1%=M;
            }
            ans1-=2;
            ans*=ans1;
            // cout<<ans<<" #### \n";
            ans%=M;
            rep(i,0,tmp2)
            {
                ans*=2;
                ans%=M;
            }
            // cout<<ans<<" #### \n";
        }
        else 
        {
            // cout<<v[i].size()<<" $$$$ \n";
            rep(j,0,v[i].size())
            {
                ans*=2;
                // cout<<ans<<" "<<j<<" #### \n";
                ans%=M;
            }
        }
    }
    cout<<ans%M;
}