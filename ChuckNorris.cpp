#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    string bitString = "";
    
    // iterate through each character in the string
    for (int i; i<MESSAGE.length(); i++)
    {
        char s = MESSAGE[i]; // find the ascii digital value of the letter (assign it to an int)
        bitset<7> bs(s); // convert that value into a binary value
        bitString += bs.to_string(); // create a string of the binary values
        
        //cerr << "bitString: " << bitString << endl;
    }

// for some reason, these need to be here, not at the beginning of main.  why?
    string output = "";
    int isZero = -1;  // flag to determine if binary value at the index is a zero
    string temp = ""; // Temporary string to build a series of zeros to indicate how many ones or zeros are in a row in binary
    
// encode the binary values to a unary value string
    for(string::iterator it = bitString.begin(); it != bitString.end(); it++)
    {
        //cerr << "isZero: " << isZero << endl;
        int newIsZero = (*it == '0'); // is the binary character at iterator it a new zero in the sequence?
        //cerr << "newIsZero: " << newIsZero << endl;
        
        if (newIsZero == isZero)      // if it's not a new zero, then we need to add another unary zero to our series
        {
            temp += '0';
            //cerr << "temp: " << temp << endl;
        }
        else
        {
            //cerr << "newIsZero: " << newIsZero << endl;
            isZero = newIsZero; // There is a problem with this, no idea what it is!!!!
            //cerr << "isZero: " << isZero << endl;
            if (output.length() > 0) // if we already have some output, we need to include a space between the next unary sequence
                output += " ";
            
            output += temp; // we add the number of necessary zeros in our unary sequence
            
            if (isZero)
                temp = "00 0"; // if we have a zero at the iterator index in the binary string, output the unary zero sequence
            else
                temp = "0 0"; // it must be a one a the iterator index in the binary string, output the unary one sequence
        }
    }
    
    // The last character has not been flushed, do it now
    if (temp.length() > 0)
    {
        if (output.length() > 0)
            output += " ";
        output += temp;
    }
    // output the answer string
    cout << output << endl;
}
