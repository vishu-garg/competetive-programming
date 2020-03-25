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
    ll w,h,r;
    cin>>w>>h>>r;
   vector<pair<ll,ll> > rsn(r);
   rep(i,0,r)
   {
       ll x,y;
       cin>>x>>y;
       rsn[i]=make_pair(x,y);
   }
    vector<ll> fact_w;
    rep(i,2,sqrt(w)+1)
    {
        if(w%i==0)
        {
            if(i*i==w)
            {
                fact_w.pb(i);
                continue;
            }
            fact_w.pb(i);
            fact_w.pb(w/i);
        }
    }
    ll n,m,flag=0,a1=1024*1024;
    sort(fact_w.begin(),fact_w.end());
    rep(i,0,fact_w.size())
    {
        rep(j,2,sqrt(h)+1)
        {
        	if(h%j==0){
            ll n1=w/fact_w[i];
            ll n2=h/j;
            if((n1*n2)<a1)
            {n=n1;m=n2;
            flag=1;
            break;
            }
        }
        }
        if(flag==1)
        break;
    }
    if(flag==0)
    {
        rep(i,0,fact_w.size())
        {
            repb(j,sqrt(h),2)
            {
                if(h%j==0)
                {
                    ll n1=w/fact_w[i];
                    ll n2=j;
                    if((n1*n2)<a1)
                    {
                        n=n1;m=n2;
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
    }
    // cout<<n<<" "<<m<<endl;
    sort(rsn.begin(),rsn.end());
}