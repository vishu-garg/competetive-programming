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
    cin>>T;
    while(T--)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll> ans(n+1);
        ll total=0;
        rep(i,0,n)
        if(s[i]=='1')total++;
        if(total==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        ll mn_ans=LLONG_MAX;
        rep(i,1,k+1)
        {
            if(s[i-1]=='1')
            ans[i]=total-1;
            else 
            ans[i]=total+1;
            mn_ans=min(ans[i],mn_ans);
        }
        rep(i,k+1,n+1)
        {
            char ch=s[i-1];
            if(ch=='1')
            ans[i]=total-1;
            else 
            ans[i]=total+1;
            ll prev;
            if(ch=='1')
            {
                prev=ans[i-k]-1;
            }
            else 
            {
                prev=ans[i-k]+1;
            }
            ans[i]=min(ans[i],prev);
            mn_ans=min(ans[i],mn_ans);
        }
        cout<<mn_ans<<endl;
    }

}