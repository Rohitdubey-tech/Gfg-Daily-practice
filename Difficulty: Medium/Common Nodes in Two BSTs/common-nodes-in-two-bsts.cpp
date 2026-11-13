class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        vector<int> ans;
        stack<Node*> s1,s2;
        Node *t1,*t2;
        while(true){
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2)  {
                s2.push(r2);
                r2 = r2->left;
            }

            if(s1.empty() || s2.empty())  return ans;

            t1 = s1.top();
            t2 = s2.top();

            if(t1->data == t2->data) {
                ans.push_back(t1->data);
                r1 = t1->right;
                r2 = t2->right;
                s1.pop();
                s2.pop();
            }
            else if(t2->data > t1->data) {
                r1 = t1->right;
                s1.pop();
            }
            else  {
                r2 = t2->right;
                s2.pop();
            }
        }
        return ans;
    }
};