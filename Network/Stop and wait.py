# Write a Program to implement stop and wait protcol.
import random 
import time
frames = random.randint(1,20)
print("Number of Frames is",frames)
for i in range(1,frames+1):
  print("Sending Frame",i)
  x=random.randint(0,9)
  if x%2==0:
    print("Waiting for 1 Second")
    time.sleep(1)
    print("Sending Frame",i)
  print("ACK for Frame",i)
print("End of Stop and Wait Protocol")

