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
#include <chrono>

using namespace std;

string conclusion_list[POICONCLISTSIZE];
Symptom VarList[POISONVARLISTSIZE];
int ClauseVarList[CLAUSEVARLISTSIZE];
vector<int> conclusion; // Derived Global Variable list

//Function declarations
void search_conclusion_list(int con);
int rule_to_clause(int Ri);
void update_VL(int Ci, int Ri);
void validate_Ri(int Ri);
void treatment(int con);
bool check_sym(string Symptom);

int main(){ //driver function for backwards chain, returns the string conclusion.

	auto start = chrono::steady_clock::now();

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
	ClauseVarList[0] = 0;

	//Rule 2: Poison Ivy
	ClauseVarList[8] = 0;
	ClauseVarList[9] = 1;

	//Rule 3: Drug Overdose
	ClauseVarList[16] = 0;
	ClauseVarList[17] = 4;

	//Rule 4: Venom
	ClauseVarList[24] = 0;
	ClauseVarList[25] = 3;

	//Rule 5: Poison
	ClauseVarList[32] = 0;
	ClauseVarList[33] = 2;
	
	//Rule 6: Rodenticide
	ClauseVarList[40] = 0;
	ClauseVarList[41] = 2;
	ClauseVarList[42] = 4;
	ClauseVarList[43] = 5;
	
	//Rule 7: Insecticide
	ClauseVarList[48] = 0;
	ClauseVarList[49] = 2;
	ClauseVarList[50] = 4;
	ClauseVarList[51] = 6;
	
	//Rule 8: Arachnid
	ClauseVarList[56] = 0;
	ClauseVarList[57] = 3;
	ClauseVarList[58] = 7;

	//Rule 9: Snake
	ClauseVarList[64] = 0;
	ClauseVarList[65] = 3;
	ClauseVarList[66] = 8;
	
	//Rule 10: Opiod
	ClauseVarList[72] = 0;
	ClauseVarList[73] = 2;
	ClauseVarList[74] = 4;
	ClauseVarList[75] = 9;
	ClauseVarList[76] = 10;

	//Rule 11: "Alcohol"
	ClauseVarList[80] = 0;
	ClauseVarList[81] = 2;
	ClauseVarList[82] = 4;
	ClauseVarList[83] = 9;
	ClauseVarList[84] = 10;
	ClauseVarList[85] = 11;
	
	//Rule 12: Cocaine
	ClauseVarList[88] = 0;
	ClauseVarList[89] = 2;
	ClauseVarList[90] = 4;
	ClauseVarList[91] = 9;
	ClauseVarList[92] = 10;
	ClauseVarList[93] = 11;
	ClauseVarList[94] = 13;
	
	//Rule 13: Antidepressant
	ClauseVarList[96] = 0;
	ClauseVarList[97] = 2;
	ClauseVarList[98] = 4;
	ClauseVarList[99] = 9;
	ClauseVarList[100] = 10;
	ClauseVarList[101] = 12;
	
	//Rule 14: Tiratricol
	ClauseVarList[104] = 0;
	ClauseVarList[105] = 2;
	ClauseVarList[106] = 4;
	ClauseVarList[107] = 9;
	ClauseVarList[108] = 10;
	ClauseVarList[109] = 12;
	ClauseVarList[110] = 14;
	
	//Rule 15: Methamphetamine
	ClauseVarList[112] = 0;
	ClauseVarList[113] = 2;
	ClauseVarList[114] = 4;
	ClauseVarList[115] = 9;
	ClauseVarList[116] = 10;
	ClauseVarList[117] = 12;
	ClauseVarList[118] = 14;
	
	//Rule 16: Tetrodotoxin
	ClauseVarList[120] = 0;
	ClauseVarList[121] = 2;
	ClauseVarList[122] = 15;
	
	//Rule 17: Warfarin
	ClauseVarList[128] = 0;
	ClauseVarList[129] = 2;
	ClauseVarList[130] = 5;
	ClauseVarList[131] = 16;
	
	//Rule 18: Thallium
	ClauseVarList[136] = 0;
	ClauseVarList[137] = 2;
	ClauseVarList[138] = 5;
	ClauseVarList[139] = 16;
	ClauseVarList[140] = 17;
	
	//Rule 19: Bromethalin
	ClauseVarList[144] = 0;
	ClauseVarList[145] = 2;
	ClauseVarList[146] = 5;
	ClauseVarList[147] = 16;
	ClauseVarList[148] = 18;
	
	//Rule 20: Strychnine
	ClauseVarList[152] = 0;
	ClauseVarList[153] = 2;
	ClauseVarList[154] = 5;
	ClauseVarList[155] = 16;
	ClauseVarList[156] = 18;
	
	//Rule 21: Carbamates
	ClauseVarList[160] = 0;
	ClauseVarList[161] = 2;
	ClauseVarList[162] = 5;
	ClauseVarList[164] = 19;
	ClauseVarList[165] = 20;
	
	//Rule 22: Organophosphates
	ClauseVarList[168] = 0;
	ClauseVarList[169] = 2;
	ClauseVarList[170] = 19;
	ClauseVarList[171] = 20;
	
	//Rule 23: Pyrethrins
	ClauseVarList[176] = 0;
	ClauseVarList[177] = 2;
	ClauseVarList[178] = 19;
	ClauseVarList[179] = 21;
	
	//Rule 24: Rotenone
	ClauseVarList[184] = 0;
	ClauseVarList[185] = 2;
	ClauseVarList[186] = 19;
	ClauseVarList[187] = 21;
	ClauseVarList[188] = 22;

	//Rule 25: Recluse Spider
	ClauseVarList[192] = 0;
	ClauseVarList[193] = 3;
	ClauseVarList[194] = 7;
	ClauseVarList[195] = 23;
	
	//Rule 26: Widow Spider
	ClauseVarList[200] = 0;
	ClauseVarList[201] = 3;
	ClauseVarList[202] = 7;
	ClauseVarList[203] = 23;
	ClauseVarList[204] = 24;
	
	//Rule 27: Tarantula
	ClauseVarList[208] = 0;
	ClauseVarList[209] = 3;
	ClauseVarList[210] = 7;
	ClauseVarList[211] = 23;
	ClauseVarList[212] = 24;
	ClauseVarList[213] = 17;
	
	//Rule 28: Deathstalker Scorpion
	ClauseVarList[216] = 0;
	ClauseVarList[217] = 3;
	ClauseVarList[218] = 7;
	ClauseVarList[219] = 23;
	ClauseVarList[220] = 24;
	ClauseVarList[221] = 25;
	
	//Rule 29: Rattlesnake
	ClauseVarList[224] = 0;
	ClauseVarList[225] = 3;
	ClauseVarList[227] = 8;
	ClauseVarList[228] = 9;
	ClauseVarList[229] = 26;
	ClauseVarList[230] = 16;
	
	//Rule 30: Cobra
	ClauseVarList[232] = 0;
	ClauseVarList[233] = 3;
	ClauseVarList[234] = 8;
	ClauseVarList[235] = 9;
	ClauseVarList[236] = 26;
	ClauseVarList[237] = 23;
	ClauseVarList[238] = 28
	
	//Rule 31: Mamba
	ClauseVarList[240] = 0;
	ClauseVarList[241] = 3;
	ClauseVarList[242] = 8;
	ClauseVarList[243] = 9;
	ClauseVarList[244] = 26;
	ClauseVarList[245] = 23;
	ClauseVarList[246] = 27
	
	//true_rules.push_back(0);
	conclusion.push_back(0);
	
	for (int i = 0; i < 32; ++i){
		search_conclusion_list(i);
	}

	for(auto i: conclusion){
		treatment(conclusion[i]);
	}

	auto end = chrono::steady_clock::now();
	auto diff = end - start;
	cout <<  "Execution time: "<< chrono::duration <double, milli> (diff).count() << " ms" << endl;

	cout << "Memory Usage: " << sizeof(conclusion_list) + sizeof(VarList) + sizeof(ClauseVarList) + sizeof(conclusion) << "MB" << endl;
}

