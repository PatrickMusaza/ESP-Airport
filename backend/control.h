
const char PAGE_CONTROL[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Control Panel - Airport</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
            display: flex;
            flex-direction: column;
            align-items: center;
            gap: 20px;
            padding: 20px;
        }
        h1 {
            color: #333;
        }
        .preview-area {
            width: 80%;
            height: 300px;
            background-color: #333;
            border-radius: 10px;
            display: flex;
            justify-content: space-around;
            align-items: center;
            padding: 20px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        .light {
            width: 50px;
            height: 50px;
            border-radius: 50%;
            background-color: #555;
            transition: background-color 0.3s;
        }
        .light.on {
            background-color: yellow;
            box-shadow: 0 0 20px yellow;
        }
        .control-panel {
            width: 80%;
            background-color: #fff;
            border-radius: 10px;
            padding: 20px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            display: flex;
            flex-wrap: wrap;
            gap: 10px;
            justify-content: center;
        }
        .switch {
            display: flex;
            align-items: center;
            gap: 10px;
        }
        .switch label {
            font-size: 18px;
            color: #333;
        }
        .switch input[type="checkbox"] {
            width: 40px;
            height: 20px;
            appearance: none;
            background-color: #ccc;
            border-radius: 10px;
            position: relative;
            cursor: pointer;
            transition: background-color 0.3s;
        }
        .switch input[type="checkbox"]:checked {
            background-color: #28a745;
        }
        .switch input[type="checkbox"]::before {
            content: '';
            width: 18px;
            height: 18px;
            background-color: #fff;
            border-radius: 50%;
            position: absolute;
            top: 1px;
            left: 1px;
            transition: transform 0.3s;
        }
        .switch input[type="checkbox"]:checked::before {
            transform: translateX(20px);
        }
    </style>
</head>
<body>
    <h1>Airport Control Panel</h1>

    <!-- Part 1: Preview Area -->
    <div class="preview-area">
        <div class="light" id="light1"></div>
        <div class="light" id="light2"></div>
        <div class="light" id="light3"></div>
        <div class="light" id="light4"></div>
        <div class="light" id="light5"></div>
        <div class="light" id="light6"></div>
        <div class="light" id="light7"></div>
        <div class="light" id="light8"></div>
    </div>

    <!-- Part 2: Control Panel -->
    <div class="control-panel">
        <div class="switch">
            <label for="switch1">Light 1</label>
            <input type="checkbox" id="switch1" onchange="toggleLight(1)">
        </div>
        <div class="switch">
            <label for="switch2">Light 2</label>
            <input type="checkbox" id="switch2" onchange="toggleLight(2)">
        </div>
        <div class="switch">
            <label for="switch3">Light 3</label>
            <input type="checkbox" id="switch3" onchange="toggleLight(3)">
        </div>
        <div class="switch">
            <label for="switch4">Light 4</label>
            <input type="checkbox" id="switch4" onchange="toggleLight(4)">
        </div>
        <div class="switch">
            <label for="switch5">Light 5</label>
            <input type="checkbox" id="switch5" onchange="toggleLight(5)">
        </div>
        <div class="switch">
            <label for="switch6">Light 6</label>
            <input type="checkbox" id="switch6" onchange="toggleLight(6)">
        </div>
        <div class="switch">
            <label for="switch7">Light 7</label>
            <input type="checkbox" id="switch7" onchange="toggleLight(7)">
        </div>
        <div class="switch">
            <label for="switch8">Light 8</label>
            <input type="checkbox" id="switch8" onchange="toggleLight(8)">
        </div>
    </div>

    <script>
        // Function to toggle lights
        function toggleLight(lightNumber) {
            const light = document.getElementById(`light${lightNumber}`);
            const switchInput = document.getElementById(`switch${lightNumber}`);

            if (switchInput.checked) {
                light.classList.add('on');
            } else {
                light.classList.remove('on');
            }
        }
    </script>
</body>
</html>

)=====";