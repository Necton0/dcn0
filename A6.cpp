#include<iostream>
#include<bitset>
#include<string>
#include<cmath>
using namespace std;

string intToBinary(unsigned int num){
  bitset <8> binary (num);
  return binary.to_string();
}

void binaryIP(int ip[]){
  cout<<"\nIP in Binary: ";
  for(int i=0; i<4; i++){
    cout<<intToBinary(ip[i]);
    if(i != 3){
      cout<<".";
    }
  }
}

void subnetMask(int ip[], int cidr){
  cout<<"\nSubnet Mask: ";
  for(int i=0; i<4; i++){
    if(cidr >= 8){
      cout<<255;
      cidr -= 8;
    }
    else if(cidr>0){
      cout<<255-pow(2,(8-cidr));
      cidr=0;
    }
    else{
      cout<<0;
    }
    
    if(i!=3){  
      cout<<".";
    }
    
  }
}

void binarySubnetMask(int ip[], int cidr){
  cout<<"\nBinary Subnet Mask: ";
  int temp;
  for(int i=0; i<4; i++){
    if(cidr >= 8){
      temp = 255;
      bitset <8> binary(temp);
      cout<<binary.to_string();
      cidr -= 8;
    }
    else if(cidr>0){
      int temp = 255-pow(2,(8-cidr));
      bitset <8> binary(temp);
      cout<<binary.to_string();
      cidr=0;
    }
    else{
      temp = 0;
      bitset <8> binary(temp);
      cout<<binary;
    }
    
    if(i!=3){  
      cout<<".";
    }
    
  }
}

void networkAddress(int ip[], int cidr){
  cout<<"\nNetwork  Address: ";
  for(int i=0; i<4; i++){
    if(cidr>=8){
      cout<<ip[i];
      cidr -= 8;
    }
    else{
    cout<<0;
    }
    
    if(i != 3){
      cout<<".";
    }
  }
}

void binaryNetworkAddress(int ip[], int cidr){
  cout<<"\nNetwork  Address: ";
  for(int i=0; i<4; i++){
    if(cidr>=8){
      bitset <8> binary (ip[i]);
      cout<<binary.to_string();
      cidr -= 8;
    }
    else{
      bitset <8> binary (0);
      cout<<binary.to_string();
    }
    
    if(i != 3){
      cout<<".";
    }
  }
}

int main(){
  int ip[4];
  int cidr;
  cout<<"\nEnter the IP address: ";
  for(int i=0; i<4; i++){
    cin>>ip[i];
  }
  cout<<"\nEnter the CIDR: ";
  cin>>cidr;
  
  binaryIP(ip);
  subnetMask(ip, cidr);
  binarySubnetMask(ip, cidr);
  networkAddress(ip, cidr);
  binaryNetworkAddress(ip, cidr);
  cout<<endl;
  
  return 0;
}
