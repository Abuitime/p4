/*
 * Name: Angelique De Castro
 * Login: ajdecast
 *
 * Filename: boggleutil.h
 * Description: Declarations of supporting classes for the Boggle program
 */
#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include <string>
#include <vector>

using namespace std;

// Misc helper class for BogglePlayer
class Boggleutil
{
friend class BogglePlayer;
private:
  /*
   * This function takes in a lexicon file and saves each parsed word in a
   * vector of strings. This function will help the buildLexicon() function
   * build its data structure for word lookup in the Boggle game.
   *
   * Returns a vector of alphabetized strings consisting of all the words
   * from the lexicon file.
   */
 // vector<string> lexiconVector( FILE * filename);
};





// A class, instances of which are nodes in a BogTree, a binary tree
class BogNode
{
public:
  // these fields of the root save the first letter of the words in the BogTree.
  string L1; // field of root of a BogTree that saves a letter
  string L2; // also saves a letter.

  BogNode* c1; // pointer to children
  BogNode* c2;
  BogNode* p; // pointer to parent

  string word; // saves word form lexicon

  BogNode( string L1, string L2, BogNode* c1, BogNode* c2, BogNode* p,
           string word) :
           L1(L1), L2(L2), c1(c1), c2(c2), word(word) {}

  ~BogNode()
  {
    delete c1; delete c2;
    p = 0;
    c1 = 0;    c2 = 0;
    L1.clear();    L2.clear();
    word.clear();
  }

  /*
   * Successor function to access nodes of the BogTree
   */
  //virtual BogNode* successor() const;
};

class BogTree
{
private:
  
public:
  BogNode* root;

  explicit BogTree() : root(0) {}

  ~BogTree()
  {
    delete root;
  }

 /**
   * Insert string in a BogTree.
   * This insert will compare the string to the root of the BogTree to
   * determine which side of the tree it will be inserted
   */
  virtual void insert(const string str, BogNode* root);

};

#endif
