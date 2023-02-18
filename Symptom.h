#include <string>

using namespace std;

class Symptom {
public:
	string name;
	bool status = true;

	void init(string);
	string getstr();

};