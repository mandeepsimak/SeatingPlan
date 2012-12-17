#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "files.h"

using namespace std;

const int MIN_SIZE = 50;
const int MAX_SIZE = 100;

class Report
{
   protected:
   
   // Allotment Details
   int total_rooms, rows[MIN_SIZE], cols[MIN_SIZE],
       seat[MIN_SIZE][MIN_SIZE][MAX_SIZE];
   
   string room_no[MIN_SIZE];
       
   // Roll No Details
   int total_branches, total_rno[MIN_SIZE], rollno[MIN_SIZE][MAX_SIZE];
   
   string branch_name[MIN_SIZE], sub_code[MIN_SIZE];
   
   //Loop variables
   int i, j, k;
   
   // Switch statement variable
   int choice;
   char ans;
   
   // Examination Variables
   string exam_name, exam_date, exam_time, exam_venue;
   
   // File Stream Variables
   ifstream infile;
   ofstream outfile;
   
   string tab, newline;
      
   public:
   
   Report();
   
   void getAllotmentDetails();
   void getRollNoDetails();
   
   void getExamDetails();
   
   void addBranchName();
   string branchName(int);
   
   void totalStudents();
   
   void generateReport();
   
   void createCSVFile();
   void createHTMLFile();
   void createTextFile();
   void createAllFiles();
   
   void Main();
   
};
