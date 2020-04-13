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
    for(ll cse =1;cse<=t;cse++)
    {
       ll n;
       cin>>n;
       vector<pair<pll,ll> >v(n);
        rep(i,0,n)
        {
            ll si,ei;
            cin>>si>>ei;
            // cin>>si>>ei;
            v[i]=make_pair(make_pair(si,ei),i);
        }
        sort(v.begin(),v.end());
        ll c=0,j=0;
        vector<char>ans(n);
        ll flag=0;
        for(auto it : v)
        {
            // cout<<it.first.first<<" "<<it.first.second<<" , "<<it.second<<" ";
            if(it.first.first>=c)
            {
                ans[it.second]='C';
                c=it.first.second;
            }
            else if(it.first.first>=j)
            {
                ans[it.second]='J';
                j=it.first.second;
            }
            else 
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"Case #"<<cse<<": IMPOSSIBLE"<<endl;
            continue;
        }
        cout<<"Case #"<<cse<<": ";
        rep(i,0,n)
        cout<<ans[i];
        cout<<endl;

    }

}