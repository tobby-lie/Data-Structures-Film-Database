//Tobby Lie
//CSCI 2421
//Final Project
//October 20, 2017
//ActorBST class implementation

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include "ActorBST.h"

using namespace std;

// Constructor
ActorBST::ActorBST() {
    root = new ActorNode;
} // end ActorBST

// Destructor
ActorBST::~ActorBST() {
    if (root !=nullptr)
        freeNode(root);
} // end ~ActorBST

// Free the node
void ActorBST::freeNode(ActorNode* leaf)
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
void ActorBST::addNode(string key, string year, string award, string winner, string name, string film)
{
    ActorActressRecord aRecord;
    aRecord.setAward(award);
    aRecord.setYear(year);
    aRecord.setWinner(winner);
    aRecord.setName(name);
    aRecord.setFilm(film);

    addNode(key, root, aRecord);
} // end addNode

// Add a node (private)
void ActorBST::addNode(string key, ActorNode* leaf, ActorActressRecord aRecord) {

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

ActorNode* ActorBST::findNode(string key)
{
    return findNode(key, root);
} // end findNode

// Find a node
ActorNode* ActorBST::findNode(string key, ActorNode* node)
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
        } // else
    } // end if
    // if tree is empty
    else{
        return nullptr;
    }
} // end findNode

// printInorder
void ActorBST::printInorder()
{
    printInorder(root);
} // end printInorder

