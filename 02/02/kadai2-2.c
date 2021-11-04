#include <time.h>
#include <stdio.h>

/*--- 現在の年月日と午前か午後かを表示する ---*/

/* ==================== 問題 ==================== */

/* 
   現在の日時と午前午後のいずれかを表示させるプログラムを
   作成せよ

   例えば，
   2019年10月10日19:00であれば
   2019/10/10 A.M.
   2032年11月11日01:00であれば
   2031/11/11 P.M.
   のように表示すること

   なお，現在時刻を取得する関数については講義資料を確認すること
*/



void put_time(void)
{
  //
  /* (* ここに解答を書き加える *) */
	time_t current;
	struct tm *local;
	time(&current);
	local = Localtime(&current);
	printf("%4d/%02d/%02 ",local->tm_year+1900,local->tm_mon+1local->tm_mday);
	if(local->tm_hour>12)printf("P.M.\n");
	else printf("A.M.\n");
}

int main(void)
{
  printf("現在は");
  put_time();
  printf("です\n");

  return(0);
}
