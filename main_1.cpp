#include "provided.h"
#include <iostream>
using namespace std;

int main() {
    string mapFile = "D:\\CppProj\\BruinNav\\mapdata.txt";
    MapLoader map;
    if (map.load(mapFile))
    {
        cout << "Map loaded" << endl;
        cout << map.getNumSegments() << endl;
    }
    AttractionMapper amap;
    amap.init(map);
    GeoCoord geo;
    if (amap.getGeoCoord("Ami Sushi", geo))
    {
        cout << "found location" << endl;
        cout << geo.latitude << " " << geo.longitude << endl;
    }
    SegmentMapper smap;
    smap.init(map);
    vector<StreetSegment> v = smap.getSegments(geo);
    if (!v.empty())
    {
        cout << "found segments" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].streetName << endl;
            cout << v[i].segment.start.latitude << " " << v[i].segment.start.longitude << " " << v[i].segment.end.latitude << " " << v[i].segment.start.longitude << endl;
        }
    }

    int choice;
    string start, end;

    Navigator nav;
    nav.loadMapData(mapFile);
    vector<NavSegment> directions;

    while(true){
        cout << "\nMenu:\n";
        cout << "1. Get Directions\n";
        cout << "2. Exit\n";
        cin>>choice;
        if(choice==1){
            fflush(stdin);
            cout<<"Enter Origin: ";
            getline(cin, start);

            cout<<"Enter Destination: ";
            getline(cin, end);
    
            if (nav.navigate(start, end, directions) == NAV_SUCCESS)
            {
                cout << "success" << endl;
                for (auto i: directions)
                    cout << i.m_geoSegment.start.latitude << " " << i.m_geoSegment.start.longitude << " " << i.m_geoSegment.end.latitude << " " << i.m_geoSegment.end.longitude << " " << i.m_direction << " " << i.m_streetName << endl;
            }else {
                cout << "\nOne or both locations not found.\n";
            }
        }else if(choice==2){
            cout<<"See you soon...\n";
            return 0;
        }else{
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
