#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <array>

/*
std::array<double, 12> read_file(std::string file_name) {
	std::string line;
	std::ifstream myfile(file_name);
	std::array<double, 12> avg_array{};
	if (myfile.is_open()) {
		int index = 0;
		while (getline(myfile, line)) {
			//std::cout << line << '\n';
			avg_array[index] = std::stod(line);
			index++;
		}
		myfile.close();
	}
	else {
		std::cout << "Unable to open file.";
	}
	return avg_array;
}
*/

void sales_report(std::array<std::string, 12> months, std::array<float, 12> monthly_averages) {
	//Sales Report
	printf("Monthly sales report for 2022:\n");
	printf("  Month     Sales\n");
	printf("-------------------\n");
	for (int i = 0; i <= 11; i++) {
		printf("%-9s $%.2f\n", months[i].c_str(), monthly_averages[i]);
	}
}

void sales_summary(std::array<std::string, 12> months, std::array<float, 12> monthly_averages) {
	//Sales Summary
	int min_index = 0;
	float min_val = monthly_averages[0];
	int max_index = 0;
	float max_val = monthly_averages[0];
	float total = 0;
	for (int i = 0; i <= 11; i++) {
		if (monthly_averages[i] < min_val) {
			min_index = i;
			min_val = monthly_averages[i];
		}

		if (monthly_averages[i] > max_val) {
			max_index = i;
			max_val = monthly_averages[i];
		}
		total += monthly_averages[i];
	}

	printf("Sales summary:\n");
	printf("Minimum sales: $%.2f (%s)\n", min_val, months[min_index].c_str());
	printf("Maximum sales: $%.2f (%s)\n", max_val, months[max_index].c_str());
	printf("Average sales: $%.2f", total / 12);
}

void moving_average(std::array<std::string, 12> months, std::array<float, 12> monthly_averages) {
	//Six-Month Moving Average Report
	float jan_june_total = 0;
	std::string first_months = "January - June";
	for (int i = 0; i <= 5; i++) {
		jan_june_total += monthly_averages[i];
	}

	float feb_july_total = 0;
	std::string second_months = "February - July";
	for (int i = 1; i <= 6; i++) {
		feb_july_total += monthly_averages[i];
	}

	float mar_aug_total = 0;
	std::string third_months = "March - August";
	for (int i = 2; i <= 7; i++) {
		mar_aug_total += monthly_averages[i];
	}

	float apr_sep_total = 0;
	std::string fourth_months = "April - September";
	for (int i = 3; i <= 8; i++) {
		apr_sep_total += monthly_averages[i];
	}

	float may_oct_total = 0;
	std::string fifth_months = "May - October";
	for (int i = 4; i <= 9; i++) {
		may_oct_total += monthly_averages[i];
	}

	float june_nov_total = 0;
	std::string sixth_months = "June - November";
	for (int i = 5; i <= 10; i++) {
		june_nov_total += monthly_averages[i];
	}

	float july_dec_total = 0;
	std::string seventh_months = "July - December";
	for (int i = 6; i <= 11; i++) {
		july_dec_total += monthly_averages[i];
	}

	printf("Six-Month Moving Average Report:\n");
	printf("%-17s $%.2f\n", first_months.c_str(), jan_june_total / 6);
	printf("%-17s $%.2f\n", second_months.c_str(), feb_july_total / 6);
	printf("%-17s $%.2f\n", third_months.c_str(), mar_aug_total / 6);
	printf("%-17s $%.2f\n", fourth_months.c_str(), apr_sep_total / 6);
	printf("%-17s $%.2f\n", fifth_months.c_str(), may_oct_total / 6);
	printf("%-17s $%.2f\n", sixth_months.c_str(), june_nov_total / 6);
	printf("%-17s $%.2f\n", seventh_months.c_str(), july_dec_total / 6);
}

void highest_to_lowest(std::array<std::string, 12> months, std::array<float, 12> monthly_averages) {
	//Sales report (highest to lowest)

	printf("Sales Report (Highest to Lowest):\n");
	printf("  Month     Sales\n");
	printf("-------------------\n");
	for (int i = 0; i <= 11; i++) {
		float highest_val = 0;
		int highest_index = 0;
		for (int j = 0; j <= 11; j++) {
			if (monthly_averages[j] > highest_val) {
				highest_val = monthly_averages[j];
				highest_index = j;
			}
		}


		printf("%-9s $%.2f\n", months[highest_index].c_str(), monthly_averages[highest_index]);

		monthly_averages[highest_index] = -1;
	}
}

int main() {

	std::array<std::string, 12> months{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	std::array<float, 12> monthly_averages{23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};

	sales_report(months, monthly_averages);
	printf("\n\n");

	sales_summary(months, monthly_averages);
	printf("\n\n");

	moving_average(months, monthly_averages);
	printf("\n\n");

	highest_to_lowest(months, monthly_averages);	

	return 0;
}