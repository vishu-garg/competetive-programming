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
const ll M = 998244353;
const ll INF = 1e12;
#define PI 3.14159265

ll pow1(ll a,ll b){
    ll res=1;
    a=(a%M);
    while(b>0){
        if(b&1){
        	res=(res*a)%M;
		}
        a=(a*a)%M;
        b>>=1;
    }
    res%=M;
    return res;
}

stack<char> opt;
stack<ll> s0,s1,sa,sA;

void calc()
{
    char sign=opt.top();opt.pop();
    ll ft0=s0.top();s0.pop();
    ll sd0=s0.top();s0.pop();

    ll ft1=s1.top();s1.pop();
    ll sd1=s1.top();s1.pop();

    ll fta=sa.top();sa.pop();
    ll sda=sa.top();sa.pop();

    ll ftA=sA.top();sA.pop();
    ll sdA=sA.top();sA.pop();

    ll ans0=0,ans1=0,ansa=0,ansA=0;

    if(sign=='&')
    {
        ll tmp=(ft0*sd0)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ft0*sd1)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ft0*sda)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ft0*sdA)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ft1*sd0)%M;
        ans0=(ans0+tmp)%M;
        tmp=(fta*sd0)%M;
        ans0=(ans0+tmp)%M;
        tmp=(fta*sdA)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ftA*sd0)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ftA*sda)%M;
        ans0=(ans0+tmp)%M;

        tmp=(ft1*sd1)%M;
        ans1=(ans1+tmp)%M;

        tmp=(ft1*sda)%M;
        ansa=(ansa+tmp)%M;
        tmp=(fta*sd1)%M;
        ansa=(ansa+tmp)%M;
        tmp=(fta*sda)%M;
        ansa=(ansa+tmp)%M;

        tmp=(ft1*sdA)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ftA*sd1)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ftA*sdA)%M;
        ansA=(ansA+tmp)%M;
    }

    else if(sign=='^')
    {
        ll tmp=(ft0*sd0)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ft1*sd1)%M;
        ans0=(ans0+tmp)%M;
        tmp=(fta*sda)%M;
        ans0=(ans0+tmp)%M;
        tmp=(ftA*sdA)%M;
        ans0=(ans0+tmp)%M;

        tmp=(ft0*sd1)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ft1*sd0)%M;
        ans1=(ans1+tmp)%M;
        tmp=(fta*sdA)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ftA*sda)%M;
        ans1=(ans1+tmp)%M;

        tmp=(ft0*sda)%M;
        ansa=(ansa+tmp)%M;
        tmp=(ft1*sdA)%M;
        ansa=(ansa+tmp)%M;
        tmp=(fta*sd0)%M;
        ansa=(ansa+tmp)%M;
        tmp=(ftA*sd1)%M;
        ansa=(ansa+tmp)%M;

        tmp=(ft0*sdA)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ft1*sda)%M;
        ansA=(ansA+tmp)%M;
        tmp=(fta*sd1)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ftA*sd0)%M;
        ansA=(ansA+tmp)%M;
    }

    else if(sign=='|')
    {
        ll tmp=(ft0*sd0)%M;
        ans0=(ans0+tmp)%M;
        
        tmp=(ft0*sd1)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ft1*sd0)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ft1*sd1)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ft1*sda)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ft1*sdA)%M;
        ans1=(ans1+tmp)%M;
        tmp=(fta*sd1)%M;
        ans1=(ans1+tmp)%M;
        tmp=(fta*sdA)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ftA*sd1)%M;
        ans1=(ans1+tmp)%M;
        tmp=(ftA*sda)%M;
        ans1=(ans1+tmp)%M;

        tmp=(ft0*sda)%M;
        ansa=(ansa+tmp)%M;
        tmp=(fta*sd0)%M;
        ansa=(ansa+tmp)%M;
        tmp=(fta*sda)%M;
        ansa=(ansa+tmp)%M;

        tmp=(ft0*sdA)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ftA*sd0)%M;
        ansA=(ansA+tmp)%M;
        tmp=(ftA*sdA)%M;
        ansA=(ansA+tmp)%M;
    }

    s0.push(ans0);
    s1.push(ans1);
    sa.push(ansa);
    sA.push(ansA);
}

int main()
{
    ll t=1;
   cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll num=(pow1(4LL,M-2))%M;
        rep(i,0,s.length())
        {
        	if(s[i]=='#')
        	{
                s0.push(num);
                s1.push(num);
                sa.push(num);
                sA.push(num);
            }
            else if(s[i]=='^' || s[i]=='|' || s[i]=='&')
                opt.push(s[i]);
            else if(s[i]==')')
            {
                calc();
            }
        }
        cout<<s0.top()<<" "<<s1.top()<<" "<<sa.top()<<" "<<sA.top()<<endl;
        s0.pop();s1.pop();sa.pop();sA.pop();
    }

}