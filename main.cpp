/*
*Cinema management program
*it books seat, cancels booking
*displays weekly schedule
*We have total 5 movies and each is showed

*/

#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdio>
#pragma GCC diagnostic ignored "-Wwrite-strings"  // to avoid warnings

using namespace std;

// Function to call title ( it just prints  cinema managements system)
void title_function();

// Function for timing of movies, it displays 2 times.
void timing();

// Function that displays the weekly schedule, 5 movies per weekend
int schedule();

//only displays schedule
void onlySchedule();

// This functions displays the map of cinema, total 100 seats.
void CinemaMap(int seatMap[][10],int rows, int movie_no, int time);

//seat booking function
void BookSeat(int seatMap[][10],int rows);

//checks the availability of entered seat number
bool Seat_checker(int seatNo,int time_choice, int movie);

bool data_checker(char filename[],int seatNo);

//cancels a booked seat
void CancelBooking(int seatMap[][10],int rows);

//cin fail validation
void cin_fail();

//function for user data storage in files
void data_storage(char filename[],int User_time_choice,int movie_no);

//reads the store data and deletes the input seat
void Data_delete(char filename[]);

//displays main menu
void main_menu(int seatMap[][10],int rows);


int main()
{
    int rows = 10;
    int arr[rows][10];
    title_function();
    cout <<"\n\t\tEnter any key to continue...";
    getch();
    main_menu(arr,rows);

    return 0;
}

/*
*Function for printing the main menu
*parameters are:
*array of seats
*its size
*/
void main_menu(int seatMap[][10],int rows)
{
    int choice;
    system("CLS");//system clear
    system("color 2");

//start is the label/goto point of goto function
start:
    cout<<"\n\n\n\t\t\t-----------------------------";
    cout<<"\n\t\t\t| CINEMA MANAGEMENT SYSTEM  |";
    cout<<"\n\t\t\t-----------------------------";
    cout <<"\n\n";
    cout << "\n\t\t\t\t MAIN MENU ";
    cout << "\n\n\n\t\t\t1.Book A Seat ";
    cout << "\n\n\t\t\t2.Cancel Booking ";
    cout << "\n\n\t\t\t3.Schedule";
    cout << "\n\n\t\t\t4.Exit\n\n";

    do
    {
        cout << "\n\t\t\tEnter Your Choice: ";
        cin >> choice;
        if(cin.fail())
            cin_fail();  //calling function which checks either input is right or not.
    }
    while (choice > 4 || choice <=0);

   //switching four choices from the main menu
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
    if(choice!=4)
        //takes the user back to main menu
        goto start;

}

/*
*class is define for the person/user
*the members of public class are:
*name of user
*seat number
*age of the
*user data function
*/
class Person
{
  public:
    string name;
    int seatNo, age;
    void Customer_Data(int[][10], int);
};

/* class function is defined here
*parameter:
*2D array of seat map
*movie number
 */
