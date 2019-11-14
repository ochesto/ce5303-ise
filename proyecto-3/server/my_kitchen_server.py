from flask import Flask, jsonify
from gpio_manager import *

#CAMBIAR PINES
lights = ["3", "6", "11"]
kitchen = "22"

export_pin(lights[0])
export_pin(lights[1])
export_pin(lights[2])
export_pin(kitchen)

pin_mode(lights[0], "out")
pin_mode(lights[1], "out")
pin_mode(lights[2], "out")
pin_mode(kitchen, "out")

is_light1_on = False
is_light2_on = False
is_light3_on = False
is_kitchen_on = False

app = Flask(__name__)


@app.route("/firstled", methods=['POST'])
def manage_first_light():
    global is_light1_on
    print ("light 1 : " + str(is_light1_on))
    if (is_light1_on):
        digital_write(lights[0], "0")
    else:
        digital_write(lights[0], "1")
    is_light1_on = not(is_light1_on)
    return jsonify( {"status":200} )
    

@app.route("/secondled", methods=['POST'])
def manage_second_light():
    global is_light2_on
    print ("light 2 : " + str(is_light2_on))
    if (is_light2_on):
        digital_write(lights[1], "0")
    else:
        digital_write(lights[1], "1")
    is_light2_on = not(is_light2_on)
    return jsonify( {"status":200} )
    


@app.route("/thirdled", methods=['POST'])
def manage_third_light():
    global is_light3_on
    print ("light 3 : " + str(is_light3_on))
    if (is_light3_on):
        digital_write(lights[2], "0")
    else:
        digital_write(lights[2], "1")
    is_light3_on = not(is_light3_on)
    return jsonify( {"status":200} )
    

@app.route("/kitchen", methods=['POST'])
def manage_kitchen():
    global is_kitchen_on
    print ("kitchen: " + str(is_kitchen_on))
    if (is_kitchen_on):
        digital_write(kitchen, "0")
    else:
        digital_write(kitchen, "1")
    is_kitchen_on = not(is_kitchen_on)
    return jsonify( {"status":200} )
   

if __name__ == '__main__':
    app.run(host="0.0.0.0", port=8080)