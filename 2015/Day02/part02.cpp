#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    string input;

    int total = 0;

    while(cin >> input){
        istringstream iss(input);
        int length, width, height;

        char x;

        iss >> length >> x >> width >> x >> height;

        int bigger = max(length, max(height, width));

        int bow = length*width*height;
        int perimeter = 2*length + 2*height + 2*width - 2*bigger;

        total += perimeter + bow;

    }

    cout << total << endl;

    return 0;
}
