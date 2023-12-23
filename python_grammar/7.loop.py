#파이선에서는 while과 for가 있는데, 코딩테스트에서는 for문이 좀 더 간결한 경우가 많다??
i = 1
result = 0
while i <= 9:
    result += i
    i += 1
print(result)

#for문
#특정한 변수를 이용하여 in 뒤에오는 데이터에 포함되어 있는 원소를 첫번째 인덱스부터 하나씩 차례대로 방문

#for 변수 in 리스트,튜플 등:
    #실행할 소스코드

array = [9,8,7,6,5]
for x in array:
    print(x)

#for문에서 연속적인 값을 차례로 순회할 때는 range()을 주로 사용
#range(시작 값, 끝 값+1)
#인자를 하나만 넣으면 자동으로 시작값은 0

result = 0
for i in range(1,10): #1~9까지 순회
    result += i
print(result)

#continue
#반복문에서 남은 코드의 실행을 건너뛰고, 다음 반복을 진행할 때

#break
#반복문 즉시 탈출