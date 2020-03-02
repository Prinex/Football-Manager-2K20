#ifndef DBS2_H_INCLUDED
#define DBS2_H_INCLUDED

#include "dbsSource.h"

/**
*           Premier league leagues
*/
/**
*       Manchester United
*/
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

std::vector<Players> ManchesterUSubs
{
    {"Juan Mata",31,"Spain",170,63,8,"SUB","GOOD",19500000,62,74,83,83,36,47,20,20,20,20,82},
    {"A. Sanchez",30,"Chile",169,62,7,"SUB","GOOD",21000000,81,78,77,85,44,73,20,20,20,20,82},
    {"S. Romero",32,"Argentina",192,86,22,"SUB","GOOD",9000000,20,20,20,20,20,20,83,79,76,79,80},
    {"C. Smalling",29,"England",194,81,12,"SUB","GOOD",12500000,69,47,58,58,79,81,20,20,20,20,80},
    {"Fred",26,"Brazil",169,64,17,"SUB","GOOD",15000000,76,73,75,80,74,69,20,20,20,20,79},
    {"A. Young",33,"England",175,65,18,"SUB","GOOD",4000000,70,66,74,75,73,71,20,20,20,20,77}
};
Squad Manchester("Manchester United F.C.", "Premier League", "Ole Gunnar Solskjær", ManchesterInfield, ManchesterUSubs, 11, 7);




/**
*       Arsenal
*/
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
std::vector<Players> ArsenalSubs
{
    {"Dani Ceballos",22,"Spain",179,70,8,"SUB","GOOD",24000000,69,67,79,84,68,68,20,20,20,20,81},
    {"H. Mkhitaryan",30,"Armenia",177,75,7,"SUB","GOOD",17000000,78,76,78,83,55,66,20,20,20,20,81},
    {"Hector BellerÃ­n",24,"Spain",178,74,2,"SUB","GOOD",17500000,92,51,70,78,76,66,20,20,20,20,80},
    {"S. Kolasinac",26,"Bosnia Herzegovina",183,85,31,"SUB","GOOD",13500000,75,62,72,73,75,87,20,20,20,20,79},
    {"S. Mustafi",27,"Germany",184,82,20,"SUB","GOOD",13000000,60,57,63,61,77,77,20,20,20,20,79},
    {"K. Tierney",22,"Scotland",178,78,3,"SUB","GOOD",11000000,88,59,70,74,71,81,20,20,20,20,76},
    {"R. Holding",23,"England",189,75,16,"SUB","GOOD",10000000,60,34,59,64,77,73,20,20,20,20,76}
};
Squad Arsenal("Arsenal F.C.", "Premier League", "Mikel Arteta", ArsenalInfield, ArsenalSubs, 11, 7);




/**
*       Liverpool
*/
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
Squad Liverpool("Liverpool F.C.", "Premier League", "Jürgen Klopp", LiverpoolInfield, LiverpoolSubs, 11, 7);



