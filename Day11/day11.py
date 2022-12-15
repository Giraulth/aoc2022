curent_monkey = 0
item_map = {}
operation_map = {}
test_map = {}
true_map = {}
false_map = {}
delete_map = {}
inspected_map = {}

# parsing
with open('day11.txt') as file:
    for line in file:
        line = line[:-1]
        if 'Monkey' in line:
            current_monkey = int(line.split('Monkey ')[1][:-1])
            delete_map[current_monkey] = []
            inspected_map[current_monkey] = 0
        elif 'Starting items:' in line:
            item_map[current_monkey] = line.split('Starting items: ')[1].split(', ')
            item_map[current_monkey] = [int(x) for x in item_map[current_monkey]]
        elif 'Operation' in line:
            operation_map[current_monkey] = line.split('Operation: new = ')[1]
        elif 'Test' in line:
            test_map[current_monkey] = int(line.split('divisible by ')[1])
        elif 'true' in line:
            true_map[current_monkey] = int(line.split('monkey ')[1])
        elif 'false' in line:
            false_map[current_monkey] = int(line.split('monkey ')[1])

pgcd = 1
for x in test_map:
    print(test_map[x])
    pgcd *= test_map[x]
print(pgcd)

for i in range(10000):
    for item in item_map:
        for elt in item_map[item]:
            inspected_map[item] += 1
            old = elt
            new_item = int(eval(operation_map[item]))
            new_item %= pgcd
            # new_item = int(new_item/3)
            if new_item % test_map[item] == 0:
                item_map[true_map[item]].append(new_item)
                # print(f'{new_item} sent to {true_map[item]}')
            else:
                item_map[false_map[item]].append(new_item)
            #     print(f'{new_item} sent to {false_map[item]}')
            # print(delete_map)
        item_map[item] = []

    
print(item_map)
print(inspected_map)
sorted_inspection = sorted(inspected_map, key=inspected_map.get)
print(sorted_inspection)

print(inspected_map[sorted_inspection[len(sorted_inspection)-2]]*inspected_map[sorted_inspection[len(sorted_inspection)-1]])