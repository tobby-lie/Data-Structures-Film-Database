//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//Functions implementation

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>
#include <fstream>
#include <cctype>
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <algorithm>
#include "ActorBST.h"
#include "PictureBST.h"

using namespace std;


// removes all non alpha/num chars in string
string removeAlNum(string input){
    for(int i = 0; i < (int)input.size(); i++){
        if(!isalnum(input[i]) && !isspace(input[i]) && input[i] != '\''){
            input.erase(i--,1);
        } // end if
    } // end for
    return input;
} // end removeAlNum

// converts string input to lowercase
string lowerCase(string input){
    for(int i = 0; i < input.size(); i++){ // traverse entire string
        input[i] = tolower(input[i]); // convert char to lowercase
    } // end for
    return input;
} // end lowerCase

// reads contents of file into ActorBST
void readInFile(ActorBST &aBST, string fileName){
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    
    string year, award, winner, name, film;
    
    // get rid of header text
    getline(inFile,year,',');
    getline(inFile,award,',');
    getline(inFile,winner,',');
    getline(inFile,name,',');
    getline(inFile,film);
    
    while(getline(inFile,year,',')){
        getline(inFile,award,',');
        getline(inFile,winner,',');
        getline(inFile,name,',');
        getline(inFile,film);
        year = removeAlNum(year);
        award = removeAlNum(award);
        winner = removeAlNum(winner);
        name = removeAlNum(name);
        film = removeAlNum(film);
        year = lowerCase(year);
        award = lowerCase(award);
        winner = lowerCase(winner);
        name = lowerCase(name);
        film = lowerCase(film);
        ActorActressRecord temp;
        temp.setYear(year);
        temp.setFilm(film);
        temp.setName(name);
        temp.setAward(award);
        temp.setWinner(winner);
        ActorNode tempNode;
        tempNode.setRecord(temp);
        tempNode.setKey(name); // for by name
        aBST.addNode(name, year, award, winner, name, film); // for BST sorted by name
    } // end while
    inFile.close();
} // end readInFile

// reads contents of file into PictureBST
void readInFile(PictureBST &aBST, string fileName){
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    
    string key, name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis;
    
    // get rid of header text
    getline(inFile,name,',');
    getline(inFile,year,',');
    getline(inFile,nomination,',');
    getline(inFile, rating,',');
    getline(inFile,duration,',');
    getline(inFile,genre1,',');
    getline(inFile,genre2,',');
    getline(inFile, release,',');
    getline(inFile, metacritic,',');
    getline(inFile,synopsis);
    
    while(getline(inFile,name,',')){
        getline(inFile,year,',');
        getline(inFile,nomination,',');
        getline(inFile, rating,',');
        getline(inFile,duration,',');
        getline(inFile,genre1,',');
        getline(inFile,genre2,',');
        getline(inFile, release,',');
        getline(inFile, metacritic,',');
        getline(inFile,synopsis);
        name = removeAlNum(name);
        year = removeAlNum(year);
        nomination = removeAlNum(nomination);
        // rating = removeAlNum(rating); need to maintain decimals
        duration = removeAlNum(duration);
        genre1 = removeAlNum(genre1);
        genre2 = removeAlNum(genre2);
        release = removeAlNum(release);
        metacritic = removeAlNum(metacritic);
        synopsis = removeAlNum(synopsis);
        name = lowerCase(name);
        year = lowerCase(year);
        nomination = lowerCase(nomination);
        rating = lowerCase(rating);
        duration = lowerCase(duration);
        genre1 = lowerCase(genre1);
        genre2 = lowerCase(genre2);
        release = lowerCase(release);
        metacritic = lowerCase(metacritic);
        synopsis = lowerCase(synopsis);
        PictureRecord aRecord;
        aRecord.setName(name);
        aRecord.setYear(year);
        aRecord.setNomination(nomination);
        aRecord.setRating(rating);
        aRecord.setDuration(duration);
        aRecord.setGenre1(genre1);
        aRecord.setGenre2(genre2);
        aRecord.setRelease(release);
        aRecord.setMetacritic(metacritic);
        aRecord.setSynopsis(synopsis);
        PictureNode tempNode;
        tempNode.setRecord(aRecord);
        tempNode.setKey(name); // for by name
        aBST.addNode(name, name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis); // for BST sorted by name
    } // end while
    inFile.close();
} // end readInFile

// reads contents of file into vector<ActorActressRecord>
void readInFile(vector<ActorActressRecord> &v, string fileName){
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    
    string year, award, winner, name, film;
    
    // get rid of header text
    getline(inFile,year,',');
    getline(inFile,award,',');
    getline(inFile,winner,',');
    getline(inFile,name,',');
    getline(inFile,film);
    
    while(getline(inFile,year,',')){
        getline(inFile,award,',');
        getline(inFile,winner,',');
        getline(inFile,name,',');
        getline(inFile,film);
        year = removeAlNum(year);
        award = removeAlNum(award);
        winner = removeAlNum(winner);
        name = removeAlNum(name);
        film = removeAlNum(film);
        year = lowerCase(year);
        award = lowerCase(award);
        winner = lowerCase(winner);
        name = lowerCase(name);
        film = lowerCase(film);
        ActorActressRecord temp;
        temp.setYear(year);
        temp.setFilm(film);
        temp.setName(name);
        temp.setAward(award);
        temp.setWinner(winner);
        v.push_back(temp);
    } // end while
    
    inFile.close();
} // end readInFile

// reads contents of file into vector<PictureREcord>
void readInFile(vector<PictureRecord> &v, string fileName){
    
    ifstream inFile;
    inFile.open(fileName.c_str());
    if(inFile.fail()){
        cout << "Failed to open file!" << endl;
    } // end if
    
    string key, name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis;
    
    // get rid of header text
    getline(inFile,name,',');
    getline(inFile,year,',');
    getline(inFile,nomination,',');
    getline(inFile, rating,',');
    getline(inFile,duration,',');
    getline(inFile,genre1,',');
    getline(inFile,genre2,',');
    getline(inFile, release,',');
    getline(inFile, metacritic,',');
    getline(inFile,synopsis);
    
    while(getline(inFile,name,',')){
        getline(inFile,year,',');
        getline(inFile,nomination,',');
        getline(inFile, rating,',');
        getline(inFile,duration,',');
        getline(inFile,genre1,',');
        getline(inFile,genre2,',');
        getline(inFile, release,',');
        getline(inFile, metacritic,',');
        getline(inFile,synopsis);
        name = removeAlNum(name);
        year = removeAlNum(year);
        nomination = removeAlNum(nomination);
        // rating = removeAlNum(rating); need to maintain decimals
        duration = removeAlNum(duration);
        genre1 = removeAlNum(genre1);
        genre2 = removeAlNum(genre2);
        release = removeAlNum(release);
        metacritic = removeAlNum(metacritic);
        synopsis = removeAlNum(synopsis);
        name = lowerCase(name);
        year = lowerCase(year);
        nomination = lowerCase(nomination);
        rating = lowerCase(rating);
        duration = lowerCase(duration);
        genre1 = lowerCase(genre1);
        genre2 = lowerCase(genre2);
        release = lowerCase(release);
        metacritic = lowerCase(metacritic);
        synopsis = lowerCase(synopsis);
        PictureRecord aRecord;
        aRecord.setName(name);
        aRecord.setYear(year);
        aRecord.setNomination(nomination);
        aRecord.setRating(rating);
        aRecord.setDuration(duration);
        aRecord.setGenre1(genre1);
        aRecord.setGenre2(genre2);
        aRecord.setRelease(release);
        aRecord.setMetacritic(metacritic);
        aRecord.setSynopsis(synopsis);
        v.push_back(aRecord);
    } // end while
    inFile.close();
} //end readInFile

// writes contents of ActorBST into file
void writeToFileActor(ActorBST &aBST, ofstream &outFile){
    vector<ActorActressRecord> aVector;
    aBST.InorderWriteOutputToVector(aVector);
    
    ActorActressRecord temp;
    
    for(int i = 0; i < aVector.size(); i++){
        temp = aVector[i];
        if(aVector[i].getName() != ""){
            outFile << temp.getYear() << "," << temp.getAward() << "," << temp.getWinner() << "," << temp.getName() << "," << temp.getFilm() << endl;
        } // end if
    } // end for
    outFile.close();
    cout << endl;
    cout << "* Successfully wrote ActorBST to updatedFileActor.txt *" << endl;
    cout << endl;
} // end writeToFileActor

// writes contents of pVector into file
void writeToFilePicture(const vector<PictureRecord> &pVector, ofstream &outFile){
    PictureRecord temp;

    for(int i = 0; i < pVector.size(); i++){
        if(pVector[i].getName() != ""){
            outFile << pVector[i].getName() << "," << pVector[i].getYear() << "," << pVector[i].getNomination() << "," << pVector[i].getRating() << "," << pVector[i].getDuration() << "," << pVector[i].getGenre1() << "," << pVector[i].getGenre2() << "," << pVector[i].getRelease() << "," << pVector[i].getMetacritic() << "," << pVector[i].getSynopsis() << endl;
        } // end if
    } // end for
    outFile.close();
    cout << endl;
    cout << "* Successfully wrote PictureBST to updatedFilePicture.txt *" << endl;
    cout << endl;
} // end writeToFilePicture

// writes contents of aVector into file
void writeToFile(vector<ActorActressRecord> &aVector, string fileName){
    ActorActressRecord temp;
    
    ofstream outFile(fileName.c_str(), ofstream::trunc);
    
    for(int i = 0; i < aVector.size(); i++){
        temp = aVector[i];
        if(aVector[i].getName() != ""){
            outFile << temp.getYear() << "," << temp.getAward() << "," << temp.getWinner() << "," << temp.getName() << "," << temp.getFilm() << endl;
        } // end for
    } // end for
    outFile.close();
} // end writeToFile

