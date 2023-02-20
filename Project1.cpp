/*
Project 1
Brad Hughes, Zohair Khan
Intelligent computer system design to diagnose toxi substances and poison, as well as recommend treatment based on the diagnosis.
*/

#include "Project1.h"
#include "Symptom.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


//Function declarations
int search_conclusion_list(string conclusion);
int rule_to_clause(int rule);
int upddate_VarList(int clause);
int validate_Ri(int rule, string conclusion);
void forwards_chain(string conclusion);
int treatment(vector<int> rule);
bool teststr(string t);

int main(){ //driver function for backwards chain, returns the string conclusion.

	string conclusion_list[POICONCLISTSIZE];
	Symptom VarList[POISONVARLISTSIZE];
	string ClauseVarList[CLAUSEVARLISTSIZE];

	vector<int>true_rules;//when a rule is set to true and rule to array. true_rules[0] = false/ivy; true_rules[1] for poison/venom. true_rules[2] for 

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
	/*
	VarList[0].init("");
	VarList[1].init("");
	VarList[2].init("");
	VarList[3].init(""); //True for poison false for venom
	VarList[4].init("");
	VarList[5].init("");
	VarList[6].init("");
	VarList[7].init("");
	VarList[8].init("");
	VarList[9].init("");
	VarList[10].init("");
	VarList[11].init("");
	VarList[12].init("");
	VarList[13].init("");
	VarList[14].init("");
	VarList[15].init("");
	VarList[16].init("");
	VarList[17].init("");
	VarList[18].init("");
	VarList[19].init("");
	VarList[20].init("");
	VarList[21].init("");
	VarList[22].init("");
	VarList[23].init("");
	VarList[24].init("");
	VarList[25].init("");
	VarList[26].init("");
	VarList[27].init("");*/

	VarList[0].name = "treatment needed";
	VarList[1].name = "exposure to an evil Redhead";
	VarList[2].name = "poison";
	VarList[3].name = "venom"; //True for poison false for venom
	VarList[4].name = "drug";
	VarList[5].name = "rodenticide";
	VarList[6].name = "insecticide";
	VarList[7].name = "single_puncture";
	VarList[8].name = "double_puncture";
	VarList[9].name = "vomiting";
	VarList[10].name = "clammy";
	VarList[11].name = "breathing";
	VarList[12].name = "shaking";
	VarList[13].name = "heartrate";
	VarList[14].name = "hypertension";
	VarList[15].name = "tingling";
	VarList[16].name = "clotting";
	VarList[17].name = "organ damage";
	VarList[18].name = "brain swelling";
	VarList[19].name = "parasympathetic";
	VarList[20].name = "nerves";
	VarList[21].name = "asthma";
	VarList[22].name = "skinIrritation";
	VarList[23].name = "necrosis";
	VarList[24].name = "latrodectism";
	VarList[25].name = "edema";
	VarList[26].name = "paralysis";
	VarList[27].name = "cardiovascular";
	VarList[28].name = "disturbed vision";
    
	//Populate the clause variable list, this is the LONG one, like really long, like really really really long. . . . . I"m tired.
	//Populate from the lowest rule, delete any line that doesn"t need instantiation since each conclusion STILL needs the space.
	//Rule 1: No Treatment Needed
	ClauseVarList[0] = "treatment needed";

	//Rule 2: Poison Ivy
	ClauseVarList[8] = "treatment needed";
	ClauseVarList[9] = "poison";
	ClauseVarList[10] = "exposure to an evil Redhead";

	//Rule 3: Drug Overdose
	ClauseVarList[16] = "treatment needed";
	ClauseVarList[17] = "poison";
	ClauseVarList[18] = "drug";

	//Rule 4: Venom
	ClauseVarList[24] = "treatment needed";
	ClauseVarList[25] = "venom";

	//Rule 5: Poison
	ClauseVarList[32] = "treatment needed";
	ClauseVarList[33] = "poison";
	
	//Rule 6: Rodenticide
	ClauseVarList[40] = "treatment needed";
	ClauseVarList[41] = "poison";
	ClauseVarList[42] = "drug";
	ClauseVarList[43] = "rodenticide";
	
	//Rule 7: Insecticide
	ClauseVarList[48] = "treatment needed";
	ClauseVarList[49] = "poison";
	ClauseVarList[50] = "drug";
	ClauseVarList[51] = "rodenticide";
	ClauseVarList[52] = "insecticide";
	
	//Rule 8: Arachnid
	ClauseVarList[56] = "treatment needed";
	ClauseVarList[57] = "venom";
	ClauseVarList[58] = "single_puncture";

	//Rule 9: Snake
	ClauseVarList[64] = "treatment needed";
	ClauseVarList[65] = "venom";
	ClauseVarList[66] = "double_puncture";
	
	//Rule 10: Opiod
	ClauseVarList[72] = "treatment needed";
	ClauseVarList[73] = "poison";
	ClauseVarList[74] = "drug";
	ClauseVarList[75] = "vomiting";
	ClauseVarList[76] = "clammy";
	//Rule 11: "Alcohol"
	ClauseVarList[80] = "treatment needed";
	ClauseVarList[81] = "poison";
	ClauseVarList[82] = "drug";
	ClauseVarList[83] = "vomiting";
	ClauseVarList[84] = "clammy";
	ClauseVarList[85] = "breathing";
	ClauseVarList[86] = "heartrate";
	
	//Rule 12: Cocaine
	ClauseVarList[88] = "treatment needed";
	ClauseVarList[89] = "poison";
	ClauseVarList[90] = "drug";
	ClauseVarList[91] = "vomiting";
	ClauseVarList[92] = "clammy";
	ClauseVarList[93] = "breathing";
	ClauseVarList[94] = "heartrate";
	
	//Rule 13: Antidepressant
	ClauseVarList[96] = "treatment needed";
	ClauseVarList[97] = "apoison";
	ClauseVarList[98] = "drug";
	ClauseVarList[99] = "vomiting";
	ClauseVarList[100] = "clammy";
	ClauseVarList[101] = "shaking";
	
	//Rule 14: Tiratricol
	ClauseVarList[104] = "treatment needed";
	ClauseVarList[105] = "poison";
	ClauseVarList[106] = "drug";
	ClauseVarList[107] = "vomiting";
	ClauseVarList[108] = "clammy";
	ClauseVarList[109] = "shaking";
	ClauseVarList[110] = "hypertension";
	
	//Rule 15: Methamphetamine
	ClauseVarList[112] = "treatment needed";
	ClauseVarList[113] = "poison";
	ClauseVarList[114] = "drug";
	ClauseVarList[115] = "vomiting";
	ClauseVarList[116] = "clammy";
	ClauseVarList[117] = "shaking";
	ClauseVarList[118] = "hypertension";
	
	//Rule 16: Tetrodotoxin
	ClauseVarList[120] = "treatment needed";
	ClauseVarList[121] = "poison";
	ClauseVarList[122] = "drug";
	ClauseVarList[123] = "tingling";
	
	//Rule 17: Warfarin
	ClauseVarList[128] = "treatment needed";
	ClauseVarList[129] = "poison";
	ClauseVarList[130] = "rodenticide";
	ClauseVarList[131] = "clotting";
	
	//Rule 18: Thallium
	ClauseVarList[136] = "treatment needed";
	ClauseVarList[137] = "poison";
	ClauseVarList[138] = "rodenticide";
	ClauseVarList[139] = "clotting";
	ClauseVarList[140] = "organ damage";
	
	//Rule 19: Bromethalin
	ClauseVarList[144] = "treatment needed";
	ClauseVarList[145] = "poison";
	ClauseVarList[146] = "rodenticide";
	ClauseVarList[147] = "clotting";
	ClauseVarList[148] = "brain swelling";
	
	//Rule 20: Strychnine
	ClauseVarList[152] = "treatment needed";
	ClauseVarList[153] = "poison";
	ClauseVarList[154] = "rodenticide";
	ClauseVarList[155] = "clotting";
	ClauseVarList[156] = "brain swelling";
	
	//Rule 21: Carbamates
	ClauseVarList[160] = "treatment needed";
	ClauseVarList[161] = "apoison";
	ClauseVarList[162] = "rodenticide";
	ClauseVarList[163] = "insecticide";
	ClauseVarList[164] = "parasympathetic";
	ClauseVarList[165] = "nerves";
	
	//Rule 22: Organophosphates
	ClauseVarList[168] = "treatment needed";
	ClauseVarList[169] = "poison";
	ClauseVarList[170] = "parasympathetic";
	ClauseVarList[171] = "nerves";
	
	//Rule 23: Pyrethrins
	ClauseVarList[176] = "treatment needed";
	ClauseVarList[177] = "poison";
	ClauseVarList[178] = "parasympathetic";
	ClauseVarList[179] = "asthma";
	
	//Rule 24: Rotenone
	ClauseVarList[184] = "treatment needed";
	ClauseVarList[185] = "poison";
	ClauseVarList[186] = "parasympathetic";
	ClauseVarList[187] = "asthma";
	ClauseVarList[188] = "skinIrritation";

	//Rule 25: Recluse Spider
	ClauseVarList[192] = "treatment needed";
	ClauseVarList[193] = "venom";
	ClauseVarList[194] = "single_puncture";
	ClauseVarList[195] = "necrosis";
	
	//Rule 26: Widow Spider
	ClauseVarList[200] = "treatment needed";
	ClauseVarList[201] = "venom";
	ClauseVarList[202] = "single_puncture";
	ClauseVarList[203] = "necrosis";
	ClauseVarList[204] = "latrodectism";
	
	//Rule 27: Tarantula
	ClauseVarList[208] = "treatment needed";
	ClauseVarList[209] = "venom";
	ClauseVarList[210] = "single_puncture";
	ClauseVarList[211] = "necrosis";
	ClauseVarList[212] = "latrodectism";
	ClauseVarList[213] = "organ damage";
	
	//Rule 28: Deathstalker Scorpion
	ClauseVarList[216] = "treatment needed";
	ClauseVarList[217] = "venom";
	ClauseVarList[218] = "single_puncture";
	ClauseVarList[219] = "necrosis";
	ClauseVarList[220] = "latrodectism";
	ClauseVarList[221] = "edema";
	
	//Rule 29: Rattlesnake
	ClauseVarList[224] = "treatment needed";
	ClauseVarList[225] = "venom";
	ClauseVarList[226] = "single_puncture";
	ClauseVarList[227] = "double_puncture";
	ClauseVarList[228] = "vomiting";
	ClauseVarList[229] = "paralysis";
	ClauseVarList[230] = "clotting";
	
	//Rule 30: Cobra
	ClauseVarList[232] = "treatment needed";
	ClauseVarList[233] = "venom";
	ClauseVarList[234] = "vomiting";
	ClauseVarList[235] = "paralysis";
	ClauseVarList[236] = "necrosis";
	ClauseVarList[237] = "disturbed vision";
	
	//Rule 31: Mamba
	ClauseVarList[240] = "treatment needed";
	ClauseVarList[241] = "venom";
	ClauseVarList[242] = "vomiting";
	ClauseVarList[243] = "paralysis";
	ClauseVarList[244] = "necrosis";
	ClauseVarList[245] = "cardiovascular";
	
	/*
	for(int i = 0; i < 31; i++){ //loop to init necssary vars

		if(i = 0){ //there three need to be insantiated first so it will always be done loop interation 0 since certain combinations will cause the program to close on the first iteration.
			VarList[0].status  = check_sym(VarList[0].name); //treatment needed init
			if(VarList[0].status = false){
				true_rules.pop_back(0);
				break;
			}

			VarList[1].status = check_sym(VarList[1].name) //poison ivy init, if either are true truement is stated and run is complete
			if(VarList[1].status = true){
				true_rules.pop_back(1);
				break;
			} 
		

		//check conditional statements based on symptoms

			bool poisonVenomTemp = check_sym("an animal bite or sting")

			switch(poisonVenomTemp){
				case 0:{ //poison
					VarList[2].instantiated = true;
					VarList[2].status = true;
					break;
				}
				case 1:{ //venom
					VarList[3].instantiated = true;
					VarList[3].status = true;
					break;
				}
			}
		} //end first loop iterations
		//start with poison conditionals
		if(VarList[2].status = true && VarList[2].status = true){ //if poison has been instantiated and is true

		}

		if(VarList[3].status = true && VarList[3].status = true){ //if venom has been instantiated and is true

		}

	}*/
	
	

	//check all symptoms in VarList that are true against the ClauseVarList ie. if(all Clauses = true || null) add the rule number to the true_rules array.
	true_rules.push_back(0);
	treatment(true_rules);
}


