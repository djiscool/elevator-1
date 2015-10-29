#include <iostream>
#include <vector>
#include <unistd.h>
#include <algorithm>
#include <string>

// Number of floors in the building.
int numFloors = 0;

using std::cin;
using std::cout;
using std::endl;

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

// What floor are you calling the elevator from?
int currentFloor()
{
  int floorCall;
  cout << "What floor are you on? ";
  cin >> floorCall;
  if( floorCall < numFloors+1 && floorCall > 0 )
    {
      return floorCall;
    }
  if( floorCall > numFloors || floorCall < 1 )
    {
      cout << "Please enter a valid floor." << endl;
      return currentFloor();
    }
}

// From your current floor, what direction are you going?
int currentDirection( int floorCall )
{
  char temp;
  int directionCall;
  cout << "What direction are you going? (U/D) ";
  cin >> temp;
  if( toupper( temp ) == 'U' )
    {
      if( floorCall < numFloors )
	{
	  return directionCall = 1; // UP
	}
      if( floorCall == numFloors )
	{
	  cout << "Can't go higher. You are going DOWN." << endl;
	  return directionCall = 2; // DOWN
	}
    }
  if( toupper( temp ) == 'D' )
    {
      if( floorCall > 1 )
	{
	  return directionCall = 2; // DOWN
	}
      if( floorCall == 1 )
	{
	  cout << "Can't go lower. You are going UP." << endl;
	  return directionCall = 1; // UP
	}
    }
  else
    {
      cout << "Please enter a valid direction." << endl;
      return currentDirection( floorCall ); // ERROR
    }
}

// From your floor and direction, which floor would you like to go to?
int currentDesired()
{
  int desiredCall;
  cout << "What floor would you like to go to? ";
  cin >> desiredCall;
  if( elevator.direction == 1 )
    {
    if( desiredCall > elevator.currentFloor )
      {
      if( desiredCall < numFloors+1 )
	{
	  cout << "Returning: " << desiredCall << endl;
	  return desiredCall;
	}
      if( desiredCall > numFloors )
	{
	  cout << "Please enter a valid floor." << endl;
	  return currentDesired(); // ERROR
	}
      }
    if( desiredCall <= elevator.currentFloor )
      {
	cout << "Please enter a floor above you." << endl;
	return currentDesired(); // ERROR
      }
    }
  if( elevator.direction == 2 )
    {
      if( desiredCall < elevator.currentFloor )
	{
	  if( desiredCall > 0 )
	    {
	      return desiredCall;
	    }
	  if( desiredCall < 1 )
	    {
	      cout << "Please enter a valid floor." << endl;
	      return currentDesired(); // ERROR
	    }
	}
      if( desiredCall >= elevator.currentFloor )
	{
	  cout << "Please enter a floor below you." << endl;
	  return currentDesired(); // ERROR
	}
    }
}

int main()
{
  cout << "How many floors? ";
  cin >> numFloors;

  // What floors have called the elevator?
  // What floors do we want to go to?
  bool floors[numFloors];

  // Can only handle one elevator for now.
  int numElevators = 0;
  cout << "How many elevators? ";
  cin >> numElevators;
  int elevators[numElevators];

  int tests = 0;
  cout << "How many tests would you like to perform? ";
  cin >> tests;

  cout << "BEGINNING SIMULATION" << endl;
  sleep( 1 );
  cout << '.' << endl;
  sleep( 1 );
  cout << '.' << endl;
  sleep( 1 );
  cout << '.' << "\n";

  // Default elevator position is floor 1.
  elevator.currentFloor = 1;

  // For as many tests as you like.
  for( int i = 0; i < tests; i++ )
    {
      cout << "Elevator beginning at floor " << elevator.currentFloor << '.' << endl;

      // What floor are you on?
      int floorCall = currentFloor();

      // Elevator wants to go to where the floorCall came from.
      elevator.destinationFloor = floorCall;

      // What direction are you going? (U/D)
      int directionCall = currentDirection( floorCall );

      cout << "Elevator moving from floor " << elevator.currentFloor << " to floor " << elevator.destinationFloor << '.' << endl;

      sleep( 1 );

      // Elevator is now where floorCall came from.
      elevator.currentFloor = elevator.destinationFloor; 

      cout << "Elevator is now on floor " << elevator.currentFloor << '.' << endl;
      
      if( directionCall == 1 )
	{
	  cout << "Elevator will go UP from floor " << elevator.currentFloor << '.' << endl;
	  elevator.direction = 1;
	  sleep( 1 );
	}
      if( directionCall == 2 )
	{
	  cout << "Elevator will go DOWN from floor " << elevator.currentFloor << '.' << endl;
	  elevator.direction = 2;
	  sleep( 1 );
	}

      // What floor would you like to go to?      
      int desiredCall = currentDesired();

      // Elevator wants to go where the new passenger has requested.
      elevator.destinationFloor = desiredCall;
      
      cout << "Elevator moving from floor " << elevator.currentFloor << " to floor " << elevator.destinationFloor << '.' << endl;

      sleep( 1 );

      // Elevator is now where desiredCall is.
      elevator.currentFloor = elevator.destinationFloor;

      cout << "Elevator is now on floor " << elevator.currentFloor << '.' << endl;

      sleep( 1 );

      cout << "END TEST NUMER " << i+1 << '.' << endl;
      cout << "\n";
      
      sleep( 1 );
    }
     
  return 0;
}
