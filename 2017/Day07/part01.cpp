#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

struct Node{
    int weight = 0;
    string name;

    Node* parent = nullptr;
    vector<Node*> children;
};

int main(){

    string input;
    map<string, Node> tree;

    while(getline(cin, input)){
        istringstream iss(input);

        string name;
        int weight;
        char parenthesis;

        iss >> name >> parenthesis >> weight >> parenthesis;

        tree[name].weight = weight;
        tree[name].name = name;

        vector<Node*> children;
        if(iss.peek() != EOF){
            string arrow; iss >> arrow;
            string childName;

            while(iss >> childName){
                Node newChildNode;

                if(childName[childName.size() - 1] == ',')
                    childName.pop_back();

                tree[childName].name = childName;
                tree[childName].parent = &tree[name];

                children.push_back(&tree[childName]);
            }
        }

        tree[name].children = children;
    }

    string bottom = tree.begin()->first;

    while(tree[bottom].parent != nullptr){
        bottom = tree[bottom].parent->name;
    }

    debug(bottom);

    return 0;
}
