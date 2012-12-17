#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "files.h"

using namespace std;

const int MIN_SIZE = 50;
const int MAX_SIZE = 100;

class subject
{
   protected:
    int rollno[MIN_SIZE][MAX_SIZE], total_rno[MIN_SIZE], total_branches, 
        total_code, set_rollno[MIN_SIZE][MAX_SIZE], set_rno[MIN_SIZE],
        i, j, k;
    
    string sub_code[MIN_SIZE], branch_name[MIN_SIZE], set_code[MIN_SIZE];
    
    ifstream infile;
    ofstream outfile;
    
    public:
    
    void get_details();
    void show_details();
    void arrange_rollno();
};
