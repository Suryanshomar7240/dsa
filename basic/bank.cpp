//***************************************************************************
//                         HEADER FILES
//***************************************************************************
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
//***************************************************************************
//                      USER DEFEINED FUNTIONS
//***************************************************************************
void intro();
void newa();
void show();
void withdrawl();
void deposit();
void update();
void search();
void deletea();
//***************************************************************************
//                  CONSTANT VARIABLE & STRINGS
//***************************************************************************
int a, c, d, e[3], i;
char z[50];
//***************************************************************************
//                         CLASS
//***************************************************************************
class newaccount
{
public:
    char Name[50], fname[50], address[50], acctype;
    double addarno[3], accno, money;
    int dob[3];
    int gaccno()
    {
        accno = rand();
        printf("your accno is =");
        return accno;
    }
    void enter()
    {
        printf("Enter your name=");
        scanf("%s",Name);
        printf("Enter you fathers name=");
        cin >> fname;
        printf("Enter your date of birth(dd/mm/yyyy)=");
        for (i = 0; i < 3; i++)
        {
            cout << "/";
            cin >> dob[i];
        }
        printf("Enter your address=");
        gets(address);
        printf("Enter your addar no.(abcd(Enter)abcd(Enter)abcd)=");
        cin >> addarno[0] >> addarno[1] >> addarno[2];
        printf("Enter the account type{ C(current)/S(saving) }=");
        cin >> acctype;
        printf("Enter the intial balance=");
        cin >> money;
        accno = gaccno();
        cout << accno;
    }

