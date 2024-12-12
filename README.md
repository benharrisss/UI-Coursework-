Team Members:
- Ben Harris (201714671)
- Jacob Onion (201710645)
- Fred Mallory-Bains ()
- Yitzchak Kupinsky ()
- Yiwen Jin ()

Project Overview:
The Water Tool application interprets and uses a water quality dataset, and it does this through 4 pages, a Pollutant Overview page, a POPs page, a Litter Indicator page and a Flourinated Components page, these pages make detailed dynamic graphs out of the dataset.

Setup Instructions:
Set up the build process with

    mkdir build && cd build && cmake ..

Build the application with

    make watertool

or just `make` by itself.

Run the application with

    ./watertool
    
Dependencies:
all in the CMakeLists.txt

File Structure:
Solution/
  CMakeLists.txt
  csv.hpp
  dataset.cpp
  dataset.hpp
  fchart.cpp
  fchart.hpp
  main.cpp
  model.cpp
  model.hpp
  myapp_de.ts
  myapp_es.ts
  myapp_fr.ts
  overviewPage.cpp
  overviewPage.hpp
  pchart.cpp
  pchart.hpp
  stats.cpp
  stats.hpp
  water.cpp
  water.hpp
  window.cpp
  window.hpp
  
Known issues:
No known issues
