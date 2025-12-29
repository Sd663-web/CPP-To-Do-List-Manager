#include<iostream>
#include<windows.h>
using namespace std;

void display_tasks(string task[], bool complete[], int task_counter){

    cout<<"Tasks To Do: "<<endl;
    cout<<"----------------------------------------"<<endl;
    if(task_counter == 0){
        cout<< "No tasks available."<<endl;
    }
    else{
        for(int i = 0; i<task_counter; i++){
            cout<< "Task " << i+1<<" : "<<task[i]
            <<" ["
            <<(complete[i] ? "Completed" : "Pending")
            <<"]"<<endl;
        }
    }
    cout<<"------------------------------------------"<<endl;
    
//     for(int i = 0; i<task_counter; i++){
//         cout<<"Task "<<i+1 <<": "<<task[i]<<endl;
//     }
//     cout<<"----------------------------------------"<<endl;
}


int main(){
    system("color b");
    string task[10] = {""};
    // counter variable to know the no of tasks alloted 
    int task_counter = 0;
    bool complete[10] = {false};



    int option = -1;
    while(option != 0){
        // menu 
        cout<< "--TO-DO LIST--"<<endl;
        cout<< "1 --Add Tasks"<<endl;
        cout<<"2 --View Tasks"<<endl;
        cout<<"3 --Mark Task As Completed"<<endl;
        cout<<"4 --Remove Task"<<endl;
        cout<<"0 --Exit Program"<<endl;
        cout<<"Enter Your Choise : ";
        cin>>option;

        switch(option){
            case 1: 
            {
                if(task_counter >= 10){
                    cout<<"Task list is full."<<endl;
                }
                else{
                    cout<<"Enter a new task"<<endl;
                    cin.ignore();
                    getline(cin,task[task_counter]);
                    complete[task_counter] = false;
                    task_counter++;

                    cout<<"Task Added Successfully."<<endl;
                }
                break;
            }
            case 2:
                {
                    system("cls");
                    display_tasks(task, complete, task_counter);
                    break;
                }
            case 3:
                {
                    system("cls");
                    display_tasks(task, complete, task_counter);

                    int task_num;
                    cout<<"Enter task number to mark as completed : ";
                    cin>>task_num;
                    

                    if(task_num < 1 || task_num > task_counter){
                        cout<<"Invalid Task Number!"<<endl;
                    }

                    else{
                        complete[task_num - 1] = true;
                        cout<< "Task Marked As Completed."<<endl;
                    }

                    break;
                }
            case 4:
                {
                    system("cls");
                    display_tasks(task, complete, task_counter);
                    // delete the tasks
                    int delete_task;
                    cout<<"Enter a task to delete: ";
                    cin>>delete_task;

                    if(delete_task < 1 || delete_task > task_counter){
                        cout<<"You Entered Invalid Task Number!"<<endl;
                        break;
                    }
                    else{
                        for(int i = delete_task - 1; i<task_counter-1; i++){
                            task[i] = task[i+1];
                            complete[i] = complete[i+1];
                        }
                        task_counter--;
                        cout<<"Task Removed Successfully."<<endl;
                    }
                    break;
                    // for(int i = delete_task; i<task_counter; i++){
                    //     task[i] = task[i+1];

                    // }

                    // task_counter--;
                    // break;
                }

            case 0:
                {
                    cout<<"Terminating the program..."<<endl;
                    break;
                }
            default:
                {
                    cout<<"You Entered Invalid Value! Try Again."<<endl;

                }
        }
    }

    return 0;
}