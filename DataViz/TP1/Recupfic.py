from urllib.request import Request, urlopen
from bs4 import BeautifulSoup, Comment
import time
import re


# Create/open a file called wunder_ny.txt (which will be a comma-delimited file)
f = open('wunder_ny.txt', 'w')
# Iterate through months and day : during test only first the second day of january
for m in range(1, 13): #for m in range(1, 13):
    for d in range(1, 32): # for d in range(1, 32):
        # Check if already gone through month
        if (m == 2 and d > 28):
            break
        elif (m in [4, 6, 9, 11] and d > 30):
            break
        #Note the timestamp
        timestamp = '' + str(d) + '-' + str(m) + '-2019 '
        #print("Getting data for " + timestamp)
        req = Request('https://www.historique-meteo.net/france/nord-pas-de-calais/lille/2020-08-01/'+ str(m) + "-" + str(d), headers={'User-Agent': 'Mozilla/5.0'})
        page = urlopen(req).read()
        # Get the soup
        soup = BeautifulSoup(page,"html.parser")
        # TODO Modify in order to got the High Temp value
        
        
        
        
        tbody = soup.select(" > div > div > div.col-lg-8 > table > tbody > tr:nth-child(1) > td.text-center.bg-primary > b")
        
        
        print(d, "/", m, "/ 2019 : ",  str(tbody))
        # TODO : Register the timestamp in the output file in addition to the hight temp
        #f.write(timestamp + ',' + highTemp + '\n')
        # Sleep 2 seconds between 2 requests in order to prevent being listed as a spammer
        time.sleep(2)
        # Done getting data! Close file.
Print("Fin Processus")
f.close()