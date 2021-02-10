#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include "valetparking.hpp"

// ATTENTION STUDENTS: DO NOT MODIFY THIS FILE TO MAKE YOUR CODE PASS. WE USE THE ORIGINAL FILE
// WHEN GRADING YOUR ASSIGNMENT.

const double TOLERANCE = 0.01;

struct AssertEquals
{
    static size_t passage;
    static size_t passagepassed;
    static size_t tests;
    static size_t passed;

    template <typename T, typename U>
    bool operator() (std::string test_name, const T & expected, const U & actual)
    {
        ++tests;
        if ((actual - expected) < TOLERANCE)
        {
            std::cout << "[PASSED] " << test_name << std::endl;
            ++passed;
            return true;
        } 
        else
        {
            std::cout << "[FAILED] " << test_name
            << " - Expected: " << expected
            << ", Actual: " << actual
            << std::endl;
            return false;
        }
    }
};

AssertEquals assertEquals;
size_t AssertEquals::passage = 0;
size_t AssertEquals::passagepassed = 0;
size_t AssertEquals::tests = 0;
size_t AssertEquals::passed = 0;

void passage_1()
{
    ++assertEquals.passage;
    ValetParking myvalet ;
    double totaltest = 12.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";    
}

void passage_2()
{
    ++assertEquals.passage;
    ValetParking myvalet ;
    double totaltest = 12.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_3()
{
    ++assertEquals.passage;
    ValetParking myvalet ;
    double totaltest = 14.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.stallNumber(1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueFull())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_4()
{
    ++assertEquals.passage;
    ValetParking myvalet ;
    double totaltest = 14.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_5()
{
    ++assertEquals.passage;
    ValetParking myvalet( 3, 2, 2, 0, 5) ;
    double totaltest = 23.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.stallNumber(5)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.stallNumber(2)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.stallNumber(4))
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_6()
{
    ++assertEquals.passage;
    ValetParking myvalet( 3, 2, 6, 0, 5) ;
    double totaltest = 29.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 2)) and //
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(2, 3)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(2, 4)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(3, 5)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(3, 6)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_7()
{
    ++assertEquals.passage;
    ValetParking myvalet( 3, 2, 6, 0, 5) ;
    double totaltest = 45.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 2)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(3, 5)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 4U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(2, 3)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(2, 4)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(3, 6)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 4U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalPaid())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";         
}

void passage_8()
{
    ++assertEquals.passage;
    ValetParking myvalet( 30, 20, 100, 0, 5) ;
    double totaltest = 45.0;
    if  (
        assertEquals( "test " + std::to_string(assertEquals.tests), 600U, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.checkIn()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 594U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 2)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 5)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 4U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 3)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 597U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 4)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 1)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.checkOut(1, 6)) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 2U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 600U, myvalet.availableStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5.0, myvalet.totalPaid()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 5U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 3U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 4U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 1U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 6U, myvalet.pay()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.parkingEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.parkingFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.stallEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.stallFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), true, myvalet.queueEmpty()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), false, myvalet.queueFull()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 600, myvalet.totalStallSpaces()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInStalls()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 0U, myvalet.carsInCheckOut()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalSales()) and
        assertEquals( "test " + std::to_string(assertEquals.tests), 30.0, myvalet.totalPaid())
    )
    ++AssertEquals::passagepassed;
    std::cout << std::fixed << std::setprecision(1)
        << "Passage " << assertEquals.passage << " " << assertEquals.passed/totaltest*100 << " %\n\n";           
}

int main()
{
    assertEquals.passage  = 0;
    assertEquals.passagepassed  = 0;
    assertEquals.tests  = 0;
    assertEquals.passed = 0;

    try {
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_1();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_2();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_3();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_4();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_5();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_6();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_7();
        assertEquals.tests = 1; assertEquals.passed = 0;
        passage_8();

    // Calculate Total Points
    std::cout << "Result: " <<  assertEquals.passagepassed << " out of " << assertEquals.passage << " passed the test." << std::endl;
    std::cout << std::fixed << std::setprecision(1) << std::endl << "Total Points: " 
        << (80.0 / assertEquals.passage) * assertEquals.passagepassed << " / 80 max" << std::endl;
    }

    catch ( const std::range_error & e )
    {
        std::cout << "\nError: " << e.what() << std::endl;
        return 1;
    }

    catch (...)
    {
        std::cout << "\nOther errors occurred." << std::endl;
        return 1;
    }

    return 0;
}
