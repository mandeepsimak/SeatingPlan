#include "report.h"

// Constructor for initialising values

Report :: Report()
{
   tab = "\t";
   newline = "\n";
   
   i = j = k = 0;
}

// Getting Allotment Details from "FinalAllotment.out" File

void Report :: getAllotmentDetails()
{
   infile.open(FinalAllotment_out);
   
   infile >> total_rooms;
   cout << total_rooms << endl;
   
   for( i = 0; i < total_rooms; i++)
   {
      infile >> room_no[i] >> rows[i] >> cols[i];
      
      for(j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            infile >> seat[i][j][k];
            cout << seat[i][j][k] << "\t";
         }
         cout << "\n";
      }
   }
   
   infile.close();
}

// Getting Roll No and Branch Details from "FinalAllotment.out" File

void Report :: getRollNoDetails()
{
   infile.open(input_rollno_out);
   
   infile >> total_branches;
   
   for(i = 0; i < total_branches; i++)
   {
      infile >> branch_name[i] >> sub_code[i] >> total_rno[i];
      
      for(j = 0; j < total_rno[i]; j++)
      {
         infile >> rollno[i][j];
      }
   }
   
   infile.close();
}

// Get Examination Details

void Report :: getExamDetails()
{
   cout << "\n\n\t Enter Examination Details \n" << endl
        << "\t\t Examination Name: ";
   cin >> exam_name;
   
   cout << "\n\t\t Date: ";
   cin >> exam_date;
   
   cout << "\n\t\t Time: ";
   cin >> exam_time;
   
   cout << "\n\t\t Venue: ";
   cin >> exam_venue;
   
   cout << endl;
}

// Getting Branch Name accord. to roll no

string Report :: branchName(int rno)
{
   string brnch = " ";

   if(rno == 0)
      brnch = " ";
   
   else
   {
      for(int m = 0; m < total_branches; m++)
      {
         for(int n = 0; n < total_rno[i]; n++)
         {
            if (rno == rollno[m][n])
            {
               brnch = sub_code[m];
               break;
            }
         }
      }
   }
  
	return brnch;
}

// Adding Branch Name

void Report :: addBranchName(int rno)
{
   cout << "\n\t Add Branch Name with roll nos(Y/N): ";
   cin >> ans;
   
   if ( ans == 'Y' || ans == 'y')
      branchName(rno);
   else
      cout << "\n\t\t NOT ADDED!" << endl;
   
}

// Generating Report

void Report :: generateReport()
{
   getAllotmentDetails();
   getRollNoDetails();

   cout << "\n\t Generating Outfile for Seating Plan" << endl;
   
   cout << "\t Choose your file type.\n" << endl
        << " 1. Text File" << endl
        << " 2. HTML File" << endl
        << " 3. CSV File" << endl
        << " 4. All Files " << endl
        << "\n Enter Choice: ";
   cin >> choice; 
   
   switch(choice)
   {
      case 1:
         createTextFile();
         break;
         
      case 2:
         createHTMLFile();
         break;
         
      case 3:
         createCSVFile();
         break;
         
      case 4:
         createAllFiles();
         break;
         
      default:
         createTextFile();
         break;
   }
   
}

// Creating Text File

void Report :: createTextFile()
{
   outfile.open(TextFile);
   
   tab = "\t\t\t";
   
   for( i = 0; i < total_rooms; i++)
   {
      outfile << tab << room_no[i] << endl
              << tab << exam_name << endl
              << tab << exam_date << tab << exam_time << endl
              << tab << exam_venue << newline << endl;
      
      for( j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            outfile << seat[i][j][k] << tab;
         }
         
         outfile << newline;
      }
      
   }
   
   outfile.close();
}

// Creating CSV File

void Report :: createCSVFile()
{

}

// Creating HTML File

void Report :: createHTMLFile()
{

}

// Creating All Files

void Report :: createAllFiles()
{

}

// Method for calling all functions

void Report :: Main()
{
   getAllotmentDetails();
   getRollNoDetails();

   getExamDetails();
   
   generateReport();
}
