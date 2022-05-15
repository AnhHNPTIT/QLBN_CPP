#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Symptom 
{
	protected:
		int symptomID; // mã triệu chứng
		string name; // triệu chứng
		string typeRisk; // low, medium or high risk

	public:
		// Hàm khởi tạo không tham số
		Symptom(){
			this->symptomID = 0;
			this->name = "";
			this->typeRisk = "";
		}

		// Hàm khởi tạo có tham số
		Symptom(int symptomID, string name, string typeRisk)
		{
			this->symptomID = symptomID;
			this->name = name;
			this->typeRisk = typeRisk;
		}

		~Symptom(){
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