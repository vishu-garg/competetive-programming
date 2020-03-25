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
    ll n,p;
    cin>>n>>p;
    string s;
    cin>>s;
    ll mid=(n+1)/2;
    ll a[n];
    ll sum=0;
    ll mn=-1,mx=-1;
    for(ll i=1;i<=mid;i++)
    {
        if(int(s[i-1])!=int(s[n-i]))
        {   
            ll dif=fabs(int(s[i-1])-int(s[n-i]));
            a[i-1]=a[n-i]=min(dif,26-dif);
            sum+=a[i-1];
            if(a[i-1]!=0)
            {
                if(mn==-1)
                mn=i;
                mx=i;
            }
        }
    }
    if(sum==0)
    return cout<<"0",0;
    if(p>mid)
    p=(n-p+1);
    ll dis;
    // cout<<p;
    if(p>=mx)
    {
        dis=p-mn;
    }
    else if(p<=mn)
    {
        dis=mx-p;
    }
    else 
    dis=(2*(min(mx-p,p-mn)))+max(mx-p,p-mn);
    sum+=dis;
    cout<<sum;
}
