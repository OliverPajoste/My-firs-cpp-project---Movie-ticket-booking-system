
//Throughout the code I misspelled schedules. So it is scedules. Sorry.

// iostream for text file reading and writing
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <sstream>


//for random numbers
#include <stdio.h> 
#include <stdlib.h>     
#include <time.h> 


using namespace std;
//basic class settings for different numbers and strings used in the system
int input, num_check, Chosen_Movie, timetable_num;
string line, file_name.myText, sk_ifend, txt_file, Fname, User_ID, txt = ".txt";
bool Main_exit;
bool incorrect = true;
char seats[5][8];
string alpha[] = { " ","a", "b", "c", "d", "e", "f", "g", "h", "i", "j"," k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z","A", "B", "C", "D", "E", "F", "G", "H", "I", "J"," K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" };

void Seating() {
    // prints out seating layout with numbers that show if the seat is taken or free(looked this part up from the internet)
    int i, j;
    for (i = 0; i < 5; i++)
        cout << i + 1 << " _" << seats[i][0] << "_|" << "_" << seats[i][1] << "_|" << "_" << seats[i][2] << "_|" << "_" << seats[i][3] << "_|" << "_" << seats[i][4] << "_|" << "_" << seats[i][5] << "_|" << "_" << seats[i][6] << "_|" << "_" << seats[i][7] << "_|" << '\n';
        cout << "\n\n";
        cout << "Enter the row number and press 'ENTER' and then the column number." << endl;

    cin >> i >> j;
    if (seats[i][j] != '1')
        seats[i][j] = '1';
    else
    {
        cout << endl;
        cout << "Warning : position not free. Please choose another seat." << endl;
        cout << endl;
    }
    cout << "\n\n";
    for (i = 0; i < 5; i++)
        cout << i + 1 << " _" << seats[i][0] << "_|" << "_" << seats[i][1] << "_|" << "_" << seats[i][2] << "_|" << "_" << seats[i][3] << "_|" << "_" << seats[i][4] << "_|" << "_" << seats[i][5] << "_|" << "_" << seats[i][6] << "_|" << "_" << seats[i][7] << "_|" << '\n';


}



void Hello_Mes() {
    // Small welcome message from the system
    cout << "\n\n";
    cout << "---------------------------------------------------------" << endl;
    cout << "------------|MOVIE TICKET BOOKING SYSTEM|----------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "\n\n";
}


void Main_menu() {
    // This is my main menu function


    cout << "\n";
    cout << "---------------------MAIN MENU---------------------------" << endl;
    cout << "\n";
    cout << "<0>    -   Movie Schedules" << endl;
    cout << "<1>    -   Book a ticket" << endl;
    cout << "<2>    -   My ticket information" << endl;
    cout << "<3>    -   My user information" << endl;
    cout << "<4>    -   Exit" << endl;
    cout << "\n";
    cout << "---------------------------------------------------------" << endl;

    cout << "Enter a number to procceed: ";
    cin >> input;
    // Checks for user input if the input is a valid number from the main menu the program continues. Otherwise continues
    while (input >= 5 || !cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // skips the invalid input
        cout << "Please enter a valid number:";
        cin >> input;
    }
    

}

void Show_Timings(int Movie_times) {
    // I used case switch to open different text files and read information from them
        switch (Chosen_Movie) {
        default:
        case 0:
            txt_file = "Marvel`s SpiderMan_timings.txt";
            break;
        case 1:
            txt_file = "Disney Lionking_timings.txt";
            break;
        case 2:
            txt_file = "Harry Potter_timings.txt";
            break;
        case 3:
            txt_file = "The Hobbit_timings.txt";
            break;
        case 4:
            txt_file = "Jumanji_timings.txt";
            break;
        case 5:
            txt_file = "Jurassic World_timings.txt";
            break;
        }

        ifstream myfile(txt_file);
        if (myfile.is_open()) //reads the text files
        {
            while (myfile.good())
            {
                getline(myfile, line);
                cout << line << endl;
            }
            myfile.close();
        }

        else cout << "Unable to open file";

}

void Movie_Scedules() {
    cout << "\n\n";
    cout << "----------------| NOW SHOWING IN CINEMAS |---------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    ifstream src("Movie Scedules.txt");
    // opens scedules file and reads from it and prints it out until file ends
    if (!src)
    {
        perror("Error opening file");
    }
    while (getline(src, line))
    {
        cout << line << "\n";
    }
    cout << "---------------------------------------------------------" << endl;

    cout << "What movie timings would you like to see? (Enter the Movie ID number) :";
    cin >> Chosen_Movie;
    while (!(Chosen_Movie <= 5) || !cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Movie ID number. Please try again: ";
        cin >> Chosen_Movie;
    }
    cout << "\n\n";
    Show_Timings(Chosen_Movie);
    cout << "\n\n";
    cout << "Here are all the timings for the movie you chose." << endl;
}

