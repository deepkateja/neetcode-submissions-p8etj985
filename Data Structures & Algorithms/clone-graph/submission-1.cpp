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
    Node* copyRecursively(Node* root, 
                        unordered_map<Node*, Node*>& mp){
        if(!root){
            return NULL;
        }
        Node* newRoot = new Node(root->val);
        mp[root] = newRoot;
        vector<Node*> nbors;
        for(Node* child: root->neighbors){
            if(mp.find(child)!=mp.end()){
                nbors.push_back(mp[child]);
            }else{
                Node* copiedNode = copyRecursively(child, mp);
                nbors.push_back(copiedNode);
            }
        }
        newRoot->neighbors = nbors;
        return newRoot;
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
      
        return copyRecursively(node, mp);
        // return root;
    }
};
