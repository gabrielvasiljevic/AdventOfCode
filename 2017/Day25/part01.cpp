#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

std::vector<unsigned> tape;
long long currentPosition = 0;
char currentState = 'A';
unsigned steps = 12'629'077;

void stateA(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 1;
        currentPosition++;
        currentState = 'B';
    }
    else{
        tape[currentPosition] = 0;
        currentPosition--;
        currentState = 'B';
    }
}

void stateB(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 0;
        currentPosition++;
        currentState = 'C';
    }
    else{
        tape[currentPosition] = 1;
        currentPosition--;
        currentState = 'B';
    }
}

void stateC(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 1;
        currentPosition++;
        currentState = 'D';
    }
    else{
        tape[currentPosition] = 0;
        currentPosition--;
        currentState = 'A';
    }
}

void stateD(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 1;
        currentPosition--;
        currentState = 'E';
    }
    else{
        tape[currentPosition] = 1;
        currentPosition--;
        currentState = 'F';
    }
}

void stateE(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 1;
        currentPosition--;
        currentState = 'A';
    }
    else{
        tape[currentPosition] = 0;
        currentPosition--;
        currentState = 'D';
    }
}

void stateF(){
    if(tape[currentPosition] == 0){
        tape[currentPosition] = 1;
        currentPosition++;
        currentState = 'A';
    }
    else{
        tape[currentPosition] = 1;
        currentPosition--;
        currentState = 'E';
    }
}

int main(){

    int checksum = 0;

    while(steps--){
        if(currentPosition < 0){
            tape.insert(tape.begin(), 0);
            currentPosition++;
        }
        else if(currentPosition >= tape.size()){
            tape.push_back(0);
        }

        switch(currentState){
            case 'A': stateA(); break;
            case 'B': stateB(); break;
            case 'C': stateC(); break;
            case 'D': stateD(); break;
            case 'E': stateE(); break;
            case 'F': stateF(); break;
        }
    }

    for(auto& n : tape){
        if(n) checksum++;
    }

    debug(checksum);

    return 0;
}
