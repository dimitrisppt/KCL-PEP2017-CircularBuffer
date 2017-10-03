#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

// TODO: your code goes here
class Item {
	
	private:
		double latitude;
		double longitude;
		string id;
		int time;
		
public:
	
	Item(double latitudeIn, double longitudeIn, string idIn, int timeIn)
	: latitude(latitudeIn), longitude(longitudeIn), id(idIn), time(timeIn) {
	}
	
	friend ostream& operator<<(ostream & os, Item & item) {
		os << "{" << item.latitude << ", " << item.longitude << ", \"" << item.id << "\", " << item.time << "}";
		return os;
	}

	double getLat() const {
        return latitude;
    }

    double getLon() const {
        return longitude;
    }

	
	double distanceTo(Item item) {
		double lon1 = getLon();
		double lon2 = item.getLon();
		
		double lat1 = getLat();
		double lat2 = item.getLat();
		
		double dlon = lon2 - lon1;
		double dlat = lat2 - lat1;
		
		int R = 6373000;
		
		double lat1Rad = lat1 * M_PI/180;
		double lat2Rad = lat2 * M_PI/180;
		
		double dlonRad = dlon * M_PI/180;
		double dlatRad = dlat * M_PI/180;
	
		double a = pow((sin(dlatRad/2)), 2) + cos(lat1Rad) * cos(lat2Rad) * pow((sin(dlonRad/2)), 2);
				
		double c = 2 * atan2(sqrt(a), sqrt(1-a) );
	
		double distance = R * c;

		return distance;
			
	}
	
};

// don't write any code below this line

#endif

