# import cppmem

# Switch C++ memory allocations to use MicroPython's heap
# cppmem.set_mode(cppmem.MICROPYTHON)

# Copy default files from readonly /system to editable /
default_files = ["main.py", "secrets.py"]
buf = bytearray(256)

for filename in default_files:
    print(f"Copying {filename}")
    try:
        open(f"/{filename}", "r").read()
        open("/system/nocopy", "r").read()
    except OSError:
        with open(f"/system/{filename}", "r") as system_main:
            with open(f"/{filename}", "w") as main:
                while True:
                    length = system_main.readinto(buf)
                    if not length:
                        break
                    main.write(buf[:length])
