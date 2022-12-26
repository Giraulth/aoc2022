arr_x = []
arr_y = []

with open('day14.txt') as file:
    for line in file:
        tmp_arr = line.split(' -> ')
        for elt in tmp_arr:
            arr_x.append(int(elt.split(',')[0]))
            arr_y.append(int(elt.split(',')[1].replace('\n','')))

print(max(arr_x))
print(max(arr_y))