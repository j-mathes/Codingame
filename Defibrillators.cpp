#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Location
{
public:
    double latitude, longitude;
    
    Location()
    {
        latitude = longitude = 0;
    }
    
    Location(string sLat, string sLong)
    {
        unsigned pos;
        pos = sLat.find(',');
        sLat[pos] = '.';
        pos = sLong.find(',');
        sLong[pos] = '.';
        
        latitude = stod(sLat);
        longitude = stod(sLong);
    }
    
    static double distance(const Location& a, const Location& b);
};

double Location::distance(const Location& a, const Location& b)
{
    //double x = (b.longitude - a.longitude) * ((a.latitude + b.latitude)/2);
    //double y = (b.latitude - a.latitude);
    //double dist = sqrt(pow(x,2) + pow(y,2)) * 6371;
    
    double dist = sqrt(pow((a.latitude - b.latitude),2)+pow((a.longitude-b.longitude),2));
    
    return dist;
}

class Defibrillator
{
public:
    Defibrillator(string descr);
    string idNum, name, address, phone;
    Location loc;
    string originalDescr;
};

Defibrillator::Defibrillator(string descr)
{
    vector<string> fields;
    stringstream ss(descr);
    string field;
    while (getline (ss, field, ';'))
    {
        fields.push_back(field);
    }
    
    this->idNum = fields[0];
    this->name = fields[1];
    this->address = fields[2];
    this->phone = fields[3];
    Location defibLoc(fields[5], fields[4]);
    this->loc = defibLoc;
    this->originalDescr = descr;
}

int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    vector<Defibrillator*> allDefibs;
    
    for (int i = 0; i < N; i++) 
    {
        string DEFIB;
        getline(cin, DEFIB);
        allDefibs.push_back(new Defibrillator(DEFIB));
    }
    
    Location userLocation(LAT, LON);
    
    double min {-1};
    string answer;
    
    for(int i=0; i<N; i++)
    {
        double distBetween = Location::distance(userLocation, allDefibs[i]->loc);
        if ((min == -1) or (distBetween < min))
        {
            min = distBetween;
            answer = allDefibs[i]->name;
        }
    }
    
    cout << answer << endl;
    
    for(int i=0; i<N; i++)
    {
        delete allDefibs[i];
    }
}
