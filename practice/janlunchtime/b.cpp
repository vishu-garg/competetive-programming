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
        ll n,a,b,c,ans=0;
        cin>>n>>a>>b>>c;
        if(a<b)
        {
            a=a+b;b=a-b;a=a-b;
        }
        // cout<<"a= "<<a<<" b="<<b<<endl;
        ll alc=INF,bob=(-1*INF);
        rep(i,0,n)
        {
            ll f;
            cin>>f;
            if(b<=f && f<=a && ans==0)
            {
                ans=1;
                cout<<a-b+c<<endl;
                // break;
            }
            else if(f>a && ans==0)
            alc=min(alc,f);
            else if(f<b && ans==0)
            bob=max(bob,f);
        }
        // cout<<alc<<" "<<bob<<endl;
        if(ans==0)
        {
            
            ll a1=bob;
            ll ans1;
            ans1=(a-a1+b-a1)+c;
            ll a2=alc;
            ll ans2=((a2-a+a2-b))+c;
            ans=min(ans1,ans2);
            cout<<ans<<endl;
        }


    }
}