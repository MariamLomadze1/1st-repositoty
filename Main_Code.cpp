#include <regex>
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
#include <iostream>

int main() {
    int num1, num2, result;
    string str1, str2;
    string operation;
    cout << "Enter number: ";
    cin >> str1;
    while (!ValidationOfRomanNumerals(str1)) {           //while უზრუნველყოფს უწყვეტ რეჟიმში მოთხოვნას სწორი მონაცემისას, რადგან შეიძლება მომხმარებელმა რამდენჯერმე არასწორად შეიყვანოს მონაცემი
        if (str1=="exit") {                              
            return 0;
        }
        cout << "Enter correct Roman numeral:  ";
        cin >> str1;      
    }
    num1=translate_roman_numeral(str1);
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    while (operation!="+"&&operation!="-"&&operation!="*"&&operation!="/"&&operation!="exit"){  //ვინაიდან, შესაძლოა მცდარი სიმბოლო იქნეს შეყვანილი ოპერატორის შეყვანისასაც, შეზღუდულია სხვა სიმბოლოს შეყვანა, რომელიც არ იქნება  მოცემული სიმბოლოებიდან რომელიმეს ტოლი ან თუ არ უდრის exit-ს
        cout<<"Enter valid operation: ";          //აქაც გამოყენებულია while, if-ის ნაცვლად, რადგან შესაძლოა ზედიზედ რამდენჯერმე იქნეს შეყვანილი არასწორი სიმბოლო
        cin>>operation;
    }
    
    while (operation!="exit")
        
    {
        cout << "Enter number: ";
        cin >> str2;
        
        while (!ValidationOfRomanNumerals(str2)) {
        if (str2=="exit") { 
            break;
        }
        cout << "Enter correct Roman numeral:  ";
        cin >> str2;      
    }
        num2=translate_roman_numeral(str2);
       if (operation=="+") {
            result = num1 + num2;}
       if (operation=="-") {
            result = num1 - num2;}
       if (operation=="*") {
            result = num1 * num2;}
       if (operation=="/") {
            result = num1 / num2;}
        
        num1=result;
        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;
        while (operation!="+"&&operation!="-"&&operation!="*"&&operation!="/"&&operation!="exit"){
            cout<<"Enter valid operation: ";
            cin>>operation;
        }
        
    }
     if (num1<=0||num1>=4000){    //ვინაიდან შესაყვანი მონაცემების დიაპაზონი არ შევზღუდეთ 1-100-მდე, საჭირო გახდა აღნიშნული შეზღუდვის დადებაც, რადგან რომაულში არ გვაქ უარყოფითი რიცხვები და ასევე რიცხვები 3999-ს ზემოთ
         cout<<"Result is out of Roman numerals range and is equals to: "<<num1<<endl;
     }  
     else
     cout << "Result: " << int_to_roman(num1) << endl;
        
  
  

    return 0;
}
