class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        Node* level = root;

        while (level->left != NULL) {
            Node* curr = level;

            while (curr != NULL) {
                // Connect left -> right
                curr->left->next = curr->right;

                // Connect right -> next subtree's left
                if (curr->next != NULL)
                    curr->right->next = curr->next->left;

                curr = curr->next;
            }
            level = level->left;
        }
        return root;
    }
};
