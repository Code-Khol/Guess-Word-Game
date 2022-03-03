#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

void select();
void valid();
void check();

fstream input; //you can get input file from github:Code-Khol.
string select_str,User,Read;
int round;
int first,second,win;
bool checkpoint;

int main()
{
    system("color 2");

    select();

    for(round=1 ; round<=5 ; round)
    {
    	cout<<"round("<<round<<"/5) : ";
        getline(cin , User);

        if(User.length() == 5)
            valid();
        if(User.length() != 5)
            cout<<"length must be 5!"<<endl;
        if(win == 5)
        {
            system("cls");
            cout<<"You Won! The answer is "<<User<<endl;
            checkpoint = true;
            break;
        }
    }
    if(checkpoint == false)
    {
        system("cls");
        cout<<"Game Over! the answer is "<<select_str<<endl;
    }


    system("pause>0");
    return 0;
}

//---------functions----------//

void select()
{
    string choose[12972];
    input.open("input.txt" , ios :: in);
    for(int line=0 ; !input.eof() ; line++)
        input>>choose[line];
    
    srand(time(0));
    select_str = choose[rand()%12972]; //choose random word from input file.
    //cout<<select_str<<endl;

    input.close();
}

void valid()
{
    int pass;
    bool valid_bool = false;
    input.open("input.txt" , ios :: in);

    for(int line=0 ; !input.eof() ; line++)
    {
        input>>Read;
        pass = Read.compare(User);

        if(pass == 0)
        {
            round++;
            valid_bool = true;
            //cout<<User<<" is valid"<<endl;
            check();
            break;
        }
    }
    if(valid_bool == false)
        cout<<User<<" Is no valid!"<<endl;
    input.close();
}

//Green = right 
//Yellow = Wrong position
//Red = wrong

void check()
{
    string point[] = {"Green" , "Yellow" , "Red"};
    bool find;
    win=0;
    for(first=0 ; first<5 ; first++)
    {
        if(User[first] == select_str[first])
        {   cout<<User[first]<<" : "<<point[0]<<endl; win++;}
        else
        {
        	find = false;
            for(second=0 ; second<5 ; second++)
                if(User[first] == select_str[second])
                {
                    find = true;
                    break;
                }
            if(find == true)
                cout<<User[first]<<" : "<<point[1]<<endl;
            else
                cout<<User[first]<<" : "<<point[2]<<endl;
        }
    }
}