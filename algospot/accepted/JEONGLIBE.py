import re
import os

m = set()
N = int(input())
for _ in range(N):
    tokens = list(map(lambda x: x.strip(), re.split('[-._]', os.path.basename(input())[:-4])))
    if len(tokens) >= 3:
        tokens = tokens[1:]

    tokens = list(map(lambda x: x.upper(), tokens))
    m.add('_'.join(tokens))

print(len(m))
