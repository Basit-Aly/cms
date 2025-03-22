#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>

using namespace std;

void timing();
int schedule();
void onlySchedule();
void CinemaMap(int seatMap[][10],int rows);
void BookSeat(int seatMap[][10],int rows);
bool Seat_checker(int seatNo,int time_choice, int movie);
void CancelBooking(int seatMap[][10],int rows);
void BookingStatus();
void cin_fail();
int Exit();

void main_menu(int seatMap[][10],int rows)
{
    int choice;
    system("CLS");
    cout << "\n\t\t\t\t MAIN MENU ";
    cout << "\n\n\n\t\t\t1.Book A Seat ";
    cout << "\n\n\t\t\t2.Cancel Booking ";
    cout << "\n\n\t\t\t3.Schedule";
    cout << "\n\n\t\t\t4.Exit\n\n";
//start:
//    do
//    {
//        cout << "\n\t\t\tEnter Your Choice: ";
//        cin >> choice;
//        if(cin.fail())
//            cin_fail();
//
//    }

    cout << "\n\t\t\tEnter Your Choice: ";
    cin >> choice;
    while ((choice < 4) && (choice >=0))
    {

        switch(choice)
        {
        case 1:
        {
            BookSeat(seatMap,rows);
            break;
        }
        case 2:
        {
            CancelBooking(seatMap,rows);
            break;
        }
        case 3:
        {
            onlySchedule();
            break;
        }
        case 4:
            break;
        }

        system("CLS");
        cout << "\n\t\t\t\t MAIN MENU ";
        cout << "\n\n\n\t\t\t1.Book A Seat ";
        cout << "\n\n\t\t\t2.Cancel Booking ";
        cout << "\n\n\t\t\t3.Schedule";
        cout << "\n\n\t\t\t4.Exit\n\n";
        cout << "\n\t\t\tEnter Your Choice: ";
        cin >> choice;

    }

}

class Person
{
public:
    string name, gender;
    int seatNo;
    //void Customer_Data(int[][10],string, string, int);
    void Customer_Data(int[][10], int);
};

