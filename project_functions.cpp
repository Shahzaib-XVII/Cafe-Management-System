#include "project.h"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLACK "\033[1;30m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define BOLD "\033[1m"
#define WHITE_BACKGROUND "\033[1;47m"
#define RESET_BACKGROUND "\033[0m"
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void admin_login()
{

  int choice = 0, flag = 0, mark, x;
  char arr1[16], arr2[16], arr3[16], arr4[16], reply[500], ch;
  cin.ignore();

  do
  {

    clrscr();
    intro_admin();

    if (mark == 1)
    {
      cout << RESET << RED << BOLD << "\n\n\n\n\t\t\tWrong User ID or password." << RESET;
    }

    mark = 0;

    cout << RESET << GREEN << BOLD << "\n\n\n\n\t\t\tEnter username:" << RESET;
    cin.getline(arr1, 16);

    cout << RESET << GREEN << BOLD << "\n\t\t\tEnter password:" << RESET;
    cin.getline(arr4, 16);

    fstream fs;
    fs.open("admin_crd.txt", ios::in);
    fs.getline(arr2, 16, ' ');
    fs.getline(arr3, 16, '\n');
    fs.close();

    if (strcmp(arr1, arr2) == 0 and strcmp(arr4, arr3) == 0)
    {

      do
      {

        random_drop();
        cout << "\n\n\t\t\tWelcome" << BOLD << GREEN << " Admin." << RESET;
        cout << BOLD << BLUE << "\n\n\t\t\tWhat do you want to do ?\n\n\n"
             << RESET;
        cout << "\t\t\t1. Search/add/remove item\n\n\t\t\t2. Add/Remove Credentials\n\n\t\t\t3. See Notifications\n\n\t\t\t4. Manage Online/Schedule orders\n\n\t\t\t5. Manage complaints\n\n\t\t\t6. Check Best seller employee\n\n\t\t\t7. Log Out\n\n";

        cin >> choice;

        switch (choice)
        {
        case 1:

          stock();
          break;

        case 2:

          do
          {

            flag = 0;

            cout << BOLD << GREEN << "\n\t\t\tSelect" << RESET << "\n\n\t\t\t1. Add credentials\n\n\t\t\t2. Remove credentials\n\n\t\t\t3. Update credentials\n\n\t\t\t4. Return\n\n\t\t\t";
            cin >> choice;

            if (choice == 1)
              add_crd();

            else if (choice == 2)
              rem_crd();

            else if (choice == 3)
              update_crd();

            else if (choice == 4)
              break;

            else
              cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
                   << RESET;

          } while (1);

        case 3:
          low_stock_notification();
          break;

        case 4:
          approval_order();
          break;

        case 5:

          do
          {

            choice = 0;
            cmp_read();
            cmp_ans();

            cout << "\n\t\t\tPress 1 to leave a reply, 2 to delete all conversation or 0 to go back\n\n";
            cin >> choice;

            if (choice == 1)
            {
              cin.ignore();
              fstream rp;

              cout << "\n\t\t\tEnter your reply: ";
              cin.getline(reply, 500);

              rp.open("reply.txt", ios::out | ios::app);
              rp << reply;
              rp.close();

              cout << BOLD << GREEN << "\n\n\t\t\tReply successfully added.\n\n"
                   << RESET;
            }

            else if (choice == 2)
            {
              fstream f;
              fstream fs;
              f.open("temp.txt", ios::out);
              fs.open("temp1.txt", ios::out);
              remove("reply.txt");
              remove("complaints.txt");
              rename("temp.txt", "reply.txt");
              rename("temp1.txt", "complaints.txt");
              f.close();
              break;
            }

            else if (choice == 0)
              break;

            else
            {
              cin.clear();
              cin.ignore();

              cout << "\n\nInvalid Input\n\n";
            }

          } while (1);

          break;

        case 6: // best seller employee
          best_employee();
          break;

        case 7:

          flag = 1;
          break;

        default:
          cin.clear();
          cin.ignore();
          cout << "\n\nInvalid Option selected. Select again.";
        }

        if (flag == 1)
          break;

      } while (1);
    }

    else
    {

      mark = 1;
    }

    if (flag == 1)
      break;

  } while (1);

} // func closing bracket

void employee_login()
{
  int choice = 0, flag, mark = 0, sales;
  char arr1[16], arr2[16], arr3[16], arr4[16];
  cin.ignore();

  do
  {
    flag = 0;

    clrscr();
    intro_employee();

    if (mark == 1)
    {
      cout << RESET << RED << BOLD << "\n\n\n\n\t\t\tWrong User ID or password." << RESET;
    }

    mark = 0;

    cout << RESET << GREEN << BOLD << "\n\n\n\n\t\t\tEnter username:" << RESET;
    cin.getline(arr1, 16);

    cout << RESET << GREEN << BOLD << "\n\t\t\tEnter password:" << RESET;
    cin.getline(arr4, 16);

    fstream fs;
    fs.open("emp_credentials.txt", ios::in);

    while (fs.getline(arr2, 16, ' '), fs.getline(arr3, 16, '\n'))
    {
      if (strcmp(arr2, arr1) == 0 and strcmp(arr3, arr4) == 0)
      {
        flag = 1;
        break;
      }
    }

    fs.close();

    if (flag == 1)
    {

      do
      {

        flag = 0;

        cout << "\n\n\t\t\tWelcome " << BOLD << GREEN << arr2 << RESET << "!";
        cout << "\n\n\t\t\t1. Take orders\n\n\t\t\t2. See and search stock\n\n\t\t\t3. Online/scheduled orders\n\n\t\t\t4. Log out\n\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
          sales = orders();
          emp_sales(arr2, sales);
          break;

        case 2:
          do
          {

            stock_display();
            search_stock();
            cout << "\n\n\t\t\tPress 0 to go back or 1 to search stock again.";
            cin >> choice;

            if (choice == 0)
            {
              break;
            }

            else if (choice == 1)
              continue;

            else
              cin.clear();
            cin.ignore();
            cout << BOLD << RED << "\n\t\t\tInvalid Input.\n\n"
                 << RESET;

          } while (1);

          break;

        case 3:
          approval_order();
          break;

        case 4:
          flag = 1;
          break;

        default:
          cin.clear();
          cin.ignore();
          cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
               << RESET;
          break;
        }

        if (flag == 1)
          break;

      } while (1);
    }

    else
      mark = 1;

    if (flag == 1)
      break;

  } while (1);
}

