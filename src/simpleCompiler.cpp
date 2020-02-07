#include <bits/stdc++.h>
#define WORDEND "helloworld"
#define SYN_BEGIN 0          // begin
#define SYN_IF 1             // if
#define SYN_THEN 2           // then
#define SYN_WHILE 3          // while
#define SYN_DO 4             // do
#define SYN_END 5            // end
#define SYN_VAR 10           // 标识符
#define SYN_CONST 20         // 常量
#define SYN_ASSIN 21         // =
#define SYN_PLUS 22          // +
#define SYN_MINUS 23         // -
#define SYN_MUL 24           // *
#define SYN_DIV 25           // /
#define SYN_LSBAC 26         // (
#define SYN_RSBAC 27         // )
#define SYN_LMBAC 28         // [
#define SYN_RMBAC 29         // ]
#define SYN_LBBAC 30         // {
#define SYN_RBBAC 31         // }
#define SYN_COMMA 32         // ,
#define SYN_COLON 33         // :
#define SYN_SEMICOLON 34     // ;
#define SYN_GT 35            // >
#define SYN_NL 37            // >=
#define SYN_LE 36            // <
#define SYN_NG 38            // <=
#define SYN_EQ 39            // ==
#define SYN_NE 40            // !=
#define SYN_DOC 99           // 注释

using namespace std;
struct WORD {
    int typeNum;
    const char *word;
    WORD(){};
    WORD(int ty, char *s) {
        typeNum=ty;
        word=s;
    }
};

struct emit
{
    char result[8], ag1[8], op[8], ag2[8];
    emit(){}
    emit(const char* rs, const char *a1, const char *o, const char *a2) {
        strcpy(result, rs);
        strcpy(ag1, a1);
        strcpy(op, o);
        strcpy(ag2, a2);
    }
}quad[1000];
int quadCnt=0;

char input[2048];
char token[2048];
int p_input;
int p_token;
int lineNum=1;

char ch;
const char *rwtab[]={"begin", "if", "then", "while", "do","end",WORDEND};

WORD *scaner();
void lrparser();
void program();
void statement(int &nChain);
char* expression();
char* term();
char* factor();
void statementSequence(int &nChain);
void statementBlock(int &nChain);
void condition(int &etc, int &efc);
int merg(int p1, int p2);
void bp(int p, int t);
int syn, kk;
WORD *myword;

int main()
{

freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);


    scanf("%[^#]s", input);

    lrparser();
    for (int i=0; i<quadCnt; i++) {
        emit tmp=quad[i];
        printf("%2d: (%s, %s, %s, %s)\n", i, tmp.result, tmp.ag1, tmp.op, tmp.ag2);
    }
    return 0;
}

char m_getch() {
    ch=input[p_input];
    p_input++;
    return ch;
}
void getbc() {
    while (ch==' ' || ch=='\n' || ch=='\r') {
        if (ch=='\n') lineNum++;
        ch=input[p_input];
        p_input++;
    }
}
void concat() {
    token[p_token]=ch;
    p_token++;
    token[p_token]=0;
}
int letter() {
    return isalpha(ch);
}
int digit() {
    return isalnum(ch);
}
int reverse() {
    for (int i=0; strcmp(WORDEND, rwtab[i]); i++) {
        if (!strcmp(rwtab[i], token)) {
            return i;
        }
    }
    return 10;
}

