/*
  @20/10/2024
*/

#include "../header/bookshop.hpp"
#include <algorithm>
#include <exception>
#include <fstream>
#include <ios>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

// compteur :
int cmpt = 0 ;
// 4 données
bookshop::bookshop( int Id  , std::string nm , std::string auth , int npge/* args */)
{
    this->infobook.id= Id ;
    this->infobook.name = nm ;
    this->infobook.autheur = auth ;
    this->infobook.numberpage = npge ;

}

 bookshop::bookshop()
 {
     this->infobook.id= 0 ;
    this->infobook.name = "" ;
    this->infobook.autheur = "" ;
    this->infobook.numberpage = 0 ;
 }
void bookshop::addbook(std::string file_name ){
    // std::list<std::string>  lts ; // return _list
    // general fstream :
    // std::fstream inout ;
 
    int count ; 
    // inout.open("../../dataFiles/store.csv" , std::ios::in | std::ios::app) ;// file in and input :
    // Enregistré au file_name :
    std::ofstream  file("../../dataFiles/"+file_name , std::ios::app | std::ios::out) ;
    // données de La bibliothéque :
    int ID ;
    std::string y ;
     std::string NM ; std::string AUTH ; int NPGE ;

    // Opérations :
    //  ID = cmpt++ ;
    /// Name 
    //
    label :

    std::cout << "Enter Your adrees number : " ;
    std::cin >> ID ;
    std::string code = std::to_string(ID)  ;
    if( code.size() == 4) {
        std::cout << "\t Nom de livre : " ; 
        std::cin >> NM ;
        // Author
        std::cout << "\t Nome d'authorisation : " ; 
        std::cin >> AUTH ;
        // Number of the page
        std::cout << "\t nombre des copies : " ;
        std::cin >> NPGE ;
    bookshop bk(ID , NM , AUTH , NPGE) ;
     /// Name 
    if(file.is_open()) {

    file <<"," << bk.infobook.id 
    /* Name :*/
    << "," << bk.infobook.name  << 
    /* Author*/ 
     ","<< bk.infobook.autheur <<
    /* Number of the page*/
     "," << bk.infobook.numberpage<<"\n" ;
    
    std::cout << "Has been stored in the data \n\n" ;
    }
    else {
        std::cout << "\nsorry! Might be some troubles in ur file_name \n" ;
    }
    }
    else {
        std::cout << "Sorry ! but your pattern has to include  4 number - Wanna try again (y/n) ? " << std::endl ;
        std::cin >> y ;
        if(y == "Y" || y == "y" || y== "yes" || y=="YES"){
        goto label ;
        }

    }
    //store the data info :
    // write out the data into the file_name :
   
    // file.app
    // Close the file_name :
    file.close();
    
    //  voided :
}

void bookshop::showbook(std::string file_name ){
    std::ifstream  fin ; 
    fin.open("../../dataFiles/"+file_name, std::ios::in);
    // roll number :

    // of which the data is required
    // Read the Data from the file
    // as String Vector
    std::vector<std::string> row;
     std::string line, word, temp;

             std::cout << "Print the found data" << "\n" ;
    while (fin)
     {
        row.clear();
        // read an entire row and
        // store it in a string variable 'line'
        std::getline(fin, line);

        // used for breaking words
        std::stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
  int i = 0 ;
        while (std::getline(s, word, ','))
        {
            // add all the column data
            // std::cout << word << "\t";
            // of a row to a vector
            row.push_back(word);
           
            switch(i){
                case 1 : 
                             std::cout << "Identify Address :" << row[i] << "\n";

        break ;
                case 2 : 
              std::cout << "Name     : " << row[i] << "\n";
        break ;
                case 3: 
             std::cout << "Author   : " << row[i] << "\n";
        break ;
                case 4 :
             std::cout << "Copies   : " << row[i] << "\n";
        break ;

            }
    i++ ;
        }
   
        
     }
    // if(fin.is_open()) 
    //     std::cout << "Record not found\n";
    fin.close();
}
// string to int : 
int str_Interger(std::string &str ) {
    return std::stoi(str) ;
}

void  bookshop::checkbook(std::string file_name  , int chk) {
    std::ifstream fin ;
    int roll ;
    fin.open("../../dataFiles/"+file_name, std::ios::in);
    std::string line , word ;
    std::vector<std::string>  vect ;
    while (!fin.eof()) 
    {
        /* check the details of the roll number : */
        vect.clear() ; 
        std::getline(fin, line);
    // store it in a string variable 'line'

        // used for breaking words
        std::stringstream s(line);
        // store it in a string variable, 'word'
        while (std::getline(s, word, ','))
        {
            // stor a word into the vector
            // std::cout << word << "\n" ; 
            vect.push_back(word) ;
            // catch the  Address number of the book informations  :
            try {
                roll = str_Interger(vect[1]) ;
                
            } catch (std::exception except) {
                std::cerr << "\nException : the Roll Number does not Exist!\n " ; 
                

                // std::cout << except.what() << std::endl ;
            }
            // Print it. :
        }
            try
            {
                if(roll == chk) {
                                    std::cout << "Point_@ :" <<  vect[1] << "\n";
                                    std::cout << "Name     : " << vect[3] << "\n";
                                    std::cout << "Author   : " << vect[2] << "\n";
                                    std::cout << "Copies   : " << vect[4] << "\n";
                                    break ;
                            }
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
   

    }
    fin.close() ;
}
// Modification  the propreties of the book :
void bookshop::modifybook(std::string file_name , std::string new_file ) {

    /* start the operation : */
     bookshop ajout_bksh ;

     std::ifstream fich; // old_file
     std::ofstream fout ; // new_file
  std::string line, someString;
  std::cout << "Enter the Roll Number : " ;
     std::cin >> someString ; 
  fich.open("../../dataFiles/"+file_name);  //The path to your file goes here
  fout.open("../../dataFiles/"+new_file ,  std::ios::app) ;
  while (fich){  //You don't have to ask if the file is open but it's more secure
    while (std::getline(fich , line )){
         if (line.find(someString) != std::string::npos)
        {            
        //         /* code */
        //  std::cout << line << std::endl ;

                  ajout_bksh.addbook(new_file) ;
                   std::cout << "Has been trashed ! \n\n" ;
         //           continue;
         }
         else {
            
             fout << line << std::endl ;
        //     std::cout << "Not Found " ;
        //     continue ;
        }
        
//      

  } // end while

  } //end if
    
    fich.close();

}

// Suppression des proprieties des biblio :: 
void bookshop::deletebook(std::string file_name  , std::string new_file ) {
     /* start the operation : */
     bookshop ajout_bksh ;
     std::ifstream fich;
     std::ofstream fout ;
  std::string line, someString;
  std::cout << "Enter the Roll Number that you wanna delete : " ;
     std::cin >> someString ; 
  fich.open( "../../dataFiles/"+file_name );  //The path to your file goes here
  fout.open("../../dataFiles/"+new_file ,  std::ios::app) ;
  while (fich){  //You don't have to ask if the file is open but it's more secure
    while (std::getline(fich , line )){
         if (line.find(someString) != std::string::npos)
        {            
        //         /* code */
        //  std::cout << line << std::endl ;
                   std::cout << "Has been trashed ! \n\n" ;
                //    continue;
         }
         else {
            
             fout << line << std::endl ;
   
        }
        
//      

  } // end while

  } //end if

    fich.close();
    
}
