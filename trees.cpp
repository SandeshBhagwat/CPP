/*  Name : Sandesh Prakash Bhagwat
    Branch : AI&DS
    Div : A
    Roll No : 13
    PRN : 12110367

    ADS Assignment 5: Trees
            A. Recursive
                1.Inorder Tree Traversal
                2.Preorder Tree Traversal
                3.Postorder Tree Traversal
            B. Non Recursive
                1.Inorder
                2.Preorder
                3.ostorder
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildBST(Node *root, int data)
{

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (data > root->data)
    {
        root->right = buildBST(root->right, data);
    }
    else
    {
        root->left = buildBST(root->left, data);
    }
    return root;
}

void buildBTree(Node *root, int val, int size)
{
    if (size == 0 || root == NULL)
        return;
    size--;
    cout << "Enter left of " << root->data << endl;
    int data;
    cin >> data;
    Node *newNode;
    if (data != -1)
        newNode = new Node(data);
    else
        newNode = NULL;
    root->left = newNode;
    buildBTree(newNode, data, size);

    size--;
    cout << "Enter right of " << root->data << endl;
    cin >> data;
    if (data != -1)
        newNode = new Node(data);
    else
        newNode = NULL;
    root->right = newNode;
    buildBTree(newNode, data, size);
}
// 11 1 6 11 8 16 -1 -1 17 -1 3 -1 -1 -1 12 -1 -1 7 9 21 -1 -1 -1 -1
void levelOrder(Node *root)
{
    queue<Node *> q;
    if (root == NULL)
        return;
    else if (root->data == -1)
        return;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void inOrder2(Node *root)
{
    stack<Node *> s;
    if (root == NULL)
        return;
    Node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preOrder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void preOrder2(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void postOrder2(Node *root)
{
    if (root == NULL)
        return;
    stack<Node *> s;
    Node *temp = root;
    while (true)
    {
        while (temp)
        {
            s.push(temp);
            s.push(temp);
            temp = temp->left;
        }
        if (s.empty())
            return;
        temp = s.top();
        s.pop();
        if (!s.empty() && s.top() == temp)
        {
            temp = temp->right;
        }
        else
        {
            cout << temp->data << " ";
            temp = NULL;
        }
    }
}

int height(Node *root)
{
    if (root == NULL)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

void solve(Node *root, int l, int r, int lvl, vector<vector<string>> &ans)
{
    if (root == NULL)
        return;
    if (lvl == ans.size())
        return;

    int mid = (l + r) / 2;
    ans[lvl][mid] = to_string(root->data);
    solve(root->left, l, mid - 1, lvl + 1, ans);
    solve(root->right, mid + 1, r, lvl + 1, ans);
}

vector<vector<string>> printTree(Node *root)
{
    if (root == nullptr)
        return {};
    int h = height(root);
    int w = pow(2, h) - 1;
    vector<vector<string>> ans(h, vector<string>(w, "  "));
    solve(root, 0, w - 1, 0, ans);
    return ans;
}

Node *build()
{
    cout << "\n===========================================================\n";
    cout << "Select type of tree: \n";
    cout << "1.Binary Tree.\n2.Binary Search Tree.\n3.Exit\n\n";
    int t;
    cin >> t;
    switch (t)
    {
    case 1:
    {
        cout << "Enter size of tree: ";
        int size;
        cin >> size;
        size = 2 * size + 1;
        cout << "Enter data for root node: ";
        int data;
        cin >> data;
        Node *root = new Node(data);
        buildBTree(root, data, size);
        return root;
    }

    case 2:
    {
        cout << "Enter the size of BST: ";
        int n;
        cin >> n;
        int data;
        cout << "Enter data of root of BST: ";
        cin >> data;
        Node *root = new Node(data);
        Node *newRoot = root;
        n--;
        while (n--)
        {
            int data;
            cout << "Enter data to insert into BST: ";
            cin >> data;
            newRoot = buildBST(newRoot, data);
        }
        return root;
        break;
    }

    case 3:
    {
        return NULL;
    }

    default:
    {
        cout << "Invalid Operation\n";
        build();
    }
    }
    return NULL;
}

void recursiveTraversal(Node *root)
{
    cout << "\n===========================================================\n";
    cout << "Select traversal type: \n";
    cout << "1.InOrder.\n2.PreOrder.\n3.PostOrder.\n4.Exit\n\n";
    int t;
    cin >> t;
    switch (t)
    {
    case 1:
    {
        cout << "Inorder traversal with recursion: ";
        inOrder(root);
        cout << endl;
        recursiveTraversal(root);
        break;
    }

    case 2:
    {
        cout << "Preorder traversal with recursion: ";
        preOrder(root);
        cout << endl;
        recursiveTraversal(root);
        break;
    }

    case 3:
    {
        cout << "Postorder traversal with recursion: ";
        postOrder(root);
        cout << endl;
        recursiveTraversal(root);
        break;
    }

    case 4:
        return;

    default:
        cout << "Invalid choice!!!\n";
        recursiveTraversal(root);
    }
}

void nonRecursiveTraversal(Node *root)
{
    cout << "\n===========================================================\n";
    cout << "Select traversal type: \n";
    cout << "1.InOrder.\n2.PreOrder.\n3.PostOrder\n4.Exit\n\n";
    int t;
    cin >> t;
    switch (t)
    {
    case 1:
    {
        cout << "Inorder traversal with recursion: ";
        inOrder2(root);
        cout << endl;
        nonRecursiveTraversal(root);
        break;
    }

    case 2:
    {
        cout << "Preorder traversal with recursion: ";
        preOrder2(root);
        cout << endl;
        nonRecursiveTraversal(root);
        break;
    }

    case 3:
    {
        cout << "Postorder traversal with recursion: ";
        postOrder2(root);
        cout << endl;
        nonRecursiveTraversal(root);
        break;
    }

    case 4:
        return;

    default:
        cout << "Invalid choice!!!\n";
        recursiveTraversal(root);
    }
}

void traverse(Node *root)
{
    cout << "\n===========================================================\n";
    cout << "Enter your choice: \n";
    cout << "1.Recursive.\n2.Non-recursive.\n3.Exit\n\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        recursiveTraversal(root);
        traverse(root);
        break;
    }

    case 2:
    {
        nonRecursiveTraversal(root);
        traverse(root);
        break;
    }

    case 3:
        return;

    default:
        cout << "Invalid choice\n";
        traverse(root);
    }
}

Node* mirrorImage(Node *root)
{
    if (!root)
        return NULL;
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirrorImage(root->left);
    mirrorImage(root->right);
    return root;
}

void noOfNodes(Node *root, int &count)
{
    if (root == NULL)
        return;
    noOfNodes(root->left, count);
    count++;
    noOfNodes(root->right, count);
}
void ops(Node *root)
{
    cout << "\n===========================================================\n";
    cout << "Enter your choice: \n";
    cout << "1.Build Tree.\n2.Traverse a tree.\n3.Height of BST.\n4.Mirror Image of BST\n5.Number of Nodes\n6.Exit\n\n";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        Node *newRoot = build();
        cout << "\nEntered tree is : \n";
        levelOrder(newRoot);
        cout << endl;
        cout << endl;
        cout << "Tree representation: \n";
        vector<vector<string>> v = printTree(newRoot);
        for (auto &i : v)
        {
            for (auto &j : i)
            {
                cout << j; // 9 8 3 10 1 6 14 13 7 6
            }
            cout << endl;
            cout << endl;
        }
        cout << endl;
        ops(newRoot);
        break;
    }

    case 2:
        traverse(root);
        ops(root);
        break;

    case 3:
        cout << "Maximum height of given tree is: " << height(root) << endl;
        ops(root);
        break;

    case 4:
    {
        cout << "Mirror image of BST: \n";
        Node *mirrorRoot = mirrorImage(root);
        vector<vector<string>> v = printTree(mirrorRoot);
        for (auto &i : v)
        {
            for (auto &j : i)
            {
                cout << j; // 9 8 3 10 1 6 14 13 7 6
            }
            cout << endl;
            cout << endl;
        }
        cout << endl;
        ops(root);
        break;
    }

    case 5:
    {
        int count = 0;
        noOfNodes(root, count);
        cout << "Number of nodes in BST :" << count << endl;
        ops(root);
        break;
    }

    case 6:
        return;
    }
}

int main()
{
    Node *root = NULL;
    ops(root);
    return 0;
}
