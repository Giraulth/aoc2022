from anytree import Node, RenderTree

dict_node = {}

current_dir = "/root"
dict_node["/root"] = Node("root")
cnt = 0
while True:

    cmd = input()

    if 'dir ' in cmd:
        cnt += 1
        leave_name = cmd.split("dir ")[1]
        dict_node[current_dir + '/' + leave_name] = Node(leave_name, parent = dict_node[current_dir])
        print(dict_node)
    
    elif '$ cd' in cmd and '/' not in cmd:
        name = cmd.split("$ cd ")[1]
        if name == "..":
            current_dir = current_dir.rsplit('/', 1)[0]
        else:
            current_dir += '/' + name


    elif cmd[0].isnumeric():
        size = cmd.split(' ')[0]
        Node(size, parent = dict_node[current_dir])

    
    if cmd == 'end':

        res_map = []
        for elt in dict_node:
            res = 0
            for node in RenderTree(dict_node[elt]):
                if node.node.name.isnumeric():
                    res += int(node.node.name)
            res_map.append(res)

        
        print(sum(x for x in res_map if x <= 100000))
