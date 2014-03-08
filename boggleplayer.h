/*
 * Name: Angelique De Castro
 * Login: ajdecast
 *
 * Filename: boggleplayer.h
 * Description: Boggleplayer implements the IBogglePlayer class.
 */

#include "iboggleplayer.h"
#include <string>
#include <vector>
#include <set>
#include <algorithm> // for sort()
#include <string> // to use std::string

using namespace std;

// subclass IBogglePlayer
class BogglePlayer : public IBogglePlayer
{
protectd:
  vector<BogNode*> rootvector(13, NULL);

public:
  BogglePlayer(); // constructor
  ~BogglePlayer(); // destructor

  /*
   * This function takes as argument a vector containing the words specifying
   * the official lexicon to be used for the game. Each word in the set will be
   * a string consisting of lowercase letters a-z only.
   *
   * This function must load the words into an efficient data structure that
   * will be used internally as needed by the BogglePlayer.
   * Returns nothings.
   */
  void IBogglePlayer::buildLexicon(const vector<string>& word_list)
  {
    // alphabetize vector of words
    sort( word_list.begin(), word_list.end());

BogTree AB = BogTree(); BogTree CD = BogTree();
BogTree EF = BogTree(); /*BogTree GH = new BogTree(rootGH);
BogTree IJ = new BogTree(rootIJ); BogTree KL = new BogTree(rootKL);
BogTree MN = new BogTree(rootMN); BogTree OP = new BogTree(rootOP);
BogTree QR = new BogTree(rootQR);*/ BogTree ST = BogTree();
/*BogTree UV = new BogTree(rootUV); BogTree WX = new BogTree(rootWX);
BogTree YZ = new BogTree(rootYZ);*/

BogNode *rootAB = new BogNode("a", "b", nullptr, nullptr, nullptr, "");
BogNode *rootCD = new BogNode("c", "d", nullptr, nullptr, nullptr, "");
BogNode *rootEF = new BogNode("e", "f", nullptr, nullptr, nullptr, "");
/*BogNode rootGH = new BogNode("g", "h", nullptr, nullptr, nullptr, NULL);
BogNode rootIJ = new BogNode("i", "j", nullptr, nullptr, nullptr, NULL);
BogNode rootKL = new BogNode("k", "l", nullptr, nullptr, nullptr, NULL);
BogNode rootMN = new BogNode("m", "n", nullptr, nullptr, nullptr, NULL);
BogNode rootOP = new BogNode("o", "p", nullptr, nullptr, nullptr, NULL);
BogNode rootQR = new BogNode("q", "r", nullptr, nullptr, nullptr, NULL);*/
BogNode *rootST = new BogNode("s", "t", nullptr, nullptr, nullptr, "");
/*BogNode rootUV = new BogNode("u", "v", nullptr, nullptr, nullptr, NULL);
BogNode rootWX = new BogNode("w", "x", nullptr, nullptr, nullptr, NULL);
BogNode rootYZ = new BogNode("y", "z", nullptr, nullptr, nullptr, NULL);*/

AB.root = rootAB; CD.root = rootCD; EF.root = rootEF; ST.root = rootST;

//BogNode* ptr;
for( int i = 0; i < word_list.size(); ++i )
{
  // get first character of string in current word_list index
  switch( (word_list[i])[0] )
  {
    case 'a': AB.insert( word_list[i],AB.root ); break;
    case 'b': AB.insert( word_list[i],AB.root ); break;
    case 'f': EF.insert( word_list[i],EF.root ); break;
    case 't': ST.insert( word_list[i],ST.root ); break;
    case 'e': EF.insert( word_list[i],EF.root ); break;
    /*case 'a' || 'b':
      AB.insert(word_list[i]);
      break;
    case 'c' || 'd':
      CD.insert(word_list[i]);
      break;
    case 'e' || 'f':
      EF.insert(word_list[i]);
      break;
    case 'g' || 'h':
      GH.insert(word_list[i]);
      break;
    case 'i' || 'j':
      IJ.insert(word_list[i]);
      break;
    case 'k' || 'l':
      KL.insert(word_list[i]);
      break;
    case 'm' || 'n':
      MN.insert(word_list[i]);
      break;
    case 'o' || 'p':
      OP.insert(word_list[i]);
      break;
    case 'q' || 'r':
      QR.insert(word_list[i]);
      break;
    case 's' || 't':
      ST.insert(word_list[i]);
      break;
    case 'u' || 'v':
      UV.insert(word_list[i]);
      break;
    case 'w' || 'x':
      WX.insert(word_list[i]);
      break;
    case 'y' || 'z':
      YZ.insert(word_list[i]);
      break;*/
    default: // shouldn't happen
      break;
  }
}

    // make rootvector's fields point to roots of BogTrees
    /*rootvector[0] = AB.root; rootvector[2] = CD.root; rootvector[3] = EF.root;
    rootvector[4] = GH.root; rootvector[5] = IJ.root; rootvector[6] = KL.root;
    rootvector[7] = MN.root; rootvector[8] = OP.root; rootvector[9] = QR.root;
    rootvector[10] = ST.root; rootvector[11] = UV.root; rootvector[12] =WX.root;
    rootvector[13] = YZ.root;*/
  }

