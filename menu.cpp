#include <iostream>
#include <string.h>
#include <iomanip>
#include "PatientDetail.cpp"
#include "Location.cpp"
#include "Symptom.cpp"

using namespace std;

class menu
{
    public:
		PatientDetail listPatientDetail[100];
		int numPatientDetail = 0;
		Location listLocation[100];
		int numLocation = 0;
		Symptom listSymptom[100];
		int numSymptom = 0;

		void readFilePatientDetail(){
			string patientID, name, dOB, address, phoneNumber, visitedLocation, dateTime, lastOverseasTravel, listSymptom, covidTest, status;
			ifstream file("COVID_Patient_data.txt",ios::in);
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numPatientDetail;
			for (int i = 0; i < numPatientDetail; i++) {
				//Đọc từng dòng trong file
				getline(file, patientID, ',');
				getline(file, name, ',');
				getline(file, dOB, ',');	
				getline(file, address, ',');
				getline(file, phoneNumber, ',');
				getline(file, visitedLocation, ',');
				getline(file, dateTime, ',');
				getline(file, lastOverseasTravel, ',');
				getline(file, listSymptom, ',');
				getline(file, covidTest, ',');
				getline(file, status, '\n');
				PatientDetail temp {atoi (patientID.c_str()), name, dOB, address, phoneNumber, visitedLocation, dateTime, lastOverseasTravel, listSymptom, covidTest, status};
				listPatientDetail[i] = temp;
			}
			//Đóng file
			file.close();
		}

		void writeFilePatientDetail()
		{
			ofstream file("COVID_Patient_data.txt",ios::out);
			file << numPatientDetail << endl;
			for (int i = 0; i < numPatientDetail; i++) {
				file << listPatientDetail[i].getPatientID() << ",";
				file << listPatientDetail[i].getName() << ",";
				file << listPatientDetail[i].getdOB() << ",";
				file << listPatientDetail[i].getAddress() << ",";
				file << listPatientDetail[i].getPhoneNumber() << ",";
				file << listPatientDetail[i].getVisitedLocation() << ",";
				file << listPatientDetail[i].getDateTime() << ",";
				file << listPatientDetail[i].getLastOverseasTravel() << ",";
				file << listPatientDetail[i].getSymptoms() << ",";
				file << listPatientDetail[i].getCovidTest() << ",";
				file << listPatientDetail[i].getStatus() << endl;
			}
			//Đóng file
			file.close();
		}

		void readFileSymptom(){
			string line;
			ifstream file("COVID_Symptom_data.txt",ios::in);
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numSymptom;
			for (int i = 0; i < numSymptom; i++) {
				//Đọc từng dòng trong file
				getline(file, line, ',');
				listSymptom[i].setSymptomID(atoi(line.c_str()));
				getline(file, line, ',');
				listSymptom[i].setName(line);
				getline(file, line, '\n');
				listSymptom[i].setTypeRisk(line);
			}
			//Đóng file
			file.close();
		}

		void writeFileSymptom()
		{
			ofstream file("COVID_Symptom_data.txt",ios::out);
			file << numSymptom << endl;
			for (int i = 0; i < numSymptom; i++) {
				file << listSymptom[i].getSymptomID() << ",";
				file << listSymptom[i].getName() << ",";
				file << listSymptom[i].getTypeRisk() << endl;
			}
			file.close();
		}

		void readFileLocation(){
			string line;
			ifstream file("COVID_Location_data.txt",ios::in);
			if(!file){
				cout << "Error:can not open file";
				return;
			}
			file >> numLocation;
			for (int i = 0; i < numLocation; i++) {
				//Đọc từng dòng trong file
				getline(file, line, ',');
				listLocation[i].setLocationID(atoi(line.c_str()));
				getline(file, line, '\n');
				listLocation[i].setLocation(line);
			}
			//Đóng file
			file.close();
		}

		void writeFileLocation()
		{
			ofstream file("COVID_Location_data.txt",ios::out);
			file << numLocation << endl;
			for (int i = 0; i < numLocation; i++) {
				file << listLocation[i].getLocationID() << ",";
				file << listLocation[i].getLocation() << endl;
			}
			file.close();
		}

		// Check exist of Patient ID?
		bool checkPatientID(int id) {
			for (int i = 0; i < numPatientDetail; i++) {
				if (listPatientDetail[i].getPatientID() == id) {
					return true;
				}
			}
			return false;
		}

