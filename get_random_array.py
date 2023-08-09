import random

a = list(range(512))

for i in range(256):
    index1 = random.randint(0,511)
    index2 = random.randint(0,511)
    if(index1 == index2):
        continue
    a[index1],a[index2] = a[index2], a[index1]

b = []
c = []
for element in a:
    if element > 255:
        b.append(element-256)
    else:
        c.append(element)

print(b)
print(c)