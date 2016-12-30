#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

enum dirs{UP = 0, RIGHT, DOWN, LEFT};

struct position{
    int x;
    int y;
};

unsigned toInt(string word){
    string number = "";
    unsigned result;

    for(int i = 1; i < word.size() && word[i] != ','; i++){
        number += word[i];
    }

    stringstream ss(number);
    ss >> result;

    return result;
}

int main(){

    string input;

    char previousDir;
    int x, y;
    x = y = 0;
    int currentDir = UP;
    vector<position> visited;
    bool found = false;

    while(cin >> input && not found){
        char dir = input[0];
        unsigned moves = toInt(input);

        if(dir == 'R') currentDir++;
        else currentDir--;

        if(currentDir < 0) currentDir = LEFT;
        else currentDir %= 4;

        while(moves-- && not found){
            switch(currentDir){
                case UP:
                    y++;
                break;
                case DOWN:
                    y--;
                break;
                case LEFT:
                    x--;
                break;
                case RIGHT:
                    x++;
                break;
            }

            position currentPosition{x, y};
            for(auto& pos : visited){
                if (pos.x == x and pos.y == y){
                    cout << abs(x) + abs(y) << endl;
                    found = true;
                }
            }
            visited.push_back(currentPosition);
        }

    }


    return 0;
}
