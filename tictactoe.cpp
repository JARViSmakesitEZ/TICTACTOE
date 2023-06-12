#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
char board[3][3]={{ '1', '2', '3' },{ '4' , '5' , '6' },{ '7' , '8' , '9' } };

int canwin(int& count){
    if(count%2==0){
        if((board[0][1]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][2]=='X' || board[1][0]=='X' && board[2][0]=='X') && (board[0][0]=='1')){
            return 1;
        }
        else if((board[0][0]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][1]=='X') && (board[0][1]=='2')){
            return 2;
        }
        else if((board[0][1]=='X' && board[0][0]=='X' || board[1][1]=='X' && board[2][0]=='X' || board[1][2]=='X' && board[2][2]=='X') && (board[0][2]=='3')){
            return 3;
        }
        else if((board[0][0]=='X' && board[2][0]=='X' || board[1][1]=='X' && board[1][2]=='X') && (board[1][0]=='4')){
            return 4;
        }
        else if((board[0][0]=='X' && board[2][2]=='X' || board[0][2]=='X' && board[2][0]=='X' || board[1][0]=='X' && board[1][2]=='X' || board[0][1]=='X' && board[2][1]=='X') && (board[1][1]=='5')){
            return 5;
        }
        else if((board[0][2]=='X' && board[2][2]=='X' || board[1][0]=='X' && board[1][1]=='X') && (board[1][2]=='6')){
            return 6;
        }
        else if((board[1][0]=='X' && board[0][0]=='X' || board[1][1]=='X' && board[0][2]=='X' || board[2][1]=='X' && board[2][2]=='X') && (board[2][0]=='7')){
            return 7;
        }
        else if((board[2][0]=='X' && board[2][2]=='X' || board[1][1]=='X' && board[0][1]=='X') && (board[2][1]=='8')){
            return 8;
        }
        else if((board[2][0]=='X' && board[2][1]=='X' || board[1][2]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[0][0]=='X') && (board[2][2]=='9')){
            return 9;
        }
    }
    else{
        if((board[0][1]=='O' && board[0][2]=='O' || board[1][1]=='O' && board[2][2]=='O' || board[1][0]=='O' && board[2][0]=='O') && (board[0][0]=='1')){
            return 1;
        }
        else if((board[0][0]=='O' && board[0][2]=='O' || board[1][1]=='O' && board[2][1]=='O') && (board[0][1]=='2')){
            return 2;
        }
        else if((board[0][1]=='O' && board[0][0]=='O' || board[1][1]=='O' && board[2][0]=='O' || board[1][2]=='O' && board[2][2]=='O') && (board[0][2]=='3')){
            return 3;
        }
        else if((board[0][0]=='O' && board[2][0]=='O' || board[1][1]=='O' && board[1][2]=='O') && (board[1][0]=='4')){
            return 4;
        }
        else if((board[0][0]=='O' && board[2][2]=='O' || board[0][2]=='O' && board[2][0]=='O' || board[0][1]=='O' && board[2][1]=='O' || board[1][0]=='O' && board[1][2]=='O') && (board[1][1]=='5')){
            return 5;
        }
        else if((board[0][2]=='O' && board[2][2]=='O' || board[1][0]=='O' && board[1][1]=='O') && (board[1][2]=='6')){
            return 6;
        }
        else if((board[1][0]=='O' && board[0][0]=='O' || board[1][1]=='O' && board[0][2]=='O' || board[2][1]=='O' && board[2][2]=='O') && (board[2][0]=='7')){
            return 7;
        }
        else if((board[2][0]=='O' && board[2][2]=='O' || board[1][1]=='O' && board[0][1]=='O') && (board[2][1]=='8')){
            return 8;
        }
        else if((board[2][0]=='O' && board[2][1]=='O' || board[1][2]=='O' && board[0][2]=='O' || board[1][1]=='O' && board[0][0]=='O') && (board[2][2]=='9')){
            return 9;
        }
    }

    return -1;
}
int equal(char a,char b,char c){
    if(a==b && a==c){
        return 1;
    }
    return 0;
}

