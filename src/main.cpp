/**
 * main.cpp
 */
#include "globals.hpp"

void setup()
{
	bno.begin(); //init della imu

	pixy.init(); //init della pixy

	planner = &attack_planner; //all'inizio, tutti e due i robot saranno attaccanti
}

void loop()
{
	/**
	 * planner ha diverse funzioni, i getter sono suoi, la handle varia in base se è attaccante o difensore
	 */
	if(/*perdo palla o qualche altra cosa. metto HIGH per non dare errori*/ HIGH)
	{
		planner = &defense_planner;
	}
	else if(/*riconquisto palla o qualche altra cosa. metto HIGH per non dare errori*/ HIGH)
	{
		planner = &attack_planner;
	}
	/**
	 * tutte le funzioni prima delle linee, poi del planner
	 */
	line_handler.handle(); //lettura dei sensori, test e calcolo dell'angolo di uscita

	planner-> handle(); //in base al ruolo del giocatore

	if(line_handler.getFlg()) //se le linee sono state lette
	{
		mors_drive.handle(line_handler.getEscapeAngle(), 200, planner-> getImuAngle()); //vorrei che guardasse il nord, ma non so come dirglielo al planner
	}
	else if(planner-> isReady()) //se le linee non sono state lette e se il giocatore rileva qualcosa
	{
		mors_drive.handle(planner-> getVel(), planner-> getAngle(), planner-> getImuAngle()); //deve guardare come dice il planner
	}
}
