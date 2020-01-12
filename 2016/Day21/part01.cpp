#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

string password = "abcdefgh";

void swapPosition(int X, int Y){
    char aux = password[X];
    password[X] = password[Y];
    password[Y] = aux;
}

void swapLetter(char X, char Y){
    int posX = password.find(X);
    int posY = password.find(Y);

    password[posX] = Y;
    password[posY] = X;
}

void rotateRight(int steps){
    int n = password.size();
    steps %= n;

    reverse(password.begin(), password.end());
    reverse(password.begin(), password.begin() + steps);
    reverse(password.begin() + steps, password.end());
}

void rotateLeft(int steps){
    while(steps--)
        std::rotate(password.begin(), password.begin() + 1, password.end());
}

void rotateByPosition(char X){
    int posX = password.find(X);

    rotateRight(1);
    rotateRight(posX);
    if(posX >= 4)
        rotateRight(1);
}

void reversePositions(int X, int Y){
    for(; X < Y; X++, Y--){
        swapPosition(X, Y);
    }
}

void movePosition(int X, int Y){
    char letter = password[X];
    password.erase(X, 1);
    password.insert(Y, 1, letter);
}

int main(){

    string input;

    while(getline(cin, input)){
        istringstream iss(input);

        string instruction, aux;

        iss >> instruction;

        if(instruction == "swap"){

            string whichSwap;
            iss >> whichSwap;

            if(whichSwap == "position"){
                int X, Y;
                iss >> X >> aux >> aux >> Y;
                     //X    with position Y
                swapPosition(X, Y);
            }
            else if(whichSwap == "letter"){
                char X, Y;
                iss >> X >> aux >> aux >> Y;
                     //X    with  letter  Y
                swapLetter(X, Y);
            }

        }
        else if(instruction == "rotate"){
            string whichRotate;
            iss >> whichRotate;

            if(whichRotate == "left"){
                int steps;
                iss >> steps;
                rotateLeft(steps);
            }
            else if(whichRotate == "right"){
                int steps;
                iss >> steps;
                rotateRight(steps);
            }
            else{
                char letter;
                iss >> aux >> aux >> aux >> aux >> letter;
                rotateByPosition(letter);
            }
        }
        else if(instruction == "reverse"){
            int X, Y;
            iss >> aux >> X >> aux >> Y;
              //positions X  through  Y
            reversePositions(X, Y);
        }
        else if(instruction == "move"){
            int X, Y;
            iss >> aux >> X >> aux >> aux >> Y;
               //position X    to  position  Y
            movePosition(X, Y);
        }

    }

    debug(password);

    return 0;
}
