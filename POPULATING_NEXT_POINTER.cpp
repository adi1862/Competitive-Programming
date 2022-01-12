
class Solution {
public:
    // Time : O(N),  Space: O(N)
    Node* connect(Node* root) {
        //BFS Approach
        queue<Node*> levels;
        if(!root)return NULL;
        levels.push(root);
        while(!levels.empty()){
            int size = levels.size();
            while(size--){
                Node *curr = levels.front();
                levels.pop();
                if(size>0)
                    curr->next = levels.front();
                if(curr->left)levels.push(curr->left);
                if(curr->right)levels.push(curr->right);
            }
        }
        return root;
    }
    // Time : O(N),  Space: O(1) 
    //DFS Approach
    Node * connect(Node* root){
        if(!root)return NULL;
        if(root->left)root->left->next = root->right;
        if(root->right && root->next)root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
    
};

