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
    ll N;
    cin>>N;
    ll A[N];
    ll arr[1e6];
    rep(i,0,N)cin>>A[i];
    sort(A,A+N);
    map<ll,ll> mp;
    rep(i,0,N)
    mp[A[i]]++;
    set<ll> st;
    map<ll,ll> mp2;
    rep(i,0,N)st.insert(A[i]);
    for(auto it=st.begin();it!=st.end();it++)
    {
        ll tmp=(ll)(pow(2,mp[*it]))-1;
        auto i2=st.begin();
        while(i2!=it && i2!=st.end())
        {
            tmp*=(ll)(pow(2,mp[*i2]));
            i2++;
        }
        // if(i2==it)
        mp2[*it]=tmp;
    }
    vector<ll> ans;
    for(auto it=st.begin();it!=st.end();it++)
    {
        auto nm=*it;
        ll sq=sqrt(nm);
        ll tmp=1;
        rep(i,1,sq+1)
        {
            if(nm%i==0)
            {
                if(nm=(i*i))
                tmp=(tmp*i)%M;
                else 
                {
                    tmp=(tmp*i)%M;
                    ll t2=nm/i;
                    tmp=(tmp*t2)%M;
                }
            }
        }
        rep(i,0,mp[*it])
        {
            ans.pb(tmp);
        }
    }
    sort(ans.begin(),ans.end());
    ll k;
    cin>>k;
    vector<ll> tbr,b(k);
    ll b[k];

    rep(i,0,k)
    {
        cin>>b[i];
        tbr.pb(ans[b[i]-1]);
    }
}