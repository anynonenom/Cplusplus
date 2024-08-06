//
//  Fproject.hpp
//  coding
//
//  Created by mac on 30/7/2024.
//
#pragma once
#ifndef Account_hpp
#define Account_hpp
#include <stdio.h>
#include<string>
#include <iostream>
#include<list>
#include<algorithm>
#include<vector>
using namespace std ;
/*
 le compte  : soit de creer ou supprimer  , modifier  .....
 
 */
typedef struct data_info {
    int id ;
    string firstname ;
    string lastname ;
    string email ;
    string  phone;
    string password  ;
    string birth ;
}data_info;
class Account {
private:
  
public:
    static int cmpt ;
    data_info d  ;
    Account( data_info ); // constructor
    Account() ; // deconstructor
    data_info create_account() ;
    data_info delete_account(Account,list<data_info>  , int ) ;
    void update_account_info(list<data_info>& ) ;// ajouter au list 
    void modify_account_info(list<data_info>& , int&) ;
    void display_info(list<data_info>) ;
    data_info return_new_list(list<data_info>) ;
    // define operator==
  //  bool operator!=(int t) const {
    //       return d.id == t ;
    //}
   // void Menu() ;
};
#endif /* Account_hpp */
