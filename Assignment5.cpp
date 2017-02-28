#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

struct Forecast{
  string day;
  int highTemp;
  int lowTemp;
  int humidity;
  int avgWind;
  string avgWindDir;
  int maxWind;
  string maxWindDir;
  double precip;
};

void populateArray(string filename, Forecast forecastData[]);
string lastDayItRained(Forecast forecastData[]);
double totalRainfall(Forecast forecastData[]);
int maxWindspeed(Forecast forecastData[]);
int maxRainfall(Forecast forecastData[]);
int maxTempDifference(Forecast forecastData[]);
Forecast forecastForDay(Forecast forecastData[],string day);


int main(){

  Forecast forecastData[246];
  populateArray("boulderData.txt", forecastData);
  cout << "Last day it rained: " << lastDayItRained(forecastData) << endl;
  cout << "The total rainfall for this period is " << totalRainfall(forecastData) << endl;
  int iMaxWind = maxWindspeed(forecastData);
  cout << "Maximum wind speed: " << forecastData[iMaxWind].maxWind << " mph on " << forecastData[iMaxWind].day << endl;
  int iMaxRain = maxRainfall(forecastData);
  cout << "Maximum rainfall: " << forecastData[iMaxRain].precip << " inches on " << forecastData[iMaxRain].day << endl;
  int iTempDiff = maxTempDifference(forecastData);
  cout << "Maximum temperature difference: " << forecastData[iTempDiff].highTemp - forecastData[iTempDiff].lowTemp << " F on " << forecastData[iTempDiff].day << endl;

  cout << "Enter a date:";
  string date;
  cin >> date;

  Forecast dayForecast = forecastForDay(forecastData,date);

  cout << "Forecast for " << dayForecast.day << ":" << endl;
  cout << "H: " << dayForecast.highTemp << endl;
  cout << "L: " << dayForecast.lowTemp << endl;
  cout << "Humidity: " << dayForecast.humidity << endl;
  cout << "Avg. wind: " << dayForecast.avgWind << endl;
  cout << "Avg. wind direction: " << dayForecast.avgWindDir << endl;
  cout << "Max wind: " << dayForecast.maxWind << endl;
  cout << "Max wind direction: " << dayForecast.maxWindDir << endl;
  cout << "Precipitation: " << dayForecast.precip << endl;

  return 0;
}

void populateArray(string filename, Forecast forecastData[]){
  ifstream inStream;
  inStream.open(filename.c_str());
  if(inStream.fail()){
    cout << "File failed to open" << endl;
    exit(1);
  }

  for(int i = 0; i < 246; i++){
    string str1;
    //day
    bool forecast = true;
    while(forecast){
      string str2;
      getline(inStream,str1,',');
      getline(inStream,str2,',');
      if(str1 == str2){
        //cout << "It happened!" << endl;
        forecastData[i].day = str1;
        forecast = false;
      }
      else{
        getline(inStream,str1);
      }
    }


    //high temp
    getline(inStream,str1,',');
    forecastData[i].highTemp = atoi(str1.substr(2,2).c_str());

    //low temp
    getline(inStream,str1,',');
    forecastData[i].lowTemp = atoi(str1.substr(2,2).c_str());

    //humidity
    getline(inStream,str1,',');
    forecastData[i].humidity = atoi(str1.c_str());

    //avgWind
    getline(inStream,str1,',');
    forecastData[i].avgWind = atoi(str1.c_str());

    //avgWindDir
    getline(inStream,forecastData[i].avgWindDir,',');

    //maxWind
    getline(inStream,str1,',');
    forecastData[i].maxWind = atoi(str1.c_str());

    //maxWindDir
    getline(inStream,forecastData[i].maxWindDir,',');

    //precip
    getline(inStream,str1,',');
    forecastData[i].precip = atof(str1.c_str());

  }
  inStream.close();
}

string lastDayItRained(Forecast forecastData[]){
  for(int i = 245; i != 0; i--){
    if(forecastData[i].precip != 0){
      return forecastData[i].day;
    }
  }
  return "It has not rained";
}

double totalRainfall(Forecast forecastData[]){
  double total = 0.0;

  for(int i = 0; i < 246; i++){
    total += forecastData[i].precip;
  }
  return total;
}

int maxWindspeed(Forecast forecastData[]){
  int max = 0;
  int index;
  for(int i = 0; i < 246; i++){
    if(max < forecastData[i].maxWind){
      max = forecastData[i].maxWind;
      index = i;
    }
  }
  return index;

}

int maxRainfall(Forecast forecastData[]){
  int index = 0;
  double max = 0.0;
  for(int i = 0; i < 246; i++){
    if(max < forecastData[i].precip){
      max = forecastData[i].precip;
      index = i;
    }
  }
  return index;
}

int maxTempDifference(Forecast forecastData[]){
  int max = 0;
  int index = 0;
  for(int i = 0; i < 246; i++){
    if(max < (forecastData[i].highTemp - forecastData[i].lowTemp)){
      max = forecastData[i].highTemp - forecastData[i].lowTemp;
      index = i;
    }
  }
  return index;
}

Forecast forecastForDay(Forecast forecastData[],string day){
  for(int i = 0; i < 246; i++){
    if(forecastData[i].day == day){
      return forecastData[i];
    }
  }
  Forecast null;
  return null;
}
