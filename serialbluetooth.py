import bluetooth

devices = bluetooth.discover_devices(lookup_names=true)

print(type(devices))

print("Devices found: %s" % len(devices))
for device in devices:
    print(item)
