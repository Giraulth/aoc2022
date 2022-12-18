from functools import cmp_to_key

left_arr = []
right_arr = []
merge_arr = []
res = 0

def compare_list(left_arr, right_arr):
    if type(left_arr)==int and type(right_arr)==int:
        if left_arr<right_arr:
            return 1
        elif left_arr==right_arr:
            return 0
        else:
            return -1

    if type(left_arr)==list and type(right_arr)==list:
        max_len = max(len(left_arr), len(right_arr))
        for i in range(max_len):
            if i >= len(right_arr) and i<len(left_arr):
                return -1
            elif i >= len(left_arr) and i<len(right_arr):
                return 1
            ret = compare_list(left_arr[i], right_arr[i])
            if ret != 0:
                return ret
    elif type(left_arr)==int and type(right_arr)==list:
        new_arr = [left_arr]
        ret = compare_list(new_arr, right_arr)
        if ret != 0:
            return ret
    elif type(left_arr)==list and type(right_arr)==int:
        new_arr = [right_arr]
        ret = compare_list(left_arr, new_arr)
        if ret != 0:
            return ret

    return 0


with open('day13.txt') as file:
    i = 0
    for line in file:
        line = line[:-1]
        if line != '':
            i += 1
            if i % 2 == 0:
                right_arr.append(line)
            else:
                left_arr.append(line)
            merge_arr.append(line)

left_arr = [eval(x) for x in left_arr]
right_arr = [eval(x) for x in right_arr]
merge_arr = [eval(x) for x in merge_arr]
merge_arr.append([[2]])
merge_arr.append([[6]])

res = 0
min_arr = min(len(left_arr), len(right_arr))
for i in range(min_arr):
    ret = 0
    ret = compare_list(left_arr[i], right_arr[i])
    if ret == 1:
        res += i + 1
    ret = 0

print('Part1 : ' + str(res))

final_list = sorted(merge_arr, key=cmp_to_key(compare_list))
final_list.reverse()

decoder_one = final_list.index([[2]]) + 1
decoder_two = final_list.index([[6]]) + 1

print('Part2 : ' + str(decoder_one * decoder_two))