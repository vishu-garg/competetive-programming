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

ll calc(string a, string b)
{
    ll d=0;
    rep(i,0,7)
    {
        if(a[i]=='1' && b[i]=='0')
        {
            return -1;
        }
        if(a[i]!=b[i])
        d++;
    }
    return d;
}

int main()
{
    ll t=1;
//     cin>>t;
    while(t--)
    {
        ll n,k;
        map<ll,string>mp;
        cin>>n>>k;
        vector<string> v(n);
        rep(i,0,n)
        {
            cin>>v[i];
        }
        
        mp[0]="1110111";
        mp[1]= "0010010";
        mp[2]="1011101";
        mp[3]="1011011";
        mp[4]="0111010";
        mp[5]="1101011";
        mp[6]="1101111";
        mp[7]="1010010";
        mp[8]="1111111";
        mp[9]="1111011";

        vector<vector<pair<ll,ll> > >cst(n);

        for(int it=0;it<n;it++)
        {
            for(ll i=9;i>=0;i--)
            {
                ll d=calc(v[it],mp[i]);
                if(d!=-1)
                {
                    cst[it].emplace_back(make_pair(i,d));
                }
            }
        }

        bool can[2005][2005];
        can[n][0]=true;
        for(ll i=n-1;i>=0;i--)
        {
            for(ll j=0;j<=k;j++)
            {
                if(can[i+1][j])
                {
                    for(auto it: cst[i])
                    {
                        can[i][j+it.second]=true;
                    }
                }
            }
        }

        if(!can[0][k])
        {
            cout<<"-1"<<endl;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                for(auto it: cst[i])
                {
                    if(k>=it.second && can[i+1][k-it.second])
                    {
                        k-=it.second;
                        cout<<it.first;
                        break;
                    }
                }
            }
        }
    }
}
        


/*

"Humne can[i][j]=true kia agar i.....n tak ke sabhi number koi valid set of digits banate ho with exactly j sticks being used"
aur j ko humne sirf 2005 tk jaane diya kyonki hume k<=2000 toh uske upar ke dekhkar fayda hi nahi he

*/