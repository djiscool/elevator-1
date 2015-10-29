#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <string>

int numFloors = 0; // Number of floors in the building.

using std::cin;
using std::cout;
using std::endl;

//using namespace std;

enum Direction
  {
    IDLE = 0,
    UP = 1,
    DOWN = 2,
  };

struct elevator
{
  int currentFloor;
  int destinationFloor;
  int direction;
} elevator; 

int currentCall()
{
  int floorCall;
  cout << "What floor are you on? ";
  cin >> floorCall;
  if( floorCall > numFloors || floorCall < 1 )
    {
      cout << "Please enter a valid floor." << endl;
      currentCall();
    }
  return floorCall;
}

int currentDirection( int floorCall )
{
  char temp;
  int directionCall = 0; // IDLE
  cout << "What direction are you going? (U/D) ";
  cin >> temp;
  if( toupper( temp ) == 'U' && floorCall == numFloors )
    {
      cout << "Can't go any higher. You are going DOWN." << endl;
      return directionCall = 2; // DOWN
    }
  if( toupper( temp ) == 'U' && floorCall < numFloors )
    {
      return directionCall = 1; // UP
    }
  if( toupper( temp ) == 'D' && floorCall == 1 )
    {
      cout << "Can't go any lower. You are going UP." << endl;
      return directionCall = 1; // UP
    }
  if( toupper( temp ) == 'D' && floorCall > 1 )
    {
      return directionCall = 2; // DOWN
    }
  if( toupper( temp ) != 'U' || toupper( temp ) != 'D' )
    {
      cout << "Please enter a valid direction." << endl;
      currentDirection( floorCall );
    }
}

int currentDesired()
{
  int desiredFloor = elevator.currentFloor;;
  cout << "What floor would you like to go to? ";
  cin >> desiredFloor;
  /*if( desiredFloor == elevator.currentFloor )
    {
      cout << "You so silly." << endl;
      currentDesired();
      }*/
  if( elevator.direction == 1 && desiredFloor > elevator.currentFloor )
    {
      return desiredFloor;
      //cout << "Please enter a floor above you." << endl;
      //currentDesired( desiredFloor );
    }
  if( elevator.direction == 2 && desiredFloor < elevator.currentFloor )
    {
      return desiredFloor;
      //cout << "Please enter a floor below you." << endl;
      //currentDesired( desiredFloor );
    }
  else
    {
      cout << "invalid." << endl;
      currentDesired();
    }
}

int main()
{
  cout << "How many floors? ";
  cin >> numFloors;
  bool floors[numFloors];

  int numElevators = 0;
  cout << "How many elevators? ";
  cin >> numElevators;
  int elevators[numElevators];

  int tests = 0;
  cout << "How many tests do you want to perform? ";
  cin >> tests;

  cout << "BEGINNING SIMULATION" << endl;
  sleep( 1 );
  cout << '.' << endl;
  sleep( 1 );
  cout << '.' << endl;
  sleep( 1 );
  cout << '.' << "\n";

  // Do this for as many tests as you want.

  elevator.currentFloor = 1;

  cout << "Elevator beginning at floor " << elevator.currentFloor << '.' <<endl;

  for( int i = 0; i < tests; i++ )
    {
      int floorCall = currentCall(); // What floor you on?
      int directionCall = currentDirection( floorCall ); // What direction?
      int desiredCall;      

      elevator.destinationFloor = floorCall;
      
      cout << "Elevator going to floor " << elevator.destinationFloor << " from floor " << elevator.currentFloor << '.' << endl;

      elevator.currentFloor = elevator.destinationFloor; 
      sleep( 1 );
      
      cout << "Elevator now at floor " << elevator.currentFloor << '.' << endl;
      
      if( directionCall == 1 )
	{
	  sleep( 1 );
	  cout << "Elevator going UP from floor " << elevator.currentFloor << '.' << endl;
	  elevator.direction = 1;
	  desiredCall = currentDesired();
	  sleep( 1 );
	}
      if( directionCall == 2 )
	{
	  sleep( 1 );
	  cout << "Elevator going DOWN from floor " << elevator.currentFloor << '.' << endl;
	  elevator.direction = 2;
	  desiredCall = currentDesired();
	  sleep( 1 );
	}
      
      elevator.destinationFloor = desiredCall;

      cout << "Elevator going to floor " << elevator.destinationFloor << '.' << endl;

      elevator.currentFloor = elevator.destinationFloor;

      cout << "\n";
    }
     
  //floors[floorCall] = true;
  
  return 0;
}
