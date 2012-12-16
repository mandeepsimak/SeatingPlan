// Class member function declaration
#include "input.h"

input :: input()
{
//   cout<<"<b>hello</b>";
}

void input :: room_details()	// get room details
{
    //file.open(in, ios::in, ios::out);
	infile>>t_rooms;
	for(i=0; i<t_rooms; i++)
	{
		infile >> room_no[i] >> rows[i] >> cols[i];
	}
}

void input :: rollno_details()	// get roll no details
{
	string Rollno;
	infile>>t_branches;
	for(i=0; i<t_branches; i++)
	{
		infile >> branch_name[i] >> subcode[i];
		//rollno[i] = infile.getline();
		getline(infile, rollno[i], '\n');
	}
}

void input ::  input_in_details()	// read input(input.in) file
{
   system("clear");
	cout<<"\n\t Enter input file name(input.in): ";
	cin>>input_file;
	//input_file = "input.in";
	infile.open(input_file);
	room_details();
	rollno_details();
	infile.close();
}

void input :: expand(string rno)	// process input.in file and 
{								// generate input_sort.out file
	istringstream rollNo(rno);
	deque<int> v;
	
	bool success = parse_number_list_with_ranges(rollNo, back_inserter(v));
	if (success)
	{
		outfile << v.size()<<endl;
		copy(v.begin(), v.end()-1, ostream_iterator<int>(outfile, " "));
		
		outfile << v.back()<<endl;
								
	}
	else
	outfile << " An error occured.\n";
	
}

void input :: add_seperator(string &rno)
{
   int sz = rno.size()+1;
   char largchar[sz];// = roll[i].c_str();//"1-10 12 34 15 20 25-30";
   strcpy(largchar,rno.c_str());
   char* chars_array = strtok(largchar, " ");
   
   a="0";
   while(chars_array)
   {
      if(chars_array!="-")
      {
         a.append(",");
         a.append(chars_array);//atoi (chars_array));//n++;
      }
     	chars_array = strtok(NULL, " ");
   }
   
   rno = a;
   
}

void input :: remove_zero()
{
   infile.open(input_expand_out);
	for(i=0; i<t_branches; i++)
	{
		infile >> roll_size[i];
		for(int j=0; j<roll_size[i]; j++)
		{
			infile >> roll_no[i][j];
		}
	}
	infile.close();
	
	for(i=0; i<t_branches; i++)
	{
		for(int j=0; j<roll_size[i]-1; j++)
		{
			roll_no[i][j] = roll_no[i][j+1];
			//infile >> remove[j];
		}
		roll_size[i]--;
	}
	
	outfile.open(input_expand_out);
	for(i=0; i<t_branches; i++)
	{
		outfile << roll_size[i] << endl;
		for(int j=0; j<roll_size[i]; j++)
		{
			outfile << roll_no[i][j] << " ";
		}
		outfile << endl;
	}
	outfile.close();
}