/**
*       Chelsea F.C.
*/
std::vector<Players>ChelseaInfield
{
    {"N'Golo Kante",28,"France",168,72,7,"RCM","GOOD",66000000,78,65,77,81,87,83,20,20,20,20,89},
    {"Kepa",24,"Spain",186,85,1,"GK","GOOD",31000000,20,20,20,20,20,20,85,84,82,80,84},
    {"Azpilicueta",29,"Spain",178,76,28,"RB","GOOD",25500000,70,55,77,73,85,76,20,20,20,20,84},
    {"Jorginho",27,"Italy",180,67,5,"CDM","GOOD",29000000,55,63,84,81,70,73,20,20,20,20,83},
    {"Pedro",31,"Spain",169,65,11,"RW","GOOD",19500000,75,77,77,84,43,56,20,20,20,20,82},
    {"A. Christensen",23,"Denmark",187,81,4,"RCB","GOOD",19000000,68,31,63,68,82,72,20,20,20,20,80},
    {"K. Zouma",24,"France",190,96,15,"LCB","GOOD",17500000,64,51,59,55,78,83,20,20,20,20,80},
    {"C. Pulisic",20,"United States",177,69,22,"LW","GOOD",18000000,90,68,70,84,36,58,20,20,20,20,79},
    {"Emerson",24,"Italy",175,77,33,"LB","GOOD",10500000,79,59,68,78,74,62,20,20,20,20,77},
    {"T. Abraham",21,"England",196,80,9,"ST","GOOD",12000000,74,74,57,69,31,68,20,20,20,20,76},
    {"M. Mount",20,"England",178,64,19,"LCM","GOOD",11500000,71,68,74,76,46,53,20,20,20,20,75}

};
std::vector<Players>ChelseaSubs
{
    {"M. Kovacic",25,"Croatia",176,78,17,"SUB","GOOD",29000000,76,68,81,86,67,70,20,20,20,20,82},
    {"A. Rudiger",26,"Germany",190,85,2,"SUB","GOOD",24000000,72,43,67,63,82,78,20,20,20,20,82},
    {"O.Giroud",32,"France",193,92,18,"SUB","GOOD",17500000,46,81,71,72,42,79,20,20,20,20,82},
    {"Willian",30,"Brazil",175,78,10,"SUB","GOOD",21000000,85,78,80,85,49,60,20,20,20,20,82},
    {"Marcos Alonso",28,"Spain",188,87,3,"SUB","GOOD",15000000,66,73,79,77,79,79,20,20,20,20,81},
    {"R. Loftus-Cheek",23,"England",191,88,12,"SUB","GOOD",17000000,70,67,76,81,62,79,20,20,20,20,79},
    {"R. Barkley",25,"England",185,87,8,"SUB","GOOD",16000000,70,73,77,80,56,73,20,20,20,20,79}

};
Squad Chelsea("Chelsea F.C.", "Premier League", "Frank Lampard", ChelseaInfield, ChelseaSubs, 11, 7);


/**
*       Tottenham F.C.
*/
std::vector<Players>TottenhamInfield
{
    {"H. Kane",25,"England",188,89,10,"ST","GOOD",83000000,70,91,79,81,47,83,20,20,20,20,89},
    {"C. Eriksen",27,"Denmark",181,76,23,"RM","GOOD",68000000,73,81,90,84,53,63,20,20,20,20,88},
    {"H. Lloris",32,"France",188,82,1,"GK","GOOD",36000000,20,20,20,20,20,20,91,89,82,84,88},
    {"H. Son",26,"Korea Republic",183,78,7,"LM","GOOD",60000000,88,86,80,87,42,68,20,20,20,20,87},
    {"J. Vertonghen",32,"Belgium",189,86,5,"LCB","GOOD",32500000,63,63,74,72,87,79,20,20,20,20,87},
    {"T. Alderweireld",30,"Belgium",186,81,4,"RCB","GOOD",41000000,64,55,72,66,88,79,20,20,20,20,87},
    {"D. Alli",23,"England",188,80,20,"CAM","GOOD",41500000,72,81,79,82,71,79,20,20,20,20,84},
    {"T. Ndombele",22,"France",181,76,28,"LDM","GOOD",26000000,80,65,78,87,70,78,20,20,20,20,81},
    {"H. Winks",23,"England",176,74,8,"RDM","GOOD",20000000,70,58,77,83,71,66,20,20,20,20,80},
    {"D. Rose",28,"England",174,76,3,"LB","GOOD",12500000,77,62,74,79,80,75,20,20,20,20,80},
    {"K. Walker-Peters",22,"England",174,64,16,"RB","GOOD",7000000,76,37,66,72,72,66,20,20,20,20,74}

};
std::vector<Players>TottenhamSubs
{
    {"G. Lo Celso",23,"Argentina",177,68,18,"SUB","GOOD",35000000,77,78,82,85,65,72,20,20,20,20,83},
    {"D. SÃ¡nchez",23,"Colombia",187,79,6,"SUB","GOOD",30500000,74,45,57,66,83,81,20,20,20,20,83},
    {"Lucas Moura",26,"Brazil",174,70,27,"SUB","GOOD",31000000,92,79,76,87,42,66,20,20,20,20,83},
    {"M. Sissoko",29,"France",187,91,17,"SUB","GOOD",17000000,80,70,78,79,79,89,20,20,20,20,81},
    {"E. Lamela",27,"Argentina",184,80,11,"SUB","GOOD",15500000,75,77,79,82,51,72,20,20,20,20,80},
    {"E. Dier",25,"England",190,90,15,"SUB","GOOD",14500000,54,63,71,64,80,84,20,20,20,20,79},
    {"B. Davies",26,"Wales",182,76,33,"SUB","GOOD",13500000,73,58,75,75,78,74,20,20,20,20,79}

};
Squad Tottenham("Tottenham Hotspur F.C.", "Premier League", "José Mourinho", TottenhamInfield, TottenhamSubs, 11, 7);



