def replaceExpression(s):
    s = s.replace('/', '//')
    s = s.replace('&&', ' and ')
    s = s.replace('||', ' or ')
    s = s.replace('!', ' not ')
    return s

def findCommandLine(program, cmd, pc):
    return pc + program[pc:].index(cmd)

while (True):
    N = int(input())
    if N == 0:
        break
    program = []
    expressions = []
    cmds = []
    for _ in range(N):
        curline = input()
        curline = curline.strip()
        program.append(curline)
        curcmds = curline.split(' ')
        if (curcmds[0] == 'end'):
            if (curcmds[1] == 'while'):
                cmds.append('end while')
            else:
                cmds.append('end if')
        else:
            cmds.append(curcmds[0])
        if (curcmds[0] == 'print') or (curcmds[0] == 'set') or (curcmds[0] == 'while') or (curcmds[0] == 'if'):
            expressions.append(replaceExpression(''.join(curcmds[1:])))
        else:
            expressions.append('')
    # print(program)
    # print(cmds)
    # print(expressions)

    # 프로그램 실행 준비
    pc = 0
    pcStack = []
    exec('a=0\nb=0\nc=0\nd=0\ne=0\nf=0\ng=0\nh=0\ni=0\nj=0\nk=0\nl=0\nm=0\nn=0\no=0\np=0\nq=0\nr=0\ns=0\nt=0\nu=0\nv=0\nw=0\nx=0\ny=0\nz=0')
    while (pc < N):
        # print('[CMD] ' + program[pc])
        if cmds[pc] == 'print':
            result = eval(expressions[pc])
            # print('[RESULT] ' + str(result))
            print(result)
        elif cmds[pc] == 'set':
            exec(expressions[pc])
        elif cmds[pc] == 'while':
            pcStack.append(pc)
            result = eval(expressions[pc])
            if result == 0: # False 인 Case
                # print('[WHILE] is false, skip caluse...')
                next = findCommandLine(program, 'end while', pc)
                pc = next + 1
                pcStack.pop()
                # print('[WHILE] go to ' + str(pc))
                continue
        elif cmds[pc] == 'end while':
            pc = pcStack.pop()
            # print('[WHILE] end, go to while start pos...')
            continue
        elif cmds[pc] == 'else':
            # print('[ELSE] found, jump to end if...')
            next = findCommandLine(program, 'end if', pc)
            pc = next + 1
            # print('[ELSE] go to ' + str(pc))
            continue
        elif cmds[pc] == 'if':
            result = eval(expressions[pc])
            # print('[RESULT] ' + str(result))
            if result == 0: # False인 Case
                nextElse = findCommandLine(program, 'else', pc)
                nextEndIf = findCommandLine(program, 'end if', pc)
                if (nextElse < nextEndIf):
                    pc = nextElse + 1
                    # print('[IF][ELSE] go to ' + str(pc))
                else:
                    pc = nextEndIf + 1
                    # print('[IF][EndIf] go to ' + str(pc))
                continue
        pc += 1
