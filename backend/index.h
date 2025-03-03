
const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Airport Homepage - Happy Light Tech</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f4f4f4;
            text-align: center;
        }
        .header {
            background-color: #333;
            color: #fff;
            padding: 20px;
            font-size: 24px;
        }
        .slides-container {
            display: flex;
            flex-wrap: wrap;
            justify-content: center;
            gap: 10px;
            padding: 20px;
        }
        .slide {
            width: 150px;
            height: 100px;
            background-color: #007bff;
            color: #fff;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 18px;
            border-radius: 8px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
        }
        .footer {
            background-color: #333;
            color: #fff;
            padding: 10px;
            position: fixed;
            bottom: 0;
            width: 100%;
            font-size: 14px;
        }
        .control-button {
            margin: 20px;
            padding: 10px 20px;
            font-size: 16px;
            background-color: #28a745;
            color: #fff;
            border: none;
            border-radius: 5px;
            cursor: pointer;
        }
        .control-button:hover {
            background-color: #218838;
        }
    </style>
</head>
<body>
    <div class="header">
        Welcome to the Airport - Developed by Happy Light Tech
    </div>

    <div class="slides-container">
        <!-- 20 slides represented by colored divs -->
        <div class="slide">Slide 1</div>
        <div class="slide">Slide 2</div>
        <div class="slide">Slide 3</div>
        <div class="slide">Slide 4</div>
        <div class="slide">Slide 5</div>
        <div class="slide">Slide 6</div>
        <div class="slide">Slide 7</div>
        <div class="slide">Slide 8</div>
        <div class="slide">Slide 9</div>
        <div class="slide">Slide 10</div>
        <div class="slide">Slide 11</div>
        <div class="slide">Slide 12</div>
        <div class="slide">Slide 13</div>
        <div class="slide">Slide 14</div>
        <div class="slide">Slide 15</div>
        <div class="slide">Slide 16</div>
        <div class="slide">Slide 17</div>
        <div class="slide">Slide 18</div>
        <div class="slide">Slide 19</div>
        <div class="slide">Slide 20</div>
    </div>

    <button class="control-button" onclick="navigateToControl()">Control</button>

    <div class="footer">
        &copy; 2023 Happy Light Tech. All rights reserved.
    </div>

    <script>
        function navigateToControl() {
            window.location.href = "/control";
        }
    </script>
</body>
</html>


)=====";