//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//PictureBST and PictureNode class prototypes

#ifndef PICTUREBST_H
#define PICTUREBST_H

#include <string>
#include "PictureRecord.h"

using namespace std;

class PictureNode {
private:
    PictureRecord record;
    string key;
    PictureNode* left;
    PictureNode* right;
    PictureNode* parent;
public:
    PictureNode() { key=""; left=nullptr; right=nullptr; parent = nullptr; };
    void setRecord(PictureRecord aRecord){record = aRecord; };
    void setKey(string aKey) {key = aKey; };
    void setLeft(PictureNode* aLeft) { left = aLeft; };
    void setRight(PictureNode* aRight) { right = aRight; };
    void setParent(PictureNode* aParent) { parent = aParent; };
    string Key() { return key; };
    PictureRecord Record() { return record; };
    PictureNode* Left() { return left; };
    PictureNode* Right() { return right; };
    PictureNode* Parent() { return parent; };
};

class PictureBST{ // used to store picture records that will be used for searches, insertion, deletion and modification
private:
    PictureNode* root;
    int size = 0;
    void addNode(string key, PictureNode* leaf, PictureRecord aRecord);
    PictureNode* findNode(string key, PictureNode* node);
    void printInorder(PictureNode* node);
    PictureNode* deleteNode(PictureNode* root,string key);
    void InorderWriteToFile(PictureNode* node, ofstream &out);
    void InorderWriteOutputToVector(PictureNode* node,vector<PictureRecord> &aVector);
public:
    PictureBST();
    ~PictureBST();
    int getSize() const { return size; };
    void setRoot(PictureNode *_root) {root = _root;};
    PictureNode* Root() { return root; };
    void freeNode(PictureNode* leaf);
    PictureNode* makeNode(string _key, PictureRecord aRecord, PictureNode* parent);
    void addNode(string key, string name, string year, string nomination, string rating, string duration, string genre1, string genre2, string release, string metacritic, string synopsis);
    PictureNode* findNode(string key);
    void printInorder();
    void InorderWriteToFile(ofstream &out);
    void InorderWriteOutputToVector(vector<PictureRecord> &aVector);
    void deleteNode(string key);
    PictureNode* min(PictureNode* node);
    PictureNode* max(PictureNode* node);
};

#endif /* PICTUREBST_H */












