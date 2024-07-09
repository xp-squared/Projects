/******************************************************************************
Assignment: For this assignment you’ll be making a Brute Force Code Cracker. It will take a
cipher for input, and run through all possible shift-cipher keys for it. Keep in mind there are only
26 possible keys for a shift cipher. After taking in a cipher input, you’ll need to, one-by-one,
convert the characters that make up the string into numbers, shift them based on the key you’re
currently testing, then shift them back to characters. Characters, when converting to numbers,
always take their ASCII values. 
Lower-case ‘a’ is 97, while lower-case ‘z’ is 122. Upper-case
‘A’ is 65, while upper-case ‘Z’ is 90. All the letters between them, have the numbers ranging
between them.
Also keep in mind that you’ll need to use modulo to take into account letters that might shift past
the end of the group, such as trying to shift ‘y’ five letters to the right. The following cipher
decodes as ‘Testing the System’ and may be used to verify your code.
Whvwlqj wkh Vbvwhp
You’ll need to deliver a screenshot for EACH of the five ciphers below. Do note that there is an
English phrase decryption of each of them.
1: Wkh qljkw lv orqj dqg zh doo suhwhqg wr vohhs
2: F xrfqq hnyd mfx gjjs inxhtajwji zsijw ymj gtbqnsl fqqjd
3: Yx Drebcnki dro vslbkbi gsvv lo exuxygklvo
4: Epht bsf opu bmmpxfe jo uif eph qbsl
5: Jrypbzr gb Avtug Inyr
(100 pts total: 50 points for code, 10 points for each output)
*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string sentence;
    cout << "Please enter a sentence: ";
    getline(cin, sentence); // takes whole sentence 
    vector<int> values; 
    
    for(int i = 0; i < sentence.size(); i++) {
        values.push_back(int(sentence[i]));
    }
    
    
    for(int i = 0; i < 26; i++) { // we need it to happen 26 times to go through all possible cases
        cout << "Shift " << i+1 << ": ";
        for(int j = 0; j < sentence.size(); j++ ) { // happens for the size of the sentence 
            if (values.at(j) == 32) {
                cout << " ";
                continue;
            }
            values.at(j) = values.at(j) + 1; // add 1 to iterate to next letter 
            if (values.at(j) == 123) {
                values.at(j) = 97;
            }
            if (values.at(j) == 91) {
                values.at(j) = 65;
            }
            cout << char(values.at(j));
        }
        cout << endl;
    }
    

    return 0;
}


