#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int move = 0;
int door[3] = { 0, 0, 0 };
int aware = 0;
int wh_1[12] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int wh_2[12] = { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
int door_time[3] = { 0, 0, 0 };
int where_you_see = 0;			//0일때 가드화면 1일때 감시카메라
int dead = 0;


void face();
void START_ROOM1();
void MAIN_ROOM1();
void START_ROOM2();
void MAIN_ROOM2();
void ROOM1_1();
void ROOM2_1();
void ROOM3_1();
void ROOM4_1();
void ROOM5_1();
void ROOM6_1();
void ROOM7_1();
void ROOM8_1();
void ROOM9_1();
void ROOM1_2();
void ROOM2_2();
void ROOM3_2();
void ROOM4_2();
void ROOM5_2();
void ROOM6_2();
void ROOM7_2();
void ROOM8_2();
void ROOM9_2();
int find_freddy();
int find_elsword();
void move_freddy();
void move_elsword();
void show_guard();
void choice_guard(int a);
void check_guard();
void show_vid();
void vid_mid_yes();
void vid_mid_no();
void vid_left_no();
void vid_right_no();
void vid_left_yes();
void vid_right_yes();
void start_no();
void start_yes();
void room1or2_no();
void room1or2_yes();
void elswordface();


int main()
{

	int choice;
	srand((unsigned)time(NULL));

	printf("48번을 버티면 승리\n프레디는 4번째마다 이동\n프레디가 근처에 오면 소리가 남.\n문은 왼쪽, 오른쪽, 윗문을 아주 적은 횟수만큼 막아둘수있음.\n창을 최대길이로 해두고 시작해주세요\n\n");
	while (1)
	{

		if (where_you_see == 0)
		{
			show_guard();
			scanf_s("%d", &choice);
			check_guard();
			choice_guard(choice);
		}
		else
		{
			show_vid();
		}
		if (move % 4 == 0)
		{
			move_freddy();
			move_elsword();
		}

		if (move >= 47)
		{
			printf(" \n 아침이 밝았습니다.\n\n");
			break;
		}
		if (dead == 1)
		{
			face();
			break;
		}
		else if (dead == 2)
		{
			elswordface();
			break;
		}



		move++;
		if (door[0] == 1){ door_time[0]++; }
		if (door[1] == 1){ door_time[1]++; }
		if (door[2] == 1){ door_time[2]++; }
		printf("문 %d %d %d\n", door_time[0], door_time[1], door_time[2]);
		printf("진행 횟수는 %d\n", move);
	}



	return 0;
}

void face()
{
	printf("@B@B@BUju7rr75@B@Z1uUJJM@BBM@B7i7vYvrr7:qB@BO1jLv777UM@@@BSuJ:rLi8@B@B\n");
	printf("@@B@BqvYi:::Y@O17i:iii:rB@BBM@7:iiirii:,G@SjLLvvii::iivMB@0ULi.ri7@@B@\n");
	printf("@@@BMuuLi7L7O0Jr:.,    .uM@B@BYiiri;ii;iZSY7v77:,.   .,,P@@P5v:v2ik@@B\n");
	printf("B@B@k2Uv,r7SEJr,.rvJ:.  iOP@B@vrriii:i:i1Sjvii.:7uUur  ..OBMkUi:77i@B@\n");
	printf("@B@O25Pvi,:5S7,:X1viPu  :MXO@Br:rYSFYi::J27::.v0YL. :7   i@BOFL::i:P@B\n");
	printf("B@BPUPN7:,iSUr.k1rPqr:. .BFBBu.rNMq00qr,:5vi,.OP7@S  0r .:B@qN7::i:LB@\n");
	printf("@B@2XP0r.,iqkr,uMN@B@BM rOM@0,LOXuuJUXG7 :FL: LB@B@B@B., :@BNqL::::i@@\n");
	printf("B@GuSk0u:::S8L:.7OB@BP  P@BqrPO5vUUUj1X8u .j7:; E@@@J  .:J@@GPrr:iiiN@\n");
	printf("@BEuXUZEr::7@PLi,.:,. L@B2JM8FLLYJLLYjjGZi.iv7, . .   ::rB@O87;i77rrU@\n");
	printf("B@X51uFEUrrrS@OFJviii:v@FvkOq5vLv1jL7vLvYXO1::iLvvrrirrJB@Our:i7Luv7v@\n");
	printf("@BS2Fu15P2Lrr1MZXUuYYLP2u0N5FJ7vYYJvL7vLYL1E8ur:ii7LLvLY5r::ii7JLvY7uB\n");
	printf("B@FF15UUuXFuJL7LY22u2qqZqS1F1L7Luj7LYv7JjJLu2kqPur:::rr:...:i:iLjL7vL@\n");
	printf("@BPS1JLL1F1UuL7r7UqP0XF5F2SFjvjJ1uYJL777LLLL2jU5PN0u7;i,:.::::vYuvriL@\n");
	printf("B@FSUUJLJFFS5jLjXGPXSFuuY1uLLjjL7J157YvrrYYJJjJU5FFqEqi..,:r,:7YYu7iY@\n");
	printf("@@Pu1UjLLuS52L18OPqXS55Y2v77u2U777vuLvujL7LLLLjYYU1uUkML,,:,,:vvjJj7UB\n");
	printf("@@0UF1U2JjujYqZ8PNPk5SUk15Lu21JvvL7jJuLuuLvuvYLY7JU2ju5Ov.::iYvLvLYv1@\n");
	printf("@BMUkk0XSU1108GqPPqSFu2UqEP12LLj11uLjrrr7vv7v7vLvvjLLL22O;:irLY777Jv0B\n");
	printf("B@BkFPNEXqq0qGEOOM8OEEqPSFUj7v7YjUjvri::iLvLvFN0ZBOMMOPFPJ,7Lu1F7YL7B@\n");
	printf("@B@OkPMB@BMMOM@ZG0OMS0@BPqBOE12uL7rii7u588ur0BY,LSi5kG@B@MBB@B@B@Pvk@B\n");
	printf("B@B@MBB@@@@@@@BFkXNBUPBMUSB@BXq@BOSEEi.@BM  q@: :: ,  M@B@B@B@B@B@B@B@\n");
	printf("@B@B@@@B@B@BMB@qqNG8MO8ZGO@@@0ZB@B@@@rrB@B0S@B@OOPUr:v@B@B@B@@@B@B@B@B\n");
	printf("B@@@B@@@BBMBM@B@FqMqB@8OB@B@B@BBM@B@@@B@B@B@B@B@B@OEv@B@O@GMO@B@@@B@@@\n");
	printf("@B@B@B@B@BBMBB@BS1@B@B@BBB@M@B@B@@@B@B@B@B@@@GBB@BUu8B@BGMk8M@@@@B@B@B\n");
	printf("B@B@@@B@@BMMMMB@S1B@OEBBB@@@B@B@@@B@@@B@B@B@BjBME@BBB@BMZM2qM@B@B@@@B@\n");
	printf("@B@B@B@B@MBB@M@Bqj@EUOJ:7rFBOkXNBB@M@@@B: Z7  OB: Fk8B@M8Bqk@B@B@B@B@B\n");
	printf("B@B@B@B@BBM@BBB@N2BFM@ZOGEEMBMOMMOOOO@@@BYLLUMBMk8FSF@M@GBOOB@@@B@@@B@\n");
	printf("@B@B@B@@@MBM@M@@BO@BOYBBM5uUM@MBMB@BMi k@r  qBN  B8O8BBMOONZ@B@B@B@B@@\n");
	printf("B@B@B@B@BMMBMBB@B@8@kYMB@Ou1q@MGXMM@M: @Bq.:M@B,L@u0GOBBM8FO@@B@B@@@B@\n");
	printf("@B@@@B@B@MBB@@@Ou1GB02@B@@@B@B@B@B@B@B@B@B@B@BBB@BMOGGqPBqMB@B@B@B@B@B\n");
	printf("B@B@B@B@B@B@BBuqZXUOG@B@FEBMM@M@BBB@B@B@B@B@G@q5MMBMEMOBBMuOB@B@B@B@B@\n");
	printf("@B@B@@@B@B@BG8jYqOB88B@BSGOZ@BBMBB@B@B@B@M@BM8MU0M@MqOkBB2r:JB@B@B@B@B\n");
	printf("B@B@B@B@@vL@OkMGkFM@B5j@BOq@B@B@B@@@@@B@B@B@BMBBi@B@MZ1@r :L:7M@B@@@B@\n");
	printf("@B@B@@@@v;vEMM@BME@M@,jB@B@@@B@B@B@B@@@B@@@B@B@B.O@BO7ZBv.iLvi:8@B@B@@\n");
	printf("B@B@B@Ov72LY:7B72@BOBkr7B@B@B@@@B@B@B@B@B@B@B@j: M@@Mi,rY:;jvYr;q@@@B@\n");
	printf("@B@B@jruPku2LFSrOB@B@ML L@F7MB@B@B@B@B@B@MYi@@  YBOB@FM@u  LvvjLr7MB@B\n");
	printf("B@@Er::rrvvX1,i@B@EOX0EFY@L  @B..@B@B: MB7  B@rL5vP@B@B@Jii1jvrvvr:kB@\n");
	printf("@BO:,:;iiirFi  B@B@BMENPX0GPiB@: M@B@7.F@k:rvrY1GM@B@B@N  v515qFi:7:XB\n");
	printf("B@ur:7jujSB@7  BB@BMB@@@MGZOMMZGY5Lv;r:irrr2FOBMO@B@B@@0: r27i7@Bi:ii@\n");
	printf("@@kY7vL0Oj5M2;i.:M@8OB@B@B@MO0Z8Oq0E8OBMMM@@M8BMG0@BBri757Y2uL7v@8::7B\n");
	printf("OEk27rL@M57F8OS.  B@B@B@BGO@BBB@B@BBMBMMGESXX0M@@@B@7  .PNuFuu5vBM7rv7\n");
	printf("LrqUvrMBMk7rE@OY. uXMMBBM8E0GGMMMO8EE00qNPqN00NqMBGZjr::2SuLuJSrMErrv,\n\n");

}

void START_ROOM1()
{
	int num1;

	srand((unsigned)time(NULL));

	num1 = rand() % ((3 - 1) + 1) + 0;
	if (num1 == 1)
	{
		//main room 이동
		wh_1[0] = 0;
		wh_1[11] = 1;
	}

}//0번 방임
void START_ROOM2()
{
	int num2;
	srand((unsigned)time(NULL));
	num2 = rand() % ((4 - 1) + 1) + 0;
	if (num2 == 1)
	{
		//main room 이동
		wh_2[0] = 0;
		wh_2[11] = 1;
	}

}//0번 방임

void MAIN_ROOM1()
{
	int num1;

	srand((unsigned)time(NULL));
	num1 = rand() % ((40 - 1) + 1) + 0;
	if (num1 == 1 || num1 == 2 || num1 == 3 || num1 == 4 || num1 == 5)
	{
		//1번방 이동
		wh_1[1] = 1;
		wh_1[11] = 0;

	}
	else if (num1 == 6 || num1 == 7 || num1 == 8 || num1 == 9 || num1 == 10)
	{
		//2번방 이동
		wh_1[2] = 1;
		wh_1[11] = 0;

	}
	else if (num1 == 11 || num1 == 12 || num1 == 13 || num1 == 14 || num1 == 15)
	{
		//3번방 이동
		wh_1[3] = 1;
		wh_1[11] = 0;

	}
	else if (num1 == 16 || num1 == 17 || num1 == 18 || num1 == 19 || num1 == 20)
	{
		//4번방 이동
		wh_1[4] = 1;
		wh_1[11] = 0;

	}
	else if (21 <= num1 && num1 <= 29)
	{
		//5번 방 이동
		wh_1[5] = 1;
		wh_1[11] = 0;

	}
	else if (30 <= num1 && num1 <= 38)
	{
		//6번 방 이동
		wh_1[6] = 1;
		wh_1[11] = 0;
	}
	else
	{
		//9번방 이동
		wh_1[9] = 1;
		wh_1[11] = 0;
		aware = 1;
	}

}//11번 방임
void MAIN_ROOM2()
{
	int num2;

	srand((unsigned)time(NULL));
	num2 = rand() % ((17 - 1) + 1) + 0;
	if (1 <= num2 &&num2 <= 4)
	{
		//1번방 이동
		wh_2[1] = 1;
		wh_2[11] = 0;

	}
	else if (num2 >= 5 && num2 <= 8)
	{
		//2번방 이동
		wh_2[2] = 1;
		wh_2[11] = 0;

	}
	else if (num2 == 9 || num2 == 10)
	{
		//3번방 이동
		wh_2[3] = 1;
		wh_2[11] = 0;

	}
	else if (num2 == 11 || num2 == 12)
	{
		//4번방 이동
		wh_2[4] = 1;
		wh_2[11] = 0;

	}
	else if (num2 == 13 || num2 == 14)
	{
		//5번 방 이동
		wh_2[5] = 1;
		wh_2[11] = 0;

	}
	else if (num2 == 15 || num2 == 16)
	{
		//6번 방 이동
		wh_2[6] = 1;
		wh_2[11] = 0;
	}
	else
	{
		//9번방 이동
		wh_2[9] = 1;
		wh_2[11] = 0;
		aware = 1;
	}

}//11번 방임

void ROOM1_1()
{
	//메인방 이동
	wh_1[11] = 1;
	wh_1[1] = 0;
}

void ROOM2_1()
{
	//메인방 이동
	wh_1[11] = 1;
	wh_1[2] = 0;
}

void ROOM3_1()
{
	//5번방 이동
	wh_1[5] = 1;
	wh_1[3] = 0;
}

void ROOM4_1()
{
	//6번방 이동
	wh_1[6] = 1;
	wh_1[4] = 0;
}

void ROOM5_1()
{
	int num;
	srand((unsigned)time(NULL));
	num = rand() % ((4 - 1) + 1) + 0;

	if (1 <= num && num <= 3)
	{
		//7번방
		wh_1[7] = 1;
		wh_1[5] = 0;
		aware = 1;
	}
	else
	{
		//메인이동
		wh_1[11] = 1;
		wh_1[5] = 0;
	}
}

void ROOM6_1()
{
	int num;
	srand((unsigned)time(NULL));
	num = rand() % ((4 - 1) + 1) + 0;

	if (1 <= num && num <= 3)
	{
		//8번방
		wh_1[8] = 1;
		wh_1[6] = 0;
		aware = 1;
	}
	else
	{
		//메인이동
		wh_1[11] = 1;
		wh_1[6] = 0;
	}
}

void ROOM7_1()
{
	if (door[1] == 1)
	{
		wh_1[11] = 1;
		wh_1[7] = 0;
		aware = 0;
	}
	else
	{

		dead = 1;
	}

}

void ROOM8_1()
{
	if (door[2] == 1)
	{
		wh_1[11] = 1;
		wh_1[8] = 0;
		aware = 0;
	}
	else
	{

		dead = 1;
	}

}

void ROOM9_1()
{
	if (door[0] == 1)
	{
		wh_1[11] = 1;
		wh_1[9] = 0;
		aware = 0;
	}
	else
	{

		dead = 1;
	}
}

void ROOM1_2()
{
	//메인방 이동
	wh_2[11] = 1;
	wh_2[1] = 0;
}

void ROOM2_2()
{
	//메인방 이동
	wh_2[11] = 1;
	wh_2[2] = 0;
}

void ROOM3_2()
{
	//5번방 이동
	wh_2[5] = 1;
	wh_2[3] = 0;
}

void ROOM4_2()
{
	//6번방 이동
	wh_2[6] = 1;
	wh_2[4] = 0;
}

void ROOM5_2()
{
	int num;
	srand((unsigned)time(NULL));
	num = rand() % ((5 - 1) + 1) + 0;

	if (1 <= num && num <= 3)
	{
		//메인이동
		wh_2[11] = 1;
		wh_2[5] = 0;
	}
	else
	{
		//7번방
		wh_2[7] = 1;
		wh_2[5] = 0;
		aware = 1;
	}
}

void ROOM6_2()
{
	int num;
	srand((unsigned)time(NULL));
	num = rand() % ((5 - 1) + 1) + 0;

	if (1 <= num && num <= 3)
	{
		//메인이동
		wh_2[11] = 1;
		wh_2[6] = 0;
	}
	else
	{
		//8번방
		wh_2[8] = 1;
		wh_2[6] = 0;
		aware = 1;
	}
}

void ROOM7_2()
{
	if (door[1] == 1)
	{
		wh_2[11] = 1;
		wh_2[7] = 0;
		aware = 0;
	}
	else
	{

		dead = 2;
	}

}

void ROOM8_2()
{
	if (door[2] == 1)
	{
		wh_2[11] = 1;
		wh_2[8] = 0;
		aware = 0;
	}
	else
	{

		dead = 2;
	}

}

void ROOM9_2()
{
	if (door[0] == 1)
	{
		wh_2[11] = 1;
		wh_2[9] = 0;
		aware = 0;
	}
	else
	{

		dead = 2;
	}
}

int find_freddy()
{
	int i;
	for (i = 0; i < 12; i++)
	{
		if (wh_1[i] == 1)
		{
			return i;
		}
	}
}

int find_elsword()
{
	int i;
	for (i = 0; i < 12; i++)
	{
		if (wh_2[i] == 1)
		{
			return i;
		}
	}
}

void move_freddy()
{
	switch (find_freddy())
	{
	case 0:
		START_ROOM1();
		break;
	case 1:
		ROOM1_1(); break;
	case 2:
		ROOM2_1(); break;
	case 3:
		ROOM3_1(); break;
	case 4:
		ROOM4_1(); break;
	case 5:
		ROOM5_1(); break;
	case 6:
		ROOM6_1(); break;
	case 7:
		ROOM7_1(); break;
	case 8:
		ROOM8_1(); break;
	case 9:
		ROOM9_1(); break;
	case 11:
		MAIN_ROOM1(); break;
	}

}

void move_elsword()
{
	switch (find_elsword())
	{
	case 0:
		START_ROOM2();
		break;
	case 1:
		ROOM1_2(); break;
	case 2:
		ROOM2_2(); break;
	case 3:
		ROOM3_2(); break;
	case 4:
		ROOM4_2(); break;
	case 5:
		ROOM5_2(); break;
	case 6:
		ROOM6_2(); break;
	case 7:
		ROOM7_2(); break;
	case 8:
		ROOM8_2(); break;
	case 9:
		ROOM9_2(); break;
	case 11:
		MAIN_ROOM2(); break;
	}

}

void show_guard()
{
	printf("-------------------------------------------------\n");
	printf("|                    |   %d   |                  |\n", door[0]);
	printf("|                    ----------                 |\n");
	printf("|------                                  -------|\n");
	printf("|  %d  |                                  |  %d   |\n", door[1], door[2]);
	printf("|------                                  -------|\n");
	printf("|                                               |\n");
	printf("-------------------------------------------------\n");
	if (aware == 1)
	{
		printf("\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!근처에 발소리가 들립니다!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n");
	}

	printf(" 1. 왼쪽 문 조작\n 2. 오른쪽 문 조작\n 3. 윗쪽 문 조작\n 4. 감시카메라 조작\n");

}
void check_guard()
{
	if (door_time[0] >= 1)
		door[0] = 0;
	if (door_time[1] >= 5)
		door[1] = 0;
	if (door_time[2] >= 5)
		door[2] = 0;
}

void choice_guard(int a)
{
	if (a == 1)
	{
		if (door[1] == 0)
		{

			if (door_time[1] < 5)
			{
				door[1] = 1;
			}
			else
			{
				door[1] = 0;
			}
		}
		else
		{
			door[1] = 0;
		}
	}

	else if (a == 2)
	{
		if (door[2] == 0)
		{

			if (door_time[2] < 5)
			{
				door[2] = 1;
			}
			else
			{
				door[2] = 0;
			}
		}
		else
		{
			door[2] = 0;
		}
	}
	else if (a == 3)
	{
		if (door[0] == 0)
		{

			if (door_time[0] < 1)
			{
				door[0] = 1;
			}
			else
			{
				door[0] = 0;
			}
		}
		else
		{
			door[0] = 0;
		}
	}
	else
		where_you_see = 1;


}

void show_vid()
{
	int Rnum;
	printf("                        --------                          \n");
	printf("                        | start |                         \n");
	printf("                        --------                          \n");
	printf("                            |                             \n");
	printf("                            |                             \n");
	printf(" ------          ------------------------      -------    \n");
	printf("|  1   | ------- |                      |------|   2  |   \n");
	printf(" ------          |                      |      -------    \n");
	printf("                 |         MAIN         |                 \n");
	printf(" ------          |                      |      -------    \n");
	printf("|  3   | ------- |                      |------|   4  |   \n");
	printf(" ------          ------------------------      -------    \n");
	printf("   |                |        |         |           |      \n");
	printf("   |             -------     |      -------        |      \n");
	printf("   |------------ㅣ  5  ㅣ    |     |  6  |---------|      \n");
	printf("                 -------     |      -------               \n");
	printf("                    |      ------      |                  \n");
	printf("                    |     |   9  |     |                  \n");
	printf("                  -----    ------     -----               \n");
	printf("                 |  7  |      |      |  8  |              \n");
	printf("                  -----       |       -----               \n");
	printf("                    |         |         |                 \n");
	printf("                  -------------------------               \n");
	printf("                  |      Guard Room       |               \n");
	printf("                  -------------------------               \n");

	if (aware == 1)
	{
		printf("\n\n\n\n\n\n\n!!!!!!!!!!!!!!!!!!!!!!!!!근처에 발소리가 들립니다!!!!!!!!!!!!!!!!!!!!!!\n\n\n\n\n\n\n");
	}
	printf("조사할 방 번호를 입력하시오(0은 시작지점, 10은 경비실 메뉴로 돌아가기, 메인은 확인 불가)");
	scanf_s("%d", &Rnum);
	switch (Rnum)
	{
	case 0:
		if (find_freddy() == 0 || find_elsword() == 0)
		{
			start_yes();
		}
		else
		{
			start_no();
		}
		break;
	case 1:
		if (find_freddy() == 1 || find_elsword() == 1)
		{
			room1or2_yes();
		}
		else
		{
			room1or2_no();
		}
		break;
	case 2:
		if (find_freddy() == 2 || find_elsword() == 2)
		{
			room1or2_yes();
		}
		else
		{
			room1or2_no();
		}
		break;
	case 3:
		if (find_freddy() == 3 || find_elsword() == 3)
		{
			vid_left_yes();
		}
		else
		{
			vid_left_no();
		}
		break;
	case 4:
		if (find_freddy() == 4 || find_elsword() == 4)
		{
			vid_right_yes();
		}
		else
		{
			vid_right_no();
		}
		break;
	case 5:
		if (find_freddy() == 5 || find_elsword() == 5)
		{
			vid_left_yes();
		}
		else
		{
			vid_left_no();
		}
		break;
	case 6:
		if (find_freddy() == 6 || find_elsword() == 6)
		{
			vid_right_yes();
		}
		else
		{
			vid_right_no();
		}
		break;
	case 7:
		if (find_freddy() == 7 || find_elsword() == 7)
		{
			vid_left_yes();
		}
		else
		{
			vid_left_no();
		}
		break;
	case 8:
		if (find_freddy() == 8 || find_elsword() == 8)
		{
			vid_right_yes();
		}
		else
		{
			vid_right_no();
		}
		break;
	case 9:
		if (find_freddy() == 9 || find_elsword() == 9)
		{
			vid_mid_yes();
		}
		else
		{
			vid_mid_no();
		}
		break;
	case 10:
		where_you_see = 0; break;
	}
}

void vid_mid_yes()
{
	printf("u7JLJvv7v77777v77rrirrr;riiiiiiiriiiriririrrr;rrrrrr7rrr77vvvvJYuJju2L\n");
	printf("uiiiiiii:::::::::,.,. ..,,.. ................,...,,:,:,:::::::i;irr7ri\n");
	printf("urv7777r7rr;r;r;i:i:::i:::::::::::::::::::::::i:i:iiiiiir;rr7r77v7Lvj7\n");
	printf("Yr77rrr7;riiiiii::::::::::::::,:,:::,:,:::::,::::::::i:ii;ir;rr7r77LL7\n");
	printf("Li7rririi:iii::::::::::,:,,,,,,.,.,,,.,,:,,,,,::::::::::iiiiiirrr;77Lr\n");
	printf("vir7rriiii::::,:::,:,,.,.,.......,.,.,.,...,,,,,,:,:,::::iii:iir;r;77r\n");
	printf("v:7rr;i:i::::,:,,,,,,...........,...........,.,.,.,,::::::i:iiiirirr7i\n");
	printf("7:;rii:i::::,:,,,,.,...............,...........,.,.:,::::::i:i:ii;irri\n");
	printf("v :rii::::::::,,.,... .............,..............,,:.:,::::i:iiiii;7i\n");
	printf("r :ii::::::,:.,...... . . . . ............ ..........,,,,::::i:iiiirri\n");
	printf("7,i:i::::,:,,., ......   . ... . . . .   ....... ..,,:,::::::i : i; 7i\n");
	printf("i,ii::::,,,,.,....          .                 . .......,,:,::::::iir7i\n");
	printf("r.ii:::,,.,., .. . .                              ......,,,,:,::::iir:\n");
	printf("r,:i::, , , , .....                                ......,.,,,:::::iii\n");
	printf("r.i::::, , ......                                    .....,.,,::::iir:\n");
	printf("i,::::, ,.... .                                    ........,.,,::::ii:\n");
	printf(";.:::,,,.....                                         ......,.,,::::;:\n");
	printf("i.::,:.,......                                     . ......., .:,::i:,\n");
	printf(".:::,,....                                            ......,.,,:::::.\n");
	printf(":.::,,.,....                                           . ....,,:,:,::.\n");
	printf("i.:,:,....                                             . ...,.,,:,:::.\n");
	printf(":.::,,....                                              .....,.,,:,::.\n");
	printf("i:,,..... .                                             . ..., ,:::::.\n");
	printf(":,, .... . .                                             ......, .,.:,\n");
	printf("::., .... . .                                           . . .. ......,\n");
	printf(",,, ...... ..                                           . . . . ......\n");
	printf(": , .........                                          ... ... .......\n");
	printf(", ., ....., .. .                                         . ..... .....\n");
	printf(", , ....., , , ..                                           ... .  ...\n");
	printf(". ......., ..                                           ....        ..\n");
	printf(". . . ....... .                   :F:   .               ...         ..\n");
	printf(".  . . .., ..                  LriLvLiiL                  ..      ....\n");
	printf(". .     ....                    :F7rrj7                  ...     .....\n");
	printf(".      .. : ..                  rF7r7vL                   ...    .....\n");
	printf(", . .   ., , ..                  vjvr7                    ..     ....,\n");
	printf(". . . .: , . ...              :r,UvvL:77                . ...   . ....\n");
	printf(", .     ., , .. ..           rMJvuYLuLUBU             . .., ..   . ...\n");
	printf("., , ... ...                 qOPF2u22k20;            . .., ,,.......,,\n");
	printf(", .., ....,::......          :S:N1F5F5U01            ..., ,,,,,,,,::i.\n");
	printf("i.::::::,:::,.....           MMXSqSkSkE@O            ..,,:,:,,,,,::i:,\n");
	printf("r.i:i:::::i::,,,:.           8@vFqXXNZSPr            .,.:::::,::::::i,\n");
	printf("r,iii:::::ii::,:,,           Sq 18NEEMuk2            ::::::::::::::ii:\n");
	printf("r.iii:::::i:i:::::.          B@u@OE PB@L,             ::::i:i:i:iiii7:\n");
	printf("r:iiir:::iii::::::,:            B@Z J@B:            .::i:iiii;irr7rr7i\n");
	printf("v,rrrri:i:;ii::::::.            7Bi  BM             .:i:ii;irirrv777Li\n");
	printf("uiYYv7ri:i;;ii:i:i::.           B@B v@Bu            .:iii;ir;rrvvLLjU7\n");
	printf("k,7;i:i::::::,,.,,,             @B@ : @@v           ..,,::::::i:iir7L:\n\n");
}

void vid_mid_no()
{
	printf("O0Z0ZN0P0XXkXFS2125U2uUjuLLvLvv7777rrr77v77r77vvLvLYuJuu2215SSkSXSPXNX\n");
	printf("GNPqPqXqSS11U1juJJYLLL77rr;rrrii:i:::::::::i:iirirr77vvJYjjuu2UFFS5SSk\n");
	printf("80Z00NEPqSk55U1uUuuYjLL77r7rr;;iiii:::::i:i:iirr7r77LLJYuu2U55SFXSXSPk\n");
	printf("EE0ZN0XPSSFSUUuuJjLLvYvv77rrii:::::::::::::::i:iirr77LLYYuJU255S5XXPPP\n");
	printf("8NZ0ZqqSXFS11uuYJYLvv7vrrii::::::,:,:,:,::::::::iir;r7vvLLjjuU51kSqXqX\n");
	printf("8ZZGNEqqSkF5UUjjLLvv77rrii::::,:,,,,.,.,,:,::::::ii;irr7vLvYJUUF1kkqXq\n");
	printf("OG8EZNNPXSS15UULLv7rr;;::::::,,.,.....,...,,:,::::::iir77vLvjuU1FFkk0P\n");
	printf("8GZ800PPkS5FU2JYvvr7ri::::,,.,.............,.,,:,::::iirr7vYYuu11kkPPq\n");
	printf("MEGEZNNXS55U1UuYL77rri:: : ,............. ......,,::::iirrvLuu21SSXkqP\n");
	printf("GGEGqNXPF522uuYJv7rrii::,, .... .           .....,.::::ii77Jj2UF5kSPPN\n");
	printf("OGGEENNXP15UUjuLv77ii::, ,....                ....:,:::irrvvju22SSPPNX\n");
	printf("GGZGqNqqkS51uuvvrri::,....                       .... ,::irYYuu21kSqPq\n");
	printf("OEG00P0XX55U2Y7rii:,, ...                         ....::::rLJj2151XkNX\n");
	printf("8GEGNENNkk11uJrrii::....                           ....::irLLuu51kkXXq\n");
	printf("OEZNEqqkX1FUUvrii::,, ..                           ...,,::rvLJuuF5PXqX\n");
	printf("OG0ZqNXk55uUjvi;::,                                . ..,::;vvju51kkqqN\n");
	printf("MZGEZqPS5UUuuvrii:,.                                 ..,::r7LYU2FFXPEq\n");
	printf("OOG800kkUUYuYLii::,.                                  .:::ivLuu25XXqqE\n");
	printf("MG8EEPPFFUuYJ7; i:,,                                ....::r7YYUUFFPPE0\n");
	printf("OOG8NNkXSF2uYvii:,.                                 .., :iiLvJuF1kkqNE\n");
	printf("MOMGGqqSS15jj7i::,,                                . ..,:irLYYuUFFPqEE\n");
	printf("MMOOGZqNSFUuL7ii::.                                 ..,:iirJJuuFFkk0E8\n");
	printf("MOOGO0EPP11juv; :::,                                ..::i;7JUu11XX0NZE\n");
	printf("OOOOGGNqkS12uYri::,                                ., ::i7vuu5FXXE0ZZO\n");
	printf("MOO8OZZNqSS21Y7;i::                                 :,::rrLu21kXqqE0OZ\n");
	printf("MMGOZ8EEPX51Uj7ri::                                 :::i;7v2UFFPNZEZZO\n");
	printf("BMM8OG80EXX15Y77ri:                                i :i;77JU55PPE0GGOO\n");
	printf("MMMM8O8ZNNXk5u77ir                                i.iii77LJFFqPEZO8OOM\n");
	printf("BMMOO8OZZqqFFJL7r;;                                .rirrLLu5kkN0GGMOMO\n");
	printf("MBMMOO880EqX1uvL77r.                                rrr7LJuSXNqZZOOMOM\n");
	printf("@MBMMOOGG00kkuLv77v                                .7r7vJY1SqPZEOOMMMM\n");
	printf("BBMBMMOOZZNXS5jJ7LL,                                vv7YJ2FNPN0G8MOBMB\n");
	printf("@MBMMOMOOEEqq2uJLLj                                :2LYj21kqNXEEMMMMBB\n");
	printf("BBMBMBMM88EEPXUuLuu.                               i5Jj51SXZ0ZE8OMMBMB\n");
	printf("@B@MBMMOM8OEZPSUuu5.                               :kuU1kk0Z8E88MMBB@B\n");
	printf("B@BBMBMMMMG8ZEkk1SS. . .                        . .;PFFPXNNO8OOMMBMBBB\n");
	printf("@B@BBM@MBMM8O00XkXN.                             ..iZkXkqqZ8OOMMBMBB@B\n\n");
}

void vid_left_no()
{
	printf("ZXPSk5S212121uUJYLLvLLL77r7r7;;i;iiiii;ii:::i:::iiii;;riri;iiirr77LvY7\n");
	printf("NJUUuuLYvL7v77rrii::::::,,....                          ..  .,,,,:irri\n");
	printf("PLS12uuYL7v77rrr7ii::::,.. .                           .. .,::::::i:i:\n");
	printf("PJ5Suviriiii:i:i::,,., .. ...                     .........:::::::::::\n");
	printf("qYF2Ui77rrri7ir; :::,,,:,......  ...        ..... ,.......:,::::i:::;i\n");
	printf("XY55jrr7;r;ri:ii::,,.,...,,:,,,,.,,, ...........,........,,::::::iirii\n");
	printf("XY1uuirLv7rr;ii:i:i:i:::::i:iiii::,.,,:,,.,,:,,.......:::,,,,,:,::::i:\n");
	printf("SLUuJi;Y77r7r7r7777v77r7rrr;ii::,:,..,.,.,,,,,,..,,,,,,:,,.,,:,::iii::\n");
	printf("OUEPPvYXF51uUjjYJvL7v77r7rrri::,,,:,:, ,::i::::::,:....,:.,..,,.:i;rr:\n");
	printf("EF0G0JuGkk1S2ujjLL7v7v77r7rriii;irrr77,,,,,::::::,::..,::::::::iirrri:\n");
	printf("G2G0Nvu0kFS51uujuJYvL7v7777rr:irv777v7.,:.,:::,:,::,.;7rr7v7r777vvr; :\n");
	printf("GFE0XJjNkX5k15u22uLLvv7vr7rLr.:77v7vvv...:.,:r::::ir..;77ri7rr7vrv7r:,\n");
	printf("M5Z0Pq0XPkPkk111SuL7v7Lv7iirr.: vLvvvJL : r7r;ri :i:7iivJL7vrvLvjv7i:.\n");
	printf("OFZ8XEq0PqqNXS1SSFLL7YYYLvri:.,JYYvLYj,r::i :r: :iiv7.:7vvYJru7ruLr:..\n");
	printf("MXM80EEqE0E0EXXkNSUYJYJLLLvri,:juLYLuu :...,:i:::r:i;i.i77;12rYjuF7;..\n");
	printf("MqOMNGG8ZG0GN0Pqqq55uuLvr7vvi::2UuJuuF:....:: i:..,i::rUvrL17v5SLLr:..\n");
	printf("@0BB8OO8OZGZ8N0qENPFXSX2uLLLL:iu5U1UF1: .:rr777;v.::,:rr7r7vUjYLu2L:,.\n");
	printf("kuXXU1XMG8GOZG0EEZPqXNkSu2uJL7vkXk555X, .iUL7vULi:: . ,..::iirrrrYr:;:\n");
	printf("@0BMO8M8OGOG8G8EGEZNNPqkS21uJvLkqFFFXPr.. :i7irY1; Yu::::,::..,...ijk7\n");
	printf("BZM@ZOMO8MOOGO8OGOZGE0q0PXFXuj7PqPkXkEF7:7710r7Y77uuv:::i, .:..:.7k0Ev\n");
	printf("@0@BOOM8M8MOOOMOMGOOOE8EGqXXSLJNGqPP0Ek7:2vrUuS22Fqu7::::.,ii.,rFFGqP7\n");
	printf("BZB@GMMMOMOMOMOM8OOO8O8OZGNPS1uZZG0Z8Mr7Y5vijkUPSPXPLr;ri,.::::iYNOSuv\n");
	printf("@NBBMMBOOZ8GGEZ0GE8G8GOOM880ZqqGOGOZ8MjL0LLF1vLLFqFkX27rvuJ77:i,7Y17;r\n");
	printf("BGBBMkXBM80EEOGOOMMMOOOMOMOMGGZO8O88GMX5Ek5OLrPN7J1q8OYUUMBM7iv5uUYju7\n");
	printf("@ZBM@2qBBOMOOG8OO8OGGGM8MOMOMOMOMMMOMON52F0NFuOO7rNG8ZMq5OBBu,qBM0PO@8\n");
	printf("@ZM@BSq@OOO8X0qOG8GGNZN88OOMOMMMMMOMMM8NSPkNkGEOXX8GuUX@05kBMLF@MO5O8M\n");
	printf("@E@B@S0BBZ0qPXZ0Z0EEZEOZOOOOMOMMMMMMMMMEZ00qPqqXZGENqr1BZi:JBZqM@@MOB5\n");
	printf("BGB@BSX@MOEEZGq8OOM8PG8GGOOMOMOMMMMBMBMMOMOO0qqqPZkPZN8@GLrJGME5ukZMMB\n");
	printf("@E@B@FXBOGZ8BMBO88O08G0q88BOOOMMBMBMBMBMMMMMMOOZ0E8Z8EOOGk5XBM8uuJqMME\n");
	printf("B8B@@SP@BBMOOBMMMZPZGOMB8OEEGBMMOMMMMBMBMBMBMMMM88ZENEPGZEqEOMZ8ENEMMN\n");
	printf("@E@B@10@@B@@@GMOBO@BMZEXEMBOM8EZMB@B@MBMBB@BBMBMMMM8O8OZO8OGEPPM@G8MB0\n");
	printf("B8B@BquEqXXqFkXPkq1YvEMMMOq0ZMM@BMMMOBMBM@M@BBMBB@BBMMMSOOGOMOE8ENSEMB\n");
	printf("@0@BBB@MBOMMBMGEO8ZEM0XSqqGOM8M8ZEMMMMBMMOMMMMBMBMBMMM@vMMM8MOMOME0qPk\n\n");
}

void vid_right_no()
{
	printf("jrYvL77rri;i;irirrrii:i:::i:::iiiiiiiiii;;rrrrr7LLLLLvJJuu1U1252S1kSqP\n");
	printf("viiri:,,.,.. ..                          ....,,::::::iirr7777LvYLuu2Uu\n");
	printf("r:i:i::::,:,...     .                     .  ..,::::i;rrrr77vvYLuu52Fu\n");
	printf("i:::::::::::..  ......                     ... ..,.,,::::i:iiiiriLuF5u\n");
	printf("7:i:::i::::::.......,......        ...   .......:,.,:::rriri7rrvrrU2Sj\n");
	printf("vi:ii:::::::.,...............,.....,.,.,,:,:.,...,.,,::;i:irir;LrrJ55u\n");
	printf("7:::i:::,,:.,,:::.......,,:.,.,.:,,.,,:iiii:i:::::iii:::iirr77LY;;uu1J\n");
	printf("r::ii:::,:,,,,,:,,,,,,.,.,,,,,.,...,,::::ii;r7r7777v7777r7r7777JirjUUu\n");
	printf("r:rr;::.:...,.:,...,:,::::::i::.:::,:,,:::irrr7r77vvvLJJuj2u11SPLLPq01\n");
	printf("i,irrrii::::::::,..::,:::::::,.,:77r;ri;iiirr7r77777vYLjjUUF1kXZJuqGZk\n");
	printf("r :;rLv7r77L77;r7i.:::,:,i::,.:,,7L777vri:rr77v7v7LvYJujuU5FkSPNJY0EZ5\n");
	printf("i,:;7vrv7rr7i7rvi..r:::::r:,.:...Lv77vv7,,7vrrrvvvvLvU21U51k5XkNYjXE0X\n");
	printf("i.,ivvjvL7777YYvi  i7:i:ir;r7;:  YJvv7Lv,,7;;i7vv7v7LUS212kPPXPP0PPEZS\n");
	printf(":.irLur7urJYL77 : ,7vii::r:i::r..uLLLYYY,.:irvLYLL7LLSkF1kX0qqP0qNX8ZX\n");
	printf(": .,r7FJuY71Uiv7i,i;i:r:::::,...iUuLYLuY:,ir7LLLJJJYUSqSkkENEqEqZN0OMP\n");
	printf(": ..:rLLS5v71vrLUr::i,..:i::....ikUuJuUU::iLv77vLuu55qPqPNNZ0GZ8ZENMO0\n");
	printf(": .,:YUuLYjuL7r7rr,,::.vi777r;:.:S5u12Fj::YLvLu2XkX5PqEP0qGG8Z8GM8OMBE\n");
	printf("::;:rYrrrrii:,..,. ::iYU77LUi. : X5F1SXk77YjuUUFkNXqqEEZ08EOGOGOk52qkU\n");
	printf("L7SJi......:,,:::.iULr2Lri7:: ..7qk5FFqFYvju11SSPP00EEZZ8Z8G88OOMGOBBE\n");
	printf("LvENSr.,. .:.:i:::LjU7rY77NU77:vSEkPkPPP7uUXFXP0P0E8ZO8OG8GOGO8MOOZ@M8\n");
	printf("u70P81Fi..ii..:,::7Uq522Fu2rLu:vkE0XqPZPYYkXXNGZ8GO8O8O8OOOOM8MOMOOB@E\n");
	printf("Jvuk8XLi::::.,ir;rLPPPSPuXLiL1L7vMZE0GZEj5kNqGZO8O8OOOOMOMOMOMOMMM8@BG\n");
	printf("j;iv1L7,i:77uJLrv1PFkq5LLL1FLJ0vUO8EOGOZPqEE88M8OG88O0ZEGEGZGZOOBMMBBZ\n");
	printf("v7JjjUU17iLMB8UUjM8P2LvEkru81PN5XM88OO8OE88MOMOM8OOMMMOOG8EZ08MBSqOBBO\n");
	printf("G8@8X0M@5,1BB85NME8ZqrvOGuS0E125EMMOMOMOMOMOMOM8MGZZOGOO8ZOOMOBBSFBBBZ\n");
	printf("BOO85OM@UYMBF1EBSuuOGkPO0ZXqXqSPGBMMOMMMMMMM8M88NZNZ8888N0kOOOO@kkMBM8\n");
	printf("81BOMB@OP8ML:r8Bu7N0Z8EXPqPq00GGMMMMMMMMMOMOOOOZOEZ0ZEZ0ESqP0GBBqX@@@Z\n");
	printf("BBMMESuFGMELrYO@80EPk0Pqqq08OMOMMBMBMMOMMMOMOOG8GZPOOOOGq8EG0MM@FqB@B8\n");
	printf("ZZMMPJjU8MMk1k8OOZ8EG00EO8MMMMMMBMBMBMMOMOOMM8GqE880OG8OBMBGGZOBSX@B@G\n");
	printf("1EMM0PE8ZM8ZP0GZP0qEG88MMMMBMBM@MBMMOMOMMBZ0EOGBMO8ZXZOMMM8MBBM@SkB@@O\n");
	printf("5GBM8G@MPPEGOGOGOOO8BMBMBMBB@BBMBMBB@MMZZ8MMBO0kZGB@@OMOMO@B@B@BPS@B@8\n");
	printf("BBM0S0Z8ZOMOZOGXMBMBB@BBM@B@M@BBMMMMOMB@OOZE0OMMMNvJ5qkPkkFqSNPEuZB@BO\n");
	printf("GFPq0EMOMOOGMB8v@MMMBMBMBMMMMMMMMMMMM088M8MOEPXkPEMEGG8NGMBMMMBMBBBB@Z\n\n");
}

void vid_left_yes()
{
	printf("X25Sk11UUJJJjLLv77r:i:i::,:::,,,:.,.,.,............,: , :::iiii;irr77vr\n");
	printf("SYL7;rii:ii:::... . .... .                             . ...,.,.,,:::::\n");
	printf("Pu7:j77riiii;:,,:.,::::::,,..........,,,......,,:::,:, ::::::::iiiirr7i\n");
	printf("SUr7Lirrii.ir::.   :::: :,:,,.,.,,:,:,:,:,,.,,:,:,:::,::::::i:i:;ir;77r\n");
	printf("Xjriuv7r7rirr:::::iii:::i:::i:i:i::::,:,:::,:,:::,,,::::::i :iiiiiirr7i\n");
	printf("5uriUYvv7777r7r77vvv77rririiii:i::::::::,:: :,,,:,:,::i:::i:i:i::i;;r;i\n");
	printf("N27;N22UUuuuuuUJJLYvv77rrii::::::::::::::,,,:::,: ,,::::,:,,::,::r;riri\n");
	printf("ZNLvO0kX5515UUjuLYvLLLrrr;iiiiiiiii:,:::: : .,,:::::,,.:,,,:,:,:::iirri\n");
	printf("OqL7OkPkk5F1F2UYjLYLv7v77; iiv77r77Li,,:,:.,,:,:,:::.irr;rr77777vJvr:ri\n");
	printf("8Zv7GqXqkX5F5SUjLYLLv7rrii:ivL7v7vL:: ,, .,.::,.:::..rJ77777v7LLJuYriii\n");
	printf("Gk1jGPXXqFkFXF2YYvv77iiii:,:uLLvvLU : ., .. ...., , .r77rrr7r7r77Y7r::,\n");
	printf("OXqGN0q0PPSkXPjL7v7riiiii:.,uuJuuu2 :           ..   :v;ririrrrr7L7:,..\n");
	printf("MX0ZEq0NNPqkqX2vL7v77iiii:.,1UUriLPi  : .       ..   iv7r7r7r7777u7:.,,\n");
	printf("MN0OZ0EZ0EXqN0S2JY77ri:ii:,:55Uu::rJirLkj7 : ... .. :LrvvLvLLLvLjv:: :,\n");
	printf("@NOOOZ8ZZ0ZNENq5S5UJJriii:, :SSSXGSLuFUkr  ...    .  rLvLYvLvLLYLu7i::.\n");
	printf("OkPGOOZ8G8EGEZNXSk5S5UJJv7::PGk1JL77vuui::.. . .....:: :;r77LLujUFviri,\n");
	printf("kLu5MOOOO8OZ8GZPqSPS5U2uUL7JEu7r7vYYYvv7v7u1v :, .. ... ,,, .::rrjr7ji.\n");
	printf("BOMBOOGO8OG8ZOEGNqkPFS55uUjui;7vYqu7riiiirLuXS  ::,, ..,.,:,., ,,irj2:,\n");
	printf("MPEE88OGOGOG8GOGO0EqqSSFFSk::r7v7::irii:iirLuUv   ,r...,..:i..,:,i:YE;:\n");
	printf("OXkPS00Z0ZN8ZOOO8OZG0EXPNqi:r                 qL, :i, . ..:i::::i::7S;i\n");
	printf("GUXX52kPGEZ088MOO8M8OGOGMj.                     07:ULrri...:.:::irri;;i\n");
	printf("OXXZ0k5kXPXqkq0O8M8MOOOB@7       RT        DS    L:5OUrvkJvv:ri:rir:::i\n");
	printf("BZjvOX2jU1S5kXN088MOMGMM@i      F  F      G  N   j:58Friq8GUi7Y1Lv7riir\n");
	printf("OZLvM80X1PXZEGEZG88MOOOBB;       YY        MM     Nvu17:SMOk7iXMGPuuJv2\n");
	printf("B82YB0G0PSEqPXEZENZEOOMM@J.                         :j0PuPEPvi1@OZ7uUL8\n");
	printf("@B1uMGN0XS2S1kkXqZ0808OMBOi                       OjruBBjiY00v5M@M1Y17O\n");
	printf("@MFj@OO00qqSqNZOEqO88MMOBBZ7                     11SUXOM5vLOBMF5SqS2uJO\n");
	printf("@B1uBON Z888OXFGOZMMZEOZMMMB@OGGB           @BON8O0kXPNPSjuOBMqjvvOO0kO\n");
	printf("@M 5u@MMOEZOGOMZq8ZOOMMM88OMOBOOM@@@      BBMOMOZOEZNZPXSPPOMMP2JuOBMMU\n");
	printf("BBUuB@BBMBMMMGqMMMMMEZ0Z0O8MEOOFv            LOBOZOGO8MOGNEqqX0NNFBBBO2\n");
	printf("@O0vk2511JuU2u5uL7uEEPZGENOMGOMv              LMMMMMM@jZMO8OqkPZ0EZOMMj\n");
	printf("BBB@BBMBM@MOOO88GMM8kEOOqZ8BOM5;               MOOMB;qBOM880Z0NPqXXPP\n\n");
}

void vid_right_yes()
{
	printf("vrvrrrri;iii::::. :,............,.,.,.:,:,:,::::iiiirr7vJYJJjYUu15kFS5\n");
	printf("r:::::,,.,.,....                               . ... ..,.::::iiiirr7LJ\n");
	printf("7i7;;ii:i::::::::,:::::,,......,,...........,,:::,::,.,,,:riiiir77J:LU\n");
	printf("vr7rr;ii:i::::::::,:,:,:,:,:.,,:,:,,,:.,...:,:,:::::   .,:7i,iirr:u;71\n");
	printf("7i7rriiii:i::::::::,,,:,:,:,:,:,::::::::i:i:::i:::ii:::::ir;ir7r7vU:vU\n");
	printf("riir;rii:iii:i::::::,,,:,,,::::::::::::::i:ii;irrrrv7v777777777vvY2:7u\n");
	printf("7:riri;::,:,,,:,:::,:,:,:,:,,,:::::::,::::::;irr77LvYLjJuuuj2u2U21NiL1\n");
	printf("7irriii:,,,:.:,,,,.,,:,:::,,.:::::,iiiii:iiiirirrLvLvLLjjUu55SFXS0O7jZ\n");
	printf("7i;:rvY7777r7rrirr:.:::,:,,,..:,:,,iL77r77viii7r77vvLLjYu2525FkSPXOrU0\n");
	printf("riiirYuJLL7v77r77Ji.. :,:.,,:.,.,,,iL77vvLv::iirr77LLJYuuS5FFkSPkPGrJG\n");
	printf("i.::r7Lr77rr7rrr7vi ., ,.... .. SDGiuvvvLYj,,:iiii77vvJYUSk5SkXXPkGY5q\n");
	printf(":..,:7L7;rrr;rirrL:  ..     SFSFDF2uuUJUY.GDGJHJR irvvvYUPkXkPq0P0q8qq\n");
	printf("i.,.:7u7777rrrrrrv : .     . ERTRrSvRYRY22uFDSGGiir7v7Lv1qNkPqNq0qEZ0q\n");
	printf(":,:::vjLvvvvvL777L:.  ... :QWuXvr;Ji::uuSUFSiDSDGHr77LJUS0N0XEEZ0ZZ80E\n");
	printf(":.i::vuLYvLvLvYv7Li   .   DFL   SUFuYSZ   5GFDGDGDFJU2k1q0EqEE8ZGZ8O8Z\n");
	printf(":,iriL5uJJLvrr;i:i:.....  GXR   Uu777Lj   S::7vJJ25k1SFX0GNZEOG8ZO8ZXP\n");
	printf(":.rur7J;i::..., .  . ..,:DL1u   vvYLLvr   0L7JUuUuFkXSqPZZGGO8O8MOM5uJ\n");
	printf(":.:FYr: .,,.,:,,,..,,: .FPkuL   ;i;vuPL   rjYUuFFFFPkPNZE8Z8GO8O8OOBMM\n");
	printf("7:rGv:i,:...i,..,..,r.LUjLr::   irri::7   ::kSSFSSNqEE8GOGO8OOOG888EEN\n");
	printf("7:rSr::i::,:::..:i:,L0OMMOY:             I: ;0qPX008ZO8OOOGGqZEZ0NFqkP\n");
	printf("v :;ririi:::.:..,irrYu:v                    .2BG8ZO8OOO8MGZ0ZEZPS25qk5\n");
	printf("vi::irir,irivvuS7r5Mu:L      TR      UI      LBMOMOM8M8O0PkqXXkX2X0ZPq\n");
	printf("Li:ir7vL5L7i5ZOSirkO2:      J  K    O  O    ;r@MMOMOMOG00kkFF2uj2XO71O\n");
	printf("1JvuUuq8M1i7qOO2:v1JL        TY      GH      7@BOMOM8GZG0Z00Pk2kEOOrjO\n");
	printf("B0v2j78OBJivqEkuXZL:j                       .u@MMOONGNZZEPqP0FqEG0BvSO\n");
	printf("BErFL5MBM1vEPLiuBMYrU                      :;MBMO808NEqPkk1SUSPNqZBYkB\n");
	printf("@0LU1SqS1kMBOLvFBOk2S22S                  LvOBBOMMO8OPEGENqSN0EE8O@LPB\n");
	printf("B8FZ8G7LJEM@8YukPNPXkE8Z0               YZM@BMMMG80GOMZOEFPO8OGENOBYS@\n");
	printf("SUBMB8uj20MO8XPkPPZ0EEOZOMOO@B@B@B@B@@@MOMBOMOO8OOBO8EGqGO88OZZOMO@LPB\n");
	printf("12MBMM50q0SqqEq88M8OZOZOBGv           vSOO8MO8EE0ZEMMMMMqGMMMBMMB@@Lk@\n");
	printf("5uMMMZE0ZkkNO8OMqu@MMMOBOv             LMG8M8qZGEXZ0J7Lu1U2uuJ2212SvZM\n");
	printf("ZPPPXqP0EZE88MO@F7BMOOMM                SMOBGEq8O0S8MBZO8O8OM@MBMBM@BB\n\n");
}

void start_no()
{
	printf("0N2qGZ0NMBMBOMOBO8OMOONXjP8GZ00ZPGEOEOZ808OZqNXZOBB@MNGZPkFkFEqU58EEqE\n");
	printf("OuuqBM0U5qOGOOO8OMBMMOMMO8M8EEGZE00EGMO8OOM0ZGGZOOMYvP0q0EOq151SGZGPEO\n");
	printf("8O8MGq22LL5OENkkSES8Pj5EOMMM8OB@BBO8qXXMEO8O88BMMMu,iZ0ZkSk00ZSGOM0qqX\n");
	printf("OFuE@MBMBMMPPF81vrkSq21FqqMOGPNFSZ@FujUYPGMZZq52NMBB@MMZZqqPM8GXkZ8NOG\n");
	printf("ZGGGM8EE8OqEPPkU2NZG8MOMM8XSNMEuLPSq5E0FqN0O0ZGO0POBEZGG0XZO8O5XXSkEM8\n");
	printf("qqMGGP0211FSXkkqGZOGENMOMOGNOBBO0SujFE8E5U0OG08O8XEOMOuLONGEZ8P5kS1FE0\n");
	printf("M@B@GBMGOBB@B@8EOMOMOEOMOG8MEZNGG8OZXqZ808OMMOZGOO8MSrvPNMGPEGSkEOqEOM\n");
	printf("0ZOB8OZONqPqXk0E5FNGEEZE0NZOPZ0N08ZOZNZ8EMO8OM8MZMOMGZk0EXkGEqXqZMZqqZ\n");
	printf("E5E88OBMGNGMB0G80NOq0N88Z0O0NZGZMO0qEZGZ8OOEGEO8EEBM8E0XENGNOqGEOZu:LO\n");
	printf("OSPONZMMB@qGB@B@@@BM8G8M0Oq0MM8O8rYOGOXqXO8ZkqB0qBMMXSXZOM08GZEONSEGEP\n");
	printf("GU5EM1Fk55MMOqkqMZ0XGO@8XqZGOZ8ZO8OqZ8BBGS88GOM8GE8EZ8MBB8G08M88MEOO8N\n");
	printf("OONEMMMOEGZOZk5E0ZEMOON8GGOOG8E8EMEZEGqPXZZMOZEOGOMBOOOOMBMMMGqE0MMOXE\n");
	printf("8MM8MOOEGEN0OZZqNkOMOXXPMO8NGZEOBBOUNMOONP0E8EG8OOBBBM80O8EZBZ8GGZEZGO\n");
	printf("ME0MOXEOMMGBM8OMMMOOE088NOOOBM88NOUvqMBMEBOOBGNXXMOGNkEMG8GMOMBBuZBEMB\n");
	printf("@OMkP0M00Z08OFXXMB80OMMZEO8EPOMqENqO0POOMZqGEZOOBGO0qPOOM8MEGZLX5ZEPGG\n");
	printf("MBMkkEEOOOq1LY2XSYSEZ8ZG0q8GiqOZG8OOGOGO0E0ZqOEGMO0k1Z88O@GOOOXMBOZEZO\n");
	printf("O0SUONZM@ONMBOZOGkOOZZMZOZMO8EMG8OMqEMBOM8OZOZZEOGGPGMOEMBO0@M@MBGZOGE\n");
	printf("EEqBBMMBO0M8kEZMOBB@OGBOZMM8BOuGZ8OBqZ8GEMG0XNOMGOMMOMZ@O0uEM@MOGONE8@\n");
	printf("8ZGqNGO8OO8q0GZkOGEF2L0GMEPkuO@EB0PX1NBPPEGqO00P8ZMB@OPv7XEMOqEEGEGO8P\n");
	printf("B8SSFP0GOMZEZMEFqMOOZ55NMEN   OB88qXuXG8qPX0M8EXEO8@BBuSM@MMGZPG8GZ88P\n");
	printf("qX@GMGOMM08BOF5PNqqr:SEqkG@5: PB8GBOZO8BOSq0MOO5X0EX08@BOZMX1M@BNu@GOE\n");
	printf("G5qOOGqGNqqEOMMMZNr:B@LqOB8@B@GGE0PZOOEOqGX8M80NYPMGXSNE0ZGqSXLuEBGO@B\n");
	printf("0k0SGGPSFPZq8O8GGkSMPv1NM8P0MO0XEqGqEO8EkXOOMGOEEOBBOZOEZZOGGOZNMMMOOE\n");
	printf("G@BE0MOOXFOZOO0GGMBMN8N5YPPEMGZ8G0ZMEOZOqZOMMMMBMMGMMOOOEOGGZ@GvOBOMZ8\n");
	printf("B0ZNqXEOMqG8BqPEMqF58P8MGEBB@08GqEPqZPkF0XZMBMZZBNq5qNqBBZOOO0OXZMONXG\n");
	printf("OMMGG@MOG5GMGMBBOOqE0EGBOZO0jGBO8Oqk0MOMOGPEq0Bu qM00OOMMOMOO8qPP8Z0E8\n");
	printf("@OM0GBBZZXGOOGO8OqOOOMP0ZSOL:GOEM8EqEGOO8qNEENBquGZOOOOGMZZqNOOZMO85k8\n");
	printf("@BBOPNOMZOG8EONq088NU8SGOMMM@@8OO@MMOOEO8OMMOO8MOMZMMOXqPNEPXM8ONE88PO\n");
	printf("8OOXX021N10ZMGOOO8qq1PqFEEO8OG0kEG8E0ZO8MMZSMMBMONEqPEOBMk5qOZOqqNMBMq\n");
	printf("NXP08@OOMOkEMMOOFEZZ0MMM8XSkXOE00ZkPNN8OZ8ZGXS8O8OO@GG0888GZqOZOOBOMPk\n\n");
}

void start_yes()
{
	printf("@MMMBMBMBMBBBMBMMMMMMMMMBOMMBMMMMOMMMMMOMMMMMMBOBMBMBBBMMOMM@MBB@BBMBM\n");
	printf("B@MBMBM@MBOMOMMOMBMMMBM@BB@@BBMOGOOMOOOMOMMMMBMMM@MBB@B@MMM@BBBBBBM@BB\n");
	printf("BOMBMM@BMMBMBMBM@MBMBB@juB O@:@BMOMMMMBMMMBB@MBMBMBB@MBB@BBMBBMMBMBBBM\n");
	printf("M@B@BBM@B@B@MBB@MBOMB@Bu U rr.@@MMMBMBMBMBBBM@@@MBBMMMB@B@MBMBMBMBMBMM\n");
	printf("@MMMMMBMBMMMBOBMBMMO@B.        G@MMOMMBMBMMMBM@BBMOOBB@MBMBBBBBMBMBM@M\n");
	printf("BBOMM@BBMBMBMMMMMMG@B: YB1 :B@  B@MMMMOBMBOMMBM@BMB@BBBBMBMMM@MMM@M@B@\n");
	printf("BBBMBM@BBB@MBMMMOXOB@: L@U :@B  @BBOMOMMBMBMMMMM@B@BBMMMBMBMBBBBBBMOBM\n");
	printf("MMM@MBMBM@B@BBOMZOM@B:   ...    B@OMGMOBBBMMMBMBBBMBB@MBOMB@MBB@BBGMMB\n");
	printf("BBBM@BBOMBBBMMMOMOOB@.  .,:,.   @BMOMOMM@MMB@M@@@MBM@BBM@MMB@BBMBOOB@B\n");
	printf("BBMBBBBBM@MMMBMMOMM@BM0u, , ,iE0B@MMOMOBMBB@BBBBMBBBBBMBBMO@MBM@M@B@MB\n");
	printf("@BBB@MBBBBBMMMMOMB@E2M@P,:::,i@BS2@BMOMMMMBZOMBBBMBBBMBMBMBMBMBB@MGM@M\n");
	printf("MBB@B@MMO@MBMMOM@@r      ....     :M@MOMMMB88BMBB@B@MMMBM@M@MMMBBB8MMM\n");
	printf("@BBMBBBMBMBMBMMO@B  :N., .,,,.v2   U@MBMMMBM@BBB@MBMBBBBBMBB@BMM@B@OOM\n");
	printf("MBM@BOMBMBMBMMMBB@  i@ ..,.,..EB   PBBOMMBBBMBMBBBMBMMMBBBBBBBBBMMOOB@\n");
	printf("@BBB@M@MBMBMMOMM@B  iB  ..... FM   k@MOOMMMMBMBBBBBBBMBB@BBBBMBM@MBMBO\n");
	printf("BMMBB@BBMBMBOMOMB@. r@,,:::::.SO   0BBOOMBMBBBMBM@MBB@MBMBMBMBMMMMBM88\n");
	printf("BMBMBMBMMMBMMMMM@B. r7 .,.,,,.:k   S@MMOBMBB@B@MBBBMBBBMBMMMBBMMMMBMBM\n");
	printf("BMM@BBMBMMMBMMOM@@  ij ..,..,.:5   SBBOMMBMBMBMBMBMMMBB@MBMBM@B@B@MBB@\n");
	printf("@MBB@BBMMMBMMMMO@B, 7 .,...,,.iu   L@MMOBMBMBMBMBM@B@MBBBMBB@MBBBMMMBM\n");
	printf("BBOMMMOMMBMBMMOMM@8M@i .......  BBZBBMOMMBMBBBMBMBB@M@MMBMM@BBMBM@MBB@\n");
	printf("BBBMBM@BBMBMBMMOOO@@@N   :@u . i@B@BMOMMMMBMBB@B@MBMMMBM@B@B@BBMBMBM@B\n");
	printf("BBM@BBB@BBBBMMMMOOOBB@   :B5 , 7@@OMOMMBMBBBM@MBBBMBMBMBOGq8MMOBMBBBMM\n");
	printf("BMMMBB@BBMBMBMBMMOMO@B . :@Y . L@BBOMM@M@@BBBB@MBB@MBBBBZNEE@BBMBMBBBM\n");
	printf("MBMBB@MBMBMBM@BBOMOBB@, .iBu   7MOB@MBMPFMBBM@MBMBMBMBMB@@B@BBB@BBMBMM\n");
	printf("BBBMBM@BBMMBBMBMMMBB@B   .@7      @BMBBOOM@B@MBM@MMMBMBBBB@M@MMMBBBMBM\n");
	printf("BBMBMBMBMBBBMMOMM@BMOB   .@MUGk1LJM@B@B@BBM@MBBBMMMBMBBBMBMBMBOBM@MMMB\n");
	printf("BBBM@MBMBMBBBMMB@@@:      @B@B@B@@@MBB@BBMBMBM@MBM@MBMBMBMBBBMBBBBBB@M\n");
	printf("BBMMMBMBMBBBBBBBM@BqiLJj7LB@MMB@BB@@MBMMM@B@BBMBMBBBMBM@MBBBBBMBBBM@M@\n");
	printf("BMBMBMBMBMBB@MBMMB@B@B@B@B@MMMBMOOBBBMBM@BBMMB@B@BBM@MBB@M@MBMMBBMBMBM\n\n");
}

void room1or2_no()
{
	printf("MMOOBMBB8u0MPX@B@BMMOGOZG0kkkFZZO0NMMMBOBSU0PuqBOB@BMB@B@B@B@B@BO@@BBB\n");
	printf("OOMMMMMBG8ZMqPq8EMMBEZq8ZGP0SqG8GqEOMMOMOE0M8ZZBOBMBOMOEZMOB@@B@B@M@BB\n");
	printf("MOOOOEO0MM:,ii:,::GqSXkNXXEPEXq0qqqXGXGXXZGOOGMPO8OOOBu:iiri.L@B@B@B@B\n");
	printf("OOGMGZOEOB.iBBOOOEEEPZPGPZN0Z008X8kPZqZ0P80OZGOZO88MOMM@B@B8 uB@BBB@B@\n");
	printf("MOOB@B@B@B,:@B@B@B@B@B@B@B@@@B@B@B@B@B@B@B@B@@@B@@@B@OBM@B@P v@B@M@BBM\n");
	printf("MOO@BBBBB@USB@B@MBMBMBMBM@B@BBMBB@B@B@B@B@B@@@B@B@B@BOMMM@@MLZB@B@B@B@\n");
	printf("MMMMBMBMBB@@@MMOMOMMMOMOMMMMBBBMBMBM@B@B@B@B@B@B@B@B@MBBBB@B@B@B@BBB@B\n");
	printf("BBB@BBM@MBMMOMOMMMOMOM8O8O8OOMMBMBBBMBB@@@B@B@B@B@B@B@B@B@B@B@B@B@B@B@\n");
	printf("NUXBBMMOMGOMMOMOMOO880Eq0XPkPP0EOMBMBMBM@B@B@B@B@@@@O20GOEG8BB@B@BMB@B\n");
	printf("S1UBMMOO8OMMOM8OZG00XqP0NEq0qNXXkqEOMBBBMB@@B@B@B@B@..:i:jir7k1OF0PEBB\n");
	printf("055BMOOOMMMGOZ8ZEXXXqPXSXFkSXkNqEPkkZOBMBMBB@B@B@B@Bvuu7X81uJ1k0FSq8@Z\n");
	printf("qS1BMMOMOOGOGEN0XPXPFF1F5F5S1S1Sk0NqSNOM8MMBB@B@B@B@B@,:OGOMMOGkUSOBOM\n");
	printf("PFkMBMMOO8OGGNNXPXPFFFkSkFkSkFSFF5P005qOOO@MMB@B@B@B@BYqX1MGBZ@BG0@0MB\n");
	printf("NqSBMM8O8OGGEXFNPX5kFkSkSkSSSkFkFS5X00SEEMMBM@B@B@B@B@8BENOMM@B@B@OMB@\n");
	printf("ZqPMMOOGO88ZG22qqSXkPFkSkFkSkSkFkFk1qEPkXOMM@B@@@@@B@B@MGuOB@B@B@B@OMM\n");
	printf("ZqEBMO8OGOE8E2UEP0OMGNkkFkSXFkFkFS5SkGPX5OO@@BMBB@B@B@BBO8B@B@@@B@B@M@\n");
	printf("8NEMMGO8OGGZZU20GSr:L0NkXFkSkSXSXSk1XE0SkGBB@MBM@B@B@M8O@B@@@B@B@B@B@B\n");
	printf("0EqBOO8O8808Ek5GP,    0PFkSkFkFkSk5FXZqqXOM@B@B@B@B@BMOMB@B@B@B@B@B@@@\n");
	printf("80EMM8OGO8GE8XXNE    iZXkSkFkSXSk5FSEqq0GGMB@B@B@@@B@B@B@B@OO8BMBB@B@B\n");
	printf("OGGBOO8OGOGZE0q0EO1JFGXXFXSkSkFk5kkEqqNOEOOBB@B@B@@@MMB@B@@@MBB@B@@@B@\n");
	printf("OZ8MMGOGO8OEG00qENMO8Pk5S5S5F5FSPXPkP0O8OMMO@B@B@B@OOO@B@B@B@BBB@B@MBB\n");
	printf("OOGMOMGOGOOMZGEZNNXPSkFkFSFSSXkkkkkq0O8MMMOMM@B@B@M@B@M@B@B@@@B@B@BBB@\n");
	printf("MGOOMMOGMOMMMZZZ800XqFS1F1k551kFXPZZOOOMMOMMBMBB@BBBBBBB@B@B@@@@@BBM@B\n");
	printf("MMOMOMOOOB:rBM8OZGEGq0qPkkkXSqqZGO8O8MMMOMMBMBMBM@M@MMB8O@@O,2B@B@B@B@\n");
	printf("MOMOMOMMBB.:@B@BBM8ZGEZ0ZNZEEEMOO8MMMM@MMMBBBMBMBMMMBB@B@B@O L@B@B@B@B\n");
	printf("OMOMOMMMB@..Jv7L7L8OGOOO8M8O8MNv:,r@BBM@B@B@@@B@B@MBO@0YJUu7 vB@B@B@B@\n");
	printf("MOMOMOMOMMN5F2SF5F@B@BBMBM@MM0NFivuu7uL:EGMB@@@MOGMO@B8jF5SkPE@B@Mv77i\n");
	printf("MMOMOMOMOBB@80XX5UL7rrri::.i7r1@B@@;52krrrrv7v7kBOOOOBB@B@B@@@MMBSrSiL\n\n");
}

void room1or2_yes()
{
	printf("BB@BBOMOOOB8@BOO@MMF25OB@@@7rB@XrivuL;1r:iPGX5u08GNJY2O8G2SqMOM00ZO08M\n");
	printf("BBBBOM8Z0ZZOq0q0M@B5X@B@B@BOu;:, ..::iLu5GqP777FEE5LJXZGE2uUGOO01NPNEO\n");
	printf("@MBMOOM0M0Zur,:,rLGNEBOvvr7v:,i..:LvuLr7@B@BZvi1OEFuS28ZO1U5MZMq8PE88G\n");
	printf("B@MBOO8GPGur     i7BFui,,,,iii,r8MGOZ1L7jkN@B@OEXZSP0S8MGk2GOMM0PPX00E\n");
	printf("@BBBMGMNOBLr     rLNuLi:::::ri:7FukEZFi7U1EM@B@@MqS1U00UM1PXO8MqSkqZZZ\n");
	printf("B@MB8OEZNMPr:.  ,Y@OS5POM@uiri::kj;,,08iuLJX0OZ@BXFLS0JPuB1kO8ONZqGM0O\n");
	printf("@MBBMZ8E0ZMEkuv7vZ@E20B12FqqB7:L5    :@ukrLFMuUSNXP5EijjikO0O8MEZGZPZ0\n");
	printf("BMB@MMO80ZEOMMMBBBBOu0U21J  :@:,ur:vL8u7UuvXXu1G8MGBuvuSvL8Z8MMGNOqGGO\n");
	printf("BB@B@MMEG00XEqGEOPEBkYvM:    BMq@@@i:   :Sk52LuUS55jFXGEZPkkEN8XPPGZ8G\n");
	printf("B@B@MOGOZZNqEGPkkjUXBPFU@ju:u@B@M7      ::XM5Y:J77J:JLJ1LSL121PS0ZN8GM\n");
	printf("@B@@@OO8O0EPZ0P@@B@B@8PvvBO7.    :  ::.:v,MO8B@@@B@B@B@B@B@B@B@@N0GGMM\n");
	printf("B@B@B@OMOOZGEEX@B@B@BN5F2U..   ..:YYL7:::8v:UEB@B@B@B@B@B@B@@@B@XZZOOO\n");
	printf("@B@B@BBMM88OMENB@B@B@MqS@O.:i::, : Yu.iYF5 2vU@q22XM@@@B@B@B@B@BE8OOBB\n");
	printf("B@B@B@B@B@B@B@M@B@B@B@@OB@v.:LYi.iE@u7B@q :u7FBr  .77rrjUNB@B@B@B@B@B@\n");
	printf("@B@B@B@@@G0NZuvB@B@B@B@B@B@8kqLMvv0FPB:L;:2JvL0u  rr:.,:::7;7S@BJqBBOM\n");
	printf("OP1uL:.    .Yr.BB@BBPMB@B@B@B0jOBO EBL iPOk2L1rLrivi.... ..:,JM     .\n");
	printf("FvL7v,:,. .,2J:B@BB27iEB@BE5Xr: Y:.7YuMEUv7LBBj7kLJr5ur:,,.:5Bq ..  7\n");
	printf("q5JJuJii:.,r2u:@8SOUL7 vB@@M0kPk5OSJYuSXqMB@B@qi22GMB@OLivrii::LLr7 v: \n");
	printf("qFSJjL::, .;uLPESJOMuYrj0k@B@Gu7ukjuMB@B@B@B@ULrNOU1U2X0uUv72 .:NB@,,1\n");
	printf("E0FuYY77i;riLqBkUXXLXMuBBrF@B@BBB@B@B@B@B@MjLuLY1MBOSUSZP2uGqi:2BB7vLu\n");
	printf("@BjXMM@B@B@iuMMPS51UM@@B@FjB@B@B@B@B@B@B@@@vr1kuJ1@B@OE7:7q0PFM@L 71@7\n");
	printf("B@kNB@@@B@8iJNBE0qqGMOFJZ@UPB@B@B@1r1j .uOBJ :uFUk@@BOrr,XLUPSNBriX@O:\n");
	printf("@BSN@B@B@BOiNOPBOEZXPPEB@B1Jk:i@@r   ..iuYri:5SM@@OjUq@k7vvjUq8@7 r\n");
	printf("B@EZMMMMMMO7NM1X2YuGG0B@B@qUu;rr.  .M@Bi,i,rri:,ikB@B@B@B@X7rr71UjPviF\n");
	printf("@BB2F5kkX8M7qBquFvLuF2@B@@@uvrji:ii:YZ0:irLLv77;LM@B@B@B@@@MGPBM5PG881\n");
	printf("PXkkkNP0Z8EYqMZXUuF52E@BM@BMjvur:77r.FBBJL7v;vY1B@O0@@B@B@B@B@@@UZ0YN0\n");
	printf("OMBB@B@@@MMqZNMXuuF50BM8@B@B@UjvYS2irM@BuU0P8B@B@EPZ@B@B@B@B@NFP0qNqZ0\n");
	printf("M@B@@@B@@BO@BG0BMNZB5S iB@BB@@B@B@BBBBBBB@B@B@8XYUSOB@B@B@B@BNM@B@@@@@\n\n");
}

void elswordface()
{
	printf("@MOM@BBMMMMO@8GB@MOOMB@@@BBMO08MBMBBBMMMGqOBBGOM@OMZ88MM@BBOOMBM@MOM@B\n");
	printf("B@O0P8OM8OO@MZ1S5FFEM@B@@@B@MN522FF00SUu2PP@B@B@@@B@BMqUFMBBZ8ZO0qPOMM\n");
	printf("@B@BMEEG8G@B@ESu5O@B@EJ7vLSE@B@q51XEE1128@MM@MNuLvUq@B@q1uPB@MMZGOBMMM\n");
	printf("B@@@@@MBM@BBX12EB@k7..:i:. ..iUM11FEXXSP8BkLi : .::.; 2OME1FB@MMMMMMOM\n");
	printf("@B@B@B@BBMBEXFEBG7i.:B@@@Bi iLXMMOMOMOBB@Pv:., B@B@@i :iqOq2NB@MOOMOMM\n");
	printf("B@B@B@M@MBM8EBBOvri,.7qMB0 jB@B@BBMBMBMBB@BMi..5MMMq  .:iMBqFOB@8MMMMM\n");
	printf("@B@B@BBB@MZ0MBMOur77vv2F5JFqPGMM@B@B@B@BMZZ8MM85k17....:rO@N1qBBMOMOMM\n");
	printf("B@B@B@M@BOPq11PB0NGMO8q52PU221u5kZE8Z8X5uuu52FSXUPZBB@PFM@MOPqM@MMMMMM\n");
	printf("@B@B@B@B@0XSF2kqN00qPkF25ujjuY2uUUUvLuJLJLjJjLJ11jF1GB@ZONULU10B@OMMMM\n");
	printf("B@B@B@B@MqXGEZEEqq1k11U1N0FUJuU211uuj2UJL2JuLjEB0YLLS8ZFFPkSFNXMBMOMMM\n");
	printf("MB@B@B@MNX0PGOZqNXXPF1u1BOMS225UF25uF1FujJuYvUMOBLvvXZOq5FZS1S00BMMOMM\n");
	printf("M@@@B@BZkNNZOOEZGO8ESX2GOqMNUX55kS2kEqXquuU5UXqPO155GBMOJF28SFSPGBM@B@\n");
	printf("MB@@@BBEOGEkZ08G@MO8NEMMYvOqPMOP0GZqGOMGXB@q8Zj:MOEqON0O8F10qqZNGB@@@M\n");
	printf("8@B@B@OE88FE8BB@SuLGjrGS, Ori@B;i@B7r@Bri@O;r@  BMruB2uSM@8q5OOGqOB@BB\n");
	printf("OM@B@@O2XMMGPk@0   O  Oq uM  BO  @M  BM  BN  B,:@S i@  .@SLBGME12qMB@M\n");
	printf("EBB@B@O8BNi, iL   r@,:B@B@B,L@B.7@O u@M 5@@ u@B@B0 EB    .u.; UBBOP@MB\n");
	printf("XO@B@MMBB   qBJ, @B@B@B@B@B@B@B@@@@@B@B@B@B@B@BMB@B@B@BXi:S@; .Z@M1M@M\n");
	printf("uOB@B@OBu,X@B@qM@@BMi@Bv5.O@F5BLB@77@OB@:,u@BO MB@B1:M@@MZ@@M J@B@UEBM\n");
	printf("vP@B@BM@jiFB@BBk21XLrEu.. FB.:i OM .i.B0   r@v iY5i,i752uk@B@B@B@BX1@M\n");
	printf("rS@@B@8OYrB8, M@MONqk2UXSk2Uu2u1uu21LJju5qk5uu12uF1NNSkMBM.uB@@@B@8jBB\n");
	printf("LU@B@@ZqFu7 ikB@@B@B@OZ0ZPqXPq05Fk05q0X2k0EkqqPkEEEG@B@B@@@  B@B@B@jOB\n");
	printf("5uB@B@ZkS@, .E2FqqB@B@B@B@B@@@B@MBMMM@BBB@BB@@B@B@B@@@O@N@G. FMOB@Bkk@\n");
	printf("0L@B@B8uBBki :     B@B@B@B@B@B@@@B@B@B@B@B@B@B@B@B@BL  , Y  .O@50B@81B\n");
	printf("8vM@B@MqEqB@BEkqP: 7@@B@B@@@B@B@B@B@B@@@B@B@@@B@@@B@  7u72q@@Z8EXZZOOB\n");
	printf("@v8B@B@ZEXEZM8@B@Y  :; Or@BOr@Bkv@BM7MB@Fu@@JPB@u8qii.BB@MMBOFqP0E@B@M\n");
	printf("BLq@B@BO8ZPEq5O@B877 .  5@, 5@  M@J 7@B  @B  @@  ; ::2B@BX5q5q08BMuL7r\n");
	printf("@XZMMGGqMO8ZMOZB@@@M2FYiqBv:0BriBBS.JB@r:B@::B@:iULq@@@BXXGNEEZU88uuYr\n");
	printf("OOEqSkPNXE0GM@OOOZO@MOq0B@SZO0SX0OEq0MENSEMN1@Bq0ZM@OXFqqMOOZq1SOO1NkJ\n");
	printf("8XqPqqNZqkXSXEMEZXPGGSqZ@B01SjjjYLXGGvvJUJkSEB@FuU8O25NE88ZkFqGJUZ7757\n");
	printf("12u5S0SqXk1FFkEZNGqkZEXFkk5uuS5XXk2521U221juSGXuukFkPGG8ZOG80Z0ZO@LvOq\n");
	printf("5212kFPX8E0EZZMZZPXkGMMNS1XXqkqPZ0NFPXNXqSNXPFkNENZZ8ZZ0OMMMO0EZOMF7XM\n\n");
}
