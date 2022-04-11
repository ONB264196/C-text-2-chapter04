#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include"CP.h"
#define _0406

#ifdef _0400
void make4digits(int X[]) {
	int i = 0, j = 0;

	for (i = 0; i < 4; i++) {
		do {
			X[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (X[i] == X[j]) {
					break;
				}
			}
		} while (j < i);
	}
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 4) {
		return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

void judge(const char s[], const int no[], int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

int main(void) {
	int try_no = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	int value[4] = { 0 };
	char buff[10] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　5846のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	make4digits(value);
	/*↓正解の表示↓
	for (int i = 0; i < 4; i++) {
		printf("%d", value[i]);
	}
	putchar('\n');*/

	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 10);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\a4文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, value, &hit, &blow);
		print_result(hit + blow, hit);

	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0401
#define TRY_NUM 12
void make4digits(int X[]) {
	int i = 0, j = 0;

	for (i = 0; i < 4; i++) {
		do {
			X[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (X[i] == X[j]) {
					break;
				}
			}
		} while (j < i);
	}
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 4) {
		return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

void judge(const char s[], const int no[], int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

int main(void) {
	int try_no = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	int value[4] = { 0 };
	char buff[10] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　5846のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	make4digits(value);
	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 10);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\a4文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, value, &hit, &blow);
		print_result(hit + blow, hit);
		if (try_no == TRY_NUM) {
			printf("残念。正解は : ");
			for (int i = 0; i < 4; i++) {
				printf("%d", value[i]);
			}
			return 0;
		}

	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0402
void make4digits(int X[]) {
	int i = 0, j = 0;

	for (i = 0; i < 4; i++) {
		do {
			X[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (X[i] == X[j]) {
					break;
				}
			}
		} while (j < i);
	}
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 4) {
		return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

void judge(const char s[], const int no[], int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

void help(const int no[], int* remain) {
	switch (*remain) {
	case 1: printf("末尾の数字は%dです。\n", no[3]); break;
	case 2: printf("先頭の数字は%dです。\n", no[0]); break;
	case 3: printf("すべての数字の和は%dです。\n", no[0] + no[1] + no[2] + no[3]);
	case 4: 
		if ((no[0] + no[1]) < 10) {
			printf("先頭二つの数字の和は10未満です。\n");
		}
		else {
			printf("先頭二つの数字の和は10以上です。\n");
		}
		break;
	case 5:
		if ((no[2] + no[3]) < 10) {
			printf("末尾二つの数字の和は10未満です。\n");
		}
		else {
			printf("末尾二つの数字の和は10以上です。\n");
		}
		break;
	}
	(*remain)--;
}

int main(void) {
	int try_no = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	int remain = 5;
	int flag = 0;
	int value[4] = { 0 };
	char buff[10] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　5846のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	make4digits(value);

	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 10);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\a4文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, value, &hit, &blow);
		print_result(hit + blow, hit);

		if (hit < 4 && try_no % 4 == 0 && remain > 0) {
			printf("ヒントを使いますか？(残り%d回)\n", remain);
			printf("(0)はい (1)いいえ : ");
			scanf_s("%d", &flag);
			if (flag == 0) {
				help(value, &remain);
			}
		}

	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0403
void make4digits(int X[], int digits) {
	int i = 0, j = 0;

	for (i = 0; i < digits; i++) {
		do {
			X[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (X[i] == X[j]) {
					break;
				}
			}
		} while (j < i);
	}
}

int  check(const char s[], int digits) {
	int i = 0, j = 0;

	if (strlen(s) != digits) {
		return 1;
	}
	for (i = 0; i < digits; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

void judge(const char s[], const int no[], int digits, int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < digits; i++) {
		for (j = 0; j < digits; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos, int digits) {
	if (spos == digits) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

int main(void) {
	int try_no = 0;
	int* value = 0;
	int num = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	char buff[16] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　584632のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	printf("何桁にしますか : ");
	scanf_s("%d", &num);

	value = (int*)calloc(num, sizeof(int));

	make4digits(value, num);

	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 16);

			chk = check(buff, num);

			switch (chk) {
			case 1: printf("\a%d文字で入力してください。", num); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の数字を複数入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, value, num, &hit, &blow);
		print_result(hit + blow, hit, num);

	} while (hit < num);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	free(value);
	return 0;
}
#endif

#ifdef _0404
void make4digits(int X[]) {
	int i = 0;

	for (i = 0; i < 4; i++) {
		X[i] = rand() % 10;
	}
}

int check_duplication(int X[]) {
	int num[10] = { 0 };
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		switch (X[i]) {
		case 0: num[0]++; break;
		case 1: num[1]++; break;
		case 2: num[2]++; break;
		case 3: num[3]++; break;
		case 4: num[4]++; break;
		case 5: num[5]++; break;
		case 6: num[6]++; break;
		case 7: num[7]++; break;
		case 8: num[8]++; break;
		case 9: num[9]++; break;
		}
	}
	for (int j = 0; j < 10; j++) {
		if (num[j] == 4) {
			cnt = 4;
			break;
		}
		if (num[j] == 3) {
			cnt = 3;
			break;
		}
		if (num[j] == 2) {
			cnt += 2;
		}
	}
	return cnt;
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 4) {
		return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
	}

	return 0;
}

void judge(const char s[], const int no[], int* hit, int* blow, int duplication) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
	if (duplication > 0) {
		*blow /= duplication;
		*blow -= (duplication + 1);
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

int main(void) {
	int duplication = 0;
	int try_no = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	int value[4] = { 0 };
	char buff[10] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの数字の並びを当ててください。");
	puts("■　5846のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	make4digits(value);
	duplication = check_duplication(value);
	/*↓正解の表示↓*/
	for (int i = 0; i < 4; i++) {
		printf("%d", value[i]);
	}
	putchar('\n');

	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 10);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\a4文字で入力してください。"); break;
			case 2: puts("\a数字以外の文字を入力しないでください。"); break;
			}
		} while (chk != 0);

		try_no++;
		judge(buff, value, &hit, &blow, duplication);
		print_result(blow + hit, hit);

	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0405

const char* color[] = { "白", "黒", "赤", "青", "黄", "緑", "橙", "茶" };

void make4color(char C[]) {
	int i = 0, j = 0;
	int n[4] = { 0 };

	for (i = 0; i < 4; i++) {
		do {
			n[i] = rand() % 8;
			for (j = 0; j < i; j++) {
				if (n[i] == n[j]) {
					break;
				}
			}
		} while (j < i);
		strcat_s(C, 4 * static_cast<size_t>(i + 1), color[n[i]]);
	}
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 8) {
		return 1;
	}
	
	for (i = 0; i < 4; i++) {
		if (!((s[i * 2] == 0xffffff94 && s[i * 2 + 1] == 0xffffff92) ||
			  (s[i * 2] == 0xffffff8d && s[i * 2 + 1] == 0xffffff95) ||
			  (s[i * 2] == 0xffffff90 && s[i * 2 + 1] == 0xffffffd4) ||
			  (s[i * 2] == 0xffffff90 && s[i * 2 + 1] == 0xffffffc2) ||
			  (s[i * 2] == 0xffffff89 && s[i * 2 + 1] == 0xffffffa9) ||
			  (s[i * 2] == 0xffffff97 && s[i * 2 + 1] == 0xffffffce) ||
			  (s[i * 2] == 0xffffff9e && s[i * 2 + 1] == 0xfffffff2) ||
			  (s[i * 2] == 0xffffff92 && s[i * 2 + 1] == 0xffffff83))) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i * 2] == s[j * 2] && s[i * 2 + 1] == s[j * 2 + 1]) {
				return 3;
			}
		}
	}

	return 0;
}