void student_login()
{
  int choice = 0, flag, mark = 0, g;
  char arr1[16], arr2[16], arr3[16], arr4[16];
  cin.ignore();

  do
  {
    flag = 0;

    clrscr();
    intro_student();

    if (mark == 1)
    {
      cout << RESET << RED << BOLD << "\n\n\n\n\t\t\tWrong User ID or password." << RESET;
    }

    mark = 0;

    cout << RESET << GREEN << BOLD << "\n\n\n\n\t\t\tEnter username:" << RESET;
    cin.getline(arr1, 16);

    cout << RESET << GREEN << BOLD << "\n\t\t\tEnter password:" << RESET;
    cin.getline(arr4, 16);

    fstream fs;
    fs.open("user_credentials.txt", ios::in);

    while (fs.getline(arr2, 16, ' '), fs.getline(arr3, 16, '\n'))
    {
      if (strcmp(arr2, arr1) == 0 and strcmp(arr3, arr4) == 0)
      {
        flag = 1;
        break;
      }
    }

    fs.close();

    if (flag == 1)
    {

      do
      {

        flag = 0;

        cout << "\n\t\t\tWelcome " << BOLD << GREEN << arr1 << RESET << "!";
        cout << BLUE << BOLD << "\n\n\t\t\tWhat do you want to do?" << RESET;
        cout << "\n\n\t\t\t1. Submit complaints\n\n\t\t\t2. See and search menu\n\n\t\t\t3. Schedule order\n\n\t\t\t4. Notifications\n\n\t\t\t5. Log out\n\n";
        cin >> choice;

        switch (choice)
        {

        case 1: // complaints
          user_complaints(arr2);
          break;

        case 2: // see and search menu
          do
          {

            stock_display();
            search_stock();
            cout << "\n\n\t\t\tPress 0 to go back or 1 to search menu again.\n\n";
            cin >> choice;

            if (choice == 0)
            {
              break;
            }

            else if (choice == 1)
              continue;

            else
              cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
                   << RESET;

          } while (1);

          break;

        case 3: // scheduled orders
          sch_order(arr2);
          break;

        case 4: // notifications
          g = user_order_notification();

          if (g == 0)
            cout << RED << BOLD << "\n\n\t\t\t- Your online order request has been rejected.\n\n"
                 << RESET;

          else if (g == 1)
            cout << GREEN << BOLD "\n\n\t\t\t- Your online order request has been accepted.\n\n"
                 << RESET;

          else if (g == 2)
            cout << YELLOW << BOLD << "\n\n\t\t\t- Your online order request is pending.\n\n"
                 << RESET;

          else
            cout << BOLD << BLUE << "\n\n\t\t\t- No Notifications.\n\n"
                 << RESET;

          admin_order_notification(3);

          break;

        case 5: // log out
          flag = 1;
          break;

        default:
          cin.clear();
          cin.ignore();

          cout << BOLD << RED << "\n\n\t\t\tInvalid Input." << RESET;
        }

        if (flag == 1)
          break;

      } while (1);

      break;
    }

    else
      mark = 1;

  } while (1);
}

void clrscr()
{
  cout << "\033[2J\033[1;1H";
}

void intro_home()
{
  clrscr();

  cout << RED << BOLD << "\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           WELCOME TO DIGITAL CAFE       ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------";

  cout << RED << BOLD << "\n\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()                HOME MENU                ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------\n";
}

void intro_admin()
{
  clrscr();

  cout << RED << BOLD << "\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           WELCOME TO DIGITAL CAFE       ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------";

  cout << RED << BOLD << "\n\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()            ADMIN LOGIN MENU             ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------\n";
}

void intro_employee()
{
  clrscr();

  cout << RED << BOLD << "\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           WELCOME TO DIGITAL CAFE       ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------";

  cout << RED << BOLD << "\n\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           EMPLOYEE LOGIN MENU           ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------\n";
}

void intro_student()
{
  clrscr();

  cout << RED << BOLD << "\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           WELCOME TO DIGITAL CAFE       ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------";

  cout << RED << BOLD << "\n\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()           STUDENT LOGIN MENU            ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------\n";
}

void intro()
{
  clrscr();

  const char message[] = "WELCOME TO DIGITAL CAFE";
  const char message0[] = "  _________________________________________";
  const char message1[] = " \\_________________________________________/";
  const char message2[] = "      _________________________________";
  const char message3[] = "-------------------------";

  cout << RED << BOLD << "\t\t\t";

  for (int i = 0; message0[i] != '\0'; ++i)
  {
    cout << message0[i] << flush;
   // usleep(20000);
  }

  cout << "\n\t\t\t /                                         \\\n\t\t\t";

  cout << RESET << BOLD << GREEN << "()          ";

  for (int i = 0; message[i] != '\0'; ++i)
  {
    cout << message[i] << flush;
   // usleep(50000);
  }

  cout << "        ()\n\t\t\t" << RESET << RED << BOLD;

  for (int i = 0; message1[i] != '\0'; ++i)
  {
    cout << message1[i] << flush;
    //usleep(20000);
  }

  cout << "\n\t\t\t" << RESET << BOLD << GREEN;

  for (int i = 0; message2[i] != '\0'; ++i)
  {
    cout << message2[i] << flush;
    //usleep(20000);
  }

  cout << "\n\t\t\t          " << RESET << BOLD << RED;

  for (int i = 0; message3[i] != '\0'; ++i)
  {
    cout << message3[i] << flush;
    //usleep(20000);
  }

  //usleep(100000);

  cout << RED << BOLD << "\n\t\t\t  _________________________________________\n\t\t\t /                                         \\\n\t\t\t" << RESET << BOLD << GREEN << "()                HOME MENU                ()\n\t\t\t" << RESET << RED << BOLD << " \\_________________________________________/\n\t\t\t" << RESET << BOLD << GREEN << "      _________________________________\n\t\t\t          " << RESET << BOLD << RED << "-------------------------\n";
}

