class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int ans=0;
        unordered_map<char,int>umap;
        for(auto i:chars) umap[i]++;
        int n=words.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int>temp;
            int m=words[i].size();
            int j;
            for(j=0;j<m;j++){
                temp[words[i][j]]++;
                if(umap.find(words[i][j])==umap.end()) break;
                if(temp[words[i][j]]>umap[words[i][j]]) break;
            }
            if(j==m) ans+=m;

        }
        return ans;
    }
};