void judge(const char s[], const char ans[], int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i * 2] == ans[j * 2] && s[i * 2 + 1] == ans[j * 2 + 1]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解です!!");
	}
	else if (snum == 0) {
		printf("	それらの色は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の色が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている色はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
	putchar('\n');
}

int main(void) {
	int try_no = 0;
	int chk = 0;
	int hit = 0;
	int blow = 0;
	char fourcolors[16] = { 0 };
	char buff[17] = { 0 };
	clock_t start = 0, end = 0;

	srand((unsigned)time(NULL));

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの色の並びを当ててください。");
	puts("■　色は白・黒・赤・青・黄・緑・橙・茶の全8種類です。");
	puts("■　同じ色が複数含まれることはありません。");
	puts("■　赤青緑黄のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	make4color(fourcolors);
	/*↓正解の表示↓*/
	//printf("%s", fourcolors);
	//putchar('\n');
	
	start = clock();

	do {
		do {
			printf("入力してください : ");
			scanf_s("%s", buff, 17);

			chk = check(buff);

			switch (chk) {
			case 1: puts("\a4文字で入力してください。"); break;
			case 2: puts("\a規定の色以外の文字を入力しないでください。"); break;
			case 3: puts("\a同一の色を複数入力しないでください。"); break;
			}
		} while (chk != 0);
		
		try_no++;
		judge(buff, fourcolors, &hit, &blow);
		print_result(hit + blow, hit);
		
	} while (hit < 4);

	end = clock();

	printf("%d回かかりました。\n所要時間は%.1f秒でした。\n",
		try_no, (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}
#endif

#ifdef _0406
void make4digits(int X[]) {
	int i = 0, j = 0;
	srand((unsigned)time(NULL));
	for (i = 0; i < 4; i++) {
		do {
			X[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (X[i] == X[j]) {
					break;
				}
			}
		} while (j < i);
	}
}

int  check(const char s[]) {
	int i = 0, j = 0;

	if (strlen(s) != 4) {
		return 1;
	}
	for (i = 0; i < 4; i++) {
		if (!isdigit(s[i])) {
			return 2;
		}
		for (j = 0; j < i; j++) {
			if (s[i] == s[j]) {
				return 3;
			}
		}
	}

	return 0;
}

void type4digits(int X[]) {
	char nums[10] = { 0 };
	int chk = 0;

	do {
		printf("出題する4桁の数を入力してください : ");
		scanf_s("%s", nums, 10);
		chk = check(nums);

		switch (chk) {
		case 1: puts("\a4文字で入力してください。"); break;
		case 2: puts("\a数字以外の文字を入力しないでください。"); break;
		case 3: puts("\a同一の数字を複数入力しないでください。"); break;
		}
	} while (chk != 0);

	for (int i = 0; i < 4; i++) {
		X[i] = nums[i] - '0';
	}
}

void ans4digits(int X[], int H1, int H2, int H3, int H4, int H5) {
	if (H5 > 0) {
		X[0] = H4;
		X[3] = H5;
		do {
			make2digits(X, H1, H2, H3);
		} while (H3 != X[1] + X[2] || checkH2(X, H2) == 1 || checkH1(X, H1) == 1);
	}
	else if (H4 > 0) {
		X[0] = H4;
		do {
			make3digits(X, H1, H2, H3);
		} while (H3 != X[1] + X[2] || checkH2(X, H2) == 1 || checkH1(X, H1) == 1);
	}
	else if (H3 > 0) {
		do {
			make4digits(X);
		} while (H3 != X[1] + X[2] || checkH2(X, H2) == 1 || checkH1(X, H1) == 1);
	}
	else if (H2 >= 0) {
		do {
			make4digits(X);
		} while (checkH1(X, H1) == 1 || checkH2(X, H2) == 1);
	}
	else if (H1 >= 0) {
		do {
			make4digits(X);
		} while (checkH1(X, H1) == 1);
	}
	else {
		make4digits(X);
	}
}

void judge(const char s[], const int no[], int* hit, int* blow) {
	int i = 0, j = 0;

	*hit = *blow = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (s[i] == '0' + no[j]) {
				if (i == j) {
					(*hit)++;
				}
				else {
					(*blow)++;
				}
			}
		}
	}
}

void print_result(int snum, int spos) {
	if (spos == 4) {
		printf("正解!!");
	}
	else if (snum == 0) {
		printf("	それらの数字は全く含まれません。\n");
	}
	else {
		printf("	それらの数字中%d個の数字が含まれます。\n", snum);

		if (spos == 0) {
			printf("	ただし一つもあっている数字はありません。\n");
		}
		else {
			printf("	その中の%d個は位置もあっています。\n", spos);
		}
	}
}

void helpPR(const int no[], int* remain) {
	switch (*remain) {
	case 1: printf("	末尾の数字は%dです。\n", no[3]); break;
	case 2: printf("	先頭の数字は%dです。\n", no[0]); break;
	case 3: printf("	中間2つ数字の和は%dです。\n", no[1] + no[2]); break;
	case 4:
		if ((no[0] + no[1]) < 10) {
			printf("	先頭二つの数字の和は10未満です。\n");
		}
		else {
			printf("	先頭二つの数字の和は10以上です。\n");
		}
		break;
	case 5:
		if ((no[2] + no[3]) < 10) {
			printf("	末尾二つの数字の和は10未満です。\n");
		}
		else {
			printf("	末尾二つの数字の和は10以上です。\n");
		}
		break;
	}
	(*remain)--;
}

void helpCP(const int no[], int* remain, int* h1, int* h2, int* h3, int* h4, int* h5) {
	switch (*remain) {
	case 1:
		printf("	末尾の数字は%dです。\n", no[3]);
		*h5 = no[3];
		break;
	case 2:
		printf("	先頭の数字は%dです。\n", no[0]);
		*h4 = no[0];
		break;
	case 3:
		printf("	中間2つ数字の和は%dです。\n", no[1] + no[2]);
		*h3 = no[1] + no[2];
		break;
	case 4:
		if ((no[0] + no[1]) < 10) {
			printf("	先頭二つの数字の和は10未満です。\n");
			*h2 = 0;
		}
		else {
			printf("	先頭二つの数字の和は10以上です。\n");
			*h2 = 1;
		}
		break;
	case 5:
		if ((no[2] + no[3]) < 10) {
			printf("	末尾二つの数字の和は10未満です。\n");
			*h1 = 0;
		}
		else {
			printf("	末尾二つの数字の和は10以上です。\n");
			*h1 = 1;
		}
		break;
	}
	(*remain)--;
}

int sleep(unsigned long x) {
	clock_t c1 = clock(), c2 = 0;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void) {
	int try_noPR = 0;
	int hitPR = 0;
	int blowPR = 0;
	int remainPR = 5;
	int valuePR[4] = { 0 };
	char buff[10] = { 0 };

	int try_noCP = 0;
	int hitCP = 0;
	int blowCP = 0;
	int remainCP = 5;
	int h1 = -1, h2 = -1, h3 = -1, h4 = -1, h5 = -1;
	int valueCP[4] = { 0 };
	int ansCP[4] = { 0 };
	char ans[4] = { 0 };

	int chk = 0;
	int flag = 0;

	puts("■　マスターマインドをしましょう。");
	puts("■　四つの数字の並びを当ててください。");
	puts("■　同じ数字が複数含まれることはありません。");
	puts("■　5846のように連続して入力してください。");
	puts("■　スペース文字等を入力してはいけません。\n");

	//出題
	make4digits(valueCP);
	type4digits(valuePR);


	while (flag == 0 || flag == 1) {
		//プレイヤーのターン
		if (flag == 0) {
			puts("\n");
			puts("あなたのターンです。");
			//回答入力
			do {
				printf("入力してください : ");
				scanf_s("%s", buff, 10);

				chk = check(buff);

				switch (chk) {
				case 1: puts("\a4文字で入力してください。"); break;
				case 2: puts("\a数字以外の文字を入力しないでください。"); break;
				case 3: puts("\a同一の数字を複数入力しないでください。"); break;
				}
			} while (chk != 0);

			//判定
			judge(buff, valueCP, &hitPR, &blowPR);
			print_result(hitPR + blowPR, hitPR);

			//ヒント(2ターンに1回)
			if (hitPR < 4 && try_noPR % 2 == 0 && remainPR > 0) {
				helpPR(valueCP, &remainPR);
			}

			try_noPR++;
			flag = 1;
			if (hitPR == 4) flag = 2;
		}

		//コンピューターのターン
		else if (flag == 1) {
			puts("\n");
			puts("コンピューターのターンです。");
			sleep(2000);
			//回答生成
			ans4digits(ansCP, h1, h2, h3, h4, h5);

			printf("コンピューターの回答 : ");
			for (int i = 0; i < 4; i++) {
				srand((unsigned)time(NULL));
				sleep((rand() % 8) * 120);
				printf("%d", ansCP[i]);
				ans[i] = ansCP[i] + '0';
			}
			putchar('\n');
			sleep(750);

			//判定
			judge(ans, valuePR, &hitCP, &blowCP);
			print_result(hitCP + blowCP, hitCP);

			//ヒント(2ターンに1回)
			if (hitCP < 2 && try_noCP % 2 == 0 && remainCP > 0) {
				helpCP(valuePR, &remainCP, &h1, &h2, &h3, &h4, &h5);
			}

			try_noCP++;
			flag = 0;
			if (hitPR == 4) flag = 2;
		}
	}

	if (flag == 0) {
		printf("\n--- コンピューターの勝ちです ---");
	}
	else {
		printf("\n--- あなたの勝ちです ---");
	}

	return 0;
}
#endif

#ifdef _0407
int main(void) {
	int no = 0;
	int ans = 0;
	int check = 0;
	int x = 0;
	int N[3] = { 0 };

	do {
		check = 0;
		srand((unsigned)time(NULL));
		ans = rand() % 1000;

		if (ans / 100 > 0) {
			x = 3;
			N[0] = ans / 100;
			N[1] = ans / 10 - N[0] * 10;
			N[2] = ans - (N[0] * 100 + N[1] * 10);
		}
		else if (ans / 10 > 0) {
			x = 2;
			N[0] = ans / 100;
			N[1] = ans / 10 - N[0] * 10;
		}
		else x = 1;

		if (x > 1) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < i; j++) {
					if (N[i] == N[j]) check = 1;
				}
			}
		}
	} while (check == 1);
	
	printf("0～999の整数を当ててください。\n\n");

	do {
		printf("いくつかな : ");
		scanf_s("%d", &no);

		if (ans > no) {
			printf("\aもっと大きいよ\n");
		}
		else if (ans < no) {
			printf("\aもっと小さいよ\n");
		}
	} while (no != ans);

	printf("正解です。");

	return 0;
}
#endif