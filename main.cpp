#include <iostream>

#include <string>

#include <fstream>

#include <windows.h>

#include <vector>

#include <algorithm>

#include <functional>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#define slp Sleep(10)

# define input fin

# define MAX 50

using namespace std;

typedef pair<int, int> p;

void shuffle(char * , int);

class Person {
    public:
        string name;
    int session[6] = {
        0,
    };
    int posDay[6] = {
        0,
    };
    int hopDay;
};

int posNumTimetable[6][6]; // tt
int middleArr[6][6][100];
int sessionAvaNum[5][5]; // 세션 가용인원
int cccweekAvaNum[5][5];
int jjjj[6][6];

int main() {

	bool runDBmaker = false;

	if (runDBmaker) {
		srand((unsigned int)time(NULL));
		int ch = 0;
		char name;
		int name_lenth = 0;
		int sesstion = 0;
		int sesstion_lenth = 0;
		int day = 0;
		int day_lenth = 0;

		char day_arr[5] = {
			'a',
			'b',
			'c',
			'd',
			'e'
		};
		char sesstion_arr[5] = {
			'v',
			'g',
			'b',
			's',
			'd'
		};

		FILE * fp = NULL;
		fp = fopen("first.txt", "w");
		fprintf(fp, "%d\n\n", MAX);

		for (int i = 0; i < MAX; i++) {
			// name
			fprintf(fp, "%c%c\n", (ch++ / 26) + 'a', (ch % 26) + 'a');
			//sesstion
			sesstion_lenth = rand() % 100 + 1;

			if (sesstion_lenth <= 60)
				sesstion = 1;
			else if (60 < sesstion_lenth && sesstion_lenth <= 76)
				sesstion = 2;
			else if (76 < sesstion_lenth && sesstion_lenth <= 92)
				sesstion = 3;
			else if (92 < sesstion_lenth && sesstion_lenth <= 96)
				sesstion = 4;
			else if (96 < sesstion_lenth && sesstion_lenth <= 100)
				sesstion = 5;

			fprintf(fp, "%d\n", sesstion);
			shuffle(sesstion_arr, 5);

			for (int k = 0; k < sesstion; k++) {
				fprintf(fp, "%c ", sesstion_arr[k]);
			}
			fprintf(fp, "\n");

			//day
			day_lenth = rand() % 100 + 1;

			if (day_lenth <= 80)
				day = 1;
			else if (80 < day_lenth && day_lenth <= 96)
				day = 2;
			else if (96 < day_lenth && day_lenth <= 4)
				day = 3;

			shuffle(day_arr, 5);
			fprintf(fp, "%d\n", day);

			for (int k = 0; k < day; k++) {
				fprintf(fp, "%c\n", day_arr[k]);
			}
			fprintf(fp, "%d", (rand() % day + 1) % (rand() + 1));
			fprintf(fp, "\n\n");

		}
		fclose(fp);
	}

	ifstream fin;
	fin.open("first.txt");

	int personnel; //총 인원 변수
	cout << "사람 총 몇명?" << endl;
	input >> personnel;
	cout << personnel << endl << endl;
	slp;
	Person people[100]; //인원별 클래스 배열 생성

	for (int i = 0; i < personnel; i++) // 인원 수 만큼 반복
	{
		string parName; // i 번째 사람의 이름 변수
		cout << i + 1 << "번째 사람의 이름 입력" << endl;
		input >> parName;
		cout << parName << endl << endl;
		slp;
		people[i].name = parName; // i 번째 사람의 이름을 클래스에 저장

		int parSessionNum; // i 번째 사람이 가능한 세션의 수

		cout << people[i].name << "의 가능한 세션은 몇개?" << endl;
		input >> parSessionNum;
		cout << parSessionNum << endl << endl;
		slp;

		cout << "보컬:v 기타:g 베이스:b 신디:s 드럼:d" << endl;

		for (int j = 0; j < parSessionNum; j++) // 가능한 세션의 수 만큼 반복
		{
			char parSession; // 가능한 세션의 종류
			input >> parSession;
			cout << parSession << endl << endl;
			slp;
			switch (parSession) // 세션 스위치
			{
			case 'g':
				people[i].session[1] = 1;
				break;
			case 's':
				people[i].session[2] = 1;
				break;
			case 'b':
				people[i].session[3] = 1;
				break;
			case 'd':
				people[i].session[4] = 1;
				break;
			case 'v':
				people[i].session[5] = 1;
				break;
			}
		}
		int parDayNum; // i번째 사람의 가능한 요일 갯수
		cout << people[i].name << "의 가능한 요일은 몇개?" << endl;
		input >> parDayNum;
		cout << parDayNum << endl << endl;
		slp;
		cout << "월:a   화:b   수:c   목:d   금:e" << endl;

		for (int j = 0; j < parDayNum; j++) {
			char parDay;
			input >> parDay;
			cout << parDay << endl << endl;
			slp;
			switch (parDay) {
			case 'a':
				people[i].posDay[1] = 1;
				break;
			case 'b':
				people[i].posDay[2] = 1;
				break;
			case 'c':
				people[i].posDay[3] = 1;
				break;
			case 'd':
				people[i].posDay[4] = 1;
				break;
			case 'e':
				people[i].posDay[5] = 1;
				break;
			}
		}
		cout << people[i].name << "의 희망 일주일 최대 출석 일 수는 몇회?" << endl;
		input >> people[i].hopDay;
		cout << people[i].hopDay << endl << endl;
		slp;
	}
	fin.close();
	Sleep(300);
	system("cls");

	for (int j = 0; j < 10; j++) {
		cout << "##";
		slp;
	}
	cout << "크";
	slp;
	cout << "롤";
	slp;
	cout << "링";
	slp;
	cout << "결";
	slp;
	cout << "과";
	slp;
	for (int j = 0; j < 10; j++) {
		cout << "##";
		slp;
	}
	cout << endl << endl << endl;

	Sleep(400);
	cout << "*****Format****************************" << endl;
	slp;
	cout << "*                                     *" << endl;
	slp;
	cout << "* ________________이름_______________ *" << endl;
	slp;
	cout << "*                                     *" << endl;
	slp;
	cout << "*  희망 최대 출석 일 수: n            *" << endl;
	slp;
	cout << "*  출석 가능 요일: 월 화 수 목 금     *" << endl;
	slp;
	cout << "*  가능한 세션 목록:  g  s  b  d  v   *" << endl;
	slp;
	cout << "*                                     *" << endl;
	slp;
	cout << "***************************************" << endl;
	Sleep(400);
	cout << endl << endl;
	for (int j = 0; j < personnel; j++) {
		cout << j << "_____________" << people[j].name << "_______________" << endl <<
			endl << "희망 최대 출석일 수: " << people[j].hopDay << endl <<
			"출석 가능 요일: " << people[j].posDay[1] << "  " <<
			people[j].posDay[2] << "  " << people[j].posDay[3] <<
			"  " << people[j].posDay[4] << "  " << people[j].posDay[5] <<
			"  " << endl << "가능한 세션 목록: " << people[j].session[1] <<
			"  " << people[j].session[2] << "  " << people[j].session[3] <<
			"  " << people[j].session[4] << "  " << people[j].session[5] <<
			endl << endl;
		slp;
	}
	cout << "__________________________________" << endl;
	char checkNormal;
	cout << endl << endl << "위 결과가 맞으면 Y 틀리면 N 입력: ";
	cin >> checkNormal;
	if (checkNormal == 'Y' || checkNormal == 'y') {}
	else if (checkNormal == 'N' || checkNormal == 'n') {
		return 0;
	}
	else return 0;

	for (int i = 0; i < personnel; i++) {
		for (int j = 1; j <= 5; j++) {
			if (people[i].posDay[j] == 1) {
				for (int k = 1; k <= 5; k++) {
					if (people[i].session[k] == 1) {
						posNumTimetable[k][j]++; //빈도수
						middleArr[k][j][i] = 1;
					}
				}
			}
		}
	}
	cout << endl << endl;
	for (int j = 0; j < 5; j++) {
		cout << "##";
		slp;
	}
	cout << "Time";
	slp;
	cout << "table";
	slp;
	for (int j = 0; j < 5; j++) {
		cout << "##";
		slp;
	}
	Sleep(400);
	cout << endl;

	char parSes[5] = {
		'g',
		's',
		'b',
		'd',
		'v'
	};
	string parD[5] = {
		"월",
		"화",
		"수",
		"목",
		"금"
	};
	cout << endl << endl << endl;
	cout << "  |  월  화  수  목  금" << endl;
	cout << "--+-------------------------" << endl;
	for (int i = 1; i <= 5; i++) {
		cout << parSes[i - 1] << " | ";
		for (int j = 1; j <= 5; j++) {
			printf("%3d ", posNumTimetable[i][j]);
		}
		cout << endl;
	}
	cout << "--+-------------------------" << endl;
	// 월 화 수 목 금
	int exDay[5] = { 0, 0, 0, 0, 0 }; // 검사 제외 요일 설정(제외하고싶으면 1로 설정)

	int minNum[5][5] = {     //팀별 세션 최소인원 설정
	//     월 화 수 목 금
		/*v*/ {1, 1, 1, 1, 1},
		/*g*/ {2, 2, 2, 2, 2},
		/*b*/ {1, 1, 1, 1, 1},
		/*s*/ {1, 1, 1, 1, 1},
		/*d*/ {2, 2, 2, 2, 2}
	};
	cout << endl;

	int checkTtPos = 1;
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (exDay[j - 1] == 0) {
				if (posNumTimetable[i][j] == 0) {
					cout << parD[j - 1] << "요일의 " << parSes[i - 1] << "항목에 해당되는 인원이 없음." << endl;
					checkTtPos = 0;
				}
				else if (posNumTimetable[i][j] < minNum[i - 1][j - 1]) {
					cout << parD[j - 1] << "요일의 " << parSes[i - 1] << "항목에 해당되는 인원이 최소인원보다 적음." << endl;
				}
			}
		}
	}
	cout << endl;

	if (checkTtPos == 0) {
		cout << "위의 이유로 시간표를 생성할 수 없음." << endl;
		Sleep(1000);
		cout << "3초 후 자동종료..." << endl;
		Sleep(1000);
		cout << "2초 후 자동종료..." << endl;
		Sleep(1000);
		cout << "1초 후 자동종료..." << endl;
		Sleep(1000);
		return 0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < personnel; i++) // AvaNum
	{
		//SessionAvaNum
		for (int j = 1; j <= 5; j++) // 요일
		{
			int sero = 0;
			if (people[i].posDay[j] == 1) {
				for (int k = 1; k <= 5; k++) // 세션
				{
					if (people[i].session[k] == 1) {
						sero++;
					}
				}
				for (int k = 1; k <= 5; k++) // 세션
				{
					if (people[i].session[k] == 1) {
						sessionAvaNum[k - 1][j - 1] += sero;
					}
				}
			}
		}
		
	}

	

	// 최대 출석 가능 일 수를 맞춰서 시간표 생성 


	p pe[100];
	for (int j = 0; j < personnel; j++) {
		pe[j].first = people[j].hopDay;
		pe[j].second = j;
	}
	sort(pe, pe + personnel);

	/*
		for (int j = 0; j < personnel; j++) {
			cout << j << "_____________" << people[pe[j].second].name << "_______________" << endl <<
				endl << "희망 최대 출석일 수: " << people[pe[j].second].hopDay << endl <<
				"출석 가능 요일: " << people[pe[j].second].posDay[1] << "  " <<
				people[pe[j].second].posDay[2] << "  " << people[pe[j].second].posDay[3] <<
				"  " << people[pe[j].second].posDay[4] << "  " << people[pe[j].second].posDay[5] <<
				"  " << endl << "가능한 세션 목록: " << people[pe[j].second].session[1] <<
				"  " << people[pe[j].second].session[2] << "  " << people[pe[j].second].session[3] <<
				"  " << people[pe[j].second].session[4] << "  " << people[pe[j].second].session[5] <<
				endl << endl;
			slp;
		}
	*/

	//세션 처리
	for (int i = 0; i < personnel; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (people[pe[i].second].posDay[j + 1] == 1) // 이거, 안한 날에 세션 체크됨
			{
				vector<int> vrr;
				for (int k = 0; k < 5; k++)
				{
					if (people[pe[i].second].session[k + 1] == 1)
					{
						vrr.push_back(sessionAvaNum[k][j]);
					}
				}
				sort(vrr.begin(), vrr.end());
				int minn = vrr[0];

				for (int k = 0; k < 5; k++)
				{
					if (people[pe[i].second].session[k + 1] == 1) //ㅁㄴㅇㄹ
					{
						if (sessionAvaNum[k][j] == minn)
						{
							middleArr[k + 1][j + 1][pe[i].second] = 2;
							sessionAvaNum[k][j]++;
							goto roofinter;
						}
					}
				}
			roofinter: for (int k = 0; k < 5; k++)
			{
				if (middleArr[k + 1][j + 1][pe[i].second] != 0) //ㅁㄴㅇㄹ
				{
					sessionAvaNum[k][j] -= vrr.size();
					middleArr[k + 1][j + 1][pe[i].second]--;
				}
			}
			}
		}
	}

	int weekAvaNum[5][5] = {  
	//     월 화 수 목 금
		/*v*/ {0, 0, 0, 0, 0},
		/*g*/ {0, 0, 0, 0, 0},
		/*b*/ {0, 0, 0, 0, 0},
		/*s*/ {0, 0, 0, 0, 0},
		/*d*/ {0, 0, 0, 0, 0}
	};

	for (int i = 0; i < personnel; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= 5; k++)
			{
				if(middleArr[j][k][i] == 1) 
				{					
					weekAvaNum[j - 1][k - 1] += people[i].hopDay;
				}
			}
		}
	}
	// WeekAvaNum
	

	int cloneMidleArr[6][6][100];
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			for(int k = 0; k < 99; k++)
			{
				cloneMidleArr[i][j][k] = middleArr[i][j][k];
			}
		}
	}

	int cloneWeekAvaNum[5][5];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			cloneWeekAvaNum[i][j] = weekAvaNum[i][j];
		}
	}

	int kkkk[6][6];
	for(int i = 1; i <= 5; i++)
	{
		for(int j = 1; j <= 5; j++)
		{
			kkkk[i][j] = jjjj[i][j];
		}
	}

	bool isTrue = true;
	
	while(isTrue) 
	{
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				jjjj[i][j] = kkkk[i][j];
			}
		}
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 5; j++)
			{
				for(int k = 0; k < 99; k++)
				{
					middleArr[i][j][k] = cloneMidleArr[i][j][k];
				}
			}
		}
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 5; j++)
			{
				weekAvaNum[i][j] = cccweekAvaNum[i][j];
			}
		}
		// 요일 처리
		for (int i = 0; i < personnel; i++)
		{
			int dummy[6][6] = { 0, };
			vector<int> vrr;
			for (int j = 0; j < 5; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if (middleArr[j + 1][k + 1][pe[i].second] == 1)
					{
						dummy[j][k] = 1;											  
						vrr.push_back(weekAvaNum[j][k]);							  
					}
				}
			}
			sort(vrr.begin(), vrr.end());
			int count = vrr.size();
			for (int f = 0; f < vrr.size(); f++)
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						if (dummy[j][k] == 1)
						{
							if (vrr.back() == weekAvaNum[j][k])
							{
								if (count > people[pe[i].second].hopDay)
								{
									middleArr[j + 1][k + 1][pe[i].second] = 0;
									weekAvaNum[j][k] -= people[pe[i].second].hopDay;
									count--;
									vrr.pop_back();
									dummy[j][k] = 0;
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < personnel; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				for (int k = 1; k <= 5; k++)
				{
					jjjj[j][k] += middleArr[j][k][pe[i].second];
				}
			}
		}
		
		isTrue = false;
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= 5; k++)
			{
				if(jjjj[j][k] == 0)
				{
					if(exDay[k - 1] == 0)
					{
						cccweekAvaNum[j - 1][k - 1]--;
						isTrue = true;
					}
				}
			}
		}
	}

	cout << endl << endl;
	for (int i = 0; i < personnel; i++)
	{
		cout << i << endl;
		for (int j = 1; j <= 5; j++)
		{
			for (int k = 1; k <= 5; k++)
			{
				cout << middleArr[j][k][pe[i].second] << "  ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	//
	cout << endl << endl << endl << endl;

	
	for (int j = 1; j <= 5; j++)
	{
		for (int k = 1; k <= 5; k++)
		{
			cout << jjjj[j][k] << "  ";
		}
		cout << endl;
	}
	cout << endl << "<세션별 가중치 테이블>" << endl;
	cout << "  |  월  화  수  목  금" << endl;
	cout << "--+----------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << parSes[i] << " | ";
		for (int j = 0; j < 5; j++) {
			printf("%3d ", sessionAvaNum[i][j]);
		}
		cout << endl;
	}
	cout << "--+-------------------------" << endl;
	cout << endl << "<요일별 가중치 테이블>" << endl;
	cout << "  |  월  화  수  목  금" << endl;
	cout << "--+----------------------" << endl;
	for (int i = 0; i < 5; i++) {
		cout << parSes[i] << " | ";
		for (int j = 0; j < 5; j++) {
			printf("%3d ", weekAvaNum[i][j]);
		}
		cout << endl;
	}
	cout << "--+-------------------------" << endl;
}

void shuffle(char * arr, int num) {
    int temp;
    int rn;
    for (int i = 0; i < num - 1; i++) {

        rn = rand() % (num - i) + i;
        temp = arr[i];
        arr[i] = arr[rn];
        arr[rn] = temp;
    }
}
