#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
#include<cctype>


using namespace std;

void log_in_panel();
void Bank_panel();
void Command_panel();
void Acconut_info();
void Deposit();
void balance();
void Withdrawal();

string choice, username , password, check_username, check_password, lastname;
int bank_card_id, date, month ,year ,bank_choice , money;
int bank_balance = 0;

int main (){
     system("clear");
     sleep(1);
     log_in_panel();

     return 0;

}


void log_in__panel(){
    cout << "\tWelcome to the centeral-bank\n "<< endl;
    cout << "Enter <<log>> to log in to your account"<< endl;
    cout << "Enter <<Reg>> for registration\n "<< endl;
    cout << "Enter your choice :";
    cin >> choice;
    if (choice == "log"|| choice == "Log" || choice == "LOG"){
    cout << "\n Please enter your username :\n>>>";
    cin >> username ;
    cout << "\n Please enter your password :\n>>>"; 
    cin >> password ;

    ifstream read(username + ".txt");
    getline(read , check_username);
    getline(read , check_password);

    if (username == check_username && password == check_password){
      sleep(1);
      system("clear");
      bank_page();
    }
    else {
         cout << "\nUser is not found \n"<< endl;
         sleep (1);
         system("clear");
         Log_in_panel();
    }
  }
  else if (choice == "Reg" || choice == "reg"){
      cout << "\nPlease enter username -> "; cin >> username;
      cout << "\nPlease enter lastname -> "; cin >> lastname;
      cout << "\nPlease enter password -> "; cin >> password;
      cout << "\nEnter your date  -> "; cin >> date ;
      cout << "\nEnter your month -> "; cin >> month;
      cout << "\nEnter your year -> "; cin >> year;

      ofstream personal_user_info;

      personal_user_info.open(username + "pr.txt", od=fstream:: out | ofstream:: app);
      personal_user_info << "Name : " << username << " "<< lastname << endl << "Password : " << password 
      << endl << "Date : "<< date << "/" << month << "/"<< year << endl;
      personal_user_info.close();
      ofstream user_file ;
      user_file.open(username + ".txt", ofstream:: out | ofstream:: app);
      user_file<< username << endl << password ;
      user_file.close();

      cout << "\n You finished your registration "<< endl;
      sleep (1);
      system ("clear");
      Bank_page();
  }
  else {
      cout << "\n Command is not found \n "<< endl;
      sleep(1);
      cout << "Plese try again!\n"<< endl;
      sleep(2);
      system("clear");
      Log_in_panel();
  }
}

void Bank_page(){
    cout << "\tWelcome to the Bank page "< username << endl<< endl;
    cout << "=========================================="<< endl;
    cout << "|" << " [1] --> Account info "<<"                     |"<< endl;
    cout << "|" << " [2] --> Deposit "<<"                          |"<< endl;
    cout << "|" << " [3] --> Check balance "<<"                    |"<< endl;
    cout << "|" << " [4] --> Withdrawal "<<"                       |"<< endl;
    cout << "|" << " [5] --> exit "<<"                             |"<< endl; 
    cout << "=========================================="<< endl;
    cout << endl;
    while (bank_choice !=5){
        cout  << "Enter the command -> ";cin >> bank_choice;
        Command_panel();
    }
}

void Command_panel(){
    switch(bank_choice)
    {
    case 0: system("clear"); Bank_page():
        break;
    case 1: system("clear"); Acconut_info():
        break;
    case 2: system("clear"); Deposit():
        break;
    case 3: system("clear"); Balance():
        break;
    case 4: system("clear"); Withdrawal():
        break;
    case 5: cout << "\n You left the bank app \n "<< endl;sleep(1); break; 
        break;
    default : cout << "\n Command is not found "<< endl; system("clear"); Bank_page():
    }
}

  void Account_info(){
   cout << "Your personal information \n "<< endl;
    sleep (1);
    ifstream tiop(username + "pr.txt");
    char ch;
    while (tiop)
    {
        tiop.get(ch);
        cout << ch;
    }
    sleep (1);
    cout << "Enter [0] to go back\n"<< endl;
    sleep (1);
  }

void Depposit(){
    cout << "\t Deposit page \n "<< endl;
    cout << "Enter the amount of money -> "; cin >> money ;
    if(money > 1000){
    sleep(1);
    cout << "\tLoading. . .\n "<< endl;
    sleep(2);
    cout << "\n Too big number , please try again !\n"endl;
    sleep(2);
    system("clear");
    Deposit():
    }
    else {
      sleep(1);
      cout << " \n Loading. . .\n"<< endl;
      sleep(2);
      cout << "\n Deposit added succesfully \n "<< endl;
      sleep(2);
      system ("clear");
      Bank_page();
    }
}
void Balance(){
    cout << "Your balance information\n"<< endl;
    cout << "Name:"<< username << " " << username << endl;
    sleep(2);
    cout<< "\n Your current balance is : " << bank_balance << endl;
    char yn;
    sleep(2);
    cout << "\n Do you want to put money on your card(y/n)->";cin>> yn ;
    if (yn == 'y'){
        cout << "\nEnter the amount of mooney ->";cin >> money ;
        bank_balance += money ;
        cout << "\n You got +"<< money << " $\n"<< endl;
        cout << "Now your balance is :"<< bank_balance << endl;
        sleep(3);
        system("clear");
        Bank_page();
    }
    else if (yn == 'n'){
        cout << "\n Your balance is still the same \n"<< endl;
        sleep(2);
        system("clear");
        Bank_page();
    }
    else{
        cout << "\n Command is not found, please try again \n "<< endl;
        sleep(2);
        system("clear");
        Balance();
    }
} 

void Withdrawal(){
    cout << "\tWithdrawal page\n "<< endl;
    cout << "Enter the amout of money -> "; cin >> money ;
    if(bank_balance < money ){
        sleep(1);
        cout << "\n Loading. . .\n "<< endl;
        sleep(2);
        cout << "\n You do not have engough money on your card!\n "<< endl;
        sleep(2);
        system("clear");
        Bank_page();
    }
    else(
        sleep(1);
        cout << "\n Loading. . .\n "<< endl;
        sleep(2);
        cout << "\n Withdrawal added succesfully \n "<< endl; 
        bank_balance -= money ;
        sleep(2);
        system("clear");
        Bank_page();
    )
}
return 0;