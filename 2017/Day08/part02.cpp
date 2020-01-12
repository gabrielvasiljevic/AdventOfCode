#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

map<string, int> registers;

bool evaluateCondition(string registerName, string condition, string value){
    int convertedValue;
    istringstream iss(value);
    iss >> convertedValue;

    if(condition == ">"){
        return registers[registerName] > convertedValue;
    }
    if(condition == "<"){
        return registers[registerName] < convertedValue;
    }
    if(condition == ">="){
        return registers[registerName] >= convertedValue;
    }
    if(condition == "<="){
        return registers[registerName] <= convertedValue;
    }
    if(condition == "=="){
        return registers[registerName] == convertedValue;
    }
    if(condition == "!="){
        return registers[registerName] != convertedValue;
    }
}

void modifyValue(string destRegister, string instruction, string value){
    int convertedValue;
    istringstream iss(value);
    iss >> convertedValue;

    if(instruction == "inc"){
        registers[destRegister] += convertedValue;
    }
    else if(instruction == "dec"){
        registers[destRegister] -= convertedValue;
    }

    return;
}

int main(){

    string input;

    int highest = 0;

    while(getline(cin, input)){
        istringstream iss(input);
        string destRegister, instruction, amount,
               ifStr,
               condRegister, condition, condValue;

        iss >> destRegister >> instruction >> amount
            >> ifStr >> condRegister >> condition >> condValue;

        if(evaluateCondition(condRegister, condition, condValue)){
            modifyValue(destRegister, instruction, amount);

            if(registers[destRegister] > highest){
                highest = registers[destRegister];
            }
        }
    }

    debug(highest);

    return 0;
}
