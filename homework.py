import sqlite3

connection = sqlite3.connect("AnimalKingdom.db")

cursor = connection.cursor()

cursor.execute('''
    CREATE TABLE IF NOT EXISTS animals(
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEX NOT NULL,
        animal_type TEX NOT NULL
        )
       ''')

cursor.execute("delete from animals;")
cursor.execute("INSERT INTO animals (name, animal_type) VALUES ('Лев', 'ссавець') ")
cursor.execute("INSERT INTO animals (name, animal_type) VALUES ('крокодил', 'плазун') ")
cursor.execute("INSERT INTO animals (name, animal_type) VALUES ('орел', 'птах') ")
cursor.execute("INSERT INTO animals (name, animal_type) VALUES ('морська черепаха', 'плазун') ")
cursor.execute("INSERT INTO animals (name, animal_type) VALUES ('мавпа', 'ссавець') ")

connection.commit()

cursor.execute("SELECT * FROM animals")
rows = cursor.fetchall()

print('всі тварини')
for row in rows:
    print(row)

cursor.execute("select * from animals where animal_type = 'ссавець';")
rows = cursor.fetchall()

print('лише савці')
for row in rows:
    print(row)

connection.close()
