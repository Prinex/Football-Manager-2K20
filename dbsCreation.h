#ifndef DBS2_H_INCLUDED
#define DBS2_H_INCLUDED

#include "dbsSource.h"

/**
*       For printing squad objects
*/
std::ostream &operator<<(std::ostream &os, Squad const& squad)
{
    os << "Squad name: " << squad.squad_name << '\n'
       << "League: " << squad.league << '\n'
       << "Manager: " << squad.manager << '\n';

    return os;
}



/**
*       Manchester United
*/
Squad Manchester("Manchester United F.C.", "Premier League", "Ole Gunnar Solskjær", 11, 7);


std::vector<Players> InitManchesterInfield;
std::vector<Players> ManchesterInfield
{
    {"De Gea",28,"Spain",192,82,1,"GK","GOOD",56000000,20,20,20,20,20,20,92,90,84,85,89},
    {"P. Pogba",26,"France",191,84,6,"LDM","GOOD",72500000,74,81,86,85,66,86,20,20,20,20,88},
    {"A. Martial",23,"France",184,76,9,"ST","GOOD",34500000,89,81,72,86,41,71,20,20,20,20,83},
    {"M. Rashford",21,"England",186,70,10,"LM","GOOD",35500000,92,82,73,84,45,77,20,20,20,20,83},
    {"H. Maguire",26,"England",194,100,5,"LCB","GOOD",23000000,50,53,64,69,81,84,20,20,20,20,82},
    {"J. Lingard",26,"England",175,62,14,"CAM","GOOD",24000000,80,78,76,83,58,72,20,20,20,20,82},
    {"V. Lindelof",24,"Sweden",187,80,2,"RCB","GOOD",22000000,74,50,72,72,82,78,20,20,20,20,81},
    {"L. Shaw",23,"England",181,75,23,"LB","GOOD",20000000,82,54,75,80,80,78,20,20,20,20,81},
    {"A. Wan-Bissaka",21,"England",183,72,29,"RB","GOOD",17500000,87,50,63,78,80,72,20,20,20,20,79},
    {"S. McTominay",22,"Scotland",193,88,39,"RDM","GOOD",11500000,61,65,72,72,74,80,20,20,20,20,77},
    {"Andreas Pereira",23,"Brazil",178,71,15,"RM","GOOD",11500000,73,74,78,78,66,69,20,20,20,20,77},

};

std::vector<Players> InitManchesterSubs;
std::vector<Players> ManchesterUSubs
{
    {"Juan Mata",31,"Spain",170,63,8,"SUB","GOOD",19500000,62,74,83,83,36,47,20,20,20,20,82},
    {"A. Sanchez",30,"Chile",169,62,7,"SUB","GOOD",21000000,81,78,77,85,44,73,20,20,20,20,82},
    {"S. Romero",32,"Argentina",192,86,22,"SUB","GOOD",9000000,20,20,20,20,20,20,83,79,76,79,80},
    {"C. Smalling",29,"England",194,81,12,"SUB","GOOD",12500000,69,47,58,58,79,81,20,20,20,20,80},
    {"Fred",26,"Brazil",169,64,17,"SUB","GOOD",15000000,76,73,75,80,74,69,20,20,20,20,79},
    {"A. Young",33,"England",175,65,18,"SUB","GOOD",4000000,70,66,74,75,73,71,20,20,20,20,77}
};


/**
*       Arsenal
*/
Squad Arsenal("Arsenal F.C", "Premier League", "Mikel Arteta", 11, 7);

std::vector<Players> InitArsenalInfield;
std::vector<Players> ArsenalInfield
{
    {"P. Aubameyang",30,"Gabon",187,80,14,"LM","GOOD",57000000,94,85,75,80,37,69,20,20,20,20,88},
    {"A. Lacazette",28,"France",175,73,9,"ST","GOOD",46000000,82,85,75,86,40,74,20,20,20,20,86},
    {"B. Leno",27,"Germany",190,83,1,"GK","GOOD",26000000,20,20,20,20,20,20,85,83,81,84,84},
    {"Sokratis",31,"Greece",186,85,5,"RCB","GOOD",23000000,72,51,52,60,84,83,20,20,20,20,84},
    {"M. Ozil",30,"Germany",180,76,10,"CAM","GOOD",29500000,70,72,86,84,24,56,20,20,20,20,84},
    {"N. Pepe",24,"Ivory Coast",183,73,19,"RM","GOOD",34500000,91,81,75,85,33,67,20,20,20,20,83},
    {"David Luiz",32,"Brazil",189,86,23,"LCB","GOOD",16500000,61,65,74,70,82,77,20,20,20,20,83},
    {"L. Torreira",23,"Uruguay",168,64,11,"RDM","GOOD",27000000,75,67,77,80,81,75,20,20,20,20,82},
    {"G. Xhaka",26,"Switzerland",185,82,34,"LDM","GOOD",21500000,51,67,81,71,69,78,20,20,20,20,81},
    {"Nacho Monreal",33,"Spain",180,77,18,"LB","GOOD",5500000,63,61,71,74,80,68,20,20,20,20,79},
    {"A.Maitland-Niles",21,"England",177,71,15,"RB","GOOD",9500000,85,59,70,76,68,67,20,20,20,20,75},
};

