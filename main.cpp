#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <functional>
#define input fin
#define slp Sleep(50)

using namespace std;

class Person
{
public:
   string name;
   int session[6] = {0, };
   int posDay[6] = {0, };
   int hopDay;
};

int posNumTimetable[6][6]; // tt
int middleArr[5][5][100];
int avaNum[5][5]; // 가용인원
int main() {
   ifstream fin;
   fin.open("first.txt");

   int personnel; //총 인원 변수
   cout << "사람 총 몇명?" << endl;
   input >> personnel;
   cout << personnel << endl << endl;
   slp;
   Person people[100]; //인원별 클래스 배열 생성

   for(int i = 0; i < personnel; i++) // 인원 수 만큼 반복
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

      cout << "보컬은:v 기타는:g 베이스는:b 신디:s 드럼:d" << endl;

      for(int j = 0; j < parSessionNum; j++) // 가능한 세션의 수 만큼 반복
      {
         char parSession; // 가능한 세션의 종류
         input >> parSession;
         cout << parSession << endl << endl;
         slp;
         switch(parSession) // 세션 스위치
         {
            case 'v':
               people[i].session[1] = 1;
               break;
            case 'g':
               people[i].session[2] = 1;
               break;
            case 'b':
               people[i].session[3] = 1;
               break;
            case 's':
               people[i].session[4] = 1;
               break;
            case 'd':
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

      for(int j = 0; j < parDayNum; j++)
      {
         char parDay;
         input >> parDay;
         cout << parDay << endl << endl;
         slp;
         switch(parDay)
         {
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

   for(int j = 0; j < 10; j++)
   {
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
   for(int j = 0; j < 10; j++)
   {
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
   cout << "*  가능한 세션 목록: v  g  b  s  d    *" << endl;
   slp;
   cout << "*                                     *" << endl;
   slp;
   cout << "***************************************" << endl;
   Sleep(400);
   cout << endl << endl;
   for(int j = 0; j < personnel; j++)
   {
      cout << j << "_____________" << people[j].name << "_______________" << endl
      << endl << "희망 최대 출석일 수: " << people[j].hopDay << endl
      << "출석 가능 요일: " << people[j].posDay[1] << "  "
      << people[j].posDay[2] << "  "  << people[j].posDay[3]
      << "  "  << people[j].posDay[4] << "  "  << people[j].posDay[5]
      << "  " << endl << "가능한 세션 목록: " << people[j].session[1]
      << "  " << people[j].session[2] << "  " << people[j].session[3]
      << "  " << people[j].session[4] << "  " << people[j].session[5]
      << endl << endl;
      slp;
   }
   cout << "__________________________________" << endl;
   char checkNormal;
   cout << endl << endl << "위 결과가 맞으면 Y 틀리면 N 입력: " ;
   cin >> checkNormal;
   if(checkNormal == 'Y' || checkNormal == 'y')
   {
   }
   else if(checkNormal == 'N' || checkNormal == 'n')
   {
      return 0;
   }else return 0;

   for(int i = 0; i < personnel; i++)
   {
      for(int j = 1; j <= 5; j++)
      {
         if(people[i].posDay[j] == 1)
         {
            for(int k = 1; k <= 5; k++)
            {
               if(people[i].session[k] == 1)
               {
                  posNumTimetable[k][j]++;
                  middleArr[k][j][i] = 1;
               }
            }
         }
      }
   }
   cout << endl << endl;
   for(int j = 0; j < 5; j++)
   {
      cout << "##";
      slp;
   }
   cout << "Time";
   slp;
   cout << "table";
   slp;
   for(int j = 0; j < 5; j++)
   {
      cout << "##";
      slp;
   }
   Sleep(400);
   cout << endl;

   char parSes[5] = {'v', 'g', 'b', 's', 'd'};
   string parD[5] = {"월", "화", "수", "목", "금"};
   cout << endl << endl << endl;
   cout << "  |월화수목금" << endl;
   cout << "--+----------" << endl;
   for(int i = 1; i <= 5; i++)
   {
      cout << parSes[i - 1] << " | ";
      for(int j = 1; j <= 5; j++)
      {
         cout << posNumTimetable[i][j] << " ";
      }
      cout << endl;
   }
   //            월 화 수 목 금
   int exDay[5] = {0, 0, 0, 0, 0}; // 검사 제외 요일 설정(제외하고싶으면 1로 설정)

   int minNum[5][5] = {     //팀별 세션 최소인원 설정
   //    월 화 수 목 금
   /*v*/{1, 1, 1, 1, 1},
   /*g*/{1, 1, 1, 1, 1},
   /*b*/{1, 1, 1, 1, 1},
   /*s*/{1, 1, 1, 1, 1},
   /*d*/{1, 1, 1, 1, 1}
   };
   cout << endl;

   int checkTtPos = 1;
   for(int i = 1; i <= 5; i++)
   {
      for(int j = 1; j <= 5; j++)
      {
         if(exDay[j-1] == 0)
         {
            if(posNumTimetable[i][j] == 0)
            {
               cout << parD[j-1] << "요일의 " << parSes[i-1] << "항목에 해당되는 인원이 없음." << endl;
               checkTtPos = 0;
            }
            else if(posNumTimetable[i][j] < minNum[i-1][j-1])
            {
               cout << parD[j-1] << "요일의 " << parSes[i-1] << "항목에 해당되는 인원이 최소인원보다 적음." << endl;
            }
         }
      }
   }
   cout << endl;

   if(checkTtPos == 0)
   {
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

   for(int i = 0; i < 5; i++) // 가용인원
   {
      for(int j = 0; j < 5; j++)
      {
         avaNum[i][j] = posNumTimetable[i-1][j-1] - minNum[i][j];
      }
   }

   //int middleArr[5][5][100];
   for(int i = 0; i < personnel; i++)
   {

      int sessionPosNum = 0;
      for(int j = 1; j <= 5; j++)
      {
         if(people[i].session[j] == 1)
         {
            sessionPosNum++;
         }
      }

      if(sessionPosNum > 1)
      {
         for(int k = 0; k < 5; k++)
         {
            int parPosNumber = sessionPosNum;
            vector<int> vv;
            for(int j = 0; j < 5; j++)
            {
               if(middleArr[j][k][i] == 1)
               {
                  vv.push_back(avaNum[j][k]);
               }
            }
            sort(vv.begin(), vv.end());
            for(int j = 0; j < 5; j++)
            {
               if(middleArr[j][k][i] == 1)
               {
                  if(vv.back() == avaNum[j][k])
                  {
                     if(parPosNumber > 1)
                     {
                        avaNum[j][k]--;
                        middleArr[j][k][i] = 0;
                        vv.pop_back();
                        parPosNumber--;

               cout << "-------------------------" << endl;
                     }
                  }
               }
            }
         }
      }

      vector<int> v;
      for(int j = 0; j < 5; j++)
      {
         for(int k = 0; k < 5; k++)
         {
            if(middleArr[j][k][i] == 1)
            {
               v.push_back(avaNum[j][k]);
            }
         }
      }
      sort(v.begin(), v.end(), greater<int>());

      for(int m = 0; m < v.size() - people[i].hopDay; m++)
      {   
         for(int j = 0; j < 5; j++)
         {
            for(int k = 0; k < 5; k++)
            {
               if(middleArr[j][k][i] == 1)
               {
                  if(v[m] == avaNum[j][k])
                  {
                     avaNum[j][k]--;
                     middleArr[j][k][i] = 0;
                     goto roopinter;
                  }
               }
            }
         }
         roopinter: cout << i << " " << people[i].hopDay << endl;
      }
   }
}
