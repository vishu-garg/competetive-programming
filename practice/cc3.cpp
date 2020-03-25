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

map<pair<char,ll>,ll>mp;

ll chk_psb(char m1 , char m2 , char m3 , char m4)
{
    ll cnt[4];
    cnt[0]=mp[{m1,12}];
    cnt[1]=mp[{m2,3}];
    cnt[2]=mp[{m3,6}];
    cnt[3]=mp[{m4,9}];
    // cout<<m1<<" "<<m2<<" "<<m3<<" "<<m4<<endl;
    // cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" "<<cnt[3]<<endl;
    sort(cnt,cnt+4);
    ll sum=0;
    repb(i,3,0){
    if(cnt[i]==0)
    sum-=100;
    else 
    sum+=((25*(i+1))*(cnt[i]));
    // cout<<"sum= "<<sum<<endl;
    }
    // cout<<"sum= "<<sum<<endl;
    return sum;
}
int main()
{
    ll t;
    cin>>t;
    ll ttl=0;
    while(t--)
    {
        ll n;
        cin>>n;
        
        rep(i,0,n)
        {
            char mve;
            ll tme;
            cin>>mve>>tme;
            mp[{mve,tme}]++;
        }
        
        ll mx=(-500);
        mx=max(mx,chk_psb('A','B','C','D'));
        mx=max(mx,chk_psb('A','B','D','C'));
        mx=max(mx,chk_psb('A','C','D','B'));
        mx=max(mx,chk_psb('A','C','B','D'));
        mx=max(mx,chk_psb('A','D','C','B'));
        mx=max(mx,chk_psb('A','D','B','C'));
        mx=max(mx,chk_psb('B','A','C','D'));
        mx=max(mx,chk_psb('B','A','D','C'));
        mx=max(mx,chk_psb('B','C','A','D'));
        mx=max(mx,chk_psb('B','C','D','A'));
        mx=max(mx,chk_psb('B','D','A','C'));
        mx=max(mx,chk_psb('B','D','C','A'));
        mx=max(mx,chk_psb('C','A','B','D'));
        mx=max(mx,chk_psb('C','A','D','B'));
        mx=max(mx,chk_psb('C','B','A','D'));
        mx=max(mx,chk_psb('C','B','D','A'));
        mx=max(mx,chk_psb('C','D','A','B'));
        mx=max(mx,chk_psb('C','D','B','A'));
        mx=max(mx,chk_psb('D','A','B','C'));
        mx=max(mx,chk_psb('D','A','C','B'));
        mx=max(mx,chk_psb('D','B','A','C'));
        mx=max(mx,chk_psb('D','B','C','A'));
        mx=max(mx,chk_psb('D','C','A','B'));
        mx=max(mx,chk_psb('D','C','B','A'));
        cout<<mx<<endl;
        ttl+=mx;
        mp[{'A',12}]=0;mp[{'B',12}]=0;mp[{'C',12}]=0;mp[{'D',12}]=0;
        mp[{'A',3}]=0;mp[{'B',3}]=0;mp[{'C',3}]=0;mp[{'D',3}]=0;
        mp[{'A',6}]=0;mp[{'B',6}]=0;mp[{'C',6}]=0;mp[{'D',6}]=0;
        mp[{'A',9}]=0;mp[{'B',9}]=0;mp[{'C',9}]=0;mp[{'D',9}]=0;
    }
    cout<<ttl;
}