  /*
   * This function takes as arguments the number of rows and columns in the
   * board, and an array of arrays of strings representing what is shown on the
   * face of dice on a Boggle board. 
   * Board can be of any width and height.
   * Should lend itself well to the search algorithm
   * row x col
   * 
   * Returns nothing
   */
  void IBogglePlayer::setBoard(unsigned int rows, unsigned int cols,
                               string** diceArray)
  {
    
  }

  /*
   * This function takes two arguments: an int specifying a minimum word length,
   * and a pointer to a set of strings.
   *
   * Returns a boolean signifying whether or not the set<string>* words will be
   * set with words that:
   * (1) are of at least the given minimum length, (2) are in the lexicon 
   * specified by the most recent call to buildLexicon(), and (3) can be found 
   * by following an acyclic simple path on the board specified by the most 
   * recent call to setBoard()
   */
  bool IBogglePlayer::getAllValidWords(unsigned int minimum_word_length, 
                                       set<string>* words)
  {
    
  }

  /*
   * This function takes as argument a const string passed by reference, and
   * determines whether it be found in the lexicon specified by the most recent
   * call to buildLexicon().
   *
   * Returns true if the word is in the 
   * lexicon, and returns false if it is not in the lexicon or if buildLexicon()
   * has not yet been called.
   */
  bool IBogglePlayer::isInLexicon(const string& word_to_check)
  {
    
  }

  /*
   * Checks if any words on the current board set by the last function call
   * setBoard() is in the lexicon made by buildLexicon() (which should have been
   * called). This is via an acyclical path on the board.
   *
   * Returns a vector containing the integers specifying the locations of dice
   * that can be used to form the word in the order that spells the word. The
   * integers used to specify the locations are row-major-order indices, that
   * is, if a letter is in row R and column C, the location will be R*Width+C.
   * If is is NOT possible to form the word, or if setBoard() has not yet been
   * called the function returns an empty vector.
   */
  vector<int> IBogglePlayer::isOnBoard(const string& word_to_check)
  {
    
  }

  /*
   * This is a method that will allow you to implement extra functionality, 
   * should you choose to (you may find it very useful for testing). This 
   * function will be called by the GUI application when a choice of "custom", 
   * non-randomly selected board layout is requested. This function should
   * populate the array of arrays referenced by the first argument, and the ints
   * pointed to by the second and third argument, with a Boggle board
   * specification suitable for passing to setBoard(). Note, the first argument,
   * which will contain the array of arrays that represents the board, will not 
   * be allocated for you; you must allocate the memory for it yourself.
   */
  void IBogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows,
                      unsigned int *cols)
  {
    
  }
}
