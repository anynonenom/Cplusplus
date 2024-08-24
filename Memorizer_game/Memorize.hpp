//
//  Memorize.hpp
//  coding
//
//  Created by mac on 14/8/2024.
//

#ifndef Memorize_hpp
#define Memorize_hpp
#define N_X 26
#include<iostream>                                                          		
#include <stdio.h>
#include<vector>
#include<random>
#include<algorithm>
#include <string>

using namespace std ;
class Memorize {
private:
    
    vector<char> vect ;
    //stack<char> stck ;
    int i = 0 ;
public:
    
    ~Memorize() ;
    Memorize(char );
    void inner_random( ) ;
    void view_output() ;
    void Hit_Box() ;
};
#endif /* Memorize_hpp */
