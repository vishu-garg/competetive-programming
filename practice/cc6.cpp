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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    ll n,m;
    cin>>n>>m;
    unordered_map<ll,ll>  nx,px,ny,py;
    ll x0=0,y0=0;
    ll mx=0,my=0;
    rep(i,0,n)
    {
        ll tmp;cin>>tmp;
        if(tmp<0){
        tmp=abs(tmp);
        nx[tmp]++;}
        else if(tmp>0)
        px[tmp]++;
        else
        x0=1;
        mx=max(mx,abs(tmp));
    }

    rep(i,0,m)
    {
        ll tmp;cin>>tmp;
        if(tmp<0){
        tmp=abs(tmp);
        ny[tmp]++;}
        else if(tmp>0)
        py[tmp]++;
        else
        y0=1;
        my=max(my,abs(tmp));
    }
    ll ans=0;
	if(y0==1)
    ans+=((n)*(m-1));
    if(x0==1)
    ans+=((m)*(n-1));
    ll N=100000;
    ll k=sqrt(N)+1;
//    ll ans=0;
    rep(a,1,k)
    {
        rep(b,1,k)
        {
            if(__gcd(a,b)==1)
            {
                ll g=1;
                ll num=max(a,b)*max(a,b);
                while((num*g)<=mx && g*a*b<=my)
                {
                    ll x1=g*a*a;
                    ll x2=g*b*b;
                    ll y1=g*a*b;
//                    cout<<x1<<" "<<x2<<" "<<y1<<endl;
                    if(nx[x1]==1 && px[x2]==1 && py[y1]==1)
                    ans++;
                    if(nx[x1]==1 && px[x2]==1 && ny[y1]==1)
                    ans++;
//                    if(nx[x2]==1 && px[x1]==1 && py[y1]==1)
//                    ans++;
//                    if(nx[x2]==1 && px[x1]==1 && ny[y1]==1)
//                    ans++;
                    g++;
                }

            }
        }
    }
    // k=sqrt(m)+1;

    rep(a,1,k)
    {
        rep(b,1,k)
        {
            if(__gcd(a,b)==1)
            {
                ll g=1;
                ll num=max(a,b)*max(a,b);
                while((num*g)<=my && g*a*b<=mx)
                {
                    ll y1=g*a*a;
                    ll y2=g*b*b;
                    ll x1=g*a*b;
                    if(ny[y1]==1 && py[y2]==1 && px[x1]==1)
                    ans++;
//                    if(ny[y2]==1 && py[y1]==1 && px[x1]==1)
//                    ans++;
                    if(ny[y1]==1 && py[y2]==1 && nx[x1]==1)
                    ans++;
//                    if(ny[y2]==1 && py[y1]==1 && nx[x1]==1)
//                    ans++;
                    g++;
                }
            }
        }
    }
    cout<<ans<<endl;
    }
}


// NOTE: The question was giving time compleity when we used map instead of ordered map