// writes contents of aVector into file
void writeToFile(vector<PictureRecord> &aVector, string fileName){
    PictureRecord temp;
    
    ofstream outFile(fileName.c_str(), ofstream::trunc);
    
    for(int i = 0; i < aVector.size(); i++){
        temp = aVector[i];
        if(aVector[i].getName() != ""){
            outFile << temp.getName() << "," << temp.getYear() << "," << temp.getNomination() << "," << temp.getRating() << "," << temp.getDuration() << "," << temp.getGenre1() << "," << temp.getGenre2() << "," << temp.getRelease() << "," << temp.getMetacritic() << "," << temp.getSynopsis() << endl;
        } // end if
    } // end for
    outFile.close();
} // end writeToFile

// adds ActorRecord to aBST
void addActorRecord(ActorBST &aBST, ActorActressRecord aRecord){
    string year, award, winner, name, film;
    year = aRecord.getYear();
    award = aRecord.getAward();
    winner = aRecord.getWinner();
    name = aRecord.getName();
    film = aRecord.getFilm();
    year = lowerCase(year);
    award = lowerCase(award);
    winner = lowerCase(winner);
    name = lowerCase(name);
    film = lowerCase(film);
    aBST.addNode(name, year, award, winner, name, film);
} // end addActorRecord

// sort aBST by name and writes to file
void sortName(ActorBST &aBST){
    
    vector<ActorActressRecord> aVector;
    aBST.InorderWriteOutputToVector(aVector);
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getName() > aVector[j+1].getName())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFileActor.txt");
} // end sortName

// sort aBST by award and writes to file
void sortAward(ActorBST &aBST){
    vector<ActorActressRecord> aVector;
    aBST.InorderWriteOutputToVector(aVector);
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getAward() > aVector[j+1].getAward())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFileActor.txt");
} // end sortAward

// sort aBST by year and writes to file
void sortYear(ActorBST &aBST){
    vector<ActorActressRecord> aVector;
    aBST.InorderWriteOutputToVector(aVector);
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getYear() > aVector[j+1].getYear())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFileActor.txt");
} // end sortYear

// sort aBST by film and writes to file
void sortFilm(ActorBST &aBST){
    vector<ActorActressRecord> aVector;
    aBST.InorderWriteOutputToVector(aVector);
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getFilm() > aVector[j+1].getFilm())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFileActor.txt");
} // end sortFilm

// sort aVector by name and writes to file
void sortNamePicture(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getName() > aVector[j+1].getName())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortNamePicture

// sort aVector by year and writes to file
void sortYearPicture(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getYear() > aVector[j+1].getYear())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortYearPicture

// sort aVector by nomination and writes to file
void sortNominations(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getNomination() > aVector[j+1].getNomination())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortNominations

// sort aVector by rating and writes to file
void sortRating(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getRating() > aVector[j+1].getRating())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortRating

// sort aVector by duration and writes to file
void sortDuration(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getDuration() > aVector[j+1].getDuration())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortDuration

// sort aVector by genre1 and writes to file
void sortGenre1(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getGenre1() > aVector[j+1].getGenre1())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortGenre1

// sort aVector by genre2 and writes to file
void sortGenre2(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getGenre2() > aVector[j+1].getGenre2())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortGenre2

// sort aVector by release and writes to file
void sortRelease(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getRelease() > aVector[j+1].getRelease())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortRelease

// sort aVector by metacritic and writes to file
void sortMetacritic(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getMetacritic() > aVector[j+1].getMetacritic())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortMetacritic

// sort aVector by synopsis and writes to file
void sortSynopsis(vector<PictureRecord> &aVector){
    int i, j;
    int n = (int)aVector.size();
    for (i = 0; i < n-1; i++)
        
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (aVector[j].getSynopsis() > aVector[j+1].getSynopsis())
                swap(aVector.at(j), aVector.at(j+1)); // end if
        // end for
    // end for
    writeToFile(aVector, "updatedFilePicture.txt");
} // end sortSynopsis

// search for all matches of target in aBST
vector<ActorActressRecord> searchName(ActorBST &aBST, string target){
    vector<ActorActressRecord> aVector;
    vector<ActorActressRecord> temp;
    vector<ActorActressRecord> empty;
    empty.push_back(ActorActressRecord());
    
    // read name tree into vector by name
    aBST.InorderWriteOutputToVector(aVector);
    
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getName() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchName

// search for all matches of target in pVector
vector<PictureRecord> searchPicName(vector<PictureRecord> &pVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;

    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)pVector.size(); i++)
        if (pVector[i].getName() == target){
            temp.push_back(pVector[i]);
            count++;
        }
    if(count > 0)
        return temp;
    else
        return empty;
}

// returns index of match to target
int searchPicNameIndex(vector<PictureRecord> &pVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    for (i=0; i < (int)pVector.size(); i++)
        if (pVector[i].getName() == target){
            temp.push_back(pVector[i]);
            return i;
        } // end if
    return -1;
} // end searchPicNameIndex

// returns index of match for contains to target
int searchNamePartial(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector O(n) so already sorted by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getName().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    return count;
} // end searchNamePartial

// search for year in aBST
int searchYear(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getYear() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    return count;
} // end searchYear

// search for years that contain target
int searchYearPartial(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector O(n) so already sorted by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getYear().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    return count;
} // end searchYearPartial

// search a vector by name and returns index to match
int searchFilm(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++){
        if (aVector[i].getFilm() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    } // end for
    return count;
} // end searchFilm

// search for films that contain target in aBST then returns index to match
int searchFilmPartial(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector O(n) so already sorted by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++){
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getFilm().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    } // end for
    return count;
} // end searchFilmPartial

// search for award in aBST then returns index to match
int searchAward(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++){
        if (aVector[i].getAward() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    } // end for
    return count;
} // end searchAward

// search for string in awards that contains target, returns index
int searchAwardPartial(ActorBST &aBST, string target, vector<ActorActressRecord> &temp){
    vector<ActorActressRecord> aVector;
    
    // read name tree into vector O(n) so already sorted by name
    aBST.InorderWriteOutputToVector(aVector);
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++){
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getAward().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    } // end for
    return count;
} // end searchAwardPartial

// search for name and return vector of all results
vector<PictureRecord> searchName(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++){
        if (aVector[i].getName() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    } // end for
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchNaem

// search names that contain target then returns vector of results
vector<PictureRecord> searchNamePartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;

    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++){
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getName().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    } // end for
    if(count > 0)
        return temp; // end temp
    else
        return empty; // end empty
} // end searchNamePartial

