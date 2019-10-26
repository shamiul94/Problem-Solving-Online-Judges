def complexNumberMultiply(a, b):
    a = a.replace(" ", "")
    a = a.replace("i", "j")
    b = b.replace(" ", "")
    b = b.replace("i", "j")
    a = a.replace("--", "+")
    a = a.replace("-+", "-")
    a = a.replace("+-", "-")
    a = a.replace("++", "+")
    b = b.replace("--", "+")
    b = b.replace("-+", "-")
    b = b.replace("+-", "-")
    b = b.replace("++", "+")
    ca = complex(a)
    cb = complex(b)
    ans = (ca * cb)
    real = ans.real
    img = ans.imag
    ans = str(int(real)) + "+" + str(int(img)) + "i"
    return str(ans)


a = "1+1i"
b = "1+1i"

print(complexNumberMultiply(a, b))
