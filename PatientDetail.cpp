#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class PatientDetail 
{
	protected:
		int patientID; // mã bệnh nhân
		string name; // tên bệnh nhân
		string dOB; // ngày sinh
		string address; // địa chỉ
		string phoneNumber; // số điện thoại
		string visitedLocation; // nơi thăm khám có nguy cơ bị COVID
		string dateTime; // thời gian đi thăm khám
		string lastOverseasTravel; // đã đi du lịch nước ngoài gần đây?
		string symptoms; // danh sách các triệu chứng mà bệnh nhân gặp phải
		string covidTest; // đã kết quả test COVID?
		string status; // tình trạng của bệnh nhân

	public:
		// Hàm khởi tạo không tham số
		PatientDetail(){
			this->patientID = 0;
			this->name = "";
			this->dOB = "";
			this->address = "";
			this->phoneNumber = "";
			this->visitedLocation = "";
			this->dateTime = "";
			this->lastOverseasTravel = "";
			this->symptoms = "";
			this->covidTest = "";
			this->status = "";
		}

		// Hàm khởi tạo có tham số
		PatientDetail(int patientID, string name, string dOB, string address, string phoneNumber, string visitedLocation,
						string dateTime, string lastOverseasTravel, string symptoms, string covidTest, string status)
		{
			this->patientID = patientID;
			this->name = name;
			this->dOB = dOB;
			this->address = address;
			this->phoneNumber = phoneNumber;
			this->visitedLocation = visitedLocation;
			this->dateTime = dateTime;
			this->lastOverseasTravel = lastOverseasTravel;
			this->symptoms = symptoms;
			this->covidTest = covidTest;
			this->status = status;
		}
		
		int getPatientID() {
			return this->patientID;
		}
		void setPatientID(int patientID) {
			this->patientID = patientID;
		}
		string getName() {
			return this->name;
		}
		void setName(string name) {
			this->name = name;
		}
		string getdOB() {
			return this->dOB;
		}
		void setdOB(string dOB) {
			this->dOB = dOB;
		}
		string getAddress() {
			return this->address;
		}
		void setAddress(string address) {
			this->address = address;
		}
		string getPhoneNumber() {
			return this->phoneNumber;
		}
		void setPhoneNumber(string phoneNumber) {
			this->phoneNumber = phoneNumber;
		}
		string getVisitedLocation() {
			return this->visitedLocation;
		}
		void setVisitedLocation(string visitedLocation) {
			this->visitedLocation = visitedLocation;
		}
		string getDateTime() {
			return this->dateTime;
		}
		void setDateTime(string dateTime) {
			this->dateTime = dateTime;
		}
		string getLastOverseasTravel() {
			return this->lastOverseasTravel;
		}
		void setLastOverseasTravel(string lastOverseasTravel) {
			this->lastOverseasTravel = lastOverseasTravel;
		}
		string getSymptoms() {
			return this->symptoms;
		}
		void setSymptoms(string symptoms) {
			this->symptoms = symptoms;
		}
		string getCovidTest() {
			return this->covidTest;
		}
		void setCovidTest(string covidTest) {
			this->covidTest = covidTest;
		}
		string getStatus() {
			return this->status;
		}
		void setStatus(string status) {
			this->status = status;
		}

		PatientDetail(int patientID, string name, string dOB, string address, string phoneNumber, string lastOverseasTravel, string symptoms, string visitedLocation, string dateTime) {
			this->patientID = patientID;
			this->name = name;
			this->dOB = dOB;
			this->address = address;
			this->phoneNumber = phoneNumber;
			this->visitedLocation = visitedLocation;
			this->dateTime = dateTime;
			this->lastOverseasTravel = lastOverseasTravel;
			this->symptoms = symptoms;
			this->covidTest = "";
			this->status = "";
		}	
};