/*
 * Name: Angelique De Castro
 * Login: ajdecast
 *
 * Filename: boggleutil.cpp
 * Description: Definitions of supporting classes for the Boggle program
 */

#include "boggleutil.h"
#include <string>
#include <vector>
#include <set>
#include <fstream>

using namespace std;


/*
 * This function takes in a lexicon file and saves each parsed word in a
 * vector of strings. This function will help the buildLexicon() function
 * build its data structure for word lookup in the Boggle game.
 *
 * Returns a vector of alphabetized strings consisting of all the words
 * from the lexicon file.
 *
vector<string> Boggleutil::lexiconVector( FILE * filename)
{
  vector<string> lexiconvector;
  ifstream infile(filename->c_str()); // init an ifstream to prase words
//  infile.open( filename , ifstream::in);
  string word;
  int i = 0;
  if( infile.is_open() )
  {
    std::getline(infile, word);
    while(infile.is_open() && infile.good())
    {
      std::getline(infile, word);
      if(word.size() < 1) continue;
      std::transform(word.begin(), word.end(), word.begin(), ::tolower);
      lexiconvector.push_back( word );
      i++;
    }
  }

  // alphabetize vector
  sort( lexiconvector.begin(), lexiconvector.end()  );

  return lexiconvector;
}
*/


/**
 * Insert string in a BogTree.
 * This insert will compare the string to the root of the BogTree to
 * determine which side of the tree it will be inserted
 */
void insert(const string str, BogNode* root)
{
  BogNode* current;
  current = root;

  // compare first letter of string to root's char fields
  if( root->L2 < str ) // e.g. if "b" < "ate", insert left
  {
    if( root->c1 != nullptr ) current = root->c1;
    else root->c1 = new BogNode(NULL,NULL,NULL,NULL,current->c1->p,str);
    return ;
  }
  // e.g. if "ate" < "a" and "b" < "ate", insert right
  else if( str < root->L1 && root->L2 < str )
  {
    if( root->c2 != nullptr ) current = root->c2;
    else root->c2 = new BogNode(NULL,NULL,NULL,NULL,current->c2->p,str);
    return ;
  }
  while( true )
  {
    if( str < current->word )
    {
      if( current->c1 == nullptr)
      {
        // init a new string BogNode
        current->c1 = new BogNode(NULL,NULL,NULL,NULL,current->c1->p,str);
        //current->c1->p = current; // make left child of root
        return ;
      }

      current = current->c1;

    }
    else if( current->word < str )
    {
      if ( current->c1 == nullptr )
      {
        current->c1 = new BogNode(0,0,NULL,NULL,current->c2->p,str);
        // current->right->parent = current;
        return ;
      }

      current = current->c2;

    }

  }

}

/*
virtual BogNode* sucessor() const
{
  BogNode* successor = nullptr;
  const BogNode* currentNode = this;

  if(currentNode == NULL)
    return 0;

  // First need to check if c0 child is the successor 
  if(currentNode->c1 != NULL)
  {
    // Move to c1 
    successor = currentNode->c1;

    // Move to the farthest c2 
    while(successor->c2 != NULL)
    {
      successor=successor->c2;
    }
    return successor;
  }

  if(p == NULL)
    return nullptr;

  // The next node could also be in a parent 
  BogNode *par = currentNode->p;

  // Search for the inorder parent 
  while(par != NULL && currentNode != NULL && par->c1 == currentNode)
  {
    currentNode = par;
    par = par->p;
  }
  return par;
}


}
*/
