#include <iostream>
#include <fstream>
#include "timer.h"
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinaryTree.cpp"


void readDictionary(std::string fileName, BinaryTree<std::string> *tree);

void readBook(std::string fileName, BinaryTree<std::string> *tree, int *x, int *y, int *z);

std::string cleanWord(std::string word);

int main()
{
    Timer Watch;

    /*BinaryTree<std::string> tree;
    tree.insert("dog");
    tree.insert("cat");
    tree.insert("canine");
    tree.insert("wolf");
    tree.printInOrder();
    //tree.find("wolf");
    tree.remove("dog");
    tree.printInOrder();*/

    int skippedWords=0;
    int foundWords=0;
    int wordsNotFound=0;

    BinaryTree<std::string>tree;
    readDictionary("dict.txt", &tree);
    Watch.Start();
    readBook("book.txt", &tree, &skippedWords, &foundWords, &wordsNotFound);
    Watch.Stop();

    std::cout << "size is " << tree.getSize() << std::endl;
    std::cout << "finished in time: " << Watch.Time() << std::endl;
    std::cout << "There are " << foundWords << " found in the dictionary" << std::endl;
    std::cout << "There are " << wordsNotFound << " NOT found in the dictionary" << std::endl;
    std::cout << "skipped words " << skippedWords << std::endl;

    return 0;
}

void readBook(std::string fileName, BinaryTree<std::string> *tree, int *x, int *y, int *z)
{
    /*NOTE-head and tail references used for recursive approach  
    typedef std::string type;
    Node<type> start = LL->front();
    Node<type> end = LL->last();*/


    std::ifstream file;
    file.open (fileName);
    if (!file.is_open()) return;

    std::string word;
    while (file >> word)
    {
      std::string cleanedWord = cleanWord(word);
      if((cleanedWord[0] >= '0') && (cleanedWord[0] <= '9'))
      {
        (*x)++; //to track any skippedWords
        continue;
      }
      else if(cleanedWord[0] == '\'')
      {
        (*x)++; //to track any skippedWords
        continue;
      }
      else if(cleanedWord.compare("")==0)
      {
        continue;
      }
      else
      {
        if(tree->find(cleanedWord))
        {
          (*y)++;//to track found words
        }
        else {
          (*z)++;//to track words not found
        }
      }
      
    }
    file.close();

}

void readDictionary(std::string fileName, BinaryTree<std::string> *tree)
{
    std::ifstream file;
    file.open (fileName);

    if (!file.is_open()) return;

    std::string word;
    while (file >> word)
    {
      std::string cleanedWord = cleanWord(word);
      tree->insert(cleanedWord);
    }
    file.close();
}

std::string cleanWord(std::string word)
{
  //std::regex upper("[A-Z]");
  std::string temp = "";

  for(int i = 0; i < word.size(); i++)
  {
    if((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= '0' && word[i]<= '9') || (word[i] == '\''))
    {
      temp = temp + word[i];
    }
    else if(word[i] >= 'A' && word[i] <='Z')
    {
      
      char lower = word[i] + 32;//std::tolower(word[i]);
      temp = temp + lower;
    }

  }
  return temp;

}
