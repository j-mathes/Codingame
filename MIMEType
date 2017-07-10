#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

string convertToUpper(string textString)
{
    string answer;
    
    for (int i = 0; i < textString.length(); i++)
    {
        char s = toupper(textString[i]);
        answer += s;
    }
    
    return answer;
}

int main()
{
    const string UNKNOWN = "UNKNOWN";
    
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    
    vector<string> fileExtensions;
    map<string, string> assocTable;
    vector<string> fileNames;
    string answer;
    
    for (int i = 0; i < N; i++) 
    {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        
        fileExtensions.push_back(convertToUpper(EXT));
        assocTable.insert({convertToUpper(EXT), MT});    
    }

    
    for (int i = 0; i < Q; i++)
    {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        
        fileNames.push_back(convertToUpper(FNAME));
    }
    
    for (int i=0; i<Q; i++)
    {
        string thisFileName = fileNames[i];
        unsigned pos = thisFileName.rfind('.'); // find the last occurance of a '.' because if it exists, then we have a file extension
        
        if (pos == -1)  // no file extension
        {
            answer = UNKNOWN;
        }
        else
        {
            string fileExtension = thisFileName.substr(pos + 1);
            map <string, string>::iterator it = assocTable.find(fileExtension);
            
            if (it == assocTable.end())
            {
                answer = UNKNOWN;
            }
            else
            {
                answer = it->second;
            }
        }
        // output answer
        cout << answer << endl;
    }
}
