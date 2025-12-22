class Solution {
public:
    bool isValidSerialization(string preorder) {
        int slots = 1; // one slot for root
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            if (preorder[i] == ',') continue;

            // Consume one slot
            slots--;
            if (slots < 0) return false;

            // If not null node, add two slots
            if (preorder[i] != '#') {
                // skip the number (can be multi-digit)
                while (i < n && preorder[i] != ',')
                    i++;
                slots += 2;
            }
        }
        return slots == 0;
    }
};
