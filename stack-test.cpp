#include <iostream>
#include <vector>
#include "stack.h"
#include "heap.h"
//#include "hw3_tests/heap_tests/"
//#include <random_generator.h>
using namespace std;

int main(){

  /*
    cout << "STACK-TEST" << endl;
    Stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    
    cout << s1.top() << endl;
    
    s1.pop();
    s1.pop();

    cout << "AFTER POP: " << s1.top() << endl;

    s1.pop();
    cout << boolalpha << s1.empty() << endl;
  */
  
  cout << "heap-test" << endl;
  Heap<int> h1;
  h1.push(5);
  h1.push(10);
  h1.push(0);
  cout << h1.top() << endl;
  
/*
  const RandomSeed masterSeed = 3764;
	const size_t numTrials = 50;
	const size_t numElements = 50;
	const size_t d = 2;

	std::vector<RandomSeed> seedVector = makeRandomSeedVector(numTrials, masterSeed);

	for(RandomSeed trialSeed : seedVector)
	{
		std::vector<int> data = makeRandomNumberVector<int>(numElements, 0, numElements * 10, trialSeed, true);
		Heap<int> heap(d);

		for(int value : data)
		{
			heap.push(value);
		}
  }
  */
}