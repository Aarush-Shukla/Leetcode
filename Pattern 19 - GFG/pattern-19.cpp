//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
       for(int i=0;i<n;i++){
           for(int j=n;j>i;j--){
               cout<<"*";
           }
           for(int k=0;k<2*i;k++){
               cout<<" ";
           }for(int j=n;j>i;j--){
               cout<<"*";
           }
           if(i<n-1){
           cout<<endl;
           }
           
       }
          for(int i=0;i<=n;i++){
           for(int j=0;j<i;j++){
               cout<<"*";
           }
           for(int k=0;k<2*(n-i);k++){
               cout<<" ";
           }for(int j=0;j<i;j++){
               cout<<"*";
           }
           
           cout<<endl;
       
       }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends