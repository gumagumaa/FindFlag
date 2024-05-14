import requests
import json

res = requests.get('https://www.wpnews.kro.kr/api/article/list')
response = json.loads(res.text)

outputjson = response[0]

print("flag: %d%s%d" %(len(response), outputjson['id'][:3], outputjson['editdate'] // 1000000000000))