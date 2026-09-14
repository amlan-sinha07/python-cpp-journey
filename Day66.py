import json
import requests
import os
from dotenv import load_dotenv
load_dotenv()
api_key=os.getenv("API_KEY","default_secret")

if not api_key:
    raise RuntimeError("CRITICAL: API_KEY environment variable is missing.")
print("API key loaded succesfully")
url="https://pokeapi.co/api/v2/pokemon/?offset=1&limit=10"
headers={
    "Authorization": f"Bearer {api_key}"
}
try:
    response=requests.get(url,headers=headers,timeout=5)
    print(f"Status Code : {response.status_code}")
    if response.status_code==200:
        print("request was succesfull")
        data=response.json()
        print(f"Data type: {type(data)}")
        print(json.dumps(data["results"][:10],indent=2))
    else:
        print(f"Request failed with HTTP status: {response.status_code}")
except requests.exceptions.Timeout:
    print("Request timeout after 5 seconds!")
except requests.exceptions.RequestException as e:
    print(f"An unexpected error occured {e}")

