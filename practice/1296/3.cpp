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
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll h=0,v=0;
        set<pair<pair<ll,ll>,ll > >s2; 
        s2.insert({{0,0},-1});
        rep(i,0,n)
        {
            if(s[i]=='R')
            h++;
            else if(s[i]=='L')
            h--;
            else if(s[i]=='U')
            v++;
            else 
            v--;
            s2.insert({{h,v},i});
        }
        auto it=s2.begin();
        auto it2=it;
        it++;
        ll al=-1,ar=-1;
        multiset<pair<ll,pll> > s3;
        while(it!=s2.end())
        {
            pair<pll,ll> p11=*it2,p12=*it;
            pll p1=p11.first,p2=p12.first;
            if(p1.first==p2.first && p1.second==p2.second)
            {
                al=p11.second;
                ar=p12.second;
                s3.insert({ar-al+1,{al+2,ar+1}});
            }
            it++;it2++;
        }
        if(s3.size()==0)
        cout<<"-1"<<endl;
        else
        {
            auto it3=*s3.begin();
            cout<<it3.second.first<<" "<<it3.second.second<<endl;
        }
    }
}