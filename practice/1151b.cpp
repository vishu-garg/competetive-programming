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
        ll arr[n][m];
        vector<set<ll> > dis(n);
        rep(i,0,n)
        {
            rep(i,0,m)
            {
                cin>>arr[i][j];
                v[i].insert(arr[i][j]);
            }
        }
        ll cur_xor=0;
        rep(i,0,n)
        {
            cur_xor^=arr[i][0];
        }
        if(cur_xor!=0)
        {
            cout<<"TAK"<<endl;
            rep(i,0,n)cout<<"1 ";
            return 0;
        }
        if(cur_xor==0)
        {
            ll num=-1;
            rep(i,0,n)
            {
                if(v[i].size()>1)
                {
                    num=i;
                    break;
                }
            }
            if(num==-1)
            return cout<<"NIE",0;
            ll dis;
            rep(i,0,m)
            {
                if(arr[num][i]!=arr[num][0]){
                dis=i;
                break;}
            }
            cout<<"TAK"<<endl;
            rep(i,0,n)
            {
                if(i==num)
                cout<<dis+1;
                else 
                cout<<"1";
                cout<<" ";
            }
            return 0;
        }
    }
}