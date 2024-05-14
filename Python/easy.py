import datetime
import time

name = input("이름을 입력해주세요 : ")
dimigo_good = ["학생 성적 분석 시스템 '베네듀'", "교내의 스마트팜", "좋은 품질의 방과후수업", "전공을 살리는 전공UP!"]

now = datetime.datetime.now()

print("%s님 안녕하세요!" %name)
datestring = now.strftime("%Y년 %m월 %d일")
timestring = now.strftime("%H시 %M분 %S초")
time.sleep(1)
print("오늘은 %s, 지금은 %s입니다." %(datestring, timestring))
time.sleep(1)
print("입학설명회에 오신 만큼, 디미고 장점을 나열해볼게요!")
time.sleep(1)
flag = 256842
for x in range(flag):
    print(dimigo_good[x % 4])
    time.sleep(1)