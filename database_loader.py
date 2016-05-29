import MySQLdb
from csv import DictReader
import ipdb

conn = MySQLdb.connect(host="fastapps04.qut.edu.au", user="n9438726", passwd="password1", db="n9438726")
x = conn.cursor()

csvfile = open('dog-parks.csv')
rows = list(DictReader(csvfile))
ipdb.set_trace()
insert_stmt = "INSERT INTO parks (parkid, suburb, street, latitude, longitude, name) VALUES ({}, \"{}\", \"{}\", {}, {}, \"{}\")"

for row in rows:
	stmt = insert_stmt.format(row['id'], row['Suburb'], row['Street'], row['Latitude'], row['Longitude'], row['Dog Park Name'])
	x.execute(stmt)

conn.commit()
