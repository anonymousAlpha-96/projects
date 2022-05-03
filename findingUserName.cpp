/*Program to find the mail ID is valid or not and if the mail id is valid user name will be displayed*/
#include<iostream>
#include<regex>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::regex;

int Username_Validator();
bool checkValid(string mail);

//regular expression have used to check mail id is valid or not
/*
1.  \w matches any character in any case any number of times.
2.  \.|_ matches if a dot or underscore is present 0 or 1 times.
3.  \w again match n characters.
4.  @ matches the @ in the email.
5.  again need to check for n characters and a ‘.’ and a word after it,
    which must be present at least one or more times.
*/
bool checkValid(string mail)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(mail,pattern);
}

int Username_Validator()
{
    string email;

    cout<<"\nEnter your Mail- ID : ";
    getline(cin,email);

    if(checkValid(email))
    {
        cout<<"\nEntered Mail-ID is valid : "<<email<<endl;
        int i = (int)email.find('@');
        string uname = email.substr(0,i);
        cout<<"\nUser Name is : "<<uname<<endl;
    }
    else{
            cout<<"\nEntered Mail-ID is invalid: "<<email<<endl;
    }
    return 0;
}
int main()
{
    Username_Validator();
    return 0;
}