/**
*       Crystal Palace
*/
std::vector<Players>CrystalInfield
{
    {"W. Zaha",26,"Ivory Coast",180,66,11,"LS","GOOD",32000000,91,76,72,88,27,74,20,20,20,20,83},
    {"L. MilivojeviÄ‡",28,"Serbia",186,80,4,"RCM","GOOD",17500000,55,67,76,67,78,84,20,20,20,20,81},
    {"Guaita",32,"Spain",190,80,31,"GK","GOOD",7500000,20,20,20,20,20,20,80,80,80,76,79},
    {"M. Meyer",23,"Germany",173,68,7,"LM","GOOD",13500000,67,62,79,83,65,65,20,20,20,20,78},
    {"A. Townsend",27,"England",178,73,10,"RM","GOOD",11000000,78,77,75,80,38,69,20,20,20,20,78},
    {"J. McArthur",31,"Scotland",178,66,18,"LCM","GOOD",6500000,60,65,72,73,71,75,20,20,20,20,76},
    {"P. van Aanholt",28,"Netherlands",176,67,3,"LB","GOOD",6500000,87,68,70,76,72,71,20,20,20,20,76},
    {"M. Kelly",29,"England",191,77,34,"RCB","GOOD",6500000,50,44,60,61,75,71,20,20,20,20,75},
    {"S. Dann",32,"England",188,78,6,"LCB","GOOD",4300000,32,40,48,47,76,65,20,20,20,20,75},
    {"C. Benteke",28,"Belgium",190,83,17,"RS","GOOD",7000000,58,74,61,65,32,72,20,20,20,20,75},
    {"J. Ward",29,"England",188,83,2,"RB","GOOD",3300000,58,52,66,66,76,71,20,20,20,20,73}

};
std::vector<Players>CrystalSubs
{
    {"M. Sakho",29,"France",187,83,12,"SUB","GOOD",12000000,53,33,65,56,78,83,20,20,20,20,79},
    {"J. Tomkins",30,"England",192,74,5,"SUB","GOOD",8500000,41,32,57,54,80,75,20,20,20,20,78},
    {"G. Cahill",33,"England",193,88,24,"SUB","GOOD",4200000,41,58,51,57,78,74,20,20,20,20,77},
    {"Camarasa",25,"Spain",183,76,23,"SUB","GOOD",10000000,63,73,74,75,69,73,20,20,20,20,76},
    {"C. KouyatÃ©",29,"Senegal",189,83,8,"SUB","GOOD",6500000,69,65,61,69,76,85,20,20,20,20,76},
    {"W. Hennessey",32,"Wales",198,90,13,"SUB","GOOD",4000000,20,20,20,20,20,20,71,75,75,75,75},
    {"J. McCarthy",28,"Republic of Ireland",180,72,22,"SUB","GOOD",6000000,58,60,73,73,74,65,20,20,20,20,75}

};
Squad CrystalPalace("Crystal Palace F.C.", "Premier League", "Roy Hodgson", CrystalInfield, CrystalSubs, 11, 7);


