//c++은 1초연산시 1억번

//알고리즘을 잘 선택했다면 시간초과는 이중반복문 제일 주시하기
//왜냐면 for문 5개 나오면 5N -> N
//이중 for문 -> N^2

//  배열 : 인덱싱은 0(1), 삽입/삭제는 0(N), 한 번 선언한 배열을 갑자기 늘릴 수 없음
//리스트 : 인덱싱은 0(N), 삽입/삭제는 0(1)
//  벡터 : 동적 배열!!**

#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> A;
	A.push_back(10);
	A.push_back(30);
	A.push_back(5);
	A.push_back(8);
	A.push_back(6);

	A.push_back(1);
	A.insert(A.begin(), 7);
	A.insert(A.begin() + 2, 10);

	A[4] = -5;

	A.pop_back();
	A.erase(A.begin() + 3);

	cout << A.size() << endl;
	cout << A.front() << endl;
	cout << A.back() << endl;
	cout << A[3] << endl;
	cout << A.at(3) << endl;

	A.clear();
}