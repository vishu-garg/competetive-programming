#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
 
#define ll long long
#define ld long double
 
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
 
 
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
        string s;
        cin>>s;
        ll f=0;
        string a1="1",a2="1";
        ll p1=0,p2=0;
        rep(i,1,n)
        {
            if(s[i]=='1')
            {
                if(f==0){
                a1+='1';
                a2+='0';f=1;}
                else 
                {
                    a1+='0';
                    a2+='1';
                }
            }
            else if(s[i]=='0')
            {a1+='0';a2+='0';}
            else 
            {
                if(f==0)
                {a1+='1';a2+='1';}
                else 
                {a1+='0';a2+='2';}
            }
        }
        cout<<a1<<endl;
        cout<<a2<<endl;
    }
}