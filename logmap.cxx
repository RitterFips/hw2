#include <iostream>
#include <fstream>

using namespace std;

int main(){
	double x0 = 0.5;
	double x;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double array[Nend - Nskip]; //erzeugt das Array um die x-Werte zu speichern
	
	ofstream out("output.data");
	
	for(double r=0; r <= 4; r += 0.001){
	   x=x0;
	   for(int i=1; i <= Nskip; i++)
		   x = r*x*(1-x);
	   for(int i=Nskip+1; i <= Nend; i++){
	   		   x = r*x*(1-x);
	   		   //cout << r << "\t" << x << endl;
			   array[i-(Nskip+1)] = x; //die x-Werte werden ins Array eingelesen
   	   }
   	 for(int n = 0; n <= ((Nend-Nskip)-1); n++){
	  out << r << "\t" << array[n] << endl; //die x-Werte werden mit den jeweiligen r-Werten abgespeichert
	 }
	}

	out.close();
	return 0;
}
