import serial
import sys
import glob

DEFAULT_BAUD_RATE = 115200

def serial_ports():
    """ Lists serial ports names

    :raises EnvrionmentError:
        on unsupported or unknown platforms
    :returns:
        A list of serial ports available on the system
    """
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (OSError, serial.SerialException):
            pass
    return result

def testSerialPorts(serialPorts=SerialPorts(), baudRate=DEFAULT_BAUD_RATE, timeout=1):
    for port in serialPorts:
        with serial.Serial(port, baudRate, timeout) as ser:
            x = ser

if __name__ == '__main__':