		// Check high risk base on symptom id
		bool checkHighRiskBySymptomID(int id) {
			for (int i = 0; i < numSymptom; i++) {
				if (listSymptom[i].getSymptomID() == id && listSymptom[i].getTypeRisk() == "high risk") {
					return true;
				}
			}
			return false;
		}

		// Check high risk of list symptom id
		bool checkHighRisk(string listSymptomID) {
			// refer to https://laptrinhcanban.com/cpp/lap-trinh-cpp-co-ban/chuoi-string-trong-cpp/tach-chuoi-trong-cpp/
			char* char_arr;
			char_arr = &listSymptomID[0];
			const char s[2] = " ";
			char *token;

			token = strtok(char_arr, s);
			while(token != NULL)
			{
				if (checkHighRiskBySymptomID(atoi(token))) {
					return true;
				}
				token = strtok(NULL, s);
			}
			return false;
		}

		string recommendCOVIDTest(string visitedLocation, string symptoms) {
			if (visitedLocation != "" && symptoms != "") {
				return "You should go to for TEST";
			} 
			else if (visitedLocation != "" && symptoms == "") {
				return "isolate yourself at home";
			}
			else if (visitedLocation == "" && symptoms == "") {
				return "isolate yourself at home";
			}
			else if (visitedLocation == "" && checkHighRisk(symptoms)) {
				return "You should go to for TEST";
			}
			else if (visitedLocation == "" && !checkHighRisk(symptoms)) {
				return "isolate yourself at home";
			}
			return "You should go to for TEST";
		}

		string getLocationByLocationID(int locationID) {
			for (int i = 0; i < numLocation; i++) {
				if (listLocation[i].getLocationID() == locationID) {
					return listLocation[i].getLocation();
				}
			}
			return "";
		}

		string getLocation(string listLocationID) {
			string result = "";
			char* char_arr;
			char_arr = &listLocationID[0];
			const char s[2] = " ";
			char *token;
		
			token = strtok(char_arr, s);
			while(token != NULL)
			{
				char *temp = token;
				token = strtok(NULL, s);
				result = result + temp + ", " + getLocationByLocationID(atoi(temp)) + "\n";
			}
			return result;
		}

		string getSymptomBySymptomID(int symptomID) {
			for (int i = 0; i < numLocation; i++) {
				if (listSymptom[i].getSymptomID() == symptomID) {
					return listSymptom[i].getName();
				}
			}
			return "";
		}

		string getSymptom(string listSymptomID) {
			string result = "";
			char* char_arr;
			char_arr = &listSymptomID[0];
			const char s[2] = " ";
			char *token;
		
			token = strtok(char_arr, s);
			while(token != NULL)
			{
				char *temp = token;
				token = strtok(NULL, s);
				result = result + temp + ", " + getSymptomBySymptomID(atoi(temp)) + "\n";
			}
			return result;
		}

		// Check exist of Patient ID who positive?
		bool checkPatientIDPositive(int id) {
			for (int i = 0; i < numPatientDetail; i++) {
				if (listPatientDetail[i].getPatientID() == id && listPatientDetail[i].getCovidTest() == "Positive") {
					return true;
				}
			}
			return false;
		}

