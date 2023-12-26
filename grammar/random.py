#1.
#map은 반복연산을 해주는 파이선 내장함수?
#for, while아님 ?
#map은 for를 간결하게 해준다.
#map은 for로 다 대체가 가능하다.

#for문사용
a = [2,4,6,8,10,12,14,16,18,20]
a_square = []
for num in a:
    a_square.append(num**2)

#map사용 -> map(A,리스트) -> 모든 리스트에 대해서 A 연산 수행
a = [2,4,6,8,10,12,14,16,18,20]
a_square = list(map(lambda x:x**2, a))

area = ["seoul,605", "busan,770", "daegu,884",
        "incheon,1063", "gwangju,501", "daejeon,540", "ulsan,1062"]
names = list(map(lambda x:x.split(',')[0], area))
areas = list(map(lambda x:int(x.split(',')[1]), area))
    
