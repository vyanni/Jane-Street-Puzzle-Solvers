//Brute forcing cause I can't bother to think of a proper solution at the moment :/
using namespace std;
#include <iostream>
#include <cmath>

void findVariables(double &a, double &b, double &c){
    /*
     * Since the grid is a 13x13 square, the area is 169, for which the highest triangular number
     * (the addition equivalent of factorial), is 17, so the max bound for N is 17
     */

    for(a = -17; a < 17; a += 1e-3){
        for(b = -17; b < 17; b += 1e-3){
            for(c = -17; c < 17; c += 1e-3){
                if(checkEquations(a, b, c)){ break; }
            }
            if(checkEquations(a, b, c)){ break; }
        }
        if(checkEquations(a, b, c)){ break; }
    }

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;
};

bool checkEquations(double &a, double &b, double &c){
    bool functionOne = (((floor(6*c - 4*b)) == (6*c - 4*b)) && ((6*c - 4*b) <= 17) && (1 <= (6*c - 4*b)));
    bool functionTwo = (((floor(8 - b)) == (8 - b)) && ((8 - b) <= 17) && (1 <= (8 - b)));
    bool functionThree = (((floor((pow(a, b) - 4) / (6*c + 1))) == ((pow(a, b) - 4) / (6*c + 1))) && (((pow(a, b) - 4) / (6*c + 1)) <= 17) && (1 <= ((pow(a, b) - 4) / (6*c + 1))));
    bool functionFour = (((floor((b + c) / (c - 1))) == ((b + c) / (c - 1))) && (((b + c) / (c - 1)) <= 17) && (1 <= ((b + c) / (c - 1))));
    bool functionFive = (((floor(pow(b, 2) - (b / c))) == (pow(b, 2) - (b / c))) && ((pow(b, 2) - (b / c)) <= 17) && (1 <= (pow(b, 2) - (b / c))));
    bool functionSix = (((floor(sqrt(30 + a) / c)) == (sqrt(30 + a) / c)) && ((sqrt(30 + a) / c) <= 17) && (1 <= (sqrt(30 + a) / c)));
    bool functionSeven = (((floor((a + b) / (c - 3*a))) == ((a + b) / (c - 3*a))) && (((a + b) / (c - 3*a)) <= 17) && (1 <= ((a + b) / (c - 3*a))));
    bool functionEight = (((floor((b - 3*a) / (a - c))) == ((b - 3*a) / (a - c))) && (((b - 3*a) / (a - c)) <= 17) && (1 <= ((b - 3*a) / (a - c))));
    
    return (functionOne && functionTwo && functionThree && functionFour && functionFive && functionSix && functionSeven && functionEight);
}