#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdio>
#include "files.h"

using namespace std;

const int MIN_SIZES = 50;
const int MAX_SIZES = 100;

class RollNo
{
    int rollno[MIN_SIZES][MAX_SIZES], total_rno[MIN_SIZES], total_branches, 
        set_rollno[MIN_SIZES][MAX_SIZES], n, set_trno[MIN_SIZES],
        i, j, k, total_rooms, rows[MIN_SIZES], cols[MIN_SIZES], row, col,
        seat[MIN_SIZES][MIN_SIZES][MAX_SIZES], x, y, z, X, Y, C, D;//, Z, A, B;
    
    string branch_name[MIN_SIZES], room_no[MIN_SIZES], subjectCode[MIN_SIZES];
    
    static int A, B, Z;
    
    ifstream infile;
    ofstream outfile;
    
    public:
    RollNo();
    void get_details();
    void show_details();
    void arrange_rollno(int strategy);
    void seat_alot(int strategy);
    void next_rollno(int strategy);
};

