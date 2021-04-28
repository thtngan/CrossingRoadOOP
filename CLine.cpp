#include "CLine.h"

CLine::CLine(int speed, bool direction, bool trafficLight, int curLine) {
	_speed = speed;
	_direction = direction;
	_trafficLight = trafficLight;
	_curLine = curLine;
	_listObj.reserve(100);
}
bool CLine::PrintObj(CPos pos, char** kind, int w, int h) {
	int X = pos.getX();
	int Y = pos.getY();
	if (Y == LEFT) 
		return false;
	if (Y > RIGHT)	
		return false;
	for (int i = 0; i < h; ++i) {
		for (int j = max(1, Y); j <= min(RIGHT, Y + w - 1); ++j) {
			gotoXY(Y + j, X + i);
			cout << kind[i][j - max(1, Y)];
		}
	}
	return true;
}
bool CLine::PushObj(CObject* newObj) {
	if (!_direction)
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
	int nDel = 0;
	if (_direction)
	{
		gotoXY(RIGHT + 69, _curLine);
	}
	else
	{
		gotoXY(LEFT, _curLine);
	}
	if (t == 0 || (!_trafficLight && (rand() % 8 == 0)) || (_trafficLight && (rand() % 8 == 0)))
		_trafficLight = !_trafficLight;
	if(_trafficLight)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("%c", 4);
	if (!_trafficLight)
		return nDel;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	vector <CObject*> newList;
	newList.reserve(100);
	for (int i = 0; i < (int)_listObj.size(); ++i) {
		CObject * curObj = _listObj[i];
		int dy = -1;
		if (_direction) dy = 1;
		DelObj(curObj->getPos(), curObj->getW(), curObj->getH());
		curObj->updatePos(0, dy);
		// Print Object
		bool print = PrintObj(curObj->getPos(), curObj->kind(), curObj->getW(), curObj->getH()); 
		if (!print) {
			curObj->setOutMap();
			++nDel;
		}
		if (curObj->isOutMap()) {
			delete curObj;
		}
		else {
			newList.push_back(curObj);
		}
	}
	_listObj = newList;
	return nDel;
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
