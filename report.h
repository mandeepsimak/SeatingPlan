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
   int total_rooms, room_no[MIN_SIZE], rows[MIN_SIZE], cols[MIN_SIZE],
       seat[MIN_SIZE][MIN_SIZE][MAX_SIZE];
       
   // Roll No Details
   int total_branches, total_rno[MIN_SIZE], rollno[MIN_SIZE][MAX_SIZE];
   
   string branch_name[MIN_SIZE], sub_code[MIN_SIZE];
   
   //Loop variables
   int i, j, k;
   
   // Switch statement variable
   int choice;
   char ans;
   
   // File Stream Variables
   ifstream infile;
   ofstream outfile;
      
   public:
   
   void getAllotmentDetails();
   void getRollNoDetails();
   
   void generateReport();
   
   void Main();
   
};
