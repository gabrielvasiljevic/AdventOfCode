#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    vector<string> grid;
    int posX = -1, posY;
    char direction = 'D';
    char currentChar = '|';
    int steps = 0;
    string input;

    while(getline(cin, input)){
        grid.push_back(input);
    }

    posY = 0;

    while(grid[0][++posX] != '|');

    while(currentChar != ' '){
        switch(direction){
            case 'D': posY++; break;
            case 'U': posY--; break;
            case 'L': posX--; break;
            case 'R': posX++; break;
        }

        steps++;

        currentChar = grid[posY][posX];

        if(currentChar == '+'){
            if(direction == 'U' or direction == 'D'){
                direction = (grid[posY][posX - 1] == ' ')? 'R' : 'L';
            }
            else{
                direction = (grid[posY - 1][posX] == ' ')? 'D' : 'U';
            }
        }

    }

    debug(steps);

    return 0;
}
