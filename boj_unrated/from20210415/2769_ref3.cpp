#include<bits/stdc++.h>


using namespace std;

inline bool is_variable(char c);
inline bool is_binary_op(char c);
inline bool is_valid_char(char c);

struct Node {
    char op;
    int pre;
    Node *left, *right, *parent;
    
    Node(char c) : op(c), left(nullptr), right(nullptr), parent(nullptr) {
        switch (c) {
            case '(': case ')': this->pre = 1; break;
            case '|': this->pre = 2; break;
            case '^': this->pre = 3; break;
            case '&': this->pre = 4; break;
            case '~': this->pre = 5; break;
            default: this->pre = 6;
        }
    }
    ~Node() {
        if (this->left != nullptr)
            delete this->left;
        if (this->right != nullptr)
            delete this->right;
    }
};

struct LogicalExpr {
    Node *root;
    map<char, bool> variables;     // pairs of variable name and its value

    LogicalExpr(string s, int &idx) {
        Node *cur;
        this->root = cur = new Node('(');

        for (int i = 0; i < (int)s.size(); i++) {
            if (!is_valid_char(s[i]))
                continue;

            Node *new_node = new Node(s[i]);

            if (s[i] == ')') {
                while (cur->op != '(')
                    cur = cur->parent;
                cur->parent->right = cur->right;
                cur->right->parent = cur->parent;
                cur->right = nullptr;
                Node *tmp = cur->parent;
                delete cur;
                cur = tmp;
                continue;
            }

            if (s[i] != '(' && s[i] != '~')
                while (cur->pre >= new_node->pre)
                    cur = cur->parent;

            if (is_variable(cur->op)
                || ((s[i] == '(' || s[i] == '~' || is_variable(s[i])) && cur->right != nullptr)) {
                idx = i;
                delete new_node;
                break;
            }

            new_node->left = cur->right;
            if (cur->right != nullptr)
                cur->right->parent = new_node;
            cur->right = new_node;
            new_node->parent = cur;
            cur = new_node;

            if (is_variable(s[i]))
                this->variables[s[i]] = true;
        }
        this->root = this->root->right;
        this->root->parent->right = nullptr;
        delete this->root->parent;
    }
    ~LogicalExpr() {
        if (root != nullptr)
            delete root;
    }

    bool eval_node(Node *node) {
        if (is_variable(node->op))
            return variables[node->op];
        switch (node->op) {
            case '|': return (eval_node(node->left) || eval_node(node->right));
            case '^': return (eval_node(node->left) != eval_node(node->right));
            case '&': return (eval_node(node->left) && eval_node(node->right));
        }
        return !eval_node(node->right);
    }
    bool eval(vector<bool> var_val) {
        auto it = this->variables.begin();
        for (int i = 0; it != this->variables.end(); i++, it++)
            it->second = var_val[i];
        return eval_node(this->root);
    }

    bool operator==(LogicalExpr &other) {
        if (this->variables.size() != other.variables.size())
            return false;
        auto it1 = this->variables.begin(), it2 = other.variables.begin();
        for (; it1 != this->variables.end(); it1++, it2++)
            if (it1->first != it2->first)
                return false;

        unsigned num_var = this->variables.size();
        for (unsigned i = 0; i < (1u << num_var); i++) {
            unsigned tmp = i;
            vector<bool> var_val;
            for (unsigned j = 0; j < num_var; j++) {
                var_val.push_back(tmp % 2 == 1);
                tmp /= 2;
            }
            if (this->eval(var_val) != other.eval(var_val))
                return false;
        }

        return true;
    }
};

inline bool is_variable(char c) {
    return ('a' <= c && c <= 'z');
}

inline bool is_binary_op(char c) {
    return (c == '|' || c == '&' || c == '^');
}

inline bool is_valid_char(char c) {
    return (is_variable(c) || is_binary_op(c) || c == '~' || c == '(' || c == ')');
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(1);

    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin, s);

        int idx;
        LogicalExpr le1(s, idx);
        LogicalExpr le2(s.substr(idx), idx);

        cout << "Data set " << i << ": ";
        cout << (le1 == le2? "Equivalent" : "Different") << '\n';
    }

    return 0;
}