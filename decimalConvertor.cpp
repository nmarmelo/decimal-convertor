/******************************************************************************

   numConvertor.cpp           CAIS 230                       Nathan Marmelo
                        
   This program uses recursive functions to convert a positive decimal 
   integer value, n, to its corresponding binary, octal and hexadecimal 
   equivalents respectively. 
*******************************************************************************/

#include <iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<cstdlib>

using namespace std;

int main()
{
    //Declare variables
    int decimalNum;
    ofstream outs;
    
    //Prototype functions
    void describeProgram();
    void Get_decimal_number(int&convertMe);
    void DectoBin(int&convertMe, ofstream& outs);
    void DectoOctal(int&convertMe, ofstream& outs);
    void DectoHex(int&convertMe, ofstream& outs);
    void Report_Conversions(int&n, ofstream& outs);
    bool again();
    
    
    outs.open("conversions.txt", ios::out);
    
    describeProgram();
    
    do
    {
        Get_decimal_number(decimalNum);
        Report_Conversions(decimalNum, outs);      
    }while(again());
    
    outs.close();
    
}

void describeProgram()
{
     cout<<"This program converts any positive integer number into the"<<endl;
     cout<<"corresponding values for binary, octal, and hexadecimal."<<endl;
     cout<<"You will be prompted for a number, and the results will be"<<endl;
     cout<<"output to the screen and an external text file, 'conversions.txt'"<<endl;
     cout<<"You may repeat as many times as you'd like :) enjoy!"<<endl;    
}
void Get_decimal_number(int&convertMe)
{
     cout<<"Enter the number you would like to convert:";
     cin>>convertMe;
       
}

void DectoBin(int&convertMe, ofstream &outs)
{
     int quotient = (convertMe/2);
     int remainder = (convertMe % 2);

     if (quotient != 0)
        DectoBin(quotient, outs);
     
     cout<<remainder;
     outs<<remainder; 
}

void DectoOctal(int&convertMe, ofstream &outs)
{
     int quotient = (convertMe/8);
     int remainder = (convertMe % 8);
     
     if (quotient != 0)
        DectoOctal(quotient, outs);
     
     cout<<remainder;
     outs<<remainder; 

}

void DectoHex(int&convertMe, ofstream &outs)
{
     int quotient = (convertMe/16);
     int remainder = (convertMe % 16);
        
     if (quotient != 0)
        DectoHex(quotient, outs);
        
     if(remainder>=10)
     {
          switch(remainder)
          {
               case 10:
                    cout<<'A';
                    outs<<'A';
                    break;
               case 11:
                    cout<<'B';
                    outs<<'B';
                    break;
               case 12:
                    cout<<'C';
                    outs<<'C';
                    break;
               case 13:
                    cout<<'D';
                    outs<<'D';
                    break;
               case 14:
                    cout<<'E';
                    outs<<'E';
                    break;
               case 15:
                    cout<<'F';
                    outs<<'F';
                    break;
          }
     }
     else
     {
         cout<<remainder;
         outs<<remainder; 
     }
}

void Report_Conversions(int&n, ofstream &outs)
{
     
     cout<<"Decimal Number is       : "<<n<<endl;
     outs<<"Decimal Number is       : "<<n<<endl;
     
     cout<<"Binary Equivalent       : ";
     outs<<"Binary Equivalent       : ";
     DectoBin(n, outs);
     
     cout<<endl<<"Octal Equivalent        : ";
     outs<<endl<<"Octal Equivalent        : ";
     DectoOctal(n, outs);
     
     cout<<endl<<"Hexadecimal Equivalent  : ";
     outs<<endl<<"Hexadecimal Equivalent  : ";
     DectoHex(n, outs);
     
     cout<<"\n\n";
     outs<<"\n\n";
}
bool again()
{
     char answer;
     cout<<"\nWould you like to run the program again?"<<endl;
     cout<<"        y=yes          n=no             "<<endl;
     cin>>answer;
     
     if(answer == 'y')
          return true;
     else if(answer == 'n')
          return false;
}
