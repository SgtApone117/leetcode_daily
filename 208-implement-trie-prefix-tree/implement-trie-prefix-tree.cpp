struct TrieNode
{
    vector<TrieNode*> data;
    bool isEnd;

    TrieNode() :isEnd(false), data(vector<TrieNode*> (26, nullptr)){}
};
class Trie {
private:
    TrieNode* root;
public:
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char& ch : word)
        {
            if(nullptr == curr->data[ch-'a'])
            {
                TrieNode* newNode = new TrieNode();
                curr->data[ch-'a'] = newNode;
            }
            curr = curr->data[ch-'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char &ch : word)
        {
            if(nullptr == curr->data[ch-'a'])
                return false;
            curr = curr->data[ch-'a'];
        }
        return (curr->isEnd && curr != nullptr);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char &ch : prefix)
        {
            if(nullptr == curr->data[ch-'a'])
                return false;
            curr = curr->data[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */