#include <iostream>
using namespace std;
struct Score
{
	int kor, eng, mat;
	double avg;
};
void input(Score &r);
Score &average(Score &r);
int main()
{
	Score s;
	input(s);
	cout << "평균 점수" << average(s).avg << endl;
}

void input(Score &r)
{
	cout << "세 과목의 점수 입력 : ";
	cin >> r.kor >> r.eng >> r.mat;
}
Score &average(Score &r)
{
	int tot;
	tot = r.kor + r.eng + r.mat;
	r.avg = tot / 3.0;
	return r;
}