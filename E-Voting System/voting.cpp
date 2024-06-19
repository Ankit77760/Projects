#include<bits/stdc++.h>
using namespace std;

vector<int>votersList;
map<int,string>electoralRoll;
map<string,map<string,string>>candidateList;
unordered_map<string,int>voteCount;
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
            uniform_int_distribution<>dis(1000,9999);
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
                cout<<idx++<<". "<<it.first<<" "<<it.second<<endl; 
            }
            cout<<"----------------------Voter List--------------------"<<endl;
        }

        void deletevoters(map<int,string>&electoralRoll,int voterNumber){
            auto it=electoralRoll.find(voterNumber);
            if(it!=electoralRoll.end()){
                electoralRoll.erase(it);
            }
            int idx=searchIndex(votersList,voterNumber);
            votersList.erase(votersList.begin()+idx);
            displayVoters(electoralRoll);
        }

        void displayCandidate(map<string,map<string,string>>&candidateList){
            cout<<"----------------------Candidate List-----------------"<<endl;
            int i=1;
            for(auto it:candidateList){
                cout<<i++<<" "<<it.first<<" ";
                for(auto itt:it.second){
                    cout<<itt.first<<" "<<itt.second<<" "<<endl;
                }
            }
            cout<<endl;
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

        void deleteCandidates(map<string, map<string, string>>& candidateList) {
            string nameOfCandidate;
            cout << "Enter The Name of Candidate to Delete: ";
            cin >> nameOfCandidate;

            bool found = false;
            for(auto it=candidateList.begin();it!=candidateList.end();){
                auto &candidates=it->second;
                auto candidateIt=candidates.find(nameOfCandidate);
                if(candidateIt!=candidates.end()){
                    candidates.erase(candidateIt);
                    found=true;
                }
                if(candidates.empty()){
                    it=candidateList.erase(it);   
                }
                else{
                    it++;
                }
            }
            if(found){
                cout<<"Candidate Deleted Successfully"<<endl;
            }
            else{
                cout<<"Candidate Not Found In Data"<<endl;
            }
            displayCandidate(candidateList);
        }   
      
        void countVote(unordered_map<string,int>&voteCount){
            for(auto it:voteCount){
                cout<<it.first<<" "<<it.second<<" "<<endl;
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
                        if(operations==6){
                            countVote(voteCount);
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
    public:
        void displayCandidate(map<string,map<string,string>>&candidateList){
            cout<<"--------------------Candidatee List-----------------------"<<endl;
            int it=0;
            for(auto it:candidateList){
                cout<<it++<<". "<<it.first<<" ";
                for(auto itt:it.second){
                    cout<<itt.first<<" "<<itt.second<<" ";
                }
            }
            cout<<endl<<endl;
        }

        bool searchNameInElectoralRoll(vector<int>&votersList,int voterNumber){
            int n=votersList.size();
            for(int i=0;i<n;i++){
                if(voterNumber==votersList[i]){
                    return true;
                }
            }
            return false;
        }

        void menu(){
            cout<<"1. View Candidate List"<<endl;
            cout<<"2. Cast Your Vote"<<endl;
        }

        bool searchCandidate(map<string,map<string,string>>&candidateList,string nameOfCandidate){
            for(auto it:candidateList){
                for(auto itt:it.second){
                    if(itt.first==nameOfCandidate){
                        return true;
                    }
                }
            }
            return false;
        }

        void display(){
            int operations;
            menu();
            cout<<"Enter The Operation to perform: ";
            cin>>operations;
            while(operations!=3){
                if(operations==1){
                    displayCandidate(candidateList);
                }
                if(operations==2){
                    int voterNumber;
                    cout<<"Enter Your Voter Number: ";
                    cin>>voterNumber;
                    if(searchNameInElectoralRoll(votersList,voterNumber)){
                        int password;
                        cout<<"Enter Your Password To Vote: ";
                        cin>>password;
                        if(password==123){
                            cout<<"Welcome To Vote"<<endl<<endl;
                            string candidateName;
                            cout<<"Enter The Name of The Candidate to Vote: ";
                            cin>>candidateName;
                            if(searchCandidate(candidateList,candidateName)){
                                voteCount[candidateName]++;
                            }
                        }

                    }
                }
                cout<<endl;
                menu();
                cin>>operations;
            }
        }

};

void optionsmenu(){
    cout<<"1. Administrator"<<endl;
    cout<<"2. User"<<endl;
}

int main(){
    cout<<"Welcome To Voting Poll"<<endl;
    int options;
    cout<<"Kindly Choose Yourself"<<endl;
    optionsmenu();
    cin>>options;

    while(options!=3){
        if(options==1){
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
        }
        if(options==2){
            User u;
            u.display();
        }
        cout<<endl;
        optionsmenu();
        cin>>options;
    }

   

    return 0;
}