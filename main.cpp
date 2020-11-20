//Dr. Tyson McMillan Football Scoreboard using 
//Object Oriented Programming in C++
//Ashley Ramos

#include <iostream>
#include <string> 
#include <unistd.h>

using namespace std; 

class Team 
{
  private:
    int Score; 
    bool Home_Status; 
    string Name; 
    int Timeout_Count;
    string Coach_Name;
    string Home_City;
    bool ball_status;

  public:
      Team() //default constructor 
      {
        Score = 0; 
        Home_Status = false; //visitor = false, home = true
        Name = "DefaultTeamName"; 
        Timeout_Count = 0;
        Home_City = "DefaultCity";
        Coach_Name = "DefaultCoachName"; 
        bool ball_status = false;
      }
      void setScore(int s) { Score = s; }
      void setHomeStatus(bool hs) { Home_Status = hs; }
      void setName(string n) { Name = n; }
      void setTimeoutCount(int toc) { Timeout_Count = toc; }
      void setHomeCity(string hc) {Home_City = hc;}
      void setCoachName(string cn) {Coach_Name = cn;}
      void setBallStatus(bool bs) { ball_status = bs;}
      int getScore() const { return Score; }
      bool getHomeStatus() const { return Home_Status; }
      string getName() const { return Name; }
      int getTimeoutCount() const { return Timeout_Count; }
      string getHomeCity() const { return Home_City;}
      string getCoachName() const { return Coach_Name;}
      bool getBallStatus() const { return ball_status;}
};

class Scoreboard
{
  private:
    int quarter; 
    Team home; //object that is a member of another object
    Team visitor;
    bool ball_status;

  public: 
    Scoreboard()
    {
      quarter = 0;
    }  
    void setQuarter(int q) { quarter = q; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    void setBallStatus(bool bs) { ball_status = bs;}
    int getQuarter() const { return quarter; }
    bool getBallStatus() const { return ball_status;}
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[32;4m"; //green 
      string score = "\x1b[44;44m"; //score color 
      string homeCity = "\x1b[36;1m";
      string TeamColors = "\x1b[31;6m";
      cout << color << "\t\tFootball Scoreboard" << reset << endl; 
      cout << "\t\t\t" << homeCity << home.getHomeCity() << reset << endl;
      cout << TeamColors << home.getName() << "\t\t" << visitor.getName() << reset << endl; 
      cout << score << home.getScore() << "\t\t\t\t\t" << visitor.getScore() << reset << endl; 
    }
};

int main() 
{
  Scoreboard s;
  Team tOne;
  Team tTwo; 
  string newName; 
  string hc;
  string userChoice = " "; 
  int newScore = 0; 

  //Set the home team 
  tOne.setHomeStatus(true); //tOne is the Home Team now   

  //add some initial data to s
  s.setHome(tOne); 
  s.setVisitor(tTwo); 

  //Loop this to make it an interactive menu

  do 
  {
      string color = ""; 
      string reset = "\x1b[0m";
      color = "\x1b[33;5m"; //green 
      system("clear"); //clear the screen of previous content 
      s.showScoreboard(); //show the current scoreboard data
      //menu choices 
      cout << endl;
      cout << color << "A = Update Home Team Name" << endl; 
      cout << "B = Update Home Team Score" << endl; 
      cout << "C = Update Home City" << endl;
      cout << "D = Update Visiting Team Name" << endl;
      cout << "E = Update Visiting Team Score" << endl;
      cout << "X = Exit" << reset << endl;
      cout << "> "; 
      cin >> userChoice; 

     

      if(userChoice == "A" || userChoice == "a")
      {
        //Dr_T challenge Accept a new name for s's home team
        cout << "****Update Home Team Score module*** " << endl; 
        cout << "\nPlease enter a new name for the home team: ";
        cin.ignore();
        getline(cin, newName); 
        //change that home team's default name
        tOne.setName(newName); //set tOne's data to the new desired name
      }
      else if(userChoice == "B" || userChoice == "b")
      {
        cout << "\nUpdate Home Score Module****" << endl; 
        cout << "\nPlease enter a new score for the home team: "; 
        cin >> newScore; 
        
        tOne.setScore(newScore);  //set the new score for tOne        
      }
      else if(userChoice == "C" || userChoice == "c")
      {
        cout << "\nUpdate the home city" << endl;
        cin.ignore();
        getline(cin, hc);

        tOne.setHomeCity(hc);

      }
      else if(userChoice == "D" || userChoice == "d")
      {
        cout << "\n***Update Visiting Team Name***" << endl;
        cout << "\nPlease enter a new name for the visiting team: ";
        cin.ignore();
        getline(cin, newName);
        
        tTwo.setName(newName);
      }
      else if(userChoice == "E" || userChoice == "e")
      {
        cout << "\n***Update Visiting Team Score***" << endl;
        cout << "Please enter a new score for the visiting team: ";
        cin >> newScore;
        
        tTwo.setScore(newScore);
      }
      else if(userChoice == "X" || userChoice == "x")
      {
        cout << "Exit chosen." << endl; 
      }
      else //invalid input: default clause
      {
        cout << "\nInvalid input." << endl; 
        sleep(2); //wait two seconds, go to the next process 
      }

      s.setHome(tOne); //refresh the data in s to the new updates...
      s.setVisitor(tTwo);
  
  }while(userChoice != "X" && userChoice != "x");


  return 0; 
}