// search year, return vector of results
vector<PictureRecord> searchYear(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++){
        if (aVector[i].getYear() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    } // end for
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchYear

// search years that contain target, returns vector of results
vector<PictureRecord> searchYearPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getYear().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchYearPartial

// search nominations, returns vector of results
vector<PictureRecord> searchNomination(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getNomination() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchNomination

// search nominations that contain target, returns vector of results
vector<PictureRecord> searchNominationPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getNomination().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchNominationPartial

// search ratings, returns vector of results
vector<PictureRecord> searchRating(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getRating() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchRating

// search ratings that contain target, returns vector of results
vector<PictureRecord> searchRatingPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getRating().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchRatingPartial

// search durations, returns vector of results
vector<PictureRecord> searchDuration(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getDuration() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchDuration

// search durations that contain target, returns vector of results
vector<PictureRecord> searchDurationPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getDuration().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchDurationPartial

// search genre1, returns vector of results
vector<PictureRecord> searchGenre1(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getGenre1() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchGenre1

// search genre1s that contain target, returns vector of results
vector<PictureRecord> searchGenre1Partial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getGenre1().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end if
} // end searchGenre1Partial

// search Genre2, returns vector of results
vector<PictureRecord> searchGenre2(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getGenre2() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchGenre2

// search genre2s that contain target, returns vector of results
vector<PictureRecord> searchGenre2Partial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getGenre2().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchGenre2Partial

// search release, returns vector of results
vector<PictureRecord> searchRelease(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getRelease() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchRelease

// search releases that contain target, returns vector of results
vector<PictureRecord> searchReleasePartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getRelease().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchReleasePartial

// search metacritics, returns vector of results
vector<PictureRecord> searchMetacritic(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getMetacritic() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchMetacritic

// search metacritics that contain target, returns vector of results
vector<PictureRecord> searchMetacriticPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getMetacritic().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchMetacriticPartial

// search synopsis, returns vector of results
vector<PictureRecord> searchSynopsis(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    sortNamePicture(aVector);
    // need to search every record, so a linear search will do, O(n)
    int count = 0;
    int i;
    for (i=0; i < (int)aVector.size(); i++)
        if (aVector[i].getSynopsis() == target){
            temp.push_back(aVector[i]);
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchSynopsis

// search synopsis' that contain target, returns vector of results
vector<PictureRecord> searchSynopsisPartial(vector<PictureRecord> aVector, string target){
    vector<PictureRecord> temp;
    vector<PictureRecord> empty;
    
    // need to search every record, so a linear search will do, O(n)
    int i;
    string curr;
    int count = 0;
    for (i=0; i < (int)aVector.size(); i++)
        // https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c
        
        if (strstr(aVector[i].getSynopsis().c_str(), target.c_str()) != NULL){ // used link above for this line of code
            temp.push_back(aVector[i]);
            
            count++;
        } // end if
    if(count > 0)
        return temp; // end if
    else
        return empty; // end else
} // end searchSynopsisPartial

// delete ActorRecord from aBST
void deleteActorRecord(ActorBST &aBST){
    
    
    string name;
    cout << "-------------------------------" << endl;
    cout << "             DELETE            " << endl;
    cout << "-------------------------------" << endl;
    cout << "You are in actors-actresses" << endl;
    cout << "                               " << endl;
    cout << "What is the name for the record" << endl;
    cout << "You wish to delete?" << endl;
    cout << "-------------------------------" << endl;
    cin.ignore();
    getline(cin,name);
    cout << endl;
    cout << endl;
    cout << "Searching for record with name: " << name << "..." << endl;
    cout << endl;
    ActorNode *n = aBST.findNode(name);
    
    if(n != nullptr){
        ActorActressRecord r = n->Record();
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "* Successfully deleted record with this information *" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Name: " << r.getName() << endl;
        cout << "Year: " << r.getYear() << endl;
        cout << "Award: " << r.getAward() << endl;
        cout << "Film: " << r.getFilm() << endl << endl;
        cout << "-----------------------------------------------------" << endl;
        aBST.deleteNode(name);
    } // end if
    else{
        cout << endl;
        cout << "* There is no record with this name *" << endl;
        cout << endl;
    } // end else
} // end deleteActorRecord
// deletePictureRecord from pVector
void deletePictureRecord(vector<PictureRecord> &pVector){
    
    string name;
    cout << "-------------------------------" << endl;
    cout << "             DELETE            " << endl;
    cout << "-------------------------------" << endl;
    cout << "You are in pictures" << endl;
    cout << "                               " << endl;
    cout << "What is the name for the record" << endl;
    cout << "You wish to delete?" << endl;
    cout << "-------------------------------" << endl;
    cin.ignore();
    getline(cin,name);
    cout << endl;
    cout << endl;
    cout << "Searching for record with name: " << name << "..." << endl;
    cout << endl;

    int index = searchPicNameIndex(pVector, name);
  
    if(index != -1){
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "* Successfully deleted record with this information *" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Name: " << pVector[index].getName() << endl;
        cout << "Year: " << pVector[index].getYear() << endl;
        cout << "Nominations: " << pVector[index].getNomination() << endl;
        cout << "Rating: " << pVector[index].getRating() << endl;
        cout << "Duration: " << pVector[index].getDuration() << endl;
        cout << "Genre 1: " << pVector[index].getGenre1() << endl;
        cout << "Genre 2: " << pVector[index].getGenre2() << endl;
        cout << "Release: " << pVector[index].getRelease() << endl;
        cout << "Metacritic: " << pVector[index].getMetacritic() << endl;
        cout << "Synopsis: " << pVector[index].getSynopsis() << endl;
        cout << "-----------------------------------------------------" << endl;
        
        pVector.erase(pVector.begin() + index);
    } // end if
    else{
        cout << endl;
        cout << "* There is no record with this name *" << endl;
        cout << endl;
    } // end else
} // end deletePictureRecord

// modify ActorRecord in aBST by name search
void modifyActorName(ActorBST &aBST){
    
    string name;
    char choiceA;
    cout << "-------------------------------------------------------" << endl;
    cout << "Please input the name for the record you want to modify" << endl;
    cout << "Input Q to exit to main menu" << endl;
    cout << "-------------------------------------------------------" << endl;
    cin.ignore();
    getline(cin, name);
    ActorNode *n = aBST.findNode(name);
    if(name[0] == 'q' || name[0] == 'Q'){
        cout << "Back to main menu..." << endl;
    } // end if
    else if(n == nullptr){
        cout << endl;
        cout << "* There is no record by this name. *" << endl;
        cout << endl;
    } // end else if
    else{
        ActorActressRecord r = n->Record();
        cout << "-------------------------------" << endl;
        cout << "Here are the record's contents: " << endl;
        cout << "-------------------------------" << endl;
        cout << "Name: " << r.getName() << endl;
        cout << "Year: " << r.getYear() << endl;
        cout << "Award: " << r.getAward() << endl;
        cout << "Film: " << r.getFilm() << endl << endl;
        cout << "-------------------------------" << endl;
        
        cout << "-------------------------------------" << endl;
        cout << "Which field would you like to modify?" << endl;
        cout << "-------------------------------------" << endl;
        cout << "A:Year" << endl;
        cout << "B:Award" << endl;
        cout << "C:Film" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "-------------------------------------" << endl;
        cin >> choiceA;
        switch(choiceA){
            case 'a':
            case 'A':{
                cout << "test in delete: " << r.getName() << endl;
                string newYear;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new year for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newYear);
                r.setYear(newYear);
                n->setRecord(r);
                break;
            }
            case 'b':
            case 'B':{
                cout << "test in delete: " << r.getName() << endl;
                string newAward;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new award for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newAward);
                r.setAward(newAward);
                n->setRecord(r);
                break;
            }
            case 'c':
            case 'C':{
                cout << "test in delete: " << r.getName() << endl;
                string newFilm;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new film for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newFilm);
                r.setFilm(newFilm);
                n->setRecord(r);
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << "* Invalid input! Try again. *" << endl;
                break;
        } // end swtich
    } // end else
} // end modifyActorName

// modify PictureRecord by name in pVector
void modifyPictureName(vector<PictureRecord> &pVector){
    string name;
    char choiceD;
    cout << "-------------------------------------------------------" << endl;
    cout << "Please input the name for the record you want to modify" << endl;
    cout << "Input Q to exit to main menu" << endl;
    cout << "-------------------------------------------------------" << endl;
    cin.ignore();
    getline(cin, name);
    int index = searchPicNameIndex(pVector, name);
    
    if(name[0] == 'q' || name[0] == 'Q'){
        cout << "Back to main menu..." << endl;
    } // end if
    else if(index == -1){
        cout << endl;
        cout << "* There is no record by this name. *" << endl;
        cout << endl;
    } // end else if
    else{
        cout << "-------------------------------" << endl;
        cout << "Here are the record's contents: " << endl;
        cout << "-------------------------------" << endl;
        cout << "Name: " << pVector[index].getName() << endl;
        cout << "Year: " << pVector[index].getYear() << endl;
        cout << "Nominations: " << pVector[index].getNomination() << endl;
        cout << "Rating: " << pVector[index].getRating() << endl;
        cout << "Duration: " << pVector[index].getDuration() << endl;
        cout << "Genre 1: " << pVector[index].getGenre1() << endl;
        cout << "Genre 2: " << pVector[index].getGenre2() << endl;
        cout << "Release: " << pVector[index].getRelease() << endl;
        cout << "Metacritic: " << pVector[index].getMetacritic() << endl;
        cout << "Synopsis: " << pVector[index].getSynopsis() << endl;
        cout << "-------------------------------" << endl;
        
        cout << "-------------------------------------" << endl;
        cout << "Which field would you like to modify?" << endl;
        cout << "-------------------------------------" << endl;
        cout << "A:Year" << endl;
        cout << "B:Nomination" << endl;
        cout << "C:Rating" << endl;
        cout << "D:Duration" << endl;
        cout << "E:Genre1" << endl;
        cout << "F:Genre2" << endl;
        cout << "G:Release" << endl;
        cout << "H:Metacritic" << endl;
        cout << "I:Synopsis" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "-------------------------------------" << endl;
        cin >> choiceD;
        switch(choiceD){
            case 'a':
            case 'A':{
                string newYear;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new year for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newYear);
                pVector[index].setYear(newYear);
                break;
            }
            case 'b':
            case 'B':{
                string newNom;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new nomination for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newNom);
                pVector[index].setNomination(newNom);
                break;
            }
            
            case 'c':
            case 'C':{
                string newRating;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new rating for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newRating);
                pVector[index].setRating(newRating);
                break;
            }
            case 'd':
            case 'D':{
                string newDur;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new duration for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newDur);
                pVector[index].setDuration(newDur);
                break;
            }
            case 'e':
            case 'E':{
                string newGenre1;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new genre1 for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newGenre1);
                pVector[index].setGenre1(newGenre1);
                break;
            }
            case 'f':
            case 'F':{
                string newGenre2;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new genre2 for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newGenre2);
                pVector[index].setGenre2(newGenre2);
                break;
            }
            case 'g':
            case 'G':{
                string newRelease;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new release for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newRelease);
                pVector[index].setRelease(newRelease);
                break;
            }
            case 'h':
            case 'H':{
                string newMeta;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new metacritic for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newMeta);
                pVector[index].setMetacritic(newMeta);
                break;
            }
            case 'i':
            case 'I':{
                string newSynop;
                cout << "------------------------------------------" << endl;
                cout << "Please input the new synopsis for this record: " << endl;
                cout << "------------------------------------------" << endl;
                cin.ignore();
                getline(cin, newSynop);
                pVector[index].setSynopsis(newSynop);
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    } // end else
} // end modifyPictureName

// addRecord to aBST
void addRecord(ActorBST &aBST,vector<PictureRecord> &pVector){
    char choiceB;
    do{
        cout << "----------------------------------" << endl;
        cout << "Would you like to add a record to: " << endl;
        cout << "----------------------------------" << endl;
        cout << "A:Actors-Actresses" << endl;
        cout << "B:Pictures" << endl;
        cout << "Q:Exit to Main Menu" << endl;
        cout << "----------------------------------" << endl;
        cin >> choiceB;
        switch(choiceB){
            case 'a':
            case 'A':{
                cin.ignore();
                string year, award, winner, name, film;
                cout << "----------------------------------" << endl;
                cout << "Input the year for the new record: " << endl;
                cout << "----------------------------------" << endl;
                getline(cin,year);
                cout << "-----------------------------------" << endl;
                cout << "Input the award for the new record: " << endl;
                cout << "-----------------------------------" << endl;
                getline(cin,award);
                cout << "----------------------------------------------------------------" << endl;
                cout << "Input winner status for the new record (1 winner, 0 not winner): " << endl;
                cout << "----------------------------------------------------------------" << endl;
                getline(cin,winner);
                while(winner[0] != '1' && winner[0] != '0'){
                    cout << endl;
                    cout << "Invalid input! Must enter a 1 for winner or 0 for not winner: " << endl;
                    cout << endl;
                    getline(cin,winner);
                } // end while
                cout << "----------------------------------" << endl;
                cout << "Input the name for the new record: " << endl;
                cout << "----------------------------------" << endl;
                getline(cin,name);
                cout << "----------------------------------" << endl;
                cout << "Input the film for the new record: " << endl;
                cout << "----------------------------------" << endl;
                getline(cin,film);
                
                year = removeAlNum(year);
                award = removeAlNum(award);
                winner = removeAlNum(winner);
                name = removeAlNum(name);
                film = removeAlNum(film);
                year = lowerCase(year);
                award = lowerCase(award);
                winner = lowerCase(winner);
                name = lowerCase(name);
                film = lowerCase(film);
                
                aBST.addNode(name, year, award, winner, name, film);
                break;
            }
            case 'b':
            case 'B':{
                cin.ignore();
                string name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis;
                cout << "----------------------------------" << endl;
                cout << "Input the name for the new record: " << endl;
                cout << "----------------------------------" << endl;
                getline(cin,name);
                cout << "-----------------------------------" << endl;
                cout << "Input the year for the new record: " << endl;
                cout << "-----------------------------------" << endl;
                getline(cin,year);
                cout << "----------------------------------------" << endl;
                cout << "Input the nomination for the new record: " << endl;
                cout << "----------------------------------------" << endl;
                getline(cin,nomination);
                cout << "------------------------------------" << endl;
                cout << "Input the rating for the new record: " << endl;
                cout << "------------------------------------" << endl;
                getline(cin,rating);
                cout << "--------------------------------------" << endl;
                cout << "Input the duration for the new record: " << endl;
                cout << "--------------------------------------" << endl;
                getline(cin,duration);
                cout << "------------------------------------" << endl;
                cout << "Input the genre1 for the new record: " << endl;
                cout << "------------------------------------" << endl;
                getline(cin,genre1);
                cout << "------------------------------------" << endl;
                cout << "Input the genre2 for the new record: " << endl;
                cout << "------------------------------------" << endl;
                getline(cin,genre2);
                cout << "-------------------------------------" << endl;
                cout << "Input the release for the new record: " << endl;
                cout << "-------------------------------------" << endl;
                getline(cin,release);
                cout << "----------------------------------------" << endl;
                cout << "Input the metacritic for the new record: " << endl;
                cout << "----------------------------------------" << endl;
                getline(cin,metacritic);
                cout << "--------------------------------------" << endl;
                cout << "Input the synopsis for the new record: " << endl;
                cout << "--------------------------------------" << endl;
                getline(cin,synopsis);
                name = removeAlNum(name);
                year = removeAlNum(year);
                nomination = removeAlNum(nomination);
                // rating = removeAlNum(rating); need to maintain decimal points
                duration = removeAlNum(duration);
                genre1 = removeAlNum(genre1);
                genre2 = removeAlNum(genre2);
                release = removeAlNum(release);
                metacritic = removeAlNum(metacritic);
                synopsis = removeAlNum(synopsis);
                name = lowerCase(name);
                year = lowerCase(year);
                nomination = lowerCase(nomination);
                rating = lowerCase(rating);
                duration = lowerCase(duration);
                genre1 = lowerCase(genre1);
                genre2 = lowerCase(genre2);
                release = lowerCase(release);
                metacritic = lowerCase(metacritic);
                synopsis = lowerCase(synopsis);

                PictureRecord r;
                r.setName(name);
                r.setYear(year);
                r.setNomination(nomination);
                r.setRating(rating);
                r.setDuration(duration);
                r.setGenre1(genre1);
                r.setGenre2(genre2);
                r.setRelease(release);
                r.setMetacritic(metacritic);
                r.setSynopsis(synopsis);
                pVector.push_back(r);
                break;
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choiceB != 'Q' && choiceB != 'q'); // end do while
} // end addRecord

// read file contents to aBST
void readToActors(ActorBST &aBST){
    readInFile(aBST, "actor-actress.csv");

    cout << endl;
    cout << "* actor-actress.csv has successfully been read in. *" << endl;
    cout << endl;
} // end readToActors

// read file contents to pBST and pVector
void readToPictures(PictureBST &pBST, vector<PictureRecord> &pVector){
    readInFile(pBST, "pictures.csv");
    readInFile(pVector, "pictures.csv"); // will be using vector implementation for pictures since there are not that many picture records
    
    cout << endl;
    cout << "* pictures.csv has successfully been read in. *" << endl;
    cout << endl;
} // end readToPictures

// sort ActorRecords in aBST and write out to file
void sortActor(ActorBST &aBST){
    char choice;
    do{
        cout << "-------------------------------------" << endl;
        cout << "What field would you like to sort by?" << endl;
        cout << "-------------------------------------" << endl;
        cout << "A:Name" << endl;
        cout << "B:Year" << endl;
        cout << "C:Award" << endl;
        cout << "D:Film" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "-------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                cout << "* Sorting by name *" << endl;
                sortName(aBST);
                break;
            }
            case 'b':
            case 'B':{
                cout << "* Sorting by year *" << endl;
                sortYear(aBST);
                break;
            }
            case 'c':
            case 'C':{
                cout << "* Sorting by award *" << endl;
                sortAward(aBST);
                break;
            }
            case 'd':
            case 'D':{
                cout << "* Sorting by film *" << endl;
                sortFilm(aBST);
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Invalid input! Try again. " << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
}// end sortActor

// sort aVector and write to file
void sortPicture(vector<PictureRecord> &aVector){
    char choice;
    do{
        cout << "--------------------------------------" << endl;
        cout << "Which field would you like to sort by?" << endl;
        cout << "--------------------------------------" << endl;
        cout << "A:Name" << endl;
        cout << "B:Year" << endl;
        cout << "C:Nomination" << endl;
        cout << "D:Rating" << endl;
        cout << "E:Duration" << endl;
        cout << "F:Genre1" << endl;
        cout << "G:Genre2" << endl;
        cout << "H:Release" << endl;
        cout << "I:Metacritic" << endl;
        cout << "J:Synopsis" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "-------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                cout << "* Sorting by name *" << endl;
                sortNamePicture(aVector);
                break;
            }
            case 'b':
            case 'B':{
                cout << "* Sorting by year *" << endl;
                sortYearPicture(aVector);
                break;
            }
            case 'c':
            case 'C':{
                cout << "* Sorting by nomination *" << endl;
                sortNominations(aVector);
                break;
            }
            case 'd':
            case 'D':{
                cout << "* Sorting by rating *" << endl;
                sortRating(aVector);
                break;
            }
            case 'e':
            case 'E':{
                cout << "* Sorting by duration *" << endl;
                sortDuration(aVector);
                break;
            }
            case 'f':
            case 'F':{
                cout << "* Sorting by genre1 *" << endl;
                sortGenre1(aVector);
                break;
            }
            case 'g':
            case 'G':{
                cout << "* Sorting by genre2 *" << endl;
                sortGenre2(aVector);
                break;
            }
            case 'h':
            case 'H':{
                cout << "* Sorting by release *" << endl;
                sortRelease(aVector);
                break;
            }
            case 'i':
            case 'I':{
                cout << "* Sorting by metacritic *" << endl;
                sortMetacritic(aVector);
                break;
            }
            case 'j':
            case 'J':{
                cout << "* Sorting by synopsis *" << endl;
                sortSynopsis(aVector);
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Invalid input! Try again. " << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
} // end sortPicture

// search actors by name
vector<ActorActressRecord> searchActorName(ActorBST &aBST){
    
    char choice;
    ActorActressRecord r;
    vector<ActorActressRecord> empty;
    empty.push_back(r);
    do{
        cout << "-----------------------------------------" << endl;
        cout << "What type of search would you like to do?" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Complete" << endl;
        cout << "B:Partial" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                string name;
                cout << "---------------------------------------" << endl;
                cout << "            COMPLETE SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What name would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,name);
                cout << endl;
                cout << "name: " << name << endl;
                cout << endl;
                cout << "* Searching for records with name: " << name << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchName(temp, name);
                

                if(!temp.empty()){
   
                    for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Award: " << temp[i].getAward() << endl;
                    cout << "Film: " << temp[i].getFilm() << endl;
                    cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with this name *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'b':
            case 'B':{
                string name;
                cout << "---------------------------------------" << endl;
                cout << "             PARTIAL SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What name would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,name);
                cout << endl;
                cout << "name: " << name << endl;
                cout << endl;
                cout << "* Searching for records with name that contains: " << name << "..." << endl;
                cout << endl;
 
                vector<ActorActressRecord> temp;
                aBST.InorderSearchNamePartial(temp, name);
                
                if(!temp.empty()){
                    for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Award: " << temp[i].getAward() << endl;
                    cout << "Film: " << temp[i].getFilm() << endl;
                    cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with that contain this input *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
    return empty;
} // searchActorName

// search actors by year
vector<ActorActressRecord> searchActorYear(ActorBST &aBST){
    
    char choice;
    ActorActressRecord r;
    vector<ActorActressRecord> empty;
    empty.push_back(r);
    do{
        cout << "-----------------------------------------" << endl;
        cout << "What type of search would you like to do?" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Complete" << endl;
        cout << "B:Partial" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                string year;
                cout << "---------------------------------------" << endl;
                cout << "            COMPLETE SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What year would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,year);
                cout << endl;
                cout << "year: " << year << endl;
                cout << endl;
                cout << "* Searching for records with year: " << year << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchYear(temp, year);
                
                if(!temp.empty()){

                    for(int i = 0; i < (int)temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with this year *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'b':
            case 'B':{
                string year;
                cout << "---------------------------------------" << endl;
                cout << "             PARTIAL SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What year would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,year);
                cout << endl;
                cout << "year: " << year << endl;
                cout << endl;
                cout << "* Searching for records with year that contains: " << year << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchYearPartial(temp, year);
                
                if(!temp.empty()){
                    for(int i = 0; i < temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with that contain this input *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
    return empty;
} // end searchActorYear

// search actor for film
vector<ActorActressRecord> searchActorFilm(ActorBST &aBST){
    
    char choice;
    ActorActressRecord r;
    vector<ActorActressRecord> empty;
    empty.push_back(r);
    do{
        cout << "-----------------------------------------" << endl;
        cout << "What type of search would you like to do?" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Complete" << endl;
        cout << "B:Partial" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                string film;
                cout << "---------------------------------------" << endl;
                cout << "            COMPLETE SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What film would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,film);
                cout << endl;
                cout << "film: " << film << endl;
                cout << endl;
                cout << "* Searching for records with film: " << film << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchFilm(temp, film);
                
                if(!temp.empty()){

                    for(int i = 0; i < (int)temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with this film *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'b':
            case 'B':{
                string film;
                cout << "---------------------------------------" << endl;
                cout << "             PARTIAL SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What film would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,film);
                cout << endl;
                cout << "film: " << film << endl;
                cout << endl;
                cout << "* Searching for records with film that contains: " << film << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchFilmPartial(temp, film);
                
                if(!temp.empty()){
                    for(int i = 0; i < temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with that contain this input *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
    return empty;
} // end searchActorFilm

// search actor for award
vector<ActorActressRecord> searchActorAward(ActorBST &aBST){
    
    char choice;
    ActorActressRecord r;
    vector<ActorActressRecord> empty;
    empty.push_back(r);
    do{
        cout << "-----------------------------------------" << endl;
        cout << "What type of search would you like to do?" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Complete" << endl;
        cout << "B:Partial" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                string award;
                cout << "---------------------------------------" << endl;
                cout << "            COMPLETE SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What award would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,award);
                cout << endl;
                cout << "award: " << award << endl;
                cout << endl;
                cout << "* Searching for records with award: " << award << "..." << endl;
                cout << endl;
 
                vector<ActorActressRecord> temp;
                aBST.InorderSearchAward(temp, award);
                
                if(!temp.empty()){

                    for(int i = 0; i < (int)temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with this award *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'b':
            case 'B':{
                string award;
                cout << "---------------------------------------" << endl;
                cout << "             PARTIAL SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in actors-actresses  " << endl;
                cout << "What film would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,award);
                cout << endl;
                cout << "award: " << award << endl;
                cout << endl;
                cout << "* Searching for records with award that contains: " << award << "..." << endl;
                cout << endl;

                vector<ActorActressRecord> temp;
                aBST.InorderSearchAwardPartial(temp, award);
                
                if(!temp.empty()){
                    for(int i = 0; i < temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Award: " << temp[i].getAward() << endl;
                        cout << "Film: " << temp[i].getFilm() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with that contain this input *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end while
    return empty;
} // end search award

// search actor by fields of choice
vector<ActorActressRecord> searchActor(ActorBST &aBST){
    vector<ActorActressRecord> temp;
    temp.push_back(ActorActressRecord());
    char choice;
    do{
        cout << "-----------------------------------------" << endl;
        cout << "                  SEARCH                 " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "What field would you like to search on?  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Name" << endl;
        cout << "B:Year" << endl;
        cout << "C:Film" << endl;
        cout << "D:Award" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                temp = searchActorName(aBST);
                return temp;
                break;
            }
            case 'b':
            case 'B':{
                temp = searchActorYear(aBST);
                return temp;
                break;
            }
            case 'c':
            case 'C':{
                temp = searchActorFilm(aBST);
                return temp;
                break;
            }
            case 'd':
            case 'D':{
                temp = searchActorAward(aBST);
                return temp;
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
    return temp;
} // end searchActor

// search pictures for a name
vector<PictureRecord> searchPictureName(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string name;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What name would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,name);
            cout << endl;
            cout << "name: " << name << endl;
            cout << endl;
            cout << "* Searching for records with name: " << name << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchName(aVector, name);
            
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this name *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string name;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What name would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,name);
            cout << endl;
            cout << "name: " << name << endl;
            cout << endl;
            cout << "* Searching for records with name that contains: " << name << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchNamePartial(aVector, name);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureName

// search pictures for year
vector<PictureRecord> searchPictureYear(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string year;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What year would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,year);
            cout << endl;
            cout << "year: " << year << endl;
            cout << endl;
            cout << "* Searching for records with year: " << year << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchYear(aVector, year);
            
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this year *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string year;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What year would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,year);
            cout << endl;
            cout << "year: " << year << endl;
            cout << endl;
            cout << "* Searching for records with year that contains: " << year << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchYearPartial(aVector, year);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureYear

// search pictures for nomination
vector<PictureRecord> searchPictureNomination(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string nomination;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What nomination would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,nomination);
            cout << endl;
            cout << "nomination: " << nomination << endl;
            cout << endl;
            cout << "* Searching for records with nomination: " << nomination << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchNomination(aVector, nomination);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this nomination *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string nomination;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What nomination would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,nomination);
            cout << endl;
            cout << "nomination: " << nomination << endl;
            cout << endl;
            cout << "* Searching for records with nomination that contains: " << nomination << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchNominationPartial(aVector, nomination);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureNomination

// search pictures for rating
vector<PictureRecord> searchPictureRating(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string rating;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What rating would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,rating);
            cout << endl;
            cout << "rating: " << rating << endl;
            cout << endl;
            cout << "* Searching for records with rating: " << rating << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchRating(aVector, rating);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } //end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this rating *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string rating;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What rating would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,rating);
            cout << endl;
            cout << "rating: " << rating << endl;
            cout << endl;
            cout << "* Searching for records with rating that contains: " << rating << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchRatingPartial(aVector, rating);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureRating

// search pictures for duration
vector<PictureRecord> searchPictureDuration(vector<PictureRecord> &aVector){
        
        char choice;
        PictureRecord r;
        vector<PictureRecord> empty;
        empty.push_back(r);
        cout << "-----------------------------------------" << endl;
        cout << "What type of search would you like to do?" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Complete" << endl;
        cout << "B:Partial" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                string duration;
                cout << "---------------------------------------" << endl;
                cout << "            COMPLETE SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in pictures          " << endl;
                cout << "What duration would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,duration);
                cout << endl;
                cout << "duration: " << duration << endl;
                cout << endl;
                cout << "* Searching for records with duration: " << duration << "..." << endl;
                cout << endl;
                vector<PictureRecord> temp = searchDuration(aVector, duration);
                if(!temp.empty()){
                    for(int i = 0; i < (int)temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Nomination: " << temp[i].getNomination() << endl;
                        cout << "Rating: " << temp[i].getRating() << endl;
                        cout << "Duration: " << temp[i].getDuration() << endl;
                        cout << "Genre1: " << temp[i].getGenre1() << endl;
                        cout << "Genre2: " << temp[i].getGenre2() << endl;
                        cout << "Release: " << temp[i].getRelease() << endl;
                        cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                        cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with this duration *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'b':
            case 'B':{
                string duration;
                cout << "---------------------------------------" << endl;
                cout << "             PARTIAL SEARCH            " << endl;
                cout << "---------------------------------------" << endl;
                cout << "You are searching in pictures          " << endl;
                cout << "What duration would you like to search for?" << endl;
                cout << "---------------------------------------" << endl;
                cin.ignore();
                getline(cin,duration);
                cout << endl;
                cout << "duration: " << duration << endl;
                cout << endl;
                cout << "* Searching for records with duration that contains: " << duration << "..." << endl;
                cout << endl;
                vector<PictureRecord> temp = searchDurationPartial(aVector, duration);
                
                if(!temp.empty()){
                    for(int i = 0; i < temp.size(); i++){
                        cout << "-------------------------------" << endl;
                        cout << "Here are the record's contents: " << endl;
                        cout << "-------------------------------" << endl;
                        cout << "Name: " << temp[i].getName() << endl;
                        cout << "Year: " << temp[i].getYear() << endl;
                        cout << "Nomination: " << temp[i].getNomination() << endl;
                        cout << "Rating: " << temp[i].getRating() << endl;
                        cout << "Duration: " << temp[i].getDuration() << endl;
                        cout << "Genre1: " << temp[i].getGenre1() << endl;
                        cout << "Genre2: " << temp[i].getGenre2() << endl;
                        cout << "Release: " << temp[i].getRelease() << endl;
                        cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                        cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                        cout << "-------------------------------" << endl;
                    } // end for
                    
                    return temp;
                } // end if
                else{
                    cout << endl;
                    cout << "* There are no records with that contain this input *" << endl;
                    cout << endl;
                    
                    return empty;
                } // end else
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
        return empty;
} // end searchPictureDuration

// search pictures for genre1
vector<PictureRecord> searchPictureGenre1(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string genre1;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What genre1 would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,genre1);
            cout << endl;
            cout << "genre1: " << genre1 << endl;
            cout << endl;
            cout << "* Searching for records with genre1: " << genre1 << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchGenre1(aVector, genre1);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this genre1 *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string genre1;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What genre1 would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,genre1);
            cout << endl;
            cout << "genre1: " << genre1 << endl;
            cout << endl;
            cout << "* Searching for records with genre1 that contains: " << genre1 << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchGenre1Partial(aVector, genre1);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureGenre1

// search pictures for genre2
vector<PictureRecord> searchPictureGenre2(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string genre2;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What genre2 would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,genre2);
            cout << endl;
            cout << "genre2: " << genre2 << endl;
            cout << endl;
            cout << "* Searching for records with genre2: " << genre2 << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchGenre2(aVector, genre2);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this genre2 *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string genre2;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What genre2 would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,genre2);
            cout << endl;
            cout << "genre2: " << genre2 << endl;
            cout << endl;
            cout << "* Searching for records with genre2 that contains: " << genre2 << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchGenre2Partial(aVector, genre2);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureGenre2

// search pictures for release
vector<PictureRecord> searchPictureRelease(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string release;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What release would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,release);
            cout << endl;
            cout << "release: " << release << endl;
            cout << endl;
            cout << "* Searching for records with release: " << release << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchRelease(aVector, release);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this release *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string release;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What release would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,release);
            cout << endl;
            cout << "release: " << release << endl;
            cout << endl;
            cout << "* Searching for records with release that contains: " << release << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchRelease(aVector, release);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPicturesRelease

// search pictures for metacritic
vector<PictureRecord> searchPictureMetacritic(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string metacritic;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What metacritic would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,metacritic);
            cout << endl;
            cout << "metacritic: " << metacritic << endl;
            cout << endl;
            cout << "* Searching for records with metacritic: " << metacritic << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchMetacritic(aVector, metacritic);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this metacritic *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string metacritic;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What metacritic would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,metacritic);
            cout << endl;
            cout << "metacritic: " << metacritic << endl;
            cout << endl;
            cout << "* Searching for records with metacritic that contains: " << metacritic << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchMetacritic(aVector, metacritic);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPicturesMetacritic

// search pictures for synopsis
vector<PictureRecord> searchPictureSynopsis(vector<PictureRecord> &aVector){
    
    char choice;
    PictureRecord r;
    vector<PictureRecord> empty;
    empty.push_back(r);
    cout << "-----------------------------------------" << endl;
    cout << "What type of search would you like to do?" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "A:Complete" << endl;
    cout << "B:Partial" << endl;
    cout << "Q:Exit to main menu" << endl;
    cout << "--------------------------------------" << endl;
    cin >> choice;
    
    switch (choice) {
        case 'a':
        case 'A':{
            string synopsis;
            cout << "---------------------------------------" << endl;
            cout << "            COMPLETE SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What synopsis would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,synopsis);
            cout << endl;
            cout << "synopsis: " << synopsis << endl;
            cout << endl;
            cout << "* Searching for records with synopsis: " << synopsis << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchSynopsis(aVector, synopsis);
            if(!temp.empty()){
                for(int i = 0; i < (int)temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with this synopsis *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'b':
        case 'B':{
            string synopsis;
            cout << "---------------------------------------" << endl;
            cout << "             PARTIAL SEARCH            " << endl;
            cout << "---------------------------------------" << endl;
            cout << "You are searching in pictures          " << endl;
            cout << "What synopsis would you like to search for?" << endl;
            cout << "---------------------------------------" << endl;
            cin.ignore();
            getline(cin,synopsis);
            cout << endl;
            cout << "synopsis: " << synopsis << endl;
            cout << endl;
            cout << "* Searching for records with synopsis that contains: " << synopsis << "..." << endl;
            cout << endl;
            vector<PictureRecord> temp = searchSynopsis(aVector, synopsis);
            
            if(!temp.empty()){
                for(int i = 0; i < temp.size(); i++){
                    cout << "-------------------------------" << endl;
                    cout << "Here are the record's contents: " << endl;
                    cout << "-------------------------------" << endl;
                    cout << "Name: " << temp[i].getName() << endl;
                    cout << "Year: " << temp[i].getYear() << endl;
                    cout << "Nomination: " << temp[i].getNomination() << endl;
                    cout << "Rating: " << temp[i].getRating() << endl;
                    cout << "Duration: " << temp[i].getDuration() << endl;
                    cout << "Genre1: " << temp[i].getGenre1() << endl;
                    cout << "Genre2: " << temp[i].getGenre2() << endl;
                    cout << "Release: " << temp[i].getRelease() << endl;
                    cout << "Metacritic: " << temp[i].getMetacritic() << endl;
                    cout << "Synopsis: " << temp[i].getSynopsis() << endl;
                    cout << "-------------------------------" << endl;
                } // end for
                
                return temp;
            } // end if
            else{
                cout << endl;
                cout << "* There are no records with that contain this input *" << endl;
                cout << endl;
                
                return empty;
            } // end else
            break;
        }
        case 'q':
        case 'Q':
            break;
        default:
            cout << endl;
            cout << "* Invalid input! Try again. *" << endl;
            cout << endl;
            break;
    } // end switch
    return empty;
} // end searchPictureSynopsis

// search picture by chosen fields
vector<PictureRecord> searchPicture(vector<PictureRecord> &aVector){
    vector<PictureRecord> temp;
    temp.push_back(PictureRecord());
    char choice;
    do{
        cout << "-----------------------------------------" << endl;
        cout << "                  SEARCH                 " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "What field would you like to search on?  " << endl;
        cout << "-----------------------------------------" << endl;
        cout << "A:Name" << endl;
        cout << "B:Year" << endl;
        cout << "C:Nominations " << endl;
        cout << "D:Rating " << endl;
        cout << "E:Duration " << endl;
        cout << "F:Genre 1 " << endl;
        cout << "G:Genre 2 " << endl;
        cout << "H:Release " << endl;
        cout << "I:Metacritic " << endl;
        cout << "J:Synopsis " << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                temp = searchPictureName(aVector);
                return temp;
                break;
            }
            case 'b':
            case 'B':{
                temp = searchPictureYear(aVector);
                return temp;
                break;
            }
            case 'c':
            case 'C':{
                temp = searchPictureNomination(aVector);
                return temp;
                break;
            }
            case 'd':
            case 'D':{
                temp = searchPictureRating(aVector);
                return temp;
                break;
            }
            case 'e':
            case 'E':{
                temp = searchPictureDuration(aVector);
                return temp;
                break;
            }
            case 'f':
            case 'F':{
                temp = searchPictureGenre1(aVector);
                return temp;
                break;
            }
            case 'g':
            case 'G':{
                temp = searchPictureGenre2(aVector);
                return temp;
                break;
            }
            case 'h':
            case 'H':{
                temp = searchPictureRelease(aVector);
                return temp;
                break;
            }
            case 'i':
            case 'I':{
                temp = searchPictureMetacritic(aVector);
                return temp;
                break;
            }
            case 'j':
            case 'J':{
                temp = searchPictureSynopsis(aVector);
                return temp;
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
    return temp;
} // end searchPicture

// user chooses fields to print out for report
void printActorFields(){
    vector<ActorActressRecord> v;
    bool name, film, award, year;
    name = false; film = false; award = false; year = false;

    readInFile(v, "updatedFileActor.txt");
    ofstream outFile;
    outFile.open("ActorReport.txt", ofstream::trunc);
    
    char choiceYear;
    cout << "Would you like the year field to be printed out? (Y/N)" << endl;
    cin >> choiceYear;
    choiceYear = toupper(choiceYear);
    while(choiceYear != 'Y' && choiceYear != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceYear;
        choiceYear = toupper(choiceYear);
    } // end while
    if(choiceYear == 'Y'){
        year = true;
    } // end if
    char choiceName;
    cout << "Would you like the name field to be printed out? (Y/N)" << endl;
    cin >> choiceName;
    choiceName = toupper(choiceName);
    while(choiceName != 'Y' && choiceName != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceName;
        choiceName = toupper(choiceName);
    } // end while
    if(choiceName == 'Y'){
        name = true;
    } // end if
    char choiceAward;
    cout << "Would you like the award field to be printed out? (Y/N)" << endl;
    cin >> choiceAward;
    choiceAward = toupper(choiceAward);
    while(choiceAward != 'Y' && choiceAward != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceAward;
        choiceAward = toupper(choiceAward);
    } // end while
    if(choiceAward == 'Y'){
        award = true;
    } // end if
    char choiceFilm;
    cout << "Would you like the film field to be printed out? (Y/N)" << endl;
    cin >> choiceFilm;
    choiceFilm = toupper(choiceFilm);
    while(choiceFilm != 'Y' && choiceFilm != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceFilm;
        choiceFilm = toupper(choiceFilm);
    } // end while
    if(choiceFilm == 'Y'){
        film = true;
    } // end if
    
    outFile << "Fields included: ";
    if(year == true){
        outFile << "Year | ";
    } // end if
    if(name == true){
        outFile << "Name | ";
    } // end if
    if(award == true){
        outFile << "Award | ";
    } // end if
    if(film == true){
        outFile << "Film";
    } // end if
    outFile << endl;
    outFile << endl;
    
    for(int i = 0; i < (int)v.size(); i++){
        if(year == true){
            outFile << v[i].getYear()<< ",";
        } // end if
        if(name == true){
            outFile << v[i].getName()<< ",";
        } // end if
        if(award == true){
            outFile << v[i].getAward()<< ",";
        } // end if
        if(film == true){
            outFile << v[i].getFilm();
        } // end if
        outFile << endl;
    } // end for
    outFile.close();
} // end printActorFields

void printActorReport(ActorBST &aBST){
    
    char choice;
    do{
        cout << "---------------------------------------" << endl;
        cout << "What report would you like to print out?" << endl;
        cout << "---------------------------------------" << endl;
        cout << "A:Sorted" << endl;
        cout << "B:Search" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                cout << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "Step 1: Sort by field of your choice, then exit sort menu" << endl;
                cout << "Step 2: Select which fields are to be printed to file" << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << endl;
                sortActor(aBST); // will write out to updatedFileActor.txt
                printActorFields();
                cout << endl;
                cout << "* successfully wrote this record to ActorReport.txt *" << endl;
                cout << endl;
                break;
            }
            case 'b':
            case 'B':{
                
                vector<ActorActressRecord> v = searchActor(aBST);
                ofstream outFile;
                outFile.open("ActorReport.txt", ofstream::trunc);
                
                if(v[0].getName() != ""){
                    outFile << "Name | Year | Award | Film " << endl;
                    for(int i = 0; i < (int)v.size(); i++){
                    outFile << v[i].getName() << "," << v[i].getYear() << "," << v[i].getAward() << "," << v[i].getFilm() << endl;
                    } // end for
                    cout << endl;
                    cout << "* successfully wrote record(s) to ActorReport.txt *" << endl;
                    cout << endl;
                } // end if
                else{
                    outFile << "* There is no record for that name *" << endl;
                } // end else
                outFile.close();
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << "Invalid input! Try again. " << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
} // end printActorReport

// user chooses which picture fields to print for report
void printPictureFields(){
    vector<PictureRecord> v;
    bool name, year, nomination, rating, duration, genre1, genre2, release, metacritic, synopsis;
    name = false; year = false; nomination = false; rating = false, duration = false; genre1 = false; genre2 = false; release = false, metacritic = false, synopsis = false;
    
    readInFile(v, "updatedFilePicture.txt");
    ofstream outFile;
    outFile.open("PictureReport.txt", ofstream::trunc);
    
    char choiceName;
    cout << "Would you like the name field to be printed out? (Y/N)" << endl;
    cin >> choiceName;
    choiceName = toupper(choiceName);
    while(choiceName != 'Y' && choiceName != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceName;
        choiceName = toupper(choiceName);
    } // end while
    if(choiceName == 'Y'){
        name = true;
    } // end if
    char choiceYear;
    cout << "Would you like the year field to be printed out? (Y/N)" << endl;
    cin >> choiceYear;
    choiceYear = toupper(choiceYear);
    while(choiceYear != 'Y' && choiceYear != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceYear;
        choiceYear = toupper(choiceYear);
    } // end while
    if(choiceYear == 'Y'){
        year = true;
    } // end if
    char choiceNom;
    cout << "Would you like the nomination field to be printed out? (Y/N)" << endl;
    cin >> choiceNom;
    choiceNom = toupper(choiceNom);
    while(choiceNom != 'Y' && choiceNom != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceNom;
        choiceNom = toupper(choiceNom);
    } // end while
    if(choiceNom == 'Y'){
        nomination = true;
    } // end if
    char choiceRating;
    cout << "Would you like the rating field to be printed out? (Y/N)" << endl;
    cin >> choiceRating;
    choiceRating = toupper(choiceRating);
    while(choiceRating != 'Y' && choiceRating != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceRating;
        choiceRating = toupper(choiceRating);
    } // end while
    if(choiceRating == 'Y'){
        rating = true;
    } // end if
    char choiceDur;
    cout << "Would you like the duration field to be printed out? (Y/N)" << endl;
    cin >> choiceDur;
    choiceDur = toupper(choiceDur);
    while(choiceDur != 'Y' && choiceDur != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceDur;
        choiceDur = toupper(choiceDur);
    } // end while
    if(choiceDur == 'Y'){
        duration = true;
    } // end if
    char choiceGenre1;
    cout << "Would you like the genre1 field to be printed out? (Y/N)" << endl;
    cin >> choiceGenre1;
    choiceGenre1 = toupper(choiceGenre1);
    while(choiceGenre1 != 'Y' && choiceGenre1 != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceGenre1;
        choiceGenre1 = toupper(choiceGenre1);
    } // end while
    if(choiceGenre1 == 'Y'){
        genre1 = true;
    } // end if
    char choiceGenre2;
    cout << "Would you like the genre2 field to be printed out? (Y/N)" << endl;
    cin >> choiceGenre2;
    choiceGenre2 = toupper(choiceGenre2);
    while(choiceGenre2 != 'Y' && choiceGenre2 != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceGenre2;
        choiceGenre2 = toupper(choiceGenre2);
    } // end while
    if(choiceGenre2 == 'Y'){
        genre2 = true;
    } // end if
    char choiceRelease;
    cout << "Would you like the release field to be printed out? (Y/N)" << endl;
    cin >> choiceRelease;
    choiceRelease = toupper(choiceRelease);
    while(choiceRelease != 'Y' && choiceRelease != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceRelease;
        choiceRelease = toupper(choiceRelease);
    } // end while
    if(choiceRelease == 'Y'){
        release = true;
    } // end if
    char choiceMeta;
    cout << "Would you like the metacritic field to be printed out? (Y/N)" << endl;
    cin >> choiceMeta;
    choiceMeta = toupper(choiceMeta);
    while(choiceMeta != 'Y' && choiceMeta != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceMeta;
        choiceMeta = toupper(choiceMeta);
    } // end while
    if(choiceMeta == 'Y'){
        metacritic = true;
    } // end if
    char choiceSynop;
    cout << "Would you like the synopsis field to be printed out? (Y/N)" << endl;
    cin >> choiceSynop;
    choiceSynop = toupper(choiceSynop);
    while(choiceSynop != 'Y' && choiceSynop != 'N'){
        cout << "Invalid input! Input Y or N" << endl;
        cin >> choiceSynop;
        choiceSynop = toupper(choiceSynop);
    } // end while
    if(choiceSynop == 'Y'){
        synopsis = true;
    } // end if
    
    outFile << "Fields included: ";
    if(name == true){
        outFile << "Name | ";
    } // end if
    if(year == true){
        outFile << "Year | ";
    } // end if
    if(nomination == true){
        outFile << "Nomination | ";
    } // end if
    if(rating == true){
        outFile << "Rating | ";
    } // end if
    if(duration == true){
        outFile << "Duration | ";
    } // end if
    if(genre1 == true){
        outFile << "Genre1 | ";
    }
    if(genre2 == true){
        outFile << "Genre2 | ";
    } // end if
    if(release == true){
        outFile << "Release | ";
    } // end if
    if(metacritic == true){
        outFile << "Metacritic | ";
    } // end if
    if(synopsis == true){
        outFile << "Synopsis";
    } // end if
    outFile << endl;
    outFile << endl;
    
    for(int i = 0; i < (int)v.size(); i++){
        if(name == true){
            outFile << v[i].getName()<< ",";
        } // end if
        if(year == true){
            outFile << v[i].getYear()<< ",";
        } // end if
        if(nomination == true){
            outFile << v[i].getNomination()<< ",";
        } // end if
        if(rating == true){
            outFile << v[i].getRating()<< ",";
        } // end if
        if(duration == true){
            outFile << v[i].getDuration()<< ",";
        } // end if
        if(genre1 == true){
            outFile << v[i].getGenre1()<< ",";
        } // end if
        if(genre2 == true){
            outFile << v[i].getGenre2()<< ",";
        } // end if
        if(release == true){
            outFile << v[i].getRelease()<< ",";
        } // end if
        if(metacritic == true){
            outFile << v[i].getMetacritic()<< ",";
        } // end if
        if(synopsis == true){
            outFile << v[i].getSynopsis();
        } // end if
        outFile << endl;
    } // end for
    outFile.close();
} // end printPictureFields

// print report for pictures based on sorted or searched
void printPictureReport(vector<PictureRecord> &aVector){
    
    char choice;
    do{
        cout << "---------------------------------------" << endl;
        cout << "What report would you like to print out?" << endl;
        cout << "---------------------------------------" << endl;
        cout << "A:Sorted" << endl;
        cout << "B:Search" << endl;
        cout << "Q:Exit to main menu" << endl;
        cout << "--------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                cout << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << "Step 1: Sort by field of your choice, then exit sort menu" << endl;
                cout << "Step 2: Select which fields are to be printed to file" << endl;
                cout << "---------------------------------------------------------" << endl;
                cout << endl;
                sortPicture(aVector); // will write out to updatedFileActor.txt
                printPictureFields();
                cout << endl;
                cout << "* successfully wrote this record to PictureReport.txt *" << endl;
                cout << endl;
                break;
            }
            case 'b':
            case 'B':{
                vector<PictureRecord> v = searchPicture(aVector);
                ofstream outFile;
                outFile.open("PictureReport.txt", ofstream::trunc);
                
                if(v[0].getName() != ""){
                    outFile << "Name | Year | Nominations | Rating | Duration | Genre 1 | Genre 2 | Release | Metacritic | Synopsis " << endl;
                    for(int i = 0; i < (int)v.size(); i++){
                        outFile << v[i].getName() << "," << v[i].getYear() << "," << v[i].getNomination() << "," << v[i].getRating() << "," << v[i].getDuration() << "," << v[i].getGenre1() << "," << v[i].getGenre2() << "," << v[i].getRelease() << "," << v[i].getMetacritic() << "," << v[i].getSynopsis() << endl;
                    } // end for
                    cout << endl;
                    cout << "* successfully wrote record(s) to PictureReport.txt *" << endl;
                    cout << endl;
                } // end if
                else{
                    outFile << "* There is no record for that name *" << endl;
                } // end else
                
                outFile.close();
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
} // end printPictureReport

// will print out top five names that appear most in actors-actresses
void topFiveNames(){
    struct name{
        string name;
        int bucketSize;
    }; // end name
    vector<ActorActressRecord> temp;
    readInFile(temp, "actor-actress.csv");
    vector<string> uniqueNames;
    vector<name> topFiveNames;
    
    unordered_multimap<string, ActorActressRecord> map;
    for(int i = 0; i < (int)temp.size(); i++){
        // utilized <algorithm> for this
        // found on https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
        if(!(find(uniqueNames.begin(),uniqueNames.end(),temp[i].getName()) != uniqueNames.end())){
            uniqueNames.push_back(temp[i].getName());
        } // end if
    } // end for
    for(int i = 0; i < (int)temp.size(); i++){
        map.emplace(temp[i].getName(), temp[i]);
    } // end for
    name topName;
    int topSize = 0;
    int topIndex = 0;
    for(int i = 0; i < 5; i++){
        topSize = 0;
        topIndex = 0;
        for(int i = 0; i < (int)uniqueNames.size(); i++){
            if((int)map.bucket_size(map.bucket(uniqueNames[i])) > topSize){
                topSize = (int)map.bucket_size(map.bucket(uniqueNames[i]));
                topIndex = i;
            } // end if
        } // end for
        topName.name = uniqueNames[topIndex];
        topName.bucketSize = topSize;
        topFiveNames.push_back(topName);
        uniqueNames.erase(uniqueNames.begin() + topIndex);
    } // end for
    
    cout << endl;
    cout << "* Here are the top 5 names in actor-actress *" << endl;
    cout << endl;
    for(int i = 0; i < (int)topFiveNames.size(); i++){
        cout << endl;
        cout << "Number: " << i + 1 << endl;
        cout << "Name: " << topFiveNames[i].name << endl;
        cout << "Number of times name appears: " << topFiveNames[i].bucketSize << endl;
        cout << endl;
    } // end for
} // end topFiveNames

// will print out top five films that appear most in actors-actresses
void topFiveFilms(){
    struct film{
        string film;
        int bucketSize;
    }; // end name
    vector<ActorActressRecord> temp;
    readInFile(temp, "actor-actress.csv");
    vector<string> uniqueFilms;
    vector<film> topFiveFilms;
    
    unordered_multimap<string, ActorActressRecord> map;
    for(int i = 0; i < (int)temp.size(); i++){
        // utilized <algorithm> for this
        // found on https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
        if(!(find(uniqueFilms.begin(),uniqueFilms.end(),temp[i].getFilm()) != uniqueFilms.end())){
            uniqueFilms.push_back(temp[i].getFilm());
        } // end if
    } // end for
    for(int i = 0; i < (int)temp.size(); i++){
        map.emplace(temp[i].getFilm(), temp[i]);
    } // end for
    film topFilm;
    int topSize = 0;
    int topIndex = 0;
    for(int i = 0; i < 5; i++){
        topSize = 0;
        topIndex = 0;
        for(int i = 0; i < (int)uniqueFilms.size(); i++){
            if((int)map.bucket_size(map.bucket(uniqueFilms[i])) > topSize){
                topSize = (int)map.bucket_size(map.bucket(uniqueFilms[i]));
                topIndex = i;
            } // end if
        } // end for
        topFilm.film = uniqueFilms[topIndex];
        topFilm.bucketSize = topSize;
        topFiveFilms.push_back(topFilm);
        uniqueFilms.erase(uniqueFilms.begin() + topIndex);
    } // end for
    
    cout << endl;
    cout << "* Here are the top 5 films in actor-actress *" << endl;
    cout << endl;
    for(int i = 0; i < (int)topFiveFilms.size(); i++){
        cout << endl;
        cout << "Number: " << i + 1 << endl;
        cout << "Film: " << topFiveFilms[i].film << endl;
        cout << "Number of times film appears: " << topFiveFilms[i].bucketSize << endl;
        cout << endl;
    } // end for
} // end topFiveFilms

void topTenRatings(){
    vector<PictureRecord> temp;
    readInFile(temp, "pictures.csv");
    vector<float> uniqueRatings;
    vector<PictureRecord> uniqueRatingsObject;
    vector<PictureRecord> topRatings;
    
    for(int i = 0; i < (int)temp.size(); i++){
        // utilized <algorithm> for this
        // found on https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
        if(!(find(uniqueRatings.begin(),uniqueRatings.end(),stof(temp[i].getRating())) != uniqueRatings.end())){
            uniqueRatings.push_back(stof(temp[i].getRating()));
            uniqueRatingsObject.push_back(temp[i]);
        } // end if
    } // end if
    int topIndex = 0;
    float topRating = 0;
    for(int i = 0; i < 10; i++){
        topIndex = 0;
        topRating = 0;
        for(int i = 0; i < (int)uniqueRatings.size(); i++){
            if(stof(uniqueRatingsObject[i].getRating()) > topRating){
                topRating = stof(uniqueRatingsObject[i].getRating());
                topIndex = i;
            } // end if
        } // end if
        topRatings.push_back(uniqueRatingsObject[topIndex]);
        uniqueRatingsObject.erase(uniqueRatingsObject.begin() + topIndex);
    } // end if
    
    cout << endl;
    cout << "* Here are the top 10 ratings in pictures *" << endl;
    cout << endl;
    for(int i = 0; i < (int)topRatings.size(); i++){
        cout << endl;
        cout << "Number: " << i + 1 << endl;
        cout << "Name: " << topRatings[i].getName() << endl;
        cout << "Year: " << topRatings[i].getYear() << endl;
        cout << "Nominations: " << topRatings[i].getNomination() << endl;
        cout << "Rating: " << topRatings[i].getRating() << endl;
        cout << "Duration: " << topRatings[i].getDuration() << endl;
        cout << "Genre 1: " << topRatings[i].getGenre1() << endl;
        cout << "Genre 2: " << topRatings[i].getGenre2() << endl;
        cout << "Release: " << topRatings[i].getRelease() << endl;
        cout << "Metacritic: " << topRatings[i].getMetacritic() << endl;
        cout << "Synopsis: " << topRatings[i].getSynopsis() << endl;
        cout << endl;
    } // end for

} // end topTenRatings

void topTenDurations(){
    vector<PictureRecord> temp;
    readInFile(temp, "pictures.csv");
    vector<float> uniqueDurations;
    vector<PictureRecord> uniqueDurationsObject;
    vector<PictureRecord> topDurations;
    
    for(int i = 0; i < (int)temp.size(); i++){
        // utilized <algorithm> for this
        // found on https://stackoverflow.com/questions/571394/how-to-find-out-if-an-item-is-present-in-a-stdvector
        if(!(find(uniqueDurations.begin(),uniqueDurations.end(),stof(temp[i].getDuration())) != uniqueDurations.end())){
            uniqueDurations.push_back(stof(temp[i].getDuration()));
            uniqueDurationsObject.push_back(temp[i]);
        } // end if
    } // end if
    int topIndex = 0;
    float topDuration = 0;
    for(int i = 0; i < 10; i++){
        topIndex = 0;
        topDuration = 0;
        for(int i = 0; i < (int)uniqueDurations.size(); i++){
            if(stof(uniqueDurationsObject[i].getDuration()) > topDuration){
                topDuration = stof(uniqueDurationsObject[i].getDuration());
                topIndex = i;
            } // end if
        } // end if
        topDurations.push_back(uniqueDurationsObject[topIndex]);
        uniqueDurationsObject.erase(uniqueDurationsObject.begin() + topIndex);
    } // end if
    
    cout << endl;
    cout << "* Here are the top 10 durations in pictures *" << endl;
    cout << endl;
    for(int i = 0; i < (int)topDurations.size(); i++){
        cout << endl;
        cout << "Number: " << i + 1 << endl;
        cout << "Name: " << topDurations[i].getName() << endl;
        cout << "Year: " << topDurations[i].getYear() << endl;
        cout << "Nominations: " << topDurations[i].getNomination() << endl;
        cout << "Rating: " << topDurations[i].getRating() << endl;
        cout << "Duration: " << topDurations[i].getDuration() << endl;
        cout << "Genre 1: " << topDurations[i].getGenre1() << endl;
        cout << "Genre 2: " << topDurations[i].getGenre2() << endl;
        cout << "Release: " << topDurations[i].getRelease() << endl;
        cout << "Metacritic: " << topDurations[i].getMetacritic() << endl;
        cout << "Synopsis: " << topDurations[i].getSynopsis() << endl;
        cout << endl;
    } // end for
    
} // end topTenDurations

void specialReports(){
    char choice;
    do{
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << "      Please select the type of report      " << endl;
        cout << "            you would like to see           " << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl;
        cout << "A:Top five actor-actress names" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "B:Top five actor-actress films              " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "C:Top ten pictures ratings                  " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "D:Top ten pictures durations                " << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Q:Quit" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                topFiveNames();
                break;
            }
            case 'b':
            case 'B':{
                topFiveFilms();
                break;
            }
            case 'c':
            case 'C':{
                topTenRatings();
                break;
            }
            case 'd':
            case 'D':{
                topTenDurations();
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
} // end specialReports

// menu for program functions
void menu(){
    char choice;
    ActorBST aBST;
    PictureBST pBST;
    vector<PictureRecord> pVector;
    do{
        cout << "********************************************" << endl;
        cout << "*                                          *" << endl;
        cout << "*                 MAIN MENU                *" << endl;
        cout << "*                                          *" << endl;
        cout << "********************************************" << endl;
        cout << endl;
        cout << "--------------------------------------------" << endl;
        cout << "   ALL RECORDS CONVERTED TO LOWERCASE FOR   " << endl;
        cout << "  EASE OF TESTING, WHEN PROMPTED TO SEARCH  " << endl;
        cout << "       INPUT YOUR ENTRY IN LOWERCASE        " << endl;
        cout << "                                            " << endl;
        cout << "           EXTRA CREDIT IS OPTION P         " << endl;
        cout << "    * PRINTS SPECIAL STATISTICS REPORTS *   " << endl;
        cout << "--------------------------------------------" << endl;
        cout << endl;
        cout << "A:Read in Actors-Actresses" << endl;
        cout << endl;
        cout << "B:Read in Pictures" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "C:Add information (to Actors-Actresses or Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "D:Modify information (to Actors-Actresses)" << endl;
        cout << endl;
        cout << "E:Modify information (to Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "F:Delete information (from Actors-Actresses)" << endl;
        cout << endl;
        cout << "G:Delete information (from Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "H:Sort (Actors-Actresses)" << endl;
        cout << endl;
        cout << "I:Sort (Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "J:Search (Actors-Actresses)" << endl;
        cout << endl;
        cout << "K:Search (Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "L:Write to file (Actors-Actresses)" << endl;
        cout << endl;
        cout << "M:Write to file (Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "N:Print out report (Actors-Actresses)" << endl;
        cout << endl;
        cout << "O:Print out report (Pictures)" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "P:Extra Credit - Special Reports" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "Q:Quit" << endl;
        cout << "--------------------------------------------" << endl;
        cin >> choice;
        
        switch (choice) {
            case 'a':
            case 'A':{
                readToActors(aBST);
                break;
            }
            case 'b':
            case 'B':{
                readToPictures(pBST, pVector);
                break;
            }
            case 'c':
            case 'C':{
                addRecord(aBST,pVector);
                break;
            }
            case 'd':
            case 'D':{
                modifyActorName(aBST);
                break;
            }
            case 'e':
            case 'E':{
                modifyPictureName(pVector);
                break;
            }
            case 'f':
            case 'F':{
                deleteActorRecord(aBST);
                break;
            }
            case 'g':
            case 'G':{
                deletePictureRecord(pVector);
                break;
            }
            case 'h':
            case 'H':{
                sortActor(aBST);
                break;
            }
            case 'i':
            case 'I':{
                sortPicture(pVector);
                break;
            }
            case 'j':
            case 'J':{
                searchActor(aBST);
                break;
            }
            case 'k':
            case 'K':{
                searchPicture(pVector);
                break;
            }
            case 'l':
            case 'L':{
                ofstream outFile;
                outFile.open("updatedFileActor.txt", ofstream::trunc);
                writeToFileActor(aBST, outFile);
                outFile.close();
                break;
            }
            case 'm':
            case 'M':{
                ofstream outFile;
                outFile.open("updatedFilePicture.txt", ofstream::trunc);
                writeToFilePicture(pVector, outFile);
                outFile.close();
                break;
            }
            case 'n':
            case 'N':{
                printActorReport(aBST);
                break;
            }
            case 'o':
            case 'O':{
                printPictureReport(pVector);
                break;
            }
            case 'p':
            case 'P':{
                specialReports();
                break;
            }
            case 'q':
            case 'Q':
                break;
            default:
                cout << endl;
                cout << "* Invalid input! Try again. *" << endl;
                cout << endl;
                break;
        } // end switch
    }while(choice != 'Q' && choice != 'q'); // end do while
} // end menu

#endif /* FUNCTIONS_H */












