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
        ll n,p;
        cin>>n>>p;
        ll d[n];
        rep(i,0,n)
        {
            cin>>d[i];
        }
        ll ans=0;
        ll a[n];
        rep(i,0,n)
        {
            if(p%d[i]==0 || ans==1)
            a[i]=0;
            else 
            {
                ll tmp=(p/d[i]);
                tmp+=1;
                a[i]=tmp;
                ans=1;
            }
        }
        if(ans==0)
        {
            ll f,s,flg=0;
            rep(i,0,n)
            {
                rep(j,i,n)
                {
                    if(d[j]%d[i]!=0)
                    {
                        f=i;
                        s=j;
                        flg=1;
                        break;
                    }
                }
                if(flg==1)
                break;
            }
            if(flg==0)
            {cout<<"NO"<<endl;
            }
            else{
            a[s]=(p/d[s])-1;
            a[f]=((p-(a[s]*d[s]))/d[f])+1;
            cout<<"YES ";
            rep(i,0,n)
            cout<<a[i]<<" ";
            cout<<endl;}
        }
        else 
        {
            cout<<"YES ";
            rep(i,0,n)
            cout<<a[i]<<" ";
            cout<<endl;
        }
    }
}