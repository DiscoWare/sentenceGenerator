#include "stdafx.h"
#include <random>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Dictionary.h"


using namespace std;



/*
Author: Steven Steele
Date: February 19, 2018

Assignment: Lab_02
*/


// Constructor
// Takes the names of the files to get the words from
Dictionary::Dictionary(std::string nounfile, std::string verbfile, std::string adverbfile, std::string adjfile, std::string prepfile, std::string articlefile) {
	if (!(readNouns(nounfile) && readVerbs(verbfile) && readAdverbs(adverbfile) && readAdjectives(adjfile) && readPrepositions(prepfile) && readVerbs(verbfile) && readArticles(articlefile))) {
		cout << "Dictionary failed to find the word list files" << endl;
	}
}

///////////////////////////////////////
// Utility Functions
///////////////////////////////////

// Returns a random noun
string Dictionary::getNoun() {
	int randIndx = getRandomNumber(0, nouns.size() - 1);
	return nouns[randIndx];
}

// Returns an article appropriate to the proceeding noun
string Dictionary::getProperArticle(char c) {
	int random = getRandomNumber(1, 2);
	if (random == 1)
	{
		return "the";
	}
	else
	{
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		{
			return "an";
		}

		else
			return "a";
	}
}

// Returns a random article
string Dictionary::getArticle() {
	int randIndx = getRandomNumber(0, articles.size() - 1);
	return articles[randIndx];
}

// Returns a random adjective
string  Dictionary::getAdjective() {
	int randIndx = getRandomNumber(0, adjectives.size() - 1);
	return adjectives[randIndx];
}

// Returns a random preposition
string  Dictionary::getPreposition() {
	int randIndx = getRandomNumber(0, prepositions.size() - 1);
	return prepositions[randIndx];
}

// Returns a random adverb
string  Dictionary::getAdverb() {
	int randIndx = getRandomNumber(0, adverbs.size() - 1);
	return adverbs[randIndx];
}

// Returns a random verb
string  Dictionary::getVerb() {
	int randIndx = getRandomNumber(0, verbs.size() - 1);
	return verbs[randIndx];
}

///////////////////////////
// Return Phrase Functions
//////////////////////////

string Dictionary::generateNounPhrase()
{
	int firstRandom = getRandomNumber(1, 2);
	ostringstream result;
	string noun = getNoun();
	int articleRandom = getRandomNumber(1, 2);
	if (articleRandom == 1) { getProperArticle(noun.at(0)); }
	result << getNoun() << " " << noun;

	if (firstRandom == 1)
	{
		int secondRandom = getRandomNumber(1, 3);
		// Prepositional Phrase
		if (secondRandom = 1)
		{
			result << " " << getAdverb() << " " << getPreposition() << " " << generateNounPhrase();
		}
		// Verb Phrase
		else if (secondRandom = 2)
		{
			result << " " << getVerb() << " " << getPreposition() << " " << generateNounPhrase();
		}
		// Adjective
		else
		{
			result << " " << getPreposition() << " " << getAdjective() << " " << generateNounPhrase();
		}
	}
	return result.str();
}

string Dictionary::generateVerbPhrase()
{
	int firstRandom = getRandomNumber(1, 2);
	ostringstream result;
	result << " " << getVerb() << " " << generateNounPhrase();

	if (firstRandom == 1)
	{
		int secondRandom = getRandomNumber(1, 2);
		// Prepositional phrase
		if (secondRandom == 1)
		{
			result << " " << getAdverb() << " " << getPreposition() << " " << generateNounPhrase();
		}
		// Adjective
		else if (secondRandom == 2)
		{
			result << " " << getAdjective() << " " << generateNounPhrase();
		}
		// Prepositional phrase with an Adjective
		else
		{
			result << " " << getPreposition() << " " << getAdjective() << " " << generateNounPhrase();
		}
	}
	return result.str();
}

string Dictionary::generateSentence()
{
	ostringstream resultOSS;
	resultOSS << generateNounPhrase() << generateVerbPhrase() << '.';
	string result = resultOSS.str();
	result.at(0) = toupper(result.at(0));

	return result;

}
///////////////////////////
// Read in files functions
//////////////////////////
bool Dictionary::readNouns(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open noun file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			nouns.push_back(word);
		}
	}

	input.close();
	return true;
}
bool Dictionary::readAdverbs(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open adverb file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			adverbs.push_back(word);
		}
	}

	input.close();
	return true;
}

bool Dictionary::readAdjectives(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open adjective file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			adjectives.push_back(word);
		}
	}

	input.close();
	return true;
}
bool Dictionary::readPrepositions(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open preposition file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			prepositions.push_back(word);
		}
	}

	input.close();
	return true;
}

bool Dictionary::readVerbs(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open verb file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			verbs.push_back(word);
		}
	}

	input.close();
	return true;
}

bool Dictionary::readArticles(string file) {
	ifstream input(file);
	// Failed to open
	if (!input) {
		cout << "Failed to open article file" << endl;
		return false;
	}
	string word;
	while (input >> word) {
		if (word != "") {
			articles.push_back(word);
		}
	}

	input.close();
	return true;
}



/////////////////
// Random number generation
/////////////////////////
int Dictionary::getRandomNumber(int minVal, int maxVal) {
	random_device r;
	default_random_engine eng(r());
	uniform_int_distribution<int> dist(minVal, maxVal);
	return dist(eng);
}

