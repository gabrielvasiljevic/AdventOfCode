#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    cin >> input;

    int n = input.size();

    pair<int, int> position;
    pair<int, int> robotPosition;
    set<pair<int, int>> path;
    bool robotTurn = false;

    path.insert(make_pair(0, 0));
    for(auto& c : input){
        switch(c){
            case '<':
                robotTurn ? robotPosition.first-- : position.first--;
            break;
            case '^':
                robotTurn ? robotPosition.second++ : position.second++;
            break;
            case '>':
                robotTurn ? robotPosition.first++ : position.first++;
            break;
            case 'v':
                robotTurn ? robotPosition.second-- : position.second--;
            break;
        }
        robotTurn ? path.insert(robotPosition) : path.insert(position);
        robotTurn = !robotTurn;
    }

    cout << path.size() << endl;
    return 0;
}
