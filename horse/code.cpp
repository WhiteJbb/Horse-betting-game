#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

void rand_seed()
{
  int seed = static_cast<int> (time(0));
  srand(seed);
}

int rand_int(int a, int b)
{
  int ret = 0;
  int temp_1 = rand();
  int temp_2 = b - a + 1;
  ret = a + (temp_1 % temp_2);
  return ret;
}

void Sleep(int milliseconds)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


int max(int num1, int num2)
{
  int larger;
  if(num1 >= num2)
  {
    larger = num1;
  }
  else
  {
    larger = num2;
  }
  return larger;
}

int main()
{
  rand_seed();
  while(1)
  {
    int don = 1000;
    std::cout << "===============================" << std::endl;
    std::cout << "Horse Racing Betting Game" << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "소유 금액 : " << don << "원" << std::endl;
    std::cout << "원하는 말에 원하는 만큼 베팅할 수 있습니다." << std::endl;
    std::cout << "말마다 상금이 다릅니다. " << std::endl;
    std::cout << std::endl;
    std::string jin = "***************************************";
    int betting = 0;
    int count = 0;
    int bettingmar = 0;
    int winmar  =  0;
    while(don>=0)
    {
      std::cout << "자신이 가진 돈보다 많은 금액을 베팅하면 종료됩니다." << std::endl;
      std::cout << "괄호 안에 적힌 숫자는 베팅 대비 상금입니다." << std::endl;
      std::cout << "베팅액에 0원을 입력하면 모두 초기화 됩니다." << std::endl;
      std::cout << "============================================" << std::endl;
      std::cout << "1 - 부케팔로스 : 알렉산더 대왕의 명마.             (2배) 등급 : ★★★★★" << std::endl;
      std::cout << "2 - 적토마 : 설명이 따로 필요 없는 명마.           (3배) 등급 : ★★★★" << std::endl;
      std::cout << "3 - 마렝고 : 나폴레옹의 애마.                      (5배) 등급 : ★★★" << std::endl;
      std::cout << "4 - 제주도 조랑말.                                (13배) 등급 : ★★" << std::endl;
      std::cout << "5 - 당나귀.                                       (30배) 등급 : ★" << std::endl;
      std::cout << "=============================================" << std::endl;

      int mar[5] = {0,0,0,0,0};
      int m = 0;
      while(1)
      {
        std::cout << "베팅할 말을 선택하세요(1 ~ 5) : ";
        std::cin >> bettingmar;
        if(bettingmar >= 1 && bettingmar <= 5)
        {
          break;
        }
        else
        {
          std::cout << "베팅할 말이 잘못 선택되었습니다. 다시 입력해주세요." << std::endl;

        } 
      }
      std::cout << "베팅할 금액을 입력해주세요 : ";
      std::cin >> betting;
      std::cout << std::endl;
      if(betting == 0)
      {
        break;
      }
      if(betting > don)
      {
        std::cout << "가진 돈을 초과하여 베팅할 수 없습니다." << std::endl;
        Sleep(2000);
        return 0;
      }
      don = don - betting;
      std::cout << "그럼 경기를 시작하겠습니다." << std::endl;
      std::cout << "=============================================" << std::endl;
      int win;
      while(m < 50)
      {
        Sleep(10);
        system("clear");
        Sleep(10);
        std::cout << m;
        win = rand_int(1,100);
        if(win >= 76)
        {
          mar[0]++;
          m = max(mar[0], m);
        }
        else if(win >= 54)
        {
          mar[1]++;
          m = max(mar[1], m);
        }
        else if(win >= 34)
        {
          mar[2]++;
          m = max(mar[2], m);
        }
        else if(win >= 16)
        {
          mar[3]++;
          m = max(mar[3], m);
        }
        else if(win >= 1)
        {
          mar[4]++;
          m = max(mar[4], m);
        }
        std::string jindo[5];
        int i, j;
        for(i=0;i<5;i++)
        {
          for(j=0;j<mar[i];j++)
          {
            jindo[i] += "*";
            if(mar[i] == m)
            {
              winmar = i + 1;
            }
          }
        }
        std::cout << "게임 현황" << std::endl;
        std::cout << "======================================================" << std::endl;
        std::cout << "1번마 : *" << jindo[0] << std::endl;
        std::cout << "2번마 : *" << jindo[1] << std::endl;
        std::cout << "3번마 : *" << jindo[2] << std::endl;
        std::cout << "4번마 : *" << jindo[3] << std::endl;
        std::cout << "5번마 : *" << jindo[4] << std::endl;
        std::cout << "======================================================" << std::endl;
      }
      if(winmar == bettingmar)
      {
        if(winmar == 1)
        {
          don += 2*betting;
          std::cout << "축하합니다! 부케팔로스가 우승했습니다." << std::endl;
          std::cout << 2*betting << "원의 상금이 적립되어 총 " << don << "원이 되었습니다." << std::endl;
          std::cout << std::endl;
        }
        else if(winmar == 2)
        {
          don += 3*betting;
          std::cout << "축하합니다! 적토마가 우승했습니다." << std::endl;
          std::cout << 3*betting << "원의 상금이 적립되어 총 " << don << "원이 되었습니다." << std::endl;
          std::cout << std::endl;
        }
        else if(winmar == 3)
        {
          don += 5*betting;
          std::cout << "축하합니다! 마렝고가 우승했습니다." << std::endl;
          std::cout << 5*betting << "원의 상금이 적립되어 총 " << don << "원이 되었습니다." << std::endl;
          std::cout << std::endl;
        }
        else if(winmar == 4)
        {
          don += 13*betting;
          std::cout << "축하합니다! 제주도 조랑말이 우승했습니다." << std::endl;
          std::cout << 13*betting << "원의 상금이 적립되어 총 " << don << "원이 되었습니다." << std::endl;
          std::cout << std::endl;
        }
        else if(winmar == 5)
        {
          don += 30*betting;
          std::cout << "축하합니다! 당나귀가 우승했습니다." << std::endl;
          std::cout << 30*betting << "원의 상금이 적립되어 총 " << don << "원이 되었습니다." << std::endl;
          std::cout << std::endl;
        }
      }
      else
      {
        std::cout << "안타깝지만 베팅한 말이 우승하지 못했습니다." << std::endl;
        std::cout << winmar << "번 말이 우승했습니다." << std::endl;
        std::cout << "베팅금을 잃어 " << don << "원이 되었습니다." << std::endl;
        std::cout << std::endl;
      }
    }
  }
  return 0;
}