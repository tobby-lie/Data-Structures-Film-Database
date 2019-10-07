//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//ActorBST and ActorNode class prototypes

#ifndef ACTORBST_H
#define ACTORBST_H

#include <string>
#include "ActorActressRecord.h"

using namespace std;

class ActorNode {
private:
    ActorActressRecord record;
    string key;
    ActorNode* left;
    ActorNode* right;
    ActorNode* parent;
public:
    ActorNode() { key=""; left=nullptr; right=nullptr; parent = nullptr; };
    void setRecord(ActorActressRecord aRecord){record = aRecord; };
    void setKey(string aKey) {key = aKey; };
    void setLeft(ActorNode* aLeft) { left = aLeft; };
    void setRight(ActorNode* aRight) { right = aRight; };
    void setParent(ActorNode* aParent) { parent = aParent; };
    string Key() { return key; };
    ActorActressRecord Record() { return record; };
    ActorNode* Left() { return left; };
    ActorNode* Right() { return right; };
    ActorNode* Parent() { return parent; };
};

class ActorBST{ // used to store actor records that will be used for searches, insertion, deletion and modification
private:
    ActorNode* root;
    int size = 0;
    void addNode(string key, ActorNode* leaf, ActorActressRecord aRecord);
    ActorNode* findNode(string key, ActorNode* node);
    void printInorder(ActorNode* node);
    ActorNode* deleteNode(ActorNode* root,string key);
    void InorderWriteToFile(ActorNode* node, ofstream &out);
    void InorderWriteOutputToVector(ActorNode* node,vector<ActorActressRecord> &aVector);
    void InorderSearchName(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchAward(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchYear(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchFilm(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchNamePartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchAwardPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchYearPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
    void InorderSearchFilmPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target);
public:
    ActorBST();
    ~ActorBST();
    int getSize() const { return size; };
    void setRoot(ActorNode *_root) {root = _root;};
    ActorNode* Root() { return root; };
    void freeNode(ActorNode* leaf);
    ActorNode* makeNode(string _key, ActorActressRecord aRecord, ActorNode* parent);
    void addNode(string key, string year, string award, string winner, string name, string film);
    ActorNode* findNode(string key);
    void printInorder();
    void InorderWriteToFile(ofstream &out);
    void InorderWriteOutputToVector(vector<ActorActressRecord> &aVector);
    void InorderSearchName(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchAward(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchYear(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchFilm(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchNamePartial(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchAwardPartial(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchYearPartial(vector<ActorActressRecord> &aVector, string target);
    void InorderSearchFilmPartial(vector<ActorActressRecord> &aVector, string target);
    void deleteNode(string key);
    ActorNode* min(ActorNode* node);
    ActorNode* max(ActorNode* node);
};

#endif /* ACTORBST_H */

