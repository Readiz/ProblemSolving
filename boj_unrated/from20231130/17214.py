# Python Gosu project

#6x+6
instr = input()


if "x" in instr:
    xsplit = instr.split('x')
    coeff1 = xsplit[0]
    coeff2 = xsplit[-1]

    if coeff2 == "":
        

    print(coeff1)
    print(coeff2)
else:
    coeff = int(instr)
    if coeff == 1:
        print("x+W")
    elif coeff == -1:
        print("-x+W")
    else:
        print(str(coeff) + "x+W")



# if "x" in instr and ("+" in instr or "-" in instr):
#     if "+" in instr:
#         instr = instr.split('+')
#         coeff1 = int(instr[0].split('x')[0])
#         coeff2 = int(instr[1])
#     else:
#         instr = instr.split('+')
#         coeff1 = int(instr[0].split('x')[0])
#         coeff2 = int(instr[1])

#     coeff1 //= 2

#     if coeff1 == 1:
#         strcoeff1 = ""
#     elif coeff1 == -1:
#         strcoeff1 = "-"
#     else:
#         strcoeff1 = str(coeff1)
    
#     if coeff2 == 1:
#         strcoeff2 = "+"
#     elif coeff2 == -1:
#         strcoeff2 = "-"
#     else:
#         strcoeff2 = str(coeff2)
#         if coeff2 > 0:
#             strcoeff2 = "+" + strcoeff2
    
#     print(strcoeff1 + "xx" + strcoeff2 + "x+W")
# elif "x" in instr:
#     coeff1 = int(instr.split('x')[0])
#     coeff1 //= 2
#     if coeff1 == 1:
#         strcoeff1 = ""
#     elif coeff1 == -1:
#         strcoeff1 = "-"
#     else:
#         strcoeff1 = str(coeff1)
#     print(str(coeff1) + "xx+W")
# else:
#     coeff2 = int(instr)
#     if coeff2 == 0:
#         print("W")
#     elif coeff2 == 1:
#         print("x+W")
#     elif coeff2 == -1:
#         print("-x+W")
#     else:
#         print(str(coeff2) + "x+W")
