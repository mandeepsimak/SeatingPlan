#include"strategyVal.h"
#include"rollno.h"
//#include"input.in"
void verification :: getInput()
{
	inFile.open(input_rooms_out);
	inFile >> totalRoom;
	for( i=0; i < totalRoom; i++)
	{
		inFile >> roomName[i] >> rows[i] >>cols[i];
	}
	inFile.close();
	
	inFile.open(subject_rollno_out);
	inFile >> totalBranches;
	for(i=0; i< totalBranches; i++)
	{
		inFile >> branchCode[i] >> branchStudent[i];
		for(j=0; j<branchStudent[i]; j++)
		{
			inFile >> subjectRoll[i][j];
		}
//		cout<<"Rooms Detail: " <<totalBranches <<" " << subjectRoll[i][j] << " " <<branchCode[i] << " "<< branchStudent[i] <<"\n";
	}
	inFile.close();
}

// to select strategy
void verification :: methodSelection()
{
	do
	{
		cout<<"Select Strategy and enter your choice\n"
		/*	<<"1. two group Strategy.Example:\n\tgroupA\tgroupA\tgroupA\n\tgroupB\tgroupB\tgroupB\n\tgroupA\tgroupA\tgroupA\n\t"
				<<"groupB\tgroupB\tgroupB\n";
		*/
			<<"\n1. 1 Group of classes\n"<<endl
			<<"A\tA\tA\t"<<endl
			<<"A\tA\tA\t"<<endl
			<<"\n2. 2 Group of classes\n"<<endl
			<<"A\tA\tA\t"<<endl
			<<"B\tB\tB\t"<<endl
			<<"\n3. 3 Group of classes\n"<<endl
			<<"A\tA\tA\t"<<endl
			<<"B\tB\tB\t"<<endl
			<<"C\tC\tC\t"<<endl
			<<"\n4. 4 Group of classes\n"<<endl
			<<"A\tA\tA\t"<<endl
			<<"B\tB\tB\t"<<endl
			<<"C\tC\tC\t"<<endl
			<<"D\tD\tD\t"<<endl
			<<"\nEnter your choice:\n";
	 	
		cin >> strategyChoice;
		switch(strategyChoice)
		{
			case 1:
				display(1);
				break;
			case 2:
				display(2);
				break;
			case 3:
				display(3);
				break;
			case 4:
				display(4);
				break;
		
		/*	case 2:
				checkValidation(strategyChoice);
				break;
		*/
			default:
			cout<<"Oops!!! Wrong choice\n Enter your choice Again\n";
		}
	
	}while(strategyChoice < 1 && strategyChoice > 4);
}

// to calculate total available seats in all rooms
int verification :: roomsCapacity()
{
	totalSeats = 0;

	for( j=0; j<totalRoom; j++)
	{
		totalSeats += ( rows[j] * cols[j] );
	}
	cout << "\ntotal Seats = " << totalSeats;
	return(totalSeats);
}


// member function to calculate the cpacity of one group 
/*void verification :: checkValidation(int strategyChoice)
{
	int temp;
	outFile.open("output.txt");
	switch(strategyChoice)
	{
		case 1:
			temp = display(4);
			if(temp == true)
				outFile << "\ncongrats!!!!!!!!!! this strategy is applicable";
			if(temp == false)
				outFile << "\nBadddddddddddd";			
			break;
			
	/*	case 2:
			temp = display(4);
			if(temp == tr`ue)
				outFile << "\ncongrats!!!!!!!!!! this strategy is applicable ";
			if(temp == false)
				outFile << "\nBadddddddddddd";			
			break;
	
	}
}
*/

int verification :: maxStudent(int groups)
{
	min = 3265;
	max = 0;
	for(i=0; i<groups; i++)
	{
		groupArray[i] = branchStudent[i];
		if(groupArray[i] < min)
		{
			min = groupArray[i];
			minPos = i;	
		}	
		if(groupArray[i] > max)
			max = groupArray[i];			
	}
				
	for(i=groups; i<totalBranches; i++)
	{
		groupArray[minPos] += branchStudent[i];
		min = max;
		for(j=0; j<groups; j++)
		{
			if(groupArray[j] <= min)
			{
				min = groupArray[j];
				minPos = j;
			}
			if(groupArray[j] > max)
				max = groupArray[j];
		}
	}
				
	outFile <<"\n Min group students = " << min <<"\tMax group students =" << max;
	cout <<"\n Min group students = " << min <<"\tMax group students =" << max;
	return(max);	
}

void verification :: display(int groups)
{
			outFile.open(strategyResults);
			groupSeats = 0;
			int selection, sum =0;
			if(totalBranches < groups)
			{
				outFile << "\n\nSorry!!!\nStrategy not possible because this strategy requires minimum 4 classes\n";
				cout << "\n\nSorry!!!\nStrategy not possible because this strategy requires minimum 4 classes\n";
			}
			else
			{
				groupSeats = (roomsCapacity()) / groups;
				outFile << "\ngroup seats= " << groupSeats;
				cout << "\ngroup seats= " << groupSeats;
				groupStudents = maxStudent(groups);
				if( groupStudents > groupSeats)
				{
					do
					{					
						outFile <<"\n\n\nstrategy is not possible bcz of less rooms\n\n";
						cout <<"\n\n\nstrategy is not possible bcz of less rooms\n";
						cout << "Would you like follow:\n1.\tStrict strategy \n2." 
							<<"\tStudents at consecutive places of same subject\n Enter choice";
						cin >> selection;
					}while(selection !=1 && selection !=2);
						
						if(selection == 1)
						{
						outFile << groupStudents - groupSeats <<" More seats are required\n";
						cout << groupStudents - groupSeats <<" More seats are required\n";
						float	extraRooms=(float) (groupStudents - groupSeats) / (32/groups);
						int extroom = extraRooms + 0.5;
						cout <<"\n Add  " << extroom << " more room to follow this stretegy.\n"; //<<" Rooms of 8 * 4 to follow this strategy where"
//								<<" 8 is rows and 4 is columns\n\n";
						}
					
						if(selection == 2)
						{
							
							for( i=0; i<groups; i++)
							{
								sum += groupArray[i];
							}
							if( roomsCapacity() >= sum)
							{
								cout << "\nTotal Students: " << sum;
								cout << "\ncongratulations!!! you can get results now.";
								RollNo obj;
								
								obj.get_details();
    							obj.seat_alot(strategyChoice);
   								obj.show_details();
					
							}
							else
							{
								cout<<"\nSorry :-( \nYou need to enter more rooms to follow this strategy";
							}
						}
					
						
				}
				else
				{
					RollNo obj;
					obj.get_details();
    				obj.seat_alot(strategyChoice);
   					obj.show_details();
   					
   				cout << "\n Sitting Plan is done.\n \n Check '" << FinalAllotment_out << "' file.\n\n" << endl;
					
				}
				
				
			}
}