void retract() {
    p_input--;
}
char *dtb() {
    return NULL;
}
void printError(const char *s) {
    printf("In line[%d]: %s\n", lineNum, s);
    fflush(stdout);
}
WORD *scaner() {
    WORD *myword=new WORD;
    myword ->typeNum=10;
    myword->word="";
    p_token=0;
    m_getch();
    getbc();
    if (letter()) {
        while (letter()||digit()) {
            concat();
            m_getch();
        }
        retract();
        myword->typeNum=reverse();
        myword->word=token;
        return myword;
    } else if (digit()) {
        while (digit()) {
            concat();
            m_getch();
        }
        retract();
        myword ->typeNum=SYN_CONST;
        myword->word=token;
        return myword;
    } else {
        switch (ch) {
            case '=':
                m_getch();
                if (ch=='=') {
                    myword->typeNum=SYN_EQ;
                    myword->word="==";
                    return myword;
                } else {
                    retract();
                    myword->typeNum=SYN_ASSIN;
                    myword->word="=";
                    return myword;
                }
            case '+':
                myword->typeNum=SYN_PLUS;
                myword->word="+";
                return myword;
            case '-':
                myword->typeNum=SYN_MINUS;
                myword->word="-";
                return myword;
            case '*':
                myword->typeNum=SYN_MUL;
                myword->word="*";
                return myword;
            case '/':
                m_getch();
                if (ch=='/') {
                    p_token=0;
                    concat();
                    for (; ch!='\n'; m_getch()) {
                        concat();
                    }
                    myword->typeNum=SYN_DOC;
                    myword->word=token;
                } else {
                    retract();
                    myword->typeNum=SYN_DIV;
                    myword->word="/";
                }
                return myword;
            case '(':
                myword->typeNum=SYN_LSBAC;
                myword->word="(";
                return myword;
            case ')':
                myword->typeNum=SYN_RSBAC;
                myword->word=")";
                return myword;
            case '[':
                myword->typeNum=SYN_LMBAC;
                myword->word="[";
                return myword;
            case ']':
                myword->typeNum=SYN_RMBAC;
                myword->word="]";
                return myword;
            case '{':
                myword->typeNum=SYN_LBBAC;
                myword->word="{";
                return myword;
            case '}':
                myword->typeNum=SYN_RBBAC;
                myword->word="}";
                return myword;
            case ',':
                myword->typeNum=SYN_COMMA;
                myword->word=",";
                return myword;
            case ':':
                myword->typeNum=SYN_COLON;
                myword->word=":";
                return myword;
            case ';':
                myword->typeNum=SYN_SEMICOLON;
                myword->word=";";
                return myword;
            case '>':
                m_getch();
                if (ch=='=') {
                    myword->typeNum=SYN_NL;
                    myword->word=">=";
                } else {
                    retract();
                    myword->typeNum=SYN_GT;
                    myword->word=">";
                }
                return myword;
            case '<':
                m_getch();
                if (ch=='=') {
                    myword->typeNum=SYN_NG;
                    myword->word="<=";
                } else {
                    retract();
                    myword->typeNum=SYN_LE;
                    myword->word="<";
                }
                return myword;
            case '!':
                m_getch();
                if (ch=='=') {
                    myword->typeNum=SYN_NE;
                    myword->word="!=";
                } else {
                    retract();
                    myword->typeNum=-1;
                    myword->word="ERROR";
                }
                return myword;
            case '\0':
                myword->typeNum=2000;
                myword->word="OVER";
                return myword;
            default:
                myword->typeNum=-1;
                myword->word="ERROR";
                return myword;
        }
    }
}


// 保存四元组
void addQuad(const char* rs, const char *a1, const char *op, const char *a2) {
    quad[quadCnt++]=emit(rs, a1, op, a2);
}
char* newTmp() {
    static int k=0;
    char *p, m[8];
    p=(char*)malloc(8);
    k++;
    itoa(k, m, 10);
    strcpy(p+1, m);
    p[0]='t';
    return p;
}

#define syn myword->typeNum

// 判断当前字符是否为所需字符
bool match(int needSyn, const char* needWord) {
    static char output[1000];
    if (syn==needSyn) {
        myword=scaner();
        return true;
    }
    sprintf(output, "lost %s", needWord);
    printError(output);
    return false;
}

// 因子处理
// 因子=常量|变量|(表达式)
char* factor() {
    char *fplace;
    fplace = (char*) malloc(12);
    strcpy(fplace, " ");
    if (syn==SYN_VAR) {
        strcpy(fplace, myword->word);
        myword=scaner();
    } else if (syn==SYN_CONST) {
        strcpy(fplace, myword->word);
        myword=scaner();
    } else if (syn==SYN_LSBAC) {
        myword=scaner();
        fplace=expression();
        match(SYN_RSBAC, ")");
    } else {
        printError("lost factor");
        kk=3;
    }
    return fplace;
}

// 项处理
// 项=因子 {(*|/) 因子}
char* term() {
    char opp[4], *eplace, *eplace2, *eplace1;
    memset(opp, 0, sizeof(opp));
    eplace=eplace1=factor();
    while (syn==SYN_MUL || syn==SYN_DIV) {
        strcpy(opp, myword->word);
        myword=scaner();
        eplace2=factor();
        eplace=newTmp();
        addQuad(eplace, eplace1, opp, eplace2);
        eplace1=eplace;
    }
    return eplace;
}

