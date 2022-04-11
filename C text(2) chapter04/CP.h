#pragma once

int checkH1(int X[], int H1) {
	if (H1 == 0) {
		if (X[2] + X[3] >= 10) return 1;
		else return 0;
	}
	else {
		if (X[2] + X[3] < 10) return 1;
		else return 0;
	}
}

int checkH2(int X[], int H2) {
	if (H2 == 0) {
		if (X[0] + X[1] >= 10) return 1;
		else return 0;
	}
	else {
		if (X[0] + X[1] < 10) return 1;
		else return 0;
	}
}

void make3digits(int X[], int H1, int H2, int H3) {
	int flag = 1;
	int i = 0, j = 0;

	while (flag == 1) {
		srand((unsigned)time(NULL));
		X[1] = rand() % 10;
		X[2] = rand() % 10;
		X[3] = rand() % 10;

		//ğŒ”»’è
		flag = 0;
		for (i = 0; i < 4; i++) {
			do {
				for (j = 0; j < i; j++) {
					if (X[i] == X[j]) {
						flag = 1;
					}
				}
			} while (j < i);
		}
		if (X[1] + X[2] != H3) flag = 1; break;
		if (checkH1(X, H1) != 0) flag = 1; break;
		if (checkH1(X, H2) != 0) flag = 1; break;
	}
}

void make2digits(int X[], int H1, int H2, int H3) {
	int flag = 0;
	int i = 0, j = 0;

	while (flag == 0) {
		srand((unsigned)time(NULL));
		X[1] = rand() % 10;
		X[2] = rand() % 10;

		//ğŒ”»’è
		flag = 1;
		for (i = 0; i < 4; i++) {
			do {
				for (j = 0; j < i; j++) {
					if (X[i] == X[j]) {
						flag = 1;
					}
				}
			} while (j < i);
		}
		if (X[1] + X[2] != H3) flag = 1; break;
		if (checkH1(X, H1) != 0) flag = 1; break;
		if (checkH2(X, H2) != 0) flag = 1; break;
	}
}