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
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        rep(i,0,n-1)
        {
            if(s[i]=='R' && s[i+1]=='L')
            s[i+1]='R';
            else if(s[i]=='L' && s[i+1]=='R')
            s[i+1]='L';
            else if(s[i]=='U' && s[i+1]=='D')
            s[i+1]='U';
            else if(s[i]=='D' && s[i+1]=='U')
            s[i+1]='D';
        }
        string s2="";s2+=s[0];
        rep(i,1,n)
        {
            if(s[i]==s[i-1])
            continue;
            else 
            s2+=s[i];
        }
        cout<<s2<<endl;
        int x=0,y=0;
        rep(i,0,s2.length())
        {
            if(s2[i]=='R')x++;
            else if(s2[i]=='L')x--;
            else if(s2[i]=='U')y++;
            else if(s2[i]=='D')y--;
        }
        cout<<x<<" "<<y<<endl;
    }
}