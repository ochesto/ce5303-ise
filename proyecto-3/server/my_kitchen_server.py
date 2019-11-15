from flask import Flask, jsonify
from gpio_manager import *

#CAMBIAR PINES
lights = ["17", "27", "22"]
kitchen = ["23", "24"]

export_pin(lights[0])
export_pin(lights[1])
export_pin(lights[2])
export_pin(kitchen[0])
export_pin(kitchen[1])

pin_mode(lights[0], "out")
pin_mode(lights[1], "out")
pin_mode(lights[2], "out")
pin_mode(kitchen[0], "out")
pin_mode(kitchen[1], "out")

is_light1_on = True
is_light2_on = True
is_light3_on = True
is_kitchen1_on = True
is_kitchen2_on = True


app = Flask(__name__)


@app.route("/firstled", methods=['POST'])
def manage_first_light():
    global is_light1_on
    state = 0
    print ("light 1 : " + str(is_light1_on))
    if (is_light1_on):
        digital_write(lights[0], "0")
        state = 0
    else:
        digital_write(lights[0], "1")
        state = 1
    is_light1_on = not(is_light1_on)
    return jsonify( {"status":state} )
    

@app.route("/secondled", methods=['POST'])
def manage_second_light():
    global is_light2_on
    state = 0
    print ("light 2 : " + str(is_light2_on))
    if (is_light2_on):
        digital_write(lights[1], "0")
        state = 0
    else:
        digital_write(lights[1], "1")
        state = 1
    is_light2_on = not(is_light2_on)
    return jsonify( {"status":state} )
    


@app.route("/thirdled", methods=['POST'])
def manage_third_light():
    global is_light3_on
    state = 0
    print ("light 3 : " + str(is_light3_on))
    if (is_light3_on):
        digital_write(lights[2], "0")
        state = 0
    else:
        digital_write(lights[2], "1")
        state = 1
    is_light3_on = not(is_light3_on)
    return jsonify( {"status":state} )
    

@app.route("/firstkitchen", methods=['POST'])
def manage_kitchen1():
    global is_kitchen1_on
    state = 0
    print ("kitchen 1: " + str(is_kitchen1_on))
    if (is_kitchen1_on):
        digital_write(kitchen[0], "0")
        state = 0
    else:
        digital_write(kitchen[0], "1")
        state = 1
    is_kitchen1_on = not(is_kitchen1_on)
    return jsonify( {"status":state} )


@app.route("/secondkitchen", methods=['POST'])
def manage_kitchen2():
    global is_kitchen2_on
    state = 0
    print ("kitchen 2: " + str(is_kitchen2_on))
    if (is_kitchen2_on):
        digital_write(kitchen[1], "0")
        state = 0
    else:
        digital_write(kitchen[1], "1")
        state = 1
    is_kitchen2_on = not(is_kitchen2_on)
    return jsonify( {"status":state} )
   

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080)