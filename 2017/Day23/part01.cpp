#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

std::map<string, long long> registers;

long long extractValue(string value){
    if(registers.find(value) != registers.end()){
        return registers[value];
    }

    stringstream ss(value);
    long long  result;
    ss >> result;

    return result;
}

int main(){

    string input;

    std::vector<string> instructions;
    int ip = 0, timesMul = 0;

    while(getline(cin, input)){
        instructions.push_back(input);
    }

    while(ip >= 0 && ip < instructions.size()){

        istringstream iss(instructions[ip]);

        string instruction, reg, value;

        iss >> instruction;

        if(instruction == "set"){
            iss >> reg >> value;
            registers[reg] = extractValue(value);
        }
        else if(instruction == "sub"){
            iss >> reg >> value;
            registers[reg] -= extractValue(value);
        }
        else if(instruction == "mul"){
            iss >> reg >> value;
            registers[reg] *= extractValue(value);
            timesMul++;
        }
        else if(instruction == "jnz"){
            int offset;
            iss >> value >> offset;

            if(extractValue(value) != 0){
                ip += offset;
                continue;
            }
        }

        ip++;
    }

    debug(timesMul);

    return 0;
}
