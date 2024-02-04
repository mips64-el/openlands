import sys
import os
import random
import string
import hashlib

chunk_size = 1024
current_path = os.getcwd() + '/'

embed_file = current_path + sys.argv[1]
embed_c = current_path + sys.argv[2]
struct_name = embed_file.replace(os.path.abspath(sys.argv[3]) + '/', '').replace('.', '_').replace('/', '_')

size = os.path.getsize(embed_file)

with open(embed_file, 'rb') as f:
    with open(embed_c, 'w') as output_c:
        output_c.write('#include "../../embed.h"\n')
        output_c.write(f'Embed {struct_name} = {{{size}, (const uint8_t[]) {{')
        while 1:
            chunk = f.read(chunk_size)
            if not chunk:
                break
            output_c.write(','.join([str(chunk[i]) for i in range(len(chunk))]))
        output_c.write('}};\n')