void Person:: Customer_Data(int seatMap[10][10], int movie)
{
    system("CLS");
    int User_time_choice;
  int rows = 10;
    timing();

    do
    {
        if(cin.fail())
        cin_fail();
        cout << "\n\t\tSelect the timing: ";
        cin >>User_time_choice;
    }while( User_time_choice > 2 || User_time_choice <= 0);

    system ("CLS");
    CinemaMap(seatMap,rows, movie, User_time_choice);

    switch (movie)  // switch  movies
    {
    case 1:
    {
        switch(User_time_choice) // switch time
        {
        case 1:

        {
            data_storage("User_data_File_M1T1.txt",User_time_choice,movie); //create file for timing 1 of movie 1
            break;

        }
        case 2:
        {
            data_storage("User_data_File_M1T2.txt",User_time_choice,movie);
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
            data_storage("User_data_File_M2T1.txt", User_time_choice,movie);
            break;

        }
        case 2:
        {
            data_storage("User_data_File_M2T2.txt", User_time_choice,movie);
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
            data_storage("User_data_File_M3T1.txt",User_time_choice,movie);
            break;
        }
        case 2:
        {
            data_storage("User_data_File_M3T2.txt",User_time_choice,movie);
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
            data_storage("User_data_File_M4T1.txt", User_time_choice,movie);
            break;
        }
        case 2:
        {
            data_storage("User_data_File_M4T2.txt", User_time_choice,movie);
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
            data_storage("User_data_File_M5T1.txt", User_time_choice,movie);
            break;

        }
        case 2:
        {
            data_storage("User_data_File_M5T2.txt",User_time_choice,movie);
            break;
        }
        }
        break;
    }
    }
}
/*
*function stores the input data
*parameters
*the filename array where data is stored(total 10 files)
*time chosen by the user
*movie number entered by the user
*/
void data_storage(char filename[],int User_time_choice,int movie_no)
{
    string name;
    int seatNo, age;

    // file handling: writing file
    ofstream fout;
    fout.open(filename, ios::app);

    do
    {
        cout << "\n Please select the seat number: ";
        cin >> seatNo;
        if(cin.fail());
        cin_fail();
    }while(seatNo > 100 || seatNo<= 0);

    bool check_r = false;//this is used for checking whether all the data is available to write it in the file
    bool check = Seat_checker( seatNo, User_time_choice,movie_no);

    if(check)
    {
        cout << " Entered Seat number is not available!!!";
    }
    else
    {
        cout << " Enter name: ";
        cin >> name;
        cout << " Enter age: ";
        cin >> age;
        check_r = true;  //it becomes false if one value is added, all three values must be added to make it true
    }
    if(check_r)
    {
        fout << seatNo << " " << name << " " << age << endl;
        cout << "\n\tSuccessFully Booked!!!\n";
    }

    fout.close();
}

/*
*this function will return false when the seat is available
*it will return true when the seat is already booked by someone else
*parameters:
*seat number entered by user
*user time choice
* movie number
*/
bool Seat_checker(int seatNo, int User_time_choice, int movie)
{
    bool checker = false; // seat is available if true , false if not available

    switch (movie)
    {
    case 1:
    {
        switch(User_time_choice)
        {
        case 1:
        {
            checker = data_checker("User_data_File_M1T1.txt",seatNo);
            return checker;
            break;

        }
        case 2:
        {
            checker = data_checker("User_data_File_M1T2.txt",seatNo);
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

            checker = data_checker("User_data_File_M2T1.txt",seatNo);
            return checker;
            break;

        }
        case 2:
        {

            checker =  data_checker("User_data_File_M2T2.txt", seatNo);
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

            checker = data_checker("User_data_File_M3T1.txt", seatNo);
            return checker;
            break;

        }
        case 2:
        {
            checker = data_checker("User_data_File_M3T2.txt",seatNo);
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
            checker = data_checker("User_data_File_M4T1.txt", seatNo);
            return checker;
            break;

        }
        case 2:
        {
            checker = data_checker("User_data_File_M4T2.txt", seatNo);
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
            checker = data_checker("User_data_File_M5T1.txt", seatNo);
            return checker;
            break;

        }
        case 2:
        {
            checker = data_checker("User_data_File_M5T2.txt", seatNo);
            return checker;
            break;
        }
        }

        break;
    }
    }

}

/*
* this function reads data stored in files, checks availability of seats and returns true or false
* parameters are the data storage files( 10 separate file)
* seat no entered by user
*/
bool data_checker(char filename[],int seatNo)   // checks seat availability
{
    int Old_seatNo, age;
    string name;
    bool checker = false;

    //File reading
    ifstream fin;
    fin.open(filename,ios::in);// ios::in	Open for input operations.

    while(fin >> Old_seatNo)//it will be false at the end of the data in file
    {
        if(seatNo == Old_seatNo)
            checker = true;
        fin >> name;
        fin >> age;
    }
    fin.close();

    return checker;

}

