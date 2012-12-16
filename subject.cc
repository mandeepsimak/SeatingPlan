#include "subject.h"

void subject :: get_details()
{
    infile.open(input_rollno_out);
    infile>>total_branches;
    for(i = 0; i < total_branches; i++)
    {
        infile>>branch_name[i]>>sub_code[i]>>total_rno[i];
        for(j = 0; j < total_rno[i]; j++)
        {
            infile>>rollno[i][j];
        }
    }
    infile.close();
}

void subject :: arrange_rollno()
{
    // Putting values of subject code into another array set_code
    for(i = 0; i < total_branches; i++)
    {
        set_code[i] = sub_code[i];
    }
    
    // Removing redundancy from set_code array
    total_code = total_branches;
    
    for(k = 0; k < total_code; k++)
    {
        for(i = k+1; i < total_code; i++)
        {
            if(set_code[i] == set_code[k])
            {
                for(j = i; j < total_code; j++)
                {
                    set_code[j] = set_code[j+1];   
                }
                total_code--;  
                //i = i-1;
            }
        }
    }
    
    // Displaying values of set_code
    cout<<" ----------------------------------------------------"<<endl
        <<"          Non redundant subject codes"<<endl
        <<" ----------------------------------------------------"<<endl;
    for(i = 0; i < total_code; i++)
    {
        cout<<'\t'<<set_code[i]<<'\n';
        set_rno[i] = 0;
    }
    //sleep(delay);
    
    // adding roll nos
    for(i = 0; i < total_branches; i++)
    {
        for(j = 0; j < total_code; j++)
        {
            if(set_code[j] == sub_code[i])
            {
//                cout<<"\nsub: "<<set_code[j]<<endl;
                for(k = 0; k < total_rno[i]; k++)
                {
                    set_rollno[j][(k + set_rno[j])] = rollno[i][k];
                }
                set_rno[j] += total_rno[i];
            }
        }

    }
    
//    // displaying roll nos.
//    cout<<"----------------------------------------------------"<<endl
//        <<"Final Roll no array which is used for sitting plan"<<endl
//        <<"----------------------------------------------------"<<endl;
//    for(i = 0; i < total_code; i++)//SizeOfArray(set_rollno)
//    {
//        cout<<'\n'<<set_code[i]<<endl;
//        for(j = 0; j < set_rno[i]; j++)//SizeOfArray(set_rollno[0])
//        {
//            cout<<set_rollno[i][j]<<"\t";
//        }
//    }

    cout << "\n Roll nos are arranged according to subject codes.\n";
    //sleep(delay); 
    cout << "Output of Subject code Module placed in: " << subject_rollno_out << endl;
    //sleep(delay);  
    outfile.open(subject_rollno_out);
    outfile<<total_code<<endl;
    for(i = 0; i < total_code; i++)//SizeOfArray(set_rollno)
    {
//        outfile<<'\n'<<set_code[i]<<endl;
        outfile << set_code[i] << " " << set_rno[i] << ' ';
        for(j = 0; j < set_rno[i]; j++)//SizeOfArray(set_rollno[0])
        {
            outfile<<set_rollno[i][j]<<"\t";
        }
        outfile<<endl;
    }
    outfile.close();
    
}

void subject :: show_details()
{
    cout<<"----------------------------------------------------"<<endl
        <<"Input file"<<endl
        <<"----------------------------------------------------"<<endl;
    for(i = 0; i < total_branches; i++)
    {
        cout<<branch_name[i]<<'\t'<<sub_code[i]<<"\t"<<total_rno[i]<<endl;
        for(j = 0; j < total_rno[i]; j++)
        {
            cout<<rollno[i][j]<<'\t';
        }
        cout<<'\n'<<endl;
    }
}
