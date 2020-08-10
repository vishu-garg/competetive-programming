#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rep(i,s,e) for(ll i=s;i<e;i++)

ll find(string s , string t)
{
    ll n=s.length();
    ll m=t.length();
    ll mat[m+1][n+1];
    rep(i,0,m+1)
    mat[i][0]=0;
    rep(i,0,n+1)
    mat[0][i]=1;
    rep(i,1,m+1)
    {
        rep(j,1,n+1)
        {
            if(t[i-1]!=s[j-1])
            mat[i][j]=mat[i][j-1];
            else 
            mat[i][j]=mat[i-1][j-1]+mat[i][j-1];
        }
    }
    return mat[m][n];
}

int main()
{
    string t;
    string s;
    cin>>s>>t;
    cout<<find(s,t);
}