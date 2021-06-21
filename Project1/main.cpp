#include <fstream>
#include "templates.h"

using namespace std;

string preProcess(string fileName)
{
	cout << "Cleaning file..." << endl;
	fstream dataFile;
	dataFile.open(fileName);
	if (dataFile.is_open())
	{
		ofstream temporary;
		string cleanFileName = "clean_" + fileName;
		temporary.open(cleanFileName);
		string d;
		while (dataFile >> d)
		{
			for (int i = 0; i <= d.length(); i++)
			{
				if (ispunct(d[i]))
				{
					d.erase(i--, 1);
				}
				else
				{
					d[i] = tolower(d[i]);
				}
			}
			temporary << d << endl;
		}
		temporary.clear();
		temporary.close();

		return cleanFileName;
	}
	else
		return 0;
}

void main()
{
	/*string titleArray[5] = {"frankenstein.txt", "macbeth.txt", "metaphysics.txt", "paradiselost.txt", "robinsoncrusoe.txt"};
	for (int i = 0; i < sizeof(titleArray) / sizeof(titleArray[0]); i++)
	{
		cout << "Current title: " << titleArray[i] << endl;
		fstream dataFile;
		dataFile.open(preProcess(titleArray[i]));
		if (dataFile.is_open())
		{
			BST<string> tree;
			string d;
			while (dataFile>>d)
				tree.addNode(d);
			tree.getDepth();
			tree.saveToFile("save_" + titleArray[i]);
		}
	}*/

	BST<string> tree;
	string titleArray[5] = {"frankenstein.txt", "macbeth.txt", "metaphysics.txt", "paradiselost.txt", "robinsoncrusoe.txt"};
	for (int i = 0; i < sizeof(titleArray) / sizeof(titleArray[0]); i++)
	{
		tree.loadFromFile("save_" + titleArray[i]);
	}
	tree.saveByOccurrence("inCommon.txt", sizeof(titleArray) / sizeof(titleArray[0]));
	// "saveByOccurence" prints only the nodes who occur the specified amount of times.
	// because we loaded the data from save files, only the words that occurred 5 times
	// (the amount of books there are) have occurred in all books.
	tree.clear();
	BST<string> tree2;
	tree2.loadFromFile("inCommon.txt");
	tree2.getDepth();
	tree2.print(0);

	int t;
	cin >> t;
}