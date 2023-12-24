#input함수는 한줄의 문자열을 입력 받는 함수
#map함수는 리스트의 모든 원소에 각각 특정한 함수를 적용할 때 사용
#map(함수, 리스트)

print('map test start')
def square(x):
    return x*x
a,b,c = map(square,[1,2,3])
print(a,b,c)
print('map test end')

#공백을 기준으로 구분된 데이터를 입력 받을 때는 다음과 같이
#input().split()은 사용자로부터 입력을 받아 공백을 기준으로 문자열을 분리한 후, 그 결과를 리스트로 반환
list(map(int, input().split()))

#공백을 기준으로 구분된 데이터의 개수가 많지 않다면
a,b,c = map(int, input().split())

#데이터의 개수 입력
n = int(input())
#각 데이터를 공백을 기준으로 구분하여 입력
data = list(map(int, input().split()))

data.sort(reverse=True)
print(data)

#사용자로부터 입력을 최대한 빠르게 받아야 하는 경우
#sys라이브러리에 정의되어 있는 sys.stdin.readline() 이용
#단, 입력 후 엔터가 줄 바꿈 기호로 입력되므로 rstring() 을 함께 사용한다. #얼스트립

import sys
#문자열 입력 받기
data = sys.stdin.readline().rstrip()
print(data)


#표준출력
#기본은 print
#각 변수를 콤마를 이용하여 띄어쓰기로 구분하여 출력할 수 있다.
#print는 기본적으로 출력 이후에 줄 바꿈 수행
#줄 바꿈 원치 않을 경우, 'end'속성 이용할 수 있다.

#출력할 변수들
a = 1
b = 2
print(a,b)
print(7, end= " ")
print(8, end= " ")

answer = 7
print("정답은 " + str(answer) + "입니다.")
print("정답은 ",answer,"입니다2.")

#파이선 3.6부터 'f'스트링
answer = 7
print(f"정답은 {answer}입니다.")

