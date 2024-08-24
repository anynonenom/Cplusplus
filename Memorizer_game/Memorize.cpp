//
//  Memorize.cpp
//  coding
//
//  Created by mac on 14/8/2024.
//

#include "Memorize.hpp"
#include <random>
#include<algorithm>
#include <string>

char arry[] = {'A'   , 'B' , 'C' , 'D' , 'E' ,  'F' ,  'G' , 'H' , 'I' , 'J' , 'K' ,'L' , 'M' , 'N' ,'O' , 'P' , 'Q',  'R' , 'S' , 'T',  'U' ,'V',  'W' , 'X' , 'Y' ,'Z' };
Memorize::Memorize(char alph){
    vect.push_back(alph) ;
}
Memorize::~Memorize(){
    // default
    vect.clear()  ;
}
void Memorize::inner_random(){
  
    int    place = 0 , compt=26   ;
    try {
       // cout << "Place a Number into the box between 0 and 25 : \n\t\t-> Start Memorization  : \n" ;
       
        int low = 0 ;
            int high = 25 ;
            std::vector<int> nums(high - low + 1);
            std::iota(nums.begin(), nums.end(), low);
            
            std::random_device rd;
            std::shuffle(nums.begin(), nums.end(), rd);
            
            for(int x : nums) {
               // cout << "->  " << x << endl ;
                //cout << arry[x] << " Inserted to the box["<< place << "],   Done , remains \n " ;
                vect.push_back(arry[x]) ;
                compt-- ;
                //cout << compt << " letters left :) \n" <<  endl ;
               // cout << "\t\t --  [!-!] -- \n " << endl ;
                place+=1 ;
            }
       // while (compt != 0 ) {
           
          //  cin >> L ;
            
        
       // }
    } catch (exception e) {
        cout << e.what() << endl ;
    }
}
    
    
  


void Memorize::view_output(){
    int i = 0 ;
    vector<char>::iterator iter ;
    iter = vect.begin() ;
    cout << endl << "\t" ;
      while(iter != vect.end()){
        cout << " box["<< i <<"] -> " << *iter  <<  " © , " ;
          ++iter ;
          i++ ;
    }
    cout << endl ;
}

void Memorize::Hit_Box() {
     int j = 1 ;
     int *status= &j ;
    cout << endl << "\t" ;
    // location :
    int loc ;
    char opt ;
    int stop = 3 , k=1 ;
    string str ;
    cout << "\t You Got 3 chance To Pick up  , Good luck Memorizer ;) \n" << endl ;
      while(stop!=0){
         cout << "Choose One letter from A to Z : " ;
          cin >> opt ;
          cout << "\n Location : " ;
          cin >> loc ;
          if (vect[loc] == opt) {
              cout << " You can do it ! ,  The box "<< vect[loc] <<" Great! , continue Memorizer " <<endl ;
              k+=1 ;
              continue;
          }
          else {
              stop-=1 ;
              cout << "You Got "<< stop <<" chances left ! " << endl ;
          }
         
          }
    wait(status) ;
        if (stop == 0) {
            cout << " You lost , sorry ! " << endl ;
            }
            if (k == 26) {
                cout << "You won ! Congratulation (+_+) " << endl ;
            }
            cout << "Do You wanna replay ( Yes/No )  : _ \t" ;
            cin >>  str ;
            if (str == "Yes" or str == "yes" or str == "y") {
                Hit_Box() ;
            }
            else {
                cout << "\n \t + Don't hesitate to return back to us , Enjoy your day memorizer ! " << endl ;
                exit(0) ;
            }
          
    
    cout << endl ;
}
