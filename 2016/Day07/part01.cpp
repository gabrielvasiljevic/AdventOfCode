#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

template<typename T>
bool isABBA(const deque<T>& buffer){
    return  (buffer[0] == buffer[3]) and
            (buffer[1] == buffer[2]);
}

int main(){

    string input;
    unsigned counter = 0;

    while(cin >> input){

        deque<char> buffer;
        bool hypernet = false;
        bool supportsTLS = false;

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
                if(buffer.size() < 4){
                    buffer.push_back(input[i]);
                    continue;
                }
                else{
                    buffer.push_back(input[i]);
                    buffer.pop_front();
                }

                if(isABBA(buffer)){
                    if(hypernet){
                        supportsTLS = false;
                        break;
                    }
                    else{
                        supportsTLS = true;
                    }
                }
            }
        }

        if(supportsTLS){
            counter++;
        }
    }

    cout << counter << endl;

    return 0;
}
