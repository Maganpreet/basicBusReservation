#include <iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include<cstring>

using namespace std;

//class bus_show;
class bus_entry
{
    public:
    int b_no;
    float charge;
    char route[100],departure[100],time[100];
    fstream b_entry;
    void bus_entr()
    {
        /**
            THE WHOLE MODULE IS FOR THE CODER
            TO ENTER THE BUSSES INTO THE FILE
            DON'T YOU DARE TO TOUCH IT !!!
        */
        b_entry.open("BusSchedule.txt",ios::in|ios::out|ios::app);
        //to check whether the file is open or not
        if(b_entry.is_open()){
            cout<<"Your file is open\n";
        }else{
            cout<<"Oops, perhaps try again !!\n";
        }
        //input the bus information
        while(cin>>b_no>>route>>departure>>time>>charge){
            b_entry << b_no <<' '<< route <<' '<< departure<<' '<<time<<' '<<charge<<endl; //departure is going to have values like morning,etc while time will have 5:00am
        }
        b_entry.close();
        //cout<<"Where do you wanna go?\n";
    }
    //virtual void book_tic()=0;
    /*virtual void opt()
    {
        //bus_show::show_bus();
    }*/
};
class options:public bus_entry
{
public:
    string location;
    void opt()
    {
        //strcpy(destination,des);
        /** GETTING THE PERSON'S LOCATION */
        cout<<"\n\n***************************************************************************************\n\n";
        cout<<"\n\nWhere you wanna catch your bus from mate :) ?\n\n";
        cin>>location;
        cout<<"\n\nSo you want a bus from "<<location<<endl;
    }
    void tion()
    {
        /** WRITING DOWN THE PERSON'S OPTION ONTO THE SCREEN */
        ifstream option("BusSchedule.txt");
        if(option.is_open()){
            cout<<"Here's your options:-\n";
        }else{
            cout<<"Maybe try again\n";
        }
        cout<<"\n\n***************************************************************************************\n\n";
        while(option>>b_no>>route>>departure>>time>>charge){
            if(route[0]==location[0]){
                cout<<b_no<<setw(28)<<route<<setw(13)<<departure<<setw(12)<<time<<setw(12)<<charge<<endl;
            }
        }
        option.close();

    }

};
class book:virtual public bus_entry
{
public:
    int n;
    int b;
    float cost;
    char name[100];
    char file[100];
    /** BOOK TICKET */
    void bus_num()
    {
        cout<<"\n\n***************************************************************************************\n\n";
        cout<<"Enter the bus number of bus you want to travel with: ";
        cin>>b;
    }
    void book_tic()
    {
        ifstream make("BusSchedule.txt");
        while(make >> b_no >> route >> departure >> time >> charge){
            if(b_no==b){
                cost = charge;
                strcpy(file,route);
                break;
            }
        }
        strcat(file,".txt");
        /** BOOKING A TICKET  */
        fstream pass(file,ios::in|ios::out|ios::app);
        if(pass.is_open()){
            cout<<"\nWe arranging a ticket for you....\n";
        }else{
            cout<<"OOPS!!\n";
        }
        /** WRITING THE PASSENGERS DOWN INTO THE FILE */
        cout<<"\nHow many of you would be accompanying us and\nYour name ;)\n";
        while(cin>>n>>name){
            char c;
            cost *= n;
            cout<<"The cost of ticket would be "<<cost<<endl;
            cout<<"Do you want to continue? ";cin>>c;
            if(c=='y'||c=='Y'){
                pass<<n<<'\t'<<name<<'\t'<<cost<<endl;
                cout<<"\nYour ticket is booked"<<endl;
                break;
            }
            break;
        }
        make.close();
        pass.close();
    }
};
/*class del:public book,public bus_entry
{
public:
    void bus_del()
    {
        cout<<"What is your Bus number: ";
        cin>>b;
        ifstream bno("")
    }
};*/
class bus_show:public bus_entry
{
    public:
    void show_bus()
    {
        /** DISPLAYS ALL THE BUSSES ONTO SCREEN*/
        ifstream b_show("BusSchedule.txt");
        if(b_show.is_open()){
            cout<<"Here's your Routes\n";
        }else{
            cout<<"Sorry mate!!\n";
        }
        cout<<"Bus No."<<setw(18)<<"Routes"<<setw(20)<<"Departure"<<setw(10)<<"Time"<<setw(15)<<"Charge\n";
        while(b_show >> b_no >> route >> departure >> time >> charge){
            cout<<b_no<<setw(28)<<right<<route<<setw(13)<<departure<<setw(12)<<time<<setw(12)<<charge<<endl;
        }
        b_show.close();
    }
};
/*class tic_show:public bus_entry
{
public:

};*/
int main(void)
{
    char ch,op;
    cout<<"Press y if you are X\n";
    cin>>ch;
    if(ch=='y'||ch=='Y'){
        bus_entry be;
        be.bus_entr();
    }
    cout<<"\n\n***************************************************************************************\n\n";
    cout<<"Want to see some options,press y then: ";
    cin>>op;
    if(op=='y'||op=='Y'){
        bus_show bs;
        bs.show_bus();
    }
    options o;
    o.opt();
    o.tion();
    cout<<"\nSo how about booking it now\n";
    char bk;
    cin>>bk;
    if(op=='y'||op=='Y'){
        book b;
        b.bus_num();
        b.book_tic();
    }
}
