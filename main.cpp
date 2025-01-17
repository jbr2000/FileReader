#include <iostream>
#include <fstream> //for File I/O
#include <string>

using namespace std;

int main()
{
char repeat;  
do{
  
  string fileName; //to get the name of the file to open
  string line; //to store a single line of a text file
  fstream fileStream; //to open a file for reading
  int characters=0;
  int lineNum=0;

  cout<<"What file do you want to open? ";
  cin>>fileName;
  fileStream.open(fileName.c_str(), ios::in);
  //STEP 1: open the fileStream for input, using the fileName specified
  
  if(fileStream.is_open()) /*STEP 2: check to see if the fileStream successfully opened*/ 
  {
   
          cout<<fileName<<" opened.\nFILE CONTENTS:\n";
    
    //STEP 3: repeat the following until the end-of-file (eof) has been reached...  
  
   while(fileStream.eof() == false)
   { 
    getline (fileStream, line);
  if (!line.empty()){         
 cout<<line<<endl;
 lineNum = lineNum + 1;
 characters = characters + line.length();
  }

   }
          
          // 3A: read a line from fileStream into the variable line
    // 3B: display the line, followed by an endline
   
    //STEP 4: close the fileStream
  
  }
  else
  {
    cout<<fileName<<" could not be opened.\n";
  
 }
cout<<"METADATA"<<endl<<"File: "<<fileName<<endl<<"Lines: "<<lineNum<<endl<<"Characters: "<<characters<<endl;


cout<<"Analyze another file (y/n)? ";
cin>>repeat;

  
fileStream.close();
}while (repeat == 'y' || repeat =='Y'); 
return 0;
}
