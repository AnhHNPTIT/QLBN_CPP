#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Location 
{
	protected:
		int locationID; // mã vị trí
		string location; // vị trí có nguy cơ nhiễm COVID cao

	public:
		// Hàm khởi tạo không tham số
		Location(){
			this->locationID = 0;
			this->location = "";
		}

		// Hàm khởi tạo có tham số
		Location(int locationID, string location)
		{
			this->locationID = locationID;
			this->location = location;
		}

		~Location(){
		}

		int getLocationID() {
			return locationID;
		}
		void setLocationID(int locationID) {
			this->locationID = locationID;
		}
		string getLocation() {
			return location;
		}
		void setLocation(string location) {
			this->location = location;
		}	
};