import RPi.GPIO as GPIO # ir sensor
GPIO.setmode(GPIO.BOARD)
GPIO.setup(3,GPIO.IN)
GPIO.setup(5,GPIO.out)

while True :
        var=GPIO.input(3)
        print(var)

        if(var==0):
            GPIO.output(5,True)
        else:
            GPIO.output(5,False)
GPIO.cleanup()
