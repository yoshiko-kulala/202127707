/*
  ファイルから指定された文字数分の文章を読み込み，文章に含まれる
  単語を分割するプログラムを作成せよ．

  以下の手順にしたがって，プログラムを作成せよ

  step1 :
  void load_characters(const char *filename, int cnum, char string[])
  ファイル名をfilenameに，文字数をcnumに指定することで，
  その文字数分の文字を読み込み string に格納する関数 load_charcters を
  作成する．

  step2 :
  int string2words(const char *string, int max_num, word wordset[], int max_wnum)
  文字列 string を単語ごとに切り分け，構造体 word へと格納する．
  このとき，単語とは，' '（スペース）, ','（カンマ）,'.'
  '\n'（開業記号）とする．
  アルファベットおよび数字以外の記号で囲まれた部分である．例えば
  I have a pen. -> [I,have,a,pen] と分割される（区切りは含まない）

  このとき，文字列の最大文字数は max_num とする．ただし，
  文字中に終端器号 '\0' がある場合には，max_num 以下の場合でも文字列は終了
  とする．

  word 構造体は以下の通りであり，文字数 num と文字列 word を持つ.
  最大文字数は 15文字（終端器号を含めず）であり，15文字以上の文字
  が与えられる場合は，それ以降な無視する．

  typedef struct {
    int num;
    char word[16];
  } word;

  max_num は最大単語数であり，wnum を超える単語が含まれる場合は，それ以降は無視する．

  戻り値は単語数である．

  step2-1 :
  step2 を進めるために，まず，以下を作成する．
  int issep(char c)
  c が区切り文字であるかどうかを確認し，区切り文字であれば1を，それ以外は0を
  返す．

  step2-2 :
  次に，上記を利用して以下を作成する．
  int string2word(const char *string, int max_num, int position, word *w)
  これは，position 文字目以降の文字列から単語を抜き出し，w へと格納し，
  単語を構成する最終文字の次の文字の位置を返す．
  単語が見つからなかった場合（与えられた文字以降区切り文字 or 最終文字
  がすべて区切り記号であった場合）には0を返す．

  例えば
  string = "I have a pen", position = 3 とした場合，
  word->num = 4, word->wordには have が格納され，さらに7を返す


  step2-3
  上の関数を用いることで，string2wordsを作成する．

*/

#include <stdio.h>
#include <string.h>

typedef struct {
  int num;
  char word[16];
} word;

void load_characters(const char *filename, int cnum, char string[]) {
  FILE *fp = NULL;

  // ここに答えを記述せよ
  // 文字列として読み込むため，最終要素に文字の終端器号を追加すること．
  fp = fopen(filename, "r");
  int i = 0;
  for (; i < cnum; i++) {
  	char ch=fgetc(fp);
    if(ch==EOF)break;
    string[i] = ch;
  }
}

int string2words(const char *string, int max_num, word words[], int max_word) {
  // ここに回答を記述せよ

  int word_num = 0; // 単語として切り出された数を入れる．
  int position = 0; // どこまで確認を行ったかを入れる．
	int word_pos;
  // while ループを用いて記述するとよい
  // string2word が単語を見つける（単語を見つけなかった場合の文字列
  // を返さない）かつ，分割された単語がmax_word を超えない限り，
  // position を進めながら，順番に words に単語を格納する．
  for(word_num = 0;word_num<max_word;word_num++){
  	word_pos=0;
  	while(string[position]!=',' && string[position]!=' ' && string[position]!='\n'){
  		words[word_num].word[word_pos]=string[position];
  		word_pos++;
  		position++;
  		//if(position>max_word)break;
  	}
  	while(string[position]==','|| string[position]==' ' || string[position]=='\n')position++;
  	words[word_num].num=word_pos+1;
  	if(string[position]=='\0')return word_num+1;
  }
  return word_num+1;
}

int main() {
  char *filename = "ihaveapen.txt";
  char string[1024] = "";
  int max_str = 1023;
#define MAX_WORD 16
  word words[MAX_WORD] = {};
  int cnum = 0, word_num = 0;
  int i;

  // 文字列を読み込む
  cnum = load_characters(filename, max_str, string);

  printf("loaded strings\n");
  printf("[%s]\n", string);


  // 分割する
  word_num = string2words(string, cnum, words, MAX_WORD);
  printf("separated wors\n");
  for (i = 0; i < word_num; i++) {
    printf("[%s]\n", words[i].word);
  }

  return 0;

}
