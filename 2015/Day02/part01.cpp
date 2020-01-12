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

        int side1 = length*width,
            side2 = length*height,
            side3 = height*width;

        int surface = 2*side1 + 2*side2 + 2*side3;
        int slack = min(side1, min(side2, side3));

        total += surface + slack;

    }

    cout << total << endl;

    return 0;
}
