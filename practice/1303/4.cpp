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
        ll n,m;
        cin>>n>>m;
        ll a[m];
        ll c[62]={0};
        ll sum=0;
        rep(i,0,m)
        {
            cin>>a[i];
            sum+=a[i];
            ll tmp=log2(a[i]);
            c[tmp]++;
        }
        if(sum<n)
        {cout<<"-1"<<endl;continue;}
        ll div=0,i=0;
        while(i<60)
        {
            if(((n>>i)&1)==1)
            {
                if(c[i]>0)
                c[i]-=1;
                else 
                {
                    while(i<60 && c[i]==0)
                    {i++;div++;}
                    c[i]-=1;
                    continue;
                }
            }
            c[i+1]+=(c[i]/2);
            i++;
        }
        cout<<div<<endl;
    }
}