from random import randint

WIDTH, HEIGHT, OFFSET = 1920, 1080, 2

def generate_seed():
	'''
		SEED_STRUCTURE = <WIDTH><HEIGHT>
	'''

	_width = int(WIDTH / 64) - OFFSET
	_height = int(HEIGHT / 64) - OFFSET
	print(randint(_width / 2, _width))
	print(randint(_height / 2, _height))

generate_seed()