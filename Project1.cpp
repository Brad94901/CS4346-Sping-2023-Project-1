/*
Project 1
Brad Hughes, Zohair Khan

Intelligent computer system design to diagnose toxi substances and poison, as well as recommend treatment based on the diagnosis.
*/

#include "Project1.h"
#include <string>

using namespace std;

//Array declarations
string conclusion_list[POICONCLISTSIZE];
string VarList[POISONVARLISTSIZE]
bool ClauseVarList[CLAUSEVARLISTSIZE]

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

	//Populate the conclusion list, all 31 rules.
	conclusion_list[0] = "No Treatment Needed";
	conclusion_list[1] = "Poison Ivy";
	//Categorical conclusions
	conclusion_list[2] = "Drug Overdose";
	conclusion_list[3] = "Venom";
	conclusion_list[4] = "Poison";
	conclusion_list[5] = "Rodenticide";
	conclusion_list[6] = "Insecticide";
	conclusion_list[7] = "Arachnid";
	conclusion_list[8] = "Snake";
	//Drugs
	conclusion_list[9] = "Opiod Overdose";
	conclusion_list[10] = "Alcohol Poisoning";
	conclusion_list[11] = "Cocaine Overdose";
	conclusion_list[12] = "Antidepressant Overdose";
	conclusion_list[13] = "Tiratricol Overdose";
	conclusion_list[14] = "Methamphetamine Overdose";
	//Misc
	conclusion_list[15] = "Tetrodotoxin Poisoning";
	//Rodenticides
	conclusion_list[16] = "Warfarin";
	conclusion_list[17] = "Thallium";
	conclusion_list[18] = "Bromethalin";
	conclusion_list[19] = "Strychnine";
	//Insecticides
	conclusion_list[20] = "Carbamates";
	conclusion_list[21] = "Organophosphates";
	conclusion_list[22] = "Pyrethrins";
	conclusion_list[23] = "Rotenone";
	//Arachnids
	conclusion_list[24] = "Recluse Spider";
	conclusion_list[25] = "Widow Spider";
	conclusion_list[26] = "Tarantula";
	conclusion_list[27] = "Deathstalker Scorpion";
	//Snakes
	conclusion_list[28] = "Rattlesnake";
	conclusion_list[29] = "Cobra";
	conclusion_list[30] = "Mamba";

	//Populate the variable list, once again a long one, but we do have SOME overlap
	VarList[0] = bool treatmentNeeded = false;
	VarList[1] = bool evilRedhead = false;
	VarList[2] = "";
	VarList[3] = "";
	VarList[4] = "";
	VarList[5] = "";
	VarList[6] = "";
	VarList[7] = "";
	VarList[8] = "";
	VarList[9] = "";
	VarList[10] = "";
	VarList[11] = "";
	VarList[12] = "";
	VarList[13] = "";
	VarList[14] = "";
	VarList[15] = "";
	VarList[16] = "";
	VarList[17] = "";
	VarList[18] = "";
	VarList[19] = "";
	VarList[20] = "";
	VarList[21] = "";
	VarList[22] = "";
	VarList[23] = "";
	VarList[24] = "";
	VarList[25] = "";
	VarList[26] = "";
	VarList[27] = "";
	VarList[28] = "";
	VarList[29] = "";
	VarList[30] = "";


	//Populate the clause variable list, this is the LONG one, like really long, like really really really long. . . . . I'm tired.
	//Populate from the lowest rule, delete any line that doesn't need instantiation since each conclusion STILL needs the space.
	//Rule 1: No Treatment Needed
	ClauseVarList[0] = treatmentNeeded;
	//Rule 2: Poison Ivy
	ClauseVarList[8] = treatmentNeeded;
	ClauseVarList[9] = evilRedhead;
	//Rule 3:
	ClauseVarList[16] = treatmentNeeded;
	ClauseVarList[17] = "";
	ClauseVarList[18] = "";
	ClauseVarList[19] = "";
	ClauseVarList[20] = "";
	ClauseVarList[21] = "";
	ClauseVarList[22] = "";
	ClauseVarList[23] = "";
	//Rule 4:
	ClauseVarList[24] = treatmentNeeded;
	ClauseVarList[25] = "";
	ClauseVarList[26] = "";
	ClauseVarList[27] = "";
	ClauseVarList[28] = "";
	ClauseVarList[29] = "";
	ClauseVarList[30] = "";
	ClauseVarList[31] = "";
	//Rule 5:
	ClauseVarList[32] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 6:
	ClauseVarList[40] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 7:
	ClauseVarList[48] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 8:
	ClauseVarList[56] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 9:
	ClauseVarList[64] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 10:
	ClauseVarList[72] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 11:
	ClauseVarList[80] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 12:
	ClauseVarList[88] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 13:
	ClauseVarList[96] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 14:
	ClauseVarList[104] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 15:
	ClauseVarList[112] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	//Rule 16:
	ClauseVarList[120] = treatmentNeeded;
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";
	ClauseVarList[] = "";

	string diagnosis;
	return diagnosis
}

int search_conclusion_list(string conclusion);{
	

}

int rule_to_clause(int rule);{
	int Ci = (rule - 1) * POISONVARLISTSIZE + 1;

}

int upddate_VarList(int clause);{
	//maximum number of nodes a path can be +1 for a buffer
	//populate based on path
	//instantiate variables when needed

}

int validate_Ri(int rule, string conclusion);{
	//check clauses and return conclusion

}

void forwards_chain(){ //driver fuctions for forwards chaing, returns void as our treatment plan will be displayed as part of the forwards chain.

}