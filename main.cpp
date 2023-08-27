#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#define Max_books 100
#include <algorithm>
#include <cctype>
#define users_admin 50
using namespace std;

class books{
	protected:
	string titleofBooks[Max_books],nameofAuthor[Max_books],bookGenre[Max_books],
	publicationYear[Max_books];
	int total, bookidnum[Max_books];
    bool bookStatus[Max_books];
	public:
		books():total(0){}
		void addBooks();
		void viewBooks();
		void searchBooks();
		void bookCheckout();
		void booknums();
		void bookReturn();
		void bookReservation();
		void book();
		void finecalculation();
		void exit();


};
void books :: booknums(){
	booknum:
		cout << "---------------------------------\n";
		cout << "Enter The Books You Want To Add\n\n";
		cout << "Number of books: "<< total << endl;
		cout << "---------------------------------\n";
		cout << "Enter Book Title: ";
	    getline(cin, titleofBooks[total]);
	    cout <<"Book Id Number: ";
	    cin >> bookidnum[total];
	    cin.ignore();
		for(int i=0; i<total;i++){
			string newbook =titleofBooks[total];
			int idnum = bookidnum[total];
			if (newbook == titleofBooks[i] && idnum == bookidnum[i]){
				cout << "Book Title Existing";
				goto booknum;
		}
	}
}

void books :: addBooks(){
	int bknum = 0;
	bknum++;
	for(int i=total; i<bknum+total; i++){
		cout << "Book Author: ";
	    getline(cin, nameofAuthor[i]);
	    cout << "Genre: ";
	    getline(cin, bookGenre[i]);
	    cout << "Publication date: ";
	    getline(cin, publicationYear[i]);
	    bookStatus[i] = false; 
	}
	total=bknum+total;
	cout << "Adding Successfully\n";
}
void books :: viewBooks(){
	if (total == 0){
		cout << "No Books is Added\n";
	}
	 for (int i = 0; i < total; i++) {
	 	cout << "_____________________________________" << endl;
	 	cout << "Book id number: " << bookidnum[i] << endl;
        cout << "Book title: " << titleofBooks[i] << endl;
        cout << "Author: " << nameofAuthor[i] << endl;
        cout << "Status: " << (bookStatus[i] == 0 ? "Available" : "Checked out") << endl;
        cout << "Genre: " << bookGenre[i] << endl;
        cout << "Publication Year: " << publicationYear[i] << endl;
        cout << "_____________________________________" << endl;
    }
}
void books :: searchBooks(){
	if(total == 0){
		cout << "No Data is entered" << endl;
	}else{
		string srbook;
		cout << "------------------------------------------------------\n";
		cout << "Enter Name or Author of Book you want to search\n\n";
		cout << "Number of books: "<< total << endl;
		cout << "------------------------------------------------------\n";
		cout << "Search Book: ";
		getline(cin, srbook);

		for (int i =0; i<total;i++){
			if( srbook == titleofBooks[i]){
				cout <<"_____________________________________\n";
				cout << "Book Id Number:" << bookidnum[i] << endl;
				cout << "Book title: "<< titleofBooks[i] << endl;
				cout << "Author: "<< nameofAuthor[i]<< endl;
				cout << "Genre: " << bookGenre[i] << endl;
				cout << "Publication Year: "<< publicationYear[i] << endl;
				cout <<"_____________________________________\n";
		  }else cout << "Search Not Found..!!" << endl;
		}
   }
}

void books::bookCheckout() {
	char yn;
    if (total == 0) {
        cout << "No books available" << endl;
    } else {
        cout << "__________________________________________\n";
        cout << "Books Checkout\n\n";
        cout << "Books available: " << total << endl;
        cout << "__________________________________________\n";

        for (int i = 0; i < total; i++) {
        	viewBooks();
            int idnums;
            cout << "Enter ID Number Of Book: ";
            cin >> idnums;

            if (idnums == bookidnum[i]) {  // Compare with the index i
                if (bookStatus[i] == 0) {
                    cout << "Checkout Successfully" << endl;
                    bookStatus[i] = 1;  // Mark the book as Checked out
                    system("pause");
                    system("cls");
                    
                    return;
                } else {
                    cout << "Book is Already Checked out" << endl;
                }
            } else {
                cout << "Book Unavailable"<< endl;
            }
        }
    }
}
void books :: bookReturn(){
	if(total == 0){
		cout << "No books Available\n";
	}else{
		int idnums;
		cout << "_________________________________\n\n";
		cout <<"Book Return\n";
		cout << "__________________________________\n\n";
		cout << "Enter Book Id Number to Return: ";
		cin >> idnums;
		for (int i=0; i<total;i++){
			if(idnums == bookidnum[i]){
				if(!bookStatus[i] == 0){
					cout << "Return Successfully"<< endl;
					bookStatus[i] = 0;
				}else{
					cout << "Book Id Don't Exist" << endl;
				}
			}else{
				cout <<"Return Unsuccessful" << endl;
			}
		}
	}
}
void books :: bookReservation(){
	bookrservtion:
	if (total == 0){
		cout << "No books Available\n";
	}else {
		string dates;
		int idnums;
		string bname;
		char yn;
		cout << "-----------------------------------\n\n";
		cout << "Book Reservations\n";
		cout << "Books Available: " << total << endl;
		cout << "-----------------------------------\n\n";
		cout << "view books available y/n: ";
		cin >> yn;
		cin.ignore();
		if(yn == 'y' || yn == 'Y'){
		viewBooks();
			for (int i = 0; i < total; i++) {
		
		  }
		}else if( yn == 'n' || yn == 'N'){
		     return;
		}
		
        cout << "Book Name: ";
        getline(cin, bname);
        cout << "Book Id number: ";
        cin >> idnums;
        cin.ignore();
        cout << "Book reservation date dd/mm/yy: ";
        getline(cin, dates);
        for (int j = 0; j< total; j++){
        	if(bname == titleofBooks[j] && idnums == bookidnum[j]){
          if(bookStatus[j] == 0){
					cout << "Book Reservation Successful"<< endl;
					bookStatus[j] = 1;
				}else{
					cout << "Book Id Don't Exist" << endl;
				}
		}else {
			cout << "Reservation Unsuccessful" << endl;
		}
	  }
 	}
 }
