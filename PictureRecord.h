//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//PictureRecord class prototype

#ifndef PICTURERECORD_H
#define PICTURERECORD_H

#include <string>
#include <sstream>
#include <cctype>

using namespace std;

class PictureRecord{
    
private:
    string name;
    string year;
    string nomination;
    string rating;
    string duration;
    string genre1;
    string genre2;
    string release;
    string metacritic;
    string synopsis;
    
public:
    // overloaded =
    void operator=(const PictureRecord &aRecord){
        name = aRecord.name;
        year = aRecord.year;
        nomination = aRecord.nomination;
        rating = aRecord.rating;
        duration = aRecord.duration;
        genre1 = aRecord.genre1;
        genre2 = aRecord.genre2;
        release = aRecord.release;
        metacritic = aRecord.metacritic;
        synopsis = aRecord.synopsis;
    }// end operator=
    // copy constructor
    PictureRecord(const PictureRecord &aRecord){
        name = aRecord.name;
        year = aRecord.year;
        nomination = aRecord.nomination;
        rating = aRecord.rating;
        duration = aRecord.duration;
        genre1 = aRecord.genre1;
        genre2 = aRecord.genre2;
        release = aRecord.release;
        metacritic = aRecord.metacritic;
        synopsis = aRecord.synopsis;
    }// end PictureRecord
    PictureRecord();
    void setName(string _name) {
        if(_name[0] == ' '){
            _name.erase(0,1);
        }
        name = _name;};
    string getName() const { return name; };
    void setYear(string _year) { year = _year; };
    string getYear() const { return year; };
    void setNomination(string _nomination) { nomination = _nomination; };
    string getNomination() const { return nomination; };
    void setRating(string _rating) { rating = _rating; };
    string getRating() const { return rating; };
    void setDuration(string _duration) { duration = _duration; };
    string getDuration() const { return duration; };
    void setGenre1(string _genre1) { genre1 = _genre1; };
    string getGenre1() const { return genre1; };
    void setGenre2(string _genre2) { genre2 = _genre2; };
    string getGenre2() const { return genre2; };
    void setRelease(string _release) { release = _release; };
    string getRelease() const { return release; };
    void setMetacritic(string _metacritic) { metacritic = _metacritic; };
    string getMetacritic() const { return metacritic; };
    void setSynopsis(string _synopsis) { synopsis = _synopsis; };
    string getSynopsis() const { return synopsis; };
};

#endif /* PICTURERECORD_H */
