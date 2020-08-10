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

ll find_ans(string &s , string &s2,ll k)
{
    ll n=s.length();
    vector<ll> pref_sum(n,0);
    rep(i,0,n)
    {
        if(s[i]==s2[i])
        continue;
        else 
        pref_sum[i]=1;
    }
    rep(i,1,n)pref_sum[i]+=pref_sum[i-1];
    // rep(i,0,n)cout<<pref_sum[i]<<" , ";
    // cout<<endl;
    ll cst=pref_sum[k-1];
    rep(i,k,n)
    {
        ll tmp=pref_sum[i]-pref_sum[i-k];
        // cout<<tmp<<"<--"<<endl;
        cst=min(cst,tmp);
    }
    return cst;
}

int main()
{
    fast;
    ll T=1;
    cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        string s2="";
        rep(i,0,n)
        {
            if(i%3==0)
            s2+='R';
            else if(i%3==1)
            s2+='G';
            else 
            s2+='B';
            // cout<<s2<<"<---"<<endl;
        }
        // cout<<s2<<endl;
        ll ans=INF;
        ll tmp=find_ans(s,s2,k);
        ans=min(ans,tmp);
        rep(i,0,n)
        {
            if(i%3==0)
            s2[i]='G';
            else if(i%3==1)
            s2[i]='B';
            else 
            s2[i]='R';
        }
        tmp=find_ans(s,s2,k);
        ans=min(ans,tmp);
        rep(i,0,n)
        {
            if(i%3==0)
            s2[i]='B';
            else if(i%3==1)
            s2[i]='R';
            else 
            s2[i]='G';
        }
        tmp=find_ans(s,s2,k);
        ans=min(ans,tmp);
        cout<<ans<<endl;
    }

}