// 表达式处理
// 表达式=项 {(+|-)项}
char* expression() {
    char *tp, *ep2, *eplace, *tt;
    tp=(char*)malloc(12);
    ep2=(char*)malloc(12);
    eplace=(char*)malloc(12);
    tt=(char*)malloc(12);
    strcpy(eplace, term());
    // term();
    while (syn==SYN_PLUS || syn==SYN_MINUS) {
        if (syn==SYN_PLUS) *tt='+', *(tt+1)=0;
        if (syn==SYN_MINUS) *tt='-', *(tt+1)=0;
        myword=scaner();
        strcpy(ep2, term());
        strcpy(tp, newTmp());
        addQuad(tp, eplace, tt, ep2);
        strcpy(eplace, tp);
    }
    return eplace;
}

// 条件
// 条件= 表达式 关系运算符 表达式
void condition(int &etc, int &efc) {
    char op[3], *eplace1, *eplace2;
    char str[4];
    eplace1=expression();
    if (syn>=SYN_GT && syn<=SYN_NE) { // < <= > >= !=
        sprintf(op, "%s", myword->word);
        myword=scaner();
        eplace2=expression();
        etc=quadCnt;
        efc=quadCnt+1;
        sprintf(str, "j %s", op);
        addQuad("0", eplace1, str, eplace2);
        addQuad("0", "", "j", "");
    } else {
        printError("need < <= > >= !=");
    }
}

// 语句
// 语句=条件语句|赋值语句|循环语句
void statement(int &nChain) {
    int ntc, nfc;
    char tt[8], eplace[8];
    int nChainTmp, nwQuad;
    if (syn==SYN_VAR) {
        // 赋值语句： 变量=表达式
        strcpy(tt, myword->word);
        myword=scaner();
        match(SYN_ASSIN, "=");
        strcpy(eplace, expression());
        match(SYN_SEMICOLON, ";");
        addQuad(tt, eplace, "", "");
        nChain=0;
    } else if (syn==SYN_IF) {
        // 条件语句：if (条件) 语句块 
        match(SYN_IF, "if");
        match(SYN_LSBAC, "(");
        condition(ntc, nfc);
        bp(ntc, quadCnt); // 成立
        match(SYN_RSBAC, ")");
        statementBlock(nChainTmp);
        nChain=merg(nChainTmp, nfc); // 不成立
    } else if (syn==SYN_WHILE) {
        // 循环语句： while (条件) 语句块
        match(SYN_WHILE, "while");
        nwQuad=quadCnt;
        match(SYN_LSBAC, "(");
        condition(ntc, nfc);
        bp(ntc, quadCnt);
        match(SYN_RSBAC, ")");
        statementBlock(nChainTmp);
        bp(nChainTmp, nwQuad);
        sprintf(tt, "%d", nwQuad);
        addQuad(tt, "", "j", "");
        nChain=nfc;
    }
    
}
// 语句块
// 语句块= '{' 语句串 '}' 
void statementBlock(int &nChain) {
    match(SYN_LBBAC, "{");
    statementSequence(nChain);
    match(SYN_RBBAC, "}");
}
// 语句串
// 语句串=语句 {语句}
void statementSequence(int &nChain) {
    statement(nChain);
    while (syn==SYN_VAR || syn==SYN_IF || syn==SYN_WHILE) {
        bp(nChain, quadCnt); // 回填不成立
        statement(nChain);
    }
    bp(nChain, quadCnt);
    return;
}
// 程序
// 程序= 
// begin {
//    语句块
// }
void program() {
    int nchain=0;
    myword=scaner();
    match(SYN_BEGIN, "begin");
    statementBlock(nchain);
}
void lrparser() {
    program();
}
// 填充条件成立时的跳转位置
int merg(int p1, int p2) {
    int p, res;
    if (p2==0) res=p1;
    else {
        res=p=p2;
        while (atoi(quad[p].result)) {
            p=atoi(quad[p].result);
            sprintf(quad[p].result, "%d", p1);
        }
    }
    return res;
}
// 填充条件不成立是跳转位置
void bp(int p, int t) {
    int w, q=p;
    while (q) {
        w=atoi(quad[q].result);
        sprintf(quad[q].result, "%d", t);
        q=w;
    }
}