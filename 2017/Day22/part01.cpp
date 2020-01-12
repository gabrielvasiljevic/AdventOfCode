#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

struct Position{
    unsigned x;
    unsigned y;
};

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction;

void changeLeft(){
    switch(direction){
        case UP:
            direction = LEFT;
        break;
        case LEFT:
            direction = DOWN;
        break;
        case DOWN:
            direction = RIGHT;
        break;
        case RIGHT:
            direction = UP;
        break;
    }
}

void changeRight(){
    switch(direction){
        case UP:
            direction = RIGHT;
        break;
        case RIGHT:
            direction = DOWN;
        break;
        case DOWN:
            direction = LEFT;
        break;
        case LEFT:
            direction = UP;
        break;
    }
}

void moveForward(Position& currentPos){
    switch(direction){
        case UP:
            currentPos.y++;
        break;
        case RIGHT:
            currentPos.x++;
        break;
        case DOWN:
            currentPos.y--;
        break;
        case LEFT:
            currentPos.y--;
        break;
    }
}

int main(){

    string input;
    vector<vector<bool>> cluster;
    direction = UP;

    while(getline(cin, input)){
        vector<bool> line;

        for(auto& node : input){
            node == '#'? line.push_back(true) : line.push_back(false);
        }

        cluster.push_back(line);
    }

    Position virusPosition = {cluster.size()/2, cluster.size()/2};

    unsigned bursts = 0;

    for(int i = 0; i < 10000; i++){
        if(cluster[virusPosition.y][virusPosition.x]){
            changeRight();
            cluster[virusPosition.y][virusPosition.x] = false;
        }
        else{
            changeLeft();
            cluster[virusPosition.y][virusPosition.x] = true;
            bursts++;
        }

        moveForward(virusPosition);
    }

    debug(bursts);

    return 0;
}
