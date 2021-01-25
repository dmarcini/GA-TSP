# Genetic Algorithm - Traveling Salesman Problem

Console application that implements Genetic Algorithm 
(GA) algorithm for Traveling Salesman Problem (TSP).

Information about GA (what it is and how it work) you can find on: <br>
https://en.wikipedia.org/wiki/Genetic_algorithm

Information about TSP you can find on: <br>
https://en.wikipedia.org/wiki/Travelling_salesman_problem

The application's menu consists of 4 options:
* load a data from the external file (you should provide your own function
  (overwrite a body of <strong>load_data</strong> function)
  to read the data from this file)
* enter stop criterium (in number of iterations)
* enter algorithm parameters like: <br>
  -- population_size <br>
  -- pk (crossover probability) <br>
  -- pm (mutation probablity) <br>

## Technology
* C++17
* cmake
* make

---

## Requirements
* Operation system: Windows, Linux, macOS
* C++17 compiler
* cmake tool installed
* make tool installed
---

## External library
* utility-library: https://github.com/dmarcini/utility-library.git
---

## Building & Running
Example for Linux system.
* install external libraries:
```
git clone library-github-url
cd path-to-clone-library
mkdir build
cd build
cmake ..
sudo make install
```
* build GA-TSP app
```
git clone https://github.com/dmarcini/GA-TSP.git
cd path-to-clone-directory
mkdir build
cd build
cmake ..
make
```
* run GA-TSP app
```
cd path-to-clone-directory/bin
./GA-TSP
```
For other systems you should update library path to place where
library has been installed, by edit target_link_libraries()
in CMakeLists.txt.