/**
*       Everton
*/
std::vector<Players>EvertonInfield
{
    {"L. Digne",25,"France",178,74,12,"LB","GOOD",28500000,78,69,79,79,80,76,20,20,20,20,83},
    {"J. Pickford",25,"England",185,77,1,"GK","GOOD",24000000,20,20,20,20,20,20,86,82,78,82,83},
    {"G. Sigurdsson",29,"Iceland",186,77,10,"CAM","GOOD",25500000,56,81,84,80,57,69,20,20,20,20,83},
    {"Andre Gomes",25,"Portugal",188,84,21,"LDM","GOOD",17500000,65,71,78,80,73,80,20,20,20,20,80},
    {"M. Keane",26,"England",191,82,5,"RCB","GOOD",16500000,60,49,62,66,80,79,20,20,20,20,80},
    {"Bernard",26,"Brazil",164,60,20,"LM","GOOD",16000000,87,69,76,85,38,44,20,20,20,20,80},
    {"J. Gbamin",23,"Ivory Coast",186,83,25,"RDM","GOOD",15500000,80,57,73,74,78,83,20,20,20,20,79},
    {"Richarlison",22,"Brazil",181,71,7,"RM","GOOD",17000000,84,77,72,81,45,79,20,20,20,20,79},
    {"S. Coleman",30,"Republic of Ireland",177,77,23,"RB","GOOD",10000000,74,65,73,77,79,71,20,20,20,20,79},
    {"Y. Mina",24,"Colombia",195,94,13,"LCB","GOOD",12500000,51,54,55,56,78,80,20,20,20,20,78},
    {"D. Calvert-Lewin",22,"England",187,71,9,"ST","GOOD",12500000,84,70,63,75,38,79,20,20,20,20,77}
};
std::vector<Players>EvertonSubs
{
    {"A. Iwobi",23,"Nigeria",185,75,17,"SUB","GOOD",17000000,80,64,74,83,28,68,20,20,20,20,79},
    {"D. Sidibe",26,"France",182,71,19,"SUB","GOOD",9000000,77,62,74,74,73,79,20,20,20,20,77},
    {"T. Walcott",30,"England",176,68,11,"SUB","GOOD",8500000,87,72,70,79,39,61,20,20,20,20,77},
    {"M. Schneiderlin",29,"France",185,75,18,"SUB","GOOD",7500000,56,60,71,71,75,76,20,20,20,20,77},
    {"F. Delph",29,"England",174,78,8,"SUB","GOOD",7500000,69,70,76,79,73,74,20,20,20,20,77},
    {"C. Tosun",28,"Turkey",183,78,14,"SUB","GOOD",9000000,71,77,66,73,36,73,20,20,20,20,77},
    {"M. Kean",19,"Italy",182,79,27,"SUB","GOOD",14500000,81,72,50,77,30,68,20,20,20,20,76}
};
Squad Everton("Everton F.C.", "Premier League", "Carlo Ancelotti", EvertonInfield, EvertonSubs, 11, 7);


/**
*       Manchester City F.C.
*/
std::vector<Players>ManchesterCInfield
{
    {"K. De Bruyne",28,"Belgium",181,70,17,"RCM","GOOD",90000000,76,86,92,86,61,78,20,20,20,20,91},
    {"S. Aguero",31,"Argentina",173,70,10,"ST","GOOD",60000000,80,90,77,88,33,74,20,20,20,20,89},
    {"Ederson",25,"Brazil",188,86,31,"GK","GOOD",54500000,20,20,20,20,20,20,88,86,82,86,88},
    {"R. Sterling",24,"England",170,69,7,"LW","GOOD",73000000,93,79,78,89,45,57,20,20,20,20,88},
    {"David Silva",33,"Spain",173,67,21,"LCM","GOOD",36000000,65,74,88,89,52,57,20,20,20,20,88},
    {"A. Laporte",25,"France",189,85,14,"LCB","GOOD",56500000,64,50,71,68,88,82,20,20,20,20,87},
    {"Bernardo Silva",24,"Portugal",173,64,20,"RW","GOOD",64000000,81,76,83,92,51,67,20,20,20,20,87},
    {"Fernandinho",34,"Brazil",179,67,25,"CDM","GOOD",19500000,66,74,79,78,84,79,20,20,20,20,87},
    {"K. Walker",29,"England",183,70,2,"RB","GOOD",25500000,91,63,76,77,81,81,20,20,20,20,84},
    {"J. Stones",25,"England",188,70,5,"RCB","GOOD",30000000,68,36,70,72,84,77,20,20,20,20,83},
    {"O. Zinchenko",22,"Ukraine",175,64,11,"LB","GOOD",13000000,71,66,80,79,77,66,20,20,20,20,78}

};
std::vector<Players>ManchesterCSubs
{
    {"L. Sane",23,"Germany",183,75,19,"SUB","GOOD",61000000,95,81,79,86,38,70,20,20,20,20,86},
    {"Rodri",23,"Spain",191,82,16,"SUB","GOOD",47000000,67,68,77,77,82,80,20,20,20,20,85},
    {"Joao Cancelo",25,"Portugal",182,74,27,"SUB","GOOD",36500000,90,65,80,84,78,71,20,20,20,20,84},
    {"I. Gundogan",28,"Germany",180,80,8,"SUB","GOOD",31000000,66,74,84,84,72,71,20,20,20,20,84},
    {"R. Mahrez",28,"Algeria",179,67,26,"SUB","GOOD",31500000,84,78,79,89,38,59,20,20,20,20,84},
    {"N. Otamendi",31,"Argentina",183,81,30,"SUB","GOOD",19000000,56,57,63,59,83,78,20,20,20,20,83},
    {"Gabriel Jesus",22,"Brazil",175,73,9,"SUB","GOOD",31000000,85,80,72,86,39,71,20,20,20,20,82}

};
Squad ManchesterCity("Manchester City F.C.", "Premier League", "Pep Guardiola", ManchesterCInfield, ManchesterCSubs, 11, 7);


