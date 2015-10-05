/* This program will recursively generate all possible permutations of
 * a given deque of integers
 */

#include <deque>
#include <iostream>
using namespace std;

// function prototypes
deque<deque<int> > getPermutations(deque<int> &init);
void getPermutationsHelper(deque<int> &current, deque<int> &rest, deque<deque<int> > &allPermutations);
void displayPermutations(deque<deque<int> > &permutations);


int main() {
	deque<deque<int> > permutations;

	// intialize a deque with a few values
	deque<int> init1;
	for(int i = 0; i < 4; i++) {
		init1.push_back(i);
	}
	
	permutations = getPermutations(init1);
	
	displayPermutations(permutations);

	return 0;
}

// client-facing function which will rely on recursive helper function
// to get the permutations of the given deque
deque<deque<int> > getPermutations(deque<int> &init) {
	deque<int> current;
	deque<deque<int> > allPermutations;
	getPermutationsHelper(current, init, allPermutations);
	
	return allPermutations;
}

// selects each of the remaining values one at a time as the next element
// and then recursively calls itself to find the permutations of the 
// remaining elements
void getPermutationsHelper(deque<int> &current, deque<int> &rest, deque<deque <int> > &allPermutations) {
	// base case: found a permutation
	if(rest.size() == 0) {
		allPermutations.push_back(current);
		return;
	}	

	for(int i = 0; i < rest.size(); i++) {
		// reset next and rest deques so that another element may be chosen as the next element
		deque<int> next = current;
		deque<int> restTemp = rest;

		// adjust next and rest for the next chosen element	
		next.push_back(rest[i]);
		restTemp.erase(restTemp.begin() + i);
		getPermutationsHelper(next, restTemp, allPermutations);
	}
}

// neatly display all permutations
void displayPermutations(deque<deque<int> > &allPermutations) {
	// iterate over all permutations
	deque<deque<int> >::iterator it;
	for(it = allPermutations.begin(); it != allPermutations.end(); it++) {
		// display each permutation
		deque<int> currentPermutation = *it;
		deque<int>::iterator i;
		for(i = currentPermutation.begin(); i != currentPermutation.end(); i++) {
			cout << *i << " ";
		}
		cout << endl;	
	}
}
