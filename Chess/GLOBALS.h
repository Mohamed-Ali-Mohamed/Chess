#ifndef GLOBALS_H
#define GLOBALS_H
#include<string>
using namespace std;
#define Board_Square_Height 75
#define Board_Square_Width 75
class GLOBALS{
public:
	static string Action_Move;
	static string Action_Attack;
	static string Action_MoveAndChange;
	static string Action_AttackAndChange;
};
#endif