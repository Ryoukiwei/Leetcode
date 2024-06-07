#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    array<TrieNode *, 26> children;
    bool isEnd;

    TrieNode() : children(), isEnd(false) {}
    ~TrieNode()
    {
        for (auto child : children)
        {
            if (child)
            {
                delete child;
                child = nullptr;
            }
        }
    }
};

class Trie
{
public:
    Trie() { root = new TrieNode(); }

    void insert(const string &word)
    {
        TrieNode *node = root;
        for (const char c : word)
        {
            const int i = c - 'a';
            if (!node->children[i])
                node->children[i] = new TrieNode();

            node = node->children[i];
        }

        node->isEnd = true;
    }

    string find(const string &word)
    {
        TrieNode *node = root;
        string rootWord = "";
        for (const char c : word)
        {
            const int i = c - 'a';
            if (!node->children[i])
                break;

            rootWord.push_back(c);
            node = node->children[i];

            if (node->isEnd)
                return rootWord;
        }

        return word;
    }

private:
    TrieNode *root;
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, const string &sentence)
    {
        Trie trie;
        for (const string &root : dictionary)
        {
            trie.insert(root);
        }

        string ans = "";
        istringstream iss(sentence);
        string word;

        while (iss >> word)
        {
            ans += trie.find(word) + " ";
        }

        if (!ans.empty())
            ans.pop_back();

        return ans;
    }
};