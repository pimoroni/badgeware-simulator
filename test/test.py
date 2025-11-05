from picovector import screen, io

def test():
    print(globals())
    print(f"UPDATE: Buttons: {io.pressed(io.BUTTON_A)}")