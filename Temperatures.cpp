#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
    string temps; // the n temperatures expressed as integers ranging from -273 to 5526
    getline(cin, temps);
    int result;
    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    if (n==0)
    {
        result = 0;
    }
    else
    {
        stringstream iss(temps);
        vector<int>tempsArray;
        int currentNumber;
    
        while(iss >> currentNumber)
            tempsArray.push_back(currentNumber);
    
        int closestIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (n!=1)
            {
                if (abs(tempsArray[i]) < (abs(tempsArray[closestIndex])))
                {
                    closestIndex = i;
                }
                else if (abs(tempsArray[i]) == (abs(tempsArray[closestIndex])))
                {
                    if (tempsArray[i] > tempsArray[closestIndex])
                        closestIndex = i;
                }
            }
            result = tempsArray[closestIndex];
            //cerr << "result at " << i << ":" << result << endl;
        }
    }
    
    cout << result << endl;
}
