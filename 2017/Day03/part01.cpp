#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl

using namespace std;

int main(){

    int input;

    cin >> input;

    int factor = 1;

    while(factor*factor < input){
        factor += 2;
    }

    int oddSquare = factor*factor;
    int boxLenght = factor - 1;
    int stepsFromMiddleToCenter = boxLenght/2;

    int distance = oddSquare - input;
    int sidesFromOddSquareToClosestMiddle = boxLenght * floor(distance / boxLenght);
    int distanceToClosestMiddle = oddSquare - sidesFromOddSquareToClosestMiddle;

    int closestMiddle = (distanceToClosestMiddle - stepsFromMiddleToCenter);
    int stepsToClosestMiddle = abs(input - closestMiddle);


    int steps = stepsToClosestMiddle + stepsFromMiddleToCenter;

    debug(steps);

    return 0;
}
