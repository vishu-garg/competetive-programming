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
//     cin>>t;
    while(t--)
    {
        vector<ll> v;
        v.pb(4);v.pb(8);v.pb(15);v.pb(16);v.pb(23);v.pb(42);
        ll ans[6];
        ll x;
        cout<<"? 1 2"<<endl;
        cin>>x;
        pair<ll,ll> p;
        rep(i,0,v.size())
        {
            ll fnd=0;
            rep(j,i+1,v.size())
            {
                if(v[i]*v[j]==x)
                {
                    p=make_pair(v[i],v[j]);
                    fnd=1;
                    break;
                }
            }
            if(fnd==1)
            break;
        }
        cout<<"? 1 1"<<endl;
        cin>>x;
        ans[0]=sqrt(x);
        if(p.first==ans[0])
        ans[1]=p.second;
        else 
        ans[1]=p.first;
        v.erase(find(all(v),ans[0]));
        v.erase(find(all(v),ans[1]));
        cout<<"? 3 4"<<endl;
        cin>>x;
        rep(i,0,v.size())
        {
            ll fnd=0;
            rep(j,i+1,v.size())
            {
                if(v[i]*v[j]==x)
                {
                    p=make_pair(v[i],v[j]);
                    fnd=1;
                    break;
                }
            }
            if(fnd==1)
            break;
        }
        pair<ll,ll> p2;
        cout<<"? 4 5"<<endl;
        cin>>x;
        if(x%p.first==0)
        {
            if(find(all(v),x/p.first)!=v.end())
            {
                ans[2]=p.second;
                ans[3]=p.first;
                ans[4]=x/p.first;
                v.erase(find(all(v),ans[2]));
                v.erase(find(all(v),ans[3]));
                v.erase(find(all(v),ans[4]));
                ans[5]=v[0];
            }
        }
        else 
        {
            ans[2]=p.first;
            ans[3]=p.second;
            ans[4]=x/p.second;
            v.erase(find(all(v),ans[2]));
            v.erase(find(all(v),ans[3]));
            v.erase(find(all(v),ans[4]));
            ans[5]=v[0];
        }
        cout<<"! ";
        rep(i,0,6)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}