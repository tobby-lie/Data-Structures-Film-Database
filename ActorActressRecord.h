//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//ActorActressRecord class prototype

#ifndef ACTORACTRESSRECORD_H
#define ACTORACTRESSRECORD_H

#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class ActorActressRecord{
    
private:
    string year;
    string award;
    bool winner;
    string name;
    string film;
public:
    void operator=(const ActorActressRecord &aRecord){
        year = aRecord.year;
        award = aRecord.award;
        winner = aRecord.winner;
        name = aRecord.name;
        film = aRecord.film;
    }
    ActorActressRecord(const ActorActressRecord &aRecord){
        year = aRecord.year;
        award = aRecord.award;
        winner = aRecord.winner;
        name = aRecord.name;
        film = aRecord.film;
    }
    ActorActressRecord();
    ActorActressRecord(string _year, string _award, bool _winner, string _name, string _film);
    void setYear(string _year) { year = _year; };
    string getYear() const { return year; };
    void setAward(string _award) { award = _award; };;
    string getAward() const { return award; };
    void setWinner(string _status) {
        int statusInt = stoi(_status);
        if(statusInt == 1){
            winner = true;
        }
        else{
            winner = false;
        }
    };
    string getWinner() const{
        if(winner == true){
            return "1";
        }
        else{
            return "0";
        }
    }
    bool isWinner() const { return winner; };
    void setName(string _name) { name = _name; };
    string getName() const { return name; };
    void setFilm(string _film) { film = _film; }
    string getFilm() const { return film; };
};

#endif /* ACTORACTRESSRECORD_H */
















