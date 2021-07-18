#include <iostream>
#include <stdio.h>
#include <math.h>
#include <climits>
#include <vector>
using namespace std;

class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
};

void insertTrie(int num, TrieNode *head)
{
    TrieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int curr_bit = (num >> i) & 1;
        if (curr_bit)
        {
            if (!curr->left)
                curr->left = new TrieNode();
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
                curr->right = new TrieNode();
            curr = curr->right;
        }
    }
}

int findMaxXor(int n, vector<int> &nums, TrieNode *head)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        TrieNode *curr = head;
        int curr_xor = 0;
        for (int j = 31; j >= 0; j--)
        {
            int curr_bit = (nums[i] >> j) & 1;
            if (curr_bit)
            {
                if (curr->right)
                {
                    // cout << curr_bit << " ";
                    curr_xor += pow(2, j);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left)
                {
                    // cout << curr_bit << " ";
                    curr_xor += pow(2, j);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<int> nums(n);
    TrieNode *head = new TrieNode();
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        insertTrie(nums[i], head);
    }
    cout << findMaxXor(n, nums, head) << "\n";
}