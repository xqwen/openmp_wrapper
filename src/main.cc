#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;

int main(int argc, char **argv){
  char script_file[256];
  memset(script_file,0,256);
  int nthread = 1;

  for(int i=1;i<argc;i++){
    
    if(strcmp(argv[i], "-thread")==0 || strcmp(argv[i],"-t")==0 ){
      nthread = atof(argv[++i]);
      continue;
    }
    
    if(strcmp(argv[i],"-f")==0 || strcmp(argv[i],"-d")==0){
      strcpy(script_file,argv[++i]);
      continue;
    }
  }



  if(strlen(script_file)==0)
    exit(0);
  
  ifstream infile(script_file);
  string line;
  vector<string> cmd_vec;
  
  while(getline(infile,line)){
    cmd_vec.push_back(line);
  }

#pragma omp parallel for num_threads(nthread)
  for (int i=0;i<cmd_vec.size();i++){
    system(cmd_vec[i].c_str());
  }
}


  
