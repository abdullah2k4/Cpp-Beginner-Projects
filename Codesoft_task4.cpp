#include <iostream>
#include <vector>
#include <string>
using namespace std;
class ToDolist
{
private:
    vector<string> task;
    int task_no;

public:
    ToDolist() { task_no = 0; }
    void initList();
    void setTask();
    void mark();
    void displayTasks();
    void deleteTask();
};
void ToDolist ::setTask()
{
    string task;
    cout << "Enter your task" << endl;
    cin.sync();
    getline(cin, task);
    task = task + "\033[1;31;40m Pending\033[0m";
    this->task.push_back(task);
    task_no++;
    system("cls");
}
void ToDolist::initList()
{
    int counter = 0;
    char option = ' ';
    while (option != 'e')
    {

        string task;
        cout << "Enter task number " << task_no + 1 << " : " << endl;
        cin.sync();
        getline(cin, task);
        task = task + "\033[1;31;40m Pending\033[0m";
        this->task.push_back(task);
        ++task_no;
        cout << "Press [E] to exit" << endl;
        cout << "Press any key to continue adding Tasks" << endl;
        cin >> option;
        system("cls");
    }
}
void ToDolist::mark()
{
    int number;

    cout << "Enter the number of task you wanna mark as completed : ";
    cin >> number;
    task[number - 1].erase(task[number - 1].end() - 11, task[number - 1].end());
    task[number - 1] = task[number - 1] + "\e[0;32m Completed\033[0m ";
}
void ToDolist ::deleteTask()
{
    int number;
    cout << "Enter the number of task you wanna delete : ";
    cin >> number;
    task.erase(task.begin() + (number - 1));
    --task_no;
}
void ToDolist::displayTasks()
{
    system("cls");
    for (int i = 0; i < task_no; i++)
    {
        cout << i + 1 << " : " << task[i] << endl;
    }
}
bool start()
{
    char option;
    cout << "*******************" << endl
         << "    TO DO LIST" << endl
         << "*******************" << endl
         << "Enter 'S' to START" << endl
         << "Enter any key to exit" << endl;
    cin >> option;
    system("cls");
    if (option == 's' || option == 'S')
        return 1;
    else
        return 0;
}
void choice(ToDolist &a)
{
    string p = "Press";
    char option;
    cout << p << " [a] Add Task to the list" << endl;
    cout << p << " [r] Remove Task from the list as completed " << endl;
    cout << p << " [m] Mark Task on the list" << endl;
    cout << p << " [d] Display the list" << endl;
    cin >> option;
    switch (option)
    {
    case 'a':
    {
        a.setTask();
        break;
    }
    case 'r':
    {
        a.deleteTask();
        break;
    }
    case 'm':
    {
        a.mark();
        break;
    }
    case 'd':
    {
        a.displayTasks();
        break;
    }
    break;

    default:
        cout << "wrong input " << endl;
        break;
    }
}
int main()
{
    ToDolist a;
    string task;
    if (start())
    {
        a.initList();
        do
        {
            choice(a);
        } while (true);
        return 0;
    }
}