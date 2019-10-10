/*
list.cc 概要： 学籍番号，名前，姓が記入されたリストを入力し， これを名前，姓，学籍番号の順に出力するプログラム
Author: Kaise Beppu 
Date: 2019-10-09
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){


    string first, last, id;
    vector<double> kadai;
    vector<double>::size_type size2;
    double mid,final,sum,average,median,score;
    int amari;
    const int size=18;
    string frame(size,'=');
    string column(size,'-');
    int cnt=0;

    //フレームの表示
    cout << "+" << frame << "+" << frame << "+" << frame << "+" << "=====+======+=======+=======+" << endl;

    //ここからデータの読み取り。一つ目のループで期末まで、二つ目のループで演習課題
    while(cin>>first>>last>>id>>mid>>final){
        
        sum=0;
        double tmp;
        cin>>tmp;
        while(tmp!=-1){

            kadai.push_back(tmp);
            sum+=tmp;
            cin>>tmp;
        }

        size2=kadai.size();
        average=sum/(double)size2;
        sort(kadai.begin(),kadai.end());

        //中央値をしらべる
        amari=(int)size2%2;
        if(amari==1) {
            amari=(int)size2/2+1;
            median=kadai[amari];
        }
        else{
            amari=(int)size2/2;
            median=(kadai[amari]+kadai[amari+1])/2;
        }
        score=mid*0.2+final*0.4+median*0.4;

        string space1(size-first.size()-1,' ');
        cout << "| " <<first <<space1;
        string space2(size-last.size()-1,' ');
        cout << "| " <<last<<space2;
        string space3(size-id.size()-1, ' ');
        cout<<"| "<<id<<space3<<"| ";
        
        cout<<sum<<" | "<<average<<" | "<<median<<" | "<<score<<" |"<<endl;

        cout<<"+"<<column<<"+"<<column<<"+"<<column<<"+" << "-----+------+-------+-------+" << endl;

}

cout << "+" << frame << "+" << frame << "+" << frame << "+" << "=====+======+=======+=======+" << endl;

    return 0;
}
        