void Book_Ticket(double ran_num) {
    cout << "Here is the list of movies available:" << endl;
    cout << "\n\n";
    cout << "----------------| NOW SHOWING IN CINEMAS |---------------" << endl;
    cout << "---------------------------------------------------------" << endl;
    ifstream src("Movie Scedules.txt");
    // opens scedules file and reads from it and prints it out until file ends
    if (!src)
        {
            perror("Error opening file");
        }
    while (getline(src, line))
        {
            cout << line << "\n";
        }
        cout << "---------------------------------------------------------" << endl;
        cout << "\n";
        cout << "What movie do you want to buy the ticket(s) for? (Enter the Movie ID number) :";
        cin >> Chosen_Movie;
    while (Chosen_Movie >= 5 || !Chosen_Movie) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Movie ID number. Please try again: ";
            cin >> Chosen_Movie;
    }
            cout << "\n\n\n";
            cout << "Thank you for your movie choice. Lets move onto the timings..." << endl;
            cout << "\n\n" << endl;
            cout << "---------------------------------------------------------" << endl;
        Show_Timings(Chosen_Movie);
        cout << "\n\n";
        cout << "Enter the number 0-5 accordingly to the table:";
        cin >> timetable_num;
        cout << "---------------------------------------------------------" << endl;
        cout << "The ticket will cost - " << ran_num << " pounds" << endl;
    double cost = ran_num;
    
    cout << "\nThank you now you just have to choose your seats and we are done." << endl;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 8; j++)
            seats[i][j] = 'O';
    bool choice = 1;
    while (choice == true)
    {
        // seating function part asks if the user wants to book more seats. if so it is possible.
        cout << "\n\n";
        Seating();
        cout << "Would like to choose another seat?(Please choose only 1 or 0)" << endl;
        cout << "(1) Yes" << endl;
        cout << "(0) No" << endl;
        cin >> choice;
        if (choice == 0)
            break;
        Seating();
    }
     cout << "\n\n";
}



void Ticket_info(double ran_num) {
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "                    YOUR TICKET INFORMATION" << endl;
    cout << "\n\n";
    cout << "You have bought a ticket for " << txt_file << endl;
    cout << "Timing index chosen:..." << timetable_num <<  endl;
    cout << "Ticket cost -      " << ran_num << " pounds" << endl;
    cout << "\n\n";
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "\n\n";

}

void User_Info() {
    cout << "\n\n";
    cout << "---------------------------------------------------------" << endl;
    cout << "\n";
    cout << "--------------------USER INFORMATION---------------------" << endl;
    cout << "\n";
    cout << "Your full name is " << Fname << endl;
    cout << "\nYou are logged in as " << User_ID;
    cout << "\n\n";
}

int main()
{

Hello_Mes();
cout << "Please enter your full name(no spaces): ";
cin >> Fname;
//Only string input is possible
while (find_if(Fname.begin(), Fname.end(), isdigit) != Fname.end()) {
    cout << "Invalid input. You are not able to use numbers. Please try again: ";
    cin >> Fname;
}


cout << "\nThank you. Now enter your username:";
cin >> User_ID;
cout << "\nYou have been logged in successfully..." << endl;

string Userfile = User_ID + txt;
ofstream myfile; // creats or appends user information to a text file myfile. Named after the username user inputs so it creates a small database
myfile.open(Userfile, ios_base::app); // used ios_base to append text not to overwrite
myfile << "---------------------------------" << endl;
myfile << Fname << " logged in.\n" << endl;
myfile << "Logged in as " << User_ID << "(username).\n";



myfile << "---------------------------------" << endl;
myfile << "\n\n\n";
myfile.close();


    while (Main_exit != true || ask_ifend == "n") {
        Main_exit = false;
        ask_ifend == "y";
        
        srand(time(NULL));
        double ran_num = rand() % 20 + 5;
        Main_menu();

        if (input == 0) {
            Movie_Scedules();
        }
        else if (input == 1) {
            Book_Ticket(ran_num);
        }
        else if (input == 2) {
            Ticket_info(ran_num);

        }
        else if (input == 3) {
            User_Info();
        }
        else if (input == 4) {
           Main_exit = true;
           cout << "\n\n";
           cout << "--------------------<<<<<<<<<<>>>>>>>>>-----------------------" << endl;
           cout << "Thank you for your time. We hope to see you soon... Take care!" << endl;
           cout << "<<<<<<<<<<<<<<<<<<<<------------------>>>>>>>>>>>>>>>>>>>>>>>" << endl;
           cout << "\n\n";
           break;
        }


        cout << "Do you want to go back to main menu(y) or exit the system(n)?: ";
        cin >> ask_ifend;
        if (ask_ifend == "y") {
            continue;
        }
        else {
            ask_ifend == "n";
            break;
        }

     
    }
    cout << "\n\n";
    cout << "--------------------<<<<<<<<<<>>>>>>>>>-----------------------" << endl;
    cout << "Thank you for your time. We hope to see you soon... Take care!" << endl;
    cout << "<<<<<<<<<<<<<<<<<<<<------------------>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    cout << "\n\n";

    return 0;
}

