#include<iostream>
#include<fstream>
using namespace std;
class verification
{
	public:
	int rows[13], cols[13], totalRoom, totalBranches, groupSeats, groupStudents, totalSeats, 
		strategyChoice, branchStudent[50], subjectStudent[500], subjectRoll[100][500];
	int branchArray[12], min, max, minPos,groupArray[7];
	string  branchCode[15], roomName[20];
	ifstream inFile;
	ofstream outFile;
	int i,j;
	
	//methods
	void getInput();
	void checkValidation( int );
	int roomsCapacity();
	void methodSelection();
	int maxStudent(int);
	void display(int);
};
