//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//PictureBST class implementation

#include <fstream>
#include <iostream>
#include <vector>
#include "PictureBST.h"

using namespace std;

// Constructor
PictureBST::PictureBST() {
    root = new PictureNode;
} // end PictureBST

// Destructor
PictureBST::~PictureBST() {
    if (root !=nullptr)
        freeNode(root);
} // end ~PictureBST

// Free the node
void PictureBST::freeNode(PictureNode* leaf)
{
    if ( this->Root() == leaf)
    {
        delete leaf;
    } // end if
    else if ( leaf != nullptr )
        
    {
        freeNode(leaf->Left());
        freeNode(leaf->Right());
        delete leaf;
    } // end else if
    
} // end freeNode

// Add a node
void PictureBST::addNode(string key, string name, string year, string nomination, string rating, string duration, string genre1, string genre2, string release, string metacritic, string synopsis)
{
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
    
    addNode(name, root, aRecord);
    
} // end addode

// Add a node (private)
void PictureBST::addNode(string key, PictureNode* leaf, PictureRecord aRecord) {
    
    // traversals are due to the nature of the BST
    // the parent will just be the previous tree
    // if key < current leaf key then traverse left
    if(key < leaf->Key()){
        // if left is not null then traverse left
        if(leaf->Left() != nullptr){
            addNode(key, leaf->Left(), aRecord);
        } // end if
        // if left is null then just make new node go left
        else{
            leaf->setLeft(makeNode(key,aRecord,leaf));
            size++;
        } // end else
    } // end if
    // if key > current leaf key then traverse right
    else if(key >= leaf->Key()){
        // if right is not null then traverse right
        if(leaf->Right() != nullptr){
            addNode(key, leaf->Right(), aRecord);
        } // end if
        // if left is null then just make new node go right
        else{
            leaf->setRight(makeNode(key,aRecord,leaf));
            size++;
        } // end else
    } // end else if
} // end addNode

PictureNode* PictureBST::findNode(string key)
{
    return findNode(key, root);
} // end findNode

// Find a node
PictureNode* PictureBST::findNode(string key, PictureNode* node)
{
    
    // if tree is not empty
    if(node != nullptr){
        // if the current node key is equal to key then return that node
        if(node->Key() == key){
            return node;
        } // end if
        else{
            // if key < current node key, need to traverse left
            if(key < node->Key()){
                return findNode(key, node->Left());
            } // end if
            // if greater
            else{
                return findNode(key, node->Right());
            } // end else
        } // end else
    } // end if
    // if tree is empty
    else{
        return nullptr;
    } // end else
} // end findNode

void PictureBST::printInorder()
{
    printInorder(root);
} // end printInorder

void PictureBST::printInorder(PictureNode* node)
{
    // inOrder is defined as: left, visit, right
    
    // if tree is not empty
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            printInorder(node->Left());
        } // end if
        // "visit"
        PictureRecord r;
        r = node->Record();
        if(r.getName() != ""){
            cout << "Name: " << r.getName() << endl;
            cout << "Year: " << r.getYear() << endl;
            cout << "Nominations: " << r.getNomination() << endl;
            cout << "Rating: " << r.getRating() << endl;
            cout << "Duration: " << r.getDuration() << endl;
            cout << "Genre 1: " << r.getGenre1() << endl;
            cout << "Genre 2: " << r.getGenre2() << endl;
            cout << "Release: " << r.getRelease() << endl;
            cout << "Metacritic: " << r.getMetacritic() << endl;
            cout << "Synopsis: " << r.getSynopsis() << endl;
            cout << endl;
        } // end if
        // go right
        if(node->Right() != nullptr){
            printInorder(node->Right());
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end printInorder

// will traverse tree in order and each visit will add to a vector
void PictureBST::InorderWriteOutputToVector(vector<PictureRecord> &aVector)
{
    InorderWriteOutputToVector(root, aVector);
} // end InorderWriteOutputToVector

void PictureBST::InorderWriteOutputToVector(PictureNode* node,vector<PictureRecord> &aVector){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderWriteOutputToVector(node->Left(), aVector);
        } // end if
        
        PictureRecord r;
        r = node->Record();

        aVector.emplace_back(r);
        
        // go right
        if(node->Right() != nullptr){
            InorderWriteOutputToVector(node->Right(), aVector);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderWriteOutputToVector

void PictureBST::deleteNode(string key)
{
    
    {
        if (deleteNode(Root(), key) == nullptr)
            setRoot(nullptr);
    } // end if
    
} // end deleteNode

//deleteNode (Private)
PictureNode* PictureBST::deleteNode(PictureNode* root,string key)
{
    
    /* Given a binary search tree and a key, this function deletes the key
     and returns the new root */
    
    if (root == nullptr) return root; // end if
    else if (key < root->Key())
        root->setLeft(deleteNode(root->Left(), key)); // end else if
    else if (key > root->Key())
        root->setRight(deleteNode(root->Right(), key)); // end else if
    else {
        // Case 1: No Child
        if (root->Left() == nullptr && root->Right() == nullptr) {
            delete root;
            root = nullptr;
            // Case 2: one child
        } // end if
        else if (root->Left() == nullptr) {
            PictureNode *temp = root;
            root = root->Right();
            delete temp;
        } // end else if
        else if (root->Right() == nullptr) {
            PictureNode *temp = root;
            root = root->Left();
            delete temp;
        } // end else if
        else {
            PictureNode *temp = min(root->Right());
            root->setKey(temp->Key());
            root->setRight(deleteNode(root->Right(), temp->Key()));
        } // end else
    } // end else
    return root;
} // end deleteNode

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
PictureNode* PictureBST::min(PictureNode* node)
{
    PictureNode* tempNode = node;
    if (node == nullptr)
        tempNode = nullptr; // end if
    else if (node->Left())
    {
        tempNode = min(node->Left());
    } // end else if
    else
        tempNode = node; // end else
    
    return tempNode;
} // end min

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
PictureNode* PictureBST::max(PictureNode* node)
{
    PictureNode * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr; // end if
    else if (node->Right())
        tempNode = max(node->Right()); // end else if
    else
        tempNode = node; // end else
    
    return tempNode;
} // end max

// creates new PictureNode and initializes it
PictureNode* PictureBST::makeNode(string _key, PictureRecord aRecord, PictureNode* parent){
    PictureNode* newPictureNode = new PictureNode;
    
    newPictureNode->setRecord(aRecord);
    newPictureNode->setKey(_key);
    newPictureNode->setLeft(nullptr);
    newPictureNode->setRight(nullptr);
    newPictureNode->setParent(nullptr);
    
    return newPictureNode;
} // end makeNode
