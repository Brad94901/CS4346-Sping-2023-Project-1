/*
Project 1
Brad Hughes, Zohair Khan

Intelligent computer system design to diagnose toxi substances and poison, as well as recommend treatment based on the diagnosis.
*/

#include "Project1.h"
#include <iostream>
#include <string>

using namespace std;



//Function declarations
int search_conclusion_list(string conclusion);
int rule_to_clause(int rule);
int upddate_VarList(int clause);
int validate_Ri(int rule, string conclusion);
int backwards_chain();
void forwards_chain(string conclusion);
int treatment(int rule[2]);


int main(){

	//int true_rules = backwards_chain()
	int true_rules[2] = {2, 10};
	diagnosis(true_rules);	
}


int backwards_chain(){ //driver function for backwards chain, returns the string conclusion.

	string conclusion_list[POICONCLISTSIZE];
	string VarList[POISONVARLISTSIZE]
	bool ClauseVarList[CLAUSEVARLISTSIZE]

	int true_rules[2]; //when a rule is set to true and rule to array. true_rules[0] = false/ivy; true_rules[1] for poison/venom. true_rules[2] for 

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
	VarList[0] = bool treatmentNeeded;
	VarList[1] = bool evilRedhead;
	VarList[2] = bool PoisonOrVenom; //True for poison false for venom
	VarList[3] = bool drug;
	VarList[4] = bool rodenticide;
	VarList[5] = bool insecticide;
	VarList[6] = bool single_puncture;
	VarList[7] = bool double_puncture;
	VarList[8] = bool vomiting;
	VarList[9] = bool clammy;
	VarList[10] = bool breathing;
	VarList[11] = bool shaking;
	VarList[12] = bool heartrate;
	VarList[14] = bool hypertension;
	VarList[15] = bool tingling;
	VarList[16] = bool clotting;
	VarList[17] = bool organDamage;
	VarList[18] = bool brainSwelling;
	VarList[19] = bool parasympathetic;
	VarList[20] = bool nerves;
	VarList[21] = bool asthma;
	VarList[22] = bool skinIrritation;
	VarList[23] = bool necrosis;
	VarList[24] = bool latrodectism;
	VarList[25] = bool edema;
	VarList[26] = bool paralysis;
	VarList[27] = bool cardiovascular;

	//Populate the clause variable list, this is the LONG one, like really long, like really really really long. . . . . I'm tired.
	//Populate from the lowest rule, delete any line that doesn't need instantiation since each conclusion STILL needs the space.
	//Rule 1: No Treatment Needed
	ClauseVarList[0] = treatmentNeeded;

	//Rule 2: Poison Ivy
	ClauseVarList[8] = treatmentNeeded;
	ClauseVarList[9] = PoisonOrVenom;
	ClauseVarList[10] = evilRedhead;

	//Rule 3: Drug Overdose
	ClauseVarList[16] = treatmentNeeded;
	ClauseVarList[17] = PoisonOrVenom;
	ClauseVarList[18] = drug;

	//Rule 4: Venom
	ClauseVarList[24] = treatmentNeeded;
	ClauseVarList[25] = PoisonOrVenom

	//Rule 5: Poison
	ClauseVarList[32] = treatmentNeeded;
	ClauseVarList[33] = PoisonOrVenom;
	
	//Rule 6: Rodenticide
	ClauseVarList[40] = treatmentNeeded;
	ClauseVarList[41] = PoisonOrVenom;
	ClauseVarList[42] = drug;
	ClauseVarList[43] = rodenticide;
	
	//Rule 7: Insecticide
	ClauseVarList[48] = treatmentNeeded;
	ClauseVarList[49] = PoisonOrVenom;
	ClauseVarList[50] = drug;
	ClauseVarList[51] = rodenticide;
	ClauseVarList[52] = insecticide;
	
	//Rule 8: Arachnid
	ClauseVarList[56] = treatmentNeeded;
	ClauseVarList[57] = PoisonOrVenom;
	ClauseVarList[58] = single_puncture;

	//Rule 9: Snake
	ClauseVarList[64] = treatmentNeeded;
	ClauseVarList[65] = PoisonOrVenom;
	ClauseVarList[66] = double_puncture;
	
	//Rule 10: Opiod
	ClauseVarList[72] = treatmentNeeded;
	ClauseVarList[73] = PoisonOrVenom;
	ClauseVarList[74] = drug;
	ClauseVarList[75] = vomiting;
	ClauseVarList[76] = clammy;
	//Rule 11: Alcohol
	ClauseVarList[80] = treatmentNeeded;
	ClauseVarList[81] = PoisonOrVenom;
	ClauseVarList[82] = drug;
	ClauseVarList[83] = vomiting;
	ClauseVarList[84] = clammy;
	ClauseVarList[85] = breathing;
	ClauseVarList[86] = heartrate;
	
	//Rule 12: Cocaine
	ClauseVarList[88] = treatmentNeeded;
	ClauseVarList[89] = PoisonOrVenom;
	ClauseVarList[90] = drug;
	ClauseVarList[91] = vomiting;
	ClauseVarList[92] = clammy;
	ClauseVarList[93] = breathing;
	ClauseVarList[94] = heartrate;
	
	//Rule 13: Antidepressant
	ClauseVarList[96] = treatmentNeeded;
	ClauseVarList[97] = PoisonOrVenom;
	ClauseVarList[98] = drug;
	ClauseVarList[99] = vomiting;
	ClauseVarList[100] = clammy;
	ClauseVarList[101] = shaking;
	
	//Rule 14: Tiratricol
	ClauseVarList[104] = treatmentNeeded;
	ClauseVarList[105] = PoisonOrVenom;
	ClauseVarList[106] = drug;
	ClauseVarList[107] = vomiting;
	ClauseVarList[108] = clammy;
	ClauseVarList[109] = shaking;
	ClauseVarList[110] = hypertension;
	
	//Rule 15: Methamphetamine
	ClauseVarList[112] = treatmentNeeded;
	ClauseVarList[113] = PoisonOrVenom;
	ClauseVarList[114] = drug;
	ClauseVarList[115] = vomiting;
	ClauseVarList[116] = clammy;
	ClauseVarList[117] = shaking;
	ClauseVarList[118] = hypertension;
	
	//Rule 16: Tetrodotoxin
	ClauseVarList[120] = treatmentNeeded;
	ClauseVarList[121] = PoisonOrVenom;
	ClauseVarList[122] = drug;
	ClauseVarList[123] = tingling;
	
	//Rule 17: Warfarin
	ClauseVarList[128] = treatmentNeeded;
	ClauseVarList[129] = PoisonOrVenom;
	ClauseVarList[130] = rodenticide;
	ClauseVarList[131] = clotting;
	
	//Rule 18: Thallium
	ClauseVarList[136] = treatmentNeeded;
	ClauseVarList[137] = PoisonOrVenom;
	ClauseVarList[138] = rodenticide;
	ClauseVarList[139] = clotting;
	ClauseVarList[140] = organDamage;
	
	//Rule 19: Bromethalin
	ClauseVarList[144] = treatmentNeeded;
	ClauseVarList[145] = PoisonOrVenom;
	ClauseVarList[146] = rodenticide;
	ClauseVarList[147] = clotting;
	ClauseVarList[148] = brainSwelling;
	
	//Rule 20: Strychnine
	ClauseVarList[152] = treatmentNeeded;
	ClauseVarList[153] = PoisonOrVenom;
	ClauseVarList[154] = rodenticide;
	ClauseVarList[155] = clotting;
	ClauseVarList[156] = brainSwelling;
	
	//Rule 21: Carbamates
	ClauseVarList[160] = treatmentNeeded;
	ClauseVarList[161] = PoisonOrVenom;
	ClauseVarList[162] = rodenticide;
	ClauseVarList[163] = insecticide;
	ClauseVarList[164] = parasympathetic;
	ClauseVarList[165] = nerves;
	
	//Rule 22: Organophosphates
	ClauseVarList[168] = treatmentNeeded;
	ClauseVarList[169] = PoisonOrVenom;
	ClauseVarList[170] = parasympathetic;
	ClauseVarList[171] = nerves;
	
	//Rule 23: Pyrethrins
	ClauseVarList[176] = treatmentNeeded;
	ClauseVarList[177] = PoisonOrVenom;
	ClauseVarList[178] = parasympathetic;
	ClauseVarList[179] = asthma;
	
	//Rule 24: Rotenone
	ClauseVarList[184] = treatmentNeeded;
	ClauseVarList[185] = PoisonOrVenom;
	ClauseVarList[186] = parasympathetic;
	ClauseVarList[187] = asthma;
	ClauseVarList[188] = skinIrritation;

	//Rule 25: Recluse Spider
	ClauseVarList[192] = treatmentNeeded;
	ClauseVarList[193] = PoisonOrVenom;
	ClauseVarList[194] = single_puncture;
	ClauseVarList[195] = necrosis;
	
	//Rule 26: Widow Spider
	ClauseVarList[200] = treatmentNeeded;
	ClauseVarList[201] = PoisonOrVenom;
	ClauseVarList[202] = single_puncture;
	ClauseVarList[203] = necrosis;
	ClauseVarList[204] = latrodectism;
	
	//Rule 27: Tarantula
	ClauseVarList[208] = treatmentNeeded;
	ClauseVarList[209] = PoisonOrVenom;
	ClauseVarList[210] = single_puncture;
	ClauseVarList[211] = necrosis;
	ClauseVarList[212] = latrodectism;
	ClauseVarList[213] = organDamage;
	
	//Rule 28: Deathstalker Scorpion
	ClauseVarList[216] = treatmentNeeded;
	ClauseVarList[217] = PoisonOrVenom;
	ClauseVarList[218] = single_puncture;
	ClauseVarList[219] = necrosis;
	ClauseVarList[220] = latrodectism;
	ClauseVarList[221] = edema;
	
	//Rule 29: Rattlesnake
	ClauseVarList[224] = treatmentNeeded;
	ClauseVarList[225] = PoisonOrVenom;
	ClauseVarList[226] = single_puncture;
	ClauseVarList[227] = double_puncture;
	ClauseVarList[228] = vomiting;
	ClauseVarList[229] = paralysis;
	ClauseVarList[230] = clotting;
	
	//Rule 30: Cobra
	ClauseVarList[232] = treatmentNeeded;
	ClauseVarList[233] = PoisonOrVenom;
	ClauseVarList[234] = vomiting;
	ClauseVarList[235] = paralysis;
	ClauseVarList[236] = necrosis;
	
	//Rule 31: Mamba
	ClauseVarList[240] = treatmentNeeded;
	ClauseVarList[241] = PoisonOrVenom;
	ClauseVarList[242] = vomiting;
	ClauseVarList[243] = paralysis;
	ClauseVarList[244] = necrosis;
	ClauseVarList[245] = cardiovascular;
	

	return true_rules;
}

