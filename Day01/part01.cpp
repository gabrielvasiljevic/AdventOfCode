#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

enum dirs{UP = 0, RIGHT, DOWN, LEFT};

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

    while(cin >> input){
        char dir = input[0];
        unsigned moves = toInt(input);

        if(dir == 'R') currentDir++;
        else currentDir--;

        if(currentDir < 0) currentDir = LEFT;
        else currentDir %= 4;

        switch(currentDir){
            case UP:
                y += moves;
            break;
            case DOWN:
                y -= moves;
            break;
            case LEFT:
                x -= moves;
            break;
            case RIGHT:
                x += moves;
            break;
        }

    }

    cout << abs(x) + abs(y) << endl;
    return 0;
}
