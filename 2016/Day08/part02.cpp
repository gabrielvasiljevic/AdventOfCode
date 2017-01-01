#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

const unsigned WIDTH = 50;
const unsigned HEIGHT = 6;

bool screen[HEIGHT][WIDTH] = {false};

void printScreen(){
    int i, j;

    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            if(screen[i][j]){
                cout << "#";
            }
            else cout << " ";
        }
        cout << endl;
    }

    return;
}

void turnON(const unsigned& width, const unsigned& height){
    unsigned i, j;

    for(i = 0; i < height; i++){
        for(j = 0; j < width; j++){
            screen[i][j] = true;
        }
    }

    return;
}

void rotateRow(const unsigned& row, const unsigned& pixels){

    bool buffer[WIDTH];

    for(unsigned i = 0; i < WIDTH; i++){
        buffer[i] = screen[row][i];
    }

    for(unsigned i = 0; i < WIDTH; i++){
        screen[row][(i + pixels)%WIDTH] = buffer[i];
    }

    return;
}

void rotateColumn(const unsigned& column, const unsigned& pixels){

    bool buffer[HEIGHT];

    for(unsigned i = 0; i < HEIGHT; i++){
        buffer[i] = screen[i][column];
    }

    for(unsigned i = 0; i < HEIGHT; i++){
        screen[(i + pixels)%HEIGHT][column] = buffer[i];
    }

    return;
}

unsigned countLitPixels(){
    unsigned i, j, result = 0;

    for(i = 0; i < HEIGHT; i++){
        for(j = 0; j < WIDTH; j++){
            if(screen[i][j]){
                result++;
            }
        }
    }

    return result;
}

int main(){

    string input;

    while(getline(cin, input)){
        stringstream ss(input);
        string operation;

        ss >> operation;

        if(operation == "rect"){
            unsigned h, w;
            char x;
            ss >> w >> x >> h;
            turnON(w, h);
        }
        else if(operation == "rotate"){
            string direction, by;
            unsigned pixels, pos;
            char positionXY, equals;

            ss >> direction >> positionXY >> equals >> pos >> by >> pixels;

            if(direction == "row"){
                rotateRow(pos, pixels);
            }
            else{
                rotateColumn(pos, pixels);
            }
        }
    }

    printScreen();

    return 0;
}
