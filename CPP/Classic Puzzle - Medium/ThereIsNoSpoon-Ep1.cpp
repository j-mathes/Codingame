#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void findNextHoriz(map<int, string>::iterator it)
{
    size_t pos = it->second.find('0');
    if (pos != string::npos)
    {
        cout << pos << " " << it->first << " ";
    }
    else
    {
        cout << "-1 -1 ";
    }
}

// Find out why it matters if temp is passes with & or not at the front
void findNextVert(map<int, string> &temp, map<int, string>::iterator it, size_t pos)
{
    int found = 2; // setting to 2 is arbitrary
    for(it; it !=temp.end(); it++)
    {
        if(it->second[pos] == '0')
        {
            cout << pos << " " << it->first << " ";
            found = 1;
            break;
        }
        else
        {
            found = 0;
        }
    }
    if (found == 0)
    {
        cout << "-1 -1 ";
    }
}

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    map <int, string> lines;
    map <int, string>::iterator it_lines;
    
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        lines[i] = line;
    }

    for (it_lines = lines.begin(); it_lines != lines.end(); it_lines++)
    {
        size_t pos = it_lines->second.find('0');
        while(pos != string::npos)
        {
            cout << pos << " " << it_lines->first << " ";
            it_lines->second[pos] = '.';
            findNextHoriz(it_lines);
            findNextVert(lines, it_lines, pos);
            pos = it_lines->second.find('0');
            cout << endl;
        }
    }
}
