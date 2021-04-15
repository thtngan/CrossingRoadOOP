#pragma once
#include "Header.h"
#include "CObject.h"
#include "CPos.h"

class CTrain : public CObject
{
private:
	char** _train;
public:
	CTrain();
	~CTrain();

	//return sth
	char** kind();
	int getW();
	int getH();


};

