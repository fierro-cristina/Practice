//coordinates of black pixels are smaller than 10 and bigger than 1
//neighbors of the lowest left pixel are specified
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

#define MS(x,val)       memset(x,val,sizeof(x))

struct Point{
	int x, y;
	Point(int xx = 0, int yy = 0){
		x = xx;
		y = yy;
	}
}origin;

int n;
string ft;
bool v[15][15];

int conv(string str){
	int s = 0;
	int ten = 1;
	for(int i = str.length()-1; i >= 0; i--){
		s += (str[i]-'0')*ten;
		ten *= 10;
	}
	return s;
}

void getOriginXY(){
	string str = "";
	for(int i = 0; i < ft.length(); i++){
		if(ft[i] == ' '){
			origin.x = conv(str);
			str = "";
		}else str += ft[i];
	}
	origin.y = conv(str);
}

bool cmp(Point a,Point b){
	if(a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

void firstBFS(){
	vector<Point> ans;
	ans.push_back(origin);
	queue<Point> q;
	q.push(origin);

	while(cin >> ft && ft != "."){
		Point current = q.front();
		q.pop();
		for(int i = 0; i < ft.length()-1; i ++){
			Point next = current;
			if(ft[i] == 'R') next.x ++;
			else if(ft[i] == 'T') next.y ++;
			else if(ft[i] == 'L') next.x --;
			else next.y --;
			ans.push_back(next);
			q.push(next);
		}
	}

	sort(ans.begin(),ans.end(),cmp);

	printf("%d\n",ans.size());
	for(int i = 0; i < ans.size(); i ++) printf("%d %d\n",ans[i].x,ans[i].y);
}

const int X[] = {1,0,-1,0};
const int Y[] = {0,1,0,-1};
const char mark[] = {'R','T','L','B'};

void secondBFS(){
	queue<Point> q;
	q.push(origin);
	v[origin.x][origin.y] = false;
	vector<string> ans;

	while(!q.empty()){
		Point current = q.front();
		string str = "";
		q.pop();

		for(int i = 0; i < 4; i ++)	{
			Point next = current;
			next.x += X[i]; next.y += Y[i];
			if(v[next.x][next.y]){
				str += mark[i];
				q.push(next);
				v[next.x][next.y] = false;
			}
		}
		str += ',';
		ans.push_back(str);
	}

	ans[ans.size()-1] = ".";
	printf("%d %d\n",origin.x,origin.y);
	for(int i = 0; i < ans.size(); i ++) cout << ans[i] << endl;
}

int main(){
	getline(cin,ft);

	if(ft.length() > 2){
		getOriginXY();
		firstBFS();
	}
	else{
		MS(v,false);
		n = conv(ft);
		for(int i = 0; i < n; i ++){
			int x,y;
			scanf("%d %d",&x,&y);
			v[x][y] = true;
			if(i == 0){
				origin.x = x;
				origin.y = y;
			}
		}
		secondBFS();
	}
}
