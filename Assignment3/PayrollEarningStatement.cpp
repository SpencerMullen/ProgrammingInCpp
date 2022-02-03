/*
Spencer Mullen
Date: 10/10/2021
Assignment 3 Payroll Earning Statement
*/

#include <iostream>	
#include <string>
#include <time.h> 
#include <iomanip>
#include <fstream>

using namespace std;

int main() {

	// Define employee values
	string employees[5] = {"Mr. A", "Ms. B", "Mrs. C", "Mr. D", "Mrs. E"};
	srand(time(NULL));
	int sales[5];
	int years[5];
	float monthly_sales = 0;
	float monthly_profit = (rand() % 51) * 0.01;
	float bonus[5];
	float commissions[5];
	float salary[5];

	// Generate Random Sales
	int sale = 0;
	for (int i = 0; i < 5; i++) {
		sale = (rand() % 10000 + 1000);
		sales[i] = sale;
		monthly_sales += sale;
		commissions[i] = sale * 0.125;
	}
	monthly_profit *= monthly_sales;

	// Generate Random Years Working and Calculate Bonuses
	int year;
	float bonus_percent = 0.10;
	for (int j = 0; j < 5; j++) {
		year = rand() % 30 + 1;
		years[j] = year;
		if (year > 10) {
			bonus_percent += 0.05;
		} 
		if (year > 20) {
			bonus_percent += 0.05;
		} 
		if (year > 30) {
			bonus_percent += 0.05;
		}
		bonus[j] = monthly_profit * bonus_percent;
		salary[j] = commissions[j] + bonus[j];
		bonus_percent = 0.10;
	}

	// writing to files using ofstream
	ofstream outfile("file1.txt");
	if (!outfile) {
		cout << "Can't write to file file1.txt" << endl;
		return EXIT_FAILURE;
	}

	// Header
	outfile << "MONTHLY STATEMENT\t(OCTOBER 2021)\n";
	outfile << right << setw(82) << "Boston Skating Company\n";
	outfile << right << setw(82) << "Boston, MA\n";
	outfile << right << setw(82) << "Phone: (617)-855-0000\n";
	
	// Monthly Sales / Profit
	outfile << "MONTHLY SALES: " << setprecision(2) << fixed << showpoint << setw(11) << monthly_sales << '\n';
	outfile << "MONTHLY PROFIT: " << setw(10) << setprecision(2) << fixed << showpoint << monthly_profit << '\n';
	outfile << "=================================================================================" << '\n';
	
	// Employee Information Header
	outfile << left << setw(10) << "Name" << setw(13) << "Commission" << setw(13) << "Bonus";
	outfile << setw(13) << "Fed W." << setw(13) << "ST W." << setw(13) << "RT" << setw(7) << "Net Pay" << '\n';
	outfile << "---------------------------------------------------------------------------------" << '\n';

	// Employee Information
	float total_commission = 0, total_bonus = 0, total_fedw = 0, total_stw = 0, total_rt = 0, total_netpay = 0, netpay;

	for (int i = 0; i < 5; i++) {
		// Employee names
		outfile << setw(10) << employees[i];
		// Commissions
		outfile << setw(13) << setprecision(2) << fixed << showpoint << commissions[i];
		total_commission += commissions[i];
		// Bonuses
		outfile << setw(13) << bonus[i];
		total_bonus += bonus[i];
		// Federal Withholding
		outfile << setw(13) << 0.15 * salary[i];
		total_fedw += 0.15 * salary[i];
		// State Withholding
		outfile << setw(13) << 0.05 * salary[i];
		total_stw += 0.15 * salary[i];
		// Retirement Contribution
		outfile << setw(13) << 0.075 * salary[i];
		total_rt += 0.15 * salary[i];
		// Netpay
		netpay = commissions[i] + bonus[i] - (0.15 * salary[i]) - (0.05 * salary[i]) - (0.075 * salary[i]);
		outfile << setw(7) << netpay;
		total_netpay += netpay;
		outfile << endl;
	}

	// Total Information
	outfile << "---------------------------------------------------------------------------------" << '\n';
	outfile << setw(10) << "Total" << setw(13) << total_commission << setw(13) << total_bonus << setw(13) << total_fedw;
	outfile << setw(13) << total_stw << setw(13) << total_rt << setw(7) << total_netpay << '\n';

	outfile << "---------------------------------------------------------------------------------" << '\n';
	outfile << "Net Profit (Profit – Bonuses):\t" << monthly_profit - total_bonus << '\n';
	outfile << "John Doe, Branch Manager" << endl;
}