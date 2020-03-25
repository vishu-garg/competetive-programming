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
// ll visited[26]={0};

// string dfs(char src, map<char,set<char> >mp , char prev)
// {
//     visited[src-'a']=1;
//     string ans="";
//     for(auto it : mp[src])
//     {
//         if(visited[it-'a']==1 && it!=prev)
//         {
//             string s="";
//             return s;
//         }
//         else if(visited[it-'a']==0)
//         {
//         string s=dfs(it,mp,src);
//         if(s=="")
//         return s;
//         ans+=s;
//         }
//     }
//     ans+=src;
//     // cout<<ans<<" <============"<<endl;
//     return ans;
// }

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll used[26]={0};
        used[s[0]-'a']=1;
        string ans(1,s[0]);
        ll pos=0;
        ll f=0;
        rep(i,1,s.size())
        {
            if(used[s[i]-'a']==1)
            {
                if(pos>0 && ans[pos-1]==s[i])
                pos--;
                else if(pos+1<ans.size() && ans[pos+1]==s[i])
                pos++;
                else 
                {
                    cout<<"NO"<<endl;
                    f=-1;
                    break;
                }
            }
            else
            {
                if(pos==0)
                ans=s[i]+ans;
                else if(pos+1==ans.size())
                {ans+=s[i];pos++;}
                else 
                {
                    cout<<"NO"<<endl;
                    f=-1;
                    break;
                }
                used[s[i]-'a']=1;
            }
        }
        // cout<<f<<"KKKKKKk";
        if(f==0)
        {
        cout<<"YES"<<endl;
        // cout<<ans<<endl;
        map<char,ll> mp2;
        rep(i,0,ans.length())
        mp2[ans[i]]++;
        rep(i,0,26)
        {
            if(mp2['a'+i]==0)
            ans+=('a'+i);
        }
        cout<<ans<<endl;
        }
    }
}