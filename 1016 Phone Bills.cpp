#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
constexpr int MAXN = 1000;

struct Record {
	string name;
	int d, h, m, on;
} records[MAXN];

bool cmp(Record a, Record b) {
	if(a.name != b.name) return a.name < b.name;
	if(a.d != b.d) return a.d < b.d;
	if(a.h != b.h) return a.h < b.h;
	if(a.m != b.m) return a.m < b.m;
	return true;
}

int main(){
	int n, month, rate[24];
	int totalCharge, charge, time, flag;
	string status;
	for(int i = 0; i < 24; i++) cin >> rate[i];
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> records[i].name;
		scanf("%d:%d:%d:%d", &month, &records[i].d, &records[i].h, &records[i].m);
		cin >> status;
		records[i].on = (status == "on-line") ? 1 : 0;
	}
	sort(records, records+n, cmp);
	for(int i = 0, d, h, m; i < n; i++) {
		Record r = records[i];
		if(i == 0 || r.name != records[i-1].name) {
			d = h = m = -1;
			totalCharge = 0;
			flag = 0;
		}
		if(r.on) {
			d = r.d;
			h = r.h;
			m = r.m;
		}
		else{
			if(d != -1) {
				if(!flag) {
					flag = 1;
					printf("%s %02d\n", r.name.c_str(), month);
				}
				printf("%02d:%02d:%02d %02d:%02d:%02d ", d, h, m, r.d, r.h, r.m);
				charge = time = 0;
				while(d != r.d || h != r.h || m != r.m) {
					m++; time++;
					charge += rate[h];
					if(m == 60) h++, m = 0;
					if(h == 24) d++, h = 0;
				}
				d = h = m = -1;
				totalCharge += charge;
				printf("%d $%.02f\n", time, charge / 100.0);
			}
		}
		if((i == n-1 || records[i+1].name != r.name) && flag) {
			flag = 0;
			printf("Total amount: $%.02f\n", totalCharge / 100.0);
		}
	}
	return 0;
}