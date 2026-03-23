N = int(input())
numList = map(int, input().split())
numCheck = [0 for _ in range(201)]
v = int(input())

for num in numList:
  numCheck[num + 100] += 1

print(numCheck[v + 100])
