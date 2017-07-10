#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L;                  // Length of an ascii art letter
    int H;                  // Height of an ascii art letter
    string T;               // The string of text we want to convert to ascii art
    vector<string> asciiArt; // Each entry in this vector will hold an entire horizontal line of the ascii art text

    const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ?";    // We use this as a reference to find each letter
    
    cin >> L; cin.ignore(); // Get the input for the height
    cin >> H; cin.ignore(); // Get the input for the length
    getline(cin, T);        // Read in the string of text we want to convert
    
    for (int i = 0; i < H; i++) 
    {
        string ROW;
        getline(cin, ROW); // This will read in an entire row of one height unit of the ascii art
        
        asciiArt.push_back(ROW);  // Here we collect each line of the ascii art in a string vector
    }
    
    vector<string> output(H, "");  // We will use this string to build our output vector of ascii art
    
    for (int i = 0; i < T.length(); i++)
    {
        char s = toupper(T[i]); // We take the first letter of the text and convert it to upper case
        
        if ((s < 'A') || (s > 'Z')) // Is the letter outside of our proper range?
        {
            s = '?'; // If so, change it to a question mark
        }
        
        int index = alphabet.find(s);   // Make an index variable and assign it to the location where we find that letter in our alphabet string
        
        for (int j = 0; j < H; j++)
        {
            string convertedLine = asciiArt[j].substr(index*L, L);  // Iterate through the ascii art lines, using the index, find the substring for the letter we want
            output[j] += convertedLine; // Take the substring and begin to build the output vector
        }
    }

    for (int i=0; i<H; i++)
    {
        cout << output[i] << endl; // Iterate through the output vector and print out each line
    }
}
