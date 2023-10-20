#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include "Header.h"

using namespace std;
const int COLUMN_WIDTH = 60;

bool isValidChar(char c)
{
    return isalnum(c);
}

vector<MyString> findPhrases(const vector<string>& words, int num) 
{
    vector<MyString> phrases;
    for (int a = 0; a < words.size() - num + 1; a++)
    {
        string phrase = words[a];
        for (int b = a + 1; b < a + num; b++)
        {
            phrase += " " + words[b];
        }
        auto c = find(phrases.begin(), phrases.end(), MyString(phrase));
        if (c == phrases.end())
        {
            phrases.push_back(MyString(phrase));
        }
        else
        {
            (*c)++;
        }
    }
    return phrases;
}

string remove_nonalphanum(const string& a) // inspired by ChatGPT
{
    string result;
    bool ValidPrevChar = false;


    for (char c : a)
    {
        if (isValidChar(c))
        {
            result += c;
            ValidPrevChar = true;
        }
        else if ((c == '-' || c == '\'') && ValidPrevChar && result.back() != c) 
        {
            result += c;
        }
        else
        {
            ValidPrevChar = false;
        }
    }


    return result;
}

pair<int, int> count_no_wordAndPhrases(const vector<string>& a, const vector<MyString>& b) 
{                                                                                         
    pair<int, int> c = make_pair(a.size(), b.size());
    return c;
}
int main()
{
    string originaltextfile;
    int n;
    cout << "Name of the text file: ";
    cin >> originaltextfile;
    cout << "Number of adjacent words to combine into a phrase (1-5): ";
    cin >> n;
    cout << "Word frequency Filename: ";
    string freqtextfile;
    cin >> freqtextfile;
    ifstream input(originaltextfile);
    if (!input)
    {
        cerr << "Error: could not open file " << originaltextfile << endl;
        return 1;
    }
    vector<string> words;
    string word;
    while (input >> word)
    {
        transform(word.begin(), word.end(), word.begin(), ::toupper); 
        words.push_back(remove_nonalphanum(word));
    }
    vector<MyString> Phrase_with_adjwords = findPhrases(words, n);
    sort(Phrase_with_adjwords.begin(), Phrase_with_adjwords.end(), greater<MyString>()); 
    ofstream output(freqtextfile);
    if (!output)
    {
        cerr << "Error: could not open file " << freqtextfile << endl;
        return 1;
    }
    pair<int, int> WordAndPhraseCount = count_no_wordAndPhrases(words, Phrase_with_adjwords);
    int wordscount = WordAndPhraseCount.first;
    int phrasescount = WordAndPhraseCount.second;
    output << "The file: " << freqtextfile << " contains " << wordscount << " words, and " << phrasescount << " phrases." << endl;
    for (const auto& cleanedwords : Phrase_with_adjwords)
    {
        output << cleanedwords;
    }
    output.close();
    return 0;
}