void search_conclusion_list(int con){

	int Ri = con; 
	int Ci = rule_to_clause(Ri);
	update_VL(Ci, Ri);
	//validate_Ri(Ri);
}

int rule_to_clause(int Ri){
	int Ci;
	if(Ri == 0)
		Ci == 0;
	else
		Ci = 8 * (Ri);

	return Ci;
}

void update_VL(int Ci, int Ri){

	bool iter = true;

	for (int i = Ci; i <= Ci+8; i++){

		//Ask symptom questions that HAVE NOT been instantiated, if any are return false after updating break and go to the next rule.
		if(VarList[ClauseVarList[i]].instantiated == true && VarList[ClauseVarList[i]].status == false){
			iter = false;
			break;
		}

		if(VarList[ClauseVarList[i]].instantiated == true) //if variable has been instantiated skip it
			continue;

		VarList[ClauseVarList[i]].status = check_sym(VarList[ClauseVarList[i]].name);
		VarList[ClauseVarList[i]].instantiated = true;

	}

	if(iter == true){
		//cout << "here" << endl;
		validate_Ri(Ri);
	}



}

void validate_Ri(int Ri){
	//if all variables for a rule are true push the rule number onto true_rules.
	int Ci = rule_to_clause(Ri);
	bool flag = true;

	for (int i = Ci; i <= Ci+8; i++){

		if(VarList[ClauseVarList[i]].instantiated == true && VarList[ClauseVarList[i]].status == false){
			cout << "CONCLUSION NOT YET REACHED" << endl;
			flag = false;
			break;
		}

	}

	if(flag == true)
		conclusion.push_back(Ri);


}




