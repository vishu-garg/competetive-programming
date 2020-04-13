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
//    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        set<ll> st;
        char arr[n];
        ll n1=0,nd=0;
        vector<vector<ll> >v(k);
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i]=='L')
            {
                nd+=i;
                n1++;
                if(i>0 && arr[i-1]=='R')
                st.insert(i-1); 
            }
        }
        nd-=(n1*(n1-1))/2;
        if(nd<k)
        {
            cout<<"-1";
            return 0;
        }
        
        for(ll k1=0,s=k ; k1<k;k1++,s--)
        {
            ll nxt=0;
            while(nd>=s)
            {
                auto it = st.lower_bound(nxt);
                if(it==st.end())
                break;
                ll i=*it;
                st.erase(it);
                --nd;
                v[k1].pb(i+1);
                swap(arr[i],arr[i+1]);
                nxt=i+2;
                if(i>0 && arr[i-1]=='R')
                st.insert(i-1);
                if(i<n-2 && arr[i+2]=='L')
                st.insert(i+1);
            }
        }
        if(nd>0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        rep(i,0,k)
        {
            cout<<v[i].size();
            rep(j,0,v[i].size())
            cout<<" "<<v[i][j];
            cout<<endl;
        }
    }

}#include<bits/stdc++.h>
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
//    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        set<ll> st;
        char arr[n];
        ll n1=0,nd=0;
        vector<vector<ll> >v(k);
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i]=='L')
            {
                nd+=i;
                n1++;
                if(i>0 && arr[i-1]=='R')
                st.insert(i-1); 
            }
        }
        nd-=(n1*(n1-1))/2;
        if(nd<k)
        {
            cout<<"-1";
            return 0;
        }
        
        for(ll k1=0,s=k ; k1<k;k1++,s--)
        {
            ll nxt=0;
            while(nd>=s)
            {
                auto it = st.lower_bound(nxt);
                if(it==st.end())
                break;
                ll i=*it;
                st.erase(it);
                --nd;
                v[k1].pb(i+1);
                swap(arr[i],arr[i+1]);
                nxt=i+2;
                if(i>0 && arr[i-1]=='R')
                st.insert(i-1);
                if(i<n-2 && arr[i+2]=='L')
                st.insert(i+1);
            }
        }
        if(nd>0)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        rep(i,0,k)
        {
            cout<<v[i].size();
            rep(j,0,v[i].size())
            cout<<" "<<v[i][j];
            cout<<endl;
        }
    }

}