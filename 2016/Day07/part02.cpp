#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

template<typename T>
bool isABA(const deque<T>& buffer){
    return  (buffer[0] == buffer[2]) and
            (buffer[0] != buffer[1]);
}

string toString(const deque<char>& buffer){
    string result = "";
    for(auto& c : buffer){
        result += c;
    }
    return result;
}


int main(){

    string input;
    unsigned counter = 0;

    while(cin >> input){

        deque<char> buffer;
        vector<string> ABAs;
        vector<string> BABs;
        bool hypernet = false;
        bool supportsSSL = false;

        for(size_t i = 0, lenght = input.size(); i < lenght; i++){

            if(input[i] == '['){
                hypernet = true;
                while(not buffer.empty()) buffer.pop_front();
            }
            else if(input[i] == ']'){
                hypernet = false;
                while(not buffer.empty()) buffer.pop_front();
            }
            else{
                if(buffer.size() < 3){
                    buffer.push_back(input[i]);
                }
                else{
                    buffer.push_back(input[i]);
                    buffer.pop_front();
                }

                if(isABA(buffer)){
                    if(hypernet){
                        BABs.push_back(toString(buffer));
                    }
                    else{
                        ABAs.push_back(toString(buffer));
                    }
                }
            }
        }

        for(auto& bab : BABs){
            for(auto& aba : ABAs){
                if(aba[0] == bab[1] and aba[1] == bab[0]){
                    supportsSSL = true;
                }
            }
        }

        if(supportsSSL){
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
