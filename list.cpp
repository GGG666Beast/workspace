/*
list.cc 概要： 学籍番号，名前，姓が記入されたリストを入力し， これを名前，姓，学籍番号の順に出力するプログラム
Author: Kaise Beppu 
Date: 2019-10-09
*/

#include<iostream>
#include<string>
using namespace std;

int main(){

    string first, last, id;
    const int size=18;
    string frame(size,'=');
    string column(size,'-');
    int cnt=0;

    cout << "+" << frame << "+" << frame << "+" << frame << "+" << endl;

    while(cin >> id >> first >> last){

        string space1(size-first.size()-1,' ');
        cout << "| " <<first <<space1;
        string space2(size-last.size()-1,' ');
        cout << "| " <<last<<space2;
        string space3(size-id.size()-1, ' ');
        cout<<"| "<<id<<space3<<"|"<<endl;

        ++cnt;
        if(cnt%5==0){
            cout<<"+"<<column<<"+"<<column<<"+"<<column<<"+"<<cnt<<endl;
        }
    }
    cout<<"+"<<column<<"+"<<column<<"+"<<column<<"+"<<cnt<<endl;
    return 0;
}
        