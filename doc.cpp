#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include "List.cpp"
using namespace std;

int max = 1;
string content;
string readFromFile(const string &filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return "";
    }

    string content;
    string line;
    while (getline(fin, line))
    {
        content += line; // Append line with newline character
    }

    content += " ";

    fin.close();
    // cout << endl
    //      << endl
    //      << content;
    return content;
}


int store_list(string &content, node *&head)
{

    if (content == "")
    {
        cout << "Your File is / are empty !" << endl;
        return 0;
    }
    string word = "";
    int max = 0;
    for (int i = 0; i < content.length(); i++)
    {

        if (content[i] >= 'A' && content[i] <= 'Z')
        {
            content[i] += 32;
            // convert all character to small
        }

        if (content[i] == ' ' or content[i] == '\t' or content[i] == '\n' or content[i] == '.' or content[i] == ',' or content[i] == '?' or content[i] == '!' or content[i] == '\"' or content[i] == '\'' or content[i] == '(' or content[i] == '{' or content[i] == '[' or content[i] == ')' or content[i] == '}' or content[i] == ']')
        {
            if ((word == ",") or (word == ".") or (word == " ") or (word == ";") or (word == "") or (word == "is") or (word == "i") or (word == "a") or (word == "my") or (word == "were") or (word == "has") or (word == "we") or (word == "every") or (word == "an") or (word == "the") or (word == "of") or (word == "from") or (word == "to") or (word == "when") or (word == "will") or (word == "be") or (word == "but") or (word == "in") or (word == "and") or (word == "for") or (word == "you") or (word == "are") or (word == "if") or (word == "while") or (word == "not") or (word == "been") or (word == "other") or (word == "need") or (word == "also") or (word == "it") or (word == "without") or (word == "itself") or (word == "etc") or (word == "which") or (word == "common") or (word == "commonly") or (word == "with") or (word == "like") or (word == "so") or (word == "may") or (word == "as") or (word == "this") or (word == "it") or (word == "or") or (word == "that") or (word == "more") or (word == "any") or (word == "many") or (word == "with") or (word == "some") or (word == "have") or (word == "am") or (word == "their") or (word == "only") or (word == "these") or (word == "on") or (word == "they") or (word == "there") or (word == "was") or (word == "her") or (word == "she") or (word == "upon") or (word == "once") or (word == "at") or (word == "about") or (word == "than") or (word == "our") or (word == "through") or (word == "them") or (word == "then") or (word == "by") or (word == "can") or (word == "s"))
            {
                word = "";
                continue;
            }

            if (word.length() == 1 or word.length() == 0)
            {
                word = "";
                continue;
            }

        start:
            int tmp = head->insert(word);
            max = (max > tmp) ? max : tmp;
            word = "";
            continue;
        }

        if (content[i] == 'e' && content[i + 1] == 's' && content[i + 2] == 's' && !((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z')))
        {
            // Condition 2 - "es" at the end (e.g., houses -> house)
            word += content[i];
            i++;
            word += content[i];
            i++;
            word += content[i];
            i++;
            goto start;
        }

        if (content[i - 1] == content[i] && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 3 - Doubled consonant before "es" (e.g., glasses -> glass)
            word += content[i];
            i++;
            i++;
            goto start;
        }

        if (content[i] == 'v' && content[i + 1] == 'e' && content[i + 2] == 's')
        {
            // Condition 4 - "ves" to "f" or "fe"
            if ((content[i - 1] == 'i') && content[i - 2] != 'r')
            {
                word += "fe";
                i++;
                i++;
                goto start;
            }
            else if ((content[i - 1] == 'l' || content[i - 1] == 'o' || content[i - 1] == 'e' || content[i - 1] == 'a' || content[i - 1] == 'r') && content[i - 2] != 'o')
            {
                word += "f";
                i++;
                i++;
                goto start;
            }
            else
            {
                word += content[i];
                i++;
                word += content[i];
                i++;
                goto start;
            }
        }

        if (content[i] == 'i' && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 5 - "ies" to "y" (e.g., flies -> fly)
            if (content[i - 1] == 'b' || content[i - 1] == 'c' || content[i - 1] == 'd' || content[i - 1] == 'f' || content[i - 1] == 'g' || content[i - 1] == 'l' || content[i - 1] == 'm' || content[i - 1] == 'n' || content[i - 1] == 'p' || content[i - 1] == 's' || content[i - 1] == 't' || content[i - 1] == 'a' || content[i - 1] == 'e' || content[i - 1] == 'i' || content[i - 1] == 'o' || content[i - 1] == 'u')
            {
                word += "y";
                i++;
                i++;
                goto start;
            }
        }

        if ((content[i] == 's' && (!((content[i + 1] >= 'a' && content[i + 1] <= 'z') || (content[i + 1] >= 'A' && content[i + 1] <= 'Z'))) && (content[i - 1] >= 'a' && content[i - 1] <= 'z') && (content[i - 1] == 't' or content[i - 1] == 'y' or content[i - 1] == 'k' or content[i - 1] == 'n' or content[i - 1] == 'd' or content[i - 1] == 'g' or content[i - 1] == 'o' or content[i - 1] == 'l' or content[i - 1] == 'w' or content[i - 1] == 'm' or content[i - 1] == 'e' or content[i - 1] == 'r')))
        {
            goto start;
        }

    
        if (content[i] == '\0')
        {
            break;
        }

        word += content[i];
    }
    return max;
}

