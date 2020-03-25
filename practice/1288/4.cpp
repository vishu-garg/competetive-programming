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
ll n,m,a1,a2;
vector<vector<ll> > a;

bool can(ll mid)
{
    vector<ll> msk(1<<m,-1);
    rep(i,0,n){
        ll cur=0;
        rep(j,0,m)
        {
            if(a[i][j]>=mid)
            cur+=(1<<j);
        }
        msk[cur]=i;
    }

    if(msk[(1<<m)-1]!=-1)
    {
        a1=msk[(1<<m)-1];
        a2=msk[(1<<m)-1];
        return true;
    }
    rep(i,0,(1<<m))
    {
        rep(j,0,(1<<m))
        {
            if(msk[i]!=-1 && msk[j]!=-1 && ((i|j)==((1<<m)-1)))
            {
                a1=msk[i];
                a2=msk[j];
                return true;
            }
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    a.resize(n,vector<ll> (m));
    rep(i,0,n) rep(j,0,m) cin>>a[i][j];
    ll lf=0,rg=1e9+100;
    while(lf<=rg)
    {
        ll m=(lf+rg)/2;
        if(can(m))
        lf=m+1;
        else 
        rg=m-1;
        // cout<<m<<endl;
    }
    // cout<<lf-1<<endl;
    cout<<a1+1<<" "<<a2+1;
}