		// Nhap lua chon theo menu de thuc hien
        void executeByMenu()
		{
			readFilePatientDetail();
			if (numPatientDetail == 0) {
				cout << "[] - the database is empty" << endl;
				exit(1);
			}
			readFileSymptom();
			if (numSymptom == 0) {
				cout << "Unable to recommend COVID Test – required data missing" << endl;
				exit(1);
			}
			readFileLocation();

			int choose;
			do
			{
				cout << "\n ====================== Recommend the COVID Test =====================" << endl;
				cout << " | 1- Enter your detail for COVID-Test Recommendation                |" << endl;
				cout << " | 2- Submit Your Covid test status & Update the Location database   |" << endl;
				cout << " | 3- Display the Updated Location (High Risk for COVID)             |" << endl;
				cout << " | 4- Update COVID Patient Details           			     |" << endl;
				cout << " | 5- Display the COVID Positive Patient Detail                      |" << endl;
				cout << " | 6- Quit                       		   		     |" << endl;
				cout << " =====================================================================" << endl;
        	    cout << "Enter choose: "; cin >> choose;

        	    switch(choose)
        	    {
        	    	case 1:
        	    		{
							int patientID;
							string name, dOB, address, phoneNumber, lastOverseasTravel, symptoms = "", visitedLocation = "", dateTime;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(checkPatientID(patientID));
							cin.ignore();
							cout << "Enter name: "; getline(cin, name);
							cout << "Enter date of birth: "; getline(cin, dOB);
							cout << "Enter address: "; getline(cin, address);
							cout << "Enter phone number: "; getline(cin, phoneNumber);
							cout << "Enter last overseas travel (Yes or No): "; getline(cin, lastOverseasTravel);
							if (lastOverseasTravel == "Yes") {
								cout << "Enter date time: "; getline(cin, dateTime);
							}
							for (int i = 0; i < numLocation; i++) {
								cout << listLocation[i].getLocationID() << ". " << listLocation[i].getLocation() << endl;
							}
							cout << "Select id of visited location: "; getline(cin, visitedLocation);
							for (int i = 0; i < numSymptom; i++) {
								cout << listSymptom[i].getSymptomID() << ". " << listSymptom[i].getName() << endl;
							}
							cout << "Select id of symptoms: "; getline(cin, symptoms);
							PatientDetail temp(patientID, name, dOB, address, phoneNumber, lastOverseasTravel, symptoms, visitedLocation, dateTime);
							listPatientDetail[numPatientDetail++] = temp;
							writeFilePatientDetail();
							cout << recommendCOVIDTest(visitedLocation, symptoms) << endl;
        	    			break;
						}
					case 2:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientID(patientID));
							cin.ignore();
							string covidTest;
							cout << "Enter result of test covid (Positive or Negative): "; getline(cin, covidTest);
							if (covidTest == "Positive") {
								int numVisitedLocation = 0;
								string visitedLocation[100];
								string listLocationID = "";
								cout << "Enter number of visited location: "; cin >> numVisitedLocation;
								cin.ignore();
								for (int i = 1; i <= numVisitedLocation; i++) {
									cout << "Enter visited location " << i << ": "; getline(cin, visitedLocation[i]);
									listLocation[numLocation].setLocationID(numLocation + 1);
									listLocation[numLocation].setLocation(visitedLocation[i]);
									numLocation++;
									writeFileLocation();
									listLocationID += to_string(numLocation) + " ";
								}
								for (int i = 0; i < numPatientDetail; i++) {
									if (listPatientDetail[i].getPatientID() == patientID) {
										listPatientDetail[i].setCovidTest(covidTest);
										listPatientDetail[i].setVisitedLocation(listLocationID);
										writeFilePatientDetail();
									}
								}
							}
							break;
						}                  				
					case 3:
					    {
							cout << "====================== THE LOCATION FOR HIGH-RISK LOCATION===========================" << endl;
							cout << "Location ID" << "		Location" << endl;
					    	for (int i = 0; i < numLocation; i++) {
								cout << listLocation[i].getLocationID() << "		" << listLocation[i].getLocation() << endl;
							}
					    	break;
						}					
                    case 4:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientIDPositive(patientID));
							cin.ignore();
							string status;
							cout << "Enter status of patient (Cured or Dead): "; getline(cin, status);
							
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getPatientID() == patientID) {
									if (status == "Cured") {
										listPatientDetail[i].setCovidTest("Negative");
										listPatientDetail[i].setStatus("Alive");
									}
									else {
										listPatientDetail[i].setStatus("Dead");
									}
									
								}
							}
							
							writeFilePatientDetail();
							break;
						}
                    case 5:
                        {
							cout << "====================== THE COVID POSITIVE PATIENTS DETAIL===========================" << endl;
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getCovidTest() == "Positive") {
									cout << "Patient ID: " << listPatientDetail[i].getPatientID() << endl;
									cout << "Visited Location: " << endl << getLocation(listPatientDetail[i].getVisitedLocation());
									cout << "Last Overseas Travel: " << listPatientDetail[i].getLastOverseasTravel() << endl;
									cout << "Date time: " << listPatientDetail[i].getDateTime() << endl;
									cout << "Symptom: " << endl << getSymptom(listPatientDetail[i].getSymptoms()) << endl;
								}
							}
                            break;
                        }
					case 6:
					    {
					    	cout << "Goodbye" << endl;
                            exit(1);
						}	
                    default :
                        {
                            cout << "Unknown selection, please try again" << endl;
                        }
				}
			}
			while(choose != 6);
		}
};
