#include<iostream>
#include<iomanip>
#include<ctime>

using namespace std;
class BILL{
    string name;
    int quantity;
    float total;
    public:
            BILL():quantity(0),total(0.0){};

        void input(){
        cout<<"enter Name of Receiptant:";
        getline(cin,name);
        cin.ignore();
        int items[12]={0,0,0,0,0,0,0,0,0,0,0,0}; int id, qty=0;
        cout<<setw(22)<<"\nSERVICE THAT WE PROVID"<<endl;
        cout<<setw(20)<<left<<"1.Banner(4x6):Rs288"<<setw(20)<<left<<"2.banner(10x9):Rs670"<<endl;
        cout<<setw(20)<<left<<"3.banner(7x12):Rs670"<<setw(20)<<left<<"4.Banner(10x10):Rs899"<<endl;
        cout<<setw(20)<<left<<"5.pamplets:Rs35"<<setw(20)<<left<<"6.Bill Board:Rs25,000"<<endl;
        cout<<setw(20)<<left<<"7.flyers:Rs20,000"<<setw(20)<<left<<"8.Graphic design:Rs500"<<endl;
        cout<<setw(20)<<left<<"9.business card:Rs20"<<setw(20)<<left<<"10.Wedding Invitation:Rs50"<<endl;
        cout<<setw(20)<<left<<"11.colour print:Rs10"<<setw(20)<<left<<"12.black & white:Rs4"<<endl;
        cout<<"Enter the item list in the form [item number] [quantity of specified item]"<<endl;
        cout<<"Enter a 0 to stop entering data"<<endl;
        while(1){
            cin>>id;
            if(id==0)
                break;
            cin>>qty;
            items[id-1]=items[id-1] + qty;
        }
        generate(items);
    }

    void generate(int item[])
    {
        time_t timestamp;
        time(&timestamp);
        int prices[12]={288,670,670,899,35,25000,20000,20,50,10,4};
        char names[20][20]={{"banner(4x6)"},{"banner(10x9)"},{"banner(7x12)"},{"banner(10x10)"},{"pamplets"},{"Bill Board"},{"flyers"},{"Graphic design"},{"business card"},{"Wedding Invitation"},{"colour print"},{"black & white"}};
        cout<<endl<<endl<<endl;
        cout<<setw(20)<<left<<"|| Shree Vetal Mahalaxmi Prasann ||"<<endl;
        cout<<setw(20)<<left<<"We Make Your Business Glow"<<setw(20)<<right<<"TAX INVOICE/CASH MEMO"<<endl;
        cout<<setw(20)<<left<<" PRABHU"<<setw(30)<<right<<"H.No.W1/26,Panditwada,Ponda-Goa"<<endl;
        cout<<setw(20)<<left<<"  IMAGE"<<setw(30)<<right<<"Tel.:0832-2315456/2319405"<<endl;
        cout<<setw(20)<<left<<" Pinting & Designing"<<setw(30)<<right<<"E-mail:prabhuimage@gmail.com"<<endl;
        for(int i=0;i<30;i++)
        cout<<"-";
        cout<<"|"<<setw(23)<<left<<setfill('-')<<"\nM/s";
        cout<<"|"<<setw(15);
    }

};

int main()
{
 	BILL b;
 	b.input();
}

