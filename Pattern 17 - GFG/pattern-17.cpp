//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void printTriangle(int n) {
        char abc= 'A';
        for(int i=0;i<n;i++){
            for(int k=0;k<n-i-1;k++){
                cout<<" ";
            }
         
            for(char ch='A';ch<='A'+i;ch++){
                cout<<ch;
            }for(char ch='A'+i-1;ch>='A';ch--){
                cout<<ch;
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