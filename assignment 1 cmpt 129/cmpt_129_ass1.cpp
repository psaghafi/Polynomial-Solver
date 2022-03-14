#include <iostream>

#include <cmath>

#include <iomanip>

#include <fstream>

#include <string>

#include <cstdlib>

using namespace std;

fstream myStream;
int MAX_ITERATION = 50;

double poly(double coef1, double coef2, double coef3, double coef4, double coef5, double x)

{

       return ((((coef1*x + coef2)*x + coef3)*x + coef4)*x + coef5);

}

double EPS = 0.000001;

void bisection_method(double l, double u, double coef1, double coef2, double coef3, double coef4, double coef5)

{
       int counter = 0;
	   cout << setw(13)<< fixed << setprecision(6) << l;
       cout << setw(13)<< fixed << setprecision(6) << u;
       cout << setw(13) << fixed << setprecision(6) << (l + u) / 2;
       cout << setw(13);
       myStream << "  Interval Start      P(x) Start    Interval End        P(x) End        Midpoint     P(Midpoint)Iteration#" << endl; 
	   
       

       if (poly(coef1, coef2, coef3, coef4, coef5, l) *poly(coef1, coef2, coef3, coef4, coef5, u) > 0.0)

       {

              cout << "-------------ERROR:  no roots in the interval" << endl;
              counter++;
        myStream << setw(16) << fixed << setprecision(6) << l;
               myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, l);
       myStream << setw(16) << fixed << setprecision(6) << u;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, u);
       myStream << setw(16)<< fixed << setprecision(6) << (l + u) / 2;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, (l+u)/2);
       myStream << setw(10)<< fixed << setprecision(6) << counter <<endl;


              myStream << "ERROR: no roots in the interval" << endl;

              return;

       }

       else if (poly(coef1, coef2, coef3, coef4, coef5, l) *poly(coef1, coef2, coef3, coef4, coef5, u) == 0.0)

       {
              counter++;
              cout << setw(13)<< l;

              cout << setw(5)<< counter << endl;

               myStream << setw(16) << fixed << setprecision(6) << l;
               myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, l);
       myStream << setw(16) << fixed << setprecision(6) << u;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, u);
       myStream << setw(16)<< fixed << setprecision(6) << (l + u) / 2;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, (l+u)/2);
       myStream << setw(10)<< fixed << setprecision(6) << counter <<endl;
              return;

       }

       double mid = l;

       while (u - l > EPS)

       {
         counter++;
         myStream << setw(16) << fixed << setprecision(6) << l;
               myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, l);
       myStream << setw(16) << fixed << setprecision(6) << u;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, u);
       myStream << setw(16)<< fixed << setprecision(6) << (l + u) / 2;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, (l+u)/2);
       myStream << setw(10)<< fixed << setprecision(6) << counter <<endl;

              mid = (l + u) / 2;

              if (poly(coef1, coef2, coef3, coef4, coef5, mid) == 0)

              {

                    break;

              }

              else if ((poly(coef1, coef2, coef3, coef4, coef5, l)*poly(coef1, coef2, coef3, coef4, coef5, mid)) < 0)

              {

                    u = mid;

              }

              else l = mid;
 

              if (counter > MAX_ITERATION)

              {

                    cout << "-------------ERROR: did not converge" << endl;
					myStream << "ERROR: did not converge" << endl;
                    return;

              }

       }

       if(u - l <= EPS) counter++;


       cout << setw(13)<< mid;

       cout << setw(5)<< counter << endl;

 
      if (poly(coef1, coef2, coef3, coef4, coef5, mid) != 0) {
       myStream << setw(16) << fixed << setprecision(6) << l;
               myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, l);
       myStream << setw(16) << fixed << setprecision(6) << u;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, u);
       myStream << setw(16)<< fixed << setprecision(6) << (l + u) / 2;
       myStream << setw(16)<< fixed << setprecision(6) <<  std::scientific <<poly(coef1, coef2, coef3, coef4, coef5, (l+u)/2);
       myStream << setw(10)<< fixed << setprecision(6) << counter <<endl;
      }

}

 

 

