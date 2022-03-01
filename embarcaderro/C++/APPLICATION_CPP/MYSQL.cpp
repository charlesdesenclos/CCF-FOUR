//---------------------------------------------------------------------------
//Programme:MYSQL.cpp 			date: 22/05/2017
//---------------------------------------------------------------------------
//Programmeurs:Muller Matthieu / Cedric Jourquin / Alexandre Gaudin
//---------------------------------------------------------------------------
//BUT: relever les temperatures d'une sonde PT100 et les affichers
//Programmes associés: IHM.h / carte.h
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

#pragma hdrstop
#pragma package(smart_init)
#include "mysql.h"
#include <String>
#include <time.h>
#include "vcl.h"
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)


BDD_MYSQL::BDD_MYSQL()
{
	/*mySQL=mysql_init(NULL);
	req1=new char[1000];*/

}


bool BDD_MYSQL::connexion(char *adress,char *id,char *mdp, char *table){   // connexion a la base de donnee

    mySQL=mysql_init(NULL);
	req1=new char[1000];

	if(mysql_real_connect(mySQL,adress,id,mdp,table,0,NULL,0)){
		etat=true;
	}
	else{
		etat=false;
	}

	return etat;
}

bool BDD_MYSQL::deconnexion()
{
	mysql_close(mySQL);
    //etatrequete=NULL;
}

//---------------------------------------------------------------------------


bool BDD_MYSQL::envoi(int temperature)
{

	int TEMPERATURES=temperature;
	String DayIs = FormatDateTime("dd", (TDate)Now());
	String hour = FormatDateTime("hh", (TDate)Now());
	String minutes = FormatDateTime("nn", (TDate)Now());

	String MonthIs = FormatDateTime("mm", (TDate)Now());
	String YearIs = FormatDateTime("yyyy", (TDate)Now());

	String req="";
	req += StrToInt(DayIs);
	req += "','";
	req += StrToInt(MonthIs);
	req += "','";
	req += StrToInt(YearIs);
	req += "','";
	req += StrToInt(hour);
	req += "','";
	req += StrToInt(minutes);
	req += "','";
	req += TEMPERATURES;
	req += "')";
	req = "INSERT INTO `temperature`(`JOUR`,`MOIS`,`ANNEE`,`HEURE`,`MINUTE`,`TEMPERATURE`) VALUES ('"+req;





	char* requeteconverti = new char [req.Length()+1] ;        // convertion des champs pour le mysql
	wcstombs(requeteconverti, req.c_str(), req.Length() + 1);
	etatrequete=mysql_query(mySQL, requeteconverti );


		if(etatrequete==0) //requete abouti
		{
			//resultat= mysql_store_result(mySQL);
			etat=true;
		}
		else                   //non
		{
			etat=false;
		}
		return etat;
}
//---------------------------------------------------------------------------


