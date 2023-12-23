#내장함수
#itertools : 반복되는 형태의 데이터 처리
#heapq : 힙 자료구조 제공
#bisect : 이진탐색 기능 제공
#collections : deque, counter 등의 자료구조
#math : 필수적인 수학적 기능(팩토리얼, 제곱근, 최대공약수, 삼각함수 ...)

#내장함수
#sum
result = sum([1,2,3,4,5])
print(result) #15

#min,max
min_result = min(7,3,5,2)
max_result = max(7,3,5,2)
print(min_result,max_result)

#eval 
result = eval("(3+5)*7")
print(result) #56

#sorted
result = sorted([9,1,8,5,4])
reverse_result = sorted([9,1,8,5,4], reverse=True)

#sorted() with key
array = [('홍길동',50),('이순신',32),('아무개',74)]
result = sorted(array, key=lambda x: x[1], reverse=True)

#순열과 조합 
#순열 : 순서를 고려한 모든 경우 나열
from itertools import permutations
data = ['A','B','C'] #데이터 준비
result = list(permutations(data,3)) #모든순열구하기
print(result) #[('A', 'B', 'C'), ('A', 'C', 'B'), ('B', 'A', 'C'), ('B', 'C', 'A'), ('C', 'A', 'B'), ('C', 'B', 'A')]

#조합 : 모든 조합구하기
from itertools import combinations
data = ['A','B','C'] #데이터 준비
result = list(combinations(data,2)) 
print(result) #[('A', 'B'), ('A', 'C'), ('B', 'C')]

#중복순열
from itertools import product
data = ['A','B','C'] #데이터 준비
result = list(product(data,repeat=2)) #2개를 뽑는 모든 순열 구하기(중복허용)
print(result)

#중복조합
from itertools import combinations_with_replacement
data = ['A','B','C'] #데이터 준비
result = list(combinations_with_replacement(data,2)) #2개를 뽑는 모든 조합 구하기(중복허용)
print(result)

#counter : 등장 횟수를 세는 기능 제공
#리스트와 같은 반복 가능한 객체가 주어졌을 때 내부의 원소가 몇 번씩 등장했는지 알려준다.
from collections import Counter
counter = Counter(['red','blue','red','green','blue','blue'])
print(counter['blue']) #blue가 등장한 횟수 출력
print(dict(counter)) #사전 자료형으로 반환
#{'red': 2, 'blue': 3, 'green': 1

#최대공약수
import math

def lcm(a,b):
    return a*b // math.gcd(a, b) #//는 정수나눗셈연산자

a=21
b=14

print(math.gcd(21,14)) #최대공약수
print(lcm(21,14))#최소공배수