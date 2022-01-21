#include <algorithm>
#include <vector>
#include <stack>
#include <hash_map>
#include <map>
#include <unordered_map>
#include <deque>
#include <string>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

/*
力扣List
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class UnionSet
{
private:
    vector<int> fa;
    //以index为根节点的数目
    vector<int> rootSize;

public:
    UnionSet(int size){
        fa.resize(size);
        rootSize.resize(size);
        for (int i = 0; i < size; i++){
            fa[i] = i;
            rootSize[i] = 1;
        }
    }

    void Union(int index1, int index2){
        int root1 = find(index1);
        int root2 = find(index2);
        if(root1 == root2){
            return;
        }
        fa[root1] = root2;
        rootSize[root2] += rootSize[root1];
    }

    int find(int index1){
        if(fa[index1] != index1){
            fa[index1] = find(fa[index1]);
        }
        return fa[index1];
    }
    
    int getSize(int index){
        return rootSize[find(index)];
    }

    vector<int>& getFa(){
        return fa;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    string ans;
    queue<TreeNode*> Q;
    void AddNode(TreeNode* root) {
        if(root) {
            ans.append(to_string(root -> val).append("_"));
            Q.push(root);
        }else{
            ans.append("#_");
        }
    }

    vector<string> split(string data) {
        if(data.empty())    return {};
        vector<string> res;
        for(int i = 0; i < data.size(); i++) {
            string word;
            while(i < data.size() && data[i] != '_') {
                word.push_back(data[i]);
                i++;
            }
            res.push_back(word);
        }
        return res;
    }

public:
    //参考力扣序列化手法，按照层次遍历完成序列化,#表示null
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> empty;  //清空Q
        swap(empty, Q);
        ans = "";
        AddNode(root);
        while(!Q.empty()) {
            TreeNode* cur = Q.front();
            AddNode(cur -> left);
            AddNode(cur -> right);
            Q.pop();
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> empty;  //清空Q
        swap(empty, Q);
        vector<string> pieceNodes = split(data);
        int n = pieceNodes.size();
        if(pieceNodes.empty() || pieceNodes[0] == "#")  return NULL;
        TreeNode* root = new TreeNode(atoi(pieceNodes[0].c_str()));
        Q.push(root);
        for(int i = 1; i < n; i += 2) {
            TreeNode* cur = Q.front();
            TreeNode* left = NULL;
            TreeNode* right = NULL;
            if(i < n && pieceNodes[i] != "#") {
                int valL = atoi(pieceNodes[i].c_str());
                left = new TreeNode(valL);   
            }

            if(i + 1 < n &&  pieceNodes[i + 1] != "#") {
                int valR = atoi(pieceNodes[i + 1].c_str());
                right = new TreeNode(valR);
            }
            cur -> left = left;
            cur -> right = right;
            AddNode(cur -> left);
            AddNode(cur -> right);
            Q.pop();
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

