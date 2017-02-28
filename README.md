# BoulderWeather


~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
* Created by Theodore Champ             *
* Last Update: February 28th, 2017      *
* Created for CSCI 1310 at CU Boulder   *
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Purpose: This program takes an input file of weather data and parses through it,
saving the data in an array of type Forecast. It then output significant information
from this data.

Running: This program is currently uncompiled, thus must be run through a c++ compiler.
Although all compilers should work, a C++11 compiler like g++ is recommended and was used
to test the program.

Warning: This program is not dynamic in it's current state. That means that the only file
it can read successfully is the boulderData.txt file that is included in the repository.
Even if another file were created of the same format, it would not work because the file must
have 246 data points.

TODO: Make dynamic by using vectors rather than arrays
      Implement accuracy of forecasts.
