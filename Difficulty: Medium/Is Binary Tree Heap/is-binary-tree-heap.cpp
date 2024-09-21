//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User Function template for C++

// Structure of node
/*struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution 
{
  public:
  bool maxorder(Node* root)
  {
      //If it's left and right is NULL means single node is there and single node is CBT.(TRUE)
      if(root->left==NULL && root->right==NULL)
         return 1;
      //If it's left exist and right not check root->data>root->left->data if true return it 
      else if(root->right==NULL)
         return root->data>root->left->data;
      //If it's left and right is not NULL check root->left and root->right and data of both left and right is greater
      else
         return maxorder(root->left)&&maxorder(root->right)&&root->data>root->left->data&&root->data>root->right->data;
  }
  bool isCBT(Node* root,int i,int size)
  {
      //If root is NULL return true
      if(root==NULL)
         return 1;
      //If size is lesser than the index value means that there is some node exist which is not following CBT properity        
      else if(i>=size)
         return 0;
      //check for both left and right      
      else
          return isCBT(root->left,2*i+1,size)&&isCBT(root->right,2*i+2,size);
  }
  int count(Node* root)
  {
      if(root==NULL)
         return 0;
      return 1+count(root->left)+count(root->right);
  }
  bool isHeap(struct Node* root) 
  {
      int size=count(root);
      return isCBT(root,0,size)&&maxorder(root);
  }
};

//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Solution ob;
        Node *root = buildTree(treeString);
        if (ob.isHeap(root))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
// } Driver Code Ends