/**
 * mors_attackPlanner.hpp
 */
#pragma once
#include "mors_planner.hpp"

class MorsAttackPlanner : public MorsPlanner
{
public:
	MorsAttackPlanner(); //costruttore

	void handle(); //non è una sua funzione, ma di MorsPlanner
};