void add_crd()
{
  int choice, flag = 0, a = 1;
  char x;
  char id[16], pass[16], ID[16];

  do
  {

    a = 1;

    cout << "\n\n\t\t\tWhose credentials do you want to add?";
    cout << "\n\n\t\t\t1. Employee\n\n\t\t\t2. Student\n";

    cin >> choice;

    if (choice == 1)
    {

      do
      {

        a = 1; // serial no
        flag = 0;

        fstream f;
        f.open("emp_credentials.txt", ios::in);

        cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

        cout << endl
             << "\t\t--|----------------|-----------\n";

        while (f.getline(id, 16, ' '), f.getline(pass, 16, '\n'))
        {

          cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

          cout << "\t\t--|----------------|----------\n";

          a++;
        }

        f.clear();
        f.seekg(0, ios::beg);

        f.close();

        fstream wr;

        wr.open("emp_credentials.txt", ios::in);

        cout << "\n\t\t\tEnter new ID: ";
        cin >> id;

        wr.clear();
        wr.seekg(0, ios::beg);

        while (wr.getline(ID, 16, ' '), wr.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            flag = 1;
            break;
          }
        }

        wr.clear();

        if (flag == 1)
        {
          cout << "\n\n\t\t\tAn ID with such name already exists, please enter a unique ID.\n\n\n";
        }
        else
        {

          cout << "\n\t\t\tEnter password : ";
          cin >> pass;

          wr.close();

          wr.open("emp_credentials.txt", ios::out | ios::app);
          wr << id << " " << pass << "\n";
          break;
        }

      } while (1);

      break;
    }

    else if (choice == 2)
    {

      do
      {

        fstream f;
        f.open("user_credentials.txt", ios::in);

        cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

        cout << endl
             << "\t\t--|----------------|-----------\n";

        while (f.getline(id, 16, ' '), f.getline(pass, 16, '\n'))
        {

          cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

          cout << "\t\t--|----------------|----------\n";

          a++;
        }

        f.clear();
        f.seekg(0, ios::beg);

        f.close();

        fstream w;

        w.open("user_credentials.txt", ios::in);

        cout << "\n\t\t\tEnter new ID: ";
        cin >> id;

        w.clear();
        w.seekg(0, ios::beg);

        while (w.getline(ID, 16, ' '), w.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            flag = 1;
          }
        }

        w.clear();

        if (flag == 1)
        {
          cout << BOLD << RED << "\n\n\t\t\tAn ID with such name already exists, please enter a unique ID.\n\n\n"
               << RESET;
        }
        else
        {

          cout << "\n\t\t\tEnter password : ";
          cin >> pass;

          w.close();

          w.open("user_credentials.txt", ios::out | ios::app);
          w << id << " " << pass << "\n";
          w.close();

          break;
        }

      } while (1);

      break;
    }

    else
      cin.clear();
    cin.ignore();
    cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
         << RESET;

  } while (1);

  cout << BOLD << GREEN << "\n\n\t\t\tNew account added. Press any key to return." << RESET;
  cin >> x;
}

void rem_crd() // employee and student k credentials remove krne k liye
{
  int a, choice, q, flag = 0;
  char x;
  char id[16], pass[16], mov1[16], mov2[16], ID[16];

  do
  {

    flag = 0;

    a = 1;

    cout << "\n\n\t\t\tWhose credentials/ID do you want to remove?";
    cout << "\n\t\t\t1. Employee\n\t\t\t2. Student\n\t\t\t3. Go back\n";

    cin >> choice;

    if (choice == 1) // employe k credentials remove krne k liye
    {

      fstream fs;

      cout << "\n\n\n";

      fs.open("emp_credentials.txt", ios::in | ios::out);

      cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

      cout << endl
           << "\t\t--|----------------|-----------\n";

      while (fs.getline(id, 16, ' '), fs.getline(pass, 16, '\n'))
      {

        cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

        cout << "\t\t--|----------------|----------\n";

        a++;
      }

      fs.close();

      do
      {

        fstream d;
        d.open("emp_credentials.txt", ios::in);

        fstream f;
        f.open("temp.txt", ios::out);

        cout << "\n\n\t\t\tEnter ID you want to remove (username): ";
        cin >> ID;

        d.seekg(0, ios::beg);

        while (d.getline(id, 16, ' '), d.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            flag = 1;
            continue;
          }

          f << id << " " << pass << "\n";
        }

        d.clear();

        if (flag == 1)
        {
          break;
        }

        else
          cin.clear();
        cin.ignore();
        cout << BOLD << RED << "\n\n\t\t\tNo such ID found, check spell and enter again." << RESET;

        d.close();
        f.close();

      } while (1);

      remove("emp_credentials.txt");
      rename("temp.txt", "emp_credentials.txt");
      cout << BOLD << GREEN << "\n\n\t\t\tCredentials updated. Press any key to return." << RESET;

      cin >> x;
    }

    else if (choice == 2) // student k credentials remove krne k liye
    {
      flag = 0;

      fstream fs;

      cout << "\n\n\n";

      fs.open("user_credentials.txt", ios::in);

      cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

      cout << endl
           << "\t\t--|----------------|-----------\n";

      while (fs.getline(id, 16, ' '), fs.getline(pass, 16, '\n'))
      {

        cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

        cout << "\t\t--|----------------|----------\n";

        a++;
      }

      fs.close();

      fs.seekg(0, ios::beg);

      do
      {

        fstream d;
        d.open("user_credentials.txt", ios::in);
        fstream f;
        f.open("temp.txt", ios::out);

        d.seekg(ios::beg);

        cout << "\n\nEnter ID you want to remove: ";
        cin >> ID;

        while (d.getline(id, 16, ' '), d.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            flag = 1;
            continue;
          }

          f << id << " " << pass << "\n";
        }

        d.clear(); // error khtm krne k liye

        if (flag == 1)
        {

          break;
        }

        else
          cout << BOLD << RED << "\n\n\t\t\tNo such ID found, check spell and enter again." << RESET;

        d.close();
        f.close();

      } while (1);

      remove("user_credentials.txt");
      rename("temp.txt", "user_credentials.txt");
      cout << BOLD << GREEN << "\n\n\t\t\tCredentials updated. Press any key to return." << RESET;

      cin >> x;
    }

    else if (choice == 3)
    {
      break;
    }

    else
    {
      cin.clear();
      cin.ignore();
      cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
           << RESET;
    }

  } while (1);
}

