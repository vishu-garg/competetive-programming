#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll findcommonele(ll mat[][1000],ll n)
{
    unordered_set<ll> us;

    for(ll i=0;i<n;i++)
    us.insert(mat[0][i]);

    for(ll i=0;i<n;i++)
    {
        unordered_set<ll> temp;
        for(ll j=0;j<n;j++)
        temp.insert(mat[i][j]);

        unordered_set<ll>::iterator itr;

        for(itr=us.begin();it!=us.end();it++)
        {
            if(temp.find(*itr)==temp.end())
            us.erase(*itr);
        }
        if(us.size()==0)
        break;
    }
    cout<<us.size();
}

int main()
{
    ll n;
    cin>>n;
    ll mat[n][n];
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        cin>>mat[i][j];
    }
    findcommonele(mat,n);
}