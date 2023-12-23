#리스트 []
#튜플 () 과 문자열
#사전 {key:value} 과
#집합 {A,B}

#리스트나 튜플은 순서가 있기 때문에 인덱싱을 통해 자료형을 얻을 수 있다.
#사전,집합자료형은 순서가 없기 때문에 인덱싱으로 값을 얻을 수  x
#사전의 키 혹은 집합의 원소를 이용해 0(1)의 시간 복잡도로 조회

#사전자료형{}은 key, value의 쌍을 데이터로 가지는 자료형이다.
#앞서 다루었던 리스트[]나 튜플()이 값을 순차적으로 저장하는 것과는 다르다.
#변경 불가능한 자료형을 키로 사용한다.
#파이선의 사전 자료형은 해시 테이블을 사용하므로 0(1)

data = dict()
data['사과'] = 'apple'
data['바나나'] = 'banana'
data['코코넛'] = 'coconut'
#   [  key   ] =  value
print(data) #{'사과':'apple','바나나'='banana','코코넛'='coconut'}

if '사과' in data:
    print("'사과'를 키로 가지는 데이터가 존재한다")

#사전 자료형에서는 키와 값을 별도로 뽑아내기 위한 메서드를 지원한다.
    #키 데이터만 뽑아서 리스트로 이용할 때는 keys()
    #값 데이터만 뽑아서 리스트로 이용할 때는 values()

key_list = data.keys()
values_list = data.values()
print(key_list) #dict_keys(['사과', '바나나', '코코넛'])
print(values_list)#dict_values(['apple', 'banana', 'coconut'])

#각 키에 따른 값을 하나씩 출력
for key in key_list:
    print(data[key])

#집합자료형
    #중복허용x
    #순서x
#집합은 리스트 혹은 문자열을 이용해서 초기화할 수 있음
    #set() 함수 사용
    #혹은 {A,B}
#데이터의 조회 및 수정에 0(1)
    
#집합자료형 초기화1
data = set([1,1,2,3,4,4,5]) #중복 원소는 제거됨
print(data) #{1, 2, 3, 4, 5}

#집합자료형 초기화2
data = {1,1,2,3,4,4,5}
print(data) #{1, 2, 3, 4, 5}

#기본적인 연산으로는 합집합,교집합,차집합 연산 등이 있다.
a = {1,2,3,4,5}
b = {3,4,5,6,7}
#합집합
print(a|b)
#교집합
print(a&b)
#차집합
print(a-b)

#기타 집합자료형 관련 함수
data = {1,2,3}
#새로운 원소 추가
data.add(4)
#새로운 원소 여러개 추가
data.update([5,6])
#특정한 값을 갖는 원소 삭제
data.remove(3)