void stock_display()
{
  int id, price, amount, choice, flag = 0;
  char items[16], x;

  fstream fs;
  fs.open("stock.txt", ios::in);

  fs.clear();

  cout << "\n\n\n";

  cout << BOLD << GREEN << "\t-------------------------------------------------------------------------\n";
  cout << "\t" << RESET << setw(3) << left << "|ID " << RESET << BOLD << GREEN
       << "|" << RESET << BOLD << YELLOW << setw(16) << "ITEMS" << RESET << BOLD << GREEN
       << "|" << RESET << BLUE << BOLD << setw(16) << "PRICE" << RESET << BOLD << GREEN
       << "|" << RESET << GREEN << BOLD << setw(16) << "QUANTITY"
       << "|" << setw(16) << "TOTAL PRICE"
       << "|\n";
  cout << RESET << BOLD << GREEN << "\t|---|----------------|----------------|----------------|----------------|\n";

  id = 1;

  while (fs.getline(items, 16, ' '), fs >> price >> amount)
  {
    fs.ignore();
    cout << "\t";
    cout << "|" << RESET << BOLD << setw(3) << left << id << RESET << BOLD << YELLOW << "|" << setw(16) << items << RESET << BOLD << BLUE << "|" << setw(16) << price;

    if (amount < 15)
      cout << RESET << BOLD << RED << "|" << setw(16) << left << amount << RESET << GREEN << BOLD << "|";
    else
      cout << RESET << GREEN << BOLD << "|" << setw(16) << amount << "|";

    cout << setw(16) << left << price * amount << "|";

    cout << endl;

    id++;

    fs.clear();
  }
  cout << "\t-------------------------------------------------------------------------\n"
       << RESET;

  fs.close();
}

void stock()
{

  do
  {

    int id, price, amount, choice, flag = 0;
    char items[16], x;

    stock_display();

    cout << "\n\n\n\t\t\t1. Add New Items\n\t\t\t2. Remove Items\n\t\t\t3. Search items\n\t\t\t4. Replenish low stock\n\t\t\t5. Go back\n\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
      add_stock();
      break;

    case 2:
      rem_stock();
      break;

    case 3:
      search_stock();
      break;

    case 4:
      add_exist_stock();
      break;

    case 5:
      flag = 1;
      break;

    default:
      cin.clear();
      cin.ignore();
      cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
           << RESET;
    }

    if (flag == 1)
      break;

  } while (1);

  cout << "\n\n\n";
}

void random_drop()
{
  int id = 0, price, amount, Amount, flag, i, val;
  char items[16], Items[16], x;

  srand(time(0));

  fstream fs;
  fs.open("stock.txt", ios::in);
  fstream f;
  f.open("temp.txt", ios::out);
  f.clear(); // to remove any error flags after opening the file
  fs.clear();

  while (fs.getline(items, 16, ' '), fs >> price >> amount) // reads content from file until none left
  {
    fs.ignore();

    val = (amount - (rand() % 15 + 1));

    if (val >= 0)
      amount = val;

    f << items << " " << price << " " << amount << "\n";
  }

  f.close();
  fs.close();

  remove("stock.txt");
  rename("temp.txt", "stock.txt");
}

void add_stock()
{

  int id = 0, price, amount, Amount, flag;
  char items[16], Items[16], x;

  do
  {

    flag = 0;

    fstream fs;
    fs.open("stock.txt", ios::in);

    fs.clear();

    fs.seekg(0, ios::beg);

    cout << "\n\t\t\tEnter name of item : ";
    cin >> Items;

    while (fs.getline(items, 16, ' '), fs >> price >> amount)
    {
      fs.ignore();

      if (strcmp(Items, items) == 0)
      {
        flag = 1;
        break;
      }
    }

    if (flag == 1)
    {
      cout << BOLD << RED << "\n\n\t\t\tThis item already exists! Enter a new item\n\n"
           << RESET;
      fs.close();
    }

    else
    {

      fstream f;

      f.clear();

      f.open("stock.txt", ios::out | ios::app);

      do
      {
        cout << "\n\t\t\tEnter price : ";
        cin >> price;

        if (price <= 0)
          cout << BOLD << RED << "\n\n\t\t\tInvald price.\n\n"
               << RESET;

      } while (price <= 0);

      do
      {

        cout << "\n\t\t\tEnter quantity : ";
        cin >> amount;

        if (amount <= 0)
        {
          cout << BOLD << RED << "\n\n\t\t\tInvalid quantity ( can't be zero or less )." << RESET;
          continue;
        }

        if (amount > 1000)
        {
          cout << BOLD << RED << "\n\n\t\t\tInvalid quantity ( can't exceed 1000 )." << RESET;
          continue;
        }

        break;

      } while (1);

      f << Items << " " << price << " " << amount << "\n";

      f.close();

      break;
    }

  } while (1);
}

void add_exist_stock()
{
  int id = 0, price, amount, Amount, flag, i;
  char items[16], Items[16], x;

  do
  {
    i = 1;
    flag = 0;

    fstream fs;
    fs.open("stock.txt", ios::in);
    fstream f;
    f.open("temp.txt", ios::out);
    f.clear(); // to remove any error flags after opening the file
    fs.clear();

    fs.seekg(0, ios::beg);

    cout << "\n\t\t\tEnter ID of item( eg 4 ) : ";
    cin >> id;

    while (fs.getline(items, 16, ' '), fs >> price >> amount) // reads content from file until none left
    {
      fs.ignore();

      if (i == id) // ager user ki input id valid ho
      {
        flag = 1;

        do
        {

          cout << "\n\n\t\t\tEnter number of quantity you want to add to " << items << " : ";
          cin >> Amount;

          if (Amount <= 0) // amount 0 ya 0 se kam ni hoskti
          {
            cout << BOLD << RED << "\n\n\t\t\tInvald Quantity! (cannot be zero or less )\n\n"
                 << RESET;
            continue;
          }

          Amount += amount;

          if (Amount > 1000) // amount cannot exceed 1000 as well
          {
            cout << BOLD << RED << "\n\n\t\t\tInvalid quantity. ( Quantity cannot exceed 1000)" << RESET;
            continue;
          }

          break;

        } while (1);

        f << items << " " << price << " " << Amount << "\n";
      }

      else
      {
        f << items << " " << price << " " << amount << "\n";
      }

      i++;
    }

    if (flag != 1) // in case id entered does not exist in file
    {
      cout << BOLD << RED << "\n\n\t\t\tNo such ID found! Please enter again." << RESET;
      fs.close();
      f.close();
      continue;
    }

    fs.close();
    f.close();

    remove("stock.txt");
    rename("temp.txt", "stock.txt");

    cout << BOLD << GREEN << "\n\n\t\t\tStock quantity updated successfully." << RESET;
    break;

  } while (1);
}

