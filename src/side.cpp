#include "side.hpp"
using namespace std;
#define COMMENTS 0


std::vector <Player> getPlayersFromData(std::string teamname);
Side::Side(){
    baseline_chance = 0.015;
    name = "defaut_name";
    goals = 0;
}

void Side::VaryChanceOverTime(int t){
    double a = baseline_chance*0.9;
    double b = baseline_chance*1.1;
    double step = ((b-a)/90);
    scoring_chance = a + t*step;
}


int Side::GoalScored(){
    goals++;
    Player scorer = GetGoalscorer();
    if(comments)
        cout << "GOAL to " << name << " [" << scorer.name << "]   ";
    
}

void Side::RedCard(){
    red_cards++;
    //Reduce scoring chance by 0.8
    ModifyBaseline(0.7);
    if(comments)
        cout << "RED CARD to " << name;
    
}

void Side::GetPlayers(std::string teamname){
    VectorPlayers = getPlayersFromData(teamname);
}

// Generate goalscorer based off xG data for each player
Player Side::GetGoalscorer(){
    vector <Player> players = VectorPlayers;
    float totalxG = 0;
    float running=0;
    Player scorer("name",0.5);
    
    for(unsigned int i=0;i<players.size();i++){
        totalxG += players[i].xG;
    }
    //Normalize xG to stack in a range 0 to 1
    for(unsigned int i=0;i<players.size();i++){
        players[i].xG = players[i].xG / totalxG;
        players[i].xG += running;
        running = players[i].xG;
    }
    float random =  (double)rand() / (double)RAND_MAX;
    
    for(unsigned int i=0;i<players.size();i++){
        
        if(random <= players[i].xG){
            scorer = players[i];
            break;
        }

    }
    return scorer;

}

