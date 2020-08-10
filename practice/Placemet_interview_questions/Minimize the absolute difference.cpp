int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i=0,j=0,k=0;
    int ans=INT_MAX;
    int n=A.size(),m=B.size(),p=C.size();
    while(i<n && j<m && k<p)
    {
        int ans1=abs(max(A[i],max(B[j],C[k]))-min(A[i],min(B[j],C[k]));
        if(ans1<ans)
        ans=ans1;
        int mn=min(A[i],min(B[j],C[k]);
        if(mn==i)i++;
        else if(mn==j)j++;
        else k++;
    }
    return ans;
}
