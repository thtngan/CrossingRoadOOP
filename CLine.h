#pragma once
#include "CObject.h"
#include <vector>
using namespace std;
#define RIGHT 65
#define LEFT 2

class CLine
{
public:
	CLine() = default;
	~CLine() = default;
	CLine(int speed, bool direction,bool trafficLight, int curLine);
	bool PrintObj(CPos pos, char** kind, int w, int h);
	bool PushObj(CObject* newObj);	
	void DelObj(CPos pos, int w, int h);
	int Transfer(int t);
	int getSpeed();
	int getCurLine();
	vector<CObject*> getListObj();
	bool getDirection();
protected:
	vector<CObject*> _listObj;
	int _speed, _curLine;
	bool _direction; // true is from left, false is from right 
	bool _trafficLight; // true is green, false is red
};

