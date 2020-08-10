//https://codeforces.com/contest/1138/problem/A
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
//     cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        map<pll,ll>mp;
        rep(i,0,n)
        {
            mp[{s1[i]-'0',s2[i]-'0'}]++;
        }

        ll na,nb,nc,nd;
        na=mp[{0,0}];nb=mp[{0,1}];nc=mp[{1,0}];nd=mp[{1,1}];
        ll a1=0,b1=0,c1=0,d1=0,flg=0;
        // cout<<na<<" "<<nb<<" "<<nc<<" "<<nd<<endl;
        rep(b,0,nb+1)
        {
            rep(c,0,nc+1)
            {
                ll d=((nb+nd)-(b+c));
                if(d%2!=0)
                continue;
                d/=2;
                ll a=(n/2-nb-nd)+d;
                if(a<=na && d<=nd && a>=0 && d>=0)
                {
                    flg=1;
                    a1=a;b1=b;c1=c;d1=d;
                    break;
                }
            }
            if(flg==1)
            break;
        }
        // cout<<a1<<" "<<b1<<" "<<c1<<" "<<d1<<endl;
        if(flg==1)
        {
            rep(i,0,n)
            {
                if(s1[i]=='0' && s2[i]=='0' && a1>0)
                {cout<<i+1<<" ";a1--;}
                else if(s1[i]=='0' && s2[i]=='1' && b1>0)
                {cout<<i+1<<" ";b1--;}
                else if(s1[i]=='1' && s2[i]=='0' && c1>0)
                {cout<<i+1<<" ";c1--;}
                else if(s1[i]=='1' && s2[i]=='1' && d1>0)
                {cout<<i+1<<" ";d1--;}
            }
        }
        else 
        cout<<"-1";
    }

}