int treatment(int rule[2]){
	string toxin_cat;
	string treatment;
	string diagnosis;
	switch(rule[0]) { //Categorically determines the switch statement to be used.
		case 0: 
			diagnosis = "PATIENT WAS NOT EXPOSED TO A TOXIC SUBSTANCE";
			treatment = "NO TREATMENT NEEDED";
			std::cout << diagnosis << endl;
			std::cout << treatment << endl;
		case 1:
			diagnosis = "PATIENT WAS POINSED BY POISON IVY";
			treatment = "CALL BATMAN";
			std::cout << diagnosis << endl;
			std::cout << treatment << endl;
			return 0;

		case 2: //Drug overdose
			toxin_cat = "DRUG OVERDOSE";
			break;
		case 3: //Venom
			toxin_cat = "EXPOSED TO VENOM";
			break;
		case 4: //Poison
			toxin_cat = "INJESTED OR INHALED POISON";
			break;
		case 5: //Rodenticide
			toxin_cat = "EXPOSED TO RODENTICIDE";
			break;
		case 6: //Insecticide
			toxin_cat = "EXPOSED TO INSECTICIDE";
			break;
		case 7: //Arachnid
			toxin_cat = "PATIENT WAS BITTEN BY AN ARACHIND";
			break;
		case 8: //Snake
			toxin_cat = "PATIENT WAS BITTEN BY A SNAKE";
			break;
		}
	

	switch(rule[1]) { //Categorically determines the switch statement to be used.
		case 9: //Opiod
			diagnosis = "PATIENT HAS OVERDOSED ON OPIODS";
			treatment = "TREAT THE PATIENT WITH NALOXONE";
			break;
		case 10://Alcohol
			diagnosis = "PATIENT IS SUFFERING FROM ALCOHOL POISONING";
			treatment = "MONITOR THE PATIENT AND TREAT THE SYMPTOMS AS NEEDED";
			break;
		case 11: //Cocaine
			diagnosis = "PATIENT HAS OVERDOSED ON COCAINE";
			treatment = "APPLY IV FLUIDS, MONITOR THE PATIENT AND TREAT THE SYMPTOMS AS NEEDED";
			break;
		case 12: //Antidepressant
			diagnosis = "PATIENT HAS OVERDOSED ON ANTIDEPRESSANTS";
			treatment = "PUMP STOMACH AND PROVIDE ACTIVATED CHARCOAL, KEEP THE PATIENT HYDRATED";
			break;
		case 13: //Tiratricol
			diagnosis = "PATIENT HAS OVERDOSED ON TIRATRICOL";
			treatment = "STOP VITAMIN D INTAKE AND RESTRICT DIETARY CALCIUM";
			break;
		case 14: //Methamphetamin
			diagnosis = "PATIENT HAS OVERDOSED ON METHAMPHETAMIN";
			treatment = "PROVIDE ACTIVATED CHARCOAL AND LAXATIVE. IV FLUIDS TO TREAT SYMPTOMNS";
			break;
		case 15: //Tetrodotoxin
			diagnosis = "PATIENT HAS BEEN EXPOSED TO TETRODOTOXIN";
			treatment = "";
			break;
		case 16: //Warfarin
			diagnosis = "PATIENT HAS BEEN EXPOSED TO WARFARIN";
			treatment = "";
			break;
		case 17: //Thallium
			diagnosis = "PATIENT HAS BEEN EXPOSED TO THALLIUM";
			treatment = "";
			break;
		case 18: //Bromethalin
			diagnosis = "PATIENT HAS BEEN EXPOSED TO BROMETHALIN";
			treatment = "";
			break;
		case 19: //Strychnine
			diagnosis = "PATIENT HAS BEEN EXPOSED TO STRYCHNINE";
			treatment = "";
			break;
		case 20: //Carbamates
			diagnosis = "PATIENT HAS BEEN EXPOSED TO CARBAMATES";
			treatment = "";
			break;
		case 21: //Organophosphates
			diagnosis = "PATIENT HAS BEEN EXPOSED TO ORGANOPHOSPHATES";
			treatment = "";
			break;
		case 22: //Pyrethrins
			diagnosis = "PATIENT HAS BEEN EXPOSED TO PYRETHRINS";
			treatment = "";
			break;
		case 23: //Rotenone
			diagnosis = "PATIENT HAS BEEN EXPOSED TO ROTENONE";
			treatment = "";
			break;
		case 24: //Recluse
			diagnosis = "PATIENT HAS BEEN BITTEN BY A RECLUSE SPIDER";
			treatment = "";
			break;
		case 25: //Widow
			diagnosis = "PATIENT HAS BEEN BITTEN BY A WIDOW SPIDER";
			treatment = "";
			break;
		case 26: //Tarantula
			diagnosis = "PATIENT HAS BEEN BITTEN BY A TARANTULA";
			treatment = "";
			break;
		case 27: //Deathstalker
			diagnosis = "PATIENT HAS BEEN STUNG BY A DEATHSTALKER SCOPRION";
			treatment = "";
			break;
		case 28: //Rattlesnake
			diagnosis = "PATIENT HAS BEEN BITTEN BY A RATTLESNAKE";
			treatment = "";
			break;
		case 29: //Cobra
			diagnosis = "PATIENT HAS BEEN BITTEN BY A COBRA";
			treatment = "";
			break;
		case 30: //Mamba
			diagnosis = "PATIENT HAS BEEN BITTEN BY A MAMBA";
			treatment = "";
			break;
		}
	

	std::cout << toxin_cat << endl;
	std::cout << diagnosis << endl;
	std::cout << treatment << endl;
	return 0;	

}

/*
int search_conclusion_list(int conclusion);{
	

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

}*/


