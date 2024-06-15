#include<bits/stdc++.h>
using namespace std;

class Task{
    public:
    
    void settask(vector<string>&taskList){
        string task;
        cout<<"Enter The Task to perform: ";
        cin>>task;
        taskList.push_back(task);
    }

    void printTask(vector<string>taskList){
        int sizeTaskList=taskList.size();
        if(sizeTaskList==0){
            cout<<"There are currently no active task";
            return;
        }
        for(int i=0;i<sizeTaskList;i++){
            cout<<i+1<<". "<<taskList[i]<<" "<<endl;
        }
    }

    void deleteTask(vector<string>&taskList,int index){
        if(index>=1){
            taskList.erase(taskList.begin()+index-1);
        }
        else {
            cout<<"Invalid Task To be Deleted";
        }
        printTask(taskList);
    }

    void completedTask(vector<string>&taskList,vector<string>&completedTask,int index){
        string completed=taskList[0];
        taskList.erase(taskList.begin()+0);
        completedTask.push_back(completed);
        printTask(taskList);
        cout<<"Completed Task List: "<<endl;
        printTask(completedTask);
    }
};



int main(){

    vector<string>today_task;
    vector<string>completedTask;

    Task t;
    int operation;
    cout<<"Choose form following to perform actions: "<<endl;
    cout<<"1. Print Task"<<endl;
    cout<<"2. Add Task"<<endl;
    cout<<"3. Delete Task"<<endl;
    cout<<"4. Add Completed Task"<<endl;
    cout<<"5. Exit"<<endl;
    cin>>operation;
    while(operation!=5){
        if(operation==1){
            t.printTask(today_task);
        }
        else if(operation==2){
            t.settask(today_task);
        }
        else if(operation==3){
            int index;
            cout<<"Enter The Index to Delete The Task: ";
            cin>>index;
            t.deleteTask(today_task,index);
        }
        else if(operation==4){
            int index;
            cout<<"Enter The Index of Completed Task: ";
            cin>>index;
            t.completedTask(today_task,completedTask,index);
        }
        cout<<"Choose form following to perform actions: "<<endl;
        cout<<"1. Print Task"<<endl;
        cout<<"2. Add Task"<<endl;
        cout<<"3. Delete Task"<<endl;
        cout<<"4. Add Completed Task"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>operation;
    }


    return 0;
}