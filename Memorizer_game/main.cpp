
//@Library

#include<iostream>
//#include <Magick++.h>
using namespace std  ;
#include"Memorize.hpp"
// Memorize the alphabet places
// @Main
 int main(int argc , const char *argv[] ) {
     // Hello !  I can do it !!!
     cout << "Hello ! Application.cpp \n " << endl ;
     vector<char> vt ;
     char chr = ' ';
     Memorize mem(chr) ;
     mem.inner_random() ;
     mem.view_output() ;
     mem.Hit_Box() ;
     
     return 0 ;
 }