//void Person:: Customer_Data(int seatMap[10][10],string name, string gender, int seatNo, int movie)
void Person:: Customer_Data(int seatMap[10][10], int movie)
{
    system("CLS"); // clear system
    int n;
    string time[3] = {"7pm --> 10pm","9pm --> 12am","2am --> 5am"};
    cout <<"\n\tMovie Timing:";
    cout <<"\n\t------------\n";

    for(int i = 0; i < 2; i++)
    {
        cout << "\n\t\t" << i + 1 << ". " << time[i] << endl;
    }
    do
    {
        if(cin.fail())
            cin_fail();
        cout << "\n\t\tSelect the timing: ";
        cin >>n; // timing choice
    }
    while( n > 2 || n <= 0);

    int User_time_choice = n;
    int rows = 10;
    system ("CLS");
    CinemaMap(seatMap,rows);
    switch (movie)
    {
        case 1: //if movie one is selected
            {
            switch(User_time_choice)
            {
                case 1: //timing 1

                {
                    ofstream fout;

                    fout.open("User_data_File_M1T1.txt", ios::app); //create file for timing 1 of movie 1
                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail());
                        cin_fail();
                    }
                    while(seatNo > 100 || seatNo<= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker( seatNo, User_time_choice, movie);

                    if(check)
                    {
                        cout << " Entered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;

                }
                case 2: //if timing 2 is selected
                {
                    ofstream fout;

                    fout.open("User_data_File_M1T2.txt", ios::app); //ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail())
                            cin_fail();
                    }
                    while(seatNo > 100 || seatNo <= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker(seatNo,User_time_choice,movie);

                    if(check)
                    {
                        cout <<"\n\tEntered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;
                    // goto start;
                }
            }
                break;
            }


            case 2: //movie 2
            {
            switch(User_time_choice)
            {
                case 1: //timing 1 of movie 2
                {
                    ofstream fout;

                    fout.open("User_data_File_M2T1.txt", ios::app); //create file of riming 1 of movie 2
                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail());
                        cin_fail();
                    }
                    while(seatNo > 100 || seatNo<= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker( seatNo, User_time_choice,movie);

                    if(check)
                    {
                        cout << " Entered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;

                }
                case 2:
                {
                    ofstream fout;

                    fout.open("User_data_File_M2T2.txt", ios::app); //ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail())
                            cin_fail();
                    }
                    while(seatNo > 100 || seatNo <= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker(seatNo,User_time_choice,movie);

                    if(check)
                    {
                        cout <<"\n\tEntered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;
                    // goto start;
                }
            }
                break;
            }


            case 3:
            {
            switch(User_time_choice)
            {
                case 1:
                {
                    ofstream fout;

                    fout.open("User_data_File_M3T1.txt", ios::app);
                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail());
                        cin_fail();
                    }
                    while(seatNo > 100 || seatNo<= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker( seatNo, User_time_choice,movie);

                    if(check)
                    {
                        cout << " Entered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;

                }
                case 2:
                {
                    ofstream fout;

                    fout.open("User_data_File_M3T2.txt", ios::app); //ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail())
                            cin_fail();
                    }
                    while(seatNo > 100 || seatNo <= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker(seatNo,User_time_choice,movie);

                    if(check)
                    {
                        cout <<"\n\tEntered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;
                    // goto start;
                }
            }
                break;
            }


            case 4:
            {


            switch(User_time_choice)
            {
                case 1:
                {
                    ofstream fout;

                    fout.open("User_data_File_M4T1.txt", ios::app);
                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail());
                        cin_fail();
                    }
                    while(seatNo > 100 || seatNo<= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker( seatNo, User_time_choice,movie);

                    if(check)
                    {
                        cout << " Entered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;

                }
                case 2:
                {
                    ofstream fout;

                    fout.open("User_data_File_M4T2.txt", ios::app); //ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

                    do
                    {
                        cout << "\n Please select the seat number: ";
                        cin >> seatNo;
                        if(cin.fail())
                            cin_fail();
                    }
                    while(seatNo > 100 || seatNo <= 0);

                    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                    bool check = Seat_checker(seatNo,User_time_choice,movie);

                    if(check)
                    {
                        cout <<"\n\tEntered Seat number is not available!!!";
                    }
                    else
                    {
                        cout << " Enter name: ";
                        cin >> name;
                        cout << " Enter gender: ";
                        cin >> gender;
                        check_r = true;
                    }
                    if(check_r)
                    {
                        fout << seatNo << " " << name << " " << gender << endl;
                        cout << "\n\tSuccessFully Booked!!!\n";
                    }

                    fout.close();
                    break;
                    // goto start;

                }
            }
                break;

            }

            case 5:
            {
                switch(User_time_choice)
                {
                    case 1:
                    {
                        ofstream fout;

                        fout.open("User_data_File_M5T1.txt", ios::app);
                        do
                        {
                            cout << "\n Please select the seat number: ";
                            cin >> seatNo;
                            if(cin.fail());
                            cin_fail();
                        }
                        while(seatNo > 100 || seatNo<= 0);

                        bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                        bool check = Seat_checker( seatNo, User_time_choice,movie);

                        if(check)
                        {
                            cout << " Entered Seat number is not available!!!";
                        }
                        else
                        {
                            cout << " Enter name: ";
                            cin >> name;
                            cout << " Enter gender: ";
                            cin >> gender;
                            check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
                        }
                        if(check_r)
                        {
                            fout << seatNo << " " << name << " " << gender << endl;
                            cout << "\n\tSuccessFully Booked!!!\n";
                        }

                        fout.close();
                        break;

                    }
                    case 2:
                    {
                        ofstream fout;

                        fout.open("User_data_File_M5T2.txt", ios::app); //ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.

                        do
                        {
                            cout << "\n Please select the seat number: ";
                            cin >> seatNo;
                            if(cin.fail())
                                cin_fail();
                        }
                        while(seatNo > 100 || seatNo <= 0);

                        bool check_r = false;//this is used for checking whether all the data is available to write it in the file
                        bool check = Seat_checker(seatNo,User_time_choice,movie);

                        if(check)
                        {
                            cout <<"\n\tEntered Seat number is not available!!!";
                        }
                        else
                        {
                            cout << " Enter name: ";
                            cin >> name;
                            cout << " Enter gender: ";
                            cin >> gender;
                            check_r = true;
                        }
                        if(check_r)
                        {
                            fout << seatNo << " " << name << " " << gender << endl;
                            cout << "\n\tSuccessFully Booked!!!\n";
                        }

                        fout.close();
                        break;
                        // goto start;
                    }
                }
                    break;
                }

    }
}
/*this function will return false when the seat is available
it will return true when the seat is already booked by someone else
*/
bool Seat_checker(int seatNo, int User_time_choice, int movie)
{
    string name,gender;   //For file handling we have to read and write file here
    int  Old_seatNo;
    bool checker = false;

    switch (movie)
    {
    case 1:
        {
        switch(User_time_choice)
        {
            case 1:
            {
                ifstream fin;
                fin.open("User_data_File_M1T1.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;

            }
            case 2:
            {
                ifstream fin;
                fin.open("User_data_File_M1T2.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;
                }
            }

            break;
        }

    case 2:
        {
        switch(User_time_choice)
        {
            case 1:
            {
                ifstream fin;
                fin.open("User_data_File_M2T1.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;

            }
            case 2:
            {
                ifstream fin;
                fin.open("User_data_File_M2T2.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;
                }
            }

            break;
        }

        case 3:
        {
        switch(User_time_choice)
        {
            case 1:
            {
                ifstream fin;
                fin.open("User_data_File_M3T1.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;

            }
            case 2:
            {
                ifstream fin;
                fin.open("User_data_File_M3T2.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;
                }
            }

            break;
        }

        case 4:
        {
        switch(User_time_choice)
        {
            case 1:
            {
                ifstream fin;
                fin.open("User_data_File_M4T1.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;

            }
            case 2:
            {
                ifstream fin;
                fin.open("User_data_File_M4T2.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;
                }
            }

            break;
        }

        case 5:
        {
        switch(User_time_choice)
        {
            case 1:
            {
                ifstream fin;
                fin.open("User_data_File_M5T1.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;

            }
            case 2:
            {
                ifstream fin;
                fin.open("User_data_File_M5T2.txt",ios::app);

                while(fin >> Old_seatNo)//it will be false at the end of the data in file
                {
                    if(seatNo==Old_seatNo)
                        checker = true;
                    fin >> name;
                    fin >> gender;
                }
                fin.close();
                return checker;
                break;
                }
            }

            break;
        }
    }

}

int schedule()
{
    cout <<"\n\tMovie Menu:\n";
    cout <<"\t-----------\n";
    cout <<"\n\n\tMovie\t\t\t\t\tDay:";
    int movie_no;
    string failure;
    string title[5][2] = {{"Star Wars","Monday"},{"Thugs of Hindustan","Tuesday"},{"Zero","Wednesday"},{"MI:Fallout","Thursday"},{"Simbha","Friday"}};
    cout <<"\n\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "\t" << i + 1 <<".";
        for(int j= 0; j <2; j++)
        {
            cout << setw(15) << left << title[i][j] << "\t\t\t";
        }
        cout << endl;
    }
    do
    {
        cout <<"\n\tEnter the Movie number from the choices: ";
        cin >> movie_no;
        if(cin.fail())
            cin_fail();
    }
    while(movie_no > 5 || movie_no <= 0);
    return movie_no;
}

void onlySchedule()
{
    system("CLS");
    cout <<"\n\tMovie Menu:\n";
    cout <<"\t-----------\n";
    cout <<"\n\n\tMovie\t\t\t\t\tDay:";
    //int movie_no;
    //string failure;
    string title[5][2] = {{"Star Wars","Monday"},{"Thugs of Hindustan","Tuesday"},{"Zero","Wednesday"},{"MI:Fallout","Thursday"},{"Simbha","Friday"}};
    cout <<"\n\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "\t" << i + 1 <<".";
        for(int j= 0; j <2; j++)
        {
            cout << setw(15) << left << title[i][j] << "\t\t\t";
        }
        cout << endl;
    }

    cout <<"\n\t\tEnter any key to continue...";
    getch();
}

void timing()
{
    int n;
    string time[2] = {"7pm-->10pm","9pm-->12am"};
    cout << "\n\tMovie Timing is as follow: \n";

    for(int i = 0; i < 2; i++)
    {
        cout << "\n\t\t\t" << i + 1 << ". " << time[i] << endl;
    }
    cout << endl;
}

void CinemaMap(int seatMap[][10], int rows)
{
    int seat_numbers = 0;

    for( int i =0; i< rows; i++)
    {
        for(int j = 0; j <10; j++)
        {
            seat_numbers++;
            seatMap[i][j] = seat_numbers;
        }
    }
    cout <<"\n\tCinema Map:";
    cout <<"\n\n\t\t________________________________________" << endl;
    for( int i =0; i< 10; i++)
    {
        cout <<"\t\t";
        for(int j = 0; j <10; j++)
        {
            if(i==0)
            {
                cout << "|" << setw(3) << seatMap[i][j];
            }
            else
            {
                cout << "|" << setw(3) << seatMap[i][j];
            }
        }
        cout << "|" << endl;;
        cout <<"\t\t_________________________________________" << endl;
    }
}
int Exit() //go to main
{
     char ch;
    string failure;

    while(1)   //while always true
    {
        cout <<"\nPress R return to main menu: ";
        cin>>ch;
        if(ch == 'R')
            return 0;
    }
    system ("CLS");
    return 1;

}


void BookSeat(int seatMap[][10], int rows)
{
    //int seatNo;
    //string name, gender;

    cout << "\nThe Movie Schedule is as follow: ";
    cout << "\n\n\tMovies\t\t\t\t\tDay\n";
    system("CLS");
    int movie=schedule();
    Person object;
   // object.Customer_Data(seatMap,name,gender,seatNo, movie);
    object.Customer_Data(seatMap, movie);
    cout << endl;

    cout <<"\n\t\tEnter any key to continue...";
    getch();
    //Exit();
}
void CancelBooking(int seatMap[][10], int rows)
{
    system("CLS");
    int t,Old_seatNo,seatNo;
    rows  =10;
    cout <<"\n\tCancel Booking\n";
    int movie=schedule();
    system("CLS");
    timing();
    cout <<"\n\tEnter time of the movie you booked: ";
    cin>>t; //time of movie
    system("CLS");
    CinemaMap( seatMap, rows);
    int user_time = t;
    switch (movie)
    {
        case 1:
            {
                switch(user_time)
                {
                case 1:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M1T1.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M1T1.txt");
                        rename("data.txt", "User_data_File_M1T1.txt");
                        break;
                    }

                    case 2:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M1T2.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M1T2.txt");
                        rename("data.txt", "User_data_File_M1T2.txt");
                        break;
                    }
                }
                break;
            }

            case 2:
            {
                switch(user_time)
                {
                case 1:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M2T1.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M2T1.txt");
                        rename("data.txt", "User_data_File_M2T1.txt");
                        break;
                    }

                    case 2:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M2T2.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M2T2.txt");
                        rename("data.txt", "User_data_File_M2T2.txt");
                        break;
                    }
                }
                break;
            }

            case 3:
            {
                switch(user_time)
                {
                case 1:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M3T1.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M3T1.txt");
                        rename("data.txt", "User_data_File_M3T1.txt");
                        break;
                    }

                    case 2:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M3T2.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M3T2.txt");
                        rename("data.txt", "User_data_File_M3T2.txt");
                        break;
                    }
                }
                break;
            }

            case 4:
            {
                switch(user_time)
                {
                case 1:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M4T1.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M4T1.txt");
                        rename("data.txt", "User_data_File_M4T1.txt");
                        break;
                    }

                    case 2:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M4T2.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M4T2.txt");
                        rename("data.txt", "User_data_File_M4T2.txt");
                        break;
                    }
                }
                break;
            }

            case 5:
            {
                switch(user_time)
                {
                case 1:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M5T1.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M5T1.txt");
                        rename("data.txt", "User_data_File_M5T1.txt");
                        break;
                    }

                    case 2:
                    {
                        int seatno, seat1,oldseatno;
                        string name, gender;
                        cout << "\n\tEnter the seat you booked: ";
                        cin >> seat1;
                        ifstream  fin;
                        fin.open("User_data_File_M5T2.txt", ios::in);

                        ofstream fwrite;
                        fwrite.open("data.txt", ios::out);

                        while(fin>>oldseatno)  // reading till the end of file.
                        {
                            if(oldseatno != seat1)
                            {
                                fin>> name >> gender;
                                fwrite <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }


                            else if(oldseatno == seat1)
                            {
                                fin>> name >> gender;
                                cout <<"deleted\n";
                                cout <<oldseatno << " " <<name <<" " <<gender <<endl;
                            }

                        }
                        fwrite.close();
                        fin.close();
                        remove ("User_data_File_M5T2.txt");
                        rename("data.txt", "User_data_File_M5T2.txt");
                        break;
                    }
                }
                break;
            }


    }

    cout <<"\n\t\tEnter any key to continue...";
    getch();

}

void cin_fail()
{
    string failure;
    cin.clear();
    getline(cin,failure);
}

int main()
{
    int rows = 10;
    int arr[rows][10];
    cout<<"\n\n\n\t\t\t-----------------------------";
    cout<<"\n\t\t\t| CINEMA MANAGEMENT PROJECT |";
    cout<<"\n\t\t\t-----------------------------";
    cout <<"\n\n";
    cout <<"\n\t\tEnter any key to continue...";
    getch();
    main_menu(arr,rows);



    return 0;
}
/*ios::in	Open for input operations.
ios::out	Open for output operations.
ios::binary	Open in binary mode.
ios::ate	Set the initial position at the end of the file.
If this flag is not set, the initial position is the beginning of the file.
ios::app	All output operations are performed at the end of the file, appending the content to the current content of the file.
*/