void rem_stock()
{
  int id = 1, price, amount, check = 1, flag;
  char items[16], x;

  fstream fs;
  fstream f;

  do
  {

    f.open("temp.txt", ios::out);
    fs.open("stock.txt", ios::in);

    flag = 0;
    check = 1;
    id = 1;

    cout << "\n\n\t\t\tEnter ID of item you want to remove ( eg: 5 ): ";
    cin >> id;

    fs.clear();

    while (fs.getline(items, 16, ' '), fs >> price >> amount)
    {
      if (id == check)
      {
        fs.ignore();
        flag = 1;
        check++;
        continue;
      }

      fs.ignore();

      f << items << " " << price << " " << amount << "\n";

      fs.clear();

      check++;
    }

    if (flag == 0)
    {
      cout << BOLD << RED << "\n\n\t\t\tInvalid ID. ID entered does not exist, check again." << RESET;
      fs.close();
      f.close();
    }
    else
    {

      fs.close();
      f.close();
      break;
    }

  } while (1);

  remove("stock.txt");
  rename("temp.txt", "stock.txt");

  cout << BOLD << GREEN << "\n\n\t\t\tItem deleted successfully." << RESET;
}

void search_stock()
{
  char name[16], items[16], x;
  int price, amount, flag = 0, id = 1;

  do
  {
    id = 1;

    cout << "\n\n\t\t\tEnter the name item you are looking for : ";
    cin >> name;

    fstream fs;

    fs.open("stock.txt", ios::in);

    fs.clear();

    while (fs.getline(items, 16, ' '), fs >> price >> amount)
    {
      fs.ignore();

      if (strcmp(name, items) == 0)
      {
        flag = 1;
        break;
      }

      id++;
    }

    if (flag != 1)
    {
      cout << BOLD << RED << "\n\n\t\t\tNO such item found! Enter again.\n\n"
           << RESET;
    }
    else
    {
      fs.close();
      break;
    }

  } while (1);

  cout << BOLD << GREEN << "\t--------------------------------------------------------\n";
  cout << "\t" << setw(3) << left << "|ID "
       << "|" << setw(16) << "ITEMS"
       << "|" << setw(16) << "PRICE"
       << "|" << setw(16) << "QUANTITY        |\n";
  cout << "\t|---|----------------|----------------|----------------|\n";

  cout << RESET << "\t";
  cout << "|" << setw(3) << left << id << "|" << setw(16) << items << "|" << setw(16) << price << "|" << setw(16) << amount << "|";
  cout << "\n\t--------------------------------------------------------\n";

  cout << "\n\n\t\t\tPress any key to return.";

  cin >> x;
}

void complaints()
{
  char cmp[1000], l;
  int x, y;
  x = 1;

  do
  {

    cout << BOLD << GREEN << "\n\n\t\t\tComplaints from Students\n\n"
         << RESET;

    fstream f;
    fstream fs;
    f.open("complaints.txt", ios::in);
    fs.open("temp.txt", ios::out);

    while (f.getline(cmp, 300, '\n'))
    {
      cout << x << ") " << cmp << "\n\n\n";
      x++;
    }

    cout << "\n\n\t\t\tEnter any number ( non-zero ) to mark all complains as read, or press 0 to go back.";
    cin >> y;

    if (y)
    {
      remove("complaints.txt");
      rename("temp.txt", "complaints.txt");
      f.close();
      fs.close();

      cout << "\n\n\t\t\tAll complaints marked as read and cleared.";
      cout << "\n\n\t\t\tPress any key to return.";
      cin >> l;
      break;
    }

    else
      break;

  } while (y != 0);
}

void user_complaints(const char *arr2) // to pass ID of the user as well with the complain
{
  char cmp[500], id[16], cmp1[500];

  ifstream rp;

  cmp_read();

  cmp_ans();

  cout << "\n\n\t\t\tEnter your complain/issue below and Admin will try to respond as soon as possible.\n\n";

  cin.ignore();
  cin.getline(cmp, 500);

  fstream x;

  x.open("complaints.txt", ios::out | ios::app);

  x << arr2 << "\n"
    << cmp << "\n";

  rp.close();

  cout << BOLD << GREEN << "\n\n\t\t\tComplain successfully submitted. Press any key to return." << RESET;
  cin >> cmp;

  cout << "\n\n\n\n";
}

void cmp_read()
{
  char id[16], cmp[500];
  int flag = 0;

  ifstream fs;

  fs.open("complaints.txt", ios::in);
  fs.clear();

  while (fs.getline(id, 16, '\n'), fs.getline(cmp, 500, '\n'))
  {
    cout << BOLD << GREEN << id << ": " << RESET << cmp << endl
         << endl;
    flag = 1;
  }

  if (flag == 0)
    cout << BOLD << GREEN << "\n\n\t\t\tNo student Complaints.\n\n\n"
         << RESET;

  fs.close();
}

void cmp_ans()
{
  char cmp[500];
  int x;

  ifstream fs;
  fs.open("reply.txt", ios::in);
  fs.clear();

  while (fs.getline(cmp, 500, '\n'))
  {
    cout << BOLD << BLUE << "\t\t\tAdmin: " << RESET << cmp << endl
         << endl;
  }

  fs.close();
}

