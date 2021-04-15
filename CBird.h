#pragma once
#include "Header.h"
#include "CObject.h"
#include "CPos.h"

class CBird : public CObject
{
private:
	char** _bird;
public:
	CBird();
	~CBird();
	
	//return sth
	char** kind();
	int getW();
	int getH();


};

