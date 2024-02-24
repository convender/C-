// P05CircularBufferDriver.cpp -- starter code
//Marcos Garnica
//CS318 P05
//to make a circular buffer, when full and wanting to put in something new
//it will overwrite the oldest infomration i.e. head

/*  REQUIREMENTS NOTES:

    Fill in the remainder of this driver program.
    Replicate exactly the sample run provided with project's specs.
    Use a capacity of 5

*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "circular_buffer.h"
#include "dog.h"

using namespace std;

int main() {
    cout << "\n*************** <int> Circular Buffer Demo ******************\n";
    //  FINISH THIS SECTION
    CircularBuffer<int, 5> buffer;
    //int userNumber;
    cout << "Initial state\n";
    cout << buffer << endl << endl;

    cout << "Pushing 0\n";
    buffer.push_back(0);
    cout << buffer << endl << endl;

    cout << "Pushing 10\n";
    buffer.push_back(10);
    cout << buffer << endl << endl;

    cout << "Pushing 20\n";
    buffer.push_back(20);
    cout << buffer << endl << endl;

    cout << "Pushing 30\n";
    buffer.push_back(30);
    cout << buffer << endl << endl;

    cout << "Pushing 40\n";
    buffer.push_back(40);
    cout << buffer << endl << endl;

    cout << "Pushing 50\n";
    buffer.push_back(50);
    cout << buffer << endl << endl;

    cout << "Pushing 60\n";
    buffer.push_back(60);
    cout << buffer << endl << endl;

    cout << "Pushing 70\n";
    buffer.push_back(70);
    cout << buffer << endl << endl;

    cout << "Poping: 30" << endl;
    buffer.pop();
    cout << buffer << endl << endl;

    cout << "Poping: 40" << endl;
    buffer.pop();
    cout << buffer << endl << endl;

    cout << "Poping: 50" << endl;
    buffer.pop();
    cout << buffer << endl << endl;

    cout << "Poping: 60" << endl;
    buffer.pop();
    cout << buffer << endl << endl;

    cout << "Poping: 70" << endl;
    buffer.pop();
    cout << buffer << endl << endl;

    cout << "\n*************** <string> Circular Buffer Demo ******************\n";
    cout << endl;

    //  FINISH THIS SECTION --
    // create a vector of words
    // use back_insert_iterator to fill the buffer

    CircularBuffer<string, 5> buffy;
    vector<string> word = { "Welcome", "to", "the", "wonderful", "world", "of", "oz" };
    
    cout << "Initial state\n";
    cout << buffy << endl << endl;

    cout << "After using back_insert_iterator" << endl;
    back_insert_iterator<CircularBuffer<string, 5>> backInserter(buffy);
    copy(word.begin(), word.end(), backInserter); //basically fills in the buffer, but add the items to the end of it
  //ex: vec 1 is 1,2,3,4 vec 2 is 6,7,8 using the back insert from vec 1 to vec 2, it will put all of vec 1 at the end of vec 2
    //so now vec 2 is 6,7,8,1,2,3,4
    cout << buffy << endl << endl;
    //popping the one where current is at 
    cout << "Popping: the" << endl;
    buffy.pop();
    cout << buffy << endl << endl;

    cout << "Popping: wonderful" << endl;
    buffy.pop();
    cout << buffy << endl << endl;

    cout << "Popping: world" << endl;
    buffy.pop();
    cout << buffy << endl << endl;

    cout << "Popping: of" << endl;
    buffy.pop();
    cout << buffy << endl << endl;

    cout << "Popping: oz\n";
    buffy.pop();
    cout << buffy << endl << endl;




    cout << "\n*************** <Dog> Circular Buffer Demo ******************\n";
    cout << endl;
    CircularBuffer<dog, 5> buffles;
    
    buffles.push_back(dog("Guinness", "Wheaten", 9));
    buffles.push_back(dog("Grimlock", "Lab", 2));
    buffles.push_back(dog("Optimus", "Bulldog", 5));
    buffles.push_back(dog("Murphy", "Lab", 14));
    buffles.push_back(dog("Floyd", "Beagle", 12));
    cout << buffles << endl << endl;
    cout << boolalpha << "dogs Full?: " << buffles.full();
    cout << endl << endl;
    buffles.push_back(dog("Snoopy", "Beagle", 100));
    cout << buffles << endl << endl;

    buffles.push_back(dog("Archie", "Brittany", 1));
    cout << buffles << endl << endl;

    buffles.push_back(dog("Penny", "Beagle", 2));
    cout << buffles << endl << endl;

    cout << "Popping: " << endl;
    cout << "    Murphy, Lab, 14" << endl << endl;
    buffles.pop();
    cout << buffles << endl << endl;

    cout << "Popping:" << endl;
    cout << "    Floyd, Beagale, 12" << endl << endl;
    buffles.pop();
    cout << buffles << endl << endl;

    cout << "Popping:" << endl;
    cout << "    Snoopy, Beagle, 100" << endl << endl;
    buffles.pop();
    cout << buffles << endl << endl;

    cout << "Popping:" << endl;
    cout << "    Archie, Brittany, 1" << endl << endl;
    buffles.pop();
    cout << buffles << endl << endl;

    cout << "Popping:" << endl;
    cout << "    Penny, Beagle, 2" << endl << endl;
    buffles.pop();
    cout << buffles << endl << endl;
    //  FINISH THIS SECTION

    cout << endl;
}
