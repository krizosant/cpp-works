#include <iostream>
#include <string>
#include <vector>

//ТРЯБВА ДА СЕ ПРЕРАБОТИ, ЗАЩОТО ДАВА ГРЕШЕН РЕЗУЛТАТ
int main()
{
  unsigned int n = 0, vecIndex = 0; //number of words
  std::string word;
  std::vector<std::string> vectorOfWords;
  
  std::cout << "Enter number of words: ";
  std::cin >> n;
  
  //zmo0nchild
  
  //цикъл за редовете
  for(unsigned int lineIndex = 0; lineIndex < n; lineIndex++)
  {
  std::cin >> word;
  //цикъл за проверка на думите
  for(unsigned int letterIndex = 0; letterIndex < word.size();)
  {
    if((word[letterIndex] >= 'a') && (word[letterIndex] <= 'z'))
    {
      letterIndex++; //на следващата буква
    }
    else if((word[letterIndex] >= 'A') && (word[letterIndex] <= 'Z'))
    {
          word[letterIndex] = word[letterIndex] + 32; //от голяма на малка буква
          letterIndex++;
        }
        else //среща различен символ от дадените
        {
          std::cout << "Invalid input. Enter new word: ";
          std::cin >> word;
          letterIndex = 0;
        }
      }
      vectorOfWords.push_back(word);
      vecIndex++;
    }
   
    //принитраме преработени думи
    vecIndex = 0;
    word.clear();
    do
    {
      word = vectorOfWords[vecIndex];
      if(word.length() < 10)
      {
        std::cout << word << "\n";
      }
      else
      {
        unsigned int number;
        //pepibox
        for(unsigned int letterIndex = 1; letterIndex < word.size(); letterIndex++)
        {
          if(letterIndex + 1 == word.size())
          {
            letterIndex--;
            number = letterIndex;
            break;
          }
        }
        std::cout << word[0] << number << word[word.size() - 1] << "\n";
      }
      vecIndex++;
    }
    while(vecIndex < vectorOfWords.size());
   
    return 0;
}
 
/*
 * Тест 1: 4 думи
 * word
 * localization
 * internationalization
 * pneumonoultramicroscopicsilicovolcanoconiosis
 * Успешен!
 *
 * Тест 2: 1 дума
 * pneumonoultramicroscopicsilicovolcanoconiosis
 * Успешен!
 *
 * Тест 3: 2 думи
 * intErnatIonalizaTion
 * loCalizatION
 * Успешен!
 *
 * Tест 4: 2 думи
 * pepibox
 * smurfbox
 * Успешен!
 *
 * Тест 5: 2 думи
 * PePiBOX
 * SMURFBOX
 * Успешен!
 */
 
//Тест 6: 3 думи
/*
Enter number of words: 3
p3p1box
Invalid input. Enter new word: 7elev3nboxers
Invalid input. Enter new word: dynamozagreb32
Invalid input. Enter new word: chalgoterka45
Invalid input. Enter new word: machkaigrisho1
Invalid input. Enter new word: tupac
pseud1
Invalid input. Enter new word: maniac
turke3
Invalid input. Enter new word: rgreu54
Invalid input. Enter new word: RonalReagan1
Invalid input. Enter new word: RonaldReagan
tupac
maniac
r10n
*/
//Успешен!
 
//Тест 7: 2 думи
/*
Enter number of words: 2
цтж54ъб65.ин67и87н
Invalid input. Enter new word: rc454yvb76.
Invalid input. Enter new word: hhjhfgbfefe.
Invalid input. Enter new word: frhytkyujfewwe[
Invalid input. Enter new word: rehyjjewfrfgbk,]
Invalid input. Enter new word: snoopdogg.
Invalid input. Enter new word: snoopdogg
doggydock
snoopdogg
doggydock
*/
//Успешен!