    void view()
    {
        cout << "\n\t\t\t";
        printf("Account no.=");
        cout << accno << "\n\n";
        printf("User Name =");
        cout << Name << endl;
        printf("Father's Name =");
        cout << fname << endl;
        printf("Account type =");
        if (acctype == 'C' || acctype == 'c')
            cout << "Current";
        else
            cout << "Saving";
        cout << endl;
        printf("Balance =");
        cout << money << endl;
        printf("Addhar no=");
        cout << addarno[0] << addarno[1] << addarno[2] << "   \n";
        printf("Date of Birth=");
        for (a = 0; a < 3; a++)
        {
            cout << dob[a] << "/";
        }
        cout << endl;
        printf("ADDRESS=");
        cout << address << endl;
    }
    void modify()
    {
        cout << endl;
        c = 0;
        printf("1.Name");
        cout << endl;
        printf("2.Fater's name");
        cout << endl;
        printf("3.address");
        cout << endl;
        printf("4.dob");
        cout << endl;
        printf("5.exit");
        cout << endl;
        printf("Enter your choice=");
        cin >> c;
        switch (c)
        {
        case 1:
            printf("ENTER NEW NAME=");
            gets(z);
            strcpy(Name, z);
            break;
        case 2:
            printf("ENTEER NEW FATHERS NAME=");
            gets(z);
            strcpy(fname, z);
            break;
        case 3:
            printf("ENTER NEW ADDRESS=");
            gets(z);
            strcpy(address, z);
            break;
        case 4:
            printf("ENTER NEW DOB(dd/mm/yy)=");
            cin >> dob[0] >> dob[1] >> dob[2];
            break;
        case 5:
            exit(0);
        }
    }
} newacc;
//***************************************************************************
//                       MAIN MENU
//***************************************************************************
void intro()
{
    printf("                    There are following operation ");
    cout << "\n                          ";
    printf("Plese choose one");
    cout << "\n\n  ";
    printf("1.Create A new Account");
    cout << "\n  ";
    printf("2.Withdraw from an Account");
    cout << "\n  ";
    printf("3.Deposit to an Account");
    cout << "\n  ";
    printf("4.Update An Account");
    cout << "\n  ";
    printf("5.Serach An Account");
    cout << "\n  ";
    printf("6.Show all the details");
    cout << "\n  ";
    printf("7.Delete an account");
    cout << "\n  ";
    printf("8.Exit");
    cout << "\n  ";
    (2);
    printf("Please Enter your choice=");
    cin >> a;
}
void welcome()
{
    cout << endl;
    printf("                        Welcome to Indian Bank");
    cout << endl
         << endl;
    printf("                         Bank Mangment Project");
    cout << "\n\n";
    getch();
}
//***************************************************************************
//                   FUNCTION DEFINATION
//***************************************************************************
void newa() //FUNCTION TO CREATE NEW ACCOUNT
{
    ofstream fout("s.dat", ios::binary | ios::app);
    newacc.enter();
    fout.write((char *)&newacc, sizeof(newacc));
    fout.close();
}
void withdrawal() //FUNTION TO WITHDRAWAL MONEY
{
    fstream fin("s.dat", ios::binary | ios::in | ios::out);
    a = 0;
    d = 0;
    c = 0;
    i = 0;
    printf("Please enter the accno of the user=");
    cin >> a;
    printf("Enter the amount to be withdrawal=");
    cin >> c;
    while (!fin.eof())
    {
        fin.read((char *)&newacc, sizeof(newacc));
        if (a == newacc.accno)
        {
            if (newacc.money < c)
                printf("your account does not have appropriate balance  ");
            else
                newacc.money -= c;
            d = -1 * sizeof(newacc);
            fin.seekp(d, ios::cur);
            fin.write((char *)&newacc, sizeof(newacc));
            cout << "\n\t\t";
            printf("Thank you");
            cout << endl;
            printf("Your new details are");
            cout << endl;
            newacc.view();
            i++;
            break;
        }
    }
    if (i == 0)
    {
        printf("Account does not found");
    }
    fin.close();
}
void deposit() //FUNTION TO DEPOSIT MONEY
{
    fstream fin("s.dat", ios::binary | ios::in | ios::out);
    (2);
    a = 0;
    c = 0;
    printf("Please enter the accno of the user=");
    cin >> a;
    printf("Enter the amount to be deposit =");
    cin >> c;
    while (!fin.eof())
    {
        fin.read((char *)&newacc, sizeof(newacc));
        if (newacc.accno == a)
        {
            newacc.money += c;
            d = -1 * sizeof(newacc);
            fin.seekg(d, ios::cur);
            fin.write((char *)&newacc, sizeof(newacc));
            cout << "\n\t\t";
            printf("Thank you");
            cout << endl;
            printf("Your new details are");
            cout << endl;
            newacc.view();
            break;
        }
    }
    if (i == 0)
    {
        printf("Account does not found");
    }
    fin.close();
}
void search() //FUNTION TO SEARCH A ACCOUNT
{
    ifstream fin("s.dat", ios::binary);
    (6);
    c = 0;
    i = 0;
    printf("Enter the accountno whose details is to be searched=");
    cin >> c;
    while (fin)
    {
        fin.read((char *)&newacc, sizeof(newacc));
        if (c == newacc.accno)
        {
            newacc.view();
            i++;
            break;
        }
    }
    if (i == 0)
    {
        printf("Account does not found");
    }
    fin.close();
}
void update() //FUNTION TO UPDATE  A ACCOUNT
{
    (6);
    c = 0;
    d = 0;
    i = 0;
    printf("Enter Accno=");
    cin >> c;
    cout << endl;
    fstream fin("s.dat", ios::binary | ios::in | ios::out);
    while (!fin.eof())
    {
        d = fin.tellg();
        fin.read((char *)&newacc, sizeof(newacc));
        if (c == newacc.accno)
        {
            newacc.view();
            cout << "\n\n";
            printf("Enter The New Details of account");
            newacc.modify();
            fin.seekg(d);
            fin.write((char *)&newacc, sizeof(newacc));
            cout << "\n\t\t";
            printf("Thank you");
            cout << endl;
            printf("Your new details are");
            cout << endl;
            newacc.view();
            i++;
            break;
        }
    }
    if (i == 0)
    {
        printf("Account does not found");
    }
    fin.close();
}
void show() //FUNCTION TO SHOW ALL DETAILS
{
    ifstream fin("s.dat", ios::binary);
    while (fin.read((char *)&newacc, sizeof(newacc)))
    {
        newacc.view();
    }
    fin.close();
}
void deletea() //FUNTION TO DELETE A ACCOUNT
{
    ifstream inFile;
    ofstream outFile;
    a = 0;
    printf("ENTER ACCNO=");
    cin >> a;
    inFile.open("s.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be open !! Press any Key...";
        return;
    }
    outFile.open("a.dat", ios::binary | ios::app);
    while (inFile.read((char *)&newacc, sizeof(newacc)))
    {
        if (newacc.accno != a)
        {
            outFile.write((char *)&newacc, sizeof(newacc));
        }
    }
    inFile.close();
    outFile.close();
    remove("s.dat");
    rename("a.dat", "s.dat");
    cout << "\n\n\t";
    printf("Record Deleted ..");
}
//***************************************************************************
//                             MAIN
//***************************************************************************
int main()
{
    //clrscr();
    welcome();
    char b[3];
    cout << "\n\n";
    do
    {
        intro();
        switch (a)
        {
        case 1:
            newa();
            break;
        case 2:
            withdrawal();
            break;
        case 3:
            deposit();
            break;
        case 4:
            update();
            break;
        case 5:
            search();
            break;
        case 6:
            show();
            break;
        case 7:
            deletea();
            break;
        case 8:
            exit(0);
        default:
            cout << "\n\n  ";
            printf("Wrong Input ");
        }
        cout << "\n\n  ";
        printf("Do you Want to countinue=");
        gets(b);
    } while (strcmpi(b, "y") == 0 || strcmpi(b, "yes") == 0);
    getch();
    return 0;
}
//***************************************************************************
//                         THANKS
//***************************************************************************