// printInorder (private)
void ActorBST::printInorder(ActorNode* node)
{
    // inOrder is defined as: left, visit, right
    
    // if tree is not empty
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            printInorder(node->Left());
        } // end if
        // "visit"
        // cout << node->Key() << " :key" << endl;
        ActorActressRecord r;
        r = node->Record();
        if(r.getName() != ""){
            cout << "Name: " << r.getName() << endl;
            cout << "Film: " << r.getFilm() << endl;
            cout << "Year: " << r.getYear() << endl;
            cout << "Award: " << r.getAward() << endl;
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

// traverses inorder and adds to vector at each visit
// if target is found
void ActorBST::InorderWriteOutputToVector(vector<ActorActressRecord> &aVector)
{
    InorderWriteOutputToVector(root, aVector);
} // end InorderWriteOutputToVector

void ActorBST::InorderWriteOutputToVector(ActorNode* node,vector<ActorActressRecord> &aVector){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderWriteOutputToVector(node->Left(), aVector);
        } // end if
        
        ActorActressRecord r;
        r = node->Record();

        ActorActressRecord temp;
        temp.setName(r.getName());
        temp.setFilm(r.getFilm());
        temp.setAward(r.getAward());
        temp.setWinner(r.getWinner());
        temp.setYear(r.getYear());
        aVector.emplace_back(temp);
        
        // go right
        if(node->Right() != nullptr){
            InorderWriteOutputToVector(node->Right(), aVector);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end inorderWriteOutputToVector

// traverses inorder and adds to vector at each visit
// if target is found
void ActorBST::InorderSearchName(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchName(root, aVector, target);
} // end InorderSearchName

void ActorBST::InorderSearchName(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchName(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(target == r.getName()) {
        aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchName(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchName

// traverses inorder and adds to vector at each visit
// if target is found
void ActorBST::InorderSearchAward(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchAward(root, aVector, target);
} // end InordersearchAward

void ActorBST::InorderSearchAward(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchAward(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(target == r.getAward()) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchAward(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchAward

// traverses inorder and adds to vector at each visit
// if target is found
void ActorBST::InorderSearchYear(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchYear(root, aVector, target);
} // end InorderSearchYear

void ActorBST::InorderSearchYear(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchYear(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(target == r.getYear()) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchYear(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchYear

// traverses inorder and adds to vector at each visit
// if target is found
void ActorBST::InorderSearchFilm(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchFilm(root, aVector, target);
} // end InorderSearchFilm

void ActorBST::InorderSearchFilm(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchFilm(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(target == r.getFilm()) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchFilm(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchFilm

//  traverses inorder and adds to vector at each visit
// if target is found to be contained
void ActorBST::InorderSearchNamePartial(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchNamePartial(root, aVector, target);
} // end InorderSearchNamePartial

void ActorBST::InorderSearchNamePartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchNamePartial(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(strstr(r.getName().c_str(),target.c_str()) != NULL) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchNamePartial(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchNamePartial

// traverses inorder and adds to vector at each visit
// if target is found to be contained
void ActorBST::InorderSearchAwardPartial(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchAwardPartial(root, aVector, target);
} // end InorderSearchAwardPartial

void ActorBST::InorderSearchAwardPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchAwardPartial(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(strstr(r.getAward().c_str(),target.c_str()) != NULL) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchAwardPartial(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchAwardPartial


// traverses inorder and adds to vector at each visit
// if target is found to be contained
void ActorBST::InorderSearchYearPartial(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchYearPartial(root, aVector, target);
} // end InorderSearchYearPartial

void ActorBST::InorderSearchYearPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchYearPartial(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(strstr(r.getYear().c_str(),target.c_str()) != NULL) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchYearPartial(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchYearPartial

// traverses inorder and adds to vector at each visit
void ActorBST::InorderSearchFilmPartial(vector<ActorActressRecord> &aVector, string target)
{
    InorderSearchFilmPartial(root, aVector, target);
} // end InorderSearchFilmPartial

void ActorBST::InorderSearchFilmPartial(ActorNode* node,vector<ActorActressRecord> &aVector, string target){
    
    if(root != nullptr){
        // go left
        if(node->Left() != nullptr){
            InorderSearchFilmPartial(node->Left(), aVector, target);
        } // end if
        
        // visit
        ActorActressRecord r;
        r = node->Record();
        if(strstr(r.getFilm().c_str(),target.c_str()) != NULL) {
            aVector.push_back(r);
            
        } // end if
        
        // go right
        if(node->Right() != nullptr){
            InorderSearchFilmPartial(node->Right(), aVector, target);
        } // end if
    } // end if
    //if tree is empty
    else{
        cout << "The tree is empty!" << endl;
    } // end else
} // end InorderSearchFilmPartial

void ActorBST::deleteNode(string key)
{

    {
        if (deleteNode(Root(), key) == nullptr)
            setRoot(nullptr);
    } // end if
  
} // end deleteNode

//deleteNode (Private)
ActorNode* ActorBST::deleteNode(ActorNode* root,string key)
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
            ActorNode *temp = root;
            root = root->Right();
            delete temp;
        } // end else if
        else if (root->Right() == nullptr) {
            ActorNode *temp = root;
            root = root->Left();
            delete temp;
        } // end else if
        else {
            ActorNode *temp = min(root->Right());
            root->setKey(temp->Key());
            root->setRight(deleteNode(root->Right(), temp->Key()));
        } //end else
    } // end else
    return root;
} // end else

// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
ActorNode* ActorBST::min(ActorNode* node)
{
    ActorNode* tempNode = node;
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
ActorNode* ActorBST::max(ActorNode* node)
{
    ActorNode * tempNode = node;
    if (node == nullptr)
        tempNode = nullptr; // end if
    else if (node->Right())
        tempNode = max(node->Right()); // end else if
    else
        tempNode = node; // end else
    
    return tempNode;
} // end max

// creates new ActorNode and initializes it
ActorNode* ActorBST::makeNode(string _key, ActorActressRecord aRecord, ActorNode* parent){
    ActorNode* newActorNode = new ActorNode;
    
    newActorNode->setRecord(aRecord);
    newActorNode->setKey(_key);
    newActorNode->setLeft(nullptr);
    newActorNode->setRight(nullptr);
    newActorNode->setParent(nullptr);
    
    return newActorNode;
} // end makeNode
