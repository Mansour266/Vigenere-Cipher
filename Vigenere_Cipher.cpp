#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void encryption(){
    int i {0}, j {0}, ascii_sum;
    
    string word,  keyword,  encryption;
    
    cout << "\nEnter the sentence you want to cipher:" << endl;
    getline(cin,word);
    cout << "\nEnter a keyword: " << endl;
    getline(cin,keyword);

    // Making sure it's length is within range
    if(word.length() > 80 || keyword.length() > 8){
        cout << "Input length is too long\n";
    }

        // Converting input into uppercase
    else{
        // here i replaced the for loops with built in functions to convert the text to upper case (Mansour)
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
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

void decryption(){
    int i {0}, j {0}, ascii_sum; // resetting the values

    string word,  keyword,  decrypted;
    // Getting user input
    cout << "\nEnter the sentence you want to decipher:" << endl;
    getline(cin,word);
    cout << "\nEnter the keyword you used to cipher it: " << endl;
    getline(cin,keyword);

    // Making sure it's length is within range
    if(word.length() > 80 || keyword.length() > 8){
        cout << "Input length is too long\n";
    }

        // Converting input into uppercase
    else{
        // here i replaced the for loops with built in functions to convert the text to upper case
        transform(word.begin(), word.end(), word.begin(), ::toupper);

        transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);

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
            decrypted += char(ascii_sum);
        }
        cout <<"\nDeciphered Message: " << decrypted << "\n\n";
    }
}


int main(){

    string option;

    while (option != "3"){

        // Selecting an option
        cout << "Choose an option:\n 1-Cipher a message\n 2-Decipher a message\n 3-End\n";
        getline(cin,option);

        // Encryption
        if(option == "1"){
            encryption();
        }

        // Decryption
        else if(option == "2"){
            decryption();
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
//You can thank me later. Mansour
