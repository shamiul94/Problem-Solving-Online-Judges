//
// Created by shamiul93 on 5/18/19.
//
#include "../Offline/DES.h"

#define LEFT_28  0b0000000011111111111111111111111111110000000000000000000000000000
#define RIGHT_28 0b0000000000000000000000000000000000001111111111111111111111111111
#define LEFT_32  0b1111111111111111111111111111111100000000000000000000000000000000
#define RIGHT_32 0b0000000000000000000000000000000011111111111111111111111111111111

int main() {


    string c = "kshdhfljsadkf";
    reverse(c.begin(), c.end());
    cout << c << endl ;
//    ll final_output = 2346297497238943329;
//    cout << fromLLToBinaryString(final_output) << endl ;
//    ll temLeft32, temRight32;
//    temLeft32 = final_output & (ll) LEFT_32;
//    cout << fromLLToBinaryString(temLeft32) << endl ;
//    temRight32 = final_output & (ll) RIGHT_32;
//    cout << fromLLToBinaryString(temRight32) << endl ;
//    temLeft32 >>= 32;
//    cout << fromLLToBinaryString(temLeft32) << endl ;
//
//    temRight32 <<= 32;
//    cout << fromLLToBinaryString(temRight32) << endl ;
//
//    final_output = temLeft32 | temRight32;
//    cout << fromLLToBinaryString(final_output) << endl ;




//    ll a = fromBinaryStringToLL("11001000011001010110110001101100011011110010000001110111");
//    cout << a << endl;
//    cout << fromLLToBinaryString(a) << endl;
//
//    ll left28, right28, msb;
//
//    left28 = a & (ll) LEFT_28;
//    left28 >>= 28;
//    msb = check(left28, 27);
//    left28 = reset(left28, 27);
//    left28 <<= 1;
//    left28 |= msb;
//    left28 <<= 28;
//    cout << fromLLToBinaryString(left28) << endl;
//
//
//    right28 = a & (ll) RIGHT_28;
//    msb = check(right28, 27);
//    right28 = reset(right28, 27);
//    right28 <<= 1;
//    right28 |= msb;
//    cout << fromLLToBinaryString(right28) << endl;
//
//    ll final = left28 ^ right28;
//    cout << fromLLToBinaryString(final) << endl;
}

