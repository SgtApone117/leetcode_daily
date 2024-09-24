struct TrieNode{
    TrieNode* data[26];
    bool isEnd;
    int frequency;

    TrieNode(): isEnd(false), frequency(0)
    {
        for(int i = 0; i < 26; i++)
        {
            data[i] = nullptr;
        }
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
            curr = curr->data[ch-'a'];
            curr->frequency++;
        }
        curr->isEnd = true;
    }

    string search(TrieNode* root, string word, int totalSize)
    {
        string prefix = "";
        TrieNode* curr = root;
        for(char &ch : word)
        {
            if(nullptr != curr->data[ch-'a'] && curr->data[ch-'a']->frequency == totalSize)
            {
                prefix += ch;
                curr = curr->data[ch-'a'];
            }
            else
            {
                break;
            }
        }
        return prefix;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        TrieNode* root = new TrieNode();
        string res = "";
        for(string word : strs)
        {
            insert(root, word);
        }
        return search(root, strs[0], strs.size());
    }
};