int main() {

       //declare variables

       double coef1, coef2, coef3, coef4, coef5, intervalEndMin, intervalEndMax, intervalShift, numRows;

       int numoferr1, numoferr2, numoferr3, numoferr4, numoferr5, numoferr6, numoferr7, numoferr8, numoferr9;

 

       string myFileName;

       //initialize variables

       coef1 = 0;

       coef2 = 0;

       coef3 = 0;

       coef4 = 0;

       coef5 = 0;

       numoferr1 = 0;

       numoferr2 = 0;

       numoferr3 = 0;

       numoferr4 = 0;

       numoferr5 = 0;

       numoferr6 = 0;

       numoferr7 = 0;

       numoferr8 = 0;

       numoferr9 = 0;

       intervalEndMin = 0;

       intervalEndMax = 0;

       intervalShift = 0;

       numRows = 0;

 

 

       //check to see if the first coefficient lies between -50 and 50

 

 

       cout << "Please enter the value of the coefficient for the order 4 term\n(-50.0 <= coefficient <= 50.0): ";

       cin >> coef1;

       while (coef1 <= -51 || coef1 >= 51)

       {

              if (numoferr1 != 3 && (coef1 <= -51 || coef1 >= 51))

              {

                    numoferr1++;

                    cout << "ERROR: The value of the order 4 term is out of range" << endl;

                    cout << "Please re-enter the value of the coefficient for the order 4 term\n(-50.0 <= coefficient <= 50.0): ";

                    cin >> coef1;

 

              }

              else

              {
				    cout << "ERROR: The value of the order 4 coefficient is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;

                    return 0;

              }

       }

 

       //check to see if coefficient 2 is between -50 and 50

       cout << "Please enter the value of the coefficient for the order 3 term\n(-50.0 <= coefficient <= 50.0): ";

       cin >> coef2;

       while (coef2 <= -51 || coef2 >= 51)

       {

              if (numoferr2 != 3 && (coef2 <= -51 || coef2 >= 51))

              {

                    numoferr2++;

                    cout << "ERROR: The value of the order 3 term is out of range" << endl;

                    cout << "Please re-enter the value of the coefficient for the order 3 term\n(-50.0 <= coefficient <= 50.0): ";

                    cin >> coef2;

 

              }

              else

              {
					cout << "ERROR: The value of the order 3 coefficient is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;

                    return 0;

              }

       }

 

       cout << "Please enter the value of the coefficient for the order 2 term\n(-50.0 <= coefficient <= 50.0): ";

       cin >> coef3;

       while (coef3 <= -51 || coef3 >= 51)

       {

              if (numoferr3 != 3 && (coef3 <= -51 || coef3 >= 51))

              {

                    numoferr3++;

                    cout << "ERROR: The value of the order 2 term is out of range" << endl;

                    cout << "Please re-enter the value of the coefficient for the order 2 term\n(-50.0 <= coefficient <= 50.0): ";

                    cin >> coef3;

 

              }

              else

              {
				    cout << "ERROR: The value of the order 2 coefficient is out of range" << endl;

                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;

                    return 0;

              }

       }

 

 

       cout << "Please enter the value of the coefficient for the order 1 term\n(-50.0 <= coefficient <= 50.0): ";

       cin >> coef4;

       while (coef4 <= -51 || coef4 >= 51)

       {

              if (numoferr4 != 3 && (coef4 <= -51 || coef4 >= 51))

              {

                    numoferr4++;

                    cout << "ERROR: The value of the order 1 term is out of range" << endl;

                    cout << "Please re-enter the value of the coefficient for the order 1 term\n(-50.0 <= coefficient <= 50.0) : ";

                    cin >> coef4;

 

              }

              else

              {
				    cout << "ERROR: The value of the order 1 coefficient is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded.Program terminating." << endl;

                    return 0;

              }

       }

 

       cout << "Please enter the value of the coefficient for the order 0 term\n(-50.0 <= coefficient <= 50.0): ";

       cin >> coef5;

       while (coef5 <= -51 || coef5 >= 51)

       {

              if (numoferr5 != 3 && (coef5 <= -51 || coef5 >= 51))

              {

                    numoferr5++;

                    cout << "ERROR: The value of the order 0 term is out of range" << endl;

                    cout << "Please re-enter the value of the coefficient for the order 0 term\n(-50.0 <= coefficient <= 50.0): ";

                    cin >> coef5;

 

              }

              else

              {
					cout << "ERROR: The value of the order 0 coefficient is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;

                    return 0;

              }

       }

 

       cout << "Please enter the minimum X value in the initial range\n(-60.0 <= minimum X value in the initial range <= 60.0): ";

       cin >> intervalEndMin;

       while (intervalEndMin <= -61 || intervalEndMin >= 61)

       {

              if (numoferr6 != 3 && (intervalEndMin <= -61 || intervalEndMin >= 61))

              {

                    numoferr6++;

                    cout << "ERROR: The value of the minimum X value in the initial range is out of range" << endl;

                    cout << "Please re-enter the minimum X value in the initial range\n(-60.0 <= minimum X value in the initial range <= 60.0): ";

                    cin >> intervalEndMin;

 

              }

              else

              {
					cout << "ERROR: The value of the minimum X value in the initial range is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded.Program terminating." << endl;

                    return 0;

              }

       }

 

       cout << "Please enter the maximum X value in the initial range\n(-60.0 <= maximum X value in the initial range <= 60.0): ";

       cin >> intervalEndMax;

       while (intervalEndMax <= -61 || intervalEndMax >= 61)

       {

              if (numoferr7 != 3 && (intervalEndMax <= -61 || intervalEndMax >= 61))

              {

                    numoferr7++;

                    cout << "ERROR: The value of the maximum X value in the initial range is out of range" << endl;

                    cout << "Please re-enter the maximum X value in the initial range\n(-60.0 <= minimum X value in the initial range <= 60.0): ";

                    cin >> intervalEndMax;

 

              }

              else

              {
					cout << "ERROR: The value of the maximum X value in the initial range is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;

                    return 0;

              }

       }

 

       cout << "Please enter the number of rows in the table\n(1 <= number of rows in the table <= 25): ";

       cin >> numRows;

       while (numRows <= 0 || numRows >= 26)

       {

              if (numoferr8 != 3 && (numRows <= 0 || numRows >= 26))

              {

                    numoferr8++;

                    cout << "ERROR: The value of the number of rows in the table is out of range" << endl;

                    cout << "Please re-enter the number of rows in the table\n(1 <= number of rows in the table <= 25): ";

                    cin >> numRows;
              }
              else
              {
					cout << "ERROR: The value of the number of rows in the table is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded.Program terminating." << endl;
                    return 0;

              }

       }

       //recieving the input from the user regarding the interval shift between the rows

       cout << "Please enter the shift of the starting interval between rows\n(0.0 <= shift of starting interval between rows <= 20.0): ";

       cin >> intervalShift;

       //now checking to see if the number of interval shifts is within the range

       while (intervalShift <= -1 || intervalShift >= 21)

       {

              //if it isn't in the range then it'll display the error to the user

              if (numoferr9 != 3 && (intervalShift <= -1 || intervalShift >= 21))

              {

                    numoferr9++;
                    cout << "ERROR: The value of the shift of the starting interval between rows is out of range" << endl;

                    cout << "Please re-enter the shift of the starting interval between rows\n(0.0 <= shift of starting interval between rows <= 20.0): ";

                    cin >> intervalShift;
              }
              //if the user makes the mistake more than 4 times then the program will terminate
              else
              {
					cout << "ERROR: The value of the shift of the starting interval between rows is out of range" << endl;
                    cout << "Maximum number of tries entering data exceeded. Program terminating." << endl;
                    return 0;
              }
       }

       //now to ask the user for the input file
       cout << "Enter the name of the output file ";
       cin >> myFileName;

       //if the output file doesn't open properly it'll display an error

       myStream.open(myFileName, ios::out);

       if (myStream.fail())

       {
          cout << "unable to open output file" << endl;
          return 1;
       }

	   cout << setw(13) << right << "intEndMin";
	   cout << setw(13)<< "intEndMax";
	   cout << setw(13)<< "midpoint";
	   cout << setw(13) << "root";
	   cout << setw(5)<< "N" << endl;
	  

       for (int i = 0; i < numRows; i++)
       {
        bisection_method(intervalEndMin, intervalEndMax, coef1, coef2, coef3, coef4, coef5);
        intervalEndMin = intervalEndMin + intervalShift;
        intervalEndMax = intervalEndMax + intervalShift;
        myStream<< endl << endl << endl << endl;


       }
       myStream.close();
       return 0;
}