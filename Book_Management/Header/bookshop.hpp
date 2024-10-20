/*
  @ 20/10/2024
*/
#pragma once
#define bookshop_HPP
#ifdef   bookshop_HPP
#include<stdio.h>
#include <iostream>
#include <fstream>
#include <ios>
#include<sstream>
#include<vector>
#include<string>



struct databook {
    int id ;
    std::string name ;
    std::string  autheur ; 
    int numberpage ;
};



class bookshop
{
private:
    /* data */
  databook infobook ;
  

public:
    bookshop(int , std::string , std::string ,  int  /* args */);
    void addbook(std::string);
    void showbook() ;
    void checkbook(int) ;
    void modifybook() ;
    void deletebook() ;

    bookshop();
    // std::string  toString() ;
};

#endif //bookshop_HPP
