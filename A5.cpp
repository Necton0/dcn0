#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

bool isAckRec(){
  return rand() % 10 < 7;
}

void goBackN(int frames, int windowSize){
  int base = 0;
  int nextSeqNum = 0;
  
  while(base<frames){
    cout<<endl;
    while(nextSeqNum < base + windowSize && nextSeqNum < frames){
      cout<<"Sending Frame "<<nextSeqNum<<endl;
      nextSeqNum++;
    }
    
    bool allAck = true;
    
    for(int i = base; i < nextSeqNum; i++){
      if( isAckRec() ){
        cout<<"\nAck for Frame "<<i<<" Received";
        base = i + 1;
      }
      else{
        cout<<"\nFrame "<<i<<" lost";
        cout<<"\n...Resending frames...\n";
        nextSeqNum = base;
        allAck = false;
        break;
      }
    }
    
    if(allAck && base!=frames) cout<<"\nWindow moved forward\n";
  }
  
  cout<<"\n...All frames Received...";
}

void selectiveRepeat(int frames, int windowSize){
  int base = 0;
  bool ack[100] = {false};
  
  while (base < frames){
   
    for(int i = base; i < (base + windowSize) && i<frames; i++ ){
      if(!ack[i]){
        cout<<"\nSending frame "<<i;
        if(isAckRec()){
          cout<<"\nAck for frame "<<i<<" Received";
          ack[i] = true;
        }
        else{
          cout<<"\nAck for frame "<<i<<" lost";
        }
      }
    }
    
    while(ack[base] && base < frames){
      base++;
    }
    
    cout<<"\n...Resending lost if any...\n"; 
  }
  cout<<"\nAll frames received successfully";
}

int main(){
  srand(time(0));
  selectiveRepeat(10, 4);
  
  return 0;
}

