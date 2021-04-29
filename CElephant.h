#pragma once
#include "CObject.h"
#include "CPos.h"

class CElephant : public CObject
{
private:
	char** _elephant;

public:
	CElephant(CPos pos);
	~CElephant();

	//return sth
	char** kind();
	int getW();
	int getH();

};

