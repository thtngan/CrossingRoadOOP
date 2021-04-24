#include "CLines.h"

CLines::CLines()
{
	_listLine.reserve(100);
}
bool CLines::PushObj(CObject* newObj, int line){
	if(line > _listLine.size())
		return false;
	return _listLine[line]->PushObj(newObj);
}
void CLines::PushLine(CLine* line){
	_listLine.push_back(line);
}
int CLines::Transfer(const int& t){
	int nDelete = 0;
	for (int i = 0; i < _listLine.size(); ++i) {
		nDelete += _listLine[i]->Transfer(t);
	}
	return nDelete;
}
