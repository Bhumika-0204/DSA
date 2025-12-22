class Codec {
public:
    // Serialize using preorder traversal
    void preorder(TreeNode* root, string &s) {
        if (!root) return;
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Deserialize helper
    TreeNode* build(vector<int>& v, int &i, int low, int high) {
        if (i >= v.size() || v[i] < low || v[i] > high)
            return NULL;

        TreeNode* root = new TreeNode(v[i++]);
        root->left = build(v, i, low, root->val);
        root->right = build(v, i, root->val, high);
        return root;
    }

    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;

        vector<int> v;
        string temp;
        for (char c : data) {
            if (c == ',') {
                v.push_back(stoi(temp));
                temp.clear();
            } else {
                temp.push_back(c);
            }
        }

        int i = 0;
        return build(v, i, INT_MIN, INT_MAX);
    }
};
