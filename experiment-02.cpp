#include <iostream>
#include <string>
using namespace std;

string Keyword[] = {
    "cin","cout","endl","getline","main",
    "int","float","char","if","else","for","while"
};

string Operator[] = {
    "+","-","*","/","%","=","==","!=",
    ">","<",">=","<=","&&","||","!",
    "++","--","<<",">>"
};

string Punctuation[] = {
    ";",",","(",")","{","}","[","]"
};

void tokenize(string input){
    string token="";
    input+=" ";

    for(int k=0; k<input.length(); k++){
        if(input[k]!=' '){
            token+=input[k];
        }
        else{
            if(token==""){
                continue;
            }

            bool found=0;

            //Keyword
            int keySize=sizeof(Keyword)/sizeof(Keyword[0]);
            for(int i=0; i<keySize; i++){
                if(token==Keyword[i]){
                    cout<<"Keyword: "<<token<<endl;
                    found=true;
                    break;
                }
            }

            //Operator
            if(!found){
                int opSize=sizeof(Operator)/sizeof(Operator[0]);
                for(int i=0; i<opSize; i++){
                    if(token==Operator[i]){
                        cout<<"Operator: "<<token<<endl;
                        found=true;
                        break;
                    }
                }
            }

            //Punctuation
            if(!found){
                int punSize=sizeof(Punctuation)/sizeof(Punctuation[0]);
                for(int i=0; i<punSize; i++){
                    if(token==Punctuation[i]){
                        cout<<"Punctuation: "<<token<<endl;
                        found=true;
                        break;
                    }
                }
            }

            //Numeric
            if(!found){
                bool numeric=true;
                int dot=0;

                for(int i=0;i<token.length();i++){
                    if(token[i]=='.'){
                        dot++;
                        if(dot>1){
                            numeric=false;
                            break;
                        }
                    }
                    else if(!isdigit(token[i])){
                        numeric=false;
                        break;
                    }
                }

                if(numeric){
                    cout<<"Numeric: "<<token<<endl;
                    found=true;
                }
            }

            //Identifier
            if(!found){
                bool identifier=true;

                if(!(isalpha(token[0]) || token[0]=='_')){
                    identifier=false;
                }

                for(int i=1;i<token.length();i++){
                    if(!(isalnum(token[i]) || token[i]=='_')){
                        identifier=false;
                        break;
                    }
                }

                if(identifier){
                    cout<<"Identifier: "<<token<<endl;
                    found=true;
                }
            }

            //Lexical Error
            if(!found){
                cout<<"Lexical Error: "<<token<<endl;
            }

            token="";
        }
    }
}

int main(){
    string input="cout << 20 + a * 60.5";
    tokenize(input);
}
