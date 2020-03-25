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
        ll n,k;
        cin>>n>>k;
        vector<ll> a,b(n);
        rep(i,0,n)cin>>b[i];
        rep(i,0,n)
        {
            if(b[i]!=0)
            a.pb(b[i]);
        }
        n=a.size();
        vector<ll>v[n];
        ll siz=0;
        rep(i,0,n)
        {
            while(a[i]!=0)
            {
                ll tmp=a[i]%k;
                v[i].pb(tmp);
                a[i]/=k;
            }
            siz=max(siz,(ll)v[i].size());
        }
        ll flag=0;
        map<ll,ll> mp;
        rep(i,0,n)
        {
            rep(j,0,v[i].size())
            {
                if(v[i][j]>1)
                {
                    flag=1;
                    break;
                }
                else if(v[i][j]==1)
                mp[j]++;
            }
            if(flag==1)
            break;
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        rep(i,0,siz)
        {
            if(mp[i]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        continue;
    }
}