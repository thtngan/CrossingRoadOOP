#include "CLine.h"

CLine::CLine(int speed, bool direction, int curLine) {
	_speed = speed;
	_direction = direction;
	_curLine = curLine;
	_listObj.reserve(100);
}
bool CLine::PrintObj(CPos pos, char** kind, int h, int w) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT) 
		return 0;
	if (Y > RIGHT)
		return 0;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHT, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << kind[i][j - max(1, Y)];
		}
	}
	return true;
}
bool CLine::PushObj(CObject* newObj) {
	if (_direction)
		newObj->updatePos(0, RIGHT - newObj->getY());
	if (newObj->getY() > RIGHT || newObj->getY() <= 3 || (_listObj.size() && abs(_listObj.back()->getY() - newObj->getY()) <= 8))
		return false;
	_listObj.push_back(newObj);
	PrintObj(newObj->getPos(), newObj->kind(), newObj->getW(), newObj->getH());
	return true;
}
void CLine::DelObj(CPos pos, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT) 
		return;
	if (Y > RIGHT) 
		return;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHT, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << ' ';
		}
	}
}
int CLine::Transfer(int t) {
	int nDelete = 0;
	if (!_direction)
	{
		gotoXY(RIGHT + 60, _curLine);
	}
	else
	{
		gotoXY(LEFT - 1, _curLine);
	}
	cout << (char)254;
	if (((t % _speed) != 0) && t != 0) return nDelete; //test
	vector <CObject*> newList;
	newList.reserve(100);
	for (int i = 0; i < (int)_listObj.size(); ++i) {
		CObject * curObj = _listObj[i];
		int dy = -1;
		if (!_direction) dy = 1;
		DelObj(curObj->getPos(), curObj->getW(), curObj->getH());
		curObj->updatePos(0, dy);
		// Print Object
		bool print = PrintObj(curObj->getPos(), curObj->kind(), curObj->getW(), curObj->getH()); 
		if (!print) {
			curObj->setOutMap();
			++nDelete;
		}
		if (curObj->isOutMap()) {
			delete curObj;
		}
		else {
			newList.push_back(curObj);
		}
	}
	_listObj = newList;
	return nDelete;
}
int CLine::getSpeed(){
	return _speed;
}
int CLine::getCurLine(){
	return _curLine;
}
vector<CObject*> CLine::getListObj(){
	return _listObj;
}
bool CLine::getDirection(){
	return _direction;
}
