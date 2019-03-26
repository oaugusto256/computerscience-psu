#include <iostream>
#include <time.h>

using namespace std;

int main()
{
  
  tm * localTime;
  
  time_t currentTime;
  time( &currentTime );                   // Get the current time
  localTime = localtime( &currentTime );  // Convert the current time to the local time

  int Hour = localTime->tm_hour;
  int Min  = localTime->tm_min;
  int Sec  = localTime->tm_sec;

  cout << "This program was exectued at: " << Hour << ":" << Min << ":" << Sec << endl;
  
  return 0;
}
