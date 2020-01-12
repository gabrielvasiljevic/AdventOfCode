#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    cin >> input;

    int n = input.size();

    pair<int, int> position;
    set<pair<int, int>> path;

    path.insert(make_pair(0, 0));
    for(auto& c : input){
        switch(c){
            case '<':
                position.first--;
            break;
            case '^':
                position.second++;
            break;
            case '>':
                position.first++;
            break;
            case 'v':
                position.second--;
            break;
        }
        path.insert(position);
    }

    cout << path.size() << endl;
    return 0;
}
