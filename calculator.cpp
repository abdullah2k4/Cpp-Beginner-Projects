#include<iostream>
using namespace std;
class Calculator
{
private:
float number_1;
float number_2;
float result;
public:
void set_number1(float a);
void set_number2(float a);
void opt(char opt);
};
void Calculator:: opt(char opt)
{
    switch(opt)
    {
        case '*':{result=number_1*number_2;
        cout<<number_1<<" * "<<number_2<<" = "<<result<<endl;
        }break;
        case '/':{result=number_1/number_2;
        cout<<number_1<<" / "<<number_2<<" = "<<result<<endl;
        }break;
        case '+':{result=number_1+number_2;
        cout<<number_1<<" + "<<number_2<<" = "<<result<<endl;
        }break;
        case '-':{result=number_1-number_2;
        cout<<number_1<<" - "<<number_2<<" = "<<result<<endl;
        }break;
        default: 
        {cout<<"wrong operator ";}
        
    }
}
void Calculator:: set_number1(float a){number_1=a;}
void Calculator:: set_number2(float a){number_2=a;}
int main()
{
    float no_1,no_2;
    char opt,option;
    do{
    Calculator a;
    cout<<"Enter first number: ";
    cin>>no_1;
    a.set_number1(no_1);
    cout<<"Enter secound number: ";
    cin>>no_2;
    a.set_number2(no_2);
    cout<<"Enter operator: ";
    cin>>opt;
    a.opt(opt);
    cout<<"Do you have more calculations to do..";
    cout<<"Enter \'y\' to continoue";
    cin>>option;
    }while(option=='y');

 return 0;
}