int orders()
{
  int id, i, flag, price, amount, Amount, choice, sum, ID;
  char items[16];

  stock_display();

  sum = 0;

  fstream t;
  fstream fs;
  fstream f;
  fs.open("stock.txt", ios::in);

  do
  {

    i = 1;
    ID = 1;
    id = 1;
    flag = 0;
    fs.clear();
    fs.seekg(0, ios::beg);

    do
    {

      cout << "\n\n\t\t\tEnter ID of item you want to buy: ";
      cin >> id;

      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
        cout << RED << BOLD << "\n\n\t\t\tInvalid Input." << RESET;
        continue;
      }

      break;

    } while (1);

    while (fs.getline(items, 16, ' '), fs >> price >> amount) // reads content from file until none left
    {
      fs.ignore();

      if (id == i)
      {
        flag = 1;
        break;
      }

      i++;
    }

    if (flag == 1) // if input id is valid
    {
      f.open("orders.txt", ios::out | ios::app);
      f.clear();

      do
      {

        cout << "\n\n\t\t\tEnter quantity of " << items << " : ";
        cin >> Amount;

        if (Amount <= 0)
        {
          cout << BOLD << RED << "\n\n\t\t\tQuantity cannot be zero or less.\n\n"
               << RESET;
          continue;
        }

        if (Amount > amount)
        {
          cout << BOLD << RED << "\n\n\t\t\tQuantity cannot exceed availabale items.\n\n"
               << RESET;
          continue;
        }

        break;

      } while (1);

      f << items << " " << id << " " << price << " " << Amount << "\n";
      f.close();
      sum = sum + (Amount * price);
      cout << "\n\n\t\t\tYour total Bill for selected items is " << BOLD << GREEN << sum << RESET;
      cout << "\n\n\t\t\tContinue buying or proceed to transaction? ( 1 for yes and 0 for no )\n\n"
           << BOLD << GREEN << "\t\t\tPress 2 to cancel order or any other number to exit." << RESET;
      cin >> choice;

      if (choice == 1)
      {
        continue;
      }

      else if (choice == 0)
      {
        fs.close();

        cout << "\n\n\n";
        cout << WHITE_BACKGROUND << BLACK << BOLD << "\tDIGITAL CAFE RECEIPT" << RESET << RESET_BACKGROUND;
        cout << "\n\n";
        cout << BOLD << GREEN << "\t----------------------------------------------------\n\t";
        cout << "|" << setw(16) << "ITEMS"
             << "|" << setw(16) << "PRICE"
             << "|" << setw(16) << "QUANTITY        |\n";
        cout << "\t|----------------|----------------|----------------|\n";

        cout << RESET;

        f.open("orders.txt", ios::in);
        f.clear();
        f.seekg(0, ios::beg);

        while (f.getline(items, 16, ' '), f >> ID >> price >> Amount) // order file say input leta hai
        {

          f.ignore();
          i = 1;
          fs.open("stock.txt", ios::in);
          t.open("temp.txt", ios::out | ios::app);

          t.clear();
          fs.clear();

          cout << "\t|" << setw(16) << items << "|" << setw(16) << price << "|" << setw(16) << Amount << "|\n"; // ordered items ko display kkrta hai

          while (fs.getline(items, 16, ' '), fs >> price >> amount) // reads content from file until none left
          {
            fs.ignore();

            if (ID == i)
              t << items << " " << price << " " << amount - Amount << "\n"; // jo quantity nikli hai usay update krta hai

            else
              t << items << " " << price << " " << amount << "\n"; // usual copy paste to temporary file

            i++;
          }

          fs.close();
          t.close();

          remove("stock.txt");
          rename("temp.txt", "stock.txt");
        }

        f.close();

        cout << "\t----------------------------------------------------\n";

        cout << BOLD << GREEN << "\n\n\t\t\tGrand total: " << RESET << sum;
        cout << BOLD << BLUE << "\n\n\t\t\tThank you for buying from Cafe Digital!\n\n"
             << RESET;

        t.open("temp.txt", ios::out);
        remove("orders.txt");
        rename("temp.txt", "orders.txt");

        break;
      }

      else if (choice == 2) // cancel order , removes all content from order file
      {
        t.open("temp.txt", ios::out);
        remove("orders.txt");
        rename("temp.txt", "orders.txt");
        sum = 0;
        break;
      }

      else // if no option is selected , exit krta hai order menu say
      {
        sum - 0;
        break;
      }
    }

    else // incorrect input check
    {
      cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
           << RESET;
      continue;
    }

  } while (1);

  return sum;
}

void emp_sales(const char *arr2, int total) // gets called when some emp is login and sells an item
{
  char ID[16];
  int price, flag = 0;

  fstream fs;
  fstream f;
  fs.open("best_emp.txt", ios::in);
  f.open("temp.txt", ios::out | ios::app);

  while (fs.getline(ID, 16, ' '), fs >> price) // takes input from best employee file
  {
    fs.ignore();
    if (strcmp(ID, arr2) == 0) // if some emp aready exisy in best emp, updates it's stat
    {
      f << arr2 << " " << total + price << "\n";
      flag = 1;
    }
    else // else just usual copy from best emp file to temp file
      f << ID << " " << price << "\n";
  }

  if (flag == 0) // if a new emp has taken order, appends it's stat at the end of file
    f << arr2 << " " << total << "\n";

  fs.close();
  f.close();

  remove("best_emp.txt");
  rename("temp.txt", "best_emp.txt");
}

void sch_order(const char *arr2)
{

  int id, i, flag, price, amount, Amount, choice, sum, ID;
  char items[16], name[16];

  stock_display();

  sum = 0;

  fstream t;  // temp file
  fstream fs; // stock file
  fstream f;  // sch order file
  fstream ff; // admin sch file
  fs.open("stock.txt", ios::in);
  ff.open("sch_admin.txt", ios::out | ios::app);

  do
  {

    i = 1;
    ID = 1;
    id = 1;
    flag = 0;
    fs.clear();
    fs.seekg(0, ios::beg);
    cout << "\n\n\t\t\tEnter ID of item you want to buy: ";
    cin >> id;

    while (fs.getline(items, 16, ' '), fs >> price >> amount) // reads content from file until none left
    {
      fs.ignore();

      if (id == i)
      {
        flag = 1;
        break;
      }

      i++;
    }

    if (flag == 1) // if input id is valid
    {
      f.open("sch_orders.txt", ios::out | ios::app);
      f.clear();

      do
      {

        cout << "\n\n\t\t\tEnter quantity of " << items << " : ";
        cin >> Amount;

        if (Amount <= 0)
        {
          cout << BOLD << RED << "\n\n\t\t\tQuantity cannot be zero or less.\n\n"
               << RESET;
          continue;
        }

        if (Amount > amount)
        {
          cout << BOLD << RED << "\n\n\t\t\tQuantity cannot exceed availabale items.\n\n"
               << RESET;
          continue;
        }

        break;

      } while (1);

      f << arr2 << " " << items << " " << id << " " << price << " " << Amount << "\n"; // takes all orders in

      f.close();

      sum = sum + (Amount * price);
      cout << "\n\n\t\t\tYour total Bill for selected items is " << BOLD << GREEN << sum << RESET;
      cout << "\n\n\t\t\tContinue buying or proceed to placing order? ( 1 for yes and 0 for no )\n\n"
           << BOLD << GREEN << "Press 2 to cancel order or any other number to exit." << RESET;
      cin >> choice;

      if (choice == 1)
      {
        continue;
      }

      else if (choice == 0)
      {
        fs.close();
        admin_order_notification(2);

        cout << "\n\n\n";
        cout << WHITE_BACKGROUND << BLACK << BOLD << "\tDIGITAL CAFE RECEIPT" << RESET << RESET_BACKGROUND;
        cout << "\n\n";
        cout << BOLD << GREEN << "\t----------------------------------------------------\n\t";
        cout << "|" << setw(16) << "ITEMS"
             << "|" << setw(16) << "PRICE"
             << "|" << setw(16) << "QUANTITY        |\n";
        cout << "\t|----------------|----------------|----------------|\n";

        cout << RESET;

        f.open("sch_orders.txt", ios::in);
        f.clear();
        f.seekg(0, ios::beg);

        while (f.getline(name, 16, ' '), f.getline(items, 16, ' '), f >> ID >> price >> Amount) // order file say input leta hai
        {

          ff << arr2 << " " << items << " " << ID << " " << price << " " << Amount << "\n"; // takes all orders in
          f.ignore();
          i = 1;

          t.clear();
          fs.clear();

          cout << "\t|" << setw(16) << items << "|" << setw(16) << price << "|" << setw(16) << Amount << "|\n"; // ordered items ko display kkrta hai
        }

        cout << BOLD << GREEN << "\n\n\t\t\tYour order request has been sent. Plase wait for approval. ( You will be notified in the notifications options in menu ).\n\n\n\n\n"
             << RESET;
        t.close();
        f.close();
        remove("sch_orders.txt");
        rename("temp.txt", "orders.txt");
        break;
      }

      else if (choice == 2) // cancel order , removes all content from order file
      {
        t.open("temp.txt", ios::out);
        remove("sch_orders.txt");
        rename("temp.txt", "orders.txt");

        sum = 0; // to set revenue 0
        break;
      }

      else // if no option is selected , exit krta hai order menu say
      {
        sum - 0;
        break;
      }
    }

    else // incorrect input check
    {
      cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
           << RESET;
      continue;
    }

  } while (1);

  ff.close();
}

