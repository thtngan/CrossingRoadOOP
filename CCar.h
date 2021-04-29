#pragma once
#include "CObject.h"
#include "CPos.h"

class CCar : public CObject
{
private:
	char** _car;
public:
	CCar(CPos pos);
	~CCar();

	//return sth
	char** kind();
	int getW();
	int getH();


};

