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

int main()
{
    ll t=1;
    cin>>t;
    ld total=0;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<pll> v(n);
        ll maxx=LLONG_MAX,minx=-LLONG_MAX;
        ll maxy=LLONG_MAX,miny=-LLONG_MAX;
        rep(i,0,n)
        {
            ll x,y;
            cin>>x>>y;
            v[i]={x,y};
            maxx=max(x,maxx);
            maxy=max(y,maxy);
            minx=min(x,minx);
            miny=min(y,miny);
        }  

        ld ans=0;

        ld ar1=1;
        pll p1,p2,p3;
        p1={minx,maxy};
        p2={minx,miny};
        p3={maxx,maxy};
        rep(i,0,n)
        {
            if(v[i].first==minx)
            p2.second=max(p2.second,v[i].second);
            if(v[i].second==maxy)
            p3.first=min(p2.first,v[i].first);
        }
        ll h=p1.second-p2.second;
        ll b=p3.first-p1.first;
        ar1=(b*h);
        ar1/=2;
        ans+=ar1;

        ld ar2=1;
        // p1,p2,p3;
        p1={minx,miny};
        p2={minx,maxy};
        p3={maxx,miny};
        rep(i,0,n)
        {
            if(v[i].first==minx)
            p2.second=min(p2.second,v[i].second);
            if(v[i].second==miny)
            p3.first=min(p2.first,v[i].first);
        }
        h=p2.second-p1.second;
        b=p3.first-p1.first;
        ar2=(b*h);
        ar2/=2;
        ans+=ar2;

        ld ar3=1;
        // p1,p2,p3;
        p1={maxx,miny};
        p2={maxx,maxy};
        p3={minx,miny};
        rep(i,0,n)
        {
            if(v[i].first==maxx)
            p2.second=min(p2.second,v[i].second);
            if(v[i].second==miny)
            p3.first=max(p2.first,v[i].first);
        }
        h=p2.second-p1.second;
        b=p1.first-p3.first;
        ar3=(b*h);
        ar3/=2;
        ans+=ar3;


        ld ar4=1;
        // p1,p2,p3;
        p1={maxx,maxy};
        p2={maxx,miny};
        p3={minx,maxy};
        rep(i,0,n)
        {
            if(v[i].first==maxx)
            p2.second=min(p2.second,v[i].second);
            if(v[i].second==maxy)
            p3.first=max(p2.first,v[i].first);
        }
        h=p1.second-p2.second;
        b=p1.first-p3.first;
        ar3=(b*h);
        ar3/=2;
        ans+=ar3;

        ld tot2=(maxx-minx)*(maxy-miny);
         
        tot2-=ans;
        total+=tot2;
    }

    cout<<floor(total);

}