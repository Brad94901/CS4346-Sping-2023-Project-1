/*
Project 1
Brad Hughes, Zohair Khan

Intelligent computer system design to diagnose toxi substances and poison, as well as recommend treatment based on the diagnosis.
*/

#include "Project1.h"
#include <string>

using namespace std;

//Function declarations

int search_conclusion_list(string conclusion);
int rule_to_clause(int rule);
int upddate_VarList(int clause);
int validate_Ri(int rule, string conclusion);
string backwards_chain();
void forwards_chain(string conclusion);


int main(){

	string conclusion = backwards_chain()
	forwards_chain(conclusion);

	
}

string backwards_chain(){ //driver function for backwards chain, returns the string conclusion.


	return conclusion
}

int search_conclusion_list(string conclusion);{
	string conclusion_list[POICONCLISTSIZE];
	//populate the conclusion list

}

int rule_to_clause(int rule);{
	int Ci = (rule - 1) * POISONVARLISTSIZE + 1;

}

int upddate_VarList(int clause);{
	string VarList[POISONVARLISTSIZE] //maximum number of nodes a path can be +1 for a buffer
	//populate based on path
	//instantiate variables when needed

}

int validate_Ri(int rule, string conclusion);{
	//check clauses and return conclusion

}

void forwards_chain(){ //driver fuctions for forwards chaing, returns void as our treatment plan will be displayed as part of the forwards chain.

}