#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int ans = 0;

struct ListNode{
    ListNode* left;
    ListNode* right;
    int val;
    // int maxs, mins;
    int len;
    ListNode() {}
    ListNode(int val):val(val), left(nullptr), right(nullptr) {}
};

int dfs1(ListNode* root, int val) {
    if (root == nullptr) {
        return 0;
    }
    if (root->val > val) {
        return root->len;
    } 
    int dx = dfs1(root->right, val);
    root->len -= dx;
    return dx;
}

int dfs2(ListNode* root, int val){
    if (root == nullptr) {
        return 0;
    }
    if (root->val < val) {
        return root->len;
    } 
    int dx = dfs2(root->left, val);
    root->len -= dx;
    return dx;
}

int dfs(ListNode* root) {
    if (root == nullptr) {
        return 0;
    }

    int leftLen, rightLen;
    if (root->left) {
        leftLen = dfs(root->left);
    }
    if (root->right) {
        rightLen = dfs(root->right);
    }

    root->len = 1;
    //back
    if (root->left && root->val > root->left->val) {
        root->len += root->left->len;
        ListNode* p = root->left;
        int dx = dfs1(p, root->val);
        root->len -= dx;
    }
    if (root->right && root->val < root->right->val) {
        root->len += root->right->len;
        ListNode* p = root->right;
        int dx = dfs2(p, root->val);
        root->len -= dx;
    }

    ans = max(ans, root->len);

}

int main() {

    return 0;
}
