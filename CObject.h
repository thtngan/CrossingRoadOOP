#pragma once
#include "CPos.h"
#include "CConsole.h"

class CObject
{
private:
	CPos _pos;
	bool _outMap;
	
public:
	int getX();
	int getY();
	CObject();
	CObject(const CPos&);
	~CObject() = default;
	CPos getPos();
	bool isOutMap();
	virtual int getH() = 0;
	virtual int getW() = 0;
	void updatePos(const int x, const int y);
	void setOutMap();
	virtual char** kind() = 0;
};

