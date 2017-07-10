#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N;
    vector<int> horseList;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        horseList.push_back(Pi);
    }

    sort(horseList.begin(), horseList.end());
    
    int lowDiff = INT_MAX;

    for (int i=0; i<horseList.size()-1; i++)
    {
        int indA, indB, tempAnswer;
        indA = i;
        indB = i+1;

        tempAnswer = horseList[indB] - horseList[indA];
        if (tempAnswer < lowDiff) lowDiff = tempAnswer;
    }

    cout << lowDiff << endl;
}
