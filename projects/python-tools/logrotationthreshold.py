'''
Created on Feb 2, 2022

@author: kumarkud
'''

from os import walk
import os
from time import sleep

MaxStores = 2


def ignore(exclude_pattern: set, element:str) -> bool: 
    for p in exclude_pattern:
        if p in element:
            return False
    return True


def acceptable(include_pattern: set, element:str) -> bool: 
    for p in include_pattern:
        if p in element:
            return True
    return False


def get_directory_location() -> str:
    return "/var/log/d2d/ssid1/dedupe-logs"


def find_files_matching_pattern(include_pattern: set, exclude_pattern: set) -> list:
    dir_to_look_into = get_directory_location() 
    files = []
    for (__, __, filenames) in walk(dir_to_look_into):
        files.extend(filenames)
        break

    filtered_files = []
    for f in files:
        # print("file {} include_pattern {} exclude_pattern {}".format( f, include_pattern, exclude_pattern) )
        if acceptable(include_pattern, f):
            if ignore(exclude_pattern, f):
                filtered_files.append(f) 
        
    return filtered_files


def collectSamples(matching_files:list, tracker:dict):
    lastTime = {}
    if len(matching_files) > 0:
        matching_files.sort()
        for f in matching_files:
            for k in tracker.keys():
                if k in f:
                    lastTime[get_directory_location() + "/" + f] = 0
                    tracker[k].append(get_directory_location() + "/" + f)  
    else:
        print("No log Files in {}".format(*get_directory_location()))
        return

    for ltf in lastTime.keys():
        os.system("> {}".format(ltf))

    stime = 0
    samples = 0
    # Collect 10 iterations
    while samples < 10:
        stime += 1
        for k in tracker.keys():
            modified = 0
            for f in tracker[k]:
                stat = os.stat(f)
                fmTime = int(stat.st_mtime)
                if lastTime[f] != fmTime:
                    if lastTime[f] != 0:
                        modified += 1
                    lastTime[f] = fmTime
            if modified == len(tracker[k]):
                print("Key {} Modifications {} totalsize {} time {}".format(k, modified, len(tracker[k]), stime))
                stime = 0
                samples += 1
                for ltf in lastTime.keys():
                    os.system("> {}".format(ltf))
        sleep(1)

    
def benchmark_dedupe_logs():
    dedupe_include_pattern = {"log"}
    dedupe_exclude_pattern = {"log.bod", "log.ctr", "log.fs", "log.hkperf", "log.perf", "log.int" , "mgr" }
    
    tracker = {}
    for i in range(32):
        if i >= 0 and i <= MaxStores - 1:
            dedupe_include_pattern.add("store." + str(i) + ".log")
            tracker["store." + str(i) + ".log"] = []
        else:
            dedupe_exclude_pattern.add("store." + str(i) + ".log")

    matching_files = find_files_matching_pattern(dedupe_include_pattern, dedupe_exclude_pattern)
    collectSamples(matching_files, tracker)
    return
        

if __name__ == '__main__':
    benchmark_dedupe_logs()
