#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
using namespace std;


// set colors for console
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Display tasks 
void display_tasks(const vector<string>& tasks, const vector<bool>& completed){
    setColor(10); //green

    cout<<"--Task List--"<<endl;

    if(tasks.empty()){
        cout<<"No Tasks available!"<<endl;
    }
    else{
        for(size_t i = 0; i< tasks.size(); i++){
            cout<< i+1<< ". "<< tasks[i]<<" ["<<(completed[i] ? "Completed" : "Pending")
            << "]"<<endl;
        }
    }
    setColor(7);
}


int main(){

    vector<string> tasks;
    vector<bool> completed;

    int option;

    do{
        setColor(11);
        cout<<"--TO-DO LIST--"<<endl;
        cout<<"1. Add Tasks"<<endl;
        cout<<"2. View Tasks"<<endl;
        cout<<"3. Mark Task As Completed"<<endl;
        cout<<"4. Remove Task"<<endl;
        cout<<"0. Exit Program"<<endl;
        setColor(7);
        cout<<"Enter Your Choice: ";
        cin>>option;

        switch(option)
        {
            case 1:
                {
                    // add task 
                    setColor(9);
                    cin.ignore();
                    string task;
                    cout << "Enter New Task: ";
                    getline(cin, task);

                    tasks.push_back(task);
                    completed.push_back(false);

                    display_tasks(tasks, completed);
                    break;
                }
            case 2:
                {
                    // view
                    setColor(10);
                    display_tasks(tasks, completed);
                    break;
                }
            case 3:
                {
                    // complete or not 
                    setColor(14);
                    display_tasks(tasks, completed);

                    int t;
                    cout<<"Enter Task Number To Mark As Completed: ";
                    cin>>t;

                    if(t < 1 || t > tasks.size()){
                        cout<< "Invalid Task Number!"<<endl;
                    }
                    else{
                        completed[t - 1] = true;
                        cout<<"Task Marked As Completed."<<endl;
                    }

                    break;
                    
                }
                case 4:
                    // remove tasks
                    {
                        setColor(12);
                        display_tasks(tasks, completed);

                        int task;
                        cout<<"Enter task number to remove: ";
                        cin>>task;

                        if(task < 1 || task > tasks.size()){
                            cout<<"Invalid Task Number!"<<endl;
                        }
                        else{
                            tasks.erase(tasks.begin() + task - 1);
                            completed.erase(completed.begin() + task - 1);
                            cout<<"Task Remove Successfully."<<endl;
                        }

                        break;
                    }
                case 0:
                    {
                        setColor(7);
                        cout<<"Exiting Program..."<<endl;
                        break;
                    }
                default:
                    {
                        cout<<"Invalid Entry! Try Again."<<endl;
                    }
        }
        
    }
    while(option != 0);
    return 0;
}