void treatment(int con){
	string toxin_cat;
	string treatment;
	string diagnosis;

	switch(con) { //False alarm shoudl ONLY pop if VarList[0].status == false so if rule[0] != 0, pop the false alarm thing so should be an . . . .easyish fix
		case 0: 
			if(VarList[0].status == false){
				diagnosis = "PATIENT WAS NOT EXPOSED TO A TOXIC SUBSTANCE";
				treatment = "NO TREATMENT NEEDED";
				break;
			}
			break;
		case 1:
			diagnosis = "PATIENT WAS POISONED BY POISON IVY";
			treatment = "CALL BATMAN";
			break;

		case 2: //Drug
			toxin_cat = "DRUG OVERDOSE";
			break;
		case 3: //Venom
			toxin_cat = "EXPOSED TO VENOM";
			break;
		case 4: //Poison
			toxin_cat = "EXPOSED TO POISON";
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
			treatment = "DECONTAMINATE AND CLEAN PATIENT'S SKIN. ACTIVATE CHARCOAL AND MONITOR";
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
	

	if (toxin_cat != "") //handles whitespace
		std::cout << toxin_cat << endl;

	if (diagnosis != "")
		std::cout << diagnosis << endl;

	if (treatment != "")
		std::cout << treatment << endl;
	

}

bool check_sym(string Symptom) {
    bool testing = true; // Condition while true will run forever, type exit to turn false
    string response;
    while (testing == true) { // when testing is false then it stops running what is inside
    	cout << "--------------------------------------------------------------" << endl;
        cout << "Is your symptom: " << Symptom << "?\n"; // Change this if you want
        cin >> response; // User response
        if (response == "Yes" || response == "YES" || response == "Y" || response == "yes" || response == "y") {
            cout << "He said yes\n"; // Response is yes
            return true;
        }
        else if (response == "No" || response == "NO" || response == "N" || response == "no" || response == "n") {
            cout << "He said no\n"; // Response is no
            return false;
        }
        else {
            cout << "Not a proper response\n";
        }
    }
}