void input :: roll_no_processing()	// Expanding, sorting, removing 
								// duplicate entries
{

	// Writing expanded form of roll nos in file
	cout << "\n Roll Nos are expanded in '" << input_expand_out << "' file." << endl;
	//sleep(delay);
	outfile.open(input_expand_out);
	for(i=0; i<t_branches; i++)
	{
	   add_seperator(rollno[i]);
		expand(rollno[i]);
	}
	outfile.close();
	
	remove_zero();
	
	// Reading roll nos from file
	infile.open(input_expand_out);
	for(i=0; i<t_branches; i++)
	{
		infile >> roll_size[i];
		for(int j=0; j<roll_size[i]; j++)
		{
			infile >> roll_no[i][j];
		}
	}
	infile.close();
	
	cout << "\n Sorted and Non-Redundant Roll Nos are placed in '" << input_sorted_out << "' file." << endl;
	//sleep(delay);
	outfile.open(input_sorted_out);	
	// Sorting of roll nos.
	for(i=0;i<t_branches;i++)
	{
		for(j=0; j<roll_size[i]; j++)
		{
			rno[j] = roll_no[i][j];
		}
		
		sort(rno, rno+roll_size[i]);	// Sort function
		
		for(j=0; j<roll_size[i]; j++)
		{	// Removing duplicate values
			if(rno[j]==rno[j+1])// || rno[j+1]==rno[j+2])
			{
				//rno[j+1]=0;
				for(k=j; k<=roll_size[i]; k++) 
     		 	{
          			rno[k] = rno[k+1];  //shifts each element one position above
     			}
     			roll_size[i]--;
     			j=0;
			}
		}
				
		// Writing into file(input_sorted.out)
		outfile << roll_size[i] <<endl;
		for(j=0; j<roll_size[i]; j++)
		{
			 outfile << rno[j] << " ";
		}
		outfile <<endl;
		
//		cout << "\nRemoving Roll nos that are not eligible for exams." << endl;
		// Removing roll nos that are not for exam
		for(j=0; j<roll_size[i]; j++)
		{
			if(rno[j]<0)	
			{
				int a,b;
				a = rno[j];
				b = -1 * a;
			
				for(k=0; k<roll_size[i]; k++)
				{
					if(rno[k] == a || rno[k] == b)
					{
						//rno[j+1]=0;
						for (int l=k; l<=roll_size[i]; l++) 
    		 			{
    		      			rno[l] = rno[l+1];  //shifts each element one position above
    		 			}
    		 			roll_size[i]--;
    		 			//k=0;
					}
				}
				j--;
			}
		}
		for(j=0; j<roll_size[i]; j++)
		{
			roll_no[i][j] = rno[j];
		}
	}
	outfile.close();
		
	// Writing into file
	cout << "\n Completely Processed Roll nos are placed in '" << input_processed_out 
	     << "' file." << endl;
	//sleep(delay);
	outfile.open(input_processed_out);
	for(int i=0; i<t_branches; i++)
	{
		outfile << roll_size[i] <<endl;
		for(int j=0; j<roll_size[i]; j++)
		{
			 outfile << roll_no[i][j] << " ";
		}
		outfile <<endl;
	}
	outfile.close();
}

void input :: input_out_file()	// To display final o/p in file
{
   cout << "\n Output files of Input Processing Module:" << endl;
   cout << "\n Room Details File: " << input_rooms_out << endl;
   
	outfile.open(input_rooms_out);//, ios::out, ios::in, ios::app);
	outfile<<t_rooms<<endl;
	for(i=0; i<t_rooms; i++)
	{
		outfile<<room_no[i]<<" "<<rows[i]<<" "<<cols[i]<<endl;
	}
	outfile.close();
	
	cout << " Roll No Details File: " << input_rollno_out << "\n" << endl;
	//sleep(delay);
	outfile.open(input_rollno_out);
	outfile<<t_branches<<endl;
	for(i=0; i<t_branches; i++)
	{
		outfile<<branch_name[i]<<" "<<subcode[i]<<" "<< roll_size[i] << " " << endl;
		//string ss = itoa (rollno[i]);
		//expand(rollno[i]);
		for(j=0; j<roll_size[i]; j++)
		{
			outfile << roll_no[i][j] << " ";
		}
		outfile<<endl;
	}
	outfile.close();
}

template<typename OutIter>  // For expanding roll nos
bool input :: parse_number_list_with_ranges(istream& is, OutIter out)
{
	int number;
	// the list always has to start with a number
	while (is >> number)
	{
		*out++ = number;
		
		char c;
		if (is >> c)
			switch(c)
			{
				case ',':
					continue;
				case '-':
				{
					int number2;
					if (is >> number2)
					{
						if (number2 < number)
							return false;
						while (number < number2)
							*out++ = ++number;
						char c2;
						if (is >> c2)
							if (c2 == ',')
								continue;
							else
								return false;
						else
							return is.eof();
					}
					else
						return false;
				}
				default:
					return is.eof();
			}
		else
			return is.eof();
	}
	// if we get here, something went wrong (otherwise we would have
	// returned from inside the loop)
	return false;
}
