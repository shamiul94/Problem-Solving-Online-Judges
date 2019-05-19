
#include "DES.h"

#define LEFT_32  0b1111111111111111111111111111111100000000000000000000000000000000
#define RIGHT_32 0b0000000000000000000000000000000011111111111111111111111111111111
#define LEFT_28  0b0000000011111111111111111111111111110000000000000000000000000000
#define RIGHT_28 0b0000000000000000000000000000000000001111111111111111111111111111
#define LAST_8   0b0000000000000000000000000000000000000000000000000000000011111111

string key, plainText, ciphered = "", final_ciphered = "";
ll currPlainTextIndex = 0;
ll initialTransposedDataLL;
ll initialKeyLL, initialTransposedKeyLL;

ll keyArr[20];

void makePlainTextFactorOf8() {
    if (plainText.length() % 8 != 0) {
        ll rem = static_cast<long long int>(plainText.length() % 8);
        ll remaining = 8 - rem;
        for (ll i = 0; i < remaining; i++) {
            plainText = plainText + '-';
        }
    }
}


string getNextPlainTextBlock() {
    if (currPlainTextIndex == plainText.length()) {
        return "";
    }
    string s;
    s = plainText.substr(static_cast<unsigned long>(currPlainTextIndex), 8);
    currPlainTextIndex += 8;
    return s;
}


ll stringTo64BitBlock(string s) {
    ll bitBlock = 0;
    for (ll i = 0; i < s.length(); i++) {
        char ch = s[i];
        ll a = (ll) ch;
        bitBlock <<= 8;
        bitBlock |= a;
//        cout << "a : " << fromLLToBinaryString(a) << endl;
//        cout << "bitBlock : " << fromLLToBinaryString(bitBlock) << endl;
    }
    return bitBlock;
}


ll Iteration(ll data, ll k) {
    ll input = data;
    ll key = k;

    ll prevLeft_32, prevRight_32, newLeft_32, newRight_32;
    ll keyLeft28 = 0, keyRight28 = 0, msb;

    for (ll i = 0; i < 16; i++) {
        ll newOutput = 0;

        ll thisRoundKeyLL;

        prevLeft_32 = input & (ll) LEFT_32;
        prevRight_32 = input & (ll) RIGHT_32;
        newLeft_32 = prevRight_32;


        ll shiftTimes = SHIFT[i];

        for (ll j = 0; j < shiftTimes; j++) {
            keyLeft28 = key & (ll) LEFT_28;
            keyLeft28 >>= 28;
            msb = check(keyLeft28, 27);
            keyLeft28 = reset(keyLeft28, 27);
            keyLeft28 <<= 1;
            keyLeft28 |= msb;
            keyLeft28 <<= 28;
//            cout << fromLLToBinaryString(keyLeft28) << endl;

            keyRight28 = key & (ll) RIGHT_28;
            msb = check(keyRight28, 27);
            keyRight28 = reset(keyRight28, 27);
            keyRight28 <<= 1;
            keyRight28 |= msb;
//            cout << fromLLToBinaryString(keyRight28) << endl;
        }

        key = keyLeft28 | keyRight28;

        ll transposedKeyLL = 0;
        for (ll j = 0; j < 48; j++) {
            ll idx = CP_2[j];
            idx--;
            transposedKeyLL = setValueBit(transposedKeyLL, j, check(key, idx));
        }

        key = transposedKeyLL;

        keyArr[i] = key;

        ll e = 0;
        ll transposedRightLL = 0;
        for (ll j = 0; j < 48; j++) {
            ll idx = E[j];
            idx--;
            transposedRightLL = setValueBit(transposedRightLL, j, check(prevRight_32, idx));
        }

        e = transposedRightLL;

        ll func = e ^key;

        ll transposedFuncLL = 0;

        for (ll j = 0; j < 32; j++) {
            ll idx = PI_2[j];
            idx--;
            transposedFuncLL = setValueBit(transposedFuncLL, j, check(func, idx));
        }

        ll PboxTransposeLL = 0;
        for (ll j = 0; j < 32; j++) {
            ll idx = P[j];
            idx--;
            PboxTransposeLL = setValueBit(PboxTransposeLL, j, check(transposedFuncLL, idx));
        }

        newRight_32 = PboxTransposeLL;
        input = newLeft_32 | newRight_32;
    }

    ll final_output = input;
    ll temLeft32, temRight32;
    temLeft32 = final_output & (ll) LEFT_32;
    temRight32 = final_output & (ll) RIGHT_32;
    temLeft32 >>= 32;
    temRight32 <<= 32;
    final_output = temLeft32 | temRight32;

    ll finalTransposeLL = 0;
    for (ll j = 0; j < 64; j++) {
        ll idx = PI_1[j];
        idx--;
        finalTransposeLL = setValueBit(finalTransposeLL, j, check(final_output, idx));
    }

    final_output = finalTransposeLL;
    return final_output;
}


