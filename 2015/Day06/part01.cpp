#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

bool grid[1000][1000] = {{false}};

void turnOn(int xi, int yi, int xf, int yf){
    for(int i = xi; i <= xf; i++){
        for(int j = yi; j <= yf; j++){
            grid[i][j] = true;
        }
    }
}

void turnOff(int xi, int yi, int xf, int yf){
    for(int i = xi; i <= xf; i++){
        for(int j = yi; j <= yf; j++){
            grid[i][j] = false;
        }
    }
}

void toggle(int xi, int yi, int xf, int yf){
    for(int i = xi; i <= xf; i++){
        for(int j = yi; j <= yf; j++){
            grid[i][j] = !grid[i][j];
        }
    }
}

int main(){

    string input;
    int lits = 0;

    while(getline(cin, input)){
        istringstream iss(input);

        string instruction, onOff;
        iss >> instruction;

        if(instruction == "turn"){
            iss >> onOff;
        }

        int xi, yi, xf, yf;
        char comma;
        string through;

        iss >> xi >> comma   >> yi
                  >> through >>
               xf >> comma   >> yf;

        if(instruction == "toggle"){
            toggle(xi, yi, xf, yf);
        }
        else{
            if(onOff == "on"){
                turnOn(xi, yi, xf, yf);
            }
            else{
                turnOff(xi, yi, xf, yf);
            }
        }
    }

    for(int i = 0; i < 1000; i++){
        for(int j = 0; j < 1000; j++){
            if(grid[i][j]) lits++;
        }
    }

    debug(lits);

    return 0;
}
