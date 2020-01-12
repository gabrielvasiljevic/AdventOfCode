#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    vector<int> instructions;

    cin >> input;
    stringstream ss(input);
    int value;
    char comma;
    while(ss >> value >> comma){
        instructions.push_back(value);
    }


    instructions[1] = 12;
    instructions[2] = 2;

    unsigned position = 0;

    while(instructions.at(position) != 99){
        switch(instructions.at(position)){
            case 1:
                instructions.at(instructions.at(position+3)) = instructions.at(instructions.at(position+1)) + instructions.at(instructions.at(position+2));
            break;

            case 2:
                instructions.at(instructions.at(position+3)) = instructions.at(instructions.at(position+1))*instructions.at(instructions.at(position+2));
            break;

        }

        position += 4;
    }

    debug(instructions.at(0));

    return 0;
}
