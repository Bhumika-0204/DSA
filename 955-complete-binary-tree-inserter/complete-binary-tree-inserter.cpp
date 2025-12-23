class CBTInserter {
public:
    TreeNode* root;
    queue<TreeNode*> q;

    CBTInserter(TreeNode* r) {
        root = r;
        queue<TreeNode*> temp;
        temp.push(root);

        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();

            if (!(node->left && node->right))
                q.push(node);

            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }

    int insert(int val) {
        TreeNode* parent = q.front();
        TreeNode* newNode = new TreeNode(val);

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            q.pop(); // parent is now full
        }

        q.push(newNode);
        return parent->val;
    }

    TreeNode* get_root() {
        return root;
    }
};
