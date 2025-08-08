import requests
from itertools import product

url = "http://10.10.43.55/game1/"
charset = "abcdefghijklmnopqrstuvwxyz"

known = ['G', 'a', '', 'e', '', '', 'e', '']  # vị trí ? để trống

for p in product(charset, repeat=4):  # thử 4 ký tự cho 4 dấu ?
    guess = known.copy()
    guess[2] = p[0]
    guess[4] = p[1]
    guess[5] = p[2]
    guess[7] = p[3]
    answer = ''.join(guess)
    res = requests.post(url, data={'answer': answer})
    if any(x in res.text.lower() for x in ['flag', 'correct', 'congrats']):
        print(f"[+] Found: {answer}")
        break
