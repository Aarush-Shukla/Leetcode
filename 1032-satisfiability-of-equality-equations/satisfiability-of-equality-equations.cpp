class Solution {
public:

vector<int> parent;
vector<int> rank;

int find(int x){
    if(x==parent[x]){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    if(rank[x]>rank[y]){
        parent[y]=x;
    }else if(rank[x]<rank[y]){
        parent[x]=y;
    }else{
        parent[x]=y;
        rank[y]++;
    }
}

bool equationsPossible(vector<string>& equations) {
    int n=equations.size();
        rank.resize(26,0);
        parent.resize(26);

        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }

        for(auto str: equations){
          if(str[1]== '='){
            Union(str[0]-'a',str[3]-'a');
          }
        }

        for(auto str: equations){
            if(str[1]== '!'){
                int x=find(str[0]-'a');
                int y=find(str[3]-'a');

                if(x==y)return false;
            }
        }
        return true;
    }
};