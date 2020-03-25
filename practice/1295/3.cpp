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
    cin>>T;
    while(t--)
    {
        string s,t;cin>>s>>t;
        ll n=s.length();ll m=t.length();
        ll A[26]={0};
        rep(i,0,n)A[s[i]-'a']++;
        ll B[26]={0};
        rep(i,0,m)B[s[i]-'a']++;
        ll fnd=0;
        rep(i,0,26)
        {
            if(B[i]!=0 && A[i]==0)
            {
                fnd=1;break;
            }
        }
        if(fnd)
        {
            cout<<"-1"<<endl;continue;
        }
        ll pos[n+1][26];
        rep(i,0,26)
        pos[n][i]=-1;
        rep(i,0,n)
        {
            rep(j,0,26)
            {
                pos[i][j]=pos[i+1][j];
            }
            pos[i][s[i]-'a']=i;
        }
        ll cur=0;
        ll ans=1;
        rep(i,0,m)
        {
            ll is_there=pos[cur][t[i]-'a'];
            if(is_there==-1)
            {
                cur=0;
                ans++;
            }
            else 
            cur=is_there+1;
        }
        cout<<ans<<endl;
    }
}