void reset(){
    board[0][0]='1';board[0][1]='2';board[0][2]='3';
    board[1][0]='4';board[1][1]='5';board[1][2]='6';
    board[2][0]='7';board[2][1]='8';board[2][2]='9';
}
void putin(int last,int count){
    int x,y;
    if(last==1){
        x=y=0;
    }
    else if(last==2){
        x=0;y=1;
    }
    else if(last==3){
        x=0;y=2;
    }
    else if(last==4){
        x=1;y=0;
    }
    else if(last==5){
        x=1;y=1;
    }
    else if(last==6){
        x=1;y=2;
    }
    else if(last==7){
        x=2;y=0;
    }
    else if(last==8){
        x=2;y=1;
    }
    else if(last==9){
        x=2;y=2;
    }
    if(count%2==0){
        board[x][y]='X';
    }
    else{
        board[x][y]='O';
    }
}
int position(int &x,int &y,int &a){
    cin>>a;
    if(a==1){
        x=0;y=0;
    }
    else if(a==2){
        x=0;y=1;
    }
    else if(a==3){
        x=0;y=2;
    }
    else if(a==4){
        x=1;y=0;
    }
    else if(a==5){
        x=1;y=1;
    }
    else if(a==6){
        x=1;y=2;
    }
    else if(a==7){
        x=2;y=0;
    }
    else if(a==8){
        x=2;y=1;
    }
    else if(a==9){
        x=2;y=2;
    }
    if(a>9 || a<1 || board[x][y]=='X' || board[x][y]=='O'){ 
        cout<<"INVALID INPUT , ENTER AGAIN..."<<endl;
        return 0;
    }
    return 1;

}
void beautify(){
    cout<<" -------------"<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(j==0){
                cout<<" | ";
            }
            cout<<board[i][j]<<" | ";
        }

        cout<<endl<<" -------------"<<endl;
    }
}


