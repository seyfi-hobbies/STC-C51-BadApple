import serial
import time
ser = serial.Serial('COM11',115200)

#This program tries to keep avg frame rate to this constant
#max frame rate can be around 15 because of serial communication speed
FRAME_RATE = 9.98  #this is calculated by a YouTube bad apple video, 2195/total seconds. 


with open("badAppleLow.bin", "rb") as f:
    start_time = time.time()
    frameCnt = 1
    bytes_read = f.read(640)
    delta = 0.0
    while bytes_read:
        ser.write(bytes_read) 
        bytes_read = f.read(640) 
        end_time = time.time()
        diff = end_time - start_time
        avg = frameCnt/diff
        #print(str(frameCnt)+" frame Time elapsed: ", diff, "Avg frame/second="+str(avg))
        frameCnt += 1
        if frameCnt > 2180:
            break;
        if (avg <= FRAME_RATE):
            #speed up
            delta -= 0.001
        else:
            delta += 0.001
        if (delta > -0.048):    
            time.sleep(0.048+delta)
        
        ch = ser.read()
       
"""
2184 frame Time elapsed:  139.60000896453857 Avg frame/second=15.644698135762894
2185 frame Time elapsed:  139.66399908065796 Avg frame/second=15.644690216396647
2186 frame Time elapsed:  139.72764444351196 Avg frame/second=15.64472090477228
2187 frame Time elapsed:  139.79083395004272 Avg frame/second=15.644802582561113
2188 frame Time elapsed:  139.8563370704651 Avg frame/second=15.64462537652191
2189 frame Time elapsed:  139.9200837612152 Avg frame/second=15.644644722595388
2190 frame Time elapsed:  139.9838879108429 Avg frame/second=15.644657629418269
2191 frame Time elapsed:  140.04741716384888 Avg frame/second=15.644701233130442
2192 frame Time elapsed:  140.11189651489258 Avg frame/second=15.644638710368259
2193 frame Time elapsed:  140.17590355873108 Avg frame/second=15.644628957794975
2194 frame Time elapsed:  140.23975253105164 Avg frame/second=15.644636847987938
2195 frame Time elapsed:  140.30357265472412 Avg frame/second=15.644647947787613
2196 frame Time elapsed:  140.36694765090942 Avg frame/second=15.644708649371077
"""       