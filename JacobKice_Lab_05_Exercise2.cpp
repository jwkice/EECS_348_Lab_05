#include <stdio.h>
#include <string>
#include <iostream>


int main() {

	int score = 2;

	while (score > 1) {
		printf("Enter 0 or 1 to STOP\n");
		printf("Enter the NFL score: ");
		std::cin >> score;
		int number_of_combinations = 0;

		for (int i = 0; i <= score / 8; i++) {
			int total_8 = 8 * i;
			for (int j = 0; j <= score / 7; j++) {
				int total_7 = total_8 + (7 * j);
				for (int k = 0; k <= score / 6; k++) {
					int total_6 = total_7 + (6 * k);
					for (int l = 0; l <= score / 3; l++) {
						int total_3 = total_6 + (3 * l);
						for (int m = 0; m <= score / 2; m++) {
							int total_2 = total_3 + (2 * m);
							if (total_2 == score) {
								printf("%d TD+2pt, %d TD+FG, %d TD, %d 3PT FG, %d Safety\n", i, j, k, l, m);
								number_of_combinations++;
							}
						}
					}
				}
			}
		}
		printf("There are %d combinations of scoring plays that result in a score of %d.\n\n", number_of_combinations, score);
	}
	

	

	return 0;
}