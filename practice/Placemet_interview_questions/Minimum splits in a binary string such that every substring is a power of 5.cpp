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

bool power_of_5(ll val)
{
    while(val>1)
    {
        if(val%5!=0)
        return false;
        val/=5;
    }
    return true;

}

int main()
{
    ll t=1;
   cin>>t;
    while(t--)
    {
        string  s;
        cin>>s;
        ll n=s.length();
        ll dp[n];
        repb(i,n-1,0)
        {
            if(s[i]-'0'==0)
            {dp[i]=-1;
            continue;}
            dp[i]=LLONG_MAX;
            ll val=0;
            rep(j,i,n)
            {
                val=(2*val)+(s[j]-'0');
                if(power_of_5(val))
                {
//                	if(i==0)
//                	{cout<<val<<" ### "<<j<<" <---"<<endl;
//                	if(j!=n-1)
//                	cout<<dp[i]<<" "<<dp[j+1]<<" <---"<<endl;}
                    if(j==n-1)
                    dp[i]=1;
                    else if(dp[j+1]!=-1)
                    dp[i]=min(dp[i],dp[j+1]+1);
                }
            }
            if(dp[i]==LLONG_MAX)
            dp[i]=-1;
        }
//        rep(i,0,n)
//        cout<<dp[i]<<" ";
//        cout<<endl;
        cout<<dp[0]<<endl;
    }

}