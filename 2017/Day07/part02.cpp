#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;


struct Node{
    int weight = 0;
    string name;

    Node* parent = nullptr;
    vector<Node*> children;

    int getTotalWeight(){
        int totalWeight = weight;

        for(auto& child : children){
            totalWeight += child->getTotalWeight();
        }

        return totalWeight;
    }
};


string findUnbalanced(Node root){
    vector<Node*> children = root.children;

    while(children.size() > 1){
        bool repeated = false;
        int i;

        for(i = 1; i < children.size() && !repeated; i++){
            if(children[i]->getTotalWeight() == children[0]->getTotalWeight()){
                repeated = true;
            }
        }

        if(repeated){
            children.erase(children.begin() + i - 1);
            children.erase(children.begin());
        }
        else break;
    }


    if(children.size() > 0){
        return findUnbalanced(*children[0]);
    }
    else{
        return root.name;
    }
}

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

    string unbalanced = findUnbalanced(tree[bottom]);

    debug(unbalanced);
    int correctWeight;

    for(auto& sibling : tree[unbalanced].parent->children){
        if(sibling->getTotalWeight() != tree[unbalanced].getTotalWeight()){
            correctWeight = sibling->getTotalWeight();
        }
    }

    cout << "Corrected weight: " << tree[unbalanced].weight - (tree[unbalanced].getTotalWeight() - correctWeight) << endl;

    return 0;
}
