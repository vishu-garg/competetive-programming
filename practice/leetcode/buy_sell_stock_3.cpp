// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define rep(i,s,e) for(int i=s;i<e;i++)

// int main()
// {
//     // vector<int> prices;
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     rep(i,0,n)
//     cin>>v[i];
//     int dp[3][n+1];
//     rep(i,0,3)
//     dp[i][0]=0;
//     rep(j,0,n+1)
//     dp[0][j]=0;
//     for(int i=1;i<=2;i++)
//     {
//         int prevdiff=INT_MIN;
//         for(int  j=1;j<n;j++)
//         {
//             prevdiff=max(prevdiff,dp[i-1][j-1]-v[j-1]);
//             dp[i][j]=max(dp[i][j-1],v[j]+prevdiff);
//         }
//     }
// //    cout<<dp[2][n-1]<<endl;
//      return dp[2][n-1];
// }

//
// O(N) memory and time solution

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,s,e) for(int i=s;i<e;i++)
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n)
    cin>>v[i];
    int res[2*k]; // here we have to make  atmost k buy and k sell so total of 2*k transactions
    rep(i,0,k)
    res[2*i]=INT_MIN;
    rep(i,0,n)
    {
        for(int j=2*k-1;j>0;j--)
        {
            if(j%2!=0)
            res[j]=max(res[j],res[j-1]+v[i]);
            else
            res[j]=max(res[j],res[j-1]-v[i]);
        }
        res[0]=max(res[0],-v[i]);
    }
    int ans=res[1];
    rep(i,0,k)
    ans=max(ans,res[2*i+1]);
}