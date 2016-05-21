#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

//extends class
class Robot {
public:
	void update() {
		move();
	};


private:
	virtual void move() = 0;
};
class CleanerRobot : public Robot {

private:
	virtual void move() {
		cout << "û�ҷκ�" << endl;
	}

};

class CombatRobot : public Robot {
private:
	virtual void move() {
		cout << "�����κ�" << endl;
	}
};
//interface class
class iRobotBehavior {

public:
	virtual ~iRobotBehavior() = default;
	virtual void move() = 0;
};

class iRobot {
public:
	iRobot(iRobotBehavior *oth) {
		obj = oth;
	}
	void update() {
		obj->move();
	}
	void change(iRobotBehavior * oth) {
		delete this->obj;
		this->obj = oth;
	}
	~iRobot() {
		delete obj;
	}
private:
	iRobotBehavior * obj;
};
class iCleanerBehavior : public iRobotBehavior {
public:
	void move() {
		cout << "û�ҷκ�" << endl;
	}


};

class iCombatBehavior : public iRobotBehavior {
public:
	void move() {
		cout << "�����κ�" << endl;
	}

};
int main() {
	//extend robot
	CleanerRobot cr;
	cr.update();
	CombatRobot cb;
	cb.update();
	//interface robot

	iRobot iC(new iCleanerBehavior);
	iC.update();
	iC.change(new iCombatBehavior);
	iC.update();



}