void books :: finecalculation(){
	if(total == 0){
		cout << "No books Available\n"; 
	}else{
		int days7 = 50, days14 = 100, days26 = 150;
		int m1 = days7 + days26;
		cout << "_____________________________________\n\n";
		cout << "Fine calculations\n\n";
		cout << "_____________________________________\n\n";
		cout << "1-7days overdue = " << days7 << endl;
		cout << "8-14days overdue = " << days14 << endl;
		cout << "15-14days overdue = " << days26 << endl;
		cout << "1month overdue = " << m1 << endl;
	}
}
void books :: exit(){
	cout << "Thank you for using our system..!!"<< endl;
	system("exit");
}
class User : public books{
	private: 
	string adminpass[users_admin], admin[users_admin], usersname[users_admin], userspass[users_admin];
	int user, contactnums[users_admin];
	public:
	User():user(0){}
	void registration();
	void login();
	void accsmanagement();
	void usersinfo();
	void updateusers();
};
void User :: updateusers(){
	string dlte;
	int a;
	if(user == 0){
	cout << "No users available\n";
	}
	else{
		cout << "________________________________\n";
		cout << "1."<<"Delete all users" << endl;
		cout << "2."<<"Delete specific user" << endl;
		cout << "________________________________\n";
		cout << "Enter: ";
	cin >> a;
	cin.ignore();
	if(a == 1){
		user = 0;
		cout << "All user is deleted\n";
	}else if (a == 2){
		cout << "Enter username: ";
		getline(cin,dlte);
		for(int i=0; i< user; i++){	
		if(dlte == usersname[i]){
			for (int j =0; j<user;j++){
				usersname[j]=usersname[j+1];
				userspass[j]=userspass[j+1];
				contactnums[j]=contactnums[j+1];
		}
		user--;
		cout << "User deleted\n";
		}
     	}
	 }
	
	}
}
void User :: usersinfo(){
	if(user == 0){
		cout << "No users available\n";
	}else{
		for (int i=0; i<user; i++){
			cout << "_________________________________\n\n";
			cout << "Username: " << usersname[i] << endl;
			cout << "Passwords: " << userspass[i] << endl;
			cout << "Contact number: " << contactnums[i] << endl;
			cout << "_________________________________\n\n";
		}
	}
}
void User :: registration(){
int Newusers = 0;
Newusers++;

	cout <<"_____________________________\n\n";
	cout <<"Account Registration\n\n";
	cout <<"_____________________________\n\n";
	
	for (int i=user; i<user +Newusers; i++){
	cout << "Username: ";
	getline(cin,usersname[i]);
	cout << "Password: ";
	getline(cin, userspass[i]);
	cout << "Conctact number: ";
	cin >> contactnums[i];
	cin.ignore();
	}
	user += Newusers;
	cout << "Regestered Success" << endl;		
	}
