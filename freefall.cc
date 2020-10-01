#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include "linspace.c"


double y(double t) {
   double y_result;
   double g = 9.80665; //[m/s^2]
   double h=20;//[m]
   double V0 = 0;


   y_result = V0*t + h - 0.5*g*pow(t,2);

   return (y_result);
}

int main(){
   double h=20;//[m]
   double g = 9.80665; //[m/s^2]
   double V0 = 0;



//Solve quadratic equation to compute the fly time
double t_f = (V0+sqrt(pow(V0,2)+4*0.5*g*h))/(2*0.5*g);

std::vector<double> t = linspace(0., t_f, 24);

//std::cout<<"y[t="<< t << "]="<<y(t)<<std::endl;


std::ofstream file;
file.open("time_pos.dat");
file.precision(6);
std::cout.precision(6);

std::cout<<std::setw(12)<< "t" <<std::setw(12) <<  "y(t)"  <<std::endl;

for(int i=0;i<sizeof(t);++i){

file<<     std::setw(12)<< 2 <<std::setw(12) <<  y(t[i]) <<std::endl;
std::cout<<std::setw(12)<< 2 <<std::setw(12) <<  y(t[i]) <<std::endl;

}



return 0;
}

