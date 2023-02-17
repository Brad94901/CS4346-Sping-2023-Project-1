#include <string>

using namespace std;

struct Symptom {
public:
	string name;
	bool status = false;

	void init(string);

};