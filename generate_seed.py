from random import randint


seed = ''
room_type = [x for x in range(2, 7)]
stop = 3

direction_map = { 'n': 's', 's': 'n', 'e': 'w', 'w': 'e' }

def generate_map(filter=[]):
    global seed, stop

    stop -= 1

    if stop == 0:
        return

    directions = [ 'n', 's', 'e', 'w' ]
    for dir in filter:
        directions.remove(dir)

    for _ in range(randint(1, 4)):
        if len(directions) > 0:
            selected_room = room_type[randint(0, len(room_type) - 1)]
            selected_direction = directions[randint(0, len(directions) - 1)]
            directions.remove(selected_direction)
            seed += f'{selected_room}{selected_direction}'

            if randint(0, 1) == 1:
                # add new node 
                generate_map([direction_map[selected_direction]])
            else:
                seed += 't'

generate_map()

print(seed)