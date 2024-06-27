#include <iostream>
 
int main(void)
{
    //Word Capitalization
    int index = 0;
    bool check = 0;
    char* word = new char[1000];
    do
    {
        std::cin.getline(word, 1000);
        for(index = 0; word[index] != '\0'; )
        {
            if(((word[index] >= 'a') && (word[index] <= 'z')) || ((word[index] >= 'A')&&(word[index] <= 'Z')))
            {
                if(word[index+1] == '\0')
                {
                    check = 1;
                }
                index++;            
            }   
            else
            {
                std::cout << word[index] << " not permitted!";
                break;
            }  
        }
        index = 0;
        if((word[index] >= 'a') && (word[index] <= 'z'))
        {
            word[index] = word[index] - 32;
        }
    }
    while(check != 1);
 
    index = 0;
    if((word[index] >= 'a') && (word[index] <= 'z'))
    {
        word[index] = word[index] - 32;
    }
    std::cout << word;
 
    delete[] word;
    return 0;
}
