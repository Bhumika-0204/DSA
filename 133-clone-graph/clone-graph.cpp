/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    vector<Node*> nodeRegister;

    Node* cloneGraph(Node* node) {

        if(node == NULL)
            return NULL;

        nodeRegister.resize(101, NULL);

        Node* clone = new Node(node->val);
        nodeRegister[node->val] = clone;

        dfs(node, clone);

        return clone;
    }

    void dfs(Node* actual, Node* clone) {

        for(auto neighbour : actual->neighbors) {

            if(nodeRegister[neighbour->val] == NULL) {

                Node* newNode = new Node(neighbour->val);

                nodeRegister[neighbour->val] = newNode;

                clone->neighbors.push_back(newNode);

                dfs(neighbour, newNode);
            }
            else {

                clone->neighbors.push_back(
                    nodeRegister[neighbour->val]
                );
            }
        }
    }
};