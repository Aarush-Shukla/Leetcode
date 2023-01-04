//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
       //{ Driver Code Starts
       char abc= 'A';
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                char ch= 'A'+n-1;
                cout<<char(ch-j)<<" ";
                
            }
            
            // for(char ch='A'+n-1;ch>='A';ch--){
            //     cout<<ch;
            // }
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