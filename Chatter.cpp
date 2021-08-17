#include <bits/stdc++.h>
using namespace std;

//しりとり言葉。nullは予約語。
vector<string> words = {"apple","android","age","agency","aisle","army","bean","ball","basketball","bit","bound","chocolate","clone","crane","crime","chrome","child","destiny","diamond","dog","dark","dilligent","drawn","deck","end","empire","estimate","finland","flow","find","finish","fast","glory","goal","germany","gain","gas","hill","hack","hat","hint","hall","intelligence","internet","india","immigrant","ignore","jail","journal","japan","jastice","kick","knowledge","king","korea","london","lock","logic","money","monster","minecraft","ministry","mother","name","needle","night","norway","nap","orange","orbit","opportunity","othero","old","purple","penguin","people","push","poison","pupil","query","quiet","quiz","question","rock","robbin","ring","read","rabit","road","resort","strawberry","spot","swing","student","stand","shark","shrine"
                    ,"train","traffic","tumor","table","tea","trouble","technology","tennis","top","thread","university","universe","union","vally","violin","victim","wish","wisdom","world","yellow","yell","yawn","young","zero"};

void falsein(bool &exit){
    cout << "死ね、言われたとおりにしろやカス" << endl;
    cout << "終わりにしたいんか？" << endl;
    cout << "(はい:1, いいえ:2, あ、間違えた一旦メンゴ:3):";
    string str;
    cin >> str;
    if(str=="1"){
        exit = true;
    }
    else if(str=="2") cout << "おk" << endl;
    else if(str=="3") cout << "うん、そうか乙～～wwwwww。馬鹿だからだよね(笑)" << endl;
    else falsein(exit);
}

/*
    check配列に含まれる座標
    0 1 2
    7 p 3
    6 5 4
    (始点はp)
*/
void should_check(vector<vector<char>> board,pair<int,int> put,vector<vector<pair<int,int>>> &check){
    check.assign(8,vector<pair<int,int>>(0));
    pair<int,int> c = put;
    while(c.first>0&&c.second>0){
        c.first--; c.second--;
        check[0].push_back(c);
    }
    c = put;
    while(c.first>0){
        c.first--;
        check[1].push_back(c);
    }
    c = put;
    while(c.first>0&&c.second<(board[0].size()-1)){
        c.first--; c.second++;
        check[2].push_back(c);
    }
    c = put;
    while(c.second<(board[0].size()-1)){
        c.second++;
        check[3].push_back(c);
    }
    c = put;
    while(c.first<(board.size()-1)&&c.second<(board[0].size()-1)){
        c.first++; c.second++;
        check[4].push_back(c);
    }
    c = put;
    while(c.first<(board.size()-1)){
        c.first++;
        check[5].push_back(c);
    }
    c = put;
    while(c.first<(board.size()-1)&&c.second>0){
        c.first++; c.second--;
        check[6].push_back(c);
    }
    c = put;
    while(c.second>0){
        c.second--;
        check[7].push_back(c);
    }
}

int main(){
    cout << "こんにちは、僕の名前はチャットマン！(僕って言っとけば良い奴感満載wwwww)" << endl;
    cout << "キミの名前は？(笑)" << endl;
    string name = "";
    cin >> name;
    cout << "へぇ、" << name << "っていうんだー(キメーなwww)" << endl;
    bool exit = false;
    while(!exit){
        cout << "何するわけ？" << endl;
        cout << "(ゲーム:1,会話:2,終了:3):";
        string x;
        cin >> x;
        if(x=="1"){
            while(!exit){
                cout << "で、何のゲームをしたいん？" << endl;
                cout << "(しりとり:1,オセロ:2,ゲームをやめる:3):";
                string y;
                cin >> y;
                if(y=="1"){
                    set<string> shiritori,said;
                    for(auto i : words) shiritori.insert(i);
                    vector<pair<string,bool>> shiri(0);
                    for(auto i : shiritori) shiri.push_back({i,false});
                    cout << "じゃあ俺からな" << endl;

                    string before;
                    char atama;
                    char tail;
                    for(int i = 0;i < shiri.size();i++){
                        if(shiri[i].first[shiri[i].first.size()-1]=='n') continue;
                        cout << "チャットマン:" << shiri[i].first << endl;
                        shiri[i].second = true;
                        before = shiri[i].first;
                        atama = shiri[i].first[shiri[i].first.size()-1];
                        break;
                    }

                    int winner = -1;        //1->AI負け,2->AI勝ち
                    while(winner==-1){
                        string str;
                        cout << name << ':';
                        cin >> str;
                        if(str[0]!=atama){
                            falsein(exit);
                            if(exit) break;
                            cout << "再開するぞ。おまえの番だ。" << before << "だからな。" << endl;
                            continue;
                        }
                        if(said.count(str)){
                            cout << "は?それ前に出た言葉だけど？？" << endl;
                            cout << "やりなおせカス" << endl;
                            continue;
                        }
                        said.insert(str);
                        tail = str[str.size()-1];

                        if(tail=='n'){
                            cout << "あれ???nじゃね????" << endl;
                            winner = 2;
                        }
                        else{
                            string ans = "null";
                            for(int i = 0;i < shiri.size();i++){
                                if((shiri[i].first[0]!=tail)||shiri[i].second||said.count(shiri[i].first)) continue;
                                ans = shiri[i].first;
                                shiri[i].second = true;
                                break;
                            }
                            if(ans=="null"){
                                cout << "くそっ、思いつかねえ..." << endl;
                                winner = 1;
                            }
                            else{
                                cout << "チャットマン:" << ans << endl;
                                if(ans[ans.size()-1]=='n'){
                                    cout << "ん？nで終わってるじゃん、やべ" << endl;
                                    winner = 1;
                                }
                                else{
                                    atama = ans[ans.size()-1];
                                    before = ans;
                                    said.insert(ans);
                                }
                            }
                        }
                    }
                    if(!exit){
                        if(winner==1) cout << "死ねーー死ね死ね" << name << "死ねーー" << endl;
                        if(winner==2) cout << "はい、乙ーー乙乙" << name << "乙ーー(あー泣いてもいいんだよ?????)" << endl;
                    }
                }
                else if(y=="2"){
                    vector<vector<char>> board(8,vector<char>(8,'.'));      //sizeは9x9が上限
                    board[3][3] = 'o'; board[3][4] = 'x';
                    board[4][3] = 'x'; board[4][4] = 'o';
                    cout << "じゃあ、" << name << "からだ。" << endl;

                    int winner = -1;        //1->AI負け,2->AI勝ち,3->引き分け
                    int maisa;
                    while(winner==-1){
                        cout << "---------------------------" << endl;

                        bool zokkou = false;
                        for(int i = 0;i < board.size();i++){
                            for(int j = 0;j < board[0].size();j++){
                                if(board[i][j]!='.') continue;

                                vector<pair<int,int>> ura_ = {};
                                vector<vector<pair<int,int>>> check_;
                                pair<int,int> put_ = make_pair(i,j);
                                should_check(board,put_,check_);

                                for(int k = 0;k < 8;k++){
                                    vector<pair<int,int>> kari_ura = {};
                                    for(int l = 0;l < check_[k].size();l++){
                                        if(board[check_[k][l].first][check_[k][l].second]=='x'){
                                            kari_ura.push_back(check_[k][l]);
                                        }
                                        else{
                                            if(kari_ura.size()&&board[check_[k][l].first][check_[k][l].second]=='o'){
                                                for(auto m : kari_ura) ura_.push_back(m);
                                            }
                                            break;
                                        }
                                    }
                                }

                                if(ura_.size()){
                                    zokkou = true;
                                }
                            }
                        }

                        if(!zokkou){
                            cout << "ん？置く場所もうねーじゃん" << endl;

                            //勝敗判定
                            int ai = 0,player = 0;
                            for(int i = 0;i < board.size();i++){
                                for(int j = 0;j < board[0].size();j++){
                                    if(board[i][j]=='o') player++;
                                    else ai++;
                                }
                            }
                            maisa = abs(ai-player);

                            if(ai>player) winner = 2;
                            else if(ai<player) winner = 1;
                            else winner = 3;
                            break;
                        }

                        cout << ' ';
                        for(int i = 0;i < board[0].size();i++) cout << i+1;
                        cout << endl;
                        for(int i = 0;i < board.size();i++){
                            cout << i+1;
                            for(auto j : board[i]) cout << j;
                            cout << endl;
                        }
                        cout << "どこに置きたいんだ？(チャットマンはx," << name << "はo)" << endl;
                        cout << "(縦,横の順番で半角空白区切りの半角数字を入力,オセロ終了はexit):";

                        string tate,yoko;
                        pair<int,int> put;
                        cin >> tate;
                        if(tate=="exit") break;
                        set<string> number = {"1","2","3","4","5","6","7","8","9"};
                        if(number.count(tate)){
                            put.first = stoi(tate);
                            put.first--;
                        }
                        else{
                            falsein(exit);
                            if(exit) break;
                            continue;
                        }
                        cin >> yoko;
                        if(number.count(yoko)){
                            put.second = stoi(yoko);
                            put.second--;
                        }
                        else{
                            falsein(exit);
                            if(exit) break;
                            continue;
                        }

                        vector<vector<pair<int,int>>> check;
                        should_check(board,put,check);
                        vector<pair<int,int>> ura = {};
                        for(int i = 0;i < 8;i++){
                            vector<pair<int,int>> kari_ura = {};
                            for(int j = 0;j < check[i].size();j++){
                                if(board[check[i][j].first][check[i][j].second]=='x'){
                                    kari_ura.push_back(check[i][j]);
                                }
                                else{
                                    if(kari_ura.size()&&board[check[i][j].first][check[i][j].second]=='o'){
                                        for(auto k : kari_ura) ura.push_back(k);
                                    }
                                    break;
                                }
                            }
                        }

                        if(ura.size()==0||board[put.first][put.second]!='.'){
                            cout << "おい、そこは置けねえだろうが。" << endl;
                            continue;
                        }

                        board[put.first][put.second] = 'o';
                        for(auto i : ura) board[i.first][i.second] = 'o';
                        cout << ' ';
                        for(int i = 0;i < board[0].size();i++) cout << i+1;
                        cout << endl;
                        for(int i = 0;i < board.size();i++){
                            cout << i+1;
                            for(auto j : board[i]) cout << j;
                            cout << endl;
                        }
                        cout << name << ':' << ura.size() << "枚裏返し！！" << endl;

                        vector<pair<int,int>> maxura = {};
                        pair<int,int> maxput = {-1,-1};
                        for(int i = 0;i < board.size();i++){
                            for(int j = 0;j < board[0].size();j++){
                                if(board[i][j]!='.') continue;

                                ura = {};
                                put = make_pair(i,j);
                                should_check(board,put,check);

                                for(int k = 0;k < 8;k++){
                                    vector<pair<int,int>> kari_ura = {};
                                    for(int l = 0;l < check[k].size();l++){
                                        if(board[check[k][l].first][check[k][l].second]=='o'){
                                            kari_ura.push_back(check[k][l]);
                                        }
                                        else{
                                            if(kari_ura.size()&&board[check[k][l].first][check[k][l].second]=='x'){
                                                for(auto m : kari_ura) ura.push_back(m);
                                            }
                                            break;
                                        }
                                    }
                                }

                                if(ura.size()>maxura.size()){
                                    maxput = put;
                                    maxura = {};
                                    for(auto k : ura) maxura.push_back(k);
                                }
                            }
                        }

                        if(maxput.first==-1&&maxput.second==-1){
                            cout << "ん？置く場所もうねーじゃん" << endl;

                            //勝敗判定
                            int ai = 0,player = 0;
                            for(int i = 0;i < board.size();i++){
                                for(int j = 0;j < board[0].size();j++){
                                    if(board[i][j]=='o') player++;
                                    else ai++;
                                }
                            }
                            maisa = abs(ai-player);

                            if(ai>player) winner = 2;
                            else if(ai<player) winner = 1;
                            else winner = 3;
                        }
                        else{
                            board[maxput.first][maxput.second] = 'x';
                            for(auto i : maxura) board[i.first][i.second] = 'x';
                            cout << ' ';
                            for(int i = 0;i < board[0].size();i++) cout << i+1;
                            cout << endl;
                            for(int i = 0;i < board.size();i++){
                                cout << i+1;
                                for(auto j : board[i]) cout << j;
                                cout << endl;
                            }
                            cout << "チャットマン:" << maxura.size() << "枚裏返し！！" << endl;
                        }
                    }
                    if(!exit){
                        if(winner==1){
                            cout << "は？お前方が" << maisa << "枚多いじゃん。うっざ。" << endl;
                        }
                        else if(winner==2){
                            cout << "草。俺の方が" << maisa << "枚多いwwwwざまぁwwwwww" << endl;
                        }
                        else if(winner==3){
                            cout << "引き分け！？なんか凄くねww" << endl;
                        }
                        else{
                            cout << "まじかよ。。" << endl;
                        }
                    }
                }
                else if(y=="3"){
                    cout << "は？wwwwま、いいけど。" << endl;
                    break;
                }
                else falsein(exit);
            }
        }
        else if(x=="2"){
            cout << "(現在作成中です。)" << endl;
        }
        else if(x=="3") exit = true;
        else{
            falsein(exit);
        }
    }
    cout << "は？マジかよw" << endl;
}