void multiplayer(){
    string p1,p2,last="";
    int count=0;
    cout<<"ENTER NAME FOR PLAYER1:";
    cin>>p1;
    cout<<"ENTER NAME FOR PLAYER2:";
    cin>>p2;
    cout<<"LET'S START!"<<endl;
    beautify();
    while(count<9){
        int x,y,success,a;
        if(count%2==0){
            cout<<p1<<" ENTER YOUR POSITION:";
            success=position(x,y,a);

            if(!success){
                continue;
            }
            board[x][y]='X';
            count++;
        }
        if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
            beautify();
            cout<<p1<<" IS THE WINNER!"<<endl;
            return;
        }
        beautify();
        if(count==9){
            break;
        }
        cout<<p2<<" ENTER YOUR POSITION:";
        success=position(x,y,a);
        if(!success){
            continue;
        }
        board[x][y]='O';
        if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
            beautify();
            cout<<p2<<" IS THE WINNER!"<<endl;
            return;
        }
        beautify();
        count++;
    }
    cout<<"IT'S A DRAW!"<<endl;
}
void jarvismove(int &count,int a){
    int x,y;
    static int last;
    if(!count){
        vector<int> v = { 1 , 3 , 5 , 9 , 7 };
        int random = rand() % v.size();
        last=v[random];
        putin(last,count);
        count++;
    }
    else if(count==1){
        if(a==5){
            vector<int> values = { 1 , 3 , 7 , 9 };
            int random = rand() % values.size();
            last=values[random];
            putin(last,count);
        }
        else if(a==1 || a==3 || a==7 || a==9){
            board[1][1]='O';
            last=5;
        }
        else if(a==2 || a==4 || a==6 || a==8){
            vector<int> values = { 1 , 3 , 7 , 9 , 5 };
            int random = rand() % values.size();
            last=values[random];
            putin(last,count);
        }
        count++;
    }
    else if(count==2){
        if(last==1){
            if(a==4){
                board[2][2]='X';
            }
            else if(a==2 || a==3){
                board[2][0]='X';
            }
            else if(a==6 || a==7 || a==8){
                board[0][2]='X';
            }
            else if(a==9){
                int temp=last;
                vector<int> values = { 3 , 7};
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==5){
                int temp=last;
                vector<int> values = { 2 , 3 , 4 , 6 , 8 ,  7 , 9 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
        }

        else if(last==3){
            if(a==6){
                board[2][0]='X';
            }
            else if(a==2 || a==1){
                board[2][2]='X';
            }
            else if(a==4 || a==8 || a==9){
                board[0][0]='X';
            }
            else if(a==7){
                int temp=last;
                vector<int> values = { 1 , 9};
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==5){
                int temp=last;
                vector<int> values = { 1 , 2 , 4 , 6 , 8 ,  7 , 9 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
        }

        else if(last==7){
            if(a==4){
                board[0][2]='X';
            }
            else if(a==8 || a==9){
                board[0][0]='X';
            }
            else if(a==6 || a==1 || a==2){
                board[2][2]='X';
            }
            else if(a==3){
                int temp=last;
                vector<int> values = { 9 , 1};
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==5){
                int temp=last;
                vector<int> values = { 1 , 2 , 3 , 4 , 6 , 8 , 9 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
        }

        else if(last==9){
            if(a==6){
                board[0][0]='X';
            }
            else if(a==8 || a==7){
                board[0][2]='X';
            }

            else if(a==4 || a==3 || a==2){
                board[2][0]='X';
            }

            else if(a==1){
                int temp=last;
                vector<int> values = { 7 , 3};
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==5){
                int temp=last;
                vector<int> values = { 1 , 2 , 3 , 4 , 6 , 8 ,  7 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
        }

        else if(last==5){
            if(a==4 || a==1){
                board[2][2]='X';
            }
            else if(a==6 || a==3){
                board[2][0]='X';
            }
            else if(a==2){
                int temp=last;
                vector<int> values = { 7 , 9 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==8){
                int temp=last;
                vector<int> values = { 1 , 3 };
                int random = rand() % values.size();
                last=values[random];
                putin(last,count);
            }
            else if(a==7){
                board[0][2]='X';
            }
            else if(a==9){
                board[0][0]='X';
            }

        }
        count++;
    }
    else if(count==3){
        if((board[0][1]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][2]=='X') && (board[0][0]=='1')){
            board[0][0]='O';
        }
        else if((board[0][0]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][1]=='X') && (board[0][1]=='2')){
            board[0][1]='O';
        }
        else if((board[0][0]=='X' && board[0][1]=='X' || board[1][1]=='X' && board[2][0]=='X') && (board[0][2]=='3')){
            board[0][2]='O';
        }
        else if((board[0][0]=='X' && board[2][0]=='X' || board[1][1]=='X' && board[1][2]=='X') && (board[1][0]=='4')){
            board[1][0]='O';
        }
        else if((board[0][1]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][2]=='X') && (board[1][1]=='5')){
            board[1][1]='O';
        }
        else if((board[1][1]=='X' && board[1][0]=='X' || board[0][2]=='X' && board[2][2]=='X') && (board[1][2]=='6')){
            board[1][2]='O';
        }
        else if((board[1][0]=='X' && board[0][0]=='X' || board[0][2]=='X' && board[1][1]=='X') && (board[2][0]=='7')){
            board[2][0]='O';
        }
        else if((board[1][1]=='X' && board[0][1]=='X' || board[2][0]=='X' && board[2][2]=='X') && (board[2][1]=='8')){
            board[2][1]='8';
        }
        else if((board[2][0]=='X' && board[2][1]=='X' || board[0][2]=='X' && board[1][2]=='X') && (board[2][2]=='9')){
            board[2][2]='O';
        }
        else if(board[1][1]=='X' && board[0][2]=='X' && board[2][0]=='O' || board[1][1]=='X' && board[2][0]=='X' && board[0][2]=='O'){
            vector<int> values = { 1 , 9 };
            int random = rand() % values.size();
            last=values[random];
            putin(last,count);
        }
        else if(board[1][1]=='X' && board[0][0]=='X' && board[2][2]=='O' || board[1][1]=='X' && board[2][2]=='X' && board[0][0]=='O'){
            vector<int> values = { 3 , 7 };
            int random = rand() % values.size();
            last=values[random];
            putin(last,count);
        }
        else{
            vector<int> temp;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]!='X' && board[i][j]!='O'){
                        if(i==0 && j==0){
                            temp.push_back(1);
                        }
                        else if(i==0 && j==1){
                            temp.push_back(2);
                        }
                        else if(i==0 && j==2){
                            temp.push_back(3);
                        }
                        else if(i==1 && j==0){
                            temp.push_back(4);
                        }
                        else if(i==1 && j==1){
                            temp.push_back(5);
                        }
                        else if(i==1 && j==2){
                            temp.push_back(6);
                        }
                        else if(i==2 && j==0){
                            temp.push_back(7);
                        }
                        else if(i==2 && j==1){
                            temp.push_back(8);
                        }
                        else if(i==2 && j==2){
                            temp.push_back(9);
                        }
                    }
                }
            }
            int random = rand() % temp.size();
            last=temp[random];
            putin(last,count);

        }
        count++;
    }
    else{
        last=canwin(count);
        if(last!=-1){
            putin(last,count);
            count++;
            return;
        }
        if((board[0][1]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][2]=='X' || board[1][0]=='X' && board[2][0]=='X' || board[0][1]=='O' && board[0][2]=='O' || board[1][0]=='O' && board[2][0]=='O' || board[1][1]=='O' && board[2][2]=='O') && (board[0][0]=='1')){
            if(count%2==0){
                board[0][0]='X';
            }
            else{
                board[0][0]='O';
            }
        }
        else if((board[0][0]=='X' && board[0][2]=='X' || board[1][1]=='X' && board[2][1]=='X' || board[0][0]=='O' && board[0][2]=='O' || board[1][1]=='O' && board[2][1]=='O') && (board[0][1]=='2')){
            if(count%2==0){
                board[0][1]='X';
            }
            else{
                board[0][1]='O';
            }
        }
        else if((board[0][0]=='X' && board[0][1]=='X' || board[1][1]=='X' && board[2][0]=='X' || board[1][2]=='X' && board[2][2]=='X' || board[0][0]=='O' && board[0][1]=='O' || board[1][2]=='O' && board[2][2]=='O' || board[1][1]=='O' && board[2][0]=='O') && (board[0][2]=='3')){
            if(count%2==0){
                board[0][2]='X';
            }
            else{
                board[0][2]='O';
            }
        }
        else if((board[0][0]=='X' && board[2][0]=='X' || board[1][1]=='X' && board[1][2]=='X' || board[0][0]=='O' && board[2][0]=='O' || board[1][1]=='O' && board[1][2]=='O') && (board[1][0]=='4')){
            if(count%2==0){
                board[1][0]='X';
            }
            else{
                board[1][0]='O';
            }
        }
        else if((board[0][1]=='X' && board[2][1]=='X' || board[1][2]=='X' && board[2][0]=='X' || board[1][0]=='X' && board[1][2]=='X' || board[0][0]=='X' && board[2][2]=='X' || board[0][1]=='O' && board[2][1]=='O' || board[1][2]=='O' && board[2][0]=='O' || board[1][0]=='O' && board[1][2]=='O' || board[0][0]=='O' && board[2][2]=='O' ) && (board[1][1]=='5')){
            if(count%2==0){
                board[1][1]='X';
            }
            else{
                board[1][1]='O';
            }
        }
        else if((board[1][1]=='X' && board[1][0]=='X' || board[0][2]=='X' && board[2][2]=='X' || board[1][1]=='O' && board[1][0]=='O' || board[0][2]=='O' && board[2][2]=='O') && (board[1][2]=='6')){
            if(count%2==0){
                board[1][2]='X';
            }
            else{
                board[1][2]='O';
            }
        }
        else if((board[1][0]=='X' && board[0][0]=='X' || board[0][2]=='X' && board[1][1]=='X' || board[2][1]=='X' && board[2][2]=='X' || board[1][0]=='O' && board[0][0]=='O' || board[0][2]=='O' && board[1][1]=='O' || board[2][1]=='O' && board[2][2]=='O') && (board[2][0]=='7')){
            if(count%2==0){
                board[2][0]='X';
            }
            else{
                board[2][0]='O';
            }
        }
        else if((board[1][1]=='X' && board[0][1]=='X' || board[2][0]=='X' && board[2][2]=='X' || board[1][1]=='O' && board[0][1]=='O' || board[2][2]=='O' && board[2][0]=='O') && (board[2][1]=='8')){
            if(count%2==0){
                board[2][1]='X';
            }
            else{
                board[2][1]='O';
            }
        }
        else if((board[2][0]=='X' && board[2][1]=='X' || board[0][2]=='X' && board[1][2]=='X' || board[0][0]=='X' && board[1][1]=='X' || board[1][1]=='O' && board[0][0]=='O' || board[0][2]=='O' && board[1][2]=='O' || board[2][0]=='O' && board[2][1]=='O')&& (board[2][2]=='9')){
            if(count%2==0){
                board[2][2]='X';
            }
            else{
                board[2][2]='O';
            }
        }
        else{
            vector<int> temp;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[i][j]!='X' && board[i][j]!='O'){
                        if(i==0 && j==0){
                            temp.push_back(1);
                        }
                        else if(i==0 && j==1){
                            temp.push_back(2);
                        }
                        else if(i==0 && j==2){
                            temp.push_back(3);
                        }
                        else if(i==1 && j==0){
                            temp.push_back(4);
                        }
                        else if(i==1 && j==1){
                            temp.push_back(5);
                        }
                        else if(i==1 && j==2){
                            temp.push_back(6);
                        }
                        else if(i==2 && j==0){
                            temp.push_back(7);
                        }
                        else if(i==2 && j==1){
                            temp.push_back(8);
                        }
                        else if(i==2 && j==2){
                            temp.push_back(9);
                        }
                    }
                }
            }
            int random = rand() % temp.size();
            last=temp[random];
            putin(last,count);

        }
        count++;
    }
}
void singleplayer(){
    string p,f;
    int a=999;
    cout<<"ENTER YOUR NAME:";
    cin>>p;
    cout<<"HI "<<p<<"! , YOU WILL BE PLAYING AGAINST JARVIS."<<endl;
    cout<<"WHO GOES FIRST? PRESS 1 FOR YOU AND ANYTHING ELSE FOR JARVIS:";
    cin>>f;
    int count=0;
    beautify();
    if(f=="1"){
        while(count<9){
            int x,y,success,a;
            cout<<p<<" ENTER YOUR POSITION:";
            success=position(x,y,a);
            if(!success){
                continue;
            }
            board[x][y]='X';
            count++;
            if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
                beautify();
                cout<<p<<" IS THE WINNER!"<<endl;
                return;
            }
            beautify();
            if(count==9){
                break;
            }
            cout<<"JARViS REPLIED.."<<endl;
            jarvismove(count,a);
            if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
                beautify();
                cout<<"JARViS IS THE WINNER!"<<endl;
                return;
            }
            beautify();
        }
        cout<<"IT'S A DRAW!"<<endl;
    }
    else{
        cout<<"JARViS REPLIED..."<<endl;
        jarvismove(count,a);
        beautify();
        while(count<9){
            int x,y,success,a;
            cout<<p<<" ENTER YOUR POSITION:";
            success=position(x,y,a);
            if(!success){
                continue;
            }
            board[x][y]='O';
            count++;
            if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
                beautify();
                cout<<p<<" IS THE WINNER!"<<endl;
                return;
            }
            beautify();
            if(count==9){
                break;
            }
            cout<<"JARViS REPLIED.."<<endl;
            jarvismove(count,a);
            if(equal(board[0][0],board[1][1],board[2][2]) || equal(board[0][2],board[1][1],board[2][0]) || equal(board[0][0],board[0][1],board[0][2]) || equal(board[1][0],board[1][1],board[1][2])  || equal(board[2][0],board[2][1],board[2][2]) || equal(board[0][0],board[1][0],board[2][0]) || equal(board[0][1],board[1][1],board[2][1]) || equal(board[0][2],board[1][2],board[2][2])){
                beautify();
                cout<<"JARViS IS THE WINNER!"<<endl;
                return;
            }
            beautify();
        }
        cout<<"IT'S A DRAW!"<<endl;
    }

}




void play(){
    cout<<"ENTER 1 IF YOU WOULD LIKE TO PLAY SINGLEPLAYER"<<endl;
    cout<<"ENTER 2 IF YOU WOULD LIKE TO PLAY MULTIPLAYER"<<endl;
    string a;
    cin>>a;
    if(a=="1"){
        singleplayer();
    }
    else if(a=="2"){
        multiplayer();
    }
    else{
        cout<<"INVALID INPUT..."<<endl;
    }
    cout<<"WOULD TO LIKE TO PLAY AGAIN?"<<endl;
    cout<<"PRESS 1 IF YES OR ANYTHING ELSE IF NO:";
    cin>>a;
    if(a=="1"){
        cout<<endl<<endl;
        reset();
        play(); 
    }
}
int main(){
    play();
    
}