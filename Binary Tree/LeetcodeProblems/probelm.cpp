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
    //
      vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        auto compare = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(compare)> minHeap(compare);

        // Push initial pairs into the heap
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            minHeap.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !minHeap.empty()) {
            auto [sum, i, j] = minHeap.top();
            minHeap.pop();
            result.push_back({nums1[i], nums2[j]});
            
            if (j + 1 < nums2.size()) {
                minHeap.emplace(nums1[i] + nums2[j + 1], i, j + 1);
            }
        }

        return result;
    }