import requests
import json

print("Discord 작동 상태 확인 중...")
res = requests.get('https://discordstatus.com/api/v2/status.json')
response = json.loads(res.text)

nowstring = response['page']['updated_at'].split('T')
nowstring = nowstring[0].split('-')
print("Discord 작동 상태 확인 종료")

if response['status']['indicator'] == 'none':
    print("Discord 상태 : 좋음")
elif response['status']['indicator'] == 'major':
    print("Discord 상태 : 주요 문제 발생")
elif response['status']['indicator'] == 'partial':
    print("Discord 상태 : 부분적 고장")
elif response['status']['flag'] == '277a10':
    print("Discord 상태 : 디미고")

print("기준: %s년 %s월 %s일" %(nowstring[0], nowstring[1], nowstring[2]))