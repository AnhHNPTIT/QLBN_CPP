#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Symptom 
{
	public:
		int symptomID; // mã triệu chứng
		string name; // triệu chứng
		string typeRisk; // low, medium or high risk

		// Hàm khởi tạo không tham số
		Symptom(){

		}

		// Hàm khởi tạo có tham số
		Symptom(int symptomID, string name, string typeRisk)
		{
			this->symptomID = symptomID;
			this->name = name;
			this->typeRisk = typeRisk;
		}

		int getSymptomID() {
			return this->symptomID;
		}
		void setSymptomID(int symptomID) {
			this->symptomID = symptomID;
		}
		string getName() {
			return this->name;
		}
		void setName(string name) {
			this->name = name;
		}
		string getTypeRisk() {
			return this->typeRisk;
		}
		void setTypeRisk(string typeRisk) {
			this->typeRisk = typeRisk;
		}	
};