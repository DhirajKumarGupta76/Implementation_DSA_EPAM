#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;

        Node(char c, int d) {
            ch = c;
            freq = d;
            left = NULL;
            right = NULL;
        }
    };

    struct cmp {
        bool operator()(Node* a, Node* b) {
            return a->freq > b->freq;
        }
    };

    void traverse(Node* root, string code, vector<string>& ans) {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL) {
            ans.push_back(code);
            return;
        }

        traverse(root->left, code + '0', ans);
        traverse(root->right, code + '1', ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {

        priority_queue<Node*, vector<Node*>, cmp> pq;

        for (int i = 0; i < s.size(); i++) {
            pq.push(new Node(s[i], f[i]));
        }

        while (pq.size() > 1) {

            Node* left = pq.top();
            pq.pop();

            Node* right = pq.top();
            pq.pop();

            Node* parent = new Node('$', left->freq + right->freq);

            parent->left = left;
            parent->right = right;

            pq.push(parent);
        }

        Node* root = pq.top();

        vector<string> ans;
        traverse(root, "", ans);

        return ans;
    }
};

int main() {

    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    Solution obj;   // Create object

    vector<string> codes = obj.huffmanCodes(s, freq);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " : " << codes[i] << endl;
    }

    return 0;
}

