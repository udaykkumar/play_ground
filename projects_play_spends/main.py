'''
Created on Dec 28, 2021

@author: kumarkud
'''

from csv import reader
from os import walk
import re

def isDate(s: str) -> bool:
    if "/" in s:
        dt = s.split("/")
        if len(dt) == 3 :
            #print(dt[0], dt[1], dt[2])
            return True
        
    return False

def isNum(s : str) -> bool:
    if "-" in s :
        return False
    return True

def get_directory_location() -> str:
    # print( os.getcwd() )
    return "C:\\Users\\kumarkud\\Downloads"


def find_csv_files() -> list :
    dir_to_look_into = get_directory_location() 
    #print( dir_to_look_into );
    files = []
    for (__, __, filenames) in walk(dir_to_look_into):
        files.extend(filenames)
        break

    csv_files = []
    for f in files:
        if f.endswith("csv"):
            csv_files.append(f)
        
    return csv_files


spendsdictionary = {}
dipositsdictionary = {}
balanceDictionary = {}

def updateSpends(key : str, value : float ) :
    if key not in spendsdictionary:
        spendsdictionary[key] = float(0)
    spendsdictionary[key] += value


def updateDeposits(key : str, value : float ) :
    if key not in dipositsdictionary:
        dipositsdictionary[key] = float(0)
    dipositsdictionary[key] += value
    

def updateBalance(key : str, value : float ) :
    if key not in balanceDictionary:
        balanceDictionary[key] = float(0)
    balanceDictionary[key] = balanceDictionary[key] + value
    
    
def process(files: list) :
    for file in files:
        file = get_directory_location( ) + "\\" + file
        with open(file, 'r') as read_obj:
            csv_reader = reader( read_obj )
            for row in csv_reader:
                if len(row) > 0 and len(row) > 2:
                    if isDate(row[0]) and isNum(row[2]):
                        dd = row[0].split("/")[0]
                        mm = row[0].split("/")[1]
                        yy = row[0].split("/")[2]
                        key = mm + "/" +  yy
                        if "." in row[2]:
                            val = row[2].split(".")[0]
                        else:
                            val = row[2]
                        if "UDAY KUMAR" in row[1]:
                            continue
                        if "KALYANI" in row[1]:
                            continue
                        if "Fixed Deposit" in row[1]:
                            continue
                        
                        
                        val = float(row[2])
                        if int(val) > 100000:
                            print (" Breach ") 
                        #print( key, val )
                        updateSpends(key, val)
                
                if len(row) > 0 and len(row) > 3:
                    if isDate(row[0]) and isNum(row[3]):
                        dd = row[0].split("/")[0]
                        mm = row[0].split("/")[1]
                        yy = row[0].split("/")[2]
                        key = mm + "/" +  yy
                        if "." in row[3]:
                            val = row[3].split(".")[0]
                        else:
                            val = row[3]
                        if "UDAY KUMAR" in row[1]:
                            continue
                        if "KALYANI" in row[1]:
                            continue
                        if "Fixed Deposit" in row[1]:
                            continue
                        
                        
                        val = float(row[3])
                        #if int(val) > 100000:
                        #    print (" Breach ") 
                        #print( key, val )
                        updateDeposits(key, val)
                    
                    
                if len(row) > 0 and len(row) > 4:
                    if isDate(row[0]) and isNum(row[4]):
                        dd = row[0].split("/")[0]
                        mm = row[0].split("/")[1]
                        yy = row[0].split("/")[2]
                        key = mm + "/" +  yy
                        if "." in row[4]:
                            val = row[4].split(".")[0]
                        else:
                            val = row[4]
                        
                        #print( row[1] )
                        if "NEFT" not in row[1]:
                            continue
                        print( row[1] )
                        
                        val = float(row[4])
                        #if int(val) > 100000:
                        #    print (" Breach ") 
                        #print( key, val )
                        updateBalance(key, val)
    print("spends")
    for k, v in spendsdictionary.items():
        print (k, int(v))
        
    print("deposits")
    for k, v in dipositsdictionary.items():
        print (k, int(v))

    print("Balance")
    for k, v in dipositsdictionary.items():
        print (k, int(v))
        
    return

def start():
    csv_files = find_csv_files()
    if len(csv_files) > 0 :
        process( csv_files )
        
    else:
        print("No CSV Files in {}", get_directory_location())

if __name__ == '__main__':
    
    start()