int treatment(vector<int>rule){
	string toxin_cat;
	string treatment;
	string diagnosis;
	switch(rule[0]) { //Categorically determines the switch statement to be used.
		case 0: 
			diagnosis = "PATIENT WAS NOT EXPOSED TO A TOXIC SUBSTANCE";
			treatment = "NO TREATMENT NEEDED";
			break;
		case 1:
			diagnosis = "PATIENT WAS POINSED BY POISON IVY";
			treatment = "CALL BATMAN";
			break;

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
			treatment = "PROVIDE RESPIRATORY AND SUPPORTIVE CARE UNTIL POISON IS EXCRETED IN THE URINE";
			break;
		case 16: //Warfarin
			diagnosis = "PATIENT HAS BEEN EXPOSED TO WARFARIN";
			treatment = "APPLY ACTIVATED CHARCOAL AND MONITOR, GIVE 10 MG OF VITAMIN K IF NEEDED";
			break;
		case 17: //Thallium
			diagnosis = "PATIENT HAS BEEN EXPOSED TO THALLIUM";
			treatment = "TREAT THE PATIENT WITH PRUSSIAN BLUE";
			break;
		case 18: //Bromethalin
			diagnosis = "PATIENT HAS BEEN EXPOSED TO BROMETHALIN";
			treatment = "PROVICE THE PATIENT WITH EMESIS AND ACTIVATED CHARCOAL";
			break;
		case 19: //Strychnine
			diagnosis = "PATIENT HAS BEEN EXPOSED TO STRYCHNINE";
			treatment = "DECONTAMINATION AND PROVIDE SUPPORTIVE CARE WITH IV FLUIDS";
			break;
		case 20: //Carbamates
			diagnosis = "PATIENT HAS BEEN EXPOSED TO CARBAMATES";
			treatment = "APPLY IV DOSES OF 1 TO 3 MG UNTIL STABILIZATION, CONTINUE MONITORING";
			break;
		case 21: //Organophosphates
			diagnosis = "PATIENT HAS BEEN EXPOSED TO ORGANOPHOSPHATES";
			treatment = "DECONTAMINATE AND   CLEAN PATIENT'S SKIN. ACTIVATE CHARCOAL AND MONITOR";
			break;
		case 22: //Pyrethrins
			diagnosis = "PATIENT HAS BEEN EXPOSED TO PYRETHRINS";
			treatment = "DECONTAMINATE AND CLEAN PATIENT'S SKIN. ADMINISTER VITAMIN E IF NEEDED";
			break;
		case 23: //Rotenone
			diagnosis = "PATIENT HAS BEEN EXPOSED TO ROTENONE";
			treatment = "DECONTAMINATE, ADMINISTER OXYGEN, GLUCOSE AND VITAMIN K3 IF NEEDED";
			break;
		case 24: //Recluse
			diagnosis = "PATIENT HAS BEEN BITTEN BY A RECLUSE SPIDER";
			treatment = "CLEAN AND ELEVATE THE BITE AREA, PROVIDE ANTIBIOTICS";
			break;
		case 25: //Widow
			diagnosis = "PATIENT HAS BEEN BITTEN BY A WIDOW SPIDER";
			treatment = "CLEAN THE WOUND, APPLY ANTIHISTAMINE IF NEEDED. TREAT WITH ANTIVENOM";
			break;
		case 26: //Tarantula
			diagnosis = "PATIENT HAS BEEN BITTEN BY A TARANTULA";
			treatment = "COOL COMPRESS WITH ICE PACKS, TREAT WITH PAIN RELIEVERS.";
			break;
		case 27: //Deathstalker
			diagnosis = "PATIENT HAS BEEN STUNG BY A DEATHSTALKER SCOPRION";
			treatment = "APPLY LARGE DOSES OF ANTIVENOM AND MONITOR CLOSELY";
			break;
		case 28: //Rattlesnake
			diagnosis = "PATIENT HAS BEEN BITTEN BY A RATTLESNAKE";
			treatment = "CLEAN THE BITE AREA. TREAT THE PATIENT WITH ANTIBIOTICS AND ANTIVENOM";
			break;
		case 29: //Cobra
			diagnosis = "PATIENT HAS BEEN BITTEN BY A COBRA";
			treatment = "CLEAN THE BITE AREA. ADMINISTER ANTIBIOTICS AND ANTIVENOM, MONITOR THE PATIENT";
			break;
		case 30: //Mamba
			diagnosis = "PATIENT HAS BEEN BITTEN BY A MAMBA";
			treatment = "PROVIDE RESPIRATORY SUPPORT AND ADMINISTER ANTIVENOM IMMEDIATELY";
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