void approval_order()
{
  char name[16], Name[16], items[16], username[16], choice;
  int id, price, amount, i = 1, y = 1, z = 1, flag = 0, g;

  fstream fs;
  fs.open("sch_admin.txt", ios::in);
  fs.clear();

  cout << "\n\n\n";
  cout << WHITE_BACKGROUND << BLACK << BOLD << "\t\tONLINE ORDER REQUESTS" << RESET << RESET_BACKGROUND;
  cout << "\n\n";
  cout << BOLD << GREEN << "                ----------------------------------------------------\n";
  cout << "                |" << setw(16) << left << "ITEMS"
       << "|" << setw(16) << left << "PRICE"
       << "|" << setw(16) << left << "QUANTITY        |\n";
  cout << "                |----------------|----------------|----------------|\n";

  cout << RESET;

  while (fs.getline(name, 16, ' '), fs.getline(items, 16, ' '), fs >> id >> price >> amount)
  {

    flag = 1;

    if (i == 1)
      strcpy(Name, name);

    if (strcmp(Name, name) == 0)
    {

      cout << GREEN << BOLD << name << "\'s order:" << RESET << "\t|" << setw(16) << left << items << "|" << setw(16) << price << "|" << setw(16) << amount << "|"; // ordered items ko display kkrta hai;
    }

    else
    {
      cout << "\n                |----------------|----------------|----------------|";

      cout << GREEN << BOLD << name << "\'s order" << RESET << "\t|" << setw(16) << left << items << "|" << setw(16) << price << "|" << setw(16) << amount << "|"; // ordered items ko display kkrta haiendl;
    }

    i++;
  }

  fs.close();
  cin.ignore();

  if (flag == 1)
  {

    do
    {

      flag = 0;

      fs.open("sch_admin.txt", ios::in);
      fs.clear();
      fstream f;
      f.open("temp.txt", ios::out | ios::app);
      f.clear();

      cout << "\n\n\t\t\tPress any key to proceed ( or press samll e to exit ): ";
      cin.getline(username, 16);

      if (strcmp(username, "e") == 0)
      {
        break;
      }

      cout << "\n\n\t\t\tPress a to approve all or press any other key to reject all.";
      cin >> choice;

      if (choice == 'a' or choice == 'A')
      {
        cout << "\n\n\t\t\tAll orders have been approved.";
        admin_order_notification(1);
      }

      else

      {
        admin_order_notification(0);
        cout << "\n\n\t\t\tAll orders have been rejected.";
      }

      f.close();
      fs.close();
      remove("sch_admin.txt");
      rename("temp.txt", "sch_admin.txt");

      break;

    } while (1);
  }

  else
    cout << BOLD << GREEN << "\n\n\t\t\tNo Online Orders.\n\n\n"
         << RESET;
}

void admin_order_notification(int notification)
{

  fstream fs;
  fs.open("user_notification.txt", ios::out);

  if (notification == 1)
  {
    fs << notification;
  }

  else if (notification == 0)
  {
    fs << notification;
  }

  else if (notification == 2)
  {

    fs << 2;
  }

  else
    fs << 3;

  fs.close();
}

int user_order_notification()
{
  int x;

  fstream fs;
  fs.open("user_notification.txt", ios::in);

  fs >> x;

  if (x == 1)
  {

    fs.close();
    return x;
  }

  else if (x == 0)
  {

    fs.close();
    return x;
  }

  else
  {

    fs.close();
    return x;
  }
}

void low_stock_notification()
{
  fstream fs;
  fs.open("stock.txt", ios::in);

  char items[16];
  int price, amount, flag;

  flag = 0;

  while (fs.getline(items, 16, ' '), fs >> price >> amount)
  {
    fs.ignore();

    if (amount < 15)
    {
      cout << BOLD << RED << "\n\n\t\t\t- " << items << " is less in quantity! Consider ordering more " << items << RESET << "\n\n";
      flag = 1;
    }
  }

  if (flag == 0)
    cout << BOLD << GREEN << "\n\n\t\t\t"
         << "- All items are above the threshold value.\n\n"
         << RESET;

  cout << "\n\n";

  fs.close();
}

