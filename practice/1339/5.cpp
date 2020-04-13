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
   cin>>t;
    while(t--)
    {
       ll n;
       cin>>n;
       ll x=0;
       while((ll)pow(4,x)<=n)
       x++;
       ll bit=2*x;
       ll tot=(ll)pow(4,x)-(ll)pow(4,x-1);
       ll cur=n-(ll)pow(4,x-1)+1;
       ll a1=0,a2=0,a3=0;
       
       a1=1ll<<(bit-2);a2=1ll<<(bit-1);a3=a1^a2;
       bit-=2;
       while(bit>0)
       {
           ll tmp=0;
           tot/=4;
           while(tot*tmp<cur)
           tmp++;
           if(tmp==2)
           {
               a1+=(1ll<<bit-2);
               a2+=(1ll<<bit-1);
               a3=a1^a2;
           }
           else if(tmp==3)
           {
               a1+=(1ll<<bit-1);
               a2+=((1ll<<bit-1)+(1ll<<bit-2));
               a3=a1^a2;
           }
           else if(tmp==4)
           {
               a1+=((1ll<<bit-1)+(1ll<<bit-2));
               a2+=(1ll<<bit-2);
               a3=a1^a2;
           }
           bit-=2;
           cur=cur-(tot*(tmp-1));
        }
        if(n%3==1)cout<<a1<<endl;
        else if(n%3==2)cout<<a2<<endl;
        else cout<<a3<<endl;
    }

}