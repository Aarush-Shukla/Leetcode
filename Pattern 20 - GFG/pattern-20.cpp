//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        for(int i=0;i<n-1;i++){
           for(int j=0;j<=i;j++){
               cout<<"*";
           }
           for(int k=0;k<2*(n-i-1);k++){
               cout<<" ";
           }for(int j=0;j<=i;j++){
               cout<<"*";
           }
          
           cout<<endl;
           
           
       }
          for(int i=0;i<n;i++){
           for(int j=n-1;j>=i;j--){
               cout<<"*";
           }
           for(int k=0;k<2*(i);k++){
               cout<<" ";
           }for(int j=n-1;j>=i;j--){
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