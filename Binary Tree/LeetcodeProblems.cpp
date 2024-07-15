

// problem on leetcode : 
    int curSum = 0;
    bool isLeaf(TreeNode* root)
    {
        return root && !root->left && !root->right;
    }
    void sumNumbersHelper(TreeNode* root , int pathSum =0)
    {
        pathSum = pathSum * 10 + root->val;
        if(isLeaf(root))
        curSum += pathSum;

        if(root->left)
        sumNumbersHelper(root->left,pathSum);
        if(root->right)
        sumNumbersHelper(root->right,pathSum);

    }
    int sumNumbers(TreeNode* root) {
        if(!root)
        return 0;
        sumNumbersHelper(root,0);
        return curSum;
        
        
        
    }
    // easy problem on leetcode : 
    string canonical(TreeNode* root) {
    if (!root) {
        return "()";
    }

    string rep = "(" + to_string(root->val);

    if (root->left) {
        rep += canonical(root->left);
    } else {
        rep += "()";
    }

    if (root->right) {
        rep += canonical(root->right);
    } else {
        rep += "()";
    }

    rep += ")";

    return rep;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        string repP = canonical(p);
        string repQ = canonical(q);

        return repP == repQ;
        
    }
    // one easy problem on leet code 
     TreeNode* invertTree(TreeNode* root) {
        if(!root)
        return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp ;

        invertTree(root->left);
        invertTree(root->right);

        return root;
        
    }
    // solved problem on leetcode 
     vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> nodes ;
        nodes.push(root);

        while(!nodes.empty())
        {
            int sz = nodes.size();
            vector<int> levelN;
            while(sz--)
            {
                TreeNode* cur = nodes.front();
                nodes.pop();

                if(cur->left)
                nodes.push(cur->left);
                if(cur->right)
                nodes.push(cur->right);

                levelN.push_back(cur->val);

            }
            res.push_back(levelN);
           
        }

        return res;
        
    }
    // just med problem on leetcode : 
     vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        deque<TreeNode*> nodes ;
        nodes.push_back(root);
        res.push_back(root->val);
        
        while(!nodes.empty())
        {
            int sz = nodes.size();
            while(sz--)
            {
            TreeNode* cur = nodes.front();
            nodes.pop_front();

            if(cur->left)
            nodes.push_back(cur->left);
            if(cur->right)
            nodes.push_back(cur->right);
            }
            if(nodes.empty())
            break;
            TreeNode* toBePushed = nodes.back();

            res.push_back(toBePushed->val);
        }

        return res;
    } 
    // just easy problem on friday on leetcode 
     vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res ;
        if(!root) return res;
        queue<TreeNode*> nodes ;
        nodes.push(root);
        double curCount = 0;
        while(!nodes.empty())
        {
            int sz = nodes.size();
            curCount = sz;
            double sum = 0 ;
            while(sz--)
            {
                TreeNode* cur = nodes.front();
                nodes.pop();

                if(cur->left)
                nodes.push(cur->left);
                if(cur->right)
                nodes.push(cur->right);

                sum += cur->val;
            }
            res.push_back(sum/curCount);
        }
        return res;
    }
    // 
    
    

    






};
// just one problem 
 int countNodes(TreeNode* root) {
        if(!root) return 0;
        int res = 1 ;
        if(root->left)
        res += countNodes(root->left);
        if(root->right)
        res += countNodes(root->right);

        return res; 
    }
    //
      bool isLeaf(TreeNode* root) {
    return root && !root->left && !root->right;
}


void getLeafSequence(TreeNode* root, std::vector<int> &leaves) {
    if (!root) return;
    
    if (isLeaf(root)) {
        leaves.push_back(root->val);
    }

    getLeafSequence(root->left, leaves);
    getLeafSequence(root->right, leaves);
}


bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    std::vector<int> seq1, seq2;

    getLeafSequence(root1, seq1);
    getLeafSequence(root2, seq2);

    return seq1 == seq2;
        
    }