//it only displays the movie
int schedule()
{
    int movie_no;
    cout <<"\n\tMovie Menu:\n";
    cout <<"\t-----------\n";
    cout <<"\n\n\tMovies\t\t\t\t\tDays:";
    string title[5][2] = {{"Star Wars","Monday"},{"Thugs of Hindustan","Tuesday"},{"Zero","Wednesday"},{"MI:Fallout","Thursday"},{"Simbha","Friday"}};
    cout <<"\n\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "\n\t" << i + 1 <<".";
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

/*
* function for booking a seat
*parameters:
*array of seat map
* size of rows
*/
void BookSeat(int seatMap[][10], int rows)
{
    cout << "\nThe Movie Schedule is as follow: ";
    cout << "\n\n\tMovies\t\t\t\t\tDay\n";
    system("CLS");
    int movie=schedule();

    // class object is defined
    Person object;
    object.Customer_Data(seatMap, movie);
    cout << endl;

    cout <<"\n\t\tEnter any key to continue...";
    getch();
}

// displays time
void timing()
{
    cout <<"\n\tMovie Timing:";
    cout <<"\n\t------------\n";
    string time[2] = {"10 am --> 12 pm","1 pm --> 3 pm"};

    for(int i = 0; i < 2; i++)
    {
        cout << "\n\t\t" << i + 1 << ". " << time[i] << endl;
    }
    cout << endl;
}
/*
*displays cinema map
*parameters:
* array of seat map
*size of array
* movie
*movie time
*/
void CinemaMap(int seatMap[][10], int rows, int movie, int time)
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


    bool check=false;
    for( int i =0; i< 10; i++)
    {
        cout <<"\t\t";
        for(int j = 0; j <10; j++)
        {
            check = Seat_checker(seatMap[i][j],time,movie);
            if (check)
            {
                cout << "|" << setw(3) << "BK";          // if seat is booked BK will be shown on the screen
                check=false;

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

/*
*cancel booking function
*parameters:
*array of seat map
*its size
*/
void CancelBooking(int seatMap[][10], int rows)
{
    system("CLS");
    int user_time,Old_seatNo,seatNo;
    rows  =10;
    cout <<"\n\tCancel Booking\n";
    int movie = schedule();
    system("CLS");

    timing();
    cout <<"\n\tEnter time of the movie you booked: ";
    cin>>user_time;

    system("CLS");

    CinemaMap( seatMap, rows , movie, user_time);

    switch (movie)
    {
    case 1:
    {
        switch(user_time)
        {
        case 1:
        {
            Data_delete("User_data_File_M1T1.txt");
            break;
        }

        case 2:
        {
            Data_delete("User_data_File_M1T2.txt");
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
            Data_delete("User_data_File_M2T1.txt");
            break;
        }

        case 2:
        {
            Data_delete("User_data_File_M2T2.txt");
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
            Data_delete("User_data_File_M3T1.txt");
            break;
        }

        case 2:
        {
            Data_delete("User_data_File_M3T2.txt");
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
            Data_delete("User_data_File_M4T1.txt");
            break;
        }

        case 2:
        {
            Data_delete("User_data_File_M4T2.txt");
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
            Data_delete("User_data_File_M5T1.txt");
            break;
        }

        case 2:
        {
            Data_delete("User_data_File_M5T2.txt");
            break;
        }
        }
        break;
    }
    }

    cout <<"\n\t\tEnter any key to continue...";
    getch();

}
/*
*the function copies the data stored in array filename to a new file data.txt then deletes the previous file
   and renames the data file.
*parameters:
* array filename.
*/
void Data_delete(char filename[])
{
    int seatNo,Old_seatNo, age;
    string name;

    do
    {
        cout << "\n\tEnter the seat you booked: ";
        cin >> seatNo;
        if(cin.fail());
        cin_fail();
    }while(seatNo > 100 || seatNo<= 0);

    ifstream  fin;
    fin.open(filename, ios::in);

    // the previous data is stored in a new file
    ofstream fwrite;
    fwrite.open("data.txt", ios::out);

    while(fin >> Old_seatNo)  // reading till the end of file.
    {
        if(Old_seatNo != seatNo)
        {
            fin>> name >> age;
            fwrite <<Old_seatNo << " " <<name <<" " <<age <<endl;
        }

        else if(Old_seatNo == seatNo)
        {
            fin>> name >> age;
            cout <<"\n\tseat number: " <<Old_seatNo;
            cout <<"\n\tName: "  <<name;
            cout <<"\n\tAge: " <<age;
            cout <<"\n\t\tThe seat has been successfully deleted!!\n";
        }
    }
    fwrite.close();
    fin.close();
    //removing and renaming the previous file
    remove (filename);
    rename("data.txt", filename);
}

void cin_fail()
{
    string failure;
    cin.clear();
    getline(cin,failure);
}

//it justs prints the schedule on the  screen.
void onlySchedule()
{
    system("CLS");
    cout <<"\n\tMovie Menu:\n";
    cout <<"\t-----------\n";
    cout <<"\n\n\tMovies\t\t\t\t\tDays:";
    string title[5][2] = {{"Star Wars","Monday"},{"Thugs of Hindustan","Tuesday"},{"Zero","Wednesday"},{"MI:Fallout","Thursday"},{"Simbha","Friday"}};
    cout <<"\n\n";

    for(int i = 0; i < 5; i++)
    {
        cout << "\n\t" << i + 1 <<".";
        for(int j= 0; j <2; j++)
        {
            cout << setw(15) << left << title[i][j] << "\t\t\t";
        }
        cout << endl;
    }

    cout <<"\n\t\tEnter any key to continue...";
    getch();
}


void title_function()
{
    cout<<"    ____ _                                                                   " <<endl;
    cout<<"   / __ (_)                                                                  " <<endl;
    cout<<"  | /  \\/_ _ __   ___ _ __ ___   __ _                                       " <<endl;
    cout<<"  | |   | | \'_ \\ / _ \\ \'_ ` _ \\ / _` |                                  " <<endl;
    cout<<"  | \\__/\\ | | | |  __/ | | | | | (_| |                                     " <<endl;
    cout<<"   \\____/_|_| |_|\\___|_| |_| |_|\\__,_|                                    " <<endl;
    cout<<"                                                                             " <<endl;
    cout<<"                                                                             " <<endl;
    cout<<"  ___  ___                                                  _                " <<endl;
    cout<<"  |  \\/  |                                                 | |              " <<endl;
    cout<<"  | .  . | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_              " <<endl;
    cout<<"  | |\\/| |/ _` | \'_ \\ / _` |/ _` |/ _ \\ \'_ ` _ \\ / _ \\ \'_ \\| __|    " <<endl;
    cout<<"  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_              " <<endl;
    cout<<"  \\_|  |_/\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__|      " <<endl;
    cout<<"                             __/ |                                           " <<endl;
    cout<<"                            |___/                                            " <<endl;
    cout<<"                                                                             " <<endl;
    cout<<"   _____           _                                                         " <<endl;
    cout<<"  /  ___|         | |                                                        " <<endl;
    cout<<"  \\ `--. _   _ ___| |_ ___ _ __ ___                                         " <<endl;
    cout<<"   `--. \\ | | / __| __/ _ \\ | _ ` _ \\                                     " <<endl;
    cout<<"  /\\__/ / |_| \\__ \\ ||  __/ | | | | |                                     " <<endl;
    cout<<"  \\____/ \\__, |___/\\__\\___|_| |_| |_|                                    " <<endl;
    cout<<"          __/ |                                                              " <<endl;
    cout<<"         |___/                                                               " <<endl;
    cout<<"                                                                             " <<endl;
    cout<<"        Made by : Syed Muhammad Ismail and Basit Ali                         " <<endl;

}

