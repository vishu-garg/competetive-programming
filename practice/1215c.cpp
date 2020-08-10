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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
    fast;
    ll T=1;
//     cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        string s,t;
        cin>>s;
        cin>>t;
        vector<ll>a;
        string s1="",s2="";
        rep(i,0,n)
        {
            if(s[i]!=t[i])
            {
                s1+=s[i];
                s2+=t[i];
                a.pb(i);
            }
        }
        if(a.size()==0)
        {
            cout<<"0";
            return 0;
        }
        s=s1;
        t=s2;
        if(s.size()%2!=0)
        {
            cout<<"-1";
            return 0;
        }
        ll ans=0;
        map<string,vector<ll> >mp;
        rep(i,0,s2.size())
        {
            if(s[i]=='a' && t[i]=='b')
            mp["ab"].pb(i);
            else 
            mp["ba"].pb(i);
        }
        if(mp["ab"].size()%2==0)
        {
            cout<<s2.size()/2<<endl;
            for(ll i=0;i<mp["ab"].size();i+=2)
            {
                cout<<a[mp["ab"][i]]+1<<" "<<a[mp["ab"][i+1]]+1<<endl;
            }
            for(ll i=0;i<mp["ba"].size();i+=2)
            {
                cout<<a[mp["ba"][i]]+1<<" "<<a[mp["ba"][i+1]]+1<<endl;
            }
        }
        else 
        {
            cout<<s2.size()/2+1<<endl;
            for(ll i=1;i<mp["ab"].size();i+=2)
            {
                cout<<a[mp["ab"][i]]+1<<" "<<a[mp["ab"][i+1]]+1<<endl;
            }
            for(ll i=1;i<mp["ba"].size();i+=2)
            {
                cout<<a[mp["ba"][i]]+1<<" "<<a[mp["ba"][i+1]]+1<<endl;
            }
            cout<<a[mp["ab"][0]]+1<<" "<<a[mp["ab"][0]]+1<<endl;
            cout<<a[mp["ab"][0]]+1<<" "<<a[mp["ba"][0]]+1<<endl;
        }
    }

}