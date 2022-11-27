#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int NUMMONTHS = 12;
const int MAXROWS = 1000;
const int NAMELEN = 21;

int LoadBudget(double budget[][NUMMONTHS], char names[][NAMELEN], int maxRows, int numMonths);

void CalculateTotals(double budget[][NUMMONTHS], int startRow, int totalsRow);

double SumColumn(const double budget[][NUMMONTHS], int startRow, int endRow, int col);

void PrintReport(const double budget[][NUMMONTHS], int totalsRow, const char names[][NAMELEN]);

int main() {
	double budget[MAXROWS][NUMMONTHS];
	char names[MAXROWS][NAMELEN];
	int numItems;
	int startExpensesIdx = 1;

	numItems = LoadBudget(budget, names, MAXROWS - 1, NUMMONTHS);
	strcpy_s(names[numItems], NAMELEN, "Totals");
	CalculateTotals(budget, startExpensesIdx, numItems);
	PrintReport(budget, numItems, names);

	return 0;
}

int LoadBudget(double budget[][NUMMONTHS], char names[][NAMELEN], int maxRows, int numMonths)
{
	int i = 0;
	ifstream infile("MonthlyExpenses.txt");
	if (!infile)
	{
		cerr << "Error: unable to open file: MonthlyExpenses.txt\n";
		exit(1);
	}
}
