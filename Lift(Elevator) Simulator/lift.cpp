#include<bits/stdc++.h>
using namespace std;

class Elevator{
    public:
        int currentFloor;
        priority_queue<int>downWards; //Here we are using max Heap 
        priority_queue<int,vector<int>,greater<int>>upWards; //Here we are using min Heap

        Elevator(){
            currentFloor=0;
        } //initially set the floor level to zero

        void getRequest(int floor){
            if(floor>currentFloor){
                upWards.push(floor);
            }
            else if(floor<currentFloor){
                downWards.push(floor);
            }
        } 

        bool hasRequest(){
            return !downWards.empty() || !upWards.empty();
        }

        void moveFloor(){
            if(!hasRequest()){
                cout<<"Currently No Request";
                return;
            }
            if(!downWards.empty()){
                currentFloor=downWards.top();
                downWards.pop();
            }
            else if(!upWards.empty()){
                currentFloor=upWards.top();
                upWards.pop();
            }
        }

        int getCurrentFloor(){
            return currentFloor;
        }
};

int main(){

    Elevator e;
    // Simulating floor requests
    e.getRequest(5);
    e.getRequest(2);
    e.getRequest(8);
    e.getRequest(3);
    e.getRequest(1);

    // Processing requests
    while (e.hasRequest()) {
        e.moveFloor();
        cout << "Elevator at floor: " << e.getCurrentFloor() << endl;
    }
    return 0;
}