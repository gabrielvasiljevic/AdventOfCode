#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

std::vector<char> programs;

void spin(unsigned a_size){
    while(a_size--){
        programs.insert(programs.begin(), *(programs.end() - 1));
        programs.pop_back();
    }
}

void exchange(unsigned x, unsigned y){
    swap(programs[x], programs[y]);
}

void partner(char x, char y){
    auto posA = std::find(programs.begin(), programs.end(), x);
    auto posB = std::find(programs.begin(), programs.end(), y);

    swap(*posA, *posB);
}

int main(){

    for(char i = 'a'; i <= 'p'; i++){
        programs.push_back(i);
    }

    string input;

    while(getline(cin, input, ',')){
        istringstream iss(input);

        char command;
        iss >> command;

        switch(command){
            case 's': {
                unsigned a_size;
                iss >> a_size;

                spin(a_size);

            } break;

            case 'x': {
                unsigned x, y;
                char slash;
                iss >> x >> slash >> y;

                exchange(x, y);

            } break;

            case 'p': {
                char x, y, slash;
                iss >> x >> slash >> y;

                partner(x, y);

            } break;
        }
    }

    for(auto& program : programs){
        cout << program << " ";
    }
    cout << endl;

    return 0;
}
