  //https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/?envType=study-plan-v2&envId=top-interview-150
  Node* connect(Node* root) {
        if(!root)
        return nullptr;
        deque<Node*> nodes;
        nodes.push_back(root);
        while(!nodes.empty())
        {
            int sz = nodes.size();
            while(sz--)
            {
                Node* cur = nodes.front();
                nodes.pop_front();
                if(sz!=0)
                cur->next = nodes.front();
                else
                cur->next = nullptr;
                if(cur->left)
                nodes.push_back(cur->left);
                if(cur->right)
                nodes.push_back(cur->right);
            }
        }

        return root;
        
    }