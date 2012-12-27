#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

#include "files.h"

using namespace std;

const int MIN_SIZE = 50;
const int MAX_SIZE = 100;

class RoomReport
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
   int i, j, k, m, n;
   
   // Switch statement variable
   int choice;
   char ans;
   
   // Examination Variables
   string exam_name, exam_date, exam_time, exam_venue;
   
   // File Stream Variables
   ifstream infile;
   ofstream outfile;
   
   string tab, newline;
   
   // HTML Tag variables
   string bold, cbold, table, ctable, th, tr, td, cth, ctr, ctd,
          htmlstart, htmlend, brk, div, cdiv;
      
   public:
   
   RoomReport();
   
   void getAllotmentDetails();
   void getRollNoDetails();
   
   void getExamDetails();
   
   void addBranchName();
   string branchName(int);
   
   void totalStudents();
   
   void generateReport();
   
   void createFile(const char*);
   void createCSVFile();
   void createHTMLFile();
   void createTextFile();
   void createAllFiles();
   void createPDFFile();
   
   void Main();
   
};

class BranchReport : public RoomReport
{
   public:
   
   BranchReport();
   void Main();
   void createBranchReport();
   string checkRoom(int);
   
};
