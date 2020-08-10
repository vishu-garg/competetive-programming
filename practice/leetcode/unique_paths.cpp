#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll m,n;
    cin>>m>>n;
    int dp[m+1][n+1];
    for(int i=1;i<=m;i++)
    dp[i][1]=1;
    for(int i=1;i<=n;i++)
    dp[1][i]=1;
    for(int i=2;i<=m;i++)
    {
        for(int j=2;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[m][n];
}

//With obstacles;

// int uniquePathsWithObstacles(vector<vector<int>>& v) {
//         int m=v[0].size();
//         int n=v.size();
//         long long dp[m+1][n+1];
//         int fnd=0;
//         for(int i=1;i<=m;i++)
//         {
//             if(v[0][i-1]==1 || fnd==1)
//             {
//                 dp[i][1]=0;
//                 fnd=1;
//             }
//             else 
//             {
//                 dp[i][1]=1;
//             }
//         }
//         fnd=0;
//         for(int i=1;i<=n;i++)
//         {
//             if(v[i-1][0]==1 || fnd==1)
//             {
//                 dp[1][i]=0;
//                 fnd=1;
//             }
//             else 
//             {
//                 dp[1][i]=1;
//             }
//         }
//         for(int i=2;i<=m;i++)
//         {
//             for(int j=2;j<=n;j++)
//             {
//                 if(v[j-1][i-1]==1)
//                 {
//                     dp[i][j]=0;
//                     continue;
//                 }
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//         return dp[m][n];
//     }