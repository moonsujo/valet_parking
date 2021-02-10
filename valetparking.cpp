#include "valetparking.hpp"

#include <iostream>

// ATTENTION STUDENTS:
// THE CONSTRUCTORS ARE ALREADY COMPLETED.
// YOU NEED TO COMPLETE THE DESTRUCTOR AND ALL OF THE REMAINING FUNCTIONS BELOW.

// CONSTRUCTORS - ALREADY COMPLETE
ValetParking::ValetParking() : _numberofstalls( 1 ), _stallcapacity( 1 ), _queuecapacity( 1 ), _currentticket( 0 ),
    _fee( 5.0 ), _paid( 0.0 ), _checkout(new std::queue<size_t>()), _parkingstall(_numberofstalls, std::stack<size_t>() )
{}

ValetParking::ValetParking( size_t numberofstalls, size_t stallcapacity,
    size_t queuecapacity, size_t ticketnumber, double fee ) : _numberofstalls( numberofstalls ), _stallcapacity( stallcapacity ), _queuecapacity( queuecapacity ), _currentticket( ticketnumber ),
    _fee( fee ), _checkout(new std::queue<size_t>()), _parkingstall(_numberofstalls, std::stack<size_t>() ), _paid( 0.0 )
{}

// DESTRUCTOR
ValetParking::~ValetParking()
{

    // ADD YOUR CODE HERE
	//deallocate the checkout queue which is dynamically allocated
	while (_checkout->size() != 0) {
		_checkout->pop();
	}
}

size_t ValetParking::totalStallSpaces()
// return the maximum number of cars that all stalls can accommodate
{
	
    // ADD YOUR CODE HERE
	size_t total = _numberofstalls * _stallcapacity;
	return total;
}

size_t ValetParking::carsInStalls()
// return the number of cars parked in all the stalls
{

    // ADD YOUR CODE HERE
	size_t occupied = 0;
	for (size_t i = 0; i < _parkingstall.size(); i++)
		occupied += _parkingstall[i].size();
	return occupied;
}

size_t ValetParking::carsInCheckOut()
// return the number of cars waiting in checkout line to pay before exiting the lot.
{

    // ADD YOUR CODE HERE
	return _checkout->size();
}

size_t ValetParking::availableStallSpaces()
// return the number of available parking spaces in all the stalls
{

    // ADD YOUR CODE HERE
	return totalStallSpaces() - carsInStalls();
}

double ValetParking::totalSales()
// return the total amount based on the number of tickets issued
{

    // ADD YOUR CODE HERE
	return _paid / _fee;
}

size_t ValetParking::pay()
// remove and return the ticket# of car at front of the checkout queue, and the fee is collected.
{

    // ADD YOUR CODE HERE
	_paid += _fee;
	size_t ticketNum = _checkout->front();
	_checkout->pop();
	return ticketNum;
}

double ValetParking::totalPaid()
// return the total amount customers have paid so far based on the number of cars exited the lot.
{

    // ADD YOUR CODE HERE
	return _paid;
}

bool ValetParking::parkingEmpty()
// return true if all stalls and checkout queue are empty
{

    // ADD YOUR CODE HERE
	bool empty;
	if (_parkingstall.size() == 0 and _checkout->size() == 0)
		empty = true;
	else
		empty = false;
	return empty;
}

bool ValetParking::parkingFull()
// return true if all stalls and checkout queue are full
{

    // ADD YOUR CODE HERE
	if (totalStallSpaces() == carsInStalls() and _checkout->size() == _queuecapacity) {
		return true;
	}
	else
		return false;
}

bool ValetParking::queueEmpty()
// return true if the checkout queue is empty
{

    // ADD YOUR CODE HERE
	return _checkout->size() == 0;
}

bool ValetParking::queueFull()
// return true if the checkout queue is full
{

    // ADD YOUR CODE HERE
	return _checkout->size() == _queuecapacity;
}

bool ValetParking::stallEmpty()
// return true if all stalls are empty
{

    // ADD YOUR CODE HERE
	return availableStallSpaces() == totalStallSpaces();
}

bool ValetParking::stallFull()
// return true if all stalls are full
{

    // ADD YOUR CODE HERE
	return availableStallSpaces() == 0;
}

size_t ValetParking::getNextTicket()
// return the next ticket number to issue to customer
{

    // ADD YOUR CODE HERE
	_currentticket += 1;
	return _currentticket;
}

size_t ValetParking::checkIn()
// on success return stall# (index-1 base), on failure return 0.
{

    // ADD YOUR CODE HERE
	size_t stallNum = 0;
	//loop
	//all stalls
	//then stall capacity
	for (size_t i = 0; i < _numberofstalls; i++) {
		stallNum += 1;
		if (_parkingstall[i].size() == _stallcapacity)
			continue;
		else {
			_parkingstall[i].push(getNextTicket());
			break;
		}
	}
	return stallNum;
				
	//check if stall is occupied
	//if not, assign ticketNum
	//if it is, move to the next one and update the stallNum
	//return stallNum
}

size_t ValetParking::stallNumber( size_t ticket)
// return the stall number (index-1 base) in which the ticket number resides
{

    // ADD YOUR CODE HERE
    	size_t stall = 0;
	bool found = false;
	std::stack<size_t> space;
    	while (!found) {
    		while (_parkingstall[stall].size() != 0) {
			if (_parkingstall[stall].top() == ticket) {
				found = true;
				break;
			} else {
				space.push(_parkingstall[stall].top());
				_parkingstall[stall].pop();
			}
		}
		while (space.size() != 0) {
			_parkingstall[stall].push(space.top());
			space.pop();
		}
		stall += 1;
	}
    return stall;
}

bool ValetParking::checkOut( size_t stallnumber, size_t ticket) 
// Retrieve the ticket# from the stall and place the ticket in the checkout queue.
// On success return true.
{
    // ADD YOUR CODE HERE   
	std::stack<size_t> space;
	//adjust for index-1 base
	stallnumber -= 1;
    	while (_parkingstall[stallnumber].size() != 0) {
		if (_parkingstall[stallnumber].top() == ticket) {
			_parkingstall[stallnumber].pop();
			_checkout->push(ticket);
			break;
		} else {
			space.push(_parkingstall[stallnumber].top());
			_parkingstall[stallnumber].pop();
		}
	}
	while (space.size() != 0) {
		_parkingstall[stallnumber].push(space.top());
		space.pop();
	}
	return true;
}
