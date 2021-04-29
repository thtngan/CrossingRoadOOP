#pragma once
#include "CObject.h"
#include "CPos.h"

class CHelicopter : public CObject
{
private:
	char** _helicopter;
public:
	CHelicopter(CPos pos);
	~CHelicopter();

	//return sth
	char** kind();
	int getW();
	int getH();


};