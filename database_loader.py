import MySQLdb
from csv import DictReader
import ipdb

conn = MySQLdb.connect(host="tailwagz.cfvove2ohkes.ap-southeast-2.rds.amazonaws.com", user="admin", passwd="masterpassword", db="tailwagz")
x = conn.cursor()

csvfile = open('dog-parks.csv')
rows = list(DictReader(csvfile))
ipdb.set_trace()
insert_stmt = "INSERT INTO parks (parkid, suburb, street, latitude, longitude, name) VALUES ({}, \"{}\", \"{}\", {}, {}, \"{}\")"

for row in rows:
	stmt = insert_stmt.format(row['id'], row['Suburb'], row['Street'], row['Latitude'], row['Longitude'], row['Dog Park Name'])
	x.execute(stmt)

conn.commit()