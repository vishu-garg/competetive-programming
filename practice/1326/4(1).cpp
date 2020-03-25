//https://codeforces.com/contest/1326/problem/B
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

void solve()
{
    string s;cin>>s;
    string a="",b="";
    bool f=true;
    if(s.length()==1)
    {
        cout<<s<<endl;return;
    }
    while(f)
    {
        if(s[0]==s[s.length()-1] && s.length()>1)
        {
            a+=s[0];
            b+=s[s.length()-1];
            ll k=s.length()-2;
            s=s.substr(1,s.length()-2);
        }
        else if(s.length()==1)
        {a+=s[0];s.clear();}
        else 
        {
            f=false;
        }
    }
    f=true;
    if(s.length()>0)
    {
        string s4=s+'#';
        reverse(s.begin(),s.end());
        s4+=s;
        ll n=s4.length();
        ll pi[n];pi[0]=0;
        rep(i,1,n)
        {
            ll j=pi[i-1];
            while(j>0 && s4[j]!=s4[i])
            j=p[j-1];
            if(s4[j]==s4[i])j++;
            pi[i]=j;
        }
        string pref=s4.substr(pi[n-1]);
        s4.clear();
        s4=s+'#';
        reverse(s.begin(),s.end());
        s4+=s;
        pi[0]=0;
        rep(i,1,n)
        {
            ll j=pi[i-1];
            while(j>0 && s4[j]!=s4[i])
            j=pi[j-1];
            if(s4[j]==s4[i])j++;
            pi[i]=j;
        }
        string suff=s4.substr(pi[n-1]);
        if(pref.length()>=suff.length())
        a+=pref;
        else 
        b=b+suff;
    }
    reverse(b.begin(),b.end());
    cout<<a+b<<endl;
    return;
}

int main()
{
    ll t;cin>>t;
    while(t--)
    {
        solve();
    }
}