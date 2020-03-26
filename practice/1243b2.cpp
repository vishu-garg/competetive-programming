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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        map<char,ll> mp;
        rep(i,0,n)
        {
            mp[s[i]]++;
            mp[t[i]]++;
        }
        ll f=1;
        for(auto it : mp)
        {
            if(it.sd%2!=0)
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            cout<<"No"<<endl;
            continue;
        }
        ll ans=0;
        vector<pair<ll,ll>> v;
        rep(i,0,n)
        {
            // cout<<s<<" "<<t<<endl;
            if(s[i]==t[i])continue;
            rep(j,i+1,n)
            {
                if(s[i]==s[j])
                {
                    ans++;
                    v.pb({j,i});
                    char tmp=s[j];
                    s[j]=t[i];
                    t[i]=tmp;
                    break;
                }
                else if(s[i]==t[j])
                {
                    ans+=2;
                    v.pb({j,j});
                    char tmp=s[j];
                    s[j]=t[j];
                    t[j]=tmp;
                    v.pb({j,i});
                    tmp=s[j];
                    s[j]=t[i];
                    t[i]=tmp;
                    break;
                }
            }
        }
        cout<<"Yes"<<endl;
        cout<<ans<<endl;
        for(auto it : v)
        {
            cout<<it.ft+1<<" "<<it.sd+1<<endl;
        }
    }
}