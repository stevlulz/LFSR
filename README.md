# Project Title

A simple implementation for LFSR


### Prerequisites


```
C++ compiler (g++)
```


## Built With

* [CMake](https://cmake.org/) 

## cmakeFile
    #Create a txt file named CMakeLists.txt 
    #fill it with the next lines
    
    cmake_minimum_required(VERSION 3.9)
    project(LinearFeedbackShiftRegister)
    
    set(CMAKE_CXX_STANDARD 11)
    
    add_executable(LinearFeedbackShiftRegister main.cpp lfsr/LFSR.cpp lfsr/LFSR.h)
## building the project
    instruction is provided in official cmake's website just follow them 
    https://cmake.org/cmake-tutorial/
 

## Authors

* **Seyyidahmed Lahmer**



## Acknowledgments

* Hat tip to my teacher Mohamed Slimane

