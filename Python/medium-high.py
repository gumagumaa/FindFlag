from bs4 import BeautifulSoup
import requests

url = 'https://ytn.co.kr'
response = requests.get(url)
html = response.text

soup = BeautifulSoup(html, 'html.parser')

ytsubscriber = soup.select('.icon.youtube > .number')
flag = ytsubscriber[0].text.replace('구독 ', '').replace(',', '')[1:7]
print("flag: %s" %flag)