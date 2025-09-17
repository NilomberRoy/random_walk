#include <iostream>
#include <cstdlib>
#include<fstream>
#include<ctime>
#include<cmath>

using namespace std;
ofstream fout("walk4.dat");

const int particle_num = 100000;
const int range1=100;
const int range2=200;
const int range3=400;

double random(){
	return (double)rand() /(double)RAND_MAX	;
	
}

double randomwalk1(int dis1,int step_num1/*,int step_num2,int step_num3*/){
 
  int count1[range1] = {};
  
 int count2[range2] = {};
  int count3[range3] = {};
  srand(time(0));

  for (int i = 0; i < particle_num; i++) {
    int pos = 0;
   
    for (int j = 0; j < step_num1; j++) {
    	if(random()>0.5){	
      pos = pos + 1; 
  }	  
      else 
	  
      pos = pos - 1;
	  	  
    }
    count1[pos + range1/2] = count1[pos + range1/2] + 1;
}
return (double)count1[dis1];
}

double randomwalk2(int dis2,int step_num2/*,int step_num2,int step_num3*/){
 
  int count1[range1] = {};
  
 int count2[range2] = {};
  int count3[range3] = {};
  srand(time(0));

  for (int i = 0; i < particle_num; i++) {
    int pos = 0;
    
    for (int j = 0; j < step_num2; j++) {
    	if(random()>0.5){	
      pos = pos + 1; 
  }	  
      else 
	  
      pos = pos - 1;
	  	  
    }
    count2[pos + range2/2] = count2[pos + range2/2] + 1;
}
return (double)count2[dis2];
}

double randomwalk3(int dis3,int step_num3/*,int step_num2,int step_num3*/){
 
  int count1[range1] = {};
  
 int count2[range2] = {};
  int count3[range3] = {};
  srand(time(0));

  for (int i = 0; i < particle_num; i++) {
    int pos = 0;
    
    for (int j = 0; j < step_num3; j++) {
    	if(random()>0.5){	
      pos = pos + 1; 
  }	  
      else 
	  
      pos = pos - 1;
	  	  
    }
    count3[pos + range3/2] = count3[pos + range3/2] + 1;
  }
  
  return (double)count3[dis3];
  
  //
  }
  
  
int main(){
cout<< "Final position vs number of particles:" <<endl;

  for (int i = 0; i < range1; i=i+2) {
  	       
      cout << (i - range1/2)<<" :"<<randomwalk1(i,50)*sqrt(50)/particle_num<<endl;
      fout << (i - range1/2)<<" "<<randomwalk1(i,50)*sqrt(50)/particle_num<<endl;
    }
    cout<<endl;
    for (int i = 0; i < range2; i=i+2) {
    cout << (i - range2/2)<<" "	<<randomwalk2(i,100)*sqrt(100)/particle_num<<endl;
    fout << (i - range2/2)<<" "	<<randomwalk2(i,100)*sqrt(100)/particle_num<<endl;
}
    cout<<endl;
  	       for (int i = 0; i < range3; i=i+4) {
    cout << (i - range3/2)<<" "	<<randomwalk3(i,200)*sqrt(200)/particle_num<<endl;
    fout << (i - range3/2)<<" "	<<randomwalk3(i,200)*sqrt(200)/particle_num<<endl;
}
    
  
    return 0;
}


