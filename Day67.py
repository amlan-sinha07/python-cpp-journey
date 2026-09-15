import requests
import os
from dotenv import load_dotenv
load_dotenv()
api_token=os.getenv("API_TOKEN","default_secret")
url="https://postman-echo.com/post"
data= {
    "id":"101",
    "name":"Rahul",
    "branch":"CSE",
    "year":1
}
headers={
    "Authorization":f"Bearer {api_token}",
    "Content-Type":"application/json"
}
response=requests.post(url,
                       json=data,
                       headers=headers
                       )
print(response.status_code)
print(response.json())