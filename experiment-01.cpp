#include <iostream>
#include <string>
using namespace std;

void check_numeric(){
    string input;
    cout<<"Enter your string: ";
    cin>>input;

    for(int i=0; i<input.length(); i++){
        if((int)input[i]>48 || (int)input[i]<57){
            cout<<"Numeric Constant"<<endl;
        }
        else{
            cout<<"Not Numeric"<<endl;
        }
    }
}

void check_operator(){
    string input;
    cout<<"Enter your string: ";
    cin>>input;

    for(int i=0; i<input.length(); i++){
        int count=0;
        if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%' || input[i]=='='){
            count++;
            for(int j=0; j<count; j++){
                cout<<"Operator "<<j+1<<": "<<input[i]<<endl;
            }
        }
    }
}

void check_comment() {
    string input;
    cout << "Enter your string: ";
    cin.ignore();
    getline(cin, input);

    bool found=0;

    for(int i=0; i+1<(int)input.length(); i++) {
        if(input[i]=='/' && input[i+1]=='/') {
            found=true;
            cout << "Single Line Comment: ";
            for(int j=i+2; j<input.length(); j++)
                cout<<input[j];
            cout<<endl;
            break;
        }

        else if(input[i]=='/' && input[i+1]=='*') {
            cout<<"Multi Line Comment: ";
            int j=i+2;
            bool closed=false;

            while(j+1<input.length()) {
                if(input[j]=='*' && input[j+1]=='/') {
                    closed=true;
                    break;
                }
                cout<<input[j];
                j++;
            }

            if(!closed)
                cout << "\nError: Comment not closed.";
            cout << endl;
            found = true;
            break;
        }
    }

    if(!found)
        cout << "No comment detected!" << endl;
}

void check_identifierA(){
    string input;
    cout<<"Enter your string: ";
    cin>>input;

    for(int i=0; i<input.length(); i++){
        if(toupper(input[0]) >='A' && toupper(input[0])<='Z' || input[0]=='_'){
            cout<<"Identifier valid."<<endl;
            break;
        }
        else{
            cout<<"Identifier not valid!"<<endl;
            break;
        }
    }
}

void check_identifierB(){
    string input;
    cout<<"Enter your string: ";
    cin>>input;

    for(int i=0; i<input.length(); i++){
        if((toupper(input[1])>='A' && toupper(input[1])<='Z') || input[1]=='_' || (input[1]>=0) && input[1]<=9){
            cout<<"Identifier valid."<<endl;
            break;
        }
        else{
            cout<<"Identifier not valid!"<<endl;
            break;
        }
    }
}

void average_value(){
    int length;
    cout<<"Enter your array length: ";
    cin>>length;
    int num_array[length];
    int sum=0;

    for(int i=0; i<length; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>num_array[i];
        sum+=num_array[i];
    }
    cout<<"Average Value: "<<(double)sum/length<<endl;
}

void minimum_maximum(){
    int length;
    cout<<"Enter your array length: ";
    cin>>length;
    int num_array[length];
    int minimum, maximum;

    for(int i=0; i<length; i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>num_array[i];
    }

    minimum=num_array[0];
    maximum=num_array[1];

    for(int i=0; i<length; i++){
        if(num_array[i]<minimum){
            minimum=num_array[i];
        }
        if(num_array[i]>maximum){
            maximum=num_array[i];
        }
    }
    cout<<"Minimum: "<<minimum<<endl;
    cout<<"Maximum: "<<maximum<<endl;
}

void concate_name(){
    string first_name;
    string last_name;

    cout<<"Enter your first name: ";
    cin>>first_name;
    cout<<"Enter your last name: ";
    cin>>last_name;

    cout<<"Your full name is "<<first_name<<" "<<last_name<<endl;
}

int main(){
    while(true){
        cout<<endl;
        cout<<"====Lab Task-1===="<<endl;
        cout<<"1. Check Numeric Constant"<<endl;
        cout<<"2. Check Operators"<<endl;
        cout<<"3. Check Comment"<<endl;
        cout<<"4. Check Identifier"<<endl;
        cout<<"5. Find Average Value"<<endl;
        cout<<"6. Find the Minimum and Maximum Value"<<endl;
        cout<<"7. Concatenate your name"<<endl;
        cout<<"8. Exit"<<endl;
        cout<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1: check_numeric();
                break;
            case 2: check_operator();
                break;
            case 3: check_comment();
                break;
            case 4: check_identifierA();
                break;
            case 5: average_value();//check_identifierB();
                break;
            case 6: minimum_maximum();
                break;
            case 7: concate_name();
                break;
            case 8:
                cout<<"Program Ended!"<<endl;
                return 0;
                break;
        }
    }
    return 0;
}


/*
cd_summer_26
experiment1.cpp
*/
