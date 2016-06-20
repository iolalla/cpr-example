#include <iostream>
#include <cpr/cpr.h>
#include <json.hpp>
/* This program is free software. It is developed by Israel Olalla as a product
   contributing to quandl.com.

   This programme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY, without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   
   The objective of this class is to demostrate how simple is to use the cpr 
   software.
*/
int main(int argc, char** argv) {
	// Set up your own URL, modify it to the right datasource, stock, format(csv|json)
	// and obviously the auth_token to your own code, if you have doubts 
	// visit  https://www.quandl.com/help/api 
    std::string url = "https://www.quandl.com/api/v3/datasets/YAHOO/MC_SAN.json";
    url += "?api_version=2015-04-09";
    url += "&sort_order=desc";
    url += "&auth_token=<<YOUROWNCODE>>"; //please visit to get your own auth code
    url += "&rows=10";
    
    try {
    	auto response = cpr::Get(cpr::Url{url});
    	if (response.status_code != 200) {
    		throw std::domain_error( "Error ["+ response.error.message + 
    			"] \nError making request to URL: [" + url + "]");
    	} else {
    		auto json = nlohmann::json::parse(response.text);
    		std::cout << json.dump(4) << std::endl;
    	}
    } catch (std::exception& e) {
    	std::cout << e.what() << '\n';
    }
}