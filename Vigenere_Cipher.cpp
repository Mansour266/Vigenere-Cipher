// Date: 16/3/2022
// This is an encryption code using the Vigenere Cipher.
// You enter a sentence that you want to cipher and a keyword along with it.
// This keyword will be the secret to ciphering or deciphering that sentence.


#include <bits/stdc++.h>

using namespace std;

int main(){

    int i, j, ascii_sum;
    string word_lower, word , keyword_lower, keyword, encryption, decryption, option;

    while (option != "3"){

        // Selecting an option
        cout << "Choose an option:\n 1-Cipher a message\n 2-Decipher a message\n 3-End\n";
        getline(cin,option);

        // Reseting all values
        i = 0, j = 0, ascii_sum = 0;
        word_lower = "", word = "", keyword_lower = "", keyword = "", encryption = "", decryption = "";

        // Encryption
        if(option == "1"){
            
            // Getting user input
            cout << "\nEnter the sentence you want to cipher:" << endl;
            getline(cin,word_lower);
            cout << "\nEnter a keyword: " << endl;
            getline(cin,keyword_lower);

            // Making sure it's length is within range
            if(word_lower.length() > 80 || keyword_lower.length() > 8){
                cout << "Input length is too long\n";
            }

            // Converting input into uppercase
            else{
                for (int l = 0; l < word_lower.length(); l++)
                {
                    word += toupper(word_lower[l]);
                }

                for (int k = 0; k < keyword_lower.length(); k++)
                {
                    keyword += toupper(keyword_lower[k]);
                }

                // Ciphering the input
                while (i < word.length())
                {
                    // Making sure the input is alphabetical
                    if(isalpha(word[i])){
                        ascii_sum = ((int(word[i]) + int(keyword[j])) % 26) + 65; 
                    }
                    else{
                        ascii_sum = word[i];
                    }
                    i++;
                    j++;

                    if(j >= keyword.length() && i != word.length()){
                        j = 0;
                    }
                    
                    // Summing up the characters into one sentence
                    encryption += char(ascii_sum);
                }
                cout <<"\nCiphered Message: " << encryption << "\n\n";
            }
        }

        // Decryption
        else if(option == "2"){

            // Getting user input
            cout << "\nEnter the sentence you want to decipher:" << endl;
            getline(cin,word_lower);
            cout << "\nEnter the keyword you used to cipher it: " << endl;
            getline(cin,keyword_lower);

            // Making sure it's length is within range
            if(word_lower.length() > 80 || keyword_lower.length() > 8){
                cout << "Input length is too long\n";
            }

            // Converting input into uppercase
            else{
                for (int l = 0; l < word_lower.length(); l++)
                {
                    word += toupper(word_lower[l]);
                }

                for (int k = 0; k < keyword_lower.length(); k++)
                {
                    keyword += toupper(keyword_lower[k]);
                }

                // Deciphering the input
                while (i < word.length())
                {
                    // Making sure the input is alphabetical
                    if(isalpha(word[i])){
                        ascii_sum = ((int(word[i]) - int(keyword[j]) + 26) % 26) + 65; 
                    }
                    else{
                        ascii_sum = word[i];
                    }
                    i++;
                    j++;

                    if(j >= keyword.length() && i != word.length()){
                        j = 0;
                    }

                    // Summing up the characters into one sentence
                    decryption += char(ascii_sum);
                }
                cout <<"\nDeciphered Message: " << decryption << "\n\n";
            }
        }

        // Exiting the program
        else if(option == "3"){
            exit(0);
        }

        // Incase the user chooses an invalid option
        else{
            cout << "\nInvalid input, please try again.\n";
        }
    }       
}
