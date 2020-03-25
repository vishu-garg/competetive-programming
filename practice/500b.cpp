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
set<ll> s[300],ind[300];
ll n,a[300],mat[300][300];
bool calc[300];
void func(ll i)
{
    calc[i]=true;
    s[i].insert(a[i]);
    ind[i].insert(i);
    rep(j,0,n)
    mat[j][i]=0;
    
    rep(j,0,n)
    {
        if(mat[i][j]==1)
        {
            mat[j][i]=0;
            func(j);
            for(auto it:s[j])
            s[i].insert(it);
            for(auto i2 : ind[j])
            ind[i].insert(i2);
        }
    }
}

int main()
{
    // ll n;
    cin>>n;
    // ll a[n];
    rep(i,0,n)cin>>a[i];
    // ll mat[n][n];
    char x;
    ll cpy[n][n];
    rep(i,0,n)
	rep(j,0,n){
        cin>>x;
        mat[i][j]=x-'0';
        cpy[i][j]=mat[i][j];
    }
    // cout<<"-------------------"<<endl;
//    rep(i,0,n)
//    {rep(j,0,n)
//    cout<<mat[i][j]<<" ";cout<<endl;}
    // set<ll> s[n];
    rep(i,0,n)
    if(!calc[i])
    func(i);
    // rep(k,0,300)
    // {
    //     if(s[k].size()>0){
    //     for(auto it : s[k])
    //     cout<<it<<" ";
    //     cout<<endl;}
    // }
    vector<ll> ans(n,-1);
    rep(k,0,n)
    {
        if(ans[k]==-1){
        for(auto it : ind[k])
        {
            ans[it]=*(s[k].begin());
            s[k].erase(ans[it]);

        }
        }
    }
    rep(i,0,n)
    cout<<ans[i]<<" ";
}