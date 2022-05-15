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
			return symptomID;
		}
		void setSymptomID(int symptomID) {
			this->symptomID = symptomID;
		}
		string getName() {
			return name;
		}
		void setName(string name) {
			this->name = name;
		}
		string getTypeRisk() {
			return typeRisk;
		}
		void setTypeRisk(string typeRisk) {
			this->typeRisk = typeRisk;
		}

		friend istream & operator>>(istream &is, Symptom &patient)
		{
			cout << "Enter symptom id: "; is >> patient.symptomID;
			is.ignore();
			cout << "Enter name: "; is >> patient.name;
			cout << "Enter type risk: "; is >> patient.typeRisk;
			return is;
		}

		friend ostream & operator<<(ostream & os, Symptom &patient)
		{
			os << "---------------SYMPTOM----------------" << endl;
			os << "symptom id: " << patient.symptomID << endl;
			os << "name: " << patient.name << endl;
			os << "type risk: " << patient.typeRisk << endl;
			return os;
		}


	
};