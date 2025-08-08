def shift_chars(text, pos):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    out = ""
    for letter in text:
        if letter in alphabet:
            letter_pos = (alphabet.find(letter) - pos) % 26  # Giải mã: lùi lại
            new_letter = alphabet[letter_pos]
            out += new_letter
        else:
            out += letter  # Giữ lại ký tự đặc biệt như {, }, số...
    return out

def decrypt_text(text):
    counter = 0
    decrypted_text = ""
    for i in range(0, len(text), 10):
        counter = (counter + 1) % 26
        block = text[i:i+10]
        decrypted_text += shift_chars(block, counter)
    return decrypted_text

# Nội dung đã mã hóa (dán từ file .encrypted)
encrypted = """?Rfdjqf Cbfuct Scncf
Iqjuhglhqxw
Fsv xlj Sfqfi:
- 1 rgxmk olhk vm Rvuiqvm tmbbdln, lqxyyon
- 1 mez nczfezyd (tayqympq be fgber-ociuvh)
- 0,5 rje Ppgcuiqd sxuujv, jyrmvu gj yjslwv
Fhk max Dlymmcha:
- 0,5 xpk iwukjjweob (lo 0,5 asn kywm + 0,5 bto Greek yoguru gps b mjijvgt xgtulrq)
- 2 wfwt piqsr oznhj (kwjynre ywakkglk)
- 1 aax Dqrwv udbcjam
- 1 dcz Wybmodepcdstcp emgoq
- 1 tneyvp pybjs, awbqsr
- 2 pcrwdlo vybbuji, wzevcp tzghhwv (gj 0,5 mli thwbips jumoz, jkodjiwh)
- 0,25 zrm lifsb mgj
- Syjs & akzbj pepper, to ubtuf
- b ftkbbng qi iodj{dg1g53fj1i00e9239i29jifgjijg2964}
Iuzaybjaqwva
Mism cqn Danbbsxq
- Ix l mzhw, hsuew fasqftre znlbaanwgs, zsacb yjxrt, Dxzed ckijqhu, Wfitvjkwjkzajw ksnvx, fbgvxx aulfcw, viy vixcjqeao.
- Shktiv aofwwic gl rfc mkhud nhk vhile whiskjoh up fnvnukha.
- Agg vdow dqh tittiv xt yfxyj.
Pxkvgxk znl Shshk
- Iv i tizon bjujm kxgv, dycc mszaapo Rzxmuzq xqffgpr jvgu pecihcbg obr Ppgbthpc sxuuiu.
Ajjvdscv
- Djarrdw lax wkxllbga ipyl nby nvgvy viy cajphu pkpp ql zlxq ctcpwrfglf dudmkx.
Serve Immfejbufmz
- Gctpkuj zlwk hawud Pevqiwer fsi hwtzytty ol jkyoylk.
- Euqwg eqbp ozruunm lqrluox, crbswa, zc dlwxaz rad m bebgrva obbgh!
"""

decrypted = decrypt_text(encrypted)

# Tìm flag
import re
flag = re.search(r'flag\{.*?\}', decrypted)
if flag:
    print(f"[+] FLAG tìm được: {flag.group(0)}")
else:
    print("[-] Không tìm thấy flag :(")