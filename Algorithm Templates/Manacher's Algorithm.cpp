/**
@author - Rumman BUET CSE'15
Problem -
Idea -
Concept -
*/

#include <bits/stdc++.h>

#define m0(a) memset(a , 0 , sizeof(a))


using namespace std;


/************************************** END OF INITIALS ****************************************/

/**
     * Linear time Manacher's algorithm to find longest palindromic substring.
     * There are 4 cases to handle
     * Case 1 : Right side palindrome is totally contained under current palindrome. In this case do not consider this as center.
     * Case 2 : Current palindrome is proper suffix of input. Terminate the loop in this case. No better palindrom will be found on right.
     * Case 3 : Right side palindrome is proper suffix and its corresponding left side palindrome is proper prefix of current palindrome. Make largest such point as
     * next center.
     * Case 4 : Right side palindrome is proper suffix but its left corresponding palindrome is be beyond current palindrome. Do not consider this
     * as center because it will not extend at all.
     *
     * To handle even size palindromes replace input string with one containing $ between every input character and in start and end.
     */

int longestPalindromicSubstringLinear(string input) {
    int index = 0;
    //preprocess the input to convert it into type abc -> $a$b$c$ to handle even length case.
    //Total size will be 2*n + 1 of this new array.
    string newInput = "";

    for (int i = 0; i < 2*input.length() + 1; i++) {
        if (i % 2 != 0) {
            newInput += input[index++];
        } else {
            newInput += '$';
        }
    }
//    cout << newInput << endl ;
    int newInputLength = static_cast<int>(newInput.length());


    //create temporary array for holding largest palindrome at every point. There are 2*n + 1 such points.
    int T[newInputLength];
    m0(T);

    int start = 0;
    int end = 0;
    //here i is the center.
    for (int i = 0; i < newInputLength;) {
        //expand around i. See how far we can go.
        while (start > 0 && end < newInputLength - 1 && newInput[start - 1] == newInput[end + 1]) {
            start--;
            end++;
        }
        //set the longest value of palindrome around center i at T[i]
        T[i] = end - start + 1;

        //Case 2: this is case 2. Current palindrome is proper suffix of input. No need to proceed. Just break out of loop.
        if (end == newInputLength - 1) {
            break;
        }
        //Mark newCenter to be either end or end + 1 depending on if we dealing with even or old number input.
        int newCenter = end + (i % 2 == 0 ? 1 : 0);

        for (int j = i + 1; j <= end; j++) {

            // This part contains Case 3,4
            /*
             *
             * Bangla explanation -
             *
             * j ki? - j hocche ashol pallindrome er center er daan pasher part ta.
             * ei j = range(center -> end)
             *
             * Case 1: jodi choto pallindrome boro pallindrome er moddhe included hoye jay.
             * how is checked? - T[j] = min(T[i - (j - i)], 2 * (end - j) + 1); -> it ensures it
             * Q: (2 * (end - j) + 1) diye ki bujhaay? - j ke center dhore pallindrom er daane baame (end-j) ta kore
             * element thaake. so, total element in that pallindrom hobe 2 * (end-j) + 1. (1 hoche j ke shoho niye).
             * Q: T[i - (j - i)] diye ki bujhaay? - Eta bujhaay i er mirror elelment ke center dhore banano
             * pallindrom er length koto hobe. ekhon chinta koro,  (2 * (end - j) + 1) is the highest possible
             * length of the pallindrome centered at j. naaile onnora ore cover kore felto.
             * So, -
             * 1. T[i - (j - i)] > (2 * (end - j) + 1) ---> maane holo, baam dike ashol pallin
             * er edge over kore chole gese. so, eta ignore korbo ---> CASE : 4
             *
             *
             * 2. T[i - (j - i)] < (2 * (end - j) + 1) ---> baam dike notun pallin ashol pallin er moddhe
             * included hoye gese. notun kore etake hishab korar proyojon nai----> CASE : 1
             *
             *
             * 3. T[i - (j - i)] == (2 * (end - j) + 1) ---> maane holo, baam dike edge thekei shuru
             * hoise oi pallindrom. maane PREFIX hoye gese eta. etake count kora lagbe ----> CASE : 3
             *
             *
             * CASE 3: etaay arektu extra kaaj kora laage.
             *
             * if (j + T[i - (j - i)] / 2 == end) --> ei check ta kora lagtese case 3 te. keno?
             * eta diye confirm kortese je 'j' theke pallin nile sheta suffix o hobe. aar prefix to aagei hoilo ekbar.
             * so, ultimately suffix , prefix duitai proof hoilo ---> CASE : 3 proved.
             *
             *
             */


            //Case 1, 4:  i - (j - i) is left mirror. Its possible left mirror might go beyond current center palindrome.
            // So take minimum of either left side palindrome or distance of j to end.
            T[j] = min(T[i - (j - i)], 2 * (end - j) + 1);

            // Case 3: Only proceed if we get case 3. This check is to make sure we do not pick j as new
            // center for case 1 or case 4
            // As soon as we find a center lets break out of this inner while loop.
            if (j + T[i - (j - i)] / 2 == end) {
                newCenter = j;
                break;
            }
        }
        //make i as newCenter. Set right and left to atleast the value we already know should be matching based of left side palindrome.
        i = newCenter;
        end = i + T[i] / 2;
        start = i - T[i] / 2;
    }


    //find the max palindrome in T and return it.
    int max = INT_MIN;

    for (int i = 0; i < newInputLength; i++) {
        cout << T[i] << " ";
        int val;
        val = T[i] / 2;
        if (max < val) {
            max = val;
        }
    }
    cout << endl;
    return max;
}


int main() {
    string str = "abaxabaxabybaxabyb";
    cout << longestPalindromicSubstringLinear(str) << endl;
    return 0;
}
