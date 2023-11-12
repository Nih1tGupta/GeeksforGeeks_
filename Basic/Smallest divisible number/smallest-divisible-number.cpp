//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    long long getSmallestDivNum(long long n){
long res = 1;
for(long i = 2; i <= n; i++)
{
res = (res*i)/__gcd(res,i);
}
return res;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<< ob.getSmallestDivNum(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends