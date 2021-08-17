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
                cout << "(しりとり:1,オセロ:2,ゲームやめる:3):";
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
                    cout << "(現在作成中です。)" << endl;
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