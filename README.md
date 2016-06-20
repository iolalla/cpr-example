# CPR + Quandl

This code is an example of integration of [cpr](https://github.com/whoshuu/cpr/) and [quandl](https://www.quandl.com/).

Basically you can choose two different flavours:
    - example: example.cpp that basically means to modify this code and adapt it to your needs.
    - quandl: this a console tool designed to make it easy to integrate with other tools, so you can
    use it as it is, so you can integrate the tool and get the files from Quandl into your process.


## Building

This project and C++ Requests both use CMake. The first step is to make sure all of the submodules are initialized:

```
git submodule update --init --recursive
```

Then make a build directory and do a typical CMake build from there:

```
mkdir build
cd build
cmake ..
make
```

This should produce two binaries in the build directory called `example` and `quandl`. Modify [example.cpp](https://github.com/iolalla/cpr-quandl/blob/master/example.cpp) to adapt it to your needs. If you want to use directly `quandl`, here you have some examples:

```
./quandl --ticker "YAHOO/MC_SAN" --order asc --start_date 2014-01-01 --end_date 2014-12-01 --code "<<YOURCODE>>" --rows 1000 --type json
./quandl --ticker "YAHOO/MC_SAN" --code "<<YOURCODE>>"
./quandl --help

    -code (Please visit https://www.quandl.com/help/api to get your code)
      type: string default: ""
    -collapse (Show data collapsed please) type: string default: ""
    -end_date (End Date) type: string default: ""
    -order (asc or desc order) type: string default: "asc"
    -rows (How many rows you want to see) type: string default: "100"
    -start_date (Start Date) type: string default: ""
    -ticker (Please visit https://www.quandl.com/ to get a proper ticker to
      download, it can be smth like YAHOO/MC_SAN) type: string default: ""
    -transformation (Transformation done to the resulting data) type: string
      default: ""
    -type (json/csv) type: string default: "json"
    -url (URL to get) type: string default: ""
```

## Requirements

Obviously will require, git, cmake and a C++11 compatible compiler such as clang or gcc. The minimum required version of gcc is unknown, so if anyone has trouble building this library with a specific version of gcc, do let me know.


## Contributing

Please fork the parent repository and contribute back using [pull requests](https://github.com/iolalla/cpr-quandl/pulls). Features can be requested using [issues](https://github.com/iolalla/cpr-quandl/issues). All code, comments, and critiques are greatly appreciated.

For direct contributions to the example project, you can open [pull requests](https://github.com/iolalla/cpr-quandl/pulls) or [issues](https://github.com/iolalla/cpr-quandl/issues).

## Thanks 

To [whoshuu](https://github.com/whoshuu), for his great code, definetly a great example of c++.

To [quandl](https://www.quandl.com/), for the data they share and the amazing service they provide.
