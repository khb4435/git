#내장함수 : 파이선이 기본적으로 제공하는 함수
#사용자 정의 함수 : 개발자가 직접 정의하여 사용하는 함수

# def 함수명(매개변수):
#     실행할 소스코드
#     return 반환 값

#global키워드 : 함수 밖에 선언된 전역변수 사용시
a = 0
def func():
    global a
    a += 1

#단순 전역변수 출력일 경우 global 키워드 없어도됌
def func2():
    print(a)

#리스트가 외부에 선언된 것 사용시, global없어도됌
array = [1,2,3,4,5]
def func3():
    array.append(6)
    print(array)

#파이선에서는 함수가 여러 반환값을 가질 수 있다.
def operator(a,b):
    add_var = a+b
    subtract_var = a-b
    multiply_var = a*b
    divide_var = a/b
    return add_var, subtract_var, multiply_var, divide_var

a,b,c,d = operator(7,4)

#람다표현식
#람다표현식을 이용하면 함수를 간단하게 작성할 수 있음
#특정한 기능을 수행하는 함수를 한 줄에 작성할 수 있다는 점이 특징 
#람다표현식 : 한 줄의 함수 ??
def add(a,b):
    return a+b
print(3,7)

print((lambda a,b: a+b)(3,7)) # lambda 매개변수: 리턴값 (실제값)

#람다표현식 예시 : 내장함수에서 자주 사용되는 람다 함수
#sorted함수는 원래가 sorted(정렬할 리스트,key=) 이렇게생김
array = [('홍길동',50),('이순신',32),('아무개',74)]
def my_key(x):
    return x[1]
#점수순으로 오름차순 정렬
print(sorted(array, key = my_key))
print(sorted(array,key = lambda x: x[1]))

#람다 표현식 예시 : 여러개의 리스트에 적용
list1 = [1,2,3,4,5]
list2 = [6,7,8,9,10]
result = map(lambda a,b : a+b, list1, list2)
print(list(result))