#include "Header.h"
#include "CObject.h"
#include "CPos.h"

class CHelicopter : public CObject
{
private:
	char** _helicopter;
public:
	CHelicopter();
	~CHelicopter();

	//return sth
	char** kind();
	int getW();
	int getH();


};