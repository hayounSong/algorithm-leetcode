/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #include <vector>
 #include <iostream>
 #include <queue>
 using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){  
            return ans;
        }
        int numcheck[100001]={0};
        TreeNode *r=root;
        ans.push_back(r->val);
        queue<pair<TreeNode*,int>> q;  // TreeNode* 타입으로 수정
        q.push({r,0});
        while(!q.empty()){
            TreeNode* node = q.front().first;  // .first()가 아닌 .first 사용
            int level = q.front().second;      // .second()가 아닌 .second 사용
            q.pop();
        }
        return ans;
    }
};