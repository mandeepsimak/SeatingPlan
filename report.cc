#include "report.h"

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
}

// Generating Report

void Report :: generateReport()
{

}

// Method for calling all functions

void Report :: Main()
{
   getAllotmentDetails();
   getRollNoDetails();
   generateReport();
}
