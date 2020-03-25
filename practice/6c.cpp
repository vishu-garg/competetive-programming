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
    ll n;cin>>n;
    ll time_slot[n];
    rep(i,0,n)cin>>time_slot[i];
    ll alice_time[n],bob_time[n];
    alice_time[0]=time_slot[0];
    rep(i,1,n)
    alice_time[i]=time_slot[i]+alice_time[i-1];
    bob_time[n-1]=time_slot[n-1];
    repb(i,n-2,0)
    bob_time[i]=time_slot[i]+bob_time[i+1];
    ll bob=n-1,alice=0;
    ll toffee=n;
    ll  ans_a=0,ans_b=0;
    // rep(i,0,n)
    // cout<<"ALICE : "<<alice_time[i]<<" BOB : "<<bob_time[i]<<endl;
    while(toffee>0)
    {
        // cout<<toffee<<endl;
        if(bob_time[bob]<alice_time[alice] && bob>=alice)
        {
            bob--;
            toffee--;
            ans_b++;
        }
        if(bob_time[bob]>alice_time[alice] && bob>=alice)
        {
            alice++;
            toffee--;
            ans_a++;
        }
        if(bob_time[bob]==alice_time[alice] && bob>=alice)
        {
            if(bob!=alice)
            {alice++;
            ans_b++;ans_a++;
            bob--;
            toffee-=2;}
            else 
            {
                ans_a++;
                alice++;
                toffee--;
            }
        }
    }
    cout<<ans_a<<" "<<ans_b;
}