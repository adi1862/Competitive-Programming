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
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        unordered_map<Node*, Node*> mp;
        // referring copies
        Node* copy = new Node(node->val, {});
        mp[node] = copy;
        // bfs traversal
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbour: curr -> neighbors){
                if(mp.find(neighbour) == mp.end()){
                    // not found in the map then
                    q.push(neighbour);
                    mp[neighbour] = new  Node(neighbour->val, {});
                }
                // filling the list for the current node
                mp[curr] -> neighbors.push_back(mp[neighbour]);
            }
        }
        return copy;
        
    }

};
