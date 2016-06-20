/* This program is free software. It is developed by Israel Olalla as a product
   contributing to quandl.com.

   This programme is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY, without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#ifndef QUANDL_H_
#define QUANDL_H_
#include <iostream>
#include <fstream>
#include <cpr/cpr.h>
#include <json.hpp>

using namespace std;

class quandl {
	public:
		quandl(){};
		~quandl(){};
		//
		void auth(string code){
			AuthCode = code;
		}

		string getURL(string url) {
			string type = "csv";
			string FileName = "output";
			
			if (url.find("json") != std::string::npos) {
				type = "json";
			}
			return download(url, FileName, type);
		}
		
		//
		string get(string code) {
			//Set optional variables by default
			string order = "asc"; 
			string type = "csv";

			string website = "https://www.quandl.com/api/v3/datasets/" + code 
				+ "." + type + "?sort_order=" + order;
			if(AuthCode.length() == 0){
				cout << "It would appear you are\'nt using an authentication"
				  << " token. Please visit https://www.quandl.com/help/c++"
				  << " or your usage may be limited." << endl;
			} else{
				website += "&api_version=2015-04-09&auth_token=" + AuthCode;
			}

			string FileName;
			int iLength = code.length();
			for (int i=0; i < iLength; i++){
				if(code.substr(i, 1) == "/"){
					FileName = code.substr(i+1, iLength - i -1);
					break;
				}
			}
			return download(website, FileName, type);
		}

		// All parameters are prescribed by users.
		// 1. Quandl code;
		// 2. Ascending/descending order;
		// 3. Start date;
		// 4. End date;
		// 5. Transformation;
		// 6. collapse;
		// 7. Rows;
		// 8. Output type
		// There are 7 optional arguments compared to the one above.
		string get(string code, string order, string StartDate, string EndDate,
			string transformation, string collapse, string rows, string type, string version){

			string website = "https://www.quandl.com/api/v3/datasets/" + code 
				+ "." + type + "?sort_order=" + order;
			if(AuthCode.length() == 0){
				cout << "It appear you are\'nt using an authentication"
				  << " token. Please visit https://www.quandl.com/help/api for getting one"
				  << " ; otherwise your usage may be limited." << endl;
			} else{
				website += "&auth_token=" + AuthCode;
			}

			if (StartDate.size()> 2) website += "&trim_start=" + StartDate;
			if (EndDate.size()> 2) website += "&trim_end=" + EndDate;
			if (transformation.size()> 2) website += "&transformation=" + transformation;
			if (collapse.size()> 2) website += "&collapse=" + collapse;
			if (rows.size()>= 1) website += "&rows=" + rows;
			website += "&api_version=2015-04-09";

			string FileName;
			int iLength = code.length();
			for (int i=0; i < iLength; i++){
				if(code.substr(i, 1) == "/"){
					FileName = code.substr(i+1, iLength - i -1);
					break;
				}
			}

			return download(website, FileName, type);
		}
	private: 
		string AuthCode;
		// Simple, use cpr to download the URL 
		// and save it to a fiel
		string download(string url, string FileName, string type) {
			    try {
					auto response = cpr::Get(cpr::Url{url});
					if (response.status_code != 200) {
						throw std::domain_error( "Error ["+ response.error.message + "] \nError making request to URL: [" + url + "]");
					} else {
						  ofstream myfile;
						  myfile.open (FileName + "." + type);
						  //Let's beautify this :-)
						  if (type == "json") {
						        auto json = nlohmann::json::parse(response.text);
						        myfile << json.dump(4);
						        return json.dump(4);    
						  }
						  // if this is csv let's print it as it comes
						  myfile << response.text;			  
						  myfile.close();
						return response.text;
					}
				} catch (std::exception& e) {
					std::cout << e.what() << '\n';
					throw e;
				}
		}
};

#endif /* QUANDL_H_ */
