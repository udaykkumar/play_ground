
from os import walk


def get_directory_location() -> str:
    # print( os.getcwd() )
    return "/ch/workspace/Comp-4.3.2-2206.40-25s2/so272607bp/log/var/log/pml/daily"

def get_collectl_logs():
    dir_to_look_into = get_directory_location() 
    files = []
    for (__, __, filenames) in walk(dir_to_look_into):
        files.extend(filenames)
        break

    collectl_logs = []
    for f in files:
        if f.endswith(".log"):
            collectl_logs.append(get_directory_location() +"/"+ f)
        
    return collectl_logs


def analyse( file: str ) :
    #print("analysing ", file)
    with open(file, 'r') as read_obj:
        Lines = read_obj.readlines()
        count =0
        nlines=len(Lines)
         
        while count < nlines:
            line = Lines[count].strip()
            if line.startswith("### RECORD"):
                tarr = line.split()
                timestamp = tarr[8] + " " + tarr[9] + " " + tarr[10]
                #print("Line{}: {} {}".format(count, Lines[count].strip(), timestamp) )
                count += 1
                while count < nlines:
                    line = Lines[count].strip()
                    
                    if line.startswith("### RECORD"):
                        break
                    if line.startswith("# MEMORY SUMMARY"):
                        print("Line {} : {} ".format(timestamp, Lines[count+3].strip() ) )
                    count += 1
            else:
                count += 1    
                
    return

def parse():
    collectl_logs = get_collectl_logs()
    for log in collectl_logs:
        analyse(log)
        
    return

if __name__ == '__main__':
    parse()