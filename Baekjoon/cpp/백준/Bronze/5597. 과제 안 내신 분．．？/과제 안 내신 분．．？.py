check = [False for _ in range(30)]

for _ in range(28):
  student = int(input())
  check[student - 1] = True

for i, isCheck in enumerate(check):
  if not isCheck:
    print(i+1)