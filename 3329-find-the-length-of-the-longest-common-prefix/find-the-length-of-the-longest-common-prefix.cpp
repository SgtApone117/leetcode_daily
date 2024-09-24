//using TRIE data structure no need to check the is true part as it is just the length
struct TrieNode
{
    TrieNode* data[10];

    // bool isEnd;

    TrieNode()
    {
        // isEnd = false;
        for(int i = 0; i < 10; i++)
            data[i] = nullptr;
    }
};

class Solution {
private:
    void insert(TrieNode* root, int number)
    {
        TrieNode* curr = root;
        string varTr = to_string(number);
        for(char &ch : varTr)
        {
            if(curr->data[ch-'0'] == nullptr)
            {
                TrieNode* newNode = new TrieNode();
                curr->data[ch-'0'] = newNode;
            }
            curr = curr->data[ch-'0'];
        }
        // curr->isEnd = true;
    }

    int search(TrieNode* root, int number)
    {
        TrieNode* curr = root;
        string varTr = to_string(number);
        int count = 0;
        for(char &ch : varTr)
        {
            if(curr->data[ch-'0'] == nullptr)
            {
                break;
            }
            else
            {
                count++;
                curr = curr->data[ch-'0'];
            }
        }
        return count;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();
        int res = 0;
        for(int &num : arr1)
        {
            insert(root, num);
        }
        for(int &num : arr2)
        {
            res = max(res, search(root, num));
        }
        return res;
    }
};