///////////////////////////////////////////////////////////////////////////////
// File Name:      Data.cpp
//
// Author:         Amit Sharma
// email:       amit030.cse@gmail.com
//
// Description:    The implementation of Data methods.
///////////////////////////////////////////////////////////////////////////////

#include "Data.hpp"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Data::Data(std::string NAME, std::string HTML) {
    name = NAME;
    //all the html of the website
    html = HTML;
    // fillData();
    
    ofstream file;
    file.open("/Users/amit/WebstormProjects/Webpages.txt");
    if(file.is_open())
    {
        file << "I love tuna and tuna loves me!\n";
        file<<HTML<<endl;
        file.close();
    }
    else{
        cout<< "No file has been created!\n";
    }
}

void Data::fillData() {
    
}

void Data::printData() {
    
}





