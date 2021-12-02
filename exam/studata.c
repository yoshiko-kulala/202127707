// 試験問題1
// あるファイルに学生の身長体重に関するデータが含まれている．
// このデータを読み込んでそれぞれの情報を構造体に格納し，整理を行いたい．
// 以下の問題に答えよ．
// なお，必要があれば新規に関数を追加しても良い．

// 2. この構造体に対して値を代入する関数 set_studata を作成せよ．
//    ただし，set_studata は以下のように定義されるものとする．
//    文字列のコピーに留意すること．
#include "studata.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void set_studata(studata *data, char *name,int age,
		 double weight, double height){
    //nameのコピー
    mystrcpy(data->name,name);
    //その他のコピー
    data->age=age;
    data->weight=weight;
    data->height=height;
}

// 3. ファイルから学生情報を読み込んで studata の配列に情報を格納する
//    関数を作成する．
//    ファイルに含まれるデータの数は不明であるが，1行目にデータの数が記述
//    されている．
// 例：(データの数は2とする)
// 2
// Chris 25 180.0 65.0
// Bob 25 180.0 65.0
//     データの数に合わせて適切に配列を動的メモリとして確保し，その配列
//     に情報を格納して返す load_studata を作成せよ．
//     なお，データの格納には 2 で作成した set_studata を必ず用いること
///    また，num は整数型のポインタであり，このポインタの示す変数に
//     読み込まれたデータの数を格納せよ．
//     読み込みが終わったファイルについては必ずクローズすること．



studata *load_studata(char *filename, int *num){
	//ファイル開く
   FILE	*fp;
   fp = fopen(filename,"r");
   fscanf(fp,"%d",num);
   //確保すべきメモリ数
   //printf("%d",num);
   studata *load;
   load = (studata*)calloc(*num,sizeof(studata));
   int iii;
   for(iii=0;iii<*num;iii++){
   		char load_name[33];
   		int load_age;
   		double load_weight,load_height;
   		fscanf(fp, "%s %d %lf %lf", load_name, &load_age, &load_height, &load_weight);
   		//printf( "%s %d %lf %lf\n", &load_name, load_age, load_height, load_weight);
   		set_studata(&load[iii],load_name,load_age, load_height, load_weight);
   }  
   return load;
}

// 4. 確認のために配列に含まれる情報を順番に表示する print_studata を作成せよ．
void print_studata(studata *data, int num){
	int iii=0;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		printf("No.%d\t%s\t%d\t%lf\t%lf\n",iii,&data->name,data->age,data->weight,data->height);
		data++;
	}
	data=pos;
}

// 5. 配列を身長にしたがってソートする関数 sort_by_height を作成せよ．
void sor_by_height(int num, studata *data){
	int iii,jjj;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		for(jjj=0;jjj<num-1;jjj++){
			if(data->weight > (data+1)->weight){
				swap_s(data->name,(data+1)->name);
				int_swap(&data->age,&(data+1)->age);
				swap_double(&data->weight,&(data+1)->weight);
				swap_double(&data->height,&(data+1)->height);
			}
			data++;
		}
		data=pos;
	}
}

// 6. 配列を学生の名前にしたがってソートしたい
//    ソート順は strcmp により与えられる順序関係に従うものとし，ソートを
//    実行する関数 sort_by_name を作成せよ．なお，num は読み込んだデータの数
//    である．
//    関数は，文字列2つを引数として持ち， strcmp(str1, str2) としたとき
//    str の方が順序が前であれば 0より小さい値を，後ろであれば0より大きい値を
//    同じであれば 0 を返す．
void sort_by_name(int num, studata *data){
	int iii,jjj;
	studata *pos=data;
	for(iii=0;iii<num;iii++){
		for(jjj=0;jjj<num-1;jjj++){
			int kkk=0;
			while(data->name[kkk] == (data+1)->name[kkk])kkk++;
			if(data->name[kkk] > (data+1)->name[kkk]){
				swap_s(data->name,(data+1)->name);
				int_swap(&data->age,&(data+1)->age);
				swap_double(&data->weight,&(data+1)->weight);
				swap_double(&data->height,&(data+1)->height);
			}
			data++;
		}
		data=pos;
	}
}

// 7. 以上の関数は main.c に含まれる main 文から呼び出される．
//    呼び出しに必要な情報 studata.h に記述し，上記関数をテストするための
//    プログラムをmain関数に記述せよ．
void mystrcpy(char *to, const char *from){
	int i=0;
	for(i=0;from[i]!='\0';i++){
		to[i]=from[i];
	}
}


void int_swap(int *p1,int *p2){
   *p1 = *p2 - *p1;
   *p2 -= *p1;
   *p1 += *p2;
}

void swap_double(double *p1,double *p2){
   *p1 = *p2 - *p1;
   *p2 -= *p1;
   *p1 += *p2;
}

void swap_s(char *to, char *from){
	int i=0;
	char tmp[33]={'\0'};
	for(i=0;from[i]!='\0';i++){
		tmp[i]=from[i];
	}
	for(i=0;i<33;i++)from[i]='\0';
	for(i=0;to[i]!='\0';i++){
		from[i]=to[i];
	}
	for(i=0;i<33;i++)to[i]='\0';
	for(i=0;tmp[i]!='\0';i++){
		to[i]=tmp[i];
	}
}