void User :: accsmanagement(){
int optn;
	
	for(int i = 0; i < user; i++){		
cout << "_______________________________\n\n";
cout << setw(20)<<"Account Management\n\n";
cout << "Account Registered: " << user << endl;
cout << "_______________________________\n\n";
while(true){
cout << "1."<<setw(5) <<"view users\n";
cout << "2."<<setw(5) <<"delete users\n";
cout << "3."<<setw(5) <<"exit\n";
cout << "_______________________________\n";
cout << "Enter Trasaction: ";
cin >> optn;
cin.ignore();

	switch(optn){
		case 1:
			system("cls");
			usersinfo();
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			updateusers();
			system("pause");
			system("cls");
			break;
		case 3:
		
			 system("cls");
			 return;
			 system("cls");
			 break;	
			}
	}
}
}
void User :: login(){
int optn2;
char yn;
string usernames;
string passwords;
string admin = "admin";
string adminpass="adminpogi";

cout << "____________________________________\n\n";
cout << setw(20)<<"Login\n\n";
cout << "____________________________________\n\n";

cout << "Username: ";
getline(cin, usernames);
cout << "Password: ";
getline(cin, passwords);

for(int i = 0; i < user; i++){
if(usernames == usersname[i] &&  passwords == userspass[i]){
	cout << "Welcome: " << usersname[i] << endl;
	while(true){
		cout << "___________________________________\n\n";
    	cout << "1." << setw(5) << "View Books" << endl;
    	cout << "2." << setw(5) << "Book Checkout" << endl;
    	cout << "3." << setw(5) << "Book Returns" << endl;
    	cout << "4." << setw(5) << "Book Reservation" << endl;
    	cout << "5." << setw(5) << "View over due fines" << endl;
    	cout << "6." << setw(5) << "exit" << endl;
    	cout << "___________________________________\n\n";
    	cout << "Enter Transaction: ";
    	cin >>optn2;
    	cin.ignore();
		switch(optn2){
			again:
			case 1:
				system("cls");
				viewBooks();
				system("pause");
				system("cls");
				return;
				break;
			case 2:
				system("cls");
				bookCheckout();
				system("pause");
				return;
				break;
			case 3:
				system("cls");
				bookReturn();
				system("pause");
				break;
			case 4:
				system("cls");
				bookReservation();
				system("pause");
				return;
				break;
			case 5:
				system("cls");
				finecalculation();
				system("pause");
				return;
				break;
			case 6:
				system("cls");
				return;
			default:
				cout << "Invalid input";
				break;
		}
	}
	return;
}
}
if(usernames == admin && passwords == adminpass){
	system("cls");
	while(true){
		cout << "___________________________________\n\n";
		cout << setw(30)<<"Welcome to admin dashboard\n\n" << endl;
		cout << "___________________________________\n\n";
		cout << "1." << setw(5) << "Accounts Management" << endl;
		cout << "2." << setw(5) << "Add Books" << endl;
    	cout << "3." << setw(5) << "View Books" << endl;
    	cout << "4." << setw(5) << "Book Checkout" << endl;
    	cout << "5." << setw(5) << "Book Returns" << endl;
    	cout << "6." << setw(5) << "Book Reservation" << endl;
    	cout << "7." << setw(5) << "View over due fines" << endl;
    	cout << "8." << setw(5) << "exit" << endl;
    	cout << "___________________________________\n\n";
    	cout << "Enter Transaction: ";
    	cin >>optn2;
    	cin.ignore();
		switch(optn2){
			opt2:
			case 1:
				again3:
				system("cls");
				accsmanagement();
				system("pause");
				break;
			case 2:
				again4:
				system("cls");
				booknums();
				addBooks();
				system("pause");
				ask1:
				cout << "Do you want to add a book again y/n: ";
				cin >>yn;
				cin.ignore();
				if (yn == 'y' || yn == 'Y'){
				goto again4;
				}else if(yn=='n'|| yn == 'N'){
					goto opt2;
					system("cls");
				}else goto ask1;
				return;
				break;
			case 3:
				system("cls");
				viewBooks();
				system("pause");
				system("cls");
				break;
			case 4:
			again2:
				system("cls");
				bookCheckout();
				system("pause");
				cout << "Do you want to checkout again y/n: ";
				cin >> yn;
				if(yn == 'y' || yn == 'Y'){
					goto again2;
				}
				else if(yn=='n' || yn=='N'){
					goto opt2;
				system("cls");
				} else return;
				break;
			case 5:
				system("cls");
				bookReturn();
				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				bookReservation();
				system("pause");
				system("cls");
				break;
			case 7:
				system("cls");
				finecalculation();
				system("pause");
				system("cls");
				break;
			case 8:
				system("cls");
				return;
			default:
				cout << "Invalid input";
				break;
		}
	}
		
}else{
	cout << "Account doesn't exist"<<endl;
}
}	
int main(int argc, char** argv) {
    User users1;
	books book;
	
	int optn1, optn2;
	char yn;

	while(true){
		system("cls");
		cout << "=====================================\n\n";
		cout << setw(30)<< "Welcome to our system\n\n";
		cout << "=====================================\n\n";
		cout << "1." << setw(7)<<"Login\n";
		cout << "2." << setw(21)<<"Register an account\n";
		cout << "3." << setw(6)<<"exit\n";
		cout << "=====================================\n\n";
		
		cout << "Enter trasaction: ";
		cin>>optn1;
		cin.ignore();
			
		switch(optn1){
	    again:
			case 1:
				system("cls");
				users1.login();
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				users1.registration();
				system("pause");
				break;
			case 3:
				book.exit();
				return 0;
				system("cls");
			default:
				cout << "invalid input\n";
					return 0;
				break;
				
		}
		
}
	return 0;

}
