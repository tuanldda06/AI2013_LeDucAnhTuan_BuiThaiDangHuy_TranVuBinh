Bài 10  :
def giaipt():
    a = [True, False]
    for p in a:
        for q in a:
            for r in a:
                if (((not p) and (not q)) or r) == ((p ^ r) and q):
                    print(p, q, r)

giaipt()

