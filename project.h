#ifndef project_H
#define project_H

void clrscr();
void admin_login();
void employee_login();
void student_login();
void intro();
void intro_home();
void intro_admin();
void intro_employee();
void intro_student();
void add_crd();
void rem_crd();
void stock();
void add_stock();
void rem_stock();
void search_stock();
void complaints();
void add_exist_stock();
void random_drop();
void stock_display();
void user_complaints(const char arr2[]);
void cmp_read();
void cmp_ans();
int  orders();
void emp_sales(const char arr2[] , int total);
void sch_order(const char arr2[]);
void approval_order();
void admin_order_notification(int x=3);
int  user_order_notification();
void low_stock_notification();
void best_employee();
void update_crd();


#endif