std::vector <Player> getPlayersFromData(std::string teamname){
    std::vector <Player> team;
    if(teamname == "Arsenal"){
team.push_back(Player("Runar Alex Runarsson",0.0));
team.push_back(Player("Pierre Emerick Aubameyang",10.6));
team.push_back(Player("Hector Bellerin",0.8));
team.push_back(Player("Dani Ceballos",0.7));
team.push_back(Player("Calum Chambers",0.6));
team.push_back(Player("Gabriel Dos Santos",1.0));
team.push_back(Player("Mohamed Elneny",0.5));
team.push_back(Player("Rob Holding",1.1));
team.push_back(Player("Sead Kolasinac",0.0));
team.push_back(Player("Alexandre Lacazette",9.7));
team.push_back(Player("Bernd Leno",0.0));
team.push_back(Player("David Luiz",0.9));
team.push_back(Player("Ainsley Maitland Niles",0.1));
team.push_back(Player("Pablo Mari",0.0));
team.push_back(Player("Martinelli",3.4));
team.push_back(Player("Shkodran Mustafi",0.0));
team.push_back(Player("Reiss Nelson",0.0));
team.push_back(Player("Eddie Nketiah",2.4));
team.push_back(Player("Thomas Partey",1.3));
team.push_back(Player("Nicolas Pepe",7.0));
team.push_back(Player("Mathew Ryan",0.0));
team.push_back(Player("Bukayo Saka",6.9));
team.push_back(Player("Emile Smith Rowe",2.0));
team.push_back(Player("Cedric Soares",0.2));
team.push_back(Player("Kieran Tierney",0.4));
team.push_back(Player("Willian",2.1));
team.push_back(Player("Joe Willock",0.4));
team.push_back(Player("Granit Xhaka",0.8));
team.push_back(Player("Martin Odegaard",1.1));
}

if(teamname == "Aston_Villa"){
team.push_back(Player("Ross Barkley",3.2));
team.push_back(Player("Matty Cash",0.3));
team.push_back(Player("Carney Chukwuemeka",0.1));
team.push_back(Player("Keinan Davis",1.0));
team.push_back(Player("Ahmed Elmohamady",0.5));
team.push_back(Player("Anwar El Ghazi",8.1));
team.push_back(Player("Jack Grealish",4.3));
team.push_back(Player("Kortney Hause",1.2));
team.push_back(Player("Conor Hourihane",0.5));
team.push_back(Player("Ezri Konsa",2.2));
team.push_back(Player("Douglas Luiz",1.5));
team.push_back(Player("Emiliano Martinez",0.0));
team.push_back(Player("John McGinn",2.2));
team.push_back(Player("Tyrone Mings",1.9));
team.push_back(Player("Wesley Moraes",0.0));
team.push_back(Player("Marvelous Nakamba",0.0));
team.push_back(Player("Jaden Philogene Bidace",0.0));
team.push_back(Player("Jacob Ramsey",0.5));
team.push_back(Player("Morgan Sanson",0.0));
team.push_back(Player("Matt Targett",0.2));
team.push_back(Player("Neil Taylor",0.0));
team.push_back(Player("Bertrand Traore",6.4));
team.push_back(Player("Trezeguet",3.8));
team.push_back(Player("Ollie Watkins",16.0));
}

if(teamname == "Brighton"){
team.push_back(Player("Steven Alzate",0.7));
team.push_back(Player("Bernardo",0.3));
team.push_back(Player("Yves Bissouma",1.2));
team.push_back(Player("Dan Burn",1.5));
team.push_back(Player("Aaron Connolly",3.5));
team.push_back(Player("Lewis Dunk",2.5));
team.push_back(Player("Pascal Gross",5.6));
team.push_back(Player("Jose Izquierdo",0.0));
team.push_back(Player("Alireza Jahanbakhsh",1.6));
team.push_back(Player("Reda Khadra",0.0));
team.push_back(Player("Adam Lallana",2.4));
team.push_back(Player("Tariq Lamptey",0.6));
team.push_back(Player("Alexis Mac Allister",1.1));
team.push_back(Player("Solly March",1.7));
team.push_back(Player("Neal Maupay",13.0));
team.push_back(Player("Jakub Moder",0.9));
team.push_back(Player("Jayson Molumby",0.0));
team.push_back(Player("Davy Propper",0.1));
team.push_back(Player("Mathew Ryan",0.0));
team.push_back(Player("Robert Sanchez",0.0));
team.push_back(Player("Percy Tau",0.0));
team.push_back(Player("Leandro Trossard",5.1));
team.push_back(Player("Joel Veltman",1.4));
team.push_back(Player("Adam Webster",1.2));
team.push_back(Player("Danny Welbeck",6.8));
team.push_back(Player("Ben White",0.7));
team.push_back(Player("Andi Zeqiri",0.6));
}

if(teamname == "Burnley"){
team.push_back(Player("Phil Bardsley",0.1));
team.push_back(Player("Ashley Barnes",5.1));
team.push_back(Player("Josh Benson",0.2));
team.push_back(Player("Johann Berg Gudmundsson",1.7));
team.push_back(Player("Robbie Brady",0.8));
team.push_back(Player("Josh Brownhill",1.9));
team.push_back(Player("Jack Cork",0.3));
team.push_back(Player("Jimmy Dunne",0.4));
team.push_back(Player("Kevin Long",0.3));
team.push_back(Player("Matthew Lowton",0.7));
team.push_back(Player("Dwight McNeil",1.1));
team.push_back(Player("Ben Mee",1.6));
team.push_back(Player("Joel Mumbongo",0.0));
team.push_back(Player("Will Norris",0.0));
team.push_back(Player("Bailey Peacock Farrell",0.0));
team.push_back(Player("Erik Pieters",0.2));
team.push_back(Player("Nick Pope",0.0));
team.push_back(Player("Lewis Richardson",0.0));
team.push_back(Player("Jay Rodriguez",2.6));
team.push_back(Player("Dale Stephens",0.2));
team.push_back(Player("James Tarkowski",2.6));
team.push_back(Player("Charlie Taylor",0.1));
team.push_back(Player("Matej Vydra",6.1));
team.push_back(Player("Ashley Westwood",1.1));
team.push_back(Player("Chris Wood",13.3));
}

if(teamname == "Chelsea"){
team.push_back(Player("Tammy Abraham",6.4));
team.push_back(Player("Marcos Alonso",1.7));
team.push_back(Player("Kepa Arrizabalaga",0.0));
team.push_back(Player("Cesar Azpilicueta",0.8));
team.push_back(Player("Ross Barkley",0.0));
team.push_back(Player("Willy Caballero",0.0));
team.push_back(Player("Ben Chilwell",2.4));
team.push_back(Player("Andreas Christensen",0.1));
team.push_back(Player("Billy Gilmour",0.0));
team.push_back(Player("Olivier Giroud",4.8));
team.push_back(Player("Kai Havertz",6.3));
team.push_back(Player("Callum Hudson Odoi",1.4));
team.push_back(Player("Reece James",1.6));
team.push_back(Player("Jorginho",7.0));
team.push_back(Player("NGolo Kante",0.9));
team.push_back(Player("Mateo Kovacic",1.0));
team.push_back(Player("Ruben Loftus Cheek",0.0));
team.push_back(Player("Edouard Mendy",0.0));
team.push_back(Player("Mason Mount",6.8));
team.push_back(Player("Emerson Palmieri",0.0));
team.push_back(Player("Christian Pulisic",5.4));
team.push_back(Player("Antonio Rudiger",1.1));
team.push_back(Player("Thiago Silva",1.1));
team.push_back(Player("Fikayo Tomori",0.0));
team.push_back(Player("Timo Werner",11.9));
team.push_back(Player("Hakim Ziyech",1.9));
team.push_back(Player("Kurt Zouma",1.8));
}

if(teamname == "Brighton"){
team.push_back(Player("Steven Alzate",0.7));
team.push_back(Player("Bernardo",0.3));
team.push_back(Player("Yves Bissouma",1.2));
team.push_back(Player("Dan Burn",1.5));
team.push_back(Player("Aaron Connolly",3.5));
team.push_back(Player("Lewis Dunk",2.5));
team.push_back(Player("Pascal Gross",5.6));
team.push_back(Player("Jose Izquierdo",0.0));
team.push_back(Player("Alireza Jahanbakhsh",1.6));
team.push_back(Player("Reda Khadra",0.0));
team.push_back(Player("Adam Lallana",2.4));
team.push_back(Player("Tariq Lamptey",0.6));
team.push_back(Player("Alexis Mac Allister",1.1));
team.push_back(Player("Solly March",1.7));
team.push_back(Player("Neal Maupay",13.0));
team.push_back(Player("Jakub Moder",0.9));
team.push_back(Player("Jayson Molumby",0.0));
team.push_back(Player("Davy Propper",0.1));
team.push_back(Player("Mathew Ryan",0.0));
team.push_back(Player("Robert Sanchez",0.0));
team.push_back(Player("Percy Tau",0.0));
team.push_back(Player("Leandro Trossard",5.1));
team.push_back(Player("Joel Veltman",1.4));
team.push_back(Player("Adam Webster",1.2));
team.push_back(Player("Danny Welbeck",6.8));
team.push_back(Player("Ben White",0.7));
team.push_back(Player("Andi Zeqiri",0.6));
}

if(teamname == "Everton"){
team.push_back(Player("Allan",0.2));
team.push_back(Player("Bernard",0.2));
team.push_back(Player("Nathan Broadhead",0.0));
team.push_back(Player("Dominic Calvert Lewin",15.4));
team.push_back(Player("Seamus Coleman",1.2));
team.push_back(Player("Tom Davies",0.2));
team.push_back(Player("Fabian Delph",0.0));
team.push_back(Player("Lucas Digne",0.6));
team.push_back(Player("Abdoulaye Doucoure",2.1));
team.push_back(Player("Jean Philippe Gbamin",0.0));
team.push_back(Player("Ben Godfrey",0.9));
team.push_back(Player("Andre Gomes",0.5));
team.push_back(Player("Anthony Gordon",0.0));
team.push_back(Player("Mason Holgate",0.8));
team.push_back(Player("Alex Iwobi",1.1));
team.push_back(Player("Moise Kean",0.0));
team.push_back(Player("Michael Keane",1.2));
team.push_back(Player("Jonjoe Kenny",0.0));
team.push_back(Player("Joshua King",0.8));
team.push_back(Player("Yerry Mina",1.3));
team.push_back(Player("Niels Nkounkou",0.0));
team.push_back(Player("Robin Olsen",0.0));
team.push_back(Player("Jordan Pickford",0.0));
team.push_back(Player("Richarlison",11.5));
team.push_back(Player("James Rodriguez",3.4));
team.push_back(Player("Gylfi Sigurdsson",6.8));
team.push_back(Player("Cenk Tosun",0.0));
team.push_back(Player("Joao Virginia",0.0));
team.push_back(Player("Theo Walcott",0.0));
}

if(teamname == "Fulham"){
team.push_back(Player("Tosin Adarabioyo",1.1));
team.push_back(Player("Ola Aina",1.0));
team.push_back(Player("Joachim Andersen",1.1));
team.push_back(Player("Alphonse Areola",0.0));
team.push_back(Player("Joe Bryan",0.4));
team.push_back(Player("Tom Cairney",0.7));
team.push_back(Player("Fabio Carvalho",1.1));
team.push_back(Player("Ivan Cavaleiro",5.4));
team.push_back(Player("Tyrese Francois",0.0));
team.push_back(Player("Michael Hector",0.1));
team.push_back(Player("Aboubakar Kamara",0.4));
team.push_back(Player("Neeskens Kebano",0.3));
team.push_back(Player("Terence Kongolo",0.0));
team.push_back(Player("Maxime Le Marchand",0.0));
team.push_back(Player("Mario Lemina",0.9));
team.push_back(Player("Ruben Loftus Cheek",3.1));
team.push_back(Player("Ademola Lookman",5.5));
team.push_back(Player("Josh Maja",4.8));
team.push_back(Player("Aleksandar Mitrovic",6.5));
team.push_back(Player("Denis Odoi",0.1));
team.push_back(Player("Josh Onomah",0.6));
team.push_back(Player("Tim Ream",0.0));
team.push_back(Player("Harrison Reed",0.3));
team.push_back(Player("Bobby Reid",4.8));
team.push_back(Player("Antonee Robinson",0.6));
team.push_back(Player("Marek Rodak",0.0));
team.push_back(Player("Kenny Tete",0.2));
team.push_back(Player("Andre Frank Zambo Anguissa",1.8));
}

if(teamname == "Leeds United"){
team.push_back(Player("Ezgjan Alioski",1.5));
team.push_back(Player("Luke Ayling",1.4));
team.push_back(Player("Patrick Bamford",17.3));
team.push_back(Player("Gaetano Berardi",0.0));
team.push_back(Player("Ian Carlo Poveda",0.4));
team.push_back(Player("Kiko Casilla",0.0));
team.push_back(Player("Liam Cooper",1.3));
team.push_back(Player("Helder Costa",2.0));
team.push_back(Player("Stuart Dallas",4.6));
team.push_back(Player("Leif Davis",0.0));
team.push_back(Player("Raphael Dias Belloli",6.0));
team.push_back(Player("Jack Harrison",6.6));
team.push_back(Player("Pablo Hernandez",1.2));
team.push_back(Player("Niall Huggins",0.0));
team.push_back(Player("Mateusz Klich",3.3));
team.push_back(Player("Robin Koch",0.8));
team.push_back(Player("Diego Llorente",0.7));
team.push_back(Player("Illan Meslier",0.0));
team.push_back(Player("Kalvin Phillips",0.4));
team.push_back(Player("Tyler Roberts",2.1));
team.push_back(Player("Rodrigo",6.3));
team.push_back(Player("Jamie Shackleton",0.0));
team.push_back(Player("Pascal Struijk",2.4));
}

if(teamname == "Leicester"){
team.push_back(Player("Marc Albrighton",1.3));
team.push_back(Player("Daniel Amartey",0.4));
team.push_back(Player("Harvey Barnes",6.2));
team.push_back(Player("Timothy Castagne",1.3));
team.push_back(Player("Hamza Choudhury",0.4));
team.push_back(Player("Jonny Evans",1.7));
team.push_back(Player("Wesley Fofana",1.0));
team.push_back(Player("Christian Fuchs",0.1));
team.push_back(Player("Demarai Gray",0.1));
team.push_back(Player("Kelechi Iheanacho",7.8));
team.push_back(Player("James Justin",1.6));
team.push_back(Player("Khanya Leshabela",0.0));
team.push_back(Player("James Maddison",4.4));
team.push_back(Player("Nampalys Mendy",0.1));
team.push_back(Player("Wes Morgan",0.0));
team.push_back(Player("Wilfred Ndidi",0.8));
team.push_back(Player("Ricardo Pereira",0.4));
team.push_back(Player("Ayoze Perez",3.2));
team.push_back(Player("Dennis Praet",0.5));
team.push_back(Player("Kasper Schmeichel",0.0));
team.push_back(Player("Islam Slimani",0.0));
team.push_back(Player("Caglar Soyuncu",0.5));
team.push_back(Player("Sidnei Tavares",0.1));
team.push_back(Player("Luke Thomas",0.3));
team.push_back(Player("Youri Tielemans",4.5));
team.push_back(Player("Cengiz Under",0.3));
team.push_back(Player("Jamie Vardy",19.7));
}

if(teamname == "Liverpool"){
team.push_back(Player("Adrian",0.0));
team.push_back(Player("Thiago Alcantara",1.4));
team.push_back(Player("Trent Alexander Arnold",2.8));
team.push_back(Player("Alisson",0.1));
team.push_back(Player("Virgil van Dijk",0.3));
team.push_back(Player("Fabinho",0.4));
team.push_back(Player("Roberto Firmino",12.6));
team.push_back(Player("Joe Gomez",0.0));
team.push_back(Player("Jordan Henderson",1.7));
team.push_back(Player("Curtis Jones",1.4));
team.push_back(Player("Diogo Jota",6.6));
team.push_back(Player("Ozan Kabak",0.1));
team.push_back(Player("Naby Keita",0.5));
team.push_back(Player("Caoimhin Kelleher",0.0));
team.push_back(Player("Sadio Mane",15.2));
team.push_back(Player("Joel Matip",0.6));
team.push_back(Player("James Milner",0.4));
team.push_back(Player("Takumi Minamino",0.7));
team.push_back(Player("Divock Origi",1.0));
team.push_back(Player("Alex Oxlade Chamberlain",0.4));
team.push_back(Player("Nathaniel Phillips",1.1));
team.push_back(Player("Andrew Robertson",1.4));
team.push_back(Player("Mohamed Salah",20.9));
team.push_back(Player("Xherdan Shaqiri",0.4));
team.push_back(Player("Kostas Tsimikas",0.0));
team.push_back(Player("Georginio Wijnaldum",3.2));
team.push_back(Player("Neco Williams",0.1));
team.push_back(Player("Rhys Williams",0.5));
}

if(teamname == "Man_C"){
team.push_back(Player("Sergio Aguero",3.4));
team.push_back(Player("Nathan Ake",0.1));
team.push_back(Player("Joao Cancelo",2.0));
team.push_back(Player("Scott Carson",0.0));
team.push_back(Player("Kevin De Bruyne",9.7));
team.push_back(Player("Liam Delap",0.0));
team.push_back(Player("Ruben Dias",2.4));
team.push_back(Player("Ederson",0.0));
team.push_back(Player("Fernandinho",0.8));
team.push_back(Player("Phil Foden",5.5));
team.push_back(Player("Eric Garcia",0.1));
team.push_back(Player("Ilkay Gundogan",9.0));
team.push_back(Player("Gabriel Jesus",8.8));
team.push_back(Player("Aymeric Laporte",0.8));
team.push_back(Player("Riyad Mahrez",5.6));
team.push_back(Player("Benjamin Mendy",0.4));
team.push_back(Player("Rodri",2.5));
team.push_back(Player("Bernardo Silva",2.8));
team.push_back(Player("Zack Steffen",0.0));
team.push_back(Player("Raheem Sterling",12.2));
team.push_back(Player("John Stones",2.2));
team.push_back(Player("Ferran Torres",5.4));
team.push_back(Player("Kyle Walker",0.2));
team.push_back(Player("Oleksandr Zinchenko",0.7));
}

if(teamname == "Man_C"){
team.push_back(Player("Eric Bailly",0.1));
team.push_back(Player("Donny van de Beek",0.3));
team.push_back(Player("Edinson Cavani",7.4));
team.push_back(Player("Amad Diallo",0.0));
team.push_back(Player("Anthony Elanga",0.3));
team.push_back(Player("Bruno Fernandes",15.4));
team.push_back(Player("Timothy Fosu Mensah",0.0));
team.push_back(Player("Fred",1.9));
team.push_back(Player("David de Gea",0.0));
team.push_back(Player("Mason Greenwood",7.4));
team.push_back(Player("Dean Henderson",0.0));
team.push_back(Player("Odion Ighalo",0.0));
team.push_back(Player("Daniel James",2.3));
team.push_back(Player("Victor Lindelof",0.7));
team.push_back(Player("Harry Maguire",2.1));
team.push_back(Player("Anthony Martial",6.5));
team.push_back(Player("Juan Mata",1.1));
team.push_back(Player("Nemanja Matic",0.3));
team.push_back(Player("Scott McTominay",2.1));
team.push_back(Player("Hannibal Mejbri",0.0));
team.push_back(Player("Paul Pogba",2.1));
team.push_back(Player("Marcus Rashford",9.3));
team.push_back(Player("Luke Shaw",0.7));
team.push_back(Player("Shola Shoretire",0.0));
team.push_back(Player("Alex Telles",0.2));
team.push_back(Player("William Thomas Fish",0.0));
team.push_back(Player("Axel Tuanzebe",0.0));
team.push_back(Player("Aaron Wan Bissaka",0.9));
team.push_back(Player("Brandon Williams",0.1));
}

if(teamname == "Newcastle"){
team.push_back(Player("Miguel Almiron",3.2));
team.push_back(Player("Elliot Anderson",0.0));
team.push_back(Player("Andy Carroll",1.2));
team.push_back(Player("Ciaran Clark",0.3));
team.push_back(Player("Karl Darlow",0.0));
team.push_back(Player("Martin Dubravka",0.0));
team.push_back(Player("Paul Dummett",0.3));
team.push_back(Player("Federico Fernandez",0.3));
team.push_back(Player("Ryan Fraser",0.9));
team.push_back(Player("Dwight Gayle",2.0));
team.push_back(Player("Isaac Hayden",0.5));
team.push_back(Player("Jeff Hendrick",1.1));
team.push_back(Player("Joelinton",6.1));
team.push_back(Player("Emil Krafth",0.2));
team.push_back(Player("Jamaal Lascelles",1.0));
team.push_back(Player("Jamal Lewis",0.2));
team.push_back(Player("Matthew Longstaff",0.0));
team.push_back(Player("Sean Longstaff",1.4));
team.push_back(Player("Javier Manquillo",0.0));
team.push_back(Player("Jacob Murphy",1.2));
team.push_back(Player("Matt Ritchie",0.4));
team.push_back(Player("Allan Saint Maximin",2.6));
team.push_back(Player("Fabian Schar",1.2));
team.push_back(Player("Jonjo Shelvey",2.5));
team.push_back(Player("Joe Willock",3.6));
team.push_back(Player("Callum Wilson",11.3));
team.push_back(Player("DeAndre Yedlin",0.1));
}

if(teamname == "Sheffield"){
team.push_back(Player("Ethan Ampadu",0.3));
team.push_back(Player("George Baldock",1.1));
team.push_back(Player("Chris Basham",0.8));
team.push_back(Player("Sander Berge",1.2));
team.push_back(Player("Jayden Bogle",1.8));
team.push_back(Player("Rhian Brewster",1.7));
team.push_back(Player("Kean Bryan",0.4));
team.push_back(Player("Oliver Burke",2.4));
team.push_back(Player("John Egan",0.7));
team.push_back(Player("John Fleck",0.9));
team.push_back(Player("Antwoine Hackford",0.1));
team.push_back(Player("Phil Jagielka",0.0));
team.push_back(Player("Daniel Jebbison",1.6));
team.push_back(Player("Max Lowe",0.1));
team.push_back(Player("John Lundstram",2.0));
team.push_back(Player("Oliver McBurnie",3.1));
team.push_back(Player("David McGoldrick",6.9));
team.push_back(Player("Lys Mousset",0.7));
team.push_back(Player("Iliman Ndiaye",0.0));
team.push_back(Player("Oliver Norwood",0.5));
team.push_back(Player("Jack OConnell",0.0));
team.push_back(Player("Ben Osborn",1.2));
team.push_back(Player("Aaron Ramsdale",0.0));
team.push_back(Player("Jack Robinson",0.4));
team.push_back(Player("Femi Seriki",0.0));
team.push_back(Player("Billy Sharp",2.7));
team.push_back(Player("Enda Stevens",1.1));
}

if(teamname == "Southampton"){
team.push_back(Player("Che Adams",8.8));
team.push_back(Player("Stuart Armstrong",3.0));
team.push_back(Player("Jan Bednarek",1.0));
team.push_back(Player("Ryan Bertrand",0.6));
team.push_back(Player("Ibrahima Diallo",0.6));
team.push_back(Player("Moussa Djenepo",0.9));
team.push_back(Player("Fraser Forster",0.0));
team.push_back(Player("Danny Ings",8.3));
team.push_back(Player("Alexandre Jankewitz",0.0));
team.push_back(Player("Shane Long",0.0));
team.push_back(Player("Alex McCarthy",0.0));
team.push_back(Player("Takumi Minamino",1.2));
team.push_back(Player("Dan Nlundulu",0.1));
team.push_back(Player("Michael Obafemi",0.0));
team.push_back(Player("Kayne Ramsey",0.0));
team.push_back(Player("Nathan Redmond",3.3));
team.push_back(Player("Oriol Romeu",0.4));
team.push_back(Player("Mohammed Salisu",0.4));
team.push_back(Player("William Smallbone",0.1));
team.push_back(Player("Jack Stephens",0.7));
team.push_back(Player("Allan Tchaptchet",0.0));
team.push_back(Player("Nathan Tella",1.8));
team.push_back(Player("Yan Valery",0.3));
team.push_back(Player("Jannik Vestergaard",2.1));
team.push_back(Player("Jake Vokins",0.0));
team.push_back(Player("Theo Walcott",3.0));
team.push_back(Player("Kyle Walker Peters",1.1));
team.push_back(Player("James Ward Prowse",5.3));
team.push_back(Player("Caleb Watts",0.0));
}

if(teamname == "Tottenham"){
team.push_back(Player("Toby Alderweireld",0.8));
team.push_back(Player("Dele Alli",1.4));
team.push_back(Player("Serge Aurier",1.4));
team.push_back(Player("Gareth Bale",5.3));
team.push_back(Player("Steven Bergwijn",2.5));
team.push_back(Player("Ben Davies",0.2));
team.push_back(Player("Eric Dier",0.9));
team.push_back(Player("Matt Doherty",0.4));
team.push_back(Player("Son Heung min",10.3));
team.push_back(Player("Pierre Hojbjerg",1.1));
team.push_back(Player("Harry Kane",20.5));
team.push_back(Player("Erik Lamela",1.4));
team.push_back(Player("Hugo Lloris",0.0));
team.push_back(Player("Giovani Lo Celso",1.2));
team.push_back(Player("Lucas Moura",2.2));
team.push_back(Player("Tanguy Ndombele",1.4));
team.push_back(Player("Sergio Reguilon",1.6));
team.push_back(Player("Joe Rodon",0.0));
team.push_back(Player("Davinson Sanchez",1.1));
team.push_back(Player("Dane Scarlett",0.0));
team.push_back(Player("Moussa Sissoko",0.4));
team.push_back(Player("Japhet Tanganga",0.2));
team.push_back(Player("Carlos Vinicius",1.4));
team.push_back(Player("Harry Winks",0.1));
}

if(teamname == "West_Brom"){
team.push_back(Player("Semi Ajayi",1.3));
team.push_back(Player("Charlie Austin",0.2));
team.push_back(Player("Kyle Bartley",2.1));
team.push_back(Player("David Button",0.0));
team.push_back(Player("Mbaye Diagne",5.0));
team.push_back(Player("Grady Diangana",1.2));
team.push_back(Player("Kyle Edwards",0.1));
team.push_back(Player("Sam Field",0.0));
team.push_back(Player("Darnell Furlong",2.0));
team.push_back(Player("Conor Gallagher",1.8));
team.push_back(Player("Kieran Gibbs",0.0));
team.push_back(Player("Karlan Grant",2.1));
team.push_back(Player("Kamil Grosicki",0.1));
team.push_back(Player("Rekeem Harper",0.0));
team.push_back(Player("Ahmed Hegazi",0.0));
team.push_back(Player("Branislav Ivanovic",0.6));
team.push_back(Player("Sam Johnstone",0.0));
team.push_back(Player("Filip Krovinovic",0.2));
team.push_back(Player("Jake Livermore",0.2));
team.push_back(Player("Ainsley Maitland Niles",0.7));
team.push_back(Player("Dara OShea",0.2));
team.push_back(Player("Lee Peltier",0.0));
team.push_back(Player("Matheus Pereira",7.2));
team.push_back(Player("Matt Phillips",2.5));
team.push_back(Player("Callum Robinson",3.1));
team.push_back(Player("Hal Robson Kanu",1.5));
team.push_back(Player("Romaine Sawyers",0.1));
team.push_back(Player("Robert Snodgrass",0.2));
team.push_back(Player("Conor Townsend",1.0));
team.push_back(Player("Okay Yokuslu",0.9));
}

if(teamname == "West_Ham"){
team.push_back(Player("Felipe Anderson",0.0));
team.push_back(Player("Michail Antonio",11.4));
team.push_back(Player("Fabian Balbuena",0.6));
team.push_back(Player("Said Benrahma",2.3));
team.push_back(Player("Jarrod Bowen",6.3));
team.push_back(Player("Vladimir Coufal",1.2));
team.push_back(Player("Aaron Cresswell",0.9));
team.push_back(Player("Craig Dawson",1.7));
team.push_back(Player("Issa Diop",0.3));
team.push_back(Player("Lukasz Fabianski",0.0));
team.push_back(Player("Pablo Fornals",6.5));
team.push_back(Player("Ryan Fredericks",0.3));
team.push_back(Player("Sebastien Haller",2.9));
team.push_back(Player("Ben Johnson",0.4));
team.push_back(Player("Manuel Lanzini",1.2));
team.push_back(Player("Jesse Lingard",5.1));
team.push_back(Player("Arthur Masuaku",0.3));
team.push_back(Player("Mark Noble",0.0));
team.push_back(Player("Angelo Ogbonna",1.5));
team.push_back(Player("Darren Randolph",0.0));
team.push_back(Player("Declan Rice",3.0));
team.push_back(Player("Robert Snodgrass",0.0));
team.push_back(Player("Tomas Soucek",9.2));
team.push_back(Player("Andriy Yarmolenko",0.4));
}

if(teamname == "Wolves"){
team.push_back(Player("Rayan Ait Nouri",0.6));
team.push_back(Player("Willy Boly",1.1));
team.push_back(Player("Oskar Buur",0.0));
team.push_back(Player("Jonny Castro",0.1));
team.push_back(Player("Conor Coady",1.3));
team.push_back(Player("Theo Corbeanu",0.0));
team.push_back(Player("Patrick Cutrone",0.2));
team.push_back(Player("Leander Dendoncker",3.3));
team.push_back(Player("Morgan Gibbs White",1.0));
team.push_back(Player("Ki Jana Hoever",0.1));
team.push_back(Player("Raul Jimenez",2.4));
team.push_back(Player("Willian Jose",1.9));
team.push_back(Player("Max Kilman",0.4));
team.push_back(Player("Fernando Marcal",0.1));
team.push_back(Player("Joao Moutinho",0.7));
team.push_back(Player("Pedro Neto",4.8));
team.push_back(Player("Ruben Neves",5.1));
team.push_back(Player("Owen Otasowie",0.6));
team.push_back(Player("Rui Patricio",0.0));
team.push_back(Player("Daniel Podence",3.1));
team.push_back(Player("John Ruddy",0.0));
team.push_back(Player("Romain Saiss",3.5));
team.push_back(Player("Nelson Semedo",1.9));
team.push_back(Player("Fabio Silva",6.0));
team.push_back(Player("Adama Traore",2.2));
team.push_back(Player("Ruben Vinagre",0.0));
team.push_back(Player("Vitinha",0.6));
}

return team;

}