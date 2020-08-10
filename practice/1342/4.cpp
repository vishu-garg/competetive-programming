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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//     cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        rep(i,0,n)
        cin>>a[i];
        int a2[k+1];
        rep(i,1,k+1)
        cin>>a2[i];
        sort(a,a+n,greater<int>());
        vector<vector<int> > ans(n);
        set<pair<int,int> > st;
        int idx=-1;
        rep(i,0,n)
        {
            int lmt=a2[a[i]];
            auto it = st.lower_bound(make_pair(lmt,-1));
            if(it==st.begin())
            {
                // We have to add new testcase because numbers greater than or equal to a[i] is more than lmt;
                idx++;
                ans[idx].pb(a[i]);
                st.insert(make_pair(1,idx));
            }
            else 
            {
                it--;
                auto pr=*it;
                ans[pr.second].pb(a[i]);
                st.erase(it);
                st.insert(make_pair(pr.first+1,pr.second));
            }
        }
    cout<<idx+1<<endl;
    for(auto it1 : ans)
    {
        if(it1.size()==0)
        break;
        // break;
        cout<<it1.size()<<" ";
        for(auto it : it1)
        cout<<it<<" ";
        cout<<endl;
    }
    }

}


// #include<bits/stdc++.h>
// #include<algorithm>
// using namespace std;
 
// #define ll long long
// #define ld long double
 
// #define rep(i,a,b) for(ll i=a;i<b;i++)
// #define repb(i,a,b) for(ll i=a;i>=b;i--)
 
// #define err() cout<<"=================================="<<endl;
// #define errA(A) for(auto i:A)   cout<<i<<" ";cout<<endl;
// #define err1(a) cout<<#a<<" "<<a<<endl
// #define err2(a,b) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<endl
// #define err3(a,b,c) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<endl
// #define err4(a,b,c,d) cout<<#a<<" "<<a<<" "<<#b<<" "<<b<<" "<<#c<<" "<<c<<" "<<#d<<" "<<d<<endl
 
// #define pb push_back
// #define all(A)  A.begin(),A.end()
// #define allr(A)    A.rbegin(),A.rend()
// #define ft first
// #define sd second
 
// #define pll pair<ll,ll>
// #define V vector<ll>
// #define S set<ll>
// #define VV vector<V>
// #define Vpll vector<pll>
 
// #define endl "\n"
 
// const ll logN = 20;
// const ll M = 1000000007;
// const ll INF = 1e12;
// #define PI 3.14159265

// int pow1(int a,int b){
//     int res=1;
//     while(b>0){
//         if(b&1){
//         	res=res*a;
// 		}
//         a=a*a;
//         b>>=1;
//     }
//     return res;
// }

// int main()
// {
//     ll t=1;
// //     cin>>t;
//     while(t--)
//     {
//         ll n,k;
//         cin>>n>>k;
//         ll a[n];
//         map<ll,ll> mp;
//         rep(i,0,n)
//         {cin>>a[i];mp[a[i]]++;}
//         vector<ll> a2(k);
//         rep(i,0,n)
//         cin>>a2[i];
//         vector<ll> a3(k);
//         for(ll i=1;i<k+1;i++)
//         {
//             ll num=mp[i];
//             a3[i-1]=num;
//         }
//         repb(i,k-2,0)
//         a3[i]+=a3[i+1];
//         ll tc=1;
//         rep(i,0,n)
//         {
//             ll tmp=ceil(double(a3[i])/double(a2[i]));
//             tc=max(tc,tmp);
//         }
//         cout<<tc<<endl;
//         rep(i,0,k-2)
//         a3[i]-=a3[i+1];
//         vector<vector<ll> >ans(tc);
//         repb(j,n-1,0)
//         {
//             ll t2=0;
//             while(a3[j]>0)
//             {
//                 ll lmt=a2[j]-(ll)ans[t2].size();
//                 lmt=min(a3[j],lmt);
//                 a3[j]-=lmt;
//                 rep(i,0,lmt)
//                 {
//                     ans[t2].pb(j+1);
//                 }
//                 t2++;
//             }
//         }
//         rep(i,0,tc)
//         {
//             cout<<ans[i].size<<" ";
//             rep(j,0,ans[i].size())
//             cout<<ans[i][j]<<" ";
//             cout<<endl;
//         }            
//     }

// }


// "In second approach the worst case is O(n*k) and avg is O(n)"