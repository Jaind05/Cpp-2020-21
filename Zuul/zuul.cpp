
#include<cstring>
#include<iostream>
#include<vector>
#include<iterator>

#ifndef ROOMS_H
#define ROOMS_H
#include "rooms.h"
#endif

using namespace std;

struct personInfo {
  rooms* currentRoom = new rooms();
  vector<char*>* inventoryItems;
  char* input;
};

char* getFirstWord(char* input);//Returns first word from the input
char* getSecondWord(char* input);//Returns second word from the input
int getFirst(char* firstWord);//Gets a number value for what command the user put for the first word
void INVENTORY(personInfo* myInfo);//Prints inventory items
void PICK(personInfo* myInfo);
void DROP(personInfo* myInfo);
void GO(personInfo* myInfo);

int main()
{

  char title[3][3] = {
    {'a', 'a', '\0'},
    {'b', '\0'},
    {'c', '\0'}
  };
  
  char* egTitle = new char[100];
  rooms* sittingRoom1 = new rooms();
  strcpy(egTitle, "Sitting Room");
  sittingRoom1->setTitle(egTitle);
  
  personInfo* myInfo = new personInfo();
  myInfo->inventoryItems = new vector<char*>;
  cout << "Start" << endl;
  char* input = new char[101];
  //cin.get(input, 100);
  //cin.get();
  char* firstWord = new char();
  firstWord = getFirstWord(input);
  //cout << firstWord << endl;
  char* secondWord = new char();
  secondWord = getSecondWord(input);
  //cout << secondWord << endl;
  //INVENTORY(myInfo);
}

void GO(personInfo* myInfo) {
  
}

void PICK(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* roomItems = myInfo->currentRoom->getItems();
  vector<char*>:: iterator roomIterator;
  cout << "You have the following items: \n";
  for(roomIterator = roomItems->begin(); roomIterator < roomItems->end(); roomIterator) {
    if(strcmp((*roomIterator), item) == 0) {
      myInfo->inventoryItems->push_back(item);
      myInfo->currentRoom->deleteItem(item);
      return;
    }
  }
  
  

}

void DROP(personInfo* myInfo) {
  char* item = getSecondWord(myInfo->input);
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    if(strcmp((*inventoryIterator), item) == 0) {
      myInfo->currentRoom->addItem(item);
      myInfo->inventoryItems->erase(inventoryIterator);
      return;
    }
  }
  cout << "Item not found\n";
}


void INVENTORY(personInfo* myInfo) {
  vector<char*>* inventoryItems = myInfo->inventoryItems;
  vector<char*>:: iterator inventoryIterator;
  cout << "You have the following items: \n";
  for(inventoryIterator = inventoryItems->begin(); inventoryIterator < inventoryItems->end(); inventoryIterator++) {
    cout << (*inventoryIterator) << endl;
  }
}

int getFirst(char* firstWord) {
  if (strcmp(firstWord, "INVENTORY") == 0) {
    return 0;
  }
  else if (strcmp(firstWord, "DROP") == 0) {
    return 1;
  }
  else if (strcmp(firstWord, "PICK") == 0) {
    return 2;
  }
  else if (strcmp(firstWord, "GO") == 0) {
    return 3;
  }
  else if (strcmp(firstWord, "QUIT") == 0) {
    return 4;
  }
  return 5;
}

char* getFirstWord(char* input) {
  char* firstWord = new char[100];
  for (int i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
      firstWord[i] = input[i];
    }
    else {
      firstWord[i] = '\0';
      return firstWord;
    }
  }
  firstWord[strlen(input)] = '\0';
  return firstWord;
}

char* getSecondWord(char* input) {
  char* secondWord = new char[100];
  int i;
  for(i = 0;(input[i] != ' ') && (i < strlen(input)); i++) {
  }
  for(int count = i + 1; count < strlen(input); count++) {
    if(input[count] != ' ') {
      secondWord[count - i - 1] = input[count];
    }
    else {
      secondWord[count+1] = '\0';
      return secondWord;
      
    }
  }
  secondWord[strlen(input)] = '\0';
  return secondWord;
}
