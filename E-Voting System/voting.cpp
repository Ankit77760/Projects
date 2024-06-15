#include<bits/stdc++.h>
using namespace std;

vector<int>votersList;
map<int,string>electoralRoll;
map<string,map<string,string>>candidateList;
class Administrator{
    public: 
        string username;
        string password;
        bool loginFlag=false;
        void setAdministrator(){
            string username;
            cout<<"Enter Your UserName: ";
            cin>>username;
            string password;
            cout<<"Enter Your Password: ";
            cin>>password;
        
            this->username=username;
            this->password=password;
        }

        void display(){
            cout<<"1. Add Voters"<<endl;
            cout<<"2. Display Voters"<<endl;
            cout<<"3. Delete Voters"<<endl;
            cout<<"4. Add Candidate"<<endl;
            cout<<"5. Delete Candidate"<<endl;
            cout<<"6. Count Votes"<<endl;
            cout<<"7. Exit"<<endl;
        }

        bool search(vector<int>&votersList,int voterNumber){
            int n=votersList.size();
            for(int i=0;i<n;i++){
                if(voterNumber==votersList[i]){
                    return true;
                }
            }
            return false;
        }

        void addvoters(vector<int>&votersList){ 
            string name;
            cout<<"Enter Name of Voter: ";
            cin>>name;
            
            int dob;
            cout<<"Enter Age of the Voter: ";
            cin>>dob;
            if(dob<18){
                cout<<"Voter Cannot be Below 18 Years";
                return;
            }
            int flagAdded=0;
            int voterNumber;
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<>dis(0,5);
            voterNumber=dis(gen);
            if(search(votersList,voterNumber)==false){
                votersList.push_back(voterNumber);
                electoralRoll[voterNumber]=name;
                cout<<endl;
                flagAdded=1;
            }
            else{
                cout<<"Failed TO Add"<<endl;
                display();
            }
        }

        int searchIndex(vector<int>votersList,int voterNumber){
            int n=votersList.size();
            for(int i=0;i<n;i++){
                if(votersList[i]==voterNumber){
                    return i;
                }
            }
            return -1;
        }

        void displayVoters(map<int,string>&electoralRoll){
            int idx=1;
            cout<<"----------------------Voter List--------------------"<<endl;
            for(auto it:electoralRoll){
                cout<<idx++<<" "<<it.first<<" "<<it.second<<endl; 
            }
            cout<<"----------------------Voter List--------------------"<<endl;
        }

        void deletevoters(map<int,string>&electoralRoll,int voterNumber){
            electoralRoll[voterNumber]="Deleted";
            int idx=searchIndex(votersList,voterNumber);
            votersList.erase(votersList.begin()+idx);
            displayVoters(electoralRoll);
        }

        void displayCandidate(map<string,map<string,string>>&candidateList){
            cout<<"----------------------Candidate List-----------------"<<endl;
            for(auto it:candidateList){
                cout<<it.first<<" ";
                for(auto itt:it.second){
                    cout<<itt.first<<" "<<itt.second<<" ";
                }
            }
            cout<<"----------------------Candidate List-----------------"<<endl;
        }
        
        void addCandidate(map<string,map<string,string>>&candidateList){
            string nameOfConstituency;
            cout<<"Enter The Name of Constituency: ";
            cin>>nameOfConstituency;
            string nameofCandidate;
            cout<<"Enter The Name of Candidate: ";
            cin>>nameofCandidate;
            string symbolOfCandidate;
            cout<<"Enter The Symbol of Candidate: ";
            cin>>symbolOfCandidate;
            candidateList[nameOfConstituency][nameofCandidate]=symbolOfCandidate;
            cout<<endl;
            displayCandidate(candidateList);
        }

        void deleteCandidates(std::map<std::string, std::map<std::string, std::string>>& candidateList) {
            string nameOfCandidate;
            cout << "Enter The Name of Candidate to Delete: ";
            cin >> nameOfCandidate;

            bool found = false;
            for (auto& constituency : candidateList) {
                auto it = constituency.second.find(nameOfCandidate);
                if (it != constituency.second.end()) {
                    constituency.second.erase(it);
                    cout << "Candidate " << nameOfCandidate << " deleted successfully." <<endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Candidate " << nameOfCandidate << " not found." << std::endl;
            }
        }   
      

        void login(string username,string password){
            if(this->username==username && this->password==password){
                cout<<"Login Successfull"<<endl<<endl;
                loginFlag=true;
                cout<<"Enter The Number to perform Operations"<<endl;
                display();
                
                if(loginFlag){
                    int operations;
                    cin>>operations;   
                    while(operations!=7){
                        if(operations==1){
                            addvoters(votersList);
                            displayVoters(electoralRoll);
                            cout<<endl;
                        }
                        if(operations==2){
                            displayVoters(electoralRoll);
                            cout<<endl;
                        }
                        if(operations==3){
                            int voterNumber;
                            cout<<"Enter Voter Number of The Voter To Delete: ";
                            cin>>voterNumber;
                            deletevoters(electoralRoll,voterNumber);
                        }
                        if(operations==4){
                            addCandidate(candidateList);
                        }
                        if(operations==5){
                            deleteCandidates(candidateList);
                        }
                        cout<<endl;
                        display();
                        cin>>operations;
                    }
                }
            }
            else{
                cout<<"Login Failed, Kindly check username or password";
            }
        }
};

class User{

};

int main(){
    Administrator a;
    cout<<"Enter Your Registration Credentials"<<endl;
    cout<<endl;
    a.setAdministrator();
    cout<<endl;
    cout<<"Enter Your Login Credentials"<<endl<<endl;
    string username;
    cout<<"Enter Your Username to Login: ";
    cin>>username;
    string password;
    cout<<"Enter Your Password to Login: ";
    cin>>password;
    a.login(username,password);

    return 0;
}