#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    vector<string> grid;
    int posX = -1, posY;
    char direction = 'D';
    char currentChar = '|';
    string result = "";
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

        currentChar = grid[posY][posX];

        if(currentChar == '+'){
            if(direction == 'U' or direction == 'D'){
                direction = (grid[posY][posX - 1] == ' ')? 'R' : 'L';
            }
            else{
                direction = (grid[posY - 1][posX] == ' ')? 'D' : 'U';
            }
        }
        else if(currentChar != '|' and currentChar != '-'){
            result.push_back(currentChar);
        }

    }

    debug(result);

    return 0;
}
