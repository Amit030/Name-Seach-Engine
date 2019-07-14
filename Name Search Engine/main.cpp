///////////////////////////////////////////////////////////////////////////////
// File Name:      main.cpp
//
// Author:         Amit Sharma
// CS email:       amit030.cse@gmail.com
//
// Description:    The main file for the c++ final project.
///////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <curl/curl.h>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "Data.hpp"

//CurlObj is used to get the html from the given webpage
class CurlObj {
public:
    /**
     * @brief Constructor for a curl object.
     *
     * @param url The url of the page to scrape.
     */
    CurlObj (std::string url) {
        curl = curl_easy_init();
        if (!curl) {
            throw std::string ("Curl did not initialize.");
        }
        
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CurlObj::curlWriter);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curlBuffer);
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_perform(curl);
    };
    
    static int curlWriter(char *data, int size, int nmemb, std::string *buffer) {
        int result = 0;
        if (buffer != NULL) {
            buffer->append(data, size * nmemb);
            result = size * nmemb;
        }
        
        return result;
    }
    
    std::string getData() {
        return curlBuffer;
    }
    
protected:
    CURL * curl;
    std::string curlBuffer;
};
//credit to stack overflow for help on the CurlObj class

int main() {
    
    //the tickers of companies
    std::vector<std::string> names;
    std::string numCompaniesString;
    
    
    
    std::cout << "Scrapting Data started" << std::endl << std::endl;
    
    std::vector<Data> dataObjs;
    
    
    std::string address = "https://www.thehindu.com/opinion/op-ed/Traditional-medicine-threat-to-vultures/article16835233.ece";
    CurlObj temp(address);
    Data *data = new Data("", temp.getData());
    
    std::cout << "Scrapting Data Ended" << std::endl << std::endl;
    try {
        //Data *data = new Data(name, temp.getData());
        data->printData();
    } catch (std::exception e) {
        std::cout << "\n Invalid Output." << std::endl;
    }
    
    
    std::cout << std::endl;
    
    return 0;
}
