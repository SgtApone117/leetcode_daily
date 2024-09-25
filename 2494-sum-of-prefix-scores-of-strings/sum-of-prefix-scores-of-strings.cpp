struct TrieNode
{
    TrieNode* data[26];
    bool isEnd;
    int count;

    TrieNode(): isEnd(false), count(0)
    {
        for(int i = 0; i < 26; i++)
            data[i] = nullptr;
    }
};
class Solution {
private:
    void insert(TrieNode* root, string word)
    {
        TrieNode* curr = root;
        for(char &ch : word)
        {
            if(nullptr == curr->data[ch-'a'])
            {
                TrieNode* newNode = new TrieNode();
                curr->data[ch-'a'] = newNode;
            }
            curr->data[ch-'a']->count++;
            curr = curr->data[ch-'a'];
        }
        curr->isEnd = true;
    }

    int search(TrieNode* root, string word)
    {
        int total_count = 0;
        TrieNode* curr = root;
        for(char& ch : word)
        {
            if(nullptr == curr->data[ch-'a'])
                return total_count;
            total_count += curr->data[ch-'a']->count;
            curr = curr->data[ch-'a'];
        }
        return total_count;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) 
    {
        TrieNode* root = new TrieNode();
        vector<int> res;
        for(string word : words)
            insert(root, word);
        for(string word : words)
            res.push_back(search(root, word));
        return res;   
    }
};