/**
*       Leicester City F. C.
*/
std::vector<Players>LeicesterInfield
{
    {"K. Schmeichel",32,"Denmark",189,89,1,"GK","GOOD",15500000,20,20,20,20,20,20,88,82,77,79,83},
    {"Ricardo Pereira",25,"Portugal",175,70,21,"RB","GOOD",23500000,86,64,77,81,79,73,20,20,20,20,82},
    {"J. Vardy",32,"England",179,74,9,"ST","GOOD",17500000,88,81,65,74,55,75,20,20,20,20,82},
    {"W. Ndidi",22,"Nigeria",183,74,25,"CDM","GOOD",20500000,71,62,67,74,83,82,20,20,20,20,81},
    {"Y. Tielemans",22,"Belgium",176,72,8,"RCM","GOOD",20500000,63,78,82,78,68,67,20,20,20,20,80},
    {"B. Chilwell",22,"England",178,77,3,"LB","GOOD",15500000,78,49,71,77,76,75,20,20,20,20,79},
    {"J. Maddison",22,"England",175,73,10,"LW","GOOD",17000000,75,72,82,79,39,57,20,20,20,20,79},
    {"J. Evans",31,"Northern Ireland",188,77,6,"RCB","GOOD",9500000,56,32,59,53,80,75,20,20,20,20,79},
    {"Ayoze Perez",25,"Spain",178,72,17,"RW","GOOD",13000000,76,75,67,81,54,66,20,20,20,20,78},
    {"H. Choudhury",21,"England",178,64,20,"LCM","GOOD",8000000,70,44,61,66,76,75,20,20,20,20,74},
    {"C. Soyuncu",23,"Turkey",185,82,4,"LCB","GOOD",7500000,63,45,52,59,74,74,20,20,20,20,74}
};
std::vector<Players>LeicesterSubs
{
    {"F. Benkovic",21,"Croatia",194,91,16,"SUB","GOOD",11000000,64,46,56,56,75,82,20,20,20,20,76},
    {"D. Praet",25,"Belgium",181,78,26,"SUB","GOOD",10000000,69,70,77,78,61,64,20,20,20,20,76},
    {"M. Albrighton",29,"England",175,74,11,"SUB","GOOD",7500000,70,68,75,77,59,69,20,20,20,20,76},
    {"H. Barnes",21,"England",174,66,19,"SUB","GOOD",11000000,78,69,71,76,45,57,20,20,20,20,75},
    {"D. Gray",23,"England",180,74,7,"SUB","GOOD",9000000,88,67,67,81,37,55,20,20,20,20,75},
    {"W. Morgan",35,"Jamaica",186,101,5,"SUB","GOOD",2000000,29,34,41,55,76,72,20,20,20,20,75},
    {"R. Ghezzal",27,"Algeria",182,70,31,"SUB","GOOD",6000000,72,68,74,78,28,58,20,20,20,20,74}

};
Squad Leicester("Leicester City F.C.", "Premier League", "Brendan Rodgers", LeicesterInfield, LeicesterSubs, 11, 7);



#endif // DBS2_H_INCLUDED
