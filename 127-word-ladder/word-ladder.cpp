class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordlist(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        int levels=1;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        while(!q.empty()){
            int N = q.size();
            while(N--){
                string curr=q.front();
                q.pop();
                if(curr == endWord)return levels;
                
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char ch='a'; ch<= 'z'; ch++){
                        temp[i]=ch;

                        if(temp==curr)continue;

                        if(visited.find(temp)==visited.end() && wordlist.find(temp)!= wordlist.end()){
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            levels++;
        }
        return 0;
    }
};