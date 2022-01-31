#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int choice, n, lineCounter = 0;
	string line;
	struct product
	{
		int id = 0;
		string name = "";
		int price = 0;
		int quantity = 0;
	}*products;

	cout << "Enter the number of Products";
	cin >> n;
	products = new product[n];

	ifstream productFile;
	productFile.open("products.txt");

	while (getline(productFile, line))
	{
		lineCounter++;
		cout << "\nproduct " << lineCounter << " :";
		string array[4];
		int j = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] != ',')
				array[j] = array[j] + line[i];
			else
			{
				cout << array[j] << ',';
				j++;
			}
			if (i == line.size() - 1)	cout << array[3];
		}
	}
	productFile.close();

	delete[n]products;
}