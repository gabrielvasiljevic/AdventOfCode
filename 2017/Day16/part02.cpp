#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

string programs;

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

    string input, moves;
    map<string, int> repetitions;

    cin >> input;

    for(int i = 1; i <= 1'000'000'000; i++){
        stringstream ss (input);

        while(getline(ss, moves, ',')){
            istringstream iss(moves);

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
        if(repetitions.count(programs)){
            if((1'000'000'000 - i)%(i - repetitions[programs]) == 0){
                cout << programs << endl;

                break;
            }
        }

        repetitions[programs] = i;
    }

    return 0;
}