std::vector<Players> InitArsenalSubs;
std::vector<Players> ArsenalSubs
{
    {"Dani Ceballos",22,"Spain",179,70,8,"SUB","GOOD",24000000,69,67,79,84,68,68,20,20,20,20,81},
    {"H. Mkhitaryan",30,"Armenia",177,75,7,"SUB","GOOD",17000000,78,76,78,83,55,66,20,20,20,20,81},
    {"Hector BellerÃ­n",24,"Spain",178,74,2,"SUB","GOOD",17500000,92,51,70,78,76,66,20,20,20,20,80},
    {"S. KolaÅ¡inac",26,"Bosnia Herzegovina",183,85,31,"SUB","GOOD",13500000,75,62,72,73,75,87,20,20,20,20,79},
    {"S. Mustafi",27,"Germany",184,82,20,"SUB","GOOD",13000000,60,57,63,61,77,77,20,20,20,20,79},
    {"K. Tierney",22,"Scotland",178,78,3,"SUB","GOOD",11000000,88,59,70,74,71,81,20,20,20,20,76},
    {"R. Holding",23,"England",189,75,16,"SUB","GOOD",10000000,60,34,59,64,77,73,20,20,20,20,76}
};


/**
*       Liverpool
*/
Squad Liverpool("Liverpool F.C", "Premier League", "Jürgen Klopp", 11, 7);

std::vector<Players> InitLiverpoolInfield;
std::vector<Players> LiverpoolInfield
{
    {"V. van Dijk",27,"Netherlands",193,92,4,"LCB","GOOD",78000000,77,60,70,71,90,86,20,20,20,20,90},
    {"M. Salah",27,"Egypt",175,71,11,"RW","GOOD",80500000,93,86,81,89,45,74,20,20,20,20,90},
    {"Alisson",26,"Brazil",191,91,1,"GK","GOOD",58000000,20,20,20,20,20,20,89,85,84,90,89},
    {"S. Mane",27,"Senegal",175,69,10,"LW","GOOD",62000000,94,83,77,89,44,74,20,20,20,20,88},
    {"Roberto Firmino",27,"Brazil",181,76,9,"CF","GOOD",52000000,77,82,80,87,61,78,20,20,20,20,86},
    {"Fabinho",25,"Brazil",188,78,3,"CDM","GOOD",45000000,68,69,78,77,85,83,20,20,20,20,85},
    {"A. Robertson",25,"Scotland",178,64,26,"LB","GOOD",43500000,85,62,77,79,80,75,20,20,20,20,85},
    {"G. Wijnaldum",28,"Netherlands",175,69,5,"LCM","GOOD",31000000,77,73,78,84,76,78,20,20,20,20,84},
    {"T. Alexander-Arnold",20,"England",180,69,66,"RB","GOOD",32000000,80,62,82,78,78,70,20,20,20,20,83},
    {"J. Henderson",29,"England",182,80,14,"RCM","GOOD",22000000,64,70,83,77,78,80,20,20,20,20,83},
    {"J. Gomez",22,"England",188,77,12,"RCB","GOOD",20000000,81,30,64,68,79,76,20,20,20,20,80}

};

std::vector<Players> InitLiverpoolSubs;
std::vector<Players> LiverpoolSubs
{
    {"N. Keita",24,"Guinea",172,64,8,"SUB","GOOD",29000000,71,73,76,88,65,66,20,20,20,20,82},
    {"J. Matip",27,"Cameroon",194,90,32,"SUB","GOOD",23000000,61,46,68,67,83,76,20,20,20,20,82},
    {"X. Shaqiri",27,"Switzerland",169,72,23,"SUB","GOOD",23000000,80,77,81,85,46,69,20,20,20,20,82},
    {"J. Milner",33,"England",175,70,7,"SUB","GOOD",10500000,61,70,82,77,77,78,20,20,20,20,81},
    {"A. Oxlade-Chamberlain",25,"England",175,70,15,"SUB","GOOD",18500000,82,73,78,84,66,73,20,20,20,20,80},
    {"D. Lovren",29,"Croatia",188,84,6,"SUB","GOOD",12500000,54,40,59,62,80,78,20,20,20,20,80},
    {"A. Lallana",31,"England",178,73,20,"SUB","GOOD",11000000,67,71,79,82,62,65,20,20,20,20,79}
};


#endif // DBS2_H_INCLUDED
