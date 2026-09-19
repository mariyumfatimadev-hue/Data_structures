#include<iostream>
using namespace std;
int main(){
    int arrofdata[]= {1,2,5,7,1,2,9};
    int arrofcol[] = {0,2,2,2,3,3,4}; //for j 
    int indexpointer[] = {0,2,3,3,3,6,6,7}//for i ya hum data ke size se bari rakhte ha jase ke arroddata+1 /&& for i 
    //(thisis for rows)
    int  target_row;
    int targetcol;
    cout<<"enter the row and column for which you need data";
    cin>> target_row >>targetcol;
    bool found = false;
    int totalelements = sizeof(arrofdata)/sizeof(arrofdata[0]);
     for(int i =0; i<totalelements; i++ ){
        if(i>=indexpointer[target_row] && i<indexpointer[target_row+1]) //ya utna hi data niklt=ata ha
            if(arrofcol[i] == targetcol ){
            cout<<arrofdata[i];
            found = true;
            break;
        }
        else
        found = false;
     }
    } 
}