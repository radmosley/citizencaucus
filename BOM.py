with open('database.json', 'rb') as f:
    contents = f.read()
    contents = contents.decode("utf-16")

with open('database-B.json', 'w', encoding='utf-8') as f:
    f.write(contents)