string DESencryption() {

    initialKeyLL = stringTo64BitBlock(key);
    makePlainTextFactorOf8();

    string nextPlainTextBlock = getNextPlainTextBlock(); /// guti
    while (!nextPlainTextBlock.empty()) {
        ll nextBitBlock = stringTo64BitBlock(nextPlainTextBlock);

        initialTransposedDataLL = 0;

        for (ll i = 0; i < 64; i++) {
            ll idx = PI[i];
            idx--;
            initialTransposedDataLL = setValueBit(initialTransposedDataLL, i, check(nextBitBlock, idx));
        }

        initialTransposedKeyLL = 0;
        for (ll i = 0; i < 56; i++) {
            ll idx = CP_1[i];
            idx--;
            initialTransposedKeyLL = setValueBit(initialTransposedKeyLL, i, check(initialKeyLL, idx));
        }


        ll ans = Iteration(initialTransposedDataLL, initialTransposedKeyLL);

        for (ll t = 0; t < 8; t++) {
            ll last8bits = ans & (ll) LAST_8;
            ans >>= 8;
            char c = (char) ((int) last8bits);
            ciphered += c;
        }

        reverse(ciphered.begin(), ciphered.end());

        final_ciphered = final_ciphered + ciphered;

        //////////////////////////////////////////////////
        nextPlainTextBlock = getNextPlainTextBlock();
    }
//    cout << final_ciphered << endl ;
    return final_ciphered;
}


ll DecryptingIteration(ll data) {
    ll input = data;
    ll key ;

    ll prevLeft_32, prevRight_32, newLeft_32, newRight_32;
    ll keyLeft28 = 0, keyRight28 = 0, msb;

    for (ll i = 15; i >= 0; i--) {
        key = keyArr[i];


        prevLeft_32 = input & (ll) LEFT_32;
        prevRight_32 = input & (ll) RIGHT_32;
        newLeft_32 = prevRight_32;


        ll shiftTimes = SHIFT[i];

        for (ll j = 0; j < shiftTimes; j++) {
            keyLeft28 = key & (ll) LEFT_28;
            keyLeft28 >>= 28;
            msb = check(keyLeft28, 27);
            keyLeft28 = reset(keyLeft28, 27);
            keyLeft28 <<= 1;
            keyLeft28 |= msb;
            keyLeft28 <<= 28;
//            cout << fromLLToBinaryString(keyLeft28) << endl;

            keyRight28 = key & (ll) RIGHT_28;
            msb = check(keyRight28, 27);
            keyRight28 = reset(keyRight28, 27);
            keyRight28 <<= 1;
            keyRight28 |= msb;
//            cout << fromLLToBinaryString(keyRight28) << endl;
        }

        key = keyLeft28 | keyRight28;

        ll transposedKeyLL = 0;
        for (ll j = 0; j < 48; j++) {
            ll idx = CP_2[j];
            idx--;
            transposedKeyLL = setValueBit(transposedKeyLL, j, check(key, idx));
        }

        key = transposedKeyLL;

        ll e = 0;
        ll transposedRightLL = 0;
        for (ll j = 0; j < 48; j++) {
            ll idx = E[j];
            idx--;
            transposedRightLL = setValueBit(transposedRightLL, j, check(prevRight_32, idx));
        }

        e = transposedRightLL;

        ll func = e ^key;

        ll transposedFuncLL = 0;

        for (ll j = 0; j < 32; j++) {
            ll idx = PI_2[j];
            idx--;
            transposedFuncLL = setValueBit(transposedFuncLL, j, check(func, idx));
        }

        ll PboxTransposeLL = 0;
        for (ll j = 0; j < 32; j++) {
            ll idx = P[j];
            idx--;
            PboxTransposeLL = setValueBit(PboxTransposeLL, j, check(transposedFuncLL, idx));
        }

        newRight_32 = PboxTransposeLL;
        input = newLeft_32 | newRight_32;
    }

    ll final_output = input;
    ll temLeft32, temRight32;
    temLeft32 = final_output & (ll) LEFT_32;
    temRight32 = final_output & (ll) RIGHT_32;
    temLeft32 >>= 32;
    temRight32 <<= 32;
    final_output = temLeft32 | temRight32;

    ll finalTransposeLL = 0;
    for (ll j = 0; j < 64; j++) {
        ll idx = PI_1[j];
        idx--;
        finalTransposeLL = setValueBit(finalTransposeLL, j, check(final_output, idx));
    }

    final_output = finalTransposeLL;
    return final_output;
}


string DESdecryption() {

    plainText = final_ciphered;

    string nextPlainTextBlock = getNextPlainTextBlock(); /// guti
    while (!nextPlainTextBlock.empty()) {
        ll nextBitBlock = stringTo64BitBlock(nextPlainTextBlock);

        initialTransposedDataLL = 0;

        for (ll i = 0; i < 64; i++) {
            ll idx = PI[i];
            idx--;
            initialTransposedDataLL = setValueBit(initialTransposedDataLL, i, check(nextBitBlock, idx));
        }

        initialTransposedKeyLL = 0;
        for (ll i = 0; i < 56; i++) {
            ll idx = CP_1[i];
            idx--;
            initialTransposedKeyLL = setValueBit(initialTransposedKeyLL, i, check(initialKeyLL, idx));
        }


        ll ans = DecryptingIteration(initialTransposedDataLL);

        for (ll t = 0; t < 8; t++) {
            ll last8bits = ans & (ll) LAST_8;
            ans >>= 8;
            char c = (char) ((int) last8bits);
            ciphered += c;
        }

        reverse(ciphered.begin(), ciphered.end());

        final_ciphered = final_ciphered + ciphered;

        //////////////////////////////////////////////////
        nextPlainTextBlock = getNextPlainTextBlock();
    }
    cout << final_ciphered << endl ;
    return final_ciphered;
}

int main() {
    fi;
    fo;
    getline(cin, key);
    getline(cin, plainText);

    DESencryption();
    DESdecryption();
    return 0;
}