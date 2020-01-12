#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

unsigned compute(vector<unsigned> instructions, unsigned noun, unsigned verb){
    instructions[1] = noun;
    instructions[2] = verb;

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

    return instructions.at(0);
}

std::pair<unsigned, unsigned> findAnswer(vector<unsigned> instructions){
    for(int i = 0; i <= 99; i++){
        for(int j = 0; j <= 99; j++){
            if(compute(instructions, i, j) == 19690720){
                return make_pair(i, j);
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    vector<unsigned> instructions;

    unsigned noun, verb;

    cin >> input;
    stringstream ss(input);
    unsigned value;
    char comma;
    while(ss >> value >> comma){
        instructions.push_back(value);
    }

    pair<unsigned, unsigned> answer = findAnswer(instructions);
    noun = answer.first;
    verb = answer.second;
    debug(100*noun + verb);

    return 0;
}
