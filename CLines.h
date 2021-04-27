#ifndef CLINES_H
#define CLINES_H
#include "CLine.h"
class CLines
{
	public:
		CLines();
		~CLines() = default;
		bool PushObj(CObject* newObj, int line);
		void PushLine(CLine* line);
		int Transfer(const int&);
		vector<CObject*> listObj();
	protected:
		vector<CLine*> _listLine;
};

#endif
