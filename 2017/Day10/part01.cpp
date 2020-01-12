#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    vector<int> lengths;

    char comma;
    string input;
    int x;

    cin >> input;
    for(auto& c : input){
        if(c == ','){
            c = ' ';
        }
    }

    istringstream iss(input);
    while(iss >> x){
        lengths.push_back(x);
    }

    vector<int> numbers;
    numbers.reserve(256);
    for(int i = 0; i <= 255; i++){
        numbers.push_back(i);
    }

    int currentPosition = 0;
    int skipSize = 0;

    for(auto& lenght : lengths){

        int listSize = lenght;
        vector<int> reverseOrder;
        int i;

        for(i = currentPosition; listSize > 0; listSize--){
            reverseOrder.push_back(numbers[i]);
            ++i %= numbers.size();
        }

        reverse(reverseOrder.begin(), reverseOrder.end());

        for(int j = 0, i = currentPosition; j < reverseOrder.size(); j++){
            numbers[i] = reverseOrder[j];
            ++i %= numbers.size();
        }

        currentPosition += lenght + skipSize;
        currentPosition %= numbers.size();
        skipSize++;


    }

    debug(numbers[0]*numbers[1]);

    return 0;
}
