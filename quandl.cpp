#include <iostream>
#include <gflags/gflags.h>
#include "quandl.hpp"
		// 1. Quandl code;
		// 2. Ascending/descending order;
		// 3. Start date;
		// 4. End date;
		// 5. Transformation;
		// 6. collapse;
		// 7. Rows;
		// 8. Output type
		// 9. Version of the API
DEFINE_string(url, "", "URL to get");
DEFINE_string(ticker, "", "Please visit https://www.quandl.com/ to get a proper ticker to download, it can be smth like YAHOO/MC_SAN");
DEFINE_string(code, "", "Please visit https://www.quandl.com/help/api to get your code");
DEFINE_string(order, "asc", "asc or desc order");
DEFINE_string(start_date, "", "Start Date");
DEFINE_string(end_date, "", "End Date");
DEFINE_string(transformation, "", "Transformation done to the resulting data");
DEFINE_string(collapse, "", "Show data collapsed please");
DEFINE_string(rows, "100", "How many rows you want to see");
DEFINE_string(type, "json", "json/csv");
DEFINE_string(quandl_version, "2015-04-09", "Version of the API, please visit https://www.quandl.com/help/api for further information");

int main(int argc, char** argv) {
	
    try {
    	
    	gflags::ParseCommandLineFlags(&argc, &argv, true);
    	
    	//gets the 
    	if (FLAGS_url.size() > 5) {
    		quandl ql;
    		//std::cout << FLAGS_url << endl;
    		std::string content = ql.getURL(FLAGS_url);
    		std::cout << content << endl;
    		return 0;
    	} else if (FLAGS_ticker.size() > 5 & FLAGS_code.size() >3) {
    		quandl ql;
			ql.auth(FLAGS_code);
			std::string content = ql.get(FLAGS_ticker,FLAGS_order, 
				FLAGS_start_date, FLAGS_end_date, FLAGS_transformation, 
				FLAGS_collapse, FLAGS_rows,FLAGS_type, FLAGS_quandl_version);
    		std::cout << content << endl;
    	} else {
    		std::cerr << "Need at least two arguments ticker and code \n" <<std::endl;
    	}

    } catch (std::exception& e) {
    	std::cout << e.what() << '\n';
    }
}
