#pragma once
#include "CObject.h"
#include "CPos.h"

class CBird : public CObject
{
private:
	char** _bird;
public:
	CBird(CPos pos);
	~CBird();
	
	//return sth
	char** kind();
	int getW();
	int getH();


};

