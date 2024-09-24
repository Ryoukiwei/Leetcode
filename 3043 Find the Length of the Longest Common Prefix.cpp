#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class TrieNode
{
public:
    int data;
    array<TrieNode *, 10> children;
    bool isEnd;

    TrieNode(int c) : data(c), isEnd(false) { children.fill(nullptr); }
};

class Trie
{
public:
    Trie() : root(new TrieNode(-1)) {}
    ~Trie() { clean(root); }

    void insert(int data)
    {
        TrieNode *node = root;
        int divisor = 1;

        while (data / divisor >= 10)
            divisor *= 10;

        while (divisor > 0)
        {
            int digit = (data / divisor) % 10;
            if (!(node->children[digit]))
                node->children[digit] = new TrieNode(digit);

            node = node->children[digit];
            divisor /= 10;
        }
        node->isEnd = true;
    }

    int prefixLen(int data)
    {
        TrieNode *node = root;
        int length = 0;
        int divisor = 1;

        while (data / divisor >= 10)
            divisor *= 10;

        while (divisor > 0)
        {
            int digit = (data / divisor) % 10;
            if (!(node->children[digit]))
                break;

            node = node->children[digit];
            ++length;
            divisor /= 10;
        }

        return length;
    }

private:
    TrieNode *root;

    void clean(TrieNode *node)
    {
        if (node)
        {
            for (auto child : node->children)
            {
                if (child)
                    clean(child);
            }
            delete node;
        }
    }
};

class Solution
{

public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {

        Trie trie;
        for (const int &num : arr1)
        {
            trie.insert(num);
        }

        int ans = 0;
        for (const int &num : arr2)
        {
            ans = max(trie.prefixLen(num), ans);
        }

        return ans;
    }
};