void best_employee()
{
  cout << "\n\n\t\t\tEmployee in" << BOLD << GREEN << " GREEN " << RESET << "is the" << BOLD << GREEN << " TOP SELLER\n\n." << RESET;

  char name[16];
  int rev[20]; // reveneue
  int i = 0, a;
  int max, sum = 0;

  fstream fs;
  fs.open("best_emp.txt", ios::in);

  cout << BOLD << "\n\t-----------------------------------" << RESET;
  cout << BOLD << "\n\t|" << setw(16) << left << "EMPLOYEE"
       << "|" << setw(16) << "TOTAL REVENUE"
       << "|\n\t" << RESET;
  cout << BOLD << "-----------------------------------" << RESET;

  cout << endl;

  while (fs.getline(name, 16, ' '), fs >> rev[i])
  {
    fs.ignore();
    sum = sum + rev[i];
    i++;
  }

  max = rev[0];

  for (a = 0; a <= i - 1; a++)
  {
    if (max < rev[a])
    {

      max = rev[a];
    }
  }

  for (a = 0; a <= i - 1; a++)
  {
    if (max == rev[a])
    {

      max = a;
      break;
    }
  }

  fs.close();
  fs.open("best_emp.txt", ios::in);
  i = 0;

  while (fs.getline(name, 16, ' '), fs >> rev[i])
  {
    fs.ignore();

    if (i == (a))
      cout << BOLD << GREEN << "\t|" << setw(16) << left << name << "|" << setw(16) << rev[i] << "|\n"
           << RESET;

    else
      cout << "\t|" << setw(16) << left << name << "|" << setw(16) << rev[i] << "|\n";

    i++;
  }

  cout << "\t-----------------------------------\n\t";

  fs.close();

  cout << BOLD << GREEN << "\n\t\t\tGRAND TOTAL REVENUE: " << RESET << sum << "\n\n";
}

void update_crd() // employee and student k credentials update krne k liye
{
  int a, choice, q, flag = 0;
  char x;
  char id[16], pass[16], mov1[16], mov2[16], ID[16];

  do
  {

    flag = 0;

    a = 1;

    cout << "\n\n\t\t\tWhose credentials/ID do you want to update?";
    cout << "\n\t\t\t1. Employee\n\t\t\t2. Student\n\t\t\t3. Admin\n\t\t\t4. Go back\n";

    cin >> choice;

    if (choice == 1) // employe k credentials remove krne k liye
    {

      fstream fs;

      cout << "\n\n\n";

      fs.open("emp_credentials.txt", ios::in | ios::out);

      cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

      cout << endl
           << "\t\t--|----------------|-----------\n";

      while (fs.getline(id, 16, ' '), fs.getline(pass, 16, '\n'))
      {

        cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

        cout << "\t\t--|----------------|----------\n";

        a++;
      }

      fs.close();

      do
      {
        flag = 0;
        fstream d;
        d.open("emp_credentials.txt", ios::in);

        fstream f;
        f.open("temp.txt", ios::out);

        cout << "\n\n\t\t\tEnter ID you want to update (username): ";
        cin >> ID;

        d.seekg(0, ios::beg);

        while (d.getline(id, 16, ' '), d.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            cin.ignore();
            cout << "\n\n\t\t\tEnter new ID for \"" << id << "\": ";
            cin.getline(id, 16);
            cout << "\n\n\t\t\tEnter new password for \"" << id << "\": ";
            cin.getline(pass, 16);
            f << id << " " << pass << "\n";
            flag = 1;
            continue;
          }

          f << id << " " << pass << "\n";
        }

        d.clear();

        if (flag == 1)
        {
          break;
        }

        else
          cout << BOLD << RED << "\n\n\t\t\tNo such ID found, check spell and enter again." << RESET;

        d.close();
        f.close();

      } while (1);

      remove("emp_credentials.txt");
      rename("temp.txt", "emp_credentials.txt");
      cout << BOLD << GREEN << "\n\n\t\t\tCredentials updated. Press any key to return." << RESET;

      cin >> x;
    }

    else if (choice == 2) // student k credentials remove krne k liye
    {
      flag = 0;

      fstream fs;

      cout << "\n\n\n";

      fs.open("user_credentials.txt", ios::in);

      cout << "\t\t  |" << setw(16) << left << "IDs" << setw(16) << "|Passwords";

      cout << endl
           << "\t\t--|----------------|-----------\n";

      while (fs.getline(id, 16, ' '), fs.getline(pass, 16, '\n'))
      {

        cout << "\t\t" << a << " |" << setw(16) << left << id << "|" << pass << "\n";

        cout << "\t\t--|----------------|----------\n";

        a++;
      }

      fs.close();

      fs.seekg(0, ios::beg);

      do
      {
        flag = 0;
        fstream d;
        d.open("user_credentials.txt", ios::in);
        fstream f;
        f.open("temp.txt", ios::out);

        d.seekg(ios::beg);

        cout << "\n\nEnter ID you want to update (username): ";
        cin >> ID;

        while (d.getline(id, 16, ' '), d.getline(pass, 16, '\n'))
        {
          if (strcmp(id, ID) == 0)
          {
            cin.ignore();
            cout << "\n\n\t\t\tEnter new ID for \"" << id << "\": ";
            cin.getline(id, 16);
            cout << "\n\n\t\t\tEnter new password for \"" << id << "\": ";
            cin.getline(pass, 16);
            f << id << " " << pass << "\n";
            flag = 1;
            continue;
          }

          f << id << " " << pass << "\n";
        }

        d.clear(); // error khtm krne k liye

        if (flag == 1)
        {

          break;
        }

        else
          cout << BOLD << RED << "\n\n\t\t\tNo such ID found, check spell and enter again." << RESET;

        d.close();
        f.close();

      } while (1);

      remove("user_credentials.txt");
      rename("temp.txt", "user_credentials.txt");
      cout << BOLD << GREEN << "\n\n\t\t\tCredentials updated. Press any key to return." << RESET;

      cin >> x;
    }

    else if (choice == 3)
    {
      fstream f;
      fstream t;
      f.open("admin_crd.txt", ios::in);
      t.open("temp.txt", ios::out);
      cin.ignore();
      cout << "\n\n\t\t\tEnter new username for Admin : ";
      cin.getline(id, 16);
      cout << "\n\n\t\t\tEnter new password for Admin : ";
      cin.getline(pass, 16);

      t << id << " " << pass << "\n";
      f.close();
      t.close();
      remove("admin_crd.txt");
      rename("temp.txt", "admin_crd.txt");

      cout << BOLD << GREEN << "\n\n\t\t\tCredentials updated. Press any key to return." << RESET;
    }

    else if (choice == 4)
    {
      break;
    }

    else
    {
      cout << BOLD << RED << "\n\n\t\t\tInvald input.\n\n"
           << RESET;
    }

  } while (1);
}
