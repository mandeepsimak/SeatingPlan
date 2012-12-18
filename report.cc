#include "report.h"

// Constructor for initialising values

Report :: Report()
{
   tab = "\t";
   newline = "\n";
   
   i = j = k = 0;
   
   // HTML Tag Variables
   bold = "<b>";  cbold = "</b>";
   table = "<table border = \"1\" align = \"center\" cellpadding = \"4\" >";   ctable = "</table>";
   th = "<th>";   cth = "</th>";
   tr = "<tr>";   ctr = "</tr>";
   td = "<td width = \"80\" height = \"30\" align = \"center\">";   ctd = "</td>";
   brk = "<br>";
   div = "<div>";
   cdiv = "</div>";
   
   htmlstart = "<html> <head> <title>Seating Plan</title> </head> <body align = \"center\"> ";
   htmlend = "</body></html>";
   // <style> div{ page-break-before: always; } </style> 
}

// Getting Allotment Details from "FinalAllotment.out" File

void Report :: getAllotmentDetails()
{
   infile.open(FinalAllotment_out);
   
   infile >> total_rooms;
   
   for( i = 0; i < total_rooms; i++)
   {
      infile >> room_no[i] >> rows[i] >> cols[i];
      
      for(j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            infile >> seat[i][j][k];
         }
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

   if(rno > 0)
   {
      for(int m = 0; m < total_branches; m++)
      {
         for(int n = 0; n < total_rno[i]; n++)
         {
            if (rno == rollno[m][n])
            {
               brnch = branch_name[m];
               break;
            }
         }
      }
   }
   
   else
      brnch  = " ";
  
	return brnch;
}

// Adding Branch Name

void Report :: addBranchName()
{
   cout << "\n\t Add Branch Name with roll nos(Y/N): ";
   cin >> ans;
   cout << newline;
   
//   if ( ans == 'Y' || ans == 'y')
//      branchName(rno);
//   else
//      cout << "\n\t\t NOT ADDED!" << endl;
   
}

// Generating Report

void Report :: generateReport()
{
   
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

// Creating File

void Report :: createFile(const char* File)
{

   addBranchName();
   outfile.open(File);
   
   for( i = 0; i < total_rooms; i++)
   {
      outfile << tab << tab << "Room: " << room_no[i] << newline
              << tab << tab << exam_name << newline
              << tab << tab << "Date:" << exam_date 
              << tab << "Time: " << exam_time << newline
              << tab << tab << exam_venue << newline << newline;
      
      for( j = 0; j < rows[i]; j++)
      {
         for(k = 0; k < cols[i]; k++)
         {
            if ( ans == 'Y' || ans == 'y')
               outfile << branchName(seat[i][j][k]) << " " << seat[i][j][k] << tab;
            else
               outfile << seat[i][j][k] << tab;
         }
         
         outfile << newline;
      }
      outfile << newline;
      
   }
   
   outfile.close();
}

// Creating Text File

void Report :: createTextFile()
{
   createFile(TextFile);
}

// Creating CSV File

void Report :: createCSVFile()
{
   createFile(CSVFile);
   //system("SeatPlan.txt > SeatPlan.csv");
}

// Creating HTML File

void Report :: createHTMLFile()
{
   if (choice == 2)
      tab = "&nbsp &nbsp &nbsp &nbsp &nbsp";
   else
      tab = "     ";
//   newline = "<br>";
//   createFile(HTMLFile);

   addBranchName();
   outfile.open(HTMLFile);
   
   outfile << htmlstart << brk;
   
   for( i = 0; i < total_rooms; i++)
   {
   
      outfile << "<p style=\"page-break-after:always\">";
      outfile << div;
      outfile << bold << "Room: " << room_no[i] << brk
              << exam_name << brk
              << "Date: " << exam_date << tab 
              << "Time: " << exam_time << brk
              << exam_venue << cbold << brk << brk;
              
      outfile << table << brk;
      
      outfile << tr;
      for( j = 0; j < (cols[i] + 1); j++)
      {
         outfile << th << j << cth;
      }
      outfile << ctr;
      
      for( j = 0; j < rows[i]; j++)
      {
         outfile << tr;
         outfile << td << bold << (j + 1) << cbold << ctd;
         for(k = 0; k < cols[i]; k++)
         {
            
            if ( ans == 'Y' || ans == 'y')
               outfile << td << branchName(seat[i][j][k]) << " " << seat[i][j][k] << ctd;
            else
               outfile << td << seat[i][j][k] << ctd;
         }
         
         outfile << ctr;
         
      }
      outfile << ctable;
      outfile << brk;
      
      outfile << cdiv;
   }
   
   outfile << htmlend;
   
   outfile.close();
   
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
