#include <iostream>
#include <cstdlib>
#include<fstream>
#include<ctime>
#include<cmath>

using namespace std;
ofstream fout("walk4.dat");

const int particle_num = 10000;
const int range=200;
const int x_range=100;



double random(){
	return (double)rand() /(double)RAND_MAX	;
	
}



double randomwalk(int yin,int xin, int step_num){

 
  int count[range][x_range] = {};

  srand(time(0));

  for (int i = 0; i < particle_num; i++) {
    int pos = 0;
   
    for (int j = 0; j < step_num; j++) {
    	if(random()>0.5){	
      pos = pos + random(); 
  }	  
      else 
	  
      pos = pos - random();
	  	  
    }
    double interval = 0.01;
   int y_indx= int(pos);
double  pos_frac = pos-y_indx	;
   int x_indx = int(pos_frac/interval);

    
    //1.62
    
    count[y_indx+ range/2][x_indx]= count[y_indx+range/2 ][x_indx] + 1;
  }
  return (double)count[yin][xin]/10000;
}
  
int main(){

  cout<< "Final position vs number of particles:" <<endl;
  for (double j = 0; j <range; j=j+1) {
  	for(double i=0; i<1; i=i+0.2 ){
	  
  	
    
      cout << (j+i - range/2)<<"  " <<randomwalk(j,i,50)<</*" "<<randomwalk(i,100)<<" "<<randomwalk(i,200)<<*/endl;
      fout << (j+i - range/2)<< "  " <<randomwalk(j,i,50)<</*" "<<randomwalk(i,100)<<" "<<randomwalk(i,200)<<*/endl;
    } }
  
  /*for(int i=50; i<=200; i+=50){
  
  cout<<" "<<" "<<" "<<" "<<log(i)<<" "<<randomwalk(100,i)<<endl;
}*/

    return 0;
}



