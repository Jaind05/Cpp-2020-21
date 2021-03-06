/*
Header filer for Music class
Made by Nividh Singh in October 2020
*/

#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class Music : public Media
{
 private:
  char artist[100];
  char publisher[100];
  double duration;
 public:
 ~Music();
  char* getArtist();
  char* getPublisher();
  double getDuration();
  void setArtist(char* newArtist);
  void setPublisher(char* newPublisher);
  void setDuration(double newDuration);
  void printArtist();
  